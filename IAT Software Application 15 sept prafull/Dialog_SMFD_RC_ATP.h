#pragma once
#include "resource.h"

// CDialog_SMFD_RC_ATP dialog

class CDialog_SMFD_RC_ATP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_ATP)

public:
	CDialog_SMFD_RC_ATP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_ATP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_ATP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_AilTrimPos;
	afx_msg void OnBnClickedButtonSmfdAnalogRcatp();
	afx_msg void OnBnClickedOk();
	CString m_straileron;
	CString m_strStatusaileron;
};
