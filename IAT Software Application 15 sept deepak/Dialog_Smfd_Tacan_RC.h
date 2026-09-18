#pragma once
#include "resource.h"

// CDialog_Smfd_Tacan_RC dialog

class CDialog_Smfd_Tacan_RC : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Tacan_RC)

public:
	CDialog_Smfd_Tacan_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Tacan_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_TACAN_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	CString m_edt_SmfdRc_TacDis;
	CString m_edt_SmfdRc_TacBear;
	CString m_strtac145; 
	CString m_strStatustac145; 
	CString m_strtac201; 
	CString m_strStatustac201; 
	CString m_strtac222; 
	CString m_strStatustac222; 
	afx_msg void OnBnClickedButtonSendarinclabelRc();
	BOOL m_chk_TacanWordRC;
	afx_msg void OnBnClickedCheckTacwordrc();
};
