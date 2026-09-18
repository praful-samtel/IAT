// Dialog_SMFD_FC_ET.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ET.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ET dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ET, CDialogEx)

CDialog_SMFD_FC_ET::CDialog_SMFD_FC_ET(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ET::IDD, pParent)
	, m_edt_SMFDFC_ET(_T(""))
{

}

CDialog_SMFD_FC_ET::~CDialog_SMFD_FC_ET()
{
}

void CDialog_SMFD_FC_ET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TORQUE, m_edt_SMFDFC_ET);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ET, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCET, &CDialog_SMFD_FC_ET::OnBnClickedButtonSmfdAnalogFcet)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ET::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ET message handlers


void CDialog_SMFD_FC_ET::OnBnClickedButtonSmfdAnalogFcet()
{
	// TODO: Add your control notification handler code here

	 UpdateData(TRUE);
	m_edt_SMFDFC_ET = "1740";


	  UpdateData(FALSE);
}


void CDialog_SMFD_FC_ET::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	    // -------- TORQUE --------
    val = _tstof(m_edt_SMFDFC_ET);
    if (val >= 1736 && val <= 1744)
    {
        m_strtorque = m_edt_SMFDFC_ET;
        m_strStatustorque = "OK";
    }
    else
    {
        g_strMsgStr = "Torque invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strtorque = m_edt_SMFDFC_ET;
        m_strStatustorque = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}
