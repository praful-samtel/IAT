// Dialog_SMFD_FC_ANFTR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANFTR.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANFTR dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANFTR, CDialogEx)

CDialog_SMFD_FC_ANFTR::CDialog_SMFD_FC_ANFTR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANFTR::IDD, pParent)
	, m_edt_SMFDFC_FTR(_T(""))
{

}

CDialog_SMFD_FC_ANFTR::~CDialog_SMFD_FC_ANFTR()
{
}

void CDialog_SMFD_FC_ANFTR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RHFUEL, m_edt_SMFDFC_FTR);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANFTR, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCFTR, &CDialog_SMFD_FC_ANFTR::OnBnClickedButtonSmfdAnalogFcftr)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANFTR::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANFTR message handlers





void CDialog_SMFD_FC_ANFTR::OnBnClickedButtonSmfdAnalogFcftr()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANFTR::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
