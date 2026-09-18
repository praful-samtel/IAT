#pragma once

#include "resource.h"

class CDialog_Smfd_Visual_FC : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Visual_FC)

public:
	CDialog_Smfd_Visual_FC(CWnd* pParent = NULL);
	virtual ~CDialog_Smfd_Visual_FC();

	enum { IDD = IDD_DIALOG_SMFD_VISUAL_FC };

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

	CString m_edt_mfd_fc_pn;
	CString m_edt_smfd_fc_pn;
};
