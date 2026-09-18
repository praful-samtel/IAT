// Dialog_GPS_PWR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_GPS_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_GPS_PWR dialog

IMPLEMENT_DYNAMIC(CDialog_GPS_PWR, CDialogEx)

CDialog_GPS_PWR::CDialog_GPS_PWR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_GPS_PWR::IDD, pParent)
	, m_edtGPSVoltage(_T(""))
	, m_edtGPSCurrent(_T(""))
{

}

CDialog_GPS_PWR::~CDialog_GPS_PWR()
{
}

void CDialog_GPS_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPS_VOL, m_edtGPSVoltage);
	DDX_Text(pDX, IDC_EDIT_GPS_CUR, m_edtGPSCurrent);
}


BEGIN_MESSAGE_MAP(CDialog_GPS_PWR, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_GPS_PWR::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_GPS_PWR, &CDialog_GPS_PWR::OnBnClickedButtonGpsPwr)
END_MESSAGE_MAP()


void CDialog_GPS_PWR::OnBnClickedOk()
{
	UpdateData(TRUE);   // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// Save measured value
	m_strGPS28V = m_edtGPSVoltage;

	// BASIC VALIDATION (you can tune limits)
	if (m_edtGPSVoltage.IsEmpty())
	{
		AfxMessageBox("Please enter GPS Power value");
		return;
	}

	// Example: assume valid range (you adjust later)
	double val = atof(m_edtGPSVoltage);

	if (val >= 27  && val <= 29)   // <-- CHANGE RANGE AS PER SPEC
	{
		m_strStatusGPS28V = "OK";
	}
	else
	{
		g_strMsgStr = "GPS Power is out of range. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusGPS28V = "NOT OK";
	}

	m_strGPSCurrent = m_edtGPSCurrent;

	// BASIC VALIDATION (you can tune limits)
	if (m_edtGPSCurrent.IsEmpty())
	{
		AfxMessageBox("Please enter GPS Power value");
		return;
	}

	// Example: assume valid range (you adjust later)
	double val2 = atof(m_edtGPSCurrent);

	if (val2 >= 0.3  && val2 <= 1.7)   // <-- CHANGE RANGE AS PER SPEC
	{
		m_strStatusGPSCurrent = "OK";
	}
	else
	{
		g_strMsgStr = "GPS Power is out of range. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusGPSCurrent = "NOT OK";
	}
	UpdateData(FALSE);
	CDialogEx::OnOK();
}


void CDialog_GPS_PWR::OnBnClickedButtonGpsPwr()
{
	// TODO: Add your control notification handler code here
	SwitchDiscrete(ADC_ON,ON);
	Sleep(2000);
	double current = ReadPowerSupplyValue('V');
	m_edtGPSVoltage.Format("%.3f", current);

	 current = ReadPowerSupplyValue('C');
	 m_edtGPSVoltage.Format("%.3f", current);
}
