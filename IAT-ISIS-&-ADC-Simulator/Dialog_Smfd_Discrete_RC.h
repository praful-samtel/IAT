#pragma once
#include "resource.h"
#include "afxwin.h"

// CDialog_Smfd_Discrete_RC dialog

class CDialog_Smfd_Discrete_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Discrete_RC)

public:
	CDialog_Smfd_Discrete_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Discrete_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_DISCRETE_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBustie();
	afx_msg void OnBnClickedButtonCanopy();
	BOOL m_chk_SmfdRc_BusTie;
	BOOL m_chk_SmfdRc_Canopy;
	BOOL m_chk_SmfdRc_EcsOff;
	afx_msg void OnBnClickedCheckEcsoffRc();
	BOOL m_chk_SmfdRc_EcsOvPr;
	BOOL m_chk_SmfdRc_AoaMute;
	CButton m_chk_SmfdRc_AlMu;
	BOOL m_chk_SmfdRc_Demist;
	BOOL m_chk_SmfdRc_StOn;
};
