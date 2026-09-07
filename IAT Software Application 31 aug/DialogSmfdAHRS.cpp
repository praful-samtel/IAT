// DialogSmfdAHRS.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfdAHRS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include "Arinc429.h"

extern CSerialPort gCommPort1;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialogSmfdAHRS, CDialog)

CDialogSmfdAHRS::CDialogSmfdAHRS(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfdAHRS::IDD, pParent)
	, m_edtSmfdArinc320(0)
	, m_edtSmfdArinc324(0)
	, m_edtSmfdArinc325(0)
	, m_edtSmfdArinc333(0)
	, m_chkSmfdAhrs330(FALSE)
	, m_chkSmfdAhrs332(FALSE)
	, dataArinc(0.0f)
	, m_bThreadRunning(FALSE)
	, m_bStopThread(FALSE)
	, m_pArincRXThread(NULL)
{
}

CDialogSmfdAHRS::~CDialogSmfdAHRS()
{
}

void CDialogSmfdAHRS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR320, m_edtSmfdArinc320);
	DDX_Text(pDX, IDC_EDIT_SMFDAR324, m_edtSmfdArinc324);
	DDX_Text(pDX, IDC_EDIT_SMFDAR325, m_edtSmfdArinc325);
	DDX_Text(pDX, IDC_EDIT_SMFDAR333, m_edtSmfdArinc333);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS330, m_chkSmfdAhrs330);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS332, m_chkSmfdAhrs332);
}

BEGIN_MESSAGE_MAP(CDialogSmfdAHRS, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfdAHRS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SEND_ARINCLABEL, &CDialogSmfdAHRS::OnBnClickedButtonSendArinclabel)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS330, &CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs330)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS332, &CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs332)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CDialogSmfdAHRS::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}

void CDialogSmfdAHRS::OnBnClickedOk()
{
	UpdateData(TRUE);

	CMessageBox_Dlg msgdlg;
	m_strSmfdAhrs320.Format(_T("%d"), m_edtSmfdArinc320);
m_strSmfdAhrs324.Format(_T("%d"), m_edtSmfdArinc324);
m_strSmfdAhrs325.Format(_T("%d"), m_edtSmfdArinc325);
m_strSmfdAhrs333.Format(_T("%d"), m_chkSmfdAhrs332);
	if (m_edtSmfdArinc320 == 60)
	{
		m_strStatusSmfdAhrs320 = "OK";
	}
	else
	{
		g_strMsgStr = "Heading value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs320 = "NOT OK";
	}

	if (m_edtSmfdArinc324 == 20)
	{
		m_strStatusSmfdAhrs324 = "OK";
	}
	else
	{
		g_strMsgStr = "Pitch value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs324 = "NOT OK";
	}

	if (m_edtSmfdArinc325 == 10)
	{
		m_strStatusSmfdAhrs325 = "OK";
	}
	else
	{
		g_strMsgStr = "Roll value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs325 = "NOT OK";
	}

	if (m_chkSmfdAhrs330)
	{
		m_strStatusSmfdAhrs330 = "OK";
	}
	else
	{
		g_strMsgStr = "Body yaw Rate value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs330 = "NOT OK";
	}

	if (m_chkSmfdAhrs332)
	{
		m_strStatusSmfdAhrs332 = "OK";
	}
	else
	{
		g_strMsgStr = "Lateral Acceleration value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs332 = "NOT OK";
	}

	if (m_edtSmfdArinc333 == 6)
	{
		m_strStatusSmfdAhrs333 = "OK";
	}
	else
	{
		g_strMsgStr = "Normal Acceleration value invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusSmfdAhrs333 = "NOT OK";
	}

	CDialog::OnOK();
}

void CDialogSmfdAHRS::OnBnClickedButtonSendArinclabel()
{
	if (m_bThreadRunning)
		return;

	InitArincRX(8); //change

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
}

UINT CDialogSmfdAHRS::ArincRXThread(LPVOID pParam)
{
	CDialogSmfdAHRS* pDlg = (CDialogSmfdAHRS*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}

void CDialogSmfdAHRS::ExecuteArincRX()
{
	float value = 0.0f;

	while (!m_bStopThread)
	{
		ReadRX(8);

		if (GetARINCValue(8, LABEL_320, &value))
			m_edtSmfdArinc320 = (int)value;

		if (GetARINCValue(8, LABEL_324, &value))
			m_edtSmfdArinc324 = (int)value;

		if (GetARINCValue(8, LABEL_325, &value))
			m_edtSmfdArinc325 = (int)value;

		if (GetARINCValue(8, LABEL_333, &value))
			m_edtSmfdArinc333 = (int)value;

		PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

LRESULT CDialogSmfdAHRS::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}

void CDialogSmfdAHRS::OnDestroy()
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

void CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs330()
{
	UpdateData(TRUE);

	if (m_chkSmfdAhrs330)
		GetDlgItem(IDC_CHECK_SMFD_AHRS330)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_AHRS330)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs332()
{
	UpdateData(TRUE);

	if (m_chkSmfdAhrs332)
		GetDlgItem(IDC_CHECK_SMFD_AHRS332)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_AHRS332)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}