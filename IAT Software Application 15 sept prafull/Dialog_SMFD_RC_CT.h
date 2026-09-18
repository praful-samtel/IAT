#pragma once
#include "resource.h"

// CDialog_SMFD_RC_CT dialog

class CDialog_SMFD_RC_CT : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_CT)

public:
	CDialog_SMFD_RC_CT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_CT();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_CT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRcct();
	afx_msg void OnBnClickedOk();
	CString m_strCollectorTank;
CString m_strStatusCollectorTank;
CString m_edt_SmfdRc_CoTank;
};
