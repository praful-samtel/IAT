#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANBV dialog

class CDialog_SMFD_FC_ANBV : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANBV)

public:
	CDialog_SMFD_FC_ANBV(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANBV();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_BV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_BV;
	afx_msg void OnBnClickedButtonSmfdAnalogFcbv();
	afx_msg void OnBnClickedOk();
	
	CString m_strbatvolt;
	CString m_strStatusbatvolt;
};
