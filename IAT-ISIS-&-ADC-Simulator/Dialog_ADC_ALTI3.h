#pragma once
#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 113)

// CDialog_ADC_ALTI3 dialog

class CDialog_ADC_ALTI3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_ALTI3)

public:
	CDialog_ADC_ALTI3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_ALTI3();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_ALTITUDE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		 virtual BOOL OnInitDialog();
		 static UINT RxThread(LPVOID pParam);
	 afx_msg void OnTimer(UINT_PTR nIDEvent);
	 afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	 void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strADCALT1;
	CString m_edtADCALT3;
		CString m_strAltitude3;
	CString m_strStatusAltitude3;
	afx_msg void OnBnClickedOk();
};
