// Dialog_SMFD_FC_ANES.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANES.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_ANES dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANES, CDialogEx)

CDialog_SMFD_FC_ANES::CDialog_SMFD_FC_ANES(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANES::IDD, pParent)
	, m_edt_SMFDFC_ES(_T(""))
{

}

CDialog_SMFD_FC_ANES::~CDialog_SMFD_FC_ANES()
{
}

void CDialog_SMFD_FC_ANES::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ENGSPD, m_edt_SMFDFC_ES);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANES, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCES, &CDialog_SMFD_FC_ANES::OnBnClickedButtonSmfdAnalogFces)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANES::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANES message handlers


void CDialog_SMFD_FC_ANES::OnBnClickedButtonSmfdAnalogFces()
{
	// TODO: Add your control notification handler code here
}


void CDialog_SMFD_FC_ANES::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
