#pragma once
#include "resource.h"

// CDialog_SMFD_FC_ANEB dialog

class CDialog_SMFD_FC_ANEB : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANEB)

public:
	CDialog_SMFD_FC_ANEB(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANEB();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_EB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFceb();
	CString m_edt_SMFDFC_EB;
	afx_msg void OnBnClickedOk();
	CString m_strEmerBrake;
CString m_strStatusEmerBrake;
};
