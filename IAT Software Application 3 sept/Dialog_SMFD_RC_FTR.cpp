// Dialog_SMFD_RC_FTR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_FTR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_FTR dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_FTR, CDialogEx)

CDialog_SMFD_RC_FTR::CDialog_SMFD_RC_FTR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_FTR::IDD, pParent)
	, m_edt_SmfdRc_FuelTankRH(_T(""))
{

}

CDialog_SMFD_RC_FTR::~CDialog_SMFD_RC_FTR()
{
}

void CDialog_SMFD_RC_FTR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCRHFUEL, m_edt_SmfdRc_FuelTankRH);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_FTR, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCFTR, &CDialog_SMFD_RC_FTR::OnBnClickedButtonSmfdAnalogRcftr)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_FTR::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_FTR message handlers


void CDialog_SMFD_RC_FTR::OnBnClickedButtonSmfdAnalogRcftr()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		m_edt_SmfdRc_FuelTankRH = "162"; //168±5 lb
		UpdateData(FALSE);
}


void CDialog_SMFD_RC_FTR::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
   
    // -------- FUEL RH --------
   int val = atoi(m_edt_SmfdRc_FuelTankRH);
    if (val >= 156 && val <= 166)
    {
        m_strFuelRh = m_edt_SmfdRc_FuelTankRH;
        m_strStatusFuelRh = "OK";
    }
    else
    {
        g_strMsgStr.Format("RH Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strFuelRh = m_edt_SmfdRc_FuelTankRH;
        m_strStatusFuelRh = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
