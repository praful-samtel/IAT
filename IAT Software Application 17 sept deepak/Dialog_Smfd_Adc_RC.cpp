// Dialog_Smfd_Adc_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Adc_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include "Arinc429.h"
#include "Globals.h"
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Adc_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Adc_RC, CDialogEx)

CDialog_Smfd_Adc_RC::CDialog_Smfd_Adc_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Adc_RC::IDD, pParent)
	, m_edt_SmfdRc_PressAlti(_T(""))
	, m_edt_SmfdRc_MachNum(_T(""))
	, m_edt_SmfdRc_CompAirSp(_T(""))
	, m_edt_SmfdRc_AltiRate(_T(""))
	, m_edt_SmfdRc_StaAirTemp(_T(""))
	, m_edt_SmfdRc_TrAirSp(_T(""))
	, m_bThreadRunning(FALSE)
	, m_bStopThread(FALSE)
	, m_pArincRXThread(NULL)
{

}

CDialog_Smfd_Adc_RC::~CDialog_Smfd_Adc_RC()
{
}

void CDialog_Smfd_Adc_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR203, m_edt_SmfdRc_PressAlti);
	DDX_Text(pDX, IDC_EDIT_SMFDAR205, m_edt_SmfdRc_MachNum);
	DDX_Text(pDX, IDC_EDIT_SMFDAR206, m_edt_SmfdRc_CompAirSp);
	DDX_Text(pDX, IDC_EDIT_SMFDAR212, m_edt_SmfdRc_AltiRate);
	DDX_Text(pDX, IDC_EDIT_SMFDAR213, m_edt_SmfdRc_StaAirTemp);
	DDX_Text(pDX, IDC_EDIT_SMFDAR210, m_edt_SmfdRc_TrAirSp);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Adc_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Adc_RC::OnBnClickedOk)
		ON_BN_CLICKED(IDC_BUTTON_RCARINC, &CDialog_Smfd_Adc_RC::OnBnClickedButtonRcarinc)
		ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_Smfd_Adc_RC message handlers


void CDialog_Smfd_Adc_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;

	double a1 = atof(m_edt_SmfdRc_PressAlti);
	double a2 = atof(m_edt_SmfdRc_MachNum);
	double a3 = atof(m_edt_SmfdRc_CompAirSp);
	double a4 = atof(m_edt_SmfdRc_AltiRate);
	double a5 = atof(m_edt_SmfdRc_StaAirTemp);
    double a6 = atof(m_edt_SmfdRc_TrAirSp);
	m_strSmfdAdc203 = m_edt_SmfdRc_PressAlti;
	m_strSmfdAdc205 = m_edt_SmfdRc_MachNum;
	m_strSmfdAdc206 = m_edt_SmfdRc_CompAirSp;
	m_strSmfdAdc212 = m_edt_SmfdRc_AltiRate;
	m_strSmfdAdc213 = m_edt_SmfdRc_StaAirTemp;
	m_strSmfdAdc210 = m_edt_SmfdRc_TrAirSp;

	if(a1==5000)
	{
		m_strStatusSmfdAdc203 = "OK";
	}else
	{
		g_strMsgStr = "Altitude value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc203 = "NOT OK";
	}
	/////////////////////////
		if(a2==0.5)
	{
		m_strStatusSmfdAdc205 = "OK";
	}else
	{
		g_strMsgStr = "Mach value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc205 = "NOT OK";
	}

	/////////////////////////
		if(a3==100)
	{
		m_strStatusSmfdAdc206 = "OK";
	}else
	{
		g_strMsgStr = "Airspeed value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc206 = "NOT OK";
	}

	/////////////////////////
		if(a4==1500)
	{
		m_strStatusSmfdAdc212 = "OK";
	}else
	{
		g_strMsgStr = "Altutude Rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc212 = "NOT OK";
	}

	/////////////////////////
		if(a5==25)
	{
		m_strStatusSmfdAdc213 = "OK";
	}else
	{
		g_strMsgStr = "Static Air Temp value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc213 = "NOT OK";
	}

	/////////////////////////
		if(a6==100)
	{
		m_strStatusSmfdAdc210 = "OK";
	}else
	{
		g_strMsgStr = "True Airspeed value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc210 = "NOT OK";
	}
	CDialogEx::OnOK();
}


