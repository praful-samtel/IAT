#pragma once
#include "afxwin.h"
#include "resource.h"

// CDialog_VORTAC_Visual dialog

class CDialog_VORTAC_Visual : public CDialog
{
	DECLARE_DYNAMIC(CDialog_VORTAC_Visual)

public:
	CDialog_VORTAC_Visual(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_VORTAC_Visual();
	// ---- ADD THESE ----
CString m_strVOR;
CString m_strStatusVOR;

CString m_strTACAN;
CString m_strStatusTACAN;

CString m_strCDU;
CString m_strStatusCDU;

CString m_strDamage;
CString m_strStatusDamage;

CString m_strScratches;
CString m_strStatusScratches;

CString m_strScrews;
CString m_strStatusScrews;

CString m_strPins;
CString m_strStatusPins;

// Dialog Data
	enum { IDD = IDD_DIALOG_VORTAC_VISUAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edtVOR_Reciever;
	CString m_edtTACAN_Reciever;
	
	CString m_edtCDU;
	BOOL m_ctlChkVorTacDamage;
	afx_msg void OnBnClickedCheckVortacDamage();
	BOOL m_chkVORTACScratches;
	BOOL m_chkVORTACScrews;
	BOOL m_chkVORTACPins;
	afx_msg void OnBnClickedCheckVortacScratches();
	afx_msg void OnBnClickedCheckVortacScrew();
	afx_msg void OnBnClickedCheckVortacPins();
};
