// Dialog_ADC_AIR3.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_AIR3.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Arinc429.h"
#include "Globals.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ADC_AIR3 dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_AIR3, CDialogEx)

CDialog_ADC_AIR3::CDialog_ADC_AIR3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_AIR3::IDD, pParent)
	, m_edtADCAirsp3(_T(""))
{

}

CDialog_ADC_AIR3::~CDialog_ADC_AIR3()
{
}

void CDialog_ADC_AIR3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_AIRSPEED3, m_edtADCAirsp3);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_AIR3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_AIR3::OnBnClickedOk)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDialog_ADC_AIR3 message handlers


void CDialog_ADC_AIR3::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;

		m_strAirspeed3.Format("%s",m_edtADCAirsp3);

	double s3 = atof(m_edtADCAirsp3);

	if (s3 >= 219 && s3 <= 227)
		m_strStatusAirspeed3 = "OK";
	else
	{
		g_strMsgStr = "Airspeed values invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAirspeed3 = "NOT OK";
	}
	UpdateData(FALSE);
		KillTimer(1);
		StopRxThread();
	CDialogEx::OnOK();
}
BOOL CDialog_ADC_AIR3::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    ShowSimulationLoopbackNotice(_T("ADC"), ADC_SIM_LOOPBACK_TX_CHANNEL_X,
                                 ADC_SIM_LOOPBACK_TX_CHANNEL_Y, ADC_SIM_LOOPBACK_RX_PIN_P,
                                 ADC_SIM_LOOPBACK_RX_PIN_Q);
	
	//InitArincRX(9);

    if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }

    SetTimer(1, 3000, NULL);      // Update 5 times/sec

    return TRUE;
}

void CDialog_ADC_AIR3::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

		//if(g_bSimulationMode)
		//{
		//	TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
		//	ADT_L0_UINT32 Labels[1];
		//	Labels[0] = 0xE0DC0086;   // LABEL_206, CAS 220 kt
		//	gArinc429.SendLabels(8, Labels, 1);
		//}

        //if(GetARINCValue(8, LABEL_206, &value))
        //{
        //    CString str;
        //    str.Format("%.0f", value);

        //    if(str != m_edtADCAirsp3)      // update only if changed
        //    {
        //        m_edtADCAirsp3 = str;
        //        UpdateData(FALSE);
        //    }
        //}
    }

    CDialogEx::OnTimer(nIDEvent);
}


UINT CDialog_ADC_AIR3::RxThread(LPVOID pParam)
{
	CDialog_ADC_AIR3* pDlg =
        reinterpret_cast<CDialog_ADC_AIR3*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			//Labels[0] = 0xE0EA6083;
			Labels[0] = 0xE3700061   ;    // LABEL_206, 220 knots
			gArinc429.SendLabels(3, Labels, 1);
		}

        ReadADCRX(9);
        Sleep(20);

		 float value;

        if(GetARINCValue(9, LABEL_206, &value))
        {
            CString str;
            str.Format(_T("%.0f"), value);

            pDlg->m_strAirSp3 = str;
    	 if (::IsWindow(pDlg->GetSafeHwnd()))
        {
            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }
    }
	}
    g_bADCThreadRunning = FALSE;

    return 0;
}

LRESULT CDialog_ADC_AIR3::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCAirsp3 = m_strAirSp3;

    UpdateData(FALSE);

    return 0;
}	

void CDialog_ADC_AIR3::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
