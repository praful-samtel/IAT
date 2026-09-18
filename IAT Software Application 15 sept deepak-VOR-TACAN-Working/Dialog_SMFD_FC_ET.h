#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ET dialog

class CDialog_SMFD_FC_ET : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ET)

public:
	CDialog_SMFD_FC_ET(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ET();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_ET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_ET;
	afx_msg void OnBnClickedButtonSmfdAnalogFcet();
	afx_msg void OnBnClickedOk();
		CString m_strtorque;
	CString m_strStatustorque;
};
