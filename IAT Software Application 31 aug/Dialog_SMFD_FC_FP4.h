#pragma once
#include "resource.h"

// CDialog_SMFD_FC_FP4 dialog

class CDialog_SMFD_FC_FP4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_FP4)

public:
	CDialog_SMFD_FC_FP4(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_FP4();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FP4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFcfp4();
	afx_msg void OnBnClickedOk();
	CString m_edt_SMFDFC_FP4;
	CString m_strflap4v;
	CString m_strStatusflap4v;
};
