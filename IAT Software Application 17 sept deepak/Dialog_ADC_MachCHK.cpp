// Dialog_ADC_MachCHK.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_MachCHK.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Globals.h"
#include "Arinc429.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_ADC_MachCHK dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_MachCHK, CDialogEx)

CDialog_ADC_MachCHK::CDialog_ADC_MachCHK(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_MachCHK::IDD, pParent)
	, m_edtADCMach1(_T(""))

{

}

CDialog_ADC_MachCHK::~CDialog_ADC_MachCHK()
{
}

void CDialog_ADC_MachCHK::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_MACH1, m_edtADCMach1);
	
}


BEGIN_MESSAGE_MAP(CDialog_ADC_MachCHK, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_MachCHK::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_MachCHK::OnUpdateArinc)
	
	ON_WM_TIMER()

END_MESSAGE_MAP()


// CDialog_ADC_MachCHK message handlers


void CDialog_ADC_MachCHK::OnBnClickedOk()
{
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;
	// TODO: Add your control notification handler code here
	m_strMach1.Format("%s",m_edtADCMach1);

	double m1 = atof(m_edtADCMach1);

	if (m1 >= 0.28 && m1<= 0.30)
		m_strStatusMach1 = "OK";
	else
	{
		g_strMsgStr = "Mach values invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusMach1 = "NOT OK";
	}
	KillTimer(1);
	StopRxThread();
	UpdateData(FALSE);

	CDialogEx::OnOK();
}

BOOL CDialog_ADC_MachCHK::OnInitDialog()
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

void CDialog_ADC_MachCHK::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

		//if(g_bSimulationMode)
		//{	
		//	TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
		//	ADT_L0_UINT32 Labels[1];
		//	Labels[0] = 0xE1220085;   // LABEL_205, Mach 0.29
		//	gArinc429.SendLabels(8, Labels, 1);

		//}

        if(GetARINCValue(9, LABEL_205, &value))
        {
            CString str;
            str.Format("%.2f", value);

            if(str != m_edtADCMach1)      // update only if changed
            {
                m_edtADCMach1 = str;
                UpdateData(FALSE);
            }
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}

UINT CDialog_ADC_MachCHK::RxThread(LPVOID pParam)
{
	CDialog_ADC_MachCHK* pDlg =
        reinterpret_cast<CDialog_ADC_MachCHK*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			//Labels[0] = 0xE0EA6083;
			Labels[0] = 0x612C00A1;   // Label 205, Mach 0.30
			gArinc429.SendLabels(3, Labels, 1);
		}

        ReadADCRX(9);
        Sleep(20);


		 float value;

        if(GetARINCValue(9, LABEL_205, &value))
        {
            CString str;
            str.Format(_T("%.2f"), value);

            pDlg->m_strADCMach1 = str;
    	 if (::IsWindow(pDlg->GetSafeHwnd()))
        {
            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }
    }
	
	}
	

    g_bADCThreadRunning = FALSE;

    return 0;
}

LRESULT CDialog_ADC_MachCHK::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCMach1 = m_strADCMach1;
	TRACE(_T("DATA is VALUE: %s\n"), (LPCTSTR)m_edtADCMach1);
    UpdateData(FALSE);

    return 0;
}	
void CDialog_ADC_MachCHK::StopRxThread()
{
    if (g_bADCThreadRunning)
    {
        g_bADCStopThread = TRUE;

        while (g_bADCThreadRunning)
            Sleep(10);
    }
}
