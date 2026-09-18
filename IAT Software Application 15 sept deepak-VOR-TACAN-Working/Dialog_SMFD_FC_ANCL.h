#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ANCL dialog

class CDialog_SMFD_FC_ANCL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANCL)

public:
	CDialog_SMFD_FC_ANCL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANCL();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_CL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFccl();
	afx_msg void OnBnClickedOk();
	CString m_edt_SMFDFC_CL;
			CString m_strcurload;
	CString m_strStatuscurload;
};
