#include "stdafx.h"
#include "Dialog_Smfd_Visual_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "resource.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_Smfd_Visual_RC, CDialog)

CDialog_Smfd_Visual_RC::CDialog_Smfd_Visual_RC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Visual_RC::IDD, pParent)

	, m_Chk_smfdRcdamage(FALSE)
	, m_chkSmfdRcScratches(FALSE)
	, m_chkSmfdRcScrews(FALSE)
	, m_chkSmfdRcPins(FALSE)
	, m_edt_mfd_rc_pn(_T(""))
	, m_edt_smfd_rc_pn(_T(""))

	
{
}

CDialog_Smfd_Visual_RC::~CDialog_Smfd_Visual_RC()
{
}

void CDialog_Smfd_Visual_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_DAMAGE, m_Chk_smfdRcdamage);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_SCRATCHES, m_chkSmfdRcScratches);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_SCREW, m_chkSmfdRcScrews);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_PINS, m_chkSmfdRcPins);

	DDX_Text(pDX, IDC_EDIT_SMFD_RC_PN, m_edt_smfd_rc_pn);
	DDX_Text(pDX, IDC_EDIT_MFD_RC_PN, m_edt_mfd_rc_pn);
}

BEGIN_MESSAGE_MAP(CDialog_Smfd_Visual_RC, CDialog)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_DAMAGE, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdDamage)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Visual_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_SCRATCHES, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScratches)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_SCREW, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScrew)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_PINS, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdPins)

END_MESSAGE_MAP()

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdDamage()
{
	UpdateData(TRUE);

	if (!m_Chk_smfdRcdamage)
		GetDlgItem(IDC_CHECK_SMFD_RC_DAMAGE)->SetWindowText("NO");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_DAMAGE)->SetWindowText("YES");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScratches()
{
	UpdateData(TRUE);

	if (!m_chkSmfdRcScratches)
		GetDlgItem(IDC_CHECK_SMFD_RC_SCRATCHES)->SetWindowText("NO");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_SCRATCHES)->SetWindowText("YES");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScrew()
{
	UpdateData(TRUE);

	if (!m_chkSmfdRcScrews)
		GetDlgItem(IDC_CHECK_SMFD_RC_SCREW)->SetWindowText("NO");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_SCREW)->SetWindowText("YES");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdPins()
{
	UpdateData(TRUE);

	if (!m_chkSmfdRcPins)
		GetDlgItem(IDC_CHECK_SMFD_RC_PINS)->SetWindowText("NO");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_PINS)->SetWindowText("YES");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;

	// -------- MFD PART NUMBER --------
    if (m_edt_mfd_rc_pn == "100-604077-000")
    {
        m_strMfdRcPNo.Format("Correct");
        m_strStatusMfdRcPNo.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("MFD Part Number is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strMfdRcPNo.Format("Not Correct");
        m_strStatusMfdRcPNo.Format("NOT OK");
    }

    // -------- SMFD PART NUMBER --------
    if (m_edt_smfd_rc_pn == "100-604078-000")
    {
        m_strSmfdRcPNo.Format("Correct");
        m_strStatusSmfdRcPNo.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("SMFD Part Number is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdRcPNo.Format("Not Correct");
        m_strStatusSmfdRcPNo.Format("NOT OK");
    }

	

	if (!m_Chk_smfdRcdamage)
	{
		m_strRcDamage.Format("NO");
		m_strStatusRcDamage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Damage is not ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcDamage.Format("YES");
		m_strStatusRcDamage.Format("NOT OK");
	}

	if (!m_chkSmfdRcScratches)
	{
		m_strRcScratches.Format("NO");
		m_strStatusRcScratches.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Scratches is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcScratches.Format("YES");
		m_strStatusRcScratches.Format("NOT OK");
	}

	if (!m_chkSmfdRcScrews)
	{
		m_strRcScrews.Format("NO");
		m_strStatusRcScrews.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Screws is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcScrews.Format("YES");
		m_strStatusRcScrews.Format("NOT OK");
	}

	if (!m_chkSmfdRcPins)
	{
		m_strRcPins.Format("NO");
		m_strStatusRcPins.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Pins is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcPins.Format("YES");
		m_strStatusRcPins.Format("NOT OK");
	}

	CDialog::OnOK();
}



