// Dialog_ADC_ALTIRATE.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_ALTIRATE.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "resource.h"
#include "Globals.h"
#include "Arinc429.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

#define ADC_ALT_RATE_POS_2000  0x607D0051  // +2000 ft/min
#define ADC_ALT_RATE_NEG_2000  0x7F830051  // -2000 ft/min
// CDialog_ADC_ALTIRATE dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_ALTIRATE, CDialogEx)

CDialog_ADC_ALTIRATE::CDialog_ADC_ALTIRATE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_ALTIRATE::IDD, pParent)
	, m_edt_AltiRate_ArincRx(_T(""))
	, m_chk_AltiRate1(FALSE)
	, m_chk_AltiRate2(FALSE)
{

}

CDialog_ADC_ALTIRATE::~CDialog_ADC_ALTIRATE()
{
}

void CDialog_ADC_ALTIRATE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ALTIRATE_ARINCRX, m_edt_AltiRate_ArincRx);
	DDX_Check(pDX, IDC_CHECK_ALTIRATE1, m_chk_AltiRate1);
	DDX_Check(pDX, IDC_CHECK_ALTIRATE2, m_chk_AltiRate2);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_ALTIRATE, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_ALTIRATE1, &CDialog_ADC_ALTIRATE::OnBnClickedCheckAltirate1)
	ON_BN_CLICKED(IDC_CHECK_ALTIRATE2, &CDialog_ADC_ALTIRATE::OnBnClickedCheckAltirate2)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_ALTIRATE::OnUpdateArinc)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_ALTIRATE::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_ADC_ALTIRATE message handlers



void CDialog_ADC_ALTIRATE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;
	// TODO: Add your control notification handler code here
	
     if(m_chk_AltiRate1)
		{  m_strAltiRate1 = "Operational";
	 m_strStatusAltiRate1 = "OK";}
	else
	{
		g_strMsgStr = "Altitude rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAltiRate1 = "NOT OK";
		  m_strAltiRate1 = "Not Operational";
	}

	 if(m_chk_AltiRate2)
		{  m_strAltiRate2 = "Operational";
	 m_strStatusAltiRate2 = "OK";}
	else
	{
		g_strMsgStr = "Altitude rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAltiRate2 = "NOT OK";
		  m_strAltiRate2 = "Not Operational";
	}
UpdateData(FALSE);

	StopRxThread();
	CDialogEx::OnOK();
}

BOOL CDialog_ADC_ALTIRATE::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    //InitArincRX(9);

    if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }

    SetTimer(1, 3000, NULL);

    return TRUE;
}


void CDialog_ADC_ALTIRATE::OnBnClickedCheckAltirate1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_chk_AltiRate1)
	GetDlgItem(IDC_CHECK_ALTIRATE1)->SetWindowTextA("Operational");
	else
      GetDlgItem(IDC_CHECK_ALTIRATE1)->SetWindowTextA("Not Operational");

	UpdateData(FALSE);
}


void CDialog_ADC_ALTIRATE::OnBnClickedCheckAltirate2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_chk_AltiRate2)
	GetDlgItem(IDC_CHECK_ALTIRATE2)->SetWindowTextA("Operational");
	else
      GetDlgItem(IDC_CHECK_ALTIRATE2)->SetWindowTextA("Not Operational");

	UpdateData(FALSE);
}

//
//UINT CDialog_ADC_ALTIRATE::RxThread(LPVOID pParam)
//{
//	CDialog_ADC_ALTIRATE* pDlg =
//        reinterpret_cast<CDialog_ADC_ALTIRATE*>(pParam);
//
//    if (pDlg == NULL)
//        return 0;
//
//    while(!g_bADCStopThread)
//    {
//		if(g_bSimulationMode)
//		{
//			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
//			ADT_L0_UINT32 Labels[1];
//			//Labels[0] = 0xE0EA6083;
//			Labels[0] = 0xE0EA60C1;    // LABEL_203, 7500 ft
//			gArinc429.SendLabels(3, Labels, 1);
//		}
//
//
//
//        ReadADCRX(9);
//        Sleep(20);
//
//
//		 float value;
//
//        if(GetARINCValue(9, LABEL_212, &value))
//        {
//            CString str;
//            str.Format(_T("%.0f"), value);
//
//            pDlg->m_strAltiRate = str;
//    	 if (::IsWindow(pDlg->GetSafeHwnd()))
//        {
//            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
//        }
//    }
//	
//	}
//	
//
//    g_bADCThreadRunning = FALSE;
//
//    return 0;
//}
UINT CDialog_ADC_ALTIRATE::RxThread(LPVOID pParam)
{
    CDialog_ADC_ALTIRATE* pDlg =
        reinterpret_cast<CDialog_ADC_ALTIRATE*>(pParam);

    if (pDlg == NULL)
        return 0;

    const DWORD TX_INTERVAL_MS    = 50;       // 20 Hz
    const DWORD CHANGE_INTERVAL_MS = 10000;   // 10 seconds

    DWORD lastTxTime    = GetTickCount() - TX_INTERVAL_MS;
    DWORD phaseStartTime = GetTickCount();
    BOOL sendPositive = TRUE;

    while (!g_bADCStopThread)
    {
        const DWORD now = GetTickCount();

        // Toggle between +2000 and -2000 every 10 seconds.
        while ((now - phaseStartTime) >= CHANGE_INTERVAL_MS)
        {
            sendPositive = !sendPositive;
            phaseStartTime += CHANGE_INTERVAL_MS;
        }

        if (g_bSimulationMode &&
            (now - lastTxTime) >= TX_INTERVAL_MS)
        {
            ADT_L0_UINT32 Labels[1];

            Labels[0] = sendPositive
                ? ADC_ALT_RATE_POS_2000
                : ADC_ALT_RATE_NEG_2000;

            gArinc429.SendLabels(3, Labels, 1);
            lastTxTime = now;

            TRACE("ADC Altitude Rate Sent: %s2000 ft/min, RAW: 0x%08X\n",
                  sendPositive ? "+" : "-",
                  Labels[0]);
        }

        ReadADCRX(9);

        float value;
        if (GetARINCValue(9, LABEL_212, &value))
        {
            pDlg->m_strAltiRate.Format(_T("%.0f"), value);

            if (::IsWindow(pDlg->GetSafeHwnd()))
                pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }

        Sleep(10);
    }

    g_bADCThreadRunning = FALSE;
    return 0;
}
LRESULT CDialog_ADC_ALTIRATE::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edt_AltiRate_ArincRx = m_strAltiRate;

    UpdateData(FALSE);

    return 0;
}

void CDialog_ADC_ALTIRATE::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}