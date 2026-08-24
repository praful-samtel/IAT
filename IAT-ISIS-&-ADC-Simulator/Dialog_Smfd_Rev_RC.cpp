// Dialog_Smfd_Rev_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Rev_RC.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CDialog_Smfd_Rev_RC message handlers


void CDialog_Smfd_Rev_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
