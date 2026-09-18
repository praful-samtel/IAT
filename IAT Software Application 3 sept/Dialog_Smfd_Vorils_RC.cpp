// Dialog_Smfd_Vorils_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Vorils_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>

extern CSerialPort gCommPort1;


extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Vorils_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Vorils_RC, CDialogEx)

CDialog_Smfd_Vorils_RC::CDialog_Smfd_Vorils_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Vorils_RC::IDD, pParent)

	, m_edt_SmfdRc_VorBear(_T(""))

	, m_chk_SMFD_VorFreqRC(FALSE)
	, m_chk_SMFD_IlsFreqRC(FALSE)

	, m_edt_LocDev173RC(_T(""))
	, m_edt_GlsDev174RC(_T(""))
{

}

CDialog_Smfd_Vorils_RC::~CDialog_Smfd_Vorils_RC()
{
}

void CDialog_Smfd_Vorils_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_VORBRG_RC, m_edt_SmfdRc_VorBear);
	DDX_Check(pDX, IDC_CHECK_VORFREQRC, m_chk_SMFD_VorFreqRC);
	DDX_Check(pDX, IDC_CHECK_ILS_FREQRC, m_chk_SMFD_IlsFreqRC);
	DDX_Text(pDX, IDC_EDIT_LOCDEV173RC, m_edt_LocDev173RC);
	DDX_Text(pDX, IDC_EDIT_GLSDEV174RC, m_edt_GlsDev174RC);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Vorils_RC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL_RC, &CDialog_Smfd_Vorils_RC::OnBnClickedButtonSendarinclabelRc)

	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Vorils_RC::OnBnClickedOk)

	ON_BN_CLICKED(IDC_CHECK_ILS_FREQRC, &CDialog_Smfd_Vorils_RC::OnBnClickedCheckIlsFreqrc)
	ON_BN_CLICKED(IDC_CHECK_VORFREQRC, &CDialog_Smfd_Vorils_RC::OnBnClickedCheckVorfreqrc)
END_MESSAGE_MAP()


// CDialog_Smfd_Vorils_RC message handlers


void CDialog_Smfd_Vorils_RC::OnBnClickedButtonSendarinclabelRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_edt_SmfdRc_VorBear  = "90";
	UpdateData(FALSE);
}


void CDialog_Smfd_Vorils_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;
		m_strlocalizer = m_edt_LocDev173RC;
	m_strglideslope = m_edt_GlsDev174RC;
	double a3 = atof(m_edt_SmfdRc_VorBear);
	

	m_strvorbrg = "90";

   if(m_chk_SMFD_VorFreqRC)
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
	if(m_chk_SMFD_IlsFreqRC)
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
	if(m_edt_LocDev173RC == "0.077")
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
	if(m_edt_GlsDev174RC == "0.087")
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
	CDialogEx::OnOK();
}





void CDialog_Smfd_Vorils_RC::OnBnClickedCheckIlsFreqrc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_SMFD_IlsFreqRC)
	{
		GetDlgItem(IDC_CHECK_ILS_FREQRC)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ILS_FREQRC)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Vorils_RC::OnBnClickedCheckVorfreqrc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_SMFD_VorFreqRC)
	{
		GetDlgItem(IDC_CHECK_VORFREQRC)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORFREQRC)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}
