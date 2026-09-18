#pragma once

#include "resource.h"
// CDialog_SMFD_RC_FTL dialog

class CDialog_SMFD_RC_FTL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_FTL)

public:
	CDialog_SMFD_RC_FTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_FTL();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_FTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonSmfdAnalogRcftl();
	CString m_edt_SmfdRc_FuelTankLH;
	// -------- FUEL --------
CString m_strFuelLh;
CString m_strStatusFuelLh;
};
