#pragma once

#include "resource.h"
// CDialog_SMFD_RC_ET dialog

class CDialog_SMFD_RC_ET : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_ET)

public:
	CDialog_SMFD_RC_ET(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_ET();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_ET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_EnTor;
	afx_msg void OnBnClickedButtonSmfdAnalogRcet();
	afx_msg void OnBnClickedOk();
		CString m_strtorque;
	CString m_strStatustorque;
};
