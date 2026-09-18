// Dialog_SMFD_FC_FP4.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_FP4.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_FP4 dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_FP4, CDialogEx)

CDialog_SMFD_FC_FP4::CDialog_SMFD_FC_FP4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_FP4::IDD, pParent)
	, m_edt_SMFDFC_FP4(_T(""))
{

}

CDialog_SMFD_FC_FP4::~CDialog_SMFD_FC_FP4()
{
}

void CDialog_SMFD_FC_FP4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FLAP4V, m_edt_SMFDFC_FP4);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_FP4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCFP4, &CDialog_SMFD_FC_FP4::OnBnClickedButtonSmfdAnalogFcfp4)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_FP4::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_FP4 message handlers


void CDialog_SMFD_FC_FP4::OnBnClickedButtonSmfdAnalogFcfp4()
{
	// TODO: Add your control notification handler code here

		UpdateData(TRUE);
	m_edt_SMFDFC_FP4 = "yellow";


	  UpdateData(FALSE);
}


void CDialog_SMFD_FC_FP4::OnBnClickedOk()
{

	    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	// TODO: Add your control notification handler code here
	    //// -------- FLAP 4V --------
    if (m_edt_SMFDFC_FP4.Find("yellow") != -1)
    {
        m_strflap4v = m_edt_SMFDFC_FP4;
        m_strStatusflap4v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 4V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap4v = m_edt_SMFDFC_FP4;
        m_strStatusflap4v = "NOT OK";
    }

		    UpdateData(FALSE);
	CDialogEx::OnOK();
}
