// DialogSIGNAL.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSIGNAL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialogSIGNAL dialog

IMPLEMENT_DYNAMIC(CDialogSIGNAL, CDialogEx)

CDialogSIGNAL::CDialogSIGNAL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogSIGNAL::IDD, pParent)
	, m_ctlChkGPSSignal(FALSE)
{

}

CDialogSIGNAL::~CDialogSIGNAL()
{
}

void CDialogSIGNAL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_GPS_SIGNAL, m_ctlChkGPSSignal);
}


BEGIN_MESSAGE_MAP(CDialogSIGNAL, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_GPS_SIGNAL, &CDialogSIGNAL::OnBnClickedCheckGpsSignal)
	ON_BN_CLICKED(IDOK, &CDialogSIGNAL::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogSIGNAL message handlers


void CDialogSIGNAL::OnBnClickedCheckGpsSignal()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_ctlChkGPSSignal)
	{
		GetDlgItem(IDC_CHECK_GPS_SIGNAL)->SetWindowText("Correct");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SIGNAL)->SetWindowText("Not Correct");
	}

	UpdateData(FALSE);
}


void CDialogSIGNAL::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
	if (m_ctlChkGPSSignal)
	{
		m_strGPSSignal = "Correct";
		m_strStatusGPSSignal = "OK";
	}
	else
	{
		g_strMsgStr = "GPS Signal Acquisition Power is not correct. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strGPSSignal = "Not Correct";
		m_strStatusGPSSignal = "NOT OK";
	}

	CDialogEx::OnOK();
}
