// Dialog_Smfd_Adc_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Adc_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Adc_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Adc_RC, CDialogEx)

CDialog_Smfd_Adc_RC::CDialog_Smfd_Adc_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Adc_RC::IDD, pParent)
	, m_edt_SmfdRc_PressAlti(_T(""))
	, m_edt_SmfdRc_MachNum(_T(""))
	, m_edt_SmfdRc_CompAirSp(_T(""))
	, m_edt_SmfdRc_AltiRate(_T(""))
	, m_edt_SmfdRc_StaAirTemp(_T(""))
	, m_edt_SmfdRc_TrAirSp(_T(""))
{

}

CDialog_Smfd_Adc_RC::~CDialog_Smfd_Adc_RC()
{
}

void CDialog_Smfd_Adc_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR203, m_edt_SmfdRc_PressAlti);
	DDX_Text(pDX, IDC_EDIT_SMFDAR205, m_edt_SmfdRc_MachNum);
	DDX_Text(pDX, IDC_EDIT_SMFDAR206, m_edt_SmfdRc_CompAirSp);
	DDX_Text(pDX, IDC_EDIT_SMFDAR212, m_edt_SmfdRc_AltiRate);
	DDX_Text(pDX, IDC_EDIT_SMFDAR213, m_edt_SmfdRc_StaAirTemp);
	DDX_Text(pDX, IDC_EDIT_SMFDAR210, m_edt_SmfdRc_TrAirSp);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Adc_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Adc_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Adc_RC message handlers


void CDialog_Smfd_Adc_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
