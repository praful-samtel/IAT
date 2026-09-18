#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANGV dialog

class CDialog_SMFD_FC_ANGV : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANGV)

public:
	CDialog_SMFD_FC_ANGV(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANGV();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_GV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFcgv();
	afx_msg void OnBnClickedOk();
	CString m_edt_SMFDFC_GV;
		CString m_strgenvolt;
	CString m_strStatusgenvolt;
};
