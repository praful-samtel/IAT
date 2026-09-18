// Dialog_SMFD_FC_FP3.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_FP3.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_FP3 dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_FP3, CDialogEx)

CDialog_SMFD_FC_FP3::CDialog_SMFD_FC_FP3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_FP3::IDD, pParent)
	, m_edt_SMFDFC_FP3(_T(""))
{

}

CDialog_SMFD_FC_FP3::~CDialog_SMFD_FC_FP3()
{
}

void CDialog_SMFD_FC_FP3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FLAT3V, m_edt_SMFDFC_FP3);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_FP3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCFP3, &CDialog_SMFD_FC_FP3::OnBnClickedButtonSmfdAnalogFcfp3)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_FP3::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_FP3 message handlers


void CDialog_SMFD_FC_FP3::OnBnClickedButtonSmfdAnalogFcfp3()
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
m_edt_SMFDFC_FP3 = "green";


	  UpdateData(FALSE);
}


void CDialog_SMFD_FC_FP3::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	    //// -------- FLAP 3V --------
    if (m_edt_SMFDFC_FP3.Find("green") != -1)
    {
        m_strflap3v = m_edt_SMFDFC_FP3;
        m_strStatusflap3v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap3v = m_edt_SMFDFC_FP3;
        m_strStatusflap3v = "NOT OK";
    }


	UpdateData(FALSE);
	CDialogEx::OnOK();
}
