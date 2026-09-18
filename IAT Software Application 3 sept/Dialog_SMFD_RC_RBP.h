#pragma once
#include "resource.h"

// CDialog_SMFD_RC_RBP dialog

class CDialog_SMFD_RC_RBP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_RBP)

public:
	CDialog_SMFD_RC_RBP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_RBP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_RBP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRcrbp();
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_RhBr;
	CString m_strRhBrake;
CString m_strStatusRhBrake;
};