UINT CDialog_Smfd_Adc_RC::ArincRXThread(LPVOID pParam)
{
	CDialog_Smfd_Adc_RC* pDlg = (CDialog_Smfd_Adc_RC*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}


void CDialog_Smfd_Adc_RC::ExecuteArincRX()
{
	float value = 0.0f;

	while (!m_bStopThread)
	{
		ADT_L0_UINT32 Labels[6];
		Labels[0] = 0xE09C40C1;    // LABEL_203, 5000 ft
		Labels[1] =	0x61F400A1;		//0.5 count 32000 0x61F400A1
		Labels[2] =	0xE1900061; 	//100 count 25600 0xE1900061
		Labels[3] =	0xFFA24051;	    //-1500 count -6000 0xFFA24051
		Labels[4] =	0x60C800D1; 	//25 count 12800 0x60C800D1
		Labels[5] =	0x60C80011;  	//100 count 12800 0x60C80011
		gArinc429.SendLabels(3, Labels, 6);
		
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On CDialogSmfd_ADC::ExecuteArincRX ::::::::::::::: Sending DATA ");
		
			ReadSMFDRX(8);

			if (GetARINCValue(8, LABEL_203, &value))
				m_edt_SmfdRc_PressAlti.Format("%.0f", value);

			if (GetARINCValue(8, LABEL_205, &value))
				m_edt_SmfdRc_MachNum.Format("%.2f", value);

			if (GetARINCValue(8, LABEL_206, &value))
				m_edt_SmfdRc_CompAirSp.Format("%.0f", value);

			if (GetARINCValue(8, LABEL_212, &value))
				m_edt_SmfdRc_AltiRate.Format("%.0f", value);

			if (GetARINCValue(8, LABEL_213, &value))
				m_edt_SmfdRc_StaAirTemp.Format("%.0f", value);

			if (GetARINCValue(8, LABEL_210, &value))
				m_edt_SmfdRc_TrAirSp.Format("%.0f", value);
		}

		if(!g_bSimulationMode)
		{
			gArinc429.SendLabels(4, Labels, 6); //SMFD
			//Send same data to SMFD & MFD FC to reflect data on SMFD, SMFD send to MFD, no direct communication to MFD from IAT
		}

		if (::IsWindow(m_hWnd))
			PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}


LRESULT CDialog_Smfd_Adc_RC::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}

void CDialog_Smfd_Adc_RC::OnDestroy()
{
	m_bStopThread = TRUE;

	if (m_pArincRXThread != NULL)
	{
		WaitForSingleObject(m_pArincRXThread->m_hThread, INFINITE);
		delete m_pArincRXThread;
		m_pArincRXThread = NULL;
	}

	m_bThreadRunning = FALSE;

	CloseRx(8);

	CDialog::OnDestroy();
}

void CDialog_Smfd_Adc_RC::OnBnClickedButtonRcarinc()
{
	// TODO: Add your control notification handler code here
		
if (m_bThreadRunning)
		return;


	ShowSimulationLoopbackNotice(_T("SMFD"), SMFD_SIM_LOOPBACK_TX_CHANNEL_X,
                                 SMFD_SIM_LOOPBACK_TX_CHANNEL_Y, SMFD_SIM_LOOPBACK_RX_PIN_P,
                                 SMFD_SIM_LOOPBACK_RX_PIN_Q);


	InitArincRX(8);//change

	m_bStopThread = FALSE;
	m_bThreadRunning = TRUE;

	m_pArincRXThread = AfxBeginThread(
		ArincRXThread,
		this,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);

	if (m_pArincRXThread == NULL)
	{
		m_bThreadRunning = FALSE;
		AfxMessageBox("Unable to start ARINC RX thread.");
		return;
	}

	m_pArincRXThread->m_bAutoDelete = FALSE;
	m_pArincRXThread->ResumeThread();


	//SendArincLabel();
}
