// MessageBox_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "MessageBox_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString g_strMsgStr;
CString g_strMsgStrScreenTitle;
CString g_strFaultyModule;

BOOL g_bContinueFlag = false;

/////////////////////////////////////////////////////////////////////////////
// CMessageBox_Dlg dialog


CMessageBox_Dlg::CMessageBox_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageBox_Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessageBox_Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	//brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa)); 
	//brushNew.CreateSolidBrush(RGB(0xff,0x00,0x00));
//	brushNew.CreateSolidBrush(RGB(0xff,0xff,0xff));
}


void CMessageBox_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessageBox_Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMessageBox_Dlg, CDialog)
	//{{AFX_MSG_MAP(CMessageBox_Dlg)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMessageBox_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessageBox_Dlg message handlers

BOOL CMessageBox_Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//CMessageBox_Dlg msgBox_Dlg;
	
	m_ulTimercount = 0;
	GetDlgItem(IDC_STATIC_MSG_STR)->SetWindowText(g_strMsgStr);
	
	GetDlgItem(IDC_STATIC_FAULTY_MOD)->SetWindowText(g_strFaultyModule);
	
	CDialog::SetWindowTextA(g_strMsgStrScreenTitle);
	
	//SetTimer(1, 500, NULL);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CMessageBox_Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( (nCtlColor == CTLCOLOR_DLG) || (nCtlColor == CTLCOLOR_STATIC) )   
	{
		pDC->SetBkMode(BACKGROUND_WARN);
		return brushNew;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMessageBox_Dlg::OnOK() 
{
	g_bContinueFlag = true;
	
	KillTimer(1);

	CDialog::OnOK();
}

void CMessageBox_Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	g_bContinueFlag = false;
	KillTimer(1);

	CDialog::OnCancel();
}

void CMessageBox_Dlg::OnTimer(UINT_PTR nIDEvent) 
{
	
	UpdateData(true);

	if (m_ulTimercount%2 == 0)
	{
		GetDlgItem(IDC_STATIC_LED) -> ShowWindow(false);
	}
	else
	{
		GetDlgItem(IDC_STATIC_LED) -> ShowWindow(true);
	}

	if (m_ulTimercount == 1000)
	{
		m_ulTimercount = 0;
	}

	m_ulTimercount++;
	
	CDialog::OnTimer(nIDEvent);

	UpdateData(false);
}

void CMessageBox_Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
