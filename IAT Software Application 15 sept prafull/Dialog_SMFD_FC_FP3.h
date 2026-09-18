#pragma once

#include "resource.h"
// CDialog_SMFD_FC_FP3 dialog

class CDialog_SMFD_FC_FP3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_FP3)

public:
	CDialog_SMFD_FC_FP3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_FP3();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFcfp3();
	afx_msg void OnBnClickedOk();
		CString m_strflap3v;
	CString m_strStatusflap3v;
	CString m_edt_SMFDFC_FP3;
};
