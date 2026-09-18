// Dialog_ISIS_ALN.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ISIS_ALN.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ISIS_ALN dialog

IMPLEMENT_DYNAMIC(CDialog_ISIS_ALN, CDialog)

CDialog_ISIS_ALN::CDialog_ISIS_ALN(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_ISIS_ALN::IDD, pParent)
	, m_chk_ISISFC_ALN(FALSE)
	, m_chk_ISISRC_ALN(FALSE)
{

}

CDialog_ISIS_ALN::~CDialog_ISIS_ALN()
{
}

void CDialog_ISIS_ALN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ISISFC_ALN, m_chk_ISISFC_ALN);
	DDX_Check(pDX, IDC_CHECK_ISISRC_ALN, m_chk_ISISRC_ALN);
}


BEGIN_MESSAGE_MAP(CDialog_ISIS_ALN, CDialog)
	ON_BN_CLICKED(IDC_CHECK_ISISFC_ALN, &CDialog_ISIS_ALN::OnBnClickedCheckIsisfcAln)
	ON_BN_CLICKED(IDC_CHECK_ISISRC_ALN, &CDialog_ISIS_ALN::OnBnClickedCheckIsisrcAln)
	ON_BN_CLICKED(IDOK, &CDialog_ISIS_ALN::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_ISIS_ALN message handlers


void CDialog_ISIS_ALN::OnBnClickedCheckIsisfcAln()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	if (m_chk_ISISFC_ALN)
	{
		GetDlgItem(IDC_CHECK_ISISFC_ALN)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISFC_ALN)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_ALN::OnBnClickedCheckIsisrcAln()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	if (m_chk_ISISRC_ALN)
	{
		GetDlgItem(IDC_CHECK_ISISRC_ALN)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISRC_ALN)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_ALN::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
	UpdateData(true); 
			if (m_chk_ISISRC_ALN)
	{
		m_strIsisFCALN.Format("Operational");
		m_strStatusIsisFCALN.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("6.01 ISIS DU FC Alignment mode Check is Not Operational, Do you want to Continue");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisFCALN.Format("Not Operational");
		m_strStatusIsisFCALN.Format("NOT OK");
	}

				if (m_chk_ISISRC_ALN)
	{
		m_strIsisRCALN.Format("Operational");
		m_strStatusIsisRCALN.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("6.02 ISIS DU RC Alignment mode Check is Not Operational, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisRCALN.Format("Not Operational");
		m_strStatusIsisRCALN.Format("NOT OK");
	}
			UpdateData(false);

	CDialog::OnOK();
}
