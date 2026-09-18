#pragma once
#include "resource.h"

#define WM_UPDATE_ARINC (WM_USER + 111)
class CDialog_ADC_FUNCHK : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_FUNCHK)

public:
	CDialog_ADC_FUNCHK(CWnd* pParent = NULL);
	virtual ~CDialog_ADC_FUNCHK();
	virtual BOOL OnInitDialog();
	enum { IDD = IDD_DIALOG_ADC_FUNCHK };
	CString m_strADCALT1;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	protected:

    // Thread function
    static UINT RxThread(LPVOID pParam);

    // Thread object

    // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	void StopRxThread();
    BOOL m_bThreadRunning;
	DECLARE_MESSAGE_MAP()

public:
	// Inputs
	CString m_edtADCALT1;



	/*

	CString m_edtADCMach1;
	CString m_edtADCMach2;*/

	// 🔥 OUTPUT (IMPORTANT)
	CString m_strAltitude1;
	CString m_strStatusAltitude1;


	/*

	CString m_strMach;
	CString m_strStatusMach;*/


	afx_msg void OnBnClickedOk();
};