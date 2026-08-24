#pragma once
#include "resource.h"

// CDialog_ISIS_IBIT dialog

class CDialog_ISIS_IBIT : public CDialog
{
	DECLARE_DYNAMIC(CDialog_ISIS_IBIT)

public:
	CDialog_ISIS_IBIT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ISIS_IBIT();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_IBIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chk_ISISFCIBIT;
	BOOL m_chk_ISISRCIBIT;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckIsisfcIbit();
	afx_msg void OnBnClickedCheckIsisrcIbit();
	CString m_strIsisFCIBIT;
	CString m_strStatusIsisFCIBIT;
	CString m_strIsisRCIBIT;
	CString m_strStatusIsisRCIBIT;
};
