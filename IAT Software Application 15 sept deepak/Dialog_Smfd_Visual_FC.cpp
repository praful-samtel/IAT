#include "stdafx.h"
#include "Dialog_Smfd_Visual_FC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_Smfd_Visual_FC, CDialog)

CDialog_Smfd_Visual_FC::CDialog_Smfd_Visual_FC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Visual_FC::IDD, pParent)
	, m_ctlChk_mfd_pNo(FALSE)
	, m_ctlChk_smfd_pNo(FALSE)
	, m_ctlChk_smfd_damage(FALSE)
	, m_chkSmfdScratches(FALSE)
	, m_chkSmfdScrews(FALSE)
	, m_chkSmfdPins(FALSE)
	, m_edt_mfd_fc_pn(_T(""))
	, m_edt_smfd_fc_pn(_T(""))
{
}

CDialog_Smfd_Visual_FC::~CDialog_Smfd_Visual_FC()
{
}

void CDialog_Smfd_Visual_FC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_MFD_FC_RESULT, m_ctlChk_mfd_pNo);
	DDX_Check(pDX, IDC_CHECK_SMFD_FC_RESULT, m_ctlChk_smfd_pNo);
	DDX_Check(pDX, IDC_CHECK_SMFD_FC_DAMAGE, m_ctlChk_smfd_damage);
	DDX_Check(pDX, IDC_CHECK_SMFD_FC_SCRATCHES, m_chkSmfdScratches);
	DDX_Check(pDX, IDC_CHECK_SMFD_FC_SCREW, m_chkSmfdScrews);
	DDX_Check(pDX, IDC_CHECK_SMFD_FC_PINS, m_chkSmfdPins);
	DDX_Text(pDX, IDC_EDIT_MFD_FC_PN, m_edt_mfd_fc_pn);
	DDX_Text(pDX, IDC_EDIT_SMFD_FC_PN, m_edt_smfd_fc_pn);
}

BEGIN_MESSAGE_MAP(CDialog_Smfd_Visual_FC, CDialog)
	ON_BN_CLICKED(IDC_CHECK_MFD_FC_RESULT, &CDialog_Smfd_Visual_FC::OnBnClickedCheckMfdVisual)
	ON_BN_CLICKED(IDC_CHECK_SMFD_FC_RESULT, &CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdVisual)
	ON_BN_CLICKED(IDC_CHECK_SMFD_FC_DAMAGE, &CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdDamage)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Visual_FC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_FC_SCRATCHES, &CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdScratches)
	ON_BN_CLICKED(IDC_CHECK_SMFD_FC_SCREW, &CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdScrew)
	ON_BN_CLICKED(IDC_CHECK_SMFD_FC_PINS, &CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdPins)
END_MESSAGE_MAP()

void CDialog_Smfd_Visual_FC::OnBnClickedCheckMfdVisual()
{
	UpdateData(TRUE);

	if (m_ctlChk_mfd_pNo)
		GetDlgItem(IDC_CHECK_MFD_FC_RESULT)->SetWindowText("Correct");
	else
		GetDlgItem(IDC_CHECK_MFD_FC_RESULT)->SetWindowText("Not Correct");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdVisual()
{
	UpdateData(TRUE);

	if (m_ctlChk_smfd_pNo)
		GetDlgItem(IDC_CHECK_SMFD_FC_RESULT)->SetWindowText("Correct");
	else
		GetDlgItem(IDC_CHECK_SMFD_FC_RESULT)->SetWindowText("Not Correct");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdDamage()
{
	UpdateData(TRUE);

	if (m_ctlChk_smfd_damage)
		GetDlgItem(IDC_CHECK_SMFD_FC_DAMAGE)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_FC_DAMAGE)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdScratches()
{
	UpdateData(TRUE);

	if (m_chkSmfdScratches)
		GetDlgItem(IDC_CHECK_SMFD_FC_SCRATCHES)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_FC_SCRATCHES)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdScrew()
{
	UpdateData(TRUE);

	if (m_chkSmfdScrews)
		GetDlgItem(IDC_CHECK_SMFD_FC_SCREW)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_FC_SCREW)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedCheckSmfdPins()
{
	UpdateData(TRUE);

	if (m_chkSmfdPins)
		GetDlgItem(IDC_CHECK_SMFD_FC_PINS)->SetWindowText("Ok");
	else
		GetDlgItem(IDC_CHECK_SMFD_FC_PINS)->SetWindowText("Not Ok");

	UpdateData(FALSE);
}

void CDialog_Smfd_Visual_FC::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;

	if (m_ctlChk_mfd_pNo)
	{
		m_strMfdPNo.Format("Correct");
		m_strStatusMfdPNo.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("MFD FC Part Number is not Correct, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strMfdPNo.Format("Not Correct");
		m_strStatusMfdPNo.Format("NOT OK");
	}

	if (m_ctlChk_smfd_pNo)
	{
		m_strSmfdPNo.Format("Correct");
		m_strStatusSmfdPNo.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD FC Part Number is not Correct, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdPNo.Format("Not Correct");
		m_strStatusSmfdPNo.Format("NOT OK");
	}

	if (m_ctlChk_smfd_damage)
	{
		m_strSmfdDamage.Format("OK");
		m_strStatusSmfdDamage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD FC Damage is not ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdDamage.Format("NOT OK");
		m_strStatusSmfdDamage.Format("NOT OK");
	}

	if (m_chkSmfdScratches)
	{
		m_strSmfdScratches.Format("OK");
		m_strStatusSmfdScratches.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD FC Scratches is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdScratches.Format("Not OK");
		m_strStatusSmfdScratches.Format("NOT OK");
	}

	if (m_chkSmfdScrews)
	{
		m_strSmfdScrews.Format("OK");
		m_strStatusSmfdScrews.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD FC Screws is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdScrews.Format("Not OK");
		m_strStatusSmfdScrews.Format("NOT OK");
	}

	if (m_chkSmfdPins)
	{
		m_strSmfdPins.Format("OK");
		m_strStatusSmfdPins.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("SMFD FC Pins is not Ok, Do You want to Continue?");
		msgdlg.DoModal();
		if (!g_bContinueFlag)
			return;
		m_strSmfdPins.Format("Not OK");
		m_strStatusSmfdPins.Format("NOT OK");
	}

	CDialog::OnOK();
}
