#pragma once

#include "resource.h"
// CDialog_AHRS_VISUALE dialog

class CDialog_AHRS_VISUAL : public CDialog
{
	DECLARE_DYNAMIC(CDialog_AHRS_VISUAL)

public:
	CDialog_AHRS_VISUAL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_AHRS_VISUAL();
	CString m_strAHRUPtNo;
	CString m_strStatusAHRUPtNo;

	CString m_strRMMPtNo;
	CString m_strStatusRMMPtNo;

	CString m_strMMSPtNo;
	CString m_strStatusMMSPtNo;
	
	CString m_strAHRSDamage;
	CString m_strStatusAHRSDamage;

	CString m_strAHRSScratches;
	CString m_strStatusAHRSScratches;
	CString m_strAHRSScrews;
	CString m_strStatusAHRSScrews;
	CString m_strAHRSPins;
	CString m_strStatusAHRSPins;

// Dialog Data
	enum { IDD = IDD_DIALOG_AHRS_VISUAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckPnAhru();
	afx_msg void OnBnClickedCheckPnRmm();
	afx_msg void OnBnClickedCheckPnMms();
	BOOL m_ctlChkAHRUPNO;
	BOOL m_ctlChkRMMPNO;
	BOOL m_ctlChkMMSPNO;
	afx_msg void OnBnClickedOk();
	BOOL m_chkAHRSDamage;
	BOOL m_chkAHRSScratches;
	BOOL m_chkAHRSScrews;
	BOOL m_chkAHRSPins;
	afx_msg void OnBnClickedCheckAhrsDamage();
	afx_msg void OnBnClickedCheckAhrsScratches();
	afx_msg void OnBnClickedCheckAhrsScrew();
	afx_msg void OnBnClickedCheckAhrsPins();
	CString m_edtAHRUPno;
	CString m_edtRMMPno;
	CString m_edtMMSPno;
};
