#pragma once
#include "resource.h"

// CDialog_SMFD_RC_HPE dialog

class CDialog_SMFD_RC_HPE : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_HPE)

public:
	CDialog_SMFD_RC_HPE(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_HPE();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_HPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRchpe();
	afx_msg void OnBnClickedOk();
	
	CString m_strHydPresEmer;
CString m_strStatusHydPresEmer;


CString m_edt_SmfdRc_HyPrEm;
};
