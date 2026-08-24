// Dialog_SMFD_PWR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_PWR dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_PWR, CDialog)

CDialog_SMFD_PWR::CDialog_SMFD_PWR(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_SMFD_PWR::IDD, pParent)
	, m_edt_smfd_pwr(_T(""))
	, m_edt_mfd_pwr(_T(""))
{

}

CDialog_SMFD_PWR::~CDialog_SMFD_PWR()
{
}

void CDialog_SMFD_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFD1_PWR, m_edt_smfd_pwr);
	//DDX_Text(pDX, IDC_EDIT_MFD1_PWR, m_edt_mfd_pwr);
	DDX_Text(pDX, IDC_EDIT_MFD1_PWR, m_edt_mfd_pwr);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_PWR, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_PWR::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_PWR message handlers


void CDialog_SMFD_PWR::OnBnClickedOk()
{
    CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    double val = 0.0;

    // -------- SMFD1 --------
    val = atof(m_edt_smfd_pwr);

    if(val > 0 && val <= 3.0)
    {
        m_strSMFD1Current = m_edt_smfd_pwr;
        m_strStatusSMFD1Current = "OK";
    }
    else
    {
        g_strMsgStr.Format("SMFD1 Current out of limit, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strSMFD1Current = m_edt_smfd_pwr;
        m_strStatusSMFD1Current = "NOT OK";
    }

  

    // -------- MFD1 --------
    val = atof(m_edt_mfd_pwr);

    if(val > 0 && val <= 1.8)
    {
        m_strMFD1Current = m_edt_mfd_pwr;
        m_strStatusMFD1Current = "OK";
    }
    else
    {
        g_strMsgStr.Format("MFD1 Current out of limit, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strMFD1Current = m_edt_mfd_pwr;
        m_strStatusMFD1Current = "NOT OK";
    }

   

    UpdateData(FALSE);

    CDialog::OnOK();
}