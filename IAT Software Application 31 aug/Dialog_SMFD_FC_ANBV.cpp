// Dialog_SMFD_FC_ANBV.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANBV.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ANBV dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANBV, CDialogEx)

CDialog_SMFD_FC_ANBV::CDialog_SMFD_FC_ANBV(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANBV::IDD, pParent)
	, m_edt_SMFDFC_BV(_T(""))
{

}

CDialog_SMFD_FC_ANBV::~CDialog_SMFD_FC_ANBV()
{
}

void CDialog_SMFD_FC_ANBV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BATTERY_VOLT, m_edt_SMFDFC_BV);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANBV, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCBV, &CDialog_SMFD_FC_ANBV::OnBnClickedButtonSmfdAnalogFcbv)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANBV::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANBV message handlers


void CDialog_SMFD_FC_ANBV::OnBnClickedButtonSmfdAnalogFcbv()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	 m_edt_SMFDFC_BV = "28";
	 	 UpdateData(FALSE);

}


void CDialog_SMFD_FC_ANBV::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	   UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	//// -------- BATTERY VOLTAGE --------
    val = _tstof(m_edt_SMFDFC_BV);
    if (val >= 27 && val <= 29)
    {
        m_strbatvolt = m_edt_SMFDFC_BV;
        m_strStatusbatvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Battery voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strbatvolt = m_edt_SMFDFC_BV;
        m_strStatusbatvolt = "NOT OK";
    }
	 UpdateData(FALSE);
	CDialogEx::OnOK();
}
