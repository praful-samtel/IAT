#pragma once
#include "resource.h"

// CDialog_SMFD_RC_EB dialog

class CDialog_SMFD_RC_EB : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_RC_EB)

public:
	CDialog_SMFD_RC_EB(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_RC_EB();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_EB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRceb();
	afx_msg void OnBnClickedOk();
	
// -------- BRAKE --------
CString m_strEmerBrake;
CString m_strStatusEmerBrake;
CString m_edt_SmfdRc_EmBr;
};
