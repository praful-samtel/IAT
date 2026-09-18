#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANFTL dialog

class CDialog_SMFD_FC_ANFTL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANFTL)

public:
	CDialog_SMFD_FC_ANFTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANFTL();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_FTL;
	afx_msg void OnBnClickedButtonSmfdAnalogFcftl();
	afx_msg void OnBnClickedOk();
	CString m_strFuelLh;
CString m_strStatusFuelLh;
};
