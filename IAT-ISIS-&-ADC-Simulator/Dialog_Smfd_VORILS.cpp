// Dialog_Smfd_VORILS.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_VORILS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>
extern CSerialPort gCommPort1;


extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_VORILS dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_VORILS, CDialog)

CDialog_Smfd_VORILS::CDialog_Smfd_VORILS(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_VORILS::IDD, pParent)
	, m_edtvorfreq(_T(""))
	, m_edtilsfreq(_T(""))
	, m_edtvorbrg(0)
	, m_chklocalizer(FALSE)
	, m_chkglideslope(FALSE)
{

}

CDialog_Smfd_VORILS::~CDialog_Smfd_VORILS()
{
}

void CDialog_Smfd_VORILS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VORFREQ, m_edtvorfreq);
	DDX_Text(pDX, IDC_EDIT_ILSFREQ, m_edtilsfreq);
	DDX_Text(pDX, IDC_EDIT_VORBRG, m_edtvorbrg);
	DDX_Check(pDX, IDC_CHECK_LOCALIZER, m_chklocalizer);
	DDX_Check(pDX, IDC_CHECK_GLIDESLOPE, m_chkglideslope);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_VORILS, CDialog)
	
	ON_BN_CLICKED(IDC_CHECK_LOCALIZER, &CDialog_Smfd_VORILS::OnBnClickedCheckLocalizer)
	ON_BN_CLICKED(IDC_CHECK_GLIDESLOPE, &CDialog_Smfd_VORILS::OnBnClickedCheckGlideslope)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_VORILS::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_VORILS message handlers




void CDialog_Smfd_VORILS::OnBnClickedCheckGlideslope()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chkglideslope)
	{
		GetDlgItem(IDC_CHECK_GLIDESLOPE)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GLIDESLOPE)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedCheckLocalizer()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chklocalizer)
	{
		GetDlgItem(IDC_CHECK_LOCALIZER)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_LOCALIZER)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edtvorfreq = "108.00";
	m_edtilsfreq = "108.10";
	m_edtvorbrg  = 90;
	UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;
	double a1 = atof(m_edtvorfreq);
	double a2 = atof(m_edtilsfreq);
	
	m_strvorfreq = m_edtvorfreq;
	m_strilsfreq = m_edtilsfreq;
	m_strvorbrg = "90";

   if(a1==108.00)
	{
		m_strStatusvorfreq = "OK";
	}else
	{
		g_strMsgStr = "VOR frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusvorfreq = "NOT OK";
	}
	/////////////////////////
	if(a2==108.10)
	{
		m_strStatusilsfreq = "OK";
	}else
	{
		g_strMsgStr = "ILS frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusilsfreq = "NOT OK";
	}

	////////////////////
	if(m_strvorbrg=="90")
	{
		m_strStatusvorbrg = "OK";
	}else
	{
		g_strMsgStr = "VOR Bearing invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusvorfreq = "NOT OK";
	}

	//////////
	if(m_chklocalizer)
	{   
		m_strlocalizer = "OK";
		m_strStatuslocalizer = "OK";
	}else
	{
		g_strMsgStr = "Localizer deviation invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatuslocalizer = "NOT OK";
	}

	/////////////////
	if(m_chkglideslope)
	{   
		m_strglideslope = "OK";
		m_strStatusglideslope = "OK";
	}else
	{
		g_strMsgStr = "glideslope deviation invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatuslocalizer = "NOT OK";
	}
	UpdateData(FALSE);
	CDialog::OnOK();
}
