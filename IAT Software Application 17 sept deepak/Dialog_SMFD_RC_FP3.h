#pragma once
#include "resource.h"

// CDialog_SMFD_RC_FP3 dialog

class CDialog_SMFD_RC_FP3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_FP3)

public:
	CDialog_SMFD_RC_FP3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_FP3();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_FP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_FlPos3V;
	afx_msg void OnBnClickedButtonSmfdAnalogRcfp3();
	afx_msg void OnBnClickedOk();
	CString m_strflap3v;
	CString m_strStatusflap3v;
};
