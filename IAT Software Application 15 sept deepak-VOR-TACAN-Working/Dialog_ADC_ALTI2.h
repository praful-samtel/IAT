#pragma once

#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 112)
// CDialog_ADC_ALTI2 dialog

class CDialog_ADC_ALTI2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_ALTI2)

public:
	CDialog_ADC_ALTI2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_ALTI2();
	CString m_strADCALT1;

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_ALTITUDE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	 virtual BOOL OnInitDialog();
	 afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	 afx_msg void OnTimer(UINT_PTR nIDEvent);
	 static UINT RxThread(LPVOID pParam);
	 void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edtADCALT2;
		CString m_strAltitude2;
	CString m_strStatusAltitude2;
};
