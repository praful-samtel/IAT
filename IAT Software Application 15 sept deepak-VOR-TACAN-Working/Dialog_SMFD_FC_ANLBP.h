#pragma once

#include "resource.h"
// CDialog_SMFD_FC_ANLBP dialog

class CDialog_SMFD_FC_ANLBP : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_ANLBP)

public:
	CDialog_SMFD_FC_ANLBP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_ANLBP();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_LBP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SMFDFC_LBP;
	afx_msg void OnBnClickedButtonSmfdAnalogFclbp();
	afx_msg void OnBnClickedOk();
	CString m_strLhBrake;
CString m_strStatusLhBrake;
};
