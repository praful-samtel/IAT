// Dialog_SMFD_FC_ETP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ETP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_FC_ETP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ETP, CDialogEx)

CDialog_SMFD_FC_ETP::CDialog_SMFD_FC_ETP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ETP::IDD, pParent)
	, m_edt_SMFDFC_ETP(_T(""))
{

}

CDialog_SMFD_FC_ETP::~CDialog_SMFD_FC_ETP()
{
}

void CDialog_SMFD_FC_ETP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ELEVATOR, m_edt_SMFDFC_ETP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ETP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCETP, &CDialog_SMFD_FC_ETP::OnBnClickedButtonSmfdAnalogFcetp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ETP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ETP message handlers


void CDialog_SMFD_FC_ETP::OnBnClickedButtonSmfdAnalogFcetp()
{
	// TODO: Add your control notification handler code here
	
	 UpdateData(TRUE);
m_edt_SMFDFC_ETP = "green";


	  UpdateData(FALSE);

}


void CDialog_SMFD_FC_ETP::OnBnClickedOk()
{

	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	// TODO: Add your control notification handler code here
	  //// -------- ELEVATOR --------
    if (m_edt_SMFDFC_ETP.Find("green") != -1)
    {
        m_strelevator = m_edt_SMFDFC_ETP;
        m_strStatuselevator = "OK";
    }
    else
    {
        g_strMsgStr = "Elevator value incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strelevator = m_edt_SMFDFC_ETP;
        m_strStatuselevator = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}
