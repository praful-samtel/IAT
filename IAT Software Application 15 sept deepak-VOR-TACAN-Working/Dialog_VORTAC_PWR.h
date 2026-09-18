#pragma once

#include "resource.h"
// CDialog_VORTAC_PWR dialog

class CDialog_VORTAC_PWR : public CDialog
{
	DECLARE_DYNAMIC(CDialog_VORTAC_PWR)

public:
	CDialog_VORTAC_PWR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_VORTAC_PWR();

// Dialog Data
	enum { IDD = IDD_DIALOG_VORTAC_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtVorTac_PWR;
	CString m_strVORTACCurrent;
	CString m_strStatusVORTACCurrent;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonVorsysPwr();
};
