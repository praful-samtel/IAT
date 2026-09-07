// Dialog_Smfd_AHRS_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_AHRS_RC.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_AHRS_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_AHRS_RC, CDialogEx)

CDialog_Smfd_AHRS_RC::CDialog_Smfd_AHRS_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_AHRS_RC::IDD, pParent)
	, m_edt_SmfdRc_MagHead(0)
	, m_edt_SmfdRc_PitAng(0)
	, m_edt_SmfdRc_RollAng(0)
	, m_edt_SmfdRc_NorAcc(0)
	, m_chkSmfdAhrs330RC(FALSE)
	, m_chkSmfdAhrs332RC(FALSE)
	, m_bThreadRunning(FALSE)
	, m_bStopThread(FALSE)
	, m_pArincRXThread(NULL)
{

}

CDialog_Smfd_AHRS_RC::~CDialog_Smfd_AHRS_RC()
{
}

void CDialog_Smfd_AHRS_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR320RC, m_edt_SmfdRc_MagHead);
	DDX_Text(pDX, IDC_EDIT_SMFDAR324RC, m_edt_SmfdRc_PitAng);
	DDX_Text(pDX, IDC_EDIT_SMFDAR325RC, m_edt_SmfdRc_RollAng);
	DDX_Text(pDX, IDC_EDIT_SMFDAR333RC, m_edt_SmfdRc_NorAcc);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS330RC, m_chkSmfdAhrs330RC);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS332RC, m_chkSmfdAhrs332RC);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_AHRS_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_AHRS_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS330RC, &CDialog_Smfd_AHRS_RC::OnBnClickedCheckSmfdAhrs330rc)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS332RC, &CDialog_Smfd_AHRS_RC::OnBnClickedCheckSmfdAhrs332rc)
	ON_BN_CLICKED(IDC_BUTTON_AHRS_RC, &CDialog_Smfd_AHRS_RC::OnBnClickedButtonAhrsRc)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_Smfd_AHRS_RC message handlers


void CDialog_Smfd_AHRS_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;
	m_strSmfdAhrs320.Format(_T("%d"), m_edt_SmfdRc_MagHead);
m_strSmfdAhrs324.Format(_T("%d"), m_edt_SmfdRc_PitAng);
m_strSmfdAhrs325.Format(_T("%d"), m_edt_SmfdRc_RollAng);
m_strSmfdAhrs333.Format(_T("%d"), m_edt_SmfdRc_NorAcc);
	if(m_edt_SmfdRc_MagHead==60)
	{   

		m_strStatusSmfdAhrs320 = "OK";
	}else
	{
		g_strMsgStr = "Heading value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs320 = "NOT OK";
	}
	/////////////////////////
		if(m_edt_SmfdRc_PitAng==20)
	{
		m_strStatusSmfdAhrs324 = "OK";
	}else
	{
		g_strMsgStr = "Pitch value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs324 = "NOT OK";
	}

	/////////////////////////
		if(m_edt_SmfdRc_RollAng==10)
	{
		m_strStatusSmfdAhrs325 = "OK";
	}else
	{
		g_strMsgStr = "Roll value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs325 = "NOT OK";
	}

	/////////////////////////
		if(m_chkSmfdAhrs330RC)
	{
		m_strSmfdAhrs330 = "Correct";
		m_strStatusSmfdAhrs330 = "OK";
	}else
	{
		g_strMsgStr = "Body yaw Rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strSmfdAhrs330 = "Not Correct";
		m_strStatusSmfdAhrs330 = "NOT OK";
	}

	/////////////////////////
		if(m_chkSmfdAhrs332RC)
	{
		m_strSmfdAhrs332 = "Correct";
		m_strStatusSmfdAhrs332 = "OK";
	}else
	{
		g_strMsgStr = "Lateral Acceleration value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
			m_strSmfdAhrs332 = "Not Correct";
		m_strStatusSmfdAhrs332 = "NOT OK";
	}

	/////////////////////////
		if(m_edt_SmfdRc_NorAcc==6)
	{
		
		m_strStatusSmfdAhrs333 = "OK";
	}else
	{
		g_strMsgStr = "Normal Acceleration value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs333 = "NOT OK";
	}
	CDialogEx::OnOK();
}


void CDialog_Smfd_AHRS_RC::OnBnClickedCheckSmfdAhrs330rc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chkSmfdAhrs330RC)
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS330RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS330RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_AHRS_RC::OnBnClickedCheckSmfdAhrs332rc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chkSmfdAhrs332RC)
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS332RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS332RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_AHRS_RC::OnBnClickedButtonAhrsRc()
{
	// TODO: Add your control notification handler code here
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
}


UINT CDialog_Smfd_AHRS_RC::ArincRXThread(LPVOID pParam)
{
	CDialog_Smfd_AHRS_RC* pDlg = (CDialog_Smfd_AHRS_RC*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}

void CDialog_Smfd_AHRS_RC::ExecuteArincRX()
{
	float value = 0.0f;

	while (!m_bStopThread)
	{
		ReadRX(8);

		if (GetARINCValue(8, LABEL_320, &value))
			m_edt_SmfdRc_MagHead = (int)value;

		if (GetARINCValue(8, LABEL_324, &value))
			m_edt_SmfdRc_PitAng = (int)value;

		if (GetARINCValue(8, LABEL_325, &value))
			m_edt_SmfdRc_RollAng = (int)value;

		if (GetARINCValue(8, LABEL_333, &value))
			m_edt_SmfdRc_NorAcc = (int)value;

		PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

LRESULT CDialog_Smfd_AHRS_RC::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}

void CDialog_Smfd_AHRS_RC::OnDestroy()
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