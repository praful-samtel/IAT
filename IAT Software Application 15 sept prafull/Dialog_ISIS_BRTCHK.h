#pragma once

#include "resource.h"
// CDialog_ISIS_BRTCHK dialog

class CDialog_ISIS_BRTCHK : public CDialog
{
	DECLARE_DYNAMIC(CDialog_ISIS_BRTCHK)

public:
	CDialog_ISIS_BRTCHK(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ISIS_BRTCHK();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_BRT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chkISISFCBRT;
	BOOL m_chkISISRCBRT;
	afx_msg void OnBnClickedCheckIsisfcBrt();
	afx_msg void OnBnClickedCheckIsisrcBrt();
	afx_msg void OnBnClickedOk();
	CString m_strIsisFCBRT;
	CString m_strStatusIsisFCBRT;
	CString m_strIsisRCBRT;
	CString m_strStatusIsisRCBRT;
};
