#pragma once

#include "resource.h"

// CDialog_Smfd_Discrete dialog

class CDialog_Smfd_Discrete : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Discrete)

public:
	CDialog_Smfd_Discrete(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Discrete();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_DISCRETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL m_chkBusTie;
	BOOL m_chkCanopy;
	BOOL m_chkEcsOff;
	BOOL m_chkEcsOvPr;
	BOOL m_chkAoaMute;
	BOOL m_chkAlarmMute;
	BOOL m_chkDemist;
	BOOL m_chkStarton;
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
	afx_msg void OnBnClickedButtonBustie();
	afx_msg void OnBnClickedButtonCanopy();
	afx_msg void OnBnClickedButtonEcsoff();
	afx_msg void OnBnClickedButtonEcsovpr();
	afx_msg void OnBnClickedButtonAoamute();
	afx_msg void OnBnClickedButtonAlarmMute();
	afx_msg void OnBnClickedButtonDemist();
	afx_msg void OnBnClickedButtonStarton();
	afx_msg void OnBnClickedCheckBustie();
	afx_msg void OnBnClickedCheckCanopy();
	afx_msg void OnBnClickedCheckEcsoff();
	afx_msg void OnBnClickedCheckEcsovpr();
	afx_msg void OnBnClickedCheckAoamute();
	afx_msg void OnBnClickedCheckAlarmmute();
	afx_msg void OnBnClickedCheckDemist();
	afx_msg void OnBnClickedCheckStarton();
};
