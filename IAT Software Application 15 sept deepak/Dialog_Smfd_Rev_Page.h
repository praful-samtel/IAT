#pragma once

#include "resource.h"
// CDialog_Smfd_Rev_Page dialog

class CDialog_Smfd_Rev_Page : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Rev_Page)

public:
	CDialog_Smfd_Rev_Page(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Rev_Page();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_REVI_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL m_ctlChk_smfd_rev_page;
	CString m_strSMFDRevPage;
	CString m_strStatusSMFDRevPage;
	afx_msg void OnBnClickedCheckSmfdRevPage();
};
