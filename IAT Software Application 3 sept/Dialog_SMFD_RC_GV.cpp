// Dialog_SMFD_RC_GV.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_GV.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_GV dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_GV, CDialogEx)

CDialog_SMFD_RC_GV::CDialog_SMFD_RC_GV(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_GV::IDD, pParent)
	, m_edt_SmfdRc_GenVol(_T(""))
{

}

CDialog_SMFD_RC_GV::~CDialog_SMFD_RC_GV()
{
}

void CDialog_SMFD_RC_GV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCGENERAL_V, m_edt_SmfdRc_GenVol);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_GV, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCGV, &CDialog_SMFD_RC_GV::OnBnClickedButtonSmfdAnalogRcgv)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_GV::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_GV message handlers


void CDialog_SMFD_RC_GV::OnBnClickedButtonSmfdAnalogRcgv()
{ 
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	m_edt_SmfdRc_GenVol = "28";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_GV::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;


    // -------- GENERATOR VOLTAGE --------
    val = _tstof(m_edt_SmfdRc_GenVol);
    if (val >= 27 && val <= 29)
    {
        m_strgenvolt = m_edt_SmfdRc_GenVol;
        m_strStatusgenvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Generator voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strgenvolt = m_edt_SmfdRc_GenVol;
        m_strStatusgenvolt = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
