#include "stdafx.h"
#include "Dlg_ADC_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDlg_ADC_PWR, CDialogEx)

CDlg_ADC_PWR::CDlg_ADC_PWR(CWnd* pParent)
	: CDialogEx(CDlg_ADC_PWR::IDD, pParent)
	, m_edtADCPWR(_T(""))
{
}

CDlg_ADC_PWR::~CDlg_ADC_PWR()
{
}

void CDlg_ADC_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_PWR, m_edtADCPWR);
}

BEGIN_MESSAGE_MAP(CDlg_ADC_PWR, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlg_ADC_PWR::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ADCPWR, &CDlg_ADC_PWR::OnBnClickedButtonAdcpwr)
END_MESSAGE_MAP()

// ---------------- OK BUTTON ----------------



void CDlg_ADC_PWR::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// Save measured value

	// BASIC VALIDATION (you can tune limits)

	// Example: assume valid range (you adjust later)
	double val = atof(m_edtADCPWR);
	m_strADCCurrent.Format("%s",m_edtADCPWR);
	if (val >= 100  && val <= 300)   // <-- CHANGE RANGE AS PER SPEC
	{
		m_strStatusADCCurrent = "OK";
	}
	else
	{
		g_strMsgStr = "ADC Power is out of range. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusADCCurrent = "NOT OK";
	}
	UpdateData(false);
	CDialogEx::OnOK();
}


void CDlg_ADC_PWR::OnBnClickedButtonAdcpwr()
{
	// TODO: Add your control notification handler code here
	SwitchDiscrete(ADC_ON,ON);
	Sleep(2000);
	double current = ReadPowerSupplyValue('C');
	m_edtADCPWR.Format("%.3f", current);

}
