// Dialog_SMFD_SW.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_SW.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_SMFD_SW dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_SW, CDialog)

CDialog_SMFD_SW::CDialog_SMFD_SW(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_SMFD_SW::IDD, pParent)
	, m_edtSmfdSw(_T(""))
{

}

CDialog_SMFD_SW::~CDialog_SMFD_SW()
{
}

void CDialog_SMFD_SW::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFD_SW, m_edtSmfdSw);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_SW, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_SW::OnBnClickedOk)
	
END_MESSAGE_MAP()


// CDialog_SMFD_SW message handlers


void CDialog_SMFD_SW::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CMessageBox_Dlg msgdlg;
	if(m_edtSmfdSw == "E73D5822")
	{  
		 m_strSmfdSw = "Correct";
		m_strStatusSmfdSw = "OK";
		
	}
	else
	{  
		g_strMsgStr = "SMFD SW Configuration is not correct. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;
		m_strSmfdSw = "Not Correct";
		m_strStatusSmfdSw = "NOT OK";
	}
	CDialog::OnOK();
}


