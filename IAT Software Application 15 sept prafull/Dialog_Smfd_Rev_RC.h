#pragma once
#include "resource.h"

// CDialog_Smfd_Rev_RC dialog

class CDialog_Smfd_Rev_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Rev_RC)

public:
	CDialog_Smfd_Rev_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Rev_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_REVI_PAGE_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL m_chk_SmfdRc_Rev;
		CString m_strSMFDRevPage;
	CString m_strStatusSMFDRevPage;
	afx_msg void OnBnClickedCheckSmfdRevPage();
};
