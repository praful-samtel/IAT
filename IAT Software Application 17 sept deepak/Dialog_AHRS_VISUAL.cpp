#include "stdafx.h"
#include "Dialog_AHRS_VISUAL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_AHRS_VISUAL, CDialog)

CDialog_AHRS_VISUAL::CDialog_AHRS_VISUAL(CWnd* pParent)
	: CDialog(CDialog_AHRS_VISUAL::IDD, pParent)
	, m_ctlChkAHRUPNO(FALSE)
	, m_ctlChkRMMPNO(FALSE)
	, m_ctlChkMMSPNO(FALSE)
	, m_chkAHRSDamage(FALSE)
	, m_chkAHRSScratches(FALSE)
	, m_chkAHRSScrews(FALSE)
	, m_chkAHRSPins(FALSE)
	, m_edtAHRUPno(_T(""))
	, m_edtRMMPno(_T(""))
	, m_edtMMSPno(_T(""))
{
}

CDialog_AHRS_VISUAL::~CDialog_AHRS_VISUAL()
{
}

void CDialog_AHRS_VISUAL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_PN_AHRU, m_ctlChkAHRUPNO);
	DDX_Check(pDX, IDC_CHECK_PN_RMM, m_ctlChkRMMPNO);
	DDX_Check(pDX, IDC_CHECK_PN_MMS, m_ctlChkMMSPNO);
	DDX_Check(pDX, IDC_CHECK_AHRS_DAMAGE, m_chkAHRSDamage);
	DDX_Check(pDX, IDC_CHECK_AHRS_SCRATCHES, m_chkAHRSScratches);
	DDX_Check(pDX, IDC_CHECK_AHRS_SCREW, m_chkAHRSScrews);
	DDX_Check(pDX, IDC_CHECK_AHRS_PINS, m_chkAHRSPins);
	DDX_Text(pDX, IDC_EDIT_AHRS_AHRUPNO, m_edtAHRUPno);
	DDX_Text(pDX, IDC_EDIT_AHRS_RMMPNO, m_edtRMMPno);
	DDX_Text(pDX, IDC_EDIT_AHRS_MMSPNO, m_edtMMSPno);
}

BEGIN_MESSAGE_MAP(CDialog_AHRS_VISUAL, CDialog)
	ON_BN_CLICKED(IDC_CHECK_PN_AHRU, &CDialog_AHRS_VISUAL::OnBnClickedCheckPnAhru)
	ON_BN_CLICKED(IDC_CHECK_PN_RMM, &CDialog_AHRS_VISUAL::OnBnClickedCheckPnRmm)
	ON_BN_CLICKED(IDC_CHECK_PN_MMS, &CDialog_AHRS_VISUAL::OnBnClickedCheckPnMms)
	ON_BN_CLICKED(IDOK, &CDialog_AHRS_VISUAL::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_AHRS_DAMAGE, &CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsDamage)
	ON_BN_CLICKED(IDC_CHECK_AHRS_SCRATCHES, &CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsScratches)
	ON_BN_CLICKED(IDC_CHECK_AHRS_SCREW, &CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsScrew)
	ON_BN_CLICKED(IDC_CHECK_AHRS_PINS, &CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsPins)
END_MESSAGE_MAP()

// ---------------- CHECK HANDLERS ----------------

void CDialog_AHRS_VISUAL::OnBnClickedCheckPnAhru()
{
	UpdateData(TRUE);

	if (m_ctlChkAHRUPNO)
		GetDlgItem(IDC_CHECK_PN_AHRU)->SetWindowText("Correct");
	else
		GetDlgItem(IDC_CHECK_PN_AHRU)->SetWindowText("Not Correct");

	UpdateData(FALSE);
}

void CDialog_AHRS_VISUAL::OnBnClickedCheckPnRmm()
{
	UpdateData(TRUE);

	if (m_ctlChkRMMPNO)
		GetDlgItem(IDC_CHECK_PN_RMM)->SetWindowText("Correct");
	else
		GetDlgItem(IDC_CHECK_PN_RMM)->SetWindowText("Not Correct");

	UpdateData(FALSE);
}

void CDialog_AHRS_VISUAL::OnBnClickedCheckPnMms()
{
	UpdateData(TRUE);

	if (m_ctlChkMMSPNO)
		GetDlgItem(IDC_CHECK_PN_MMS)->SetWindowText("Correct");
	else
		GetDlgItem(IDC_CHECK_PN_MMS)->SetWindowText("Not Correct");

	UpdateData(FALSE);
}

