#include "stdafx.h"
#include "Dialog_ADC_LEAK.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_ADC_LEAK, CDialogEx)

CDialog_ADC_LEAK::CDialog_ADC_LEAK(CWnd* pParent)
	: CDialogEx(CDialog_ADC_LEAK::IDD, pParent)
	, m_edtADCPitotLeak(_T(""))
	, m_edtADCStaticLeak(_T(""))
{
}

CDialog_ADC_LEAK::~CDialog_ADC_LEAK()
{
}

void CDialog_ADC_LEAK::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_PITLEAK, m_edtADCPitotLeak);
	DDX_Text(pDX, IDC_EDIT_ADC_STLEAK, m_edtADCStaticLeak);
}

BEGIN_MESSAGE_MAP(CDialog_ADC_LEAK, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_LEAK::OnBnClickedOk)
END_MESSAGE_MAP()

// ---------------- OK BUTTON ----------------



void CDialog_ADC_LEAK::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// ---------------- PITOT ----------------
	if (m_edtADCPitotLeak.IsEmpty())
	{
		AfxMessageBox("Enter Pitot Leak value");
		return;
	}

	double pitot = atof(m_edtADCPitotLeak);
	m_strPitot = m_edtADCPitotLeak;

	// Example validation (adjust as per spec)
	if (pitot <= 0.1)
	{
		m_strStatusPitot = "OK";
	}
	else
	{
		g_strMsgStr = "Pitot Leak out of range. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusPitot = "NOT OK";
	}

	// ---------------- STATIC ----------------
	if (m_edtADCStaticLeak.IsEmpty())
	{
		AfxMessageBox("Enter Static Leak value");
		return;
	}

	double stat = atof(m_edtADCStaticLeak);
	m_strStatic = m_edtADCStaticLeak;

	if (stat <= 0.1)
	{
		m_strStatusStatic = "OK";
	}
	else
	{
		g_strMsgStr = "Static Leak out of range. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusStatic = "NOT OK";
	}
	UpdateData(false);
	CDialogEx::OnOK();
}
