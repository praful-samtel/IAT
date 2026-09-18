#pragma once

#include "resource.h"
// CDialog_ADC_MachCHK dialog
#define WM_UPDATE_ARINC (WM_USER + 117)
class CDialog_ADC_MachCHK : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_MachCHK)

public:
	CDialog_ADC_MachCHK(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_MachCHK();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_MACH };

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
	CString m_strADCMach1;
	CString m_edtADCMach1;
	CString m_strMach1;
	CString m_strStatusMach1;
	afx_msg void OnBnClickedOk();
};
