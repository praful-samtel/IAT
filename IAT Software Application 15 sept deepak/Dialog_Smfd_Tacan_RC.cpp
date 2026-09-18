// Dialog_Smfd_Tacan_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Tacan_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Tacan_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Tacan_RC, CDialog)

CDialog_Smfd_Tacan_RC::CDialog_Smfd_Tacan_RC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Tacan_RC::IDD, pParent)

	, m_edt_SmfdRc_TacDis(_T(""))
	, m_edt_SmfdRc_TacBear(_T(""))
	, m_chk_TacanWordRC(FALSE)
{

}

CDialog_Smfd_Tacan_RC::~CDialog_Smfd_Tacan_RC()
{
}

void CDialog_Smfd_Tacan_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	;
	DDX_Text(pDX, IDC_EDIT_TAC201_RC, m_edt_SmfdRc_TacDis);
	DDX_Text(pDX, IDC_EDIT_TAC222_RC, m_edt_SmfdRc_TacBear);
	DDX_Check(pDX, IDC_CHECK_TACWORDRC, m_chk_TacanWordRC);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Tacan_RC, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Tacan_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL_RC, &CDialog_Smfd_Tacan_RC::OnBnClickedButtonSendarinclabelRc)
	ON_BN_CLICKED(IDC_CHECK_TACWORDRC, &CDialog_Smfd_Tacan_RC::OnBnClickedCheckTacwordrc)
END_MESSAGE_MAP()


// CDialog_Smfd_Tacan_RC message handlers


void CDialog_Smfd_Tacan_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);//  MUST
	CMessageBox_Dlg msgdlg;
//	m_strtac145 = m_edt_SmfdRc_TacConWord;
	m_strtac201 = m_edt_SmfdRc_TacDis;
	m_strtac222 = m_edt_SmfdRc_TacBear;

	if(m_chk_TacanWordRC)
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

	CDialog::OnOK();
}


void CDialog_Smfd_Tacan_RC::OnBnClickedButtonSendarinclabelRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_edt_SmfdRc_TacDis = "300";
	m_edt_SmfdRc_TacBear = "90";
	UpdateData(FALSE);
}


void CDialog_Smfd_Tacan_RC::OnBnClickedCheckTacwordrc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_TacanWordRC)
	{
		GetDlgItem(IDC_CHECK_TACWORDRC)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_TACWORDRC)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}
