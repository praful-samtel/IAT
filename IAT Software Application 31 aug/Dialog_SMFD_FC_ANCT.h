#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ANCT dialog

class CDialog_SMFD_FC_ANCT : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANCT)

public:
	CDialog_SMFD_FC_ANCT(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANCT();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_CT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_CT;
	afx_msg void OnBnClickedButtonSmfdAnalogFcct();
	afx_msg void OnBnClickedOk();
CString m_strCollectorTank;
CString m_strStatusCollectorTank;
};
