// Dialog_SMFD_FC_ANCT.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANCT.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ANCT dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANCT, CDialogEx)

CDialog_SMFD_FC_ANCT::CDialog_SMFD_FC_ANCT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANCT::IDD, pParent)
	, m_edt_SMFDFC_CT(_T(""))
{

}

CDialog_SMFD_FC_ANCT::~CDialog_SMFD_FC_ANCT()
{
}

void CDialog_SMFD_FC_ANCT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_COLLECTORANK, m_edt_SMFDFC_CT);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANCT, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCCT, &CDialog_SMFD_FC_ANCT::OnBnClickedButtonSmfdAnalogFcct)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANCT::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANCT message handlers


void CDialog_SMFD_FC_ANCT::OnBnClickedButtonSmfdAnalogFcct()
{
	// TODO: Add your control notification handler code here

}


void CDialog_SMFD_FC_ANCT::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	  UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	    //// -------- CURRENT LOAD --------
   /* val = _tstof(m_edt_SMFDFC_CT);
    if (val >= 190 && val <= 210)
    {
        m_strcurload = m_edt_SMFDFC_CT;
        m_strStatuscurload = "OK";
    }
    else
    {
        g_strMsgStr = "Current load invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strcurload = m_edt_SMFDFC_CT;
        m_strStatuscurload = "NOT OK";
    }*/
	    UpdateData(FALSE);
	CDialogEx::OnOK();
}
