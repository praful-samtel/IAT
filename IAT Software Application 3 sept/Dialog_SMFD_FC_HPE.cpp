// Dialog_SMFD_FC_HPE.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_HPE.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_HPE dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_HPE, CDialogEx)

CDialog_SMFD_FC_HPE::CDialog_SMFD_FC_HPE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_HPE::IDD, pParent)
	, m_edt_SMFDFC_HPE(_T(""))
{

}

CDialog_SMFD_FC_HPE::~CDialog_SMFD_FC_HPE()
{
}

void CDialog_SMFD_FC_HPE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HYDPRESEMER, m_edt_SMFDFC_HPE);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_HPE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCHPE, &CDialog_SMFD_FC_HPE::OnBnClickedButtonSmfdAnalogFchpe)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_HPE::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_HPE message handlers


void CDialog_SMFD_FC_HPE::OnBnClickedButtonSmfdAnalogFchpe()
{
	// TODO: Add your control notification handler code here

}


void CDialog_SMFD_FC_HPE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
	    // -------- HYD PRES EMER --------
   int val = atoi(m_edt_SMFDFC_HPE);
    if (val >= 3310 && val <= 3350)
    {
        m_strHydPresEmer = m_edt_SMFDFC_HPE;
        m_strStatusHydPresEmer = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Emergency Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresEmer = m_edt_SMFDFC_HPE;
        m_strStatusHydPresEmer = "NOT OK";
    }

	  UpdateData(FALSE);
	CDialogEx::OnOK();
}
