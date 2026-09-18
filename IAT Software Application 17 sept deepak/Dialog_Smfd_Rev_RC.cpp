// Dialog_Smfd_Rev_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Rev_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Rev_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Rev_RC, CDialogEx)

CDialog_Smfd_Rev_RC::CDialog_Smfd_Rev_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Rev_RC::IDD, pParent)
	, m_chk_SmfdRc_Rev(FALSE)
{

}

CDialog_Smfd_Rev_RC::~CDialog_Smfd_Rev_RC()
{
}

void CDialog_Smfd_Rev_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SMFD_REV_PAGE_RC, m_chk_SmfdRc_Rev);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Rev_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Rev_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_SMFD_REV_PAGE_RC, &CDialog_Smfd_Rev_RC::OnBnClickedCheckSmfdRevPage)
END_MESSAGE_MAP()


// CDialog_Smfd_Rev_RC message handlers


void CDialog_Smfd_Rev_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
	  UpdateData(TRUE);
		if (m_chk_SmfdRc_Rev)
	{
		m_strSMFDRevPage.Format("Operatinal");
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
		m_strSMFDRevPage.Format("Not Operatinal");
		m_strStatusSMFDRevPage.Format("NOT OK");
	}
		UpdateData(FALSE);
	CDialogEx::OnOK();
}


void CDialog_Smfd_Rev_RC::OnBnClickedCheckSmfdRevPage()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if (m_chk_SmfdRc_Rev)
	{
		GetDlgItem(IDC_CHECK_SMFD_REV_PAGE_RC)-> SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_REV_PAGE_RC)-> SetWindowText("Not Displayed");	
	}

	UpdateData(FALSE);
}
