#pragma once
#include "resource.h"
class CDlg_ADC_PWR : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ADC_PWR)

public:
	CDlg_ADC_PWR(CWnd* pParent = NULL);
	virtual ~CDlg_ADC_PWR();

	enum { IDD = IDD_DIALOG_ADC_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	CString m_edtADCPWR;

	// ADD THESE
	CString m_strADCCurrent;
	CString m_strStatusADCCurrent;


	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonAdcpwr();
};