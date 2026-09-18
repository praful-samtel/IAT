#pragma once

#include "resource.h"
// CDialog_SMFD_RC_RTP dialog

class CDialog_SMFD_RC_RTP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_RTP)

public:
	CDialog_SMFD_RC_RTP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_RTP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_RTP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_RudTrimPos;
	afx_msg void OnBnClickedButtonSmfdAnalogRcrtp();
	afx_msg void OnBnClickedOk();
		CString m_strrudder;
	CString m_strStatusrudder;
};
