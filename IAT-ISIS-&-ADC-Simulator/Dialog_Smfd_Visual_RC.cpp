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
	, m_ctlChk_mfd_pNo(FALSE)
	, m_ctlChk_smfd_pNo(FALSE)
	, m_ctlChk_smfd_damage(FALSE)
	, m_chkSmfdScratches(FALSE)
	, m_chkSmfdScrews(FALSE)
	, m_chkSmfdPins(FALSE)
	, m_edt_mfd_rc_pn(_T(""))
	, m_edt_smfd_rc_pn(_T(""))
	, m_edt_SmfdRc_PartNo(_T(""))
	, m_edt_MfdRc_PartNo(_T(""))
{
}

CDialog_Smfd_Visual_RC::~CDialog_Smfd_Visual_RC()
{
}

void CDialog_Smfd_Visual_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_DAMAGE, m_ctlChk_smfd_damage);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_SCRATCHES, m_chkSmfdScratches);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_SCREW, m_chkSmfdScrews);
	DDX_Check(pDX, IDC_CHECK_SMFD_RC_PINS, m_chkSmfdPins);

	DDX_Text(pDX, IDC_EDIT_SMFD_RC_PN, m_edt_smfd_rc_pn);
	DDX_Text(pDX, IDC_EDIT_MFD_RC_PN, m_edt_mfd_rc_pn);
}

BEGIN_MESSAGE_MAP(CDialog_Smfd_Visual_RC, CDialog)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_DAMAGE, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdDamage)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Visual_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_SCRATCHES, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScratches)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_SCREW, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScrew)
	ON_BN_CLICKED(IDC_CHECK_SMFD_RC_PINS, &CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdPins)
	ON_EN_CHANGE(IDC_EDIT_SMFD_RC_PN, &CDialog_Smfd_Visual_RC::OnEnChangeEditSmfdRcPn)
END_MESSAGE_MAP()

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdDamage()
{
	UpdateData(TRUE);

	if (m_ctlChk_smfd_damage)
		GetDlgItem(IDC_CHECK_SMFD_RC_DAMAGE)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_DAMAGE)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScratches()
{
	UpdateData(TRUE);

	if (m_chkSmfdScratches)
		GetDlgItem(IDC_CHECK_SMFD_RC_SCRATCHES)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_SCRATCHES)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdScrew()
{
	UpdateData(TRUE);

	if (m_chkSmfdScrews)
		GetDlgItem(IDC_CHECK_SMFD_RC_SCREW)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_SCREW)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_RC::OnBnClickedCheckSmfdPins()
{
	UpdateData(TRUE);

	if (m_chkSmfdPins)
		GetDlgItem(IDC_CHECK_SMFD_RC_PINS)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_RC_PINS)->SetWindowText("Not Ok");

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

	if (m_ctlChk_mfd_pNo)
	{
		m_strMfdRcPNo.Format("Correct");
		m_strStatusMfdRcPNo.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("MFD RC Part Number is not Correct, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strMfdRcPNo.Format("Not Correct");
		m_strStatusMfdRcPNo.Format("NOT OK");
	}

	/*if (m_ctlChk_smfd_pNo)
	{
		m_strSmfdRcPNo.Format("Correct");
		m_strStatusSmfdRcPNo.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Part Number is not Correct, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdRcPNo.Format("Not Correct");
		m_strStatusSmfdRcPNo.Format("NOT OK");
	}*/

	if (m_ctlChk_smfd_damage)
	{
		m_strRcDamage.Format("OK");
		m_strStatusRcDamage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Damage is not ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcDamage.Format("NOT OK");
		m_strStatusRcDamage.Format("NOT OK");
	}

	if (m_chkSmfdScratches)
	{
		m_strRcScratches.Format("OK");
		m_strStatusRcScratches.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Scratches is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcScratches.Format("Not OK");
		m_strStatusRcScratches.Format("NOT OK");
	}

	if (m_chkSmfdScrews)
	{
		m_strRcScrews.Format("OK");
		m_strStatusRcScrews.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Screws is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcScrews.Format("Not OK");
		m_strStatusRcScrews.Format("NOT OK");
	}

	if (m_chkSmfdPins)
	{
		m_strRcPins.Format("OK");
		m_strStatusRcPins.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD RC Pins is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strRcPins.Format("Not OK");
		m_strStatusRcPins.Format("NOT OK");
	}

	CDialog::OnOK();
}



void CDialog_Smfd_Visual_RC::OnEnChangeEditSmfdRcPn()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	

	// TODO:  Add your control notification handler code here
}
