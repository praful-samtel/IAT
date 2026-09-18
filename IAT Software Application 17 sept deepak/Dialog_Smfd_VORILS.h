#pragma once
#include "resource.h"

#define WM_UPDATE_ARINC (WM_USER + 125)
// CDialog_Smfd_VORILS dialog

class CDialog_Smfd_VORILS : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_VORILS)

public:
	CDialog_Smfd_VORILS(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_VORILS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_VORILS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:


	int m_edtvorbrg;

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

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSendarinclabel();
	static UINT ArincRXThread(LPVOID pParam);
	void ExecuteArincRX();
	afx_msg void OnBnClickedOk();
	BOOL m_chk_SMFD_VorFreq;
	BOOL m_chk_SMFD_IlsFreq;
	afx_msg void OnBnClickedCheckVorfreq();
	afx_msg void OnBnClickedCheckIlsFreq();
	CString m_edt_LocDev173;
	CString m_edt_GlsDev174;

	afx_msg void OnDestroy();
	
	BOOL m_bThreadRunning;
	BOOL m_bStopThread;
	CWinThread* m_pArincRXThread;
};
