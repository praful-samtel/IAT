// Dialog_ISIS_BRTCHK.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ISIS_BRTCHK.h"
#include "afxdialogex.h"


#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_ISIS_BRTCHK dialog
#include "resource.h"
IMPLEMENT_DYNAMIC(CDialog_ISIS_BRTCHK, CDialog)

CDialog_ISIS_BRTCHK::CDialog_ISIS_BRTCHK(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_ISIS_BRTCHK::IDD, pParent)
	, m_chkISISFCBRT(FALSE)
	, m_chkISISRCBRT(FALSE)
{

}

CDialog_ISIS_BRTCHK::~CDialog_ISIS_BRTCHK()
{
}

void CDialog_ISIS_BRTCHK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ISISFC_BRT, m_chkISISFCBRT);
	DDX_Check(pDX, IDC_CHECK_ISISRC_BRT, m_chkISISRCBRT);
}


BEGIN_MESSAGE_MAP(CDialog_ISIS_BRTCHK, CDialog)
	ON_BN_CLICKED(IDC_CHECK_ISISFC_BRT, &CDialog_ISIS_BRTCHK::OnBnClickedCheckIsisfcBrt)
	ON_BN_CLICKED(IDC_CHECK_ISISRC_BRT, &CDialog_ISIS_BRTCHK::OnBnClickedCheckIsisrcBrt)
	ON_BN_CLICKED(IDOK, &CDialog_ISIS_BRTCHK::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_ISIS_BRTCHK message handlers


void CDialog_ISIS_BRTCHK::OnBnClickedCheckIsisfcBrt()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	if (m_chkISISFCBRT)
	{
		GetDlgItem(IDC_CHECK_ISISFC_BRT)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISFC_BRT)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_BRTCHK::OnBnClickedCheckIsisrcBrt()
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	
	if (m_chkISISRCBRT)
	{
		GetDlgItem(IDC_CHECK_ISISRC_BRT)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISRC_BRT)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_BRTCHK::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CMessageBox_Dlg msgdlg;
	UpdateData(true); 
			if (m_chkISISRCBRT)
	{
		m_strIsisFCBRT.Format("Operational");
		m_strStatusIsisFCBRT.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("5.01 ISIS DU FC Brightness and knob Check is Not Operational, Do you want to Continue");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisFCBRT.Format("Not Operational");
		m_strStatusIsisFCBRT.Format("NOT OK");
	}

				if (m_chkISISRCBRT)
	{
		m_strIsisRCBRT.Format("Operational");
		m_strStatusIsisRCBRT.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("5.02 ISIS DU RC Brightness and knob Check is Not Operational, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisRCBRT.Format("Not Operational");
		m_strStatusIsisRCBRT.Format("NOT OK");
	}
				UpdateData(false); 
	CDialog::OnOK();
}
