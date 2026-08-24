#pragma once
#include "resource.h"

// CDialog_Smfd_Vorils_RC dialog

class CDialog_Smfd_Vorils_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Vorils_RC)

public:
	CDialog_Smfd_Vorils_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Vorils_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_VORILS_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_VorFreq;
	CString m_edt_SmfdRc_ILSFreq;
	CString m_edt_SmfdRc_VorBear;
	BOOL m_chk_SmfdRc_LocDev;
	BOOL m_chk_SmfdRc_GlidDev;
};
