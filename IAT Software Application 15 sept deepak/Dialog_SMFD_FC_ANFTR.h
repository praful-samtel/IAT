#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ANFTR dialog

class CDialog_SMFD_FC_ANFTR : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANFTR)

public:
	CDialog_SMFD_FC_ANFTR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANFTR();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	CString m_edt_SMFDFC_FTR;
	afx_msg void OnBnClickedButtonSmfdAnalogFcftr();
	afx_msg void OnBnClickedOk();
	CString m_strFuelRh;
CString m_strStatusFuelRh;
};
