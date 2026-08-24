#pragma once

#include "resource.h"

class CDialog_Smfd_Visual_RC : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Visual_RC)

public:
	CDialog_Smfd_Visual_RC(CWnd* pParent = NULL);
	virtual ~CDialog_Smfd_Visual_RC();

	enum { IDD = IDD_DIALOG_SMFD_VISUAL_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedCheckMfdVisual();
	afx_msg void OnBnClickedCheckSmfdVisual();
	afx_msg void OnBnClickedCheckSmfdDamage();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckSmfdScratches();
	afx_msg void OnBnClickedCheckSmfdScrew();
	afx_msg void OnBnClickedCheckSmfdPins();

	BOOL m_ctlChk_mfd_pNo;
	BOOL m_ctlChk_smfd_pNo;
	BOOL m_ctlChk_smfd_damage;
	BOOL m_chkSmfdScratches;
	BOOL m_chkSmfdScrews;
	BOOL m_chkSmfdPins;

	CString m_strMfdRcPNo;
	CString m_strStatusMfdRcPNo;
	CString m_strSmfdRcPNo;
	CString m_strStatusSmfdRcPNo;
	CString m_strRcDamage;
	CString m_strStatusRcDamage;
	CString m_strRcScratches;
	CString m_strStatusRcScratches;
	CString m_strRcScrews;
	CString m_strStatusRcScrews;
	CString m_strRcPins;
	CString m_strStatusRcPins;

	//CString m_strMfdPNo;
	//CString m_strStatusMfdPNo;
	CString m_edt_mfd_rc_pn;
	CString m_edt_smfd_rc_pn;
	CString m_edt_SmfdRc_PartNo;
	CString m_edt_MfdRc_PartNo;
	afx_msg void OnEnChangeEditSmfdRcPn();
};



