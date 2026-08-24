// Dialog_Smfd_AHRS_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_AHRS_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_AHRS_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_AHRS_RC, CDialogEx)

CDialog_Smfd_AHRS_RC::CDialog_Smfd_AHRS_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_AHRS_RC::IDD, pParent)
	, m_edt_SmfdRc_MagHead(_T(""))
	, m_edt_SmfdRc_PitAng(_T(""))
	, m_edt_SmfdRc_RollAng(_T(""))
	, m_edt_SmfdRc_NorAcc(_T(""))
{

}

CDialog_Smfd_AHRS_RC::~CDialog_Smfd_AHRS_RC()
{
}

void CDialog_Smfd_AHRS_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR320, m_edt_SmfdRc_MagHead);
	DDX_Text(pDX, IDC_EDIT_SMFDAR324, m_edt_SmfdRc_PitAng);
	DDX_Text(pDX, IDC_EDIT_SMFDAR325, m_edt_SmfdRc_RollAng);
	DDX_Text(pDX, IDC_EDIT_SMFDAR333, m_edt_SmfdRc_NorAcc);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_AHRS_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_AHRS_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_AHRS_RC message handlers


void CDialog_Smfd_AHRS_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
