#include "stdafx.h"
#include "Dlg_ISIS_AHRS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDlg_ISIS_AHRS, CDialog)

CDlg_ISIS_AHRS::CDlg_ISIS_AHRS(CWnd* pParent)
	: CDialog(CDlg_ISIS_AHRS::IDD, pParent)
	, m_bRoll(FALSE)
	, m_bPitch(FALSE)
	, m_bHeading(FALSE)
	, m_bRollRC(FALSE)
	, m_bPitchRC(FALSE)
	, m_bHeadingRC(FALSE)
{
}

CDlg_ISIS_AHRS::~CDlg_ISIS_AHRS()
{
}

void CDlg_ISIS_AHRS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSROLL, m_bRoll);
	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSPITCH, m_bPitch);
	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSHEAD, m_bHeading);
	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSROLL2, m_bRollRC);
	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSPITCH2, m_bPitchRC);
	DDX_Check(pDX, IDC_CHECK_ISIS_AHRSHEAD2, m_bHeadingRC);
}

BEGIN_MESSAGE_MAP(CDlg_ISIS_AHRS, CDialog)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSROLL, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrsroll)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSPITCH, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrspitch)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSHEAD, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrshead)
	ON_BN_CLICKED(IDOK, &CDlg_ISIS_AHRS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSROLL2, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrsroll2)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSPITCH2, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrspitch2)
	ON_BN_CLICKED(IDC_CHECK_ISIS_AHRSHEAD2, &CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrshead2)
END_MESSAGE_MAP()

BOOL CDlg_ISIS_AHRS::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}

// ---------------- CHECK HANDLERS ----------------

void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrsroll()
{
	UpdateData(TRUE);

	if (m_bRoll)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSROLL, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSROLL, "Not Operational");
	UpdateData(FALSE);
}

void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrspitch()
{
	UpdateData(TRUE);

	if (m_bPitch)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSPITCH, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSPITCH, "Not Operational");
	UpdateData(FALSE);
}

void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrshead()
{
	UpdateData(TRUE);

	if (m_bHeading)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSHEAD, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSHEAD, "Not Operational");

	UpdateData(FALSE);
}

// ---------------- OK BUTTON ----------------



void CDlg_ISIS_AHRS::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   // 🔥 VERY IMPORTANT

	CMessageBox_Dlg msgdlg;

	// -------- ROLL --------
	if (m_bRoll)
	{
		m_strISISRoll = "OK";
		m_strStatusISISRoll = "OK";
	}
	else
	{
		g_strMsgStr = "8.01 AHRS Roll Angle is not correct on ISIS-DU FC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISRoll = "Not OK";
		m_strStatusISISRoll = "NOT OK";
	}

	// -------- PITCH --------
	if (m_bPitch)
	{
		m_strISISPitch = "OK";
		m_strStatusISISPitch = "OK";
	}
	else
	{
		g_strMsgStr = "8.02 AHRS Pitch Angle is not correct on ISIS-DU FC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISPitch = "Not OK";
		m_strStatusISISPitch = "NOT OK";
	}

	// -------- HEADING --------
	if (m_bHeading)
	{
		m_strISISHeading = "OK";
		m_strStatusISISHeading = "OK";
	}
	else
	{
		g_strMsgStr = "8.03 AHRS Heading is not correct on ISIS-DU FC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISHeading = "Not OK";
		m_strStatusISISHeading = "NOT OK";
	}


		// -------- ROLL  RC--------
	if (m_bRollRC)
	{
		m_strISISRollRC = "OK";
		m_strStatusISISRollRC = "OK";
	}
	else
	{
		g_strMsgStr = "8.04 AHRS Roll Angle is not correct on ISIS-DU RC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISRollRC = "Not OK";
		m_strStatusISISRollRC = "NOT OK";
	}

	// -------- PITCH --------
	if (m_bPitchRC)
	{
		m_strISISPitchRC = "OK";
		m_strStatusISISPitchRC = "OK";
	}
	else
	{
		g_strMsgStr = "8.05 AHRS Pitch Angle is not correct on ISIS-DU RC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISPitchRC = "Not OK";
		m_strStatusISISPitchRC = "NOT OK";
	}

	// -------- HEADING --------
	if (m_bHeadingRC)
	{
		m_strISISHeadingRC = "OK";
		m_strStatusISISHeadingRC = "OK";
	}
	else
	{
		g_strMsgStr = "8.06 AHRS Heading is not correct on ISIS-DU RC. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strISISHeadingRC = "Not OK";
		m_strStatusISISHeadingRC = "NOT OK";
	}
	UpdateData(FALSE);

	CDialog::OnOK();
}


void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrsroll2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_bRollRC)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSROLL2, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSROLL2, "Not Operational");
	UpdateData(FALSE);
}


void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrspitch2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_bPitchRC)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSPITCH2, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSPITCH2, "Not Operational");
	UpdateData(FALSE);
}


void CDlg_ISIS_AHRS::OnBnClickedCheckIsisAhrshead2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_bHeadingRC)
		SetDlgItemText(IDC_CHECK_ISIS_AHRSHEAD2, "Operational");
	else
		SetDlgItemText(IDC_CHECK_ISIS_AHRSHEAD2, "Not Operational");

	UpdateData(FALSE);
}
