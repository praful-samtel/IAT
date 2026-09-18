// Dialog_Smfd_Sw_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Sw_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Sw_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Sw_RC, CDialogEx)

CDialog_Smfd_Sw_RC::CDialog_Smfd_Sw_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Sw_RC::IDD, pParent)
	, m_edt_SmfdRc_OpSw(_T(""))
{

}

CDialog_Smfd_Sw_RC::~CDialog_Smfd_Sw_RC()
{
}

void CDialog_Smfd_Sw_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFD_SW_RC, m_edt_SmfdRc_OpSw);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Sw_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Sw_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Sw_RC message handlers


void CDialog_Smfd_Sw_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;
	if(m_edt_SmfdRc_OpSw == "E73D5822")
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
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
