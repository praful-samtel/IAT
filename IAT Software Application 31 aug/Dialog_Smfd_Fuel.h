#pragma once
#include "resource.h"

// CDialog_Smfd_Fuel dialog

class CDialog_Smfd_Fuel : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Fuel)

public:
	CDialog_Smfd_Fuel(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Fuel();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_FUEl };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtsmfdsendfuellabel;
	CString m_edtsmfdRecfuellabel;
	afx_msg void OnBnClickedButtonSmfdFuelLabel();
	afx_msg void OnBnClickedOk();
	CString m_strSmfdfuel;
	CString m_strStatusSmfdfuel;


};
