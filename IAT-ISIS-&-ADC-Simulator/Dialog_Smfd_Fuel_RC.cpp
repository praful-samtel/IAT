// Dialog_Smfd_Fuel_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Fuel_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Fuel_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Fuel_RC, CDialogEx)

CDialog_Smfd_Fuel_RC::CDialog_Smfd_Fuel_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Fuel_RC::IDD, pParent)
	, m_edt_SmfdRc_Fuel(_T(""))
	, m_edt_SmfdRc_FuelResponse(_T(""))
{

}

CDialog_Smfd_Fuel_RC::~CDialog_Smfd_Fuel_RC()
{
}

void CDialog_Smfd_Fuel_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1_RC, m_edt_SmfdRc_Fuel);
	DDX_Text(pDX, IDC_EDIT2_RC, m_edt_SmfdRc_FuelResponse);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Fuel_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Fuel_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Fuel_RC message handlers


void CDialog_Smfd_Fuel_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
