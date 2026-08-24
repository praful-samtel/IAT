#pragma once
#include "resource.h"

// CDialog_Smfd_AHRS_RC dialog

class CDialog_Smfd_AHRS_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_AHRS_RC)

public:
	CDialog_Smfd_AHRS_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_AHRS_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_AHRS_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_MagHead;
	CString m_edt_SmfdRc_PitAng;
	CString m_edt_SmfdRc_RollAng;
	CString m_edt_SmfdRc_NorAcc;
};
