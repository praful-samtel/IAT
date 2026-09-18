#include "stdafx.h"
#include "Dialog_ADC_FUNCHK.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "resource.h"
#include "Globals.h"
#include "Arinc429.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_ADC_FUNCHK, CDialogEx)

CDialog_ADC_FUNCHK::CDialog_ADC_FUNCHK(CWnd* pParent)
	: CDialogEx(CDialog_ADC_FUNCHK::IDD, pParent)
	, m_edtADCALT1(_T(""))
	
	
	
{

   
    m_bThreadRunning = FALSE;
}

CDialog_ADC_FUNCHK::~CDialog_ADC_FUNCHK()
{
}

void CDialog_ADC_FUNCHK::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ADC_ALTITUDE1, m_edtADCALT1);



}

BEGIN_MESSAGE_MAP(CDialog_ADC_FUNCHK, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_FUNCHK::OnBnClickedOk)
	 ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_FUNCHK::OnUpdateArinc)
	
END_MESSAGE_MAP()

// ---------------- OK BUTTON ----------------



void CDialog_ADC_FUNCHK::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;


	m_strAltitude1.Format("%s",m_edtADCALT1);

	// Simple validation (you adjust later)
	double a1 = atof(m_edtADCALT1);
	
	if (a1 <= 7530 && a1 >= 7470 )
		m_strStatusAltitude1 = "OK";
	else
	{
		g_strMsgStr = "Altitude at 7500 ft are out of range. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusAltitude1 = "NOT OK";
	}
	KillTimer(1);
	StopRxThread();
	CDialogEx::OnOK();
}


BOOL CDialog_ADC_FUNCHK::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    ShowSimulationLoopbackNotice(_T("ADC"), ADC_SIM_LOOPBACK_TX_CHANNEL_X,
                                 ADC_SIM_LOOPBACK_TX_CHANNEL_Y, ADC_SIM_LOOPBACK_RX_PIN_P,
                                 ADC_SIM_LOOPBACK_RX_PIN_Q);

    InitArincRX(9);

    if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }

    SetTimer(1, 3000, NULL);

    return TRUE;
}

void CDialog_ADC_FUNCHK::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

        if(GetARINCValue(9, LABEL_203, &value))
        {
            CString str;
            str.Format("%.0f", value);

            if(str != m_edtADCALT1)      // update only if changed
            {
                m_edtADCALT1 = str;
                UpdateData(FALSE);
            }
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}

UINT CDialog_ADC_FUNCHK::RxThread(LPVOID pParam)
{
	CDialog_ADC_FUNCHK* pDlg =
        reinterpret_cast<CDialog_ADC_FUNCHK*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			//Labels[0] = 0xE0EA6083;
			Labels[0] = 0xE0EA60C1;    // LABEL_203, 7500 ft
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

LRESULT CDialog_ADC_FUNCHK::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCALT1 = m_strADCALT1;

    UpdateData(FALSE);

    return 0;
}						 //Altitude   RawCount         Word    Decoded
     // 7500      15000  0xE0EA60C1     7500.0  label=0xC1
     //15000      30000  0xE1D4C0C1    15000.0  label=0xC1
     //20000      40000  0xE27100C1    20000.0  label=0xC1



void CDialog_ADC_FUNCHK::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