// ---------------- MAIN LOGIC ----------------

void CDialog_AHRS_VISUAL::OnBnClickedOk()
{
	UpdateData(TRUE);

	CMessageBox_Dlg msgdlg;

	// ---------- AHRU ----------
	if (m_edtAHRUPno.Compare("420-00332-440") == 0)
	{
		m_strAHRUPtNo = "Correct";
		m_strStatusAHRUPtNo = "OK";
	}
	else
	{
		g_strMsgStr = "AHRU Part Number is incorrect. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strAHRUPtNo = "Not Correct";
		m_strStatusAHRUPtNo = "NOT OK";
	}

	// ---------- RMM ----------
	if (m_edtRMMPno.Compare("420-01867-310") == 0)
	{
		m_strRMMPtNo = "Correct";
		m_strStatusRMMPtNo = "OK";
	}
	else
	{
		g_strMsgStr = "RMM Part Number is incorrect. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strRMMPtNo = "Not Correct";
		m_strStatusRMMPtNo = "NOT OK";
	}

	// ---------- MMS ----------
	if (m_edtMMSPno.Compare("420-00339-000") == 0)
	{
		m_strMMSPtNo = "Correct";
		m_strStatusMMSPtNo = "OK";
	}
	else
	{
		g_strMsgStr = "MMS Part Number is incorrect. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;

		m_strMMSPtNo = "Not Correct";
		m_strStatusMMSPtNo = "NOT OK";
	}

	// ---------- DAMAGE CHECK ----------
	// You don’t have checkbox → assume based on all OK
	if (!m_chkAHRSDamage)
	{
		m_strAHRSDamage = "NO";
		m_strStatusAHRSDamage = "OK";
	}
	else
	{   g_strMsgStr = "AHRS System is Damaged. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;
		m_strAHRSDamage = "YES";
		m_strStatusAHRSDamage = "NOT OK";
	}
	///
	if (!m_chkAHRSScratches)
	{
		m_strAHRSScratches = "NO";
		m_strStatusAHRSScratches = "OK";
	}
	else
	{   g_strMsgStr = "AHRS system has Foreign Material. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;
		m_strAHRSScratches = "YES";
		m_strStatusAHRSScratches = "NOT OK";
	}
	///
	if (!m_chkAHRSScrews)
	{
		m_strAHRSScrews = "NO";
		m_strStatusAHRSScrews = "OK";
	}
	else
	{   g_strMsgStr = "AHRS system has loose screws. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;
		m_strAHRSScrews = "YES";
		m_strStatusAHRSScrews = "NOT OK";
	}
		///
	if (!m_chkAHRSPins)
	{
		m_strAHRSPins = "NO";
		m_strStatusAHRSPins = "OK";
	}
	else
	{   g_strMsgStr = "AHRS system Connectors has bend pins. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag) return;
		m_strAHRSPins = "YES";
		m_strStatusAHRSPins = "NOT OK";
	}
	UpdateData(FALSE);


	CDialog::OnOK();
}

void CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsDamage()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkAHRSDamage)
		GetDlgItem(IDC_CHECK_AHRS_DAMAGE)->SetWindowText("YES");
	else
		GetDlgItem(IDC_CHECK_AHRS_DAMAGE)->SetWindowText("NO");

	UpdateData(FALSE);
}


void CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsScratches()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkAHRSScratches)
		GetDlgItem(IDC_CHECK_AHRS_SCRATCHES)->SetWindowText("YES");
	else
		GetDlgItem(IDC_CHECK_AHRS_SCRATCHES)->SetWindowText("NO");

	UpdateData(FALSE);
}


void CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsScrew()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkAHRSScrews)
		GetDlgItem(IDC_CHECK_AHRS_SCREW)->SetWindowText("YES");
	else
		GetDlgItem(IDC_CHECK_AHRS_SCREW)->SetWindowText("NO");

	UpdateData(FALSE);
}


void CDialog_AHRS_VISUAL::OnBnClickedCheckAhrsPins()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkAHRSPins)
		GetDlgItem(IDC_CHECK_AHRS_PINS)->SetWindowText("YES");
	else
		GetDlgItem(IDC_CHECK_AHRS_PINS)->SetWindowText("NO");

	UpdateData(FALSE);
}
