// Dialog_ISIS_IBIT.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ISIS_IBIT.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ISIS_IBIT dialog

IMPLEMENT_DYNAMIC(CDialog_ISIS_IBIT, CDialog)

CDialog_ISIS_IBIT::CDialog_ISIS_IBIT(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_ISIS_IBIT::IDD, pParent)
	, m_chk_ISISFCIBIT(FALSE)
	, m_chk_ISISRCIBIT(FALSE)
{

}

CDialog_ISIS_IBIT::~CDialog_ISIS_IBIT()
{
}

void CDialog_ISIS_IBIT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ISISFC_IBIT, m_chk_ISISFCIBIT);
	DDX_Check(pDX, IDC_CHECK_ISISRC_IBIT, m_chk_ISISRCIBIT);
}


BEGIN_MESSAGE_MAP(CDialog_ISIS_IBIT, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_ISIS_IBIT::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_ISISFC_IBIT, &CDialog_ISIS_IBIT::OnBnClickedCheckIsisfcIbit)
	ON_BN_CLICKED(IDC_CHECK_ISISRC_IBIT, &CDialog_ISIS_IBIT::OnBnClickedCheckIsisrcIbit)
END_MESSAGE_MAP()


// CDialog_ISIS_IBIT message handlers


void CDialog_ISIS_IBIT::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
        UpdateData(true); 
			if (m_chk_ISISFCIBIT)
	{
		m_strIsisFCIBIT.Format("Operational");
		m_strStatusIsisFCIBIT.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("4.01 ISIS DU FC IBIT Check is Not Operational, Do you want to Continue");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisFCIBIT.Format("Not Operational");
		m_strStatusIsisFCIBIT.Format("NOT OK");
	}

				if (m_chk_ISISRCIBIT)
	{
		m_strIsisRCIBIT.Format("Operational");
		m_strStatusIsisRCIBIT.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("4.02 ISIS DU RC IBIT Check is Not Operational, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisRCIBIT.Format("Not Operational");
		m_strStatusIsisRCIBIT.Format("NOT OK");
	}
			UpdateData(false); 
	CDialog::OnOK();
}


void CDialog_ISIS_IBIT::OnBnClickedCheckIsisfcIbit()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	if (m_chk_ISISFCIBIT)
	{
		GetDlgItem(IDC_CHECK_ISISFC_IBIT)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISFC_IBIT)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_IBIT::OnBnClickedCheckIsisrcIbit()
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	UpdateData(true);
	
	if (m_chk_ISISRCIBIT)
	{
		GetDlgItem(IDC_CHECK_ISISRC_IBIT)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISRC_IBIT)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}
