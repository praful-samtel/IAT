// Dialog_ADC_ALTI2.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_ALTI2.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Arinc429.h"
#include "Globals.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_ADC_ALTI2 dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_ALTI2, CDialogEx)

CDialog_ADC_ALTI2::CDialog_ADC_ALTI2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_ALTI2::IDD, pParent)
	, m_edtADCALT2(_T(""))
{

}

CDialog_ADC_ALTI2::~CDialog_ADC_ALTI2()
{
}

void CDialog_ADC_ALTI2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_ALTITUDE2, m_edtADCALT2);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_ALTI2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_ALTI2::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_ALTI2::OnUpdateArinc)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDialog_ADC_ALTI2 message handlers


void CDialog_ADC_ALTI2::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;
	double a2 = atof(m_edtADCALT2);
	m_strAltitude2.Format("%s",m_edtADCALT2);
	if ( a2 >= 14055 && a2 <= 15045 )
		m_strStatusAltitude2 = "OK";
	else
	{
		g_strMsgStr = "Altitude at 15000 ft are out of range. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAltitude2 = "NOT OK";
	}

	UpdateData(FALSE);
		KillTimer(1);
		StopRxThread();
	CDialogEx::OnOK();
}


BOOL CDialog_ADC_ALTI2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

 //   ShowSimulationLoopbackNotice(_T("ADC"), ADC_SIM_LOOPBACK_TX_CHANNEL_X,
 //                                ADC_SIM_LOOPBACK_TX_CHANNEL_Y, ADC_SIM_LOOPBACK_RX_PIN_P,
 //                                ADC_SIM_LOOPBACK_RX_PIN_Q);
	////InitArincRX(9);

    if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }


    SetTimer(1, 3000, NULL);      // Update 5 times/sec

    return TRUE;
}


UINT CDialog_ADC_ALTI2::RxThread(LPVOID pParam)
{
	CDialog_ADC_ALTI2* pDlg =
        reinterpret_cast<CDialog_ADC_ALTI2*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			Labels[0] = 0xE1D4C0C1;    // LABEL_203, 15000 ft
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

void CDialog_ADC_ALTI2::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

		//if(g_bSimulationMode)
		//{	
		//	TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
		//		ADT_L0_UINT32 Labels[3];
		//		Labels[0] = 0xE1D4C0C1 ;

		//		gArinc429.SendLabels(0, Labels, 3); //FC

		//}

        if(GetARINCValue(8, LABEL_203, &value))
        {
            CString str;
            str.Format("%.0f", value);

            if(str != m_edtADCALT2)      // update only if changed
            {
                m_edtADCALT2 = str;
                UpdateData(FALSE);
            }
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}

LRESULT CDialog_ADC_ALTI2::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCALT2 = m_strADCALT1;

    UpdateData(FALSE);

    return 0;
}	
void CDialog_ADC_ALTI2::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
