#pragma once
#include "resource.h"

// CDialog_Smfd_Tacan_RC dialog

class CDialog_Smfd_Tacan_RC : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Tacan_RC)

public:
	CDialog_Smfd_Tacan_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Tacan_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_TACAN_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_TacConWord;
	CString m_edt_SmfdRc_TacDis;
	CString m_edt_SmfdRc_TacBear;
};
