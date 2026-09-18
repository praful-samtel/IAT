// Dialog_SMFD_FC_ANEB.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANEB.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANEB dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANEB, CDialogEx)

CDialog_SMFD_FC_ANEB::CDialog_SMFD_FC_ANEB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANEB::IDD, pParent)
	, m_edt_SMFDFC_EB(_T(""))
{

}

CDialog_SMFD_FC_ANEB::~CDialog_SMFD_FC_ANEB()
{
}

void CDialog_SMFD_FC_ANEB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ACCUMPRES, m_edt_SMFDFC_EB);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANEB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCEB, &CDialog_SMFD_FC_ANEB::OnBnClickedButtonSmfdAnalogFceb)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANEB::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANEB message handlers


void CDialog_SMFD_FC_ANEB::OnBnClickedButtonSmfdAnalogFceb()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANEB::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
