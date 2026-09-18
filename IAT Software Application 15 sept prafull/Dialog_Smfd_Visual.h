#pragma once

#include "resource.h"
// CDialog_Smfd_Visual dialog

class CDialog_Smfd_Visual : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Visual)

public:
	CDialog_Smfd_Visual(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Visual();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_VISUAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckMfdVisual();
	afx_msg void OnBnClickedCheckSmfdVisual();
	afx_msg void OnBnClickedCheckSmfdDamage();
	BOOL m_ctlChk_mfd_pNo;
	BOOL m_ctlChk_smfd_pNo;
	BOOL m_ctlChk_smfd_damage;
	CString m_strMfdPNo;
	CString m_strStatusMfdPNo;
	CString m_strSmfdPNo;
	CString m_strStatusSmfdPNo;
	CString m_strSmfdDamage;
	CString m_strStatusSmfdDamage;
	CString m_strSmfdScratches;
	CString m_strStatusSmfdScratches;
	CString m_strSmfdScrews;
	CString m_strStatusSmfdScrews;
	CString m_strSmfdPins;
	CString m_strStatusSmfdPins;
	
	afx_msg void OnBnClickedOk();
	BOOL m_chkSmfdScratches;
	BOOL m_chkSmfdScrews;
	BOOL m_chkSmfdPins;
	afx_msg void OnBnClickedCheckSmfdScratches();
	afx_msg void OnBnClickedCheckSmfdScrew();
	afx_msg void OnBnClickedCheckSmfdPins();
	CString m_edt_mfd_fc_pn;
	CString m_edt_smfd_fc_pn;
	afx_msg void OnBnClickedCheckSmfdFcDamage();
	//afx_msg void OnBnClickedCheckSmfdFcScratches();
	//afx_msg void OnBnClickedCheckSmfdFcScrew();
	//afx_msg void OnEnChangeEditMfdPn();
	//afx_msg void OnEnChangeEditSmfdFcPn();
};
