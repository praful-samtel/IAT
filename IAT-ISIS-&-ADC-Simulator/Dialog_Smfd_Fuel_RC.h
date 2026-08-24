#pragma once

#include "resource.h"
// CDialog_Smfd_Fuel_RC dialog

class CDialog_Smfd_Fuel_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Fuel_RC)

public:
	CDialog_Smfd_Fuel_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Fuel_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_FUEl_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_Fuel;
	CString m_edt_SmfdRc_FuelResponse;
};
