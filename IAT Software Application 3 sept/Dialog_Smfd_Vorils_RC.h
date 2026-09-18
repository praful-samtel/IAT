#pragma once
#include "resource.h"

// CDialog_Smfd_Vorils_RC dialog

class CDialog_Smfd_Vorils_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Vorils_RC)

public:
	CDialog_Smfd_Vorils_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Vorils_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_VORILS_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	CString m_edt_SmfdRc_VorBear;

	afx_msg void OnBnClickedButtonSendarinclabelRc();

	CString m_strvorfreq;
	CString m_strStatusvorfreq;
	CString m_strilsfreq;
	CString m_strStatusilsfreq;
    CString m_strlocalizer;
	CString m_strStatuslocalizer;
	CString m_strglideslope;
	CString m_strStatusglideslope;
	CString m_strvorbrg;
	CString m_strStatusvorbrg;
	afx_msg void OnBnClickedOk();
	BOOL m_chk_SMFD_VorFreqRC;
	BOOL m_chk_SMFD_IlsFreqRC;

	afx_msg void OnBnClickedCheckVorfreqrc2();
	afx_msg void OnBnClickedCheckIlsFreqrc();

	CString m_edt_LocDev173RC;
	CString m_edt_GlsDev174RC;
	afx_msg void OnBnClickedCheckVorfreqrc();
};
