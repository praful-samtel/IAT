#pragma once
#include "afxwin.h"
#include "resource.h"

class CDlg_ISIS_AHRS : public CDialog
{
	DECLARE_DYNAMIC(CDlg_ISIS_AHRS)

public:
	CDlg_ISIS_AHRS(CWnd* pParent = NULL);
	virtual ~CDlg_ISIS_AHRS();

	// Result strings
	CString m_strISISRoll;
	CString m_strStatusISISRoll;

	CString m_strISISPitch;
	CString m_strStatusISISPitch;

	CString m_strISISHeading;
	CString m_strStatusISISHeading;

	// Checkbox states
	BOOL m_bRoll;
	BOOL m_bPitch;
	BOOL m_bHeading;

	enum { IDD = IDD_DIALOG_ISIS_AHRS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	

	afx_msg void OnBnClickedCheckIsisAhrsroll();
	afx_msg void OnBnClickedCheckIsisAhrspitch();
	afx_msg void OnBnClickedCheckIsisAhrshead();
	afx_msg void OnBnClickedOk();
	BOOL m_bRollRC;
	BOOL m_bPitchRC;
	BOOL m_bHeadingRC;
	afx_msg void OnBnClickedCheckIsisAhrsroll2();
	afx_msg void OnBnClickedCheckIsisAhrspitch2();
	afx_msg void OnBnClickedCheckIsisAhrshead2();

	CString m_strISISRollRC;
	CString m_strStatusISISRollRC;

	CString m_strISISPitchRC;
	CString m_strStatusISISPitchRC;

	CString m_strISISHeadingRC;
	CString m_strStatusISISHeadingRC;

};