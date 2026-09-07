// DialogSmfd_Tacan.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfd_Tacan.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialogSmfd_Tacan dialog

IMPLEMENT_DYNAMIC(CDialogSmfd_Tacan, CDialog)

CDialogSmfd_Tacan::CDialogSmfd_Tacan(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfd_Tacan::IDD, pParent)
	, m_edtTac201(0)
	, m_edtTac222(0)
	, m_chk_TacanWord(FALSE)
{

}

CDialogSmfd_Tacan::~CDialogSmfd_Tacan()
{
}

void CDialogSmfd_Tacan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_TAC201, m_edtTac201);
	DDX_Text(pDX, IDC_EDIT_TAC222, m_edtTac222);
	DDX_Check(pDX, IDC_CHECK_TACWORD, m_chk_TacanWord);
}


BEGIN_MESSAGE_MAP(CDialogSmfd_Tacan, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfd_Tacan::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialogSmfd_Tacan::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDC_CHECK_TACWORD, &CDialogSmfd_Tacan::OnBnClickedCheckTacword)
END_MESSAGE_MAP()


// CDialogSmfd_Tacan message handlers


void CDialogSmfd_Tacan::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);//  MUST
	CMessageBox_Dlg msgdlg;

	m_strtac201 = "300";
	m_strtac222 = "90";

	if(m_chk_TacanWord)
	{  
		m_strtac145 = "Displayed";
		m_strStatustac145 = "OK";
	}else
	{
		g_strMsgStr = "TACAN control word invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strtac145 = "Not Displayed";
		m_strStatustac145 = "NOT OK";
	}

	if(m_strtac201=="300")
	{
		m_strStatustac201 = "OK";
	}else
	{
		g_strMsgStr = "TACAN Distance invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatustac201 = "NOT OK";
	}
	if(m_strtac222=="90")
	{
		m_strStatustac222 = "OK";
	}else
	{
		g_strMsgStr = "TACAN Distance invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatustac222 = "NOT OK";
	}

	UpdateData(FALSE);
	CDialog::OnOK();
}


void CDialogSmfd_Tacan::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//isme send label ka krdeo rx se read nhi krna sirf send krna h
	m_edtTac201 = 300;
	m_edtTac222 = 90;
	UpdateData(FALSE);
}


void CDialogSmfd_Tacan::OnBnClickedCheckTacword()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_TacanWord)
	{
		GetDlgItem(IDC_CHECK_TACWORD)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_TACWORD)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}
