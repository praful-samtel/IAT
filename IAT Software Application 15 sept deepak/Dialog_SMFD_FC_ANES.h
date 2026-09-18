#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANES dialog

class CDialog_SMFD_FC_ANES : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANES)

public:
	CDialog_SMFD_FC_ANES(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANES();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_ES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_ES;
	afx_msg void OnBnClickedButtonSmfdAnalogFces();
	afx_msg void OnBnClickedOk();
CString m_strEngineSpd;
CString m_strStatusEngineSpd;
};
