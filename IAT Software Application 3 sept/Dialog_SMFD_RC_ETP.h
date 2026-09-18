#pragma once
#include "resource.h"

// CDialog_SMFD_RC_ETP dialog

class CDialog_SMFD_RC_ETP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_ETP)

public:
	CDialog_SMFD_RC_ETP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_ETP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_ETP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_ElevTrimPos;
	afx_msg void OnBnClickedButtonSmfdAnalogRcetp();
	afx_msg void OnBnClickedOk();
	CString m_strelevator;
	CString m_strStatuselevator;
};
