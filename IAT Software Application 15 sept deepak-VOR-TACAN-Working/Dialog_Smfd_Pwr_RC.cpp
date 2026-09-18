// Dialog_Smfd_Pwr_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Pwr_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Pwr_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Pwr_RC, CDialogEx)

CDialog_Smfd_Pwr_RC::CDialog_Smfd_Pwr_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Pwr_RC::IDD, pParent)
	, m_edt_SmfdRc_CurrCon(_T(""))
	, m_edt_MfdRc_CurrCon(_T(""))
{

}

CDialog_Smfd_Pwr_RC::~CDialog_Smfd_Pwr_RC()
{
}

void CDialog_Smfd_Pwr_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFD1_PWR_RC, m_edt_SmfdRc_CurrCon);
	DDX_Text(pDX, IDC_EDIT_SMFD2_PWR_RC, m_edt_MfdRc_CurrCon);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Pwr_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Pwr_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFDRC_PWR, &CDialog_Smfd_Pwr_RC::OnBnClickedButtonSmfdrcPwr)
END_MESSAGE_MAP()


// CDialog_Smfd_Pwr_RC message handlers


void CDialog_Smfd_Pwr_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    double val = 0.0;

    // -------- SMFD1 --------
    val = atof(m_edt_SmfdRc_CurrCon);

    if(val > 0 && val <= 3.0)
    {
        m_strSMFD1Current = m_edt_SmfdRc_CurrCon;
        m_strStatusSMFD1Current = "OK";
    }
    else
    {
        g_strMsgStr.Format("SMFD1 Current out of limit, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strSMFD1Current = m_edt_SmfdRc_CurrCon;
        m_strStatusSMFD1Current = "NOT OK";
    }

  

    // -------- MFD1 --------
    val = atof(m_edt_MfdRc_CurrCon);

    if(val > 0 && val <= 1.8)
    {
        m_strMFD1Current = m_edt_MfdRc_CurrCon;
        m_strStatusMFD1Current = "OK";
    }
    else
    {
        g_strMsgStr.Format("MFD1 Current out of limit, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strMFD1Current = m_edt_MfdRc_CurrCon;
        m_strStatusMFD1Current = "NOT OK";
    }

   

    UpdateData(FALSE);

	CDialogEx::OnOK();
}


void CDialog_Smfd_Pwr_RC::OnBnClickedButtonSmfdrcPwr()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SwitchDiscrete(SMFD_RC_ON,ON);
	Sleep(20000);
	double current = ReadPowerSupplyValue('C');
	m_edt_SmfdRc_CurrCon.Format("%.3f", current);

	SwitchDiscrete(SMFD_RC_ON,OFF);
	Sleep(250);
	SwitchDiscrete(MFD_RC_ON,ON);
	Sleep(5000);
	SwitchDiscrete(MFD_RC_ON,OFF);
	 current = ReadPowerSupplyValue('C');
	m_edt_MfdRc_CurrCon.Format("%.3f", current);
	UpdateData(FALSE);
}
