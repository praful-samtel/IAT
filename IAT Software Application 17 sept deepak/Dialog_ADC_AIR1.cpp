// Dialog_ADC_AIR1.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_AIR1.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Globals.h"
#include "Arinc429.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ADC_AIR1 dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_AIR1, CDialogEx)

CDialog_ADC_AIR1::CDialog_ADC_AIR1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_AIR1::IDD, pParent)
	, m_edtADCAirsp1(_T(""))
{

}

CDialog_ADC_AIR1::~CDialog_ADC_AIR1()
{
}

void CDialog_ADC_AIR1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_AIRSPEED1, m_edtADCAirsp1);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_AIR1, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_AIR1::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_AIR1::OnUpdateArinc)

	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDialog_ADC_AIR1 message handlers


void CDialog_ADC_AIR1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;

		m_strAirspeed1.Format("%s",m_edtADCAirsp1);

	double s1 = atof(m_edtADCAirsp1);

	if (s1 >= 95 && s1 <= 105 )
		m_strStatusAirspeed1 = "OK";
	else
	{
		g_strMsgStr = "Airspeed values invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAirspeed1 = "NOT OK";
	}
	UpdateData(FALSE);
		KillTimer(1);
		StopRxThread();
	CDialogEx::OnOK();
}

BOOL CDialog_ADC_AIR1::OnInitDialog()
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

void CDialog_ADC_AIR1::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

		//if(g_bSimulationMode)
		//{	
		//	TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
		//	ADT_L0_UINT32 Labels[1];
		//	Labels[0] = 0xE0640086;   // LABEL_206, 100 kt
		//	gArinc429.SendLabels(8, Labels, 1);

		//}

  //      if(GetARINCValue(8, LABEL_206, &value))
  //      {
  //          CString str;
  //          str.Format("%.0f", value);

  //          if(str != m_edtADCAirsp1)      // update only if changed
  //          {
  //              m_edtADCAirsp1 = str;
  //              UpdateData(FALSE);
  //          }
  //      }
    }

    CDialogEx::OnTimer(nIDEvent);
}


UINT CDialog_ADC_AIR1::RxThread(LPVOID pParam)
{
	CDialog_ADC_AIR1* pDlg =
        reinterpret_cast<CDialog_ADC_AIR1*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			//Labels[0] = 0xE0EA6083;
			Labels[0] = 0xE1900061;    // LABEL_206, 100 knots
			gArinc429.SendLabels(3, Labels, 1);
		}

        ReadADCRX(9);
        Sleep(20);

		 float value;

        if(GetARINCValue(9, LABEL_206, &value))
        {
            CString str;
            str.Format(_T("%.0f"), value);

            pDlg->m_strAirSp1 = str;
    	 if (::IsWindow(pDlg->GetSafeHwnd()))
        {
            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }
    }
	
	}
	
    g_bADCThreadRunning = FALSE;

    return 0;
}

LRESULT CDialog_ADC_AIR1::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCAirsp1 = m_strAirSp1;

    UpdateData(FALSE);

    return 0;
}		


void CDialog_ADC_AIR1::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
