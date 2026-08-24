// Dialog_Smfd_Discrete_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Discrete_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Discrete_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Discrete_RC, CDialogEx)

CDialog_Smfd_Discrete_RC::CDialog_Smfd_Discrete_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Discrete_RC::IDD, pParent)
	, m_chk_SmfdRc_BusTie(FALSE)
	, m_chk_SmfdRc_Canopy(FALSE)
	, m_chk_SmfdRc_EcsOff(FALSE)
	, m_chk_SmfdRc_EcsOvPr(FALSE)
	, m_chk_SmfdRc_AoaMute(FALSE)
	, m_chk_SmfdRc_Demist(FALSE)
	, m_chk_SmfdRc_StOn(FALSE)
{

}

CDialog_Smfd_Discrete_RC::~CDialog_Smfd_Discrete_RC()
{
}

void CDialog_Smfd_Discrete_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BUSTIE_RC, m_chk_SmfdRc_BusTie);
	DDX_Check(pDX, IDC_CHECK_CANOPY_RC, m_chk_SmfdRc_Canopy);
	DDX_Check(pDX, IDC_CHECK_ECSOFF_RC, m_chk_SmfdRc_EcsOff);
	DDX_Check(pDX, IDC_CHECK_ECSOVPR_RC, m_chk_SmfdRc_EcsOvPr);
	DDX_Check(pDX, IDC_CHECK_AOAMUTE_RC, m_chk_SmfdRc_AoaMute);
	DDX_Control(pDX, IDC_CHECK_ALARMMUTE_RC, m_chk_SmfdRc_AlMu);
	DDX_Check(pDX, IDC_CHECK_DEMIST_RC, m_chk_SmfdRc_Demist);
	DDX_Check(pDX, IDC_CHECK_STARTON_RC, m_chk_SmfdRc_StOn);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Discrete_RC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BUSTIE, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonBustie)
	ON_BN_CLICKED(IDC_BUTTON_CANOPY, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonCanopy)
	ON_BN_CLICKED(IDC_CHECK_ECSOFF_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsoffRc)
END_MESSAGE_MAP()


// CDialog_Smfd_Discrete_RC message handlers


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonBustie()
{
	// TODO: Add your control notification handler code here
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonCanopy()
{
	// TODO: Add your control notification handler code here
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsoffRc()
{
	// TODO: Add your control notification handler code here
}
