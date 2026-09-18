#pragma once
#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 114)
// CDialog_ADC_AIR1 dialog

class CDialog_ADC_AIR1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_AIR1)

public:
	CDialog_ADC_AIR1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_AIR1();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_AIRSPEED1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		 virtual BOOL OnInitDialog();

		 static UINT RxThread(LPVOID pParam);
		 // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	 afx_msg void OnTimer(UINT_PTR nIDEvent);
	 void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strAirSp1;
	CString m_strAirspeed1;
	CString m_strStatusAirspeed1;
	afx_msg void OnBnClickedOk();
	CString m_edtADCAirsp1;
};
