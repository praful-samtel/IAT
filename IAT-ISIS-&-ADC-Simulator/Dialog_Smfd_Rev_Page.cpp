// Dialog_Smfd_Rev_Page.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Rev_Page.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Rev_Page dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Rev_Page, CDialog)

CDialog_Smfd_Rev_Page::CDialog_Smfd_Rev_Page(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Rev_Page::IDD, pParent)
	, m_ctlChk_smfd_rev_page(FALSE)
{

}

CDialog_Smfd_Rev_Page::~CDialog_Smfd_Rev_Page()
{
}

void CDialog_Smfd_Rev_Page::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SMFD_REV_PAGE, m_ctlChk_smfd_rev_page);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Rev_Page, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Rev_Page::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_REV_PAGE, &CDialog_Smfd_Rev_Page::OnBnClickedCheckSmfdRevPage)
END_MESSAGE_MAP()


// CDialog_Smfd_Rev_Page message handlers


void CDialog_Smfd_Rev_Page::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	  CMessageBox_Dlg msgdlg;
	  UpdateData(TRUE);
		if (m_ctlChk_smfd_rev_page)
	{
		m_strSMFDRevPage.Format("Correct");
		m_strStatusSMFDRevPage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("Revisionary Page not Displayed, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strSMFDRevPage.Format("Not Correct");
		m_strStatusSMFDRevPage.Format("NOT OK");
	}
		UpdateData(FALSE);

	CDialog::OnOK();
}


void CDialog_Smfd_Rev_Page::OnBnClickedCheckSmfdRevPage()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if (m_ctlChk_smfd_rev_page)
	{
		GetDlgItem(IDC_CHECK_SMFD_REV_PAGE)-> SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_REV_PAGE)-> SetWindowText("Not Displayed");	
	}

	UpdateData(FALSE);
}
