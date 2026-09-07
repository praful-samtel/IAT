// Dialog_SMFD_FC_ANLBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANLBP.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANLBP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANLBP, CDialogEx)

CDialog_SMFD_FC_ANLBP::CDialog_SMFD_FC_ANLBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANLBP::IDD, pParent)
	, m_edt_SMFDFC_LBP(_T(""))
{

}

CDialog_SMFD_FC_ANLBP::~CDialog_SMFD_FC_ANLBP()
{
}

void CDialog_SMFD_FC_ANLBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LHBRAKE, m_edt_SMFDFC_LBP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANLBP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCLBP, &CDialog_SMFD_FC_ANLBP::OnBnClickedButtonSmfdAnalogFclbp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANLBP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANLBP message handlers


void CDialog_SMFD_FC_ANLBP::OnBnClickedButtonSmfdAnalogFclbp()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANLBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
