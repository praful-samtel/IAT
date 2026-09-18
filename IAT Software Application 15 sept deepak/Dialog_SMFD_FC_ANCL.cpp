// Dialog_SMFD_FC_ANCL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANCL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ANCL dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANCL, CDialogEx)

CDialog_SMFD_FC_ANCL::CDialog_SMFD_FC_ANCL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANCL::IDD, pParent)
	, m_edt_SMFDFC_CL(_T(""))
{

}

CDialog_SMFD_FC_ANCL::~CDialog_SMFD_FC_ANCL()
{
}

void CDialog_SMFD_FC_ANCL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CURR, m_edt_SMFDFC_CL);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANCL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCCL, &CDialog_SMFD_FC_ANCL::OnBnClickedButtonSmfdAnalogFccl)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANCL::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANCL message handlers


void CDialog_SMFD_FC_ANCL::OnBnClickedButtonSmfdAnalogFccl()
{
	// TODO: Add your control notification handler code here
		  UpdateData(TRUE);
	  m_edt_SMFDFC_CL = "200";


	  UpdateData(FALSE);
}


void CDialog_SMFD_FC_ANCL::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	    //// -------- CURRENT LOAD --------
    val = _tstof(m_edt_SMFDFC_CL);
    if (val >= 190 && val <= 210)
    {
        m_strcurload = m_edt_SMFDFC_CL;
        m_strStatuscurload = "OK";
    }
    else
    {
        g_strMsgStr = "Current load invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strcurload = m_edt_SMFDFC_CL;
        m_strStatuscurload = "NOT OK";
    }
	    UpdateData(FALSE);
	CDialogEx::OnOK();
}
