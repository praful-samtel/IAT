// Dialog_SMFD_FC_ANRBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANRBP.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANRBP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANRBP, CDialogEx)

CDialog_SMFD_FC_ANRBP::CDialog_SMFD_FC_ANRBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANRBP::IDD, pParent)
	, m_edt_SMFDFC_RBP(_T(""))
{

}

CDialog_SMFD_FC_ANRBP::~CDialog_SMFD_FC_ANRBP()
{
}

void CDialog_SMFD_FC_ANRBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RHBRAKE, m_edt_SMFDFC_RBP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANRBP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCRBP, &CDialog_SMFD_FC_ANRBP::OnBnClickedButtonSmfdAnalogFcrbp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANRBP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANRBP message handlers


void CDialog_SMFD_FC_ANRBP::OnBnClickedButtonSmfdAnalogFcrbp()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANRBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
