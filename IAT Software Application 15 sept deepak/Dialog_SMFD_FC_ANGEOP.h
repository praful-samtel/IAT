#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANGEOP dialog

class CDialog_SMFD_FC_ANGEOP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANGEOP)

public:
	CDialog_SMFD_FC_ANGEOP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANGEOP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_EOP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_EOP;
	afx_msg void OnBnClickedButtonSmfdAnalogFceop();
		afx_msg void OnBnClickedOk();
			CString m_stroilpressure;
	CString m_strStatusoilpressure;
};
