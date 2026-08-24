// Dialog_Smfd_Tacan_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Tacan_RC.h"
#include "afxdialogex.h"


// CDialog_Smfd_Tacan_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Tacan_RC, CDialog)

CDialog_Smfd_Tacan_RC::CDialog_Smfd_Tacan_RC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Tacan_RC::IDD, pParent)
	, m_edt_SmfdRc_TacConWord(_T(""))
	, m_edt_SmfdRc_TacDis(_T(""))
	, m_edt_SmfdRc_TacBear(_T(""))
{

}

CDialog_Smfd_Tacan_RC::~CDialog_Smfd_Tacan_RC()
{
}

void CDialog_Smfd_Tacan_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TAC145_RC, m_edt_SmfdRc_TacConWord);
	DDX_Text(pDX, IDC_EDIT_TAC201_RC, m_edt_SmfdRc_TacDis);
	DDX_Text(pDX, IDC_EDIT_TAC222_RC, m_edt_SmfdRc_TacBear);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Tacan_RC, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Tacan_RC::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Tacan_RC message handlers


void CDialog_Smfd_Tacan_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
