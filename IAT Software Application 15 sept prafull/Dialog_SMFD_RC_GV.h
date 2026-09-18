#pragma once
#include "resource.h"

// CDialog_SMFD_RC_GV dialog

class CDialog_SMFD_RC_GV : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_GV)

public:
	CDialog_SMFD_RC_GV(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_GV();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_GV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_GenVol;
	afx_msg void OnBnClickedButtonSmfdAnalogRcgv();
	afx_msg void OnBnClickedOk();
	CString m_strgenvolt;
	CString m_strStatusgenvolt;
};
