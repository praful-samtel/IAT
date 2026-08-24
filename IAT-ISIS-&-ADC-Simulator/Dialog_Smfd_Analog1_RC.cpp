// Dialog_Smfd_Analog1_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog1_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Analog1_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog1_RC, CDialogEx)

CDialog_Smfd_Analog1_RC::CDialog_Smfd_Analog1_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Analog1_RC::IDD, pParent)
	, m_edt_SmfdRc_HyPrMain(_T(""))
	, m_edt_SmfdRc_HyPrEm(_T(""))
	, m_edt_SmfdRc_EmBr(_T(""))
	, m_edt_SmfdRc_LHBr(_T(""))
	, m_edt_SmfdRc_RhBr(_T(""))
	, m_edt_SmfdRc_EnSpeed(_T(""))
	, m_edt_SmfdRc_FuelTankLH(_T(""))
	, m_edt_SmfdRc_FuelTankRH(_T(""))
	, m_edt_SmfdRc_CoTank(_T(""))
{

}

CDialog_Smfd_Analog1_RC::~CDialog_Smfd_Analog1_RC()
{
}

void CDialog_Smfd_Analog1_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HYDPRESMAIN, m_edt_SmfdRc_HyPrMain);
	DDX_Text(pDX, IDC_EDIT_HYDPRESEMER, m_edt_SmfdRc_HyPrEm);
	DDX_Text(pDX, IDC_EDIT_ACCUMPRES, m_edt_SmfdRc_EmBr);
	DDX_Text(pDX, IDC_EDIT_LHBRAKE, m_edt_SmfdRc_LHBr);
	DDX_Text(pDX, IDC_EDIT_RHBRAKE, m_edt_SmfdRc_RhBr);
	DDX_Text(pDX, IDC_EDIT_ENGSPD, m_edt_SmfdRc_EnSpeed);
	DDX_Text(pDX, IDC_EDIT_LHFUEL, m_edt_SmfdRc_FuelTankLH);
	DDX_Text(pDX, IDC_EDIT_RHFUEL, m_edt_SmfdRc_FuelTankRH);
	DDX_Text(pDX, IDC_EDIT_COLLECTORANK, m_edt_SmfdRc_CoTank);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog1_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog1_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog1_RC message handlers


void CDialog_Smfd_Analog1_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
