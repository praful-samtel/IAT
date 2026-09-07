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
	CString m_strBusTie;
	CString m_strStatusBusTie;
	CString m_strCanopy;
	CString m_strStatusCanopy;
	CString m_strEcsoff;
	CString m_strStatusEcsoff;
	CString m_strEcsOvPr;
	CString m_strStatusEcsOvPr;
	CString m_strAoamute;
	CString m_strStatusAoamute;
	CString m_strAlarmMute;
	CString m_strStatusAlarmMute;
	CString m_strDemist;
	CString m_strStatusDemist;
	CString m_strStarton;
	CString m_strStatusStarton;
	afx_msg void OnBnClickedButtonEcsovpr();
	afx_msg void OnBnClickedButtonAoamute();
	afx_msg void OnBnClickedButtonAlarmMute();
	afx_msg void OnBnClickedButtonDemist();
	afx_msg void OnBnClickedButtonStarton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckBustieRc();
	afx_msg void OnBnClickedCheckCanopyRc();
	afx_msg void OnBnClickedCheckEcsovprRc();
	afx_msg void OnBnClickedCheckAoamuteRc();
	afx_msg void OnBnClickedCheckAlarmmuteRc();
	afx_msg void OnBnClickedCheckDemistRc();
	afx_msg void OnBnClickedButtonEcsoff();
	afx_msg void OnBnClickedCheckStartonRc();
};
