// Dialog_SMFD_RC_BV.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_BV.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_BV dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_BV, CDialogEx)

CDialog_SMFD_RC_BV::CDialog_SMFD_RC_BV(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_BV::IDD, pParent)
	, m_edt_SmfdRc_Battvol(_T(""))
{

}

CDialog_SMFD_RC_BV::~CDialog_SMFD_RC_BV()
{
}

void CDialog_SMFD_RC_BV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCBATTERY_VOLT, m_edt_SmfdRc_Battvol);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_BV, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCBV, &CDialog_SMFD_RC_BV::OnBnClickedButtonSmfdAnalogRcbv)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_BV::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_BV message handlers


void CDialog_SMFD_RC_BV::OnBnClickedButtonSmfdAnalogRcbv()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
		m_edt_SmfdRc_Battvol = "28";
		UpdateData(FALSE);
}


void CDialog_SMFD_RC_BV::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- BATTERY VOLTAGE --------
    val = _tstof(m_edt_SmfdRc_Battvol);
    if (val >= 27 && val <= 29)
    {
        m_strbatvolt = m_edt_SmfdRc_Battvol;
        m_strStatusbatvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Battery voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strbatvolt = m_edt_SmfdRc_Battvol;
        m_strStatusbatvolt = "NOT OK";
    }
	UpdateData(FALSE);

	CDialogEx::OnOK();
}
