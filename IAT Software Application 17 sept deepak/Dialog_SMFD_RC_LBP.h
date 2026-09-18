#pragma once

#include "resource.h"
// CDialog_SMFD_RC_LBP dialog

class CDialog_SMFD_RC_LBP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_LBP)

public:
	CDialog_SMFD_RC_LBP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_LBP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_LBP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_LHBr;
	afx_msg void OnBnClickedButtonSmfdAnalogRclbp();
	afx_msg void OnBnClickedOk();
	CString m_strLhBrake;
CString m_strStatusLhBrake;
};
