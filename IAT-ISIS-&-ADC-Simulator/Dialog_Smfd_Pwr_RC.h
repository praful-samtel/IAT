#pragma once
#include "resource.h"

// CDialog_Smfd_Pwr_RC dialog

class CDialog_Smfd_Pwr_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Pwr_RC)

public:
	CDialog_Smfd_Pwr_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Pwr_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_PWR_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_CurrCon;
	CString m_edt_MfdRc_CurrCon;
};
