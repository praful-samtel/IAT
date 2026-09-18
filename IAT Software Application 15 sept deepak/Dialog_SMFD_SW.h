#pragma once
#include "resource.h"

// CDialog_SMFD_SW dialog

class CDialog_SMFD_SW : public CDialog
{
	DECLARE_DYNAMIC(CDialog_SMFD_SW)

public:
	CDialog_SMFD_SW(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_SW();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_SW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtSmfdSw;
	afx_msg void OnBnClickedOk();
	
	CString m_strSmfdSw;
	CString m_strStatusSmfdSw;
};
