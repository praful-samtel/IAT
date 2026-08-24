#pragma once
#include "resource.h"

// CDialog_Smfd_Sw_RC dialog

class CDialog_Smfd_Sw_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Sw_RC)

public:
	CDialog_Smfd_Sw_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Sw_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_SW_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_OpSw;
	afx_msg void OnBnClickedOk();
};
