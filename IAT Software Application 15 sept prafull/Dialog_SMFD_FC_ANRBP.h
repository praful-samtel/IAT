#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ANRBP dialog

class CDialog_SMFD_FC_ANRBP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANRBP)

public:
	CDialog_SMFD_FC_ANRBP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANRBP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_RBP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_RBP;
	afx_msg void OnBnClickedButtonSmfdAnalogFcrbp();
	afx_msg void OnBnClickedOk();
	CString m_strRhBrake;
CString m_strStatusRhBrake;

};
