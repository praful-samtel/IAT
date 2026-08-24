#pragma once
#include "resource.h"

// CDialog_Smfd_VORILS dialog

class CDialog_Smfd_VORILS : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_VORILS)

public:
	CDialog_Smfd_VORILS(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_VORILS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_VORILS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString m_edtvorfreq;
	CString m_edtilsfreq;
	int m_edtvorbrg;
	BOOL m_chklocalizer;
	BOOL m_chkglideslope;
	CString m_strvorfreq;
	CString m_strStatusvorfreq;
	CString m_strilsfreq;
	CString m_strStatusilsfreq;
    CString m_strlocalizer;
	CString m_strStatuslocalizer;
	CString m_strglideslope;
	CString m_strStatusglideslope;
	CString m_strvorbrg;
	CString m_strStatusvorbrg;
	afx_msg void OnBnClickedCheckLocalizer();
	afx_msg void OnBnClickedCheckGlideslope();
	afx_msg void OnBnClickedButtonSendarinclabel();
	afx_msg void OnBnClickedOk();
};
