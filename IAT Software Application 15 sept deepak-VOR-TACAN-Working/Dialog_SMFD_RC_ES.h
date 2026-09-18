#pragma once
#include "resource.h"

// CDialog_SMFD_RC_ES dialog

class CDialog_SMFD_RC_ES : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_ES)

public:
	CDialog_SMFD_RC_ES(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_ES();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_ES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_EnSpeed;
	afx_msg void OnBnClickedButtonSmfdAnalogRces();
	afx_msg void OnBnClickedOk();
	// -------- ENGINE --------
CString m_strEngineSpd;
CString m_strStatusEngineSpd;
};
