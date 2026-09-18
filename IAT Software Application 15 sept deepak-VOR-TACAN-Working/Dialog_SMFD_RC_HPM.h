#pragma once

#include "resource.h"
// CDialog_SMFD_RC_HPM dialog

class CDialog_SMFD_RC_HPM : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_HPM)

public:
	CDialog_SMFD_RC_HPM(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_HPM();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_HPM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdRcAnhpm();
	afx_msg void OnBnClickedOk();
	CString m_strHydPresMain;
CString m_strStatusHydPresMain;
CString m_edt_SmfdRc_HyPrMain;
};
