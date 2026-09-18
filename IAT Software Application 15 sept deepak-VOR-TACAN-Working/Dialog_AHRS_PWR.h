#pragma once
#include "resource.h"

// CDialog_AHRS_PWR dialog

class CDialog_AHRS_PWR : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_AHRS_PWR)

public:
	CDialog_AHRS_PWR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_AHRS_PWR();

// Dialog Data
	enum { IDD = IDD_DIALOG_AHRS_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtAHRSPWR;
	afx_msg void OnBnClickedOk();
	//virtual void OnOK();
	CString m_strAHRSCurrent;
	CString m_strStatusAHRSCurrent;
	afx_msg void OnBnClickedButtonAhrsPwr();
};
