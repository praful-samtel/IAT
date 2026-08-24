#pragma once

#include "resource.h"
// CDialogSmfdAHRS dialog

class CDialogSmfdAHRS : public CDialog
{
	DECLARE_DYNAMIC(CDialogSmfdAHRS)

public:
	CDialogSmfdAHRS(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogSmfdAHRS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_AHRS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_edtSmfdArinc320;
	int m_edtSmfdArinc324;
	int m_edtSmfdArinc325;
	int m_edtSmfdArinc333;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
		float dataArinc;
	    CString m_strSmfdAhrs320;
		CString m_strStatusSmfdAhrs320;
	    CString m_strSmfdAhrs324;
		CString m_strStatusSmfdAhrs324;
		CString m_strSmfdAhrs325;
		CString m_strStatusSmfdAhrs325;
		  CString m_strSmfdAhrs330;
		CString m_strStatusSmfdAhrs330;
		  CString m_strSmfdAhrs332;
		CString m_strStatusSmfdAhrs332;
		  CString m_strSmfdAhrs333;
		CString m_strStatusSmfdAhrs333;
		
		BOOL m_chkSmfdAhrs330;
		BOOL m_chkSmfdAhrs332;
		afx_msg void OnBnClickedButtonSendArinclabel();
		afx_msg void OnBnClickedCheckSmfdAhrs330();
		afx_msg void OnBnClickedCheckSmfdAhrs332();
};
