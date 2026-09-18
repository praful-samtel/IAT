// Dialog_SMFD_FC_ANGV.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANGV.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ANGV dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANGV, CDialogEx)

CDialog_SMFD_FC_ANGV::CDialog_SMFD_FC_ANGV(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANGV::IDD, pParent)
	, m_edt_SMFDFC_GV(_T(""))
{

}

CDialog_SMFD_FC_ANGV::~CDialog_SMFD_FC_ANGV()
{
}

void CDialog_SMFD_FC_ANGV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GENERAL_V, m_edt_SMFDFC_GV);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANGV, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCGV, &CDialog_SMFD_FC_ANGV::OnBnClickedButtonSmfdAnalogFcgv)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANGV::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANGV message handlers


void CDialog_SMFD_FC_ANGV::OnBnClickedButtonSmfdAnalogFcgv()
{
	// TODO: Add your control notification handler code here
		 UpdateData(TRUE);
	m_edt_SMFDFC_GV = "28";
		UpdateData(FALSE);
}


void CDialog_SMFD_FC_ANGV::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;


	  //// -------- GENERATOR VOLTAGE --------
    val = _tstof(m_edt_SMFDFC_GV);
    if (val >= 27 && val <= 29)
    {
        m_strgenvolt = m_edt_SMFDFC_GV;
        m_strStatusgenvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Generator voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strgenvolt = m_edt_SMFDFC_GV;
        m_strStatusgenvolt = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
