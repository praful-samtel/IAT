// Dialog_SMFD_FC_CL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_CL.h"
#include "afxdialogex.h"


// CDialog_SMFD_FC_CL dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_CL, CDialogEx)

CDialog_SMFD_FC_CL::CDialog_SMFD_FC_CL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_CL::IDD, pParent)
{

}

CDialog_SMFD_FC_CL::~CDialog_SMFD_FC_CL()
{
}

void CDialog_SMFD_FC_CL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_CL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCCL, &CDialog_SMFD_FC_CL::OnBnClickedButtonSmfdAnalogRccl)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_CL message handlers


void CDialog_SMFD_FC_CL::OnBnClickedButtonSmfdAnalogRccl()
{
	// TODO: Add your control notification handler code here
}
