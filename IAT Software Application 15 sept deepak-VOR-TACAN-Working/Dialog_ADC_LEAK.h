#pragma once
#include "resource.h"
class CDialog_ADC_LEAK : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_LEAK)

public:
	CDialog_ADC_LEAK(CWnd* pParent = NULL);
	virtual ~CDialog_ADC_LEAK();

	enum { IDD = IDD_DIALOG_ADC_Leak };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	// Input fields
	CString m_edtADCPitotLeak;
	CString m_edtADCStaticLeak;

	// 🔥 ADD THESE (IMPORTANT)
	CString m_strPitot;
	CString m_strStatusPitot;

	CString m_strStatic;
	CString m_strStatusStatic;


	afx_msg void OnBnClickedOk();
};