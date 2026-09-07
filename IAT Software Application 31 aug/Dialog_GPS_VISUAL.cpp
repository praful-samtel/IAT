// Dialog_GPS_VISUAL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_GPS_VISUAL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_GPS_VISUAL dialog

IMPLEMENT_DYNAMIC(CDialog_GPS_VISUAL, CDialogEx)

CDialog_GPS_VISUAL::CDialog_GPS_VISUAL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_GPS_VISUAL::IDD, pParent)
	, m_edtGPSPtNo(_T(""))
	, m_ctlChkGPSDamage(FALSE)
	, m_chkGPSScratches(FALSE)
	, m_chkGPSScrews(FALSE)
	, m_chkGPSPins(FALSE)
{

}

CDialog_GPS_VISUAL::~CDialog_GPS_VISUAL()
{
}

void CDialog_GPS_VISUAL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPS_PtNo, m_edtGPSPtNo);
	DDX_Check(pDX, IDC_CHECK_GPS_DAMAGE, m_ctlChkGPSDamage);
	DDX_Check(pDX, IDC_CHECK_GPS_SCRATCHES, m_chkGPSScratches);
	DDX_Check(pDX, IDC_CHECK_GPS_SCREW, m_chkGPSScrews);
	DDX_Check(pDX, IDC_CHECK_GPS_PINS, m_chkGPSPins);
}


BEGIN_MESSAGE_MAP(CDialog_GPS_VISUAL, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_GPS_DAMAGE, &CDialog_GPS_VISUAL::OnBnClickedCheckGpsDamage)
	ON_BN_CLICKED(IDOK, &CDialog_GPS_VISUAL::OnBnClickedOk)	
	ON_BN_CLICKED(IDC_CHECK_GPS_SCRATCHES, &CDialog_GPS_VISUAL::OnBnClickedCheckGpsScratches)
	ON_BN_CLICKED(IDC_CHECK_GPS_SCREW, &CDialog_GPS_VISUAL::OnBnClickedCheckGpsScrew)
	ON_BN_CLICKED(IDC_CHECK_GPS_PINS, &CDialog_GPS_VISUAL::OnBnClickedCheckGpsPins)
END_MESSAGE_MAP()


// CDialog_GPS_VISUAL message handlers


void CDialog_GPS_VISUAL::OnBnClickedCheckGpsDamage()
{
	UpdateData(TRUE);

	if (!m_ctlChkGPSDamage)
	{
		GetDlgItem(IDC_CHECK_GPS_DAMAGE)->SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_DAMAGE)->SetWindowText("YES");
	}

	UpdateData(FALSE);
}


void CDialog_GPS_VISUAL::OnBnClickedOk()
{
	UpdateData(TRUE);

	CMessageBox_Dlg msgdlg;

	// -------- PART NUMBER CHECK --------
	if (m_edtGPSPtNo.IsEmpty())
	{
		AfxMessageBox("Enter GPS Part Number");
		return;
	}


	if(m_edtGPSPtNo == "011-04629-00")
	{   m_strGPSPtNo = m_edtGPSPtNo;
		m_strStatusGPSPtNo = "OK";

	}else
	{  g_strMsgStr = "GPS part number is wrong. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;
		m_strStatusGPSPtNo = " NOT OK";
	}
	// Simple validation (you can refine later)
	

	// -------- DAMAGE CHECK --------
	if (!m_ctlChkGPSDamage)
	{
		m_strGPSDamage = "NO";
		m_strStatusGPSDamage = "OK";
	}
	else
	{
		g_strMsgStr = "GPS unit has damage. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strGPSDamage = "YES";
		m_strStatusGPSDamage = "NOT OK";
	}
	//// -------- Scratches CHECK --------
	//if (m_chkGPSScratches)
	//{
	//	m_strGPSScratches = "OK";
	//	m_strStatusGPSScratches = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "GPS unit has Scratches. Continue?";
	//	msgdlg.DoModal();

	//	if (!g_bContinueFlag)
	//		return;

	//	m_strGPSScratches = "Not OK";
	//	m_strStatusGPSScratches = "NOT OK";
	//}
	//	// -------- Screws CHECK --------
	//if (m_chkGPSScrews)
	//{
	//	m_strGPSScrews = "OK";
	//	m_strStatusGPSScrews = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "GPS unit has loose screws. Continue?";
	//	msgdlg.DoModal();

	//	if (!g_bContinueFlag)
	//		return;

	//	m_strGPSScrews = "Not OK";
	//	m_strStatusGPSScrews = "NOT OK";
	//}
	//	// -------- ScrewPins CHECK --------
	//if (m_chkGPSPins)
	//{
	//	m_strGPSPins = "OK";
	//	m_strStatusGPSPins = "OK";
	//}
	//else
	//{
	//	g_strMsgStr = "GPS unit has Bend Pins. Continue?";
	//	msgdlg.DoModal();

	//	if (!g_bContinueFlag)
	//		return;

	//	m_strGPSPins = "Not OK";
	//	m_strStatusGPSPins = "NOT OK";
	//}
	UpdateData(FALSE);
	CDialogEx::OnOK();
}



void CDialog_GPS_VISUAL::OnBnClickedCheckGpsScratches()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkGPSScratches)
	{
		GetDlgItem(IDC_CHECK_GPS_SCRATCHES)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SCRATCHES)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}


void CDialog_GPS_VISUAL::OnBnClickedCheckGpsScrew()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkGPSScrews)
	{
		GetDlgItem(IDC_CHECK_GPS_SCREW)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SCREW)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}


void CDialog_GPS_VISUAL::OnBnClickedCheckGpsPins()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_chkGPSPins)
	{
		GetDlgItem(IDC_CHECK_GPS_PINS)->SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_PINS)->SetWindowText("Not OK");
	}

	UpdateData(FALSE);
}
