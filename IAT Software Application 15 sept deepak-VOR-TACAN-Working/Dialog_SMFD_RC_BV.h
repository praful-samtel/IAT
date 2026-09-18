#pragma once

#include "resource.h"
// CDialog_SMFD_RC_BV dialog

class CDialog_SMFD_RC_BV : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_BV)

public:
	CDialog_SMFD_RC_BV(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_BV();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_BV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRcbv();
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_Battvol;
		CString m_strbatvolt;
	CString m_strStatusbatvolt;
};
