#pragma once
#include "resource.h"

// CDialog_SMFD_FC_RTP dialog

class CDialog_SMFD_FC_RTP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_RTP)

public:
	CDialog_SMFD_FC_RTP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_RTP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_RTP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogFcrtp();
	CString m_edt_SMFDFC_RTP;
	afx_msg void OnBnClickedOk();
		CString m_strrudder;
	CString m_strStatusrudder;
};
