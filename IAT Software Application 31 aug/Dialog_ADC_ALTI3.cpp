// Dialog_ADC_ALTI3.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_ALTI3.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Arinc429.h"
#include "Globals.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ADC_ALTI3 dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_ALTI3, CDialogEx)

CDialog_ADC_ALTI3::CDialog_ADC_ALTI3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_ALTI3::IDD, pParent)
	, m_edtADCALT3(_T(""))
{

}

CDialog_ADC_ALTI3::~CDialog_ADC_ALTI3()
{
}

void CDialog_ADC_ALTI3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_ALTITUDE3, m_edtADCALT3);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_ALTI3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_ALTI3::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_ALTI3::OnUpdateArinc)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDialog_ADC_ALTI3 message handlers


void CDialog_ADC_ALTI3::OnBnClickedOk()
{
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;
	double a2 = atof(m_edtADCALT3);
	m_strAltitude3.Format("%s",m_edtADCALT3);
	if ( a2 >= 19950 && a2 <= 20050 )
		m_strStatusAltitude3 = "OK";
	else
	{
		g_strMsgStr = "Altitude at 15000 ft are out of range. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAltitude3 = "NOT OK";
	}
	UpdateData(FALSE);
		KillTimer(1);
		StopRxThread();
	CDialogEx::OnOK();
}

BOOL CDialog_ADC_ALTI3::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    ShowSimulationLoopbackNotice(_T("ADC"), ADC_SIM_LOOPBACK_TX_CHANNEL_X,
                                 ADC_SIM_LOOPBACK_TX_CHANNEL_Y, ADC_SIM_LOOPBACK_RX_PIN_P,
                                 ADC_SIM_LOOPBACK_RX_PIN_Q);

	 if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }

    SetTimer(1, 3000, NULL);      // Update 5 times/sec

    return TRUE;
}



UINT CDialog_ADC_ALTI3::RxThread(LPVOID pParam)
{
	CDialog_ADC_ALTI3* pDlg =
        reinterpret_cast<CDialog_ADC_ALTI3*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			Labels[0] = 0xE27100C1;    // LABEL_203, 20000 ft
			gArinc429.SendLabels(3, Labels, 1);
		}

        ReadADCRX(9);
        Sleep(20);

		 float value;

        if(GetARINCValue(9, LABEL_203, &value))
        {
            CString str;
            str.Format(_T("%.0f"), value);

            pDlg->m_strADCALT1 = str;
    	 if (::IsWindow(pDlg->GetSafeHwnd()))
        {
            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }
    }
	
	}
	

    g_bADCThreadRunning = FALSE;

    return 0;
}


void CDialog_ADC_ALTI3::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

        if(GetARINCValue(8, LABEL_203, &value))
        {
            CString str;
            str.Format("%.0f", value);

            if(str != m_edtADCALT3)      // update only if changed
            {
                m_edtADCALT3 = str;
                UpdateData(FALSE);
            }
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}


LRESULT CDialog_ADC_ALTI3::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCALT3 = m_strADCALT1;

    UpdateData(FALSE);

    return 0;
}	
void CDialog_ADC_ALTI3::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
