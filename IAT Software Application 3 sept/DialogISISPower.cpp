// DialogISISPower.cpp : implementation file
//

#include "stdafx.h"
#include "DialogISISPower.h"
#include "afxdialogex.h"


// CDialogISISPower dialog

IMPLEMENT_DYNAMIC(CDialogISISPower, CDialogEx)

CDialogISISPower::CDialogISISPower(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogISISPower::IDD, pParent)
{

}

CDialogISISPower::~CDialogISISPower()
{
}

void CDialogISISPower::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_EDIT_ISIS_PWR, m_ctlChkPwr);
}


BEGIN_MESSAGE_MAP(CDialogISISPower, CDialogEx)
	ON_BN_CLICKED(ID_BTN_ISIS_PWR, &CDialogISISPower::OnBnClickedBtnIsisPwr)
	ON_BN_CLICKED(IDC_EDIT_ISIS_PWR, &CDialogISISPower::OnBnClickedBtnIsisPwr)
END_MESSAGE_MAP()


// CDialogISISPower message handlers


void CDialogISISPower::OnBnClickedBtnIsisPwr()
{
	// TODO: Add your control notification handler code here


}
