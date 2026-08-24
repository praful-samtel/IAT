#pragma once
#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 115)
// CDialog_ADC_AIR2 dialog

class CDialog_ADC_AIR2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_AIR2)

public:
	CDialog_ADC_AIR2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_AIR2();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_AIRSPEED2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	 virtual BOOL OnInitDialog();
	  // Thread function
    static UINT RxThread(LPVOID pParam);
    // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	 afx_msg void OnTimer(UINT_PTR nIDEvent);
	 void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strAirSp2;
	CString m_edtADCAirsp2;
	CString m_strAirspeed2;
	CString m_strStatusAirspeed2;
	afx_msg void OnBnClickedOk();
};
