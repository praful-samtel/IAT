#pragma once
#include "resource.h"
#define WM_UPDATE_ARINC (WM_USER + 118)
// CDialog_ADC_MACH2 dialog

class CDialog_ADC_MACH2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_MACH2)

public:
	CDialog_ADC_MACH2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_MACH2();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_MACH1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	 afx_msg void OnTimer(UINT_PTR nIDEvent);
	 protected:
    afx_msg void OnDestroy();
	// Thread function
    static UINT RxThread(LPVOID pParam);

    // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	CString m_edtADCMach2;
	CString m_strMach2;
	CString m_strStatusMach2;
	CString m_strADCMach2;
	afx_msg void OnBnClickedOk();
};
