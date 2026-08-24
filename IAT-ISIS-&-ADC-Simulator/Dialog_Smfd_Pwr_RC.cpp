// Dialog_Smfd_Pwr_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Pwr_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Pwr_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Pwr_RC, CDialogEx)

CDialog_Smfd_Pwr_RC::CDialog_Smfd_Pwr_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Pwr_RC::IDD, pParent)
	, m_edt_SmfdRc_CurrCon(_T(""))
	, m_edt_MfdRc_CurrCon(_T(""))
{

}

CDialog_Smfd_Pwr_RC::~CDialog_Smfd_Pwr_RC()
{
}

void CDialog_Smfd_Pwr_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFD1_PWR_RC, m_edt_SmfdRc_CurrCon);
	DDX_Text(pDX, IDC_EDIT_SMFD2_PWR_RC, m_edt_MfdRc_CurrCon);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Pwr_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Pwr_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Pwr_RC message handlers


void CDialog_Smfd_Pwr_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
