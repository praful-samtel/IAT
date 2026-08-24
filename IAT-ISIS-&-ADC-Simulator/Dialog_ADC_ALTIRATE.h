#pragma once

#include "resource.h"
// CDialog_ADC_ALTIRATE dialog
#define WM_UPDATE_ARINC (WM_USER + 119)
class CDialog_ADC_ALTIRATE : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_ADC_ALTIRATE)

public:
	CDialog_ADC_ALTIRATE(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_ALTIRATE();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_ALTIRATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	// Thread function
    static UINT RxThread(LPVOID pParam);

    // Thread object

    // Thread control flags
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	void StopRxThread();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strAltiRate;
	CString m_edt_AltiRate_ArincRx;
	BOOL m_chk_AltiRate1;
	BOOL m_chk_AltiRate2;
	CString m_strAltiRate1;
	CString m_strStatusAltiRate1;
	CString m_strAltiRate2;
	CString m_strStatusAltiRate2;
	afx_msg void OnBnClickedCheckAltirate1();
	afx_msg void OnBnClickedCheckAltirate2();
	afx_msg void OnBnClickedOk();
};
