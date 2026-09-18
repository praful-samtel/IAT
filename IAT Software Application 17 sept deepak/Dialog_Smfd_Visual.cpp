// Dialog_Smfd_Visual.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Visual.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Visual dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Visual, CDialog)

CDialog_Smfd_Visual::CDialog_Smfd_Visual(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Visual::IDD, pParent)
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

CDialog_Smfd_Visual::~CDialog_Smfd_Visual()
{
}

void CDialog_Smfd_Visual::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SMFD_DAMAGE, m_ctlChk_smfd_damage);
	DDX_Check(pDX, IDC_CHECK_SMFD_SCRATCHES, m_chkSmfdScratches);
	DDX_Check(pDX, IDC_CHECK_SMFD_SCREW, m_chkSmfdScrews);
	DDX_Check(pDX, IDC_CHECK_SMFD_PINS, m_chkSmfdPins);
	DDX_Text(pDX, IDC_EDIT_MFD_FC_PN, m_edt_mfd_fc_pn);
	DDX_Text(pDX, IDC_EDIT_SMFD_FC_PN, m_edt_smfd_fc_pn);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Visual, CDialog)
	
	ON_BN_CLICKED(IDC_CHECK_SMFD_DAMAGE, &CDialog_Smfd_Visual::OnBnClickedCheckSmfdDamage)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Visual::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_SCRATCHES, &CDialog_Smfd_Visual::OnBnClickedCheckSmfdScratches)
	ON_BN_CLICKED(IDC_CHECK_SMFD_SCREW, &CDialog_Smfd_Visual::OnBnClickedCheckSmfdScrew)
	ON_BN_CLICKED(IDC_CHECK_SMFD_PINS, &CDialog_Smfd_Visual::OnBnClickedCheckSmfdPins)
END_MESSAGE_MAP()


// CDialog_Smfd_Visual message handlers




void CDialog_Smfd_Visual::OnBnClickedOk()
{ 
	UpdateData(TRUE);
    CMessageBox_Dlg msgdlg;

    // -------- MFD PART NUMBER --------
    if (m_edt_mfd_fc_pn == "100-604077-000")
    {
        m_strMfdPNo.Format("Correct");
        m_strStatusMfdPNo.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("MFD Part Number is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strMfdPNo.Format("Not Correct");
        m_strStatusMfdPNo.Format("NOT OK");
    }

    // -------- SMFD PART NUMBER --------
    if (m_edt_smfd_fc_pn == "100-604078-000")
    {
        m_strSmfdPNo.Format("Correct");
        m_strStatusSmfdPNo.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("SMFD Part Number is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdPNo.Format("Not Correct");
        m_strStatusSmfdPNo.Format("NOT OK");
    }

    // -------- SMFD DAMAGE --------
    if (!m_ctlChk_smfd_damage)
    {
        m_strSmfdDamage.Format("NO");
        m_strStatusSmfdDamage.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("corrosion/foreign material present on SMFD/MFD FCk, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdDamage.Format("YES");
        m_strStatusSmfdDamage.Format("NOT OK");
    }
	  if (!m_chkSmfdScratches)
    {
        m_strSmfdScratches.Format("NO");
        m_strStatusSmfdScratches.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("SMFD Scratches is not Ok, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdScratches.Format("Not OK");
        m_strStatusSmfdScratches.Format("NOT OK");
    }
	 if (!m_chkSmfdScrews)
    {
        m_strSmfdScrews.Format("NO");
        m_strStatusSmfdScrews.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("SMFD Screws is not Ok, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdScrews.Format("YES");
        m_strStatusSmfdScrews.Format("NOT OK");
    }

     if (!m_chkSmfdPins)
    {
        m_strSmfdPins.Format("NO");
        m_strStatusSmfdPins.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("SMFD Pins is not Ok, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strSmfdPins.Format("YES");
        m_strStatusSmfdPins.Format("NOT OK");
    }
	 UpdateData(FALSE);

    CDialog::OnOK();
}

void CDialog_Smfd_Visual::OnBnClickedCheckSmfdDamage()
{
    UpdateData(TRUE);

   if (!m_ctlChk_smfd_damage)
	{
		GetDlgItem(IDC_CHECK_SMFD_DAMAGE)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_DAMAGE)->SetWindowText("YES");
	}
    UpdateData(FALSE);
}

void CDialog_Smfd_Visual::OnBnClickedCheckSmfdScratches()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (!m_chkSmfdScratches)
	{
		GetDlgItem(IDC_CHECK_SMFD_SCRATCHES)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_SCRATCHES)->SetWindowText("YES");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Visual::OnBnClickedCheckSmfdScrew()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (!m_chkSmfdScrews)
	{
		GetDlgItem(IDC_CHECK_SMFD_SCREW)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_SCREW)->SetWindowText("YES");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Visual::OnBnClickedCheckSmfdPins()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (!m_chkSmfdPins)
	{
		GetDlgItem(IDC_CHECK_SMFD_PINS)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_PINS)->SetWindowText("YES");
	}
    UpdateData(FALSE);
}









