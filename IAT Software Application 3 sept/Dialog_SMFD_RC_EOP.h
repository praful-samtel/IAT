#pragma once
#include "resource.h"

// CDialog_SMFD_RC_EOP dialog

class CDialog_SMFD_RC_EOP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_EOP)

public:
	CDialog_SMFD_RC_EOP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_EOP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_EOP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRceop();
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_EnOilPress;
		CString m_stroilpressure;
	CString m_strStatusoilpressure;
};
