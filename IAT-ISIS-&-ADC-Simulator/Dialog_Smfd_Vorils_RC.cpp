// Dialog_Smfd_Vorils_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Vorils_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Vorils_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Vorils_RC, CDialogEx)

CDialog_Smfd_Vorils_RC::CDialog_Smfd_Vorils_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Vorils_RC::IDD, pParent)
	, m_edt_SmfdRc_VorFreq(_T(""))
	, m_edt_SmfdRc_ILSFreq(_T(""))
	, m_edt_SmfdRc_VorBear(_T(""))
	, m_chk_SmfdRc_LocDev(FALSE)
	, m_chk_SmfdRc_GlidDev(FALSE)
{

}

CDialog_Smfd_Vorils_RC::~CDialog_Smfd_Vorils_RC()
{
}

void CDialog_Smfd_Vorils_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VORFREQ_RC, m_edt_SmfdRc_VorFreq);
	DDX_Text(pDX, IDC_EDIT_ILSFREQ_RC, m_edt_SmfdRc_ILSFreq);
	DDX_Text(pDX, IDC_EDIT_VORBRG_RC, m_edt_SmfdRc_VorBear);
	DDX_Check(pDX, IDC_CHECK_LOCALIZER_RC, m_chk_SmfdRc_LocDev);
	DDX_Check(pDX, IDC_CHECK_GLIDESLOPE_RC, m_chk_SmfdRc_GlidDev);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Vorils_RC, CDialogEx)
END_MESSAGE_MAP()


// CDialog_Smfd_Vorils_RC message handlers
