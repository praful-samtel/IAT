#pragma once

#include "resource.h"
// CDialog_SMFD_RC_EOT dialog

class CDialog_SMFD_RC_EOT : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_EOT)

public:
	CDialog_SMFD_RC_EOT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_EOT();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_EOT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdRcAnalogeot();
	CString m_edt_SMFDRC_EOT;
	afx_msg void OnBnClickedOk();
		CString m_stroiltemp;
	CString m_strStatusoiltemp;
};
