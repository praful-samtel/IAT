#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ETP dialog

class CDialog_SMFD_FC_ETP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ETP)

public:
	CDialog_SMFD_FC_ETP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ETP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_ETP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_ETP;
	afx_msg void OnBnClickedButtonSmfdAnalogFcetp();
	afx_msg void OnBnClickedOk();
	CString m_strelevator;
	CString m_strStatuselevator;
};
