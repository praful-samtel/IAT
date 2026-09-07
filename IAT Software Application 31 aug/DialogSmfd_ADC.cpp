// DialogSmfd_ADC.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfd_ADC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include "Arinc429.h"
#include "Globals.h"

extern CSerialPort gCommPort1;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialogSmfd_ADC, CDialog)

CDialogSmfd_ADC::CDialogSmfd_ADC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfd_ADC::IDD, pParent)
	, m_edtSmfdArinc203(_T(""))
	, m_edtSmfdArinc205(_T(""))
	, m_edtSmfdArinc206(_T(""))
	, m_edtSmfdArinc212(_T(""))
	, m_edtSmfdArinc213(_T(""))
	, m_edtSmfdArinc210(_T(""))
	, dataArinc(0.0f)
	, m_bThreadRunning(FALSE)
	, m_bStopThread(FALSE)
	, m_pArincRXThread(NULL)
{
}

CDialogSmfd_ADC::~CDialogSmfd_ADC()
{
}

void CDialogSmfd_ADC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR203, m_edtSmfdArinc203);
	DDX_Text(pDX, IDC_EDIT_SMFDAR205, m_edtSmfdArinc205);
	DDX_Text(pDX, IDC_EDIT_SMFDAR206, m_edtSmfdArinc206);
	DDX_Text(pDX, IDC_EDIT_SMFDAR212, m_edtSmfdArinc212);
	DDX_Text(pDX, IDC_EDIT_SMFDAR213, m_edtSmfdArinc213);
	DDX_Text(pDX, IDC_EDIT_SMFDAR210, m_edtSmfdArinc210);
}

BEGIN_MESSAGE_MAP(CDialogSmfd_ADC, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfd_ADC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINC_LABEL, &CDialogSmfd_ADC::OnBnClickedButtonSendarincLabel)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

void CDialogSmfd_ADC::OnBnClickedOk()
{
	UpdateData(TRUE);

	CMessageBox_Dlg msgdlg;

	double a1 = atof(m_edtSmfdArinc203);
	double a2 = atof(m_edtSmfdArinc205);
	double a3 = atof(m_edtSmfdArinc206);
	double a4 = atof(m_edtSmfdArinc212);
	double a5 = atof(m_edtSmfdArinc213);
	double a6 = atof(m_edtSmfdArinc210);

	m_strSmfdAdc203 = m_edtSmfdArinc203;
	m_strSmfdAdc205 = m_edtSmfdArinc205;
	m_strSmfdAdc206 = m_edtSmfdArinc206;
	m_strSmfdAdc212 = m_edtSmfdArinc212;
	m_strSmfdAdc213 = m_edtSmfdArinc213;
	m_strSmfdAdc210 = m_edtSmfdArinc210;

	if (a1 == 5000)
		m_strStatusSmfdAdc203 = "OK";
	else
	{
		g_strMsgStr = "Altitude value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc203 = "NOT OK";
	}

	if (a2 == 0.5)
		m_strStatusSmfdAdc205 = "OK";
	else
	{
		g_strMsgStr = "Mach value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc205 = "NOT OK";
	}

	if (a3 == 100)
		m_strStatusSmfdAdc206 = "OK";
	else
	{
		g_strMsgStr = "Airspeed value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc206 = "NOT OK";
	}

	if (a4 == 1500)
		m_strStatusSmfdAdc212 = "OK";
	else
	{
		g_strMsgStr = "Altitude Rate value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc212 = "NOT OK";
	}

	if (a5 == 25)
		m_strStatusSmfdAdc213 = "OK";
	else
	{
		g_strMsgStr = "Static Air Temp value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc213 = "NOT OK";
	}

	if (a6 == 100)
		m_strStatusSmfdAdc210 = "OK";
	else
	{
		g_strMsgStr = "True Airspeed value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAdc210 = "NOT OK";
	}

	CDialog::OnOK();
}

BOOL CDialogSmfd_ADC::OnInitDialog()
{
	CDialog::OnInitDialog();

	
	return TRUE;
}

UINT CDialogSmfd_ADC::ArincRXThread(LPVOID pParam)
{
	CDialogSmfd_ADC* pDlg = (CDialogSmfd_ADC*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}

void CDialogSmfd_ADC::ExecuteArincRX()
{
	float value = 0.0f;

	while (!m_bStopThread)
	{
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On CDialogSmfd_ADC::ExecuteArincRX ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			Labels[0] = 0xE1900061;    // LABEL_206, 100 knots
			gArinc429.SendLabels(3, Labels, 1);
		}


		ReadSMFDRX(8);

		if (GetARINCValue(8, LABEL_203, &value))
			m_edtSmfdArinc203.Format("%.0f", value);

		if (GetARINCValue(8, LABEL_205, &value))
			m_edtSmfdArinc205.Format("%.2f", value);

		if (GetARINCValue(8, LABEL_206, &value))
			m_edtSmfdArinc206.Format("%.0f", value);

		if (GetARINCValue(8, LABEL_212, &value))
			m_edtSmfdArinc212.Format("%.0f", value);

		if (GetARINCValue(8, LABEL_213, &value))
			m_edtSmfdArinc213.Format("%.0f", value);

		if (GetARINCValue(8, LABEL_210, &value))
			m_edtSmfdArinc210.Format("%.0f", value);

		if (::IsWindow(m_hWnd))
			PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

LRESULT CDialogSmfd_ADC::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}

void CDialogSmfd_ADC::OnDestroy()
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

void CDialogSmfd_ADC::OnBnClickedButtonSendarincLabel()
{
	
if (m_bThreadRunning)
		return;

	InitArincRX(8);

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



	// SendArincLabel();
}