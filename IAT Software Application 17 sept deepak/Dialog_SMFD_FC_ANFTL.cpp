// Dialog_SMFD_FC_ANFTL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANFTL.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANFTL dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANFTL, CDialogEx)

CDialog_SMFD_FC_ANFTL::CDialog_SMFD_FC_ANFTL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANFTL::IDD, pParent)
	, m_edt_SMFDFC_FTL(_T(""))
{

}

CDialog_SMFD_FC_ANFTL::~CDialog_SMFD_FC_ANFTL()
{
}

void CDialog_SMFD_FC_ANFTL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LHFUEL, m_edt_SMFDFC_FTL);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANFTL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCFTL, &CDialog_SMFD_FC_ANFTL::OnBnClickedButtonSmfdAnalogFcftl)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANFTL::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANFTL message handlers


void CDialog_SMFD_FC_ANFTL::OnBnClickedButtonSmfdAnalogFcftl()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANFTL::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
