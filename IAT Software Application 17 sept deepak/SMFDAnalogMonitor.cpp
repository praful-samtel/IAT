#include "stdafx.h"
#include "SMFDAnalogMonitor.h"
#include "Arinc429.h"
#include "DataStruct.h"

static UINT g_SMFDAnalogLabel = LABEL_317;
static HWND g_hSMFDAnalogTarget = NULL;

void SetSMFDAnalogLabel(UINT label)
{
    CSingleLock lock(&g_csSMFDAnalog, TRUE);

    g_SMFDAnalogLabel = label;
}

BOOL StartSMFDAnalogMonitor()
{
    if (g_bSMFDAnalogThreadRunning)
        return TRUE;

    g_bSMFDAnalogStopThread = FALSE;
    g_bSMFDAnalogThreadRunning = TRUE;

    CWinThread* pThread =
        AfxBeginThread(SMFDAnalogMonitorThread, NULL);

    if (pThread == NULL)
    {
        g_bSMFDAnalogThreadRunning = FALSE;
        return FALSE;
    }

    return TRUE;
}

void StopSMFDAnalogMonitor()
{
    g_bSMFDAnalogStopThread = TRUE;

    while (g_bSMFDAnalogThreadRunning)
    {
        Sleep(10);
    }
}

UINT SMFDAnalogMonitorThread(LPVOID pParam)
{
    UNREFERENCED_PARAMETER(pParam);

    while (!g_bSMFDAnalogStopThread)
    {
        UINT currentLabel;
        HWND hTargetWnd;

        {
            CSingleLock lock(&g_csSMFDAnalog, TRUE);

            currentLabel = g_SMFDAnalogLabel;
            hTargetWnd = g_hSMFDAnalogTarget;
        }

        ReadADCRX(9);

        Sleep(20);

        float value = 0.0f;

        if (GetARINCValue(9, currentLabel, &value))
        {
            {
                CSingleLock lock(&g_csSMFDAnalog, TRUE);

                g_fLatestSMFDAnalogValue = value;
            }

            if (hTargetWnd != NULL &&
                ::IsWindow(hTargetWnd))
            {
                ::PostMessage(
                    hTargetWnd,
                    WM_UPDATE_SMFD_ANALOG,
                    0,
                    0
                );
            }
        }

        Sleep(20);
    }

    g_bSMFDAnalogThreadRunning = FALSE;

    return 0;
}

void SetSMFDAnalogTarget(HWND hWnd, UINT label)
{
    CSingleLock lock(&g_csSMFDAnalog, TRUE);

    g_hSMFDAnalogTarget = hWnd;
    g_SMFDAnalogLabel = label;
}

void ClearSMFDAnalogTarget()
{
    CSingleLock lock(&g_csSMFDAnalog, TRUE);

    g_hSMFDAnalogTarget = NULL;
}

float GetLatestSMFDAnalogValue()
{
    CSingleLock lock(&g_csSMFDAnalog, TRUE);

    return g_fLatestSMFDAnalogValue;
}