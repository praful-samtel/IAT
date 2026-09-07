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

	, m_edtvorbrg(0)
	, m_chk_SMFD_VorFreq(FALSE)
	, m_chk_SMFD_IlsFreq(FALSE)
	, m_edt_LocDev173(_T(""))
	, m_edt_GlsDev174(_T(""))
{

}

CDialog_Smfd_VORILS::~CDialog_Smfd_VORILS()
{
}

void CDialog_Smfd_VORILS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_VORBRG, m_edtvorbrg);

	DDX_Check(pDX, IDC_CHECK_VORFREQ, m_chk_SMFD_VorFreq);
	DDX_Check(pDX, IDC_CHECK_ILS_FREQ, m_chk_SMFD_IlsFreq);
	DDX_Text(pDX, IDC_EDIT_LOCDEV173, m_edt_LocDev173);
	DDX_Text(pDX, IDC_EDIT_GLSDEV174, m_edt_GlsDev174);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_VORILS, CDialog)

	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_VORILS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_VORFREQ, &CDialog_Smfd_VORILS::OnBnClickedCheckVorfreq)
	ON_BN_CLICKED(IDC_CHECK_ILS_FREQ, &CDialog_Smfd_VORILS::OnBnClickedCheckIlsFreq)
END_MESSAGE_MAP()



void CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_edtvorbrg  = 90;
	UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;

	m_strlocalizer = m_edt_LocDev173;
	m_strglideslope = m_edt_GlsDev174;
	
	m_strvorbrg = "90";

   if(m_chk_SMFD_VorFreq)
	{
		m_strvorfreq = "Displayed";
		m_strStatusvorfreq = "OK";
	}else
	{
		g_strMsgStr = "VOR frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strvorfreq = "Not Displayed";
		m_strStatusvorfreq = "NOT OK";
	}
	/////////////////////////
	if(m_chk_SMFD_IlsFreq)
	{
		m_strilsfreq = "Displayed";
		m_strStatusilsfreq = "OK";
	}else
	{
		g_strMsgStr = "ILS frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strilsfreq = "Not Displayed";
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
	if(m_edt_LocDev173 == "0.077")
	{   
		
		m_strStatuslocalizer = "OK";
	}else
	{
		g_strMsgStr = "Localizer deviation invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatuslocalizer = "NOT OK";
	}

	/////////////////
	if(m_edt_GlsDev174 == "0.087")
	{   
		
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


void CDialog_Smfd_VORILS::OnBnClickedCheckVorfreq()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_SMFD_VorFreq)
	{
		GetDlgItem(IDC_CHECK_VORFREQ)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORFREQ)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedCheckIlsFreq()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);

   if (m_chk_SMFD_IlsFreq)
	{
		GetDlgItem(IDC_CHECK_ILS_FREQ)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ILS_FREQ)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}
