#pragma once
#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 116)
// CDialog_ADC_AIR3 dialog

class CDialog_ADC_AIR3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_AIR3)

public:
	CDialog_ADC_AIR3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_AIR3();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_AIRSPEED3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	 virtual BOOL OnInitDialog();
	 afx_msg void OnTimer(UINT_PTR nIDEvent);

	 // Thread function
    static UINT RxThread(LPVOID pParam);
    // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strAirspeed3;
	CString m_strStatusAirspeed3;
	CString m_edtADCAirsp3;
	CString m_strAirSp3;
	afx_msg void OnBnClickedOk();
};
