#pragma once

#include "resource.h"
// CDialog_SMFD_PWR dialog

class CDialog_SMFD_PWR : public CDialog
{
	DECLARE_DYNAMIC(CDialog_SMFD_PWR)

public:
	CDialog_SMFD_PWR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_PWR();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_smfd_pwr;

	
	CString m_edt_mfd1_pwr;
	CString m_strSMFD1Current;
	CString m_strStatusSMFD1Current;

	
	CString m_strMFD1Current;
	CString m_strStatusMFD1Current;

	
	afx_msg void OnBnClickedOk();
	CString m_edt_mfd_pwr;
};
