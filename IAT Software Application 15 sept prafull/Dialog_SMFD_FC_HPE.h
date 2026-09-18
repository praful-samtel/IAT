#pragma once

#include "resource.h"
// CDialog_SMFD_FC_HPE dialog

class CDialog_SMFD_FC_HPE : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_HPE)

public:
	CDialog_SMFD_FC_HPE(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_HPE();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_HPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_HPE;
	afx_msg void OnBnClickedButtonSmfdAnalogFchpe();
	afx_msg void OnBnClickedOk();
	CString m_strHydPresEmer;
CString m_strStatusHydPresEmer;
};
