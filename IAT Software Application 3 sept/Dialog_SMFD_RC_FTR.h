#pragma once
#include "resource.h"

// CDialog_SMFD_RC_FTR dialog

class CDialog_SMFD_RC_FTR : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_FTR)

public:
	CDialog_SMFD_RC_FTR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_FTR();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_FTR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRcftr();
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_FuelTankRH;
	CString m_strFuelRh;
CString m_strStatusFuelRh;
};
