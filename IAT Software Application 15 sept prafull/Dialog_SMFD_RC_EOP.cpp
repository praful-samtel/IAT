// Dialog_SMFD_RC_EOP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_EOP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_EOP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_EOP, CDialogEx)

CDialog_SMFD_RC_EOP::CDialog_SMFD_RC_EOP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_EOP::IDD, pParent)
	, m_edt_SmfdRc_EnOilPress(_T(""))
{

}

CDialog_SMFD_RC_EOP::~CDialog_SMFD_RC_EOP()
{
}

void CDialog_SMFD_RC_EOP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCOILPRES, m_edt_SmfdRc_EnOilPress);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_EOP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCEOP, &CDialog_SMFD_RC_EOP::OnBnClickedButtonSmfdAnalogRceop)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_EOP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_EOP message handlers


void CDialog_SMFD_RC_EOP::OnBnClickedButtonSmfdAnalogRceop()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	 m_edt_SmfdRc_EnOilPress = "41";
	 UpdateData(FALSE);
}


void CDialog_SMFD_RC_EOP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;


    // -------- OIL PRESSURE --------
    val = _tstof(m_edt_SmfdRc_EnOilPress);
    if (val >= 37 && val <= 43)
    {
        m_stroilpressure = m_edt_SmfdRc_EnOilPress;
        m_strStatusoilpressure = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Pressure out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroilpressure = m_edt_SmfdRc_EnOilPress;
        m_strStatusoilpressure = "NOT OK";
    }
	UpdateData(FALSE);

	CDialogEx::OnOK();
}
