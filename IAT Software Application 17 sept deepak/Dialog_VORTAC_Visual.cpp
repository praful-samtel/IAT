// Dialog_VORTAC_Visual.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_VORTAC_Visual.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_VORTAC_Visual dialog

IMPLEMENT_DYNAMIC(CDialog_VORTAC_Visual, CDialog)

CDialog_VORTAC_Visual::CDialog_VORTAC_Visual(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_VORTAC_Visual::IDD, pParent)
	, m_edtVOR_Reciever(_T(""))
	, m_edtTACAN_Reciever(_T(""))
	, m_edtCDU(_T(""))
	, m_ctlChkVorTacDamage(FALSE)
	, m_chkVORTACScratches(FALSE)
	, m_chkVORTACScrews(FALSE)
	, m_chkVORTACPins(FALSE)
{

}

CDialog_VORTAC_Visual::~CDialog_VORTAC_Visual()
{
}

void CDialog_VORTAC_Visual::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VOR_RECIEVER, m_edtVOR_Reciever);
	DDX_Text(pDX, IDC_EDIT_TACAN, m_edtTACAN_Reciever);
	DDX_Text(pDX, IDC_EDIT_CDU, m_edtCDU);
	DDX_Check(pDX, IDC_CHECK_VORTAC_DAMAGE, m_ctlChkVorTacDamage);
	DDX_Check(pDX, IDC_CHECK_VORTAC_SCRATCHES, m_chkVORTACScratches);
	DDX_Check(pDX, IDC_CHECK_VORTAC_SCREW, m_chkVORTACScrews);
	DDX_Check(pDX, IDC_CHECK_VORTAC_PINS, m_chkVORTACPins);
}


BEGIN_MESSAGE_MAP(CDialog_VORTAC_Visual, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_VORTAC_Visual::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_VORTAC_DAMAGE, &CDialog_VORTAC_Visual::OnBnClickedCheckVortacDamage)
	ON_BN_CLICKED(IDC_CHECK_VORTAC_SCRATCHES, &CDialog_VORTAC_Visual::OnBnClickedCheckVortacScratches)
	ON_BN_CLICKED(IDC_CHECK_VORTAC_SCREW, &CDialog_VORTAC_Visual::OnBnClickedCheckVortacScrew)
	ON_BN_CLICKED(IDC_CHECK_VORTAC_PINS, &CDialog_VORTAC_Visual::OnBnClickedCheckVortacPins)
END_MESSAGE_MAP()


// CDialog_VORTAC_Visual message handlers


void CDialog_VORTAC_Visual::OnBnClickedOk()
{
	UpdateData(TRUE);

	CMessageBox_Dlg msgdlg;

	// -------- VOR RECEIVER --------
	if (!m_edtVOR_Reciever.IsEmpty() && m_edtVOR_Reciever.Compare("ANS2810A HTT1")  == 0)
	{
		m_strVOR = m_edtVOR_Reciever;
		m_strStatusVOR = "OK";
	}
	else
	{
		g_strMsgStr = "VOR Part Number is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strVOR = m_edtVOR_Reciever;
		m_strStatusVOR = "NOT OK";
	}

	// -------- TACAN RECEIVER --------
	if (!m_edtTACAN_Reciever.IsEmpty() && m_edtTACAN_Reciever.Compare("2920A HTT1") == 0)
	{
		m_strTACAN = m_edtTACAN_Reciever;
		m_strStatusTACAN = "OK";
	}
	else
	{
		g_strMsgStr = "TACAN Part Number is notCorrect. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strTACAN = m_edtTACAN_Reciever;
		m_strStatusTACAN = "NOT OK";
	}

	// -------- CDU --------
	if (!m_edtCDU.IsEmpty() && m_edtCDU.Compare("CDU-2810A HTT1") == 0 )
	{
		m_strCDU = m_edtCDU;
		m_strStatusCDU = "OK";
	}
	else
	{
		g_strMsgStr = "CDU Part Number is not Correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strCDU = "Not Entered";
		m_strStatusCDU = "NOT OK";
	}

	// -------- DAMAGE CHECK --------
	if (!m_ctlChkVorTacDamage)
	{
		m_strDamage = "NO";
		m_strStatusDamage = "OK";
	}
	else
	{
		g_strMsgStr = "Damage found in VOR/TACAN. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strDamage = "YES";
		m_strStatusDamage = "NOT OK";
	}
	//// -------- Scratches CHECK --------
	//if (m_chkVORTACScratches)
	//{
	//	m_strScratches = "Satisfactory";
	//	m_strStatusScratches = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "Scratches found in VOR/TACAN. Continue?";
	//	msgdlg.DoModal();
	//	if (!g_bContinueFlag) return;

	//	m_strScratches = "Not Satisfactory";
	//	m_strStatusScratches = "NOT OK";
	//}
	//	// -------- Screw CHECK --------
	//if (m_chkVORTACScrews)
	//{
	//	m_strScrews = "Satisfactory";
	//	m_strStatusScrews = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "Loose Screws found in VOR/TACAN. Continue?";
	//	msgdlg.DoModal();
	//	if (!g_bContinueFlag) return;

	//	m_strScrews = "Not Satisfactory";
	//	m_strStatusScrews = "NOT OK";
	//}
	//		// -------- Pins CHECK --------
	//if (m_chkVORTACPins)
	//{
	//	m_strPins = "Satisfactory";
	//	m_strStatusPins = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "Bend Pins found in VOR/TACAN. Continue?";
	//	msgdlg.DoModal();
	//	if (!g_bContinueFlag) return;

	//	m_strPins = "Not Satisfactory";
	//	m_strStatusPins = "NOT OK";
	//}

	CDialog::OnOK();
}


void CDialog_VORTAC_Visual::OnBnClickedCheckVortacDamage()
{
	UpdateData(TRUE);

	if (!m_ctlChkVorTacDamage)
	{
		GetDlgItem(IDC_CHECK_VORTAC_DAMAGE)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORTAC_DAMAGE)->SetWindowText("YES");
	}

	UpdateData(FALSE);
}


void CDialog_VORTAC_Visual::OnBnClickedCheckVortacScratches()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);

	if (m_chkVORTACScratches)
	{
		GetDlgItem(IDC_CHECK_VORTAC_SCRATCHES)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORTAC_SCRATCHES)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}


void CDialog_VORTAC_Visual::OnBnClickedCheckVortacScrew()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkVORTACScrews)
	{
		GetDlgItem(IDC_CHECK_VORTAC_SCREW)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORTAC_SCREW)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}


void CDialog_VORTAC_Visual::OnBnClickedCheckVortacPins()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkVORTACPins)
	{
		GetDlgItem(IDC_CHECK_VORTAC_PINS)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORTAC_PINS)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}
