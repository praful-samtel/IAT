// Dialog_SMFD_RC_FTL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_FTL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_FTL dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_FTL, CDialogEx)

CDialog_SMFD_RC_FTL::CDialog_SMFD_RC_FTL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_FTL::IDD, pParent)
	, m_edt_SmfdRc_FuelTankLH(_T(""))
{

}

CDialog_SMFD_RC_FTL::~CDialog_SMFD_RC_FTL()
{
}

void CDialog_SMFD_RC_FTL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCLHFUEL, m_edt_SmfdRc_FuelTankLH);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_FTL, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_FTL::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCFTL, &CDialog_SMFD_RC_FTL::OnBnClickedButtonSmfdAnalogRcftl)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_FTL message handlers


void CDialog_SMFD_RC_FTL::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
    // -------- FUEL LH --------
   int val = atoi(m_edt_SmfdRc_FuelTankLH);
    if (val >= 163 && val <= 173)
    {
        m_strFuelLh = m_edt_SmfdRc_FuelTankLH;
        m_strStatusFuelLh = "OK";
    }
    else
    {
        g_strMsgStr.Format("LH Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strFuelLh = m_edt_SmfdRc_FuelTankLH;
        m_strStatusFuelLh = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}


void CDialog_SMFD_RC_FTL::OnBnClickedButtonSmfdAnalogRcftl()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		m_edt_SmfdRc_FuelTankLH = "170"; //168±5 lb
		UpdateData(FALSE);
}
