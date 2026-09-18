#pragma once
#include "resource.h"


// CDialog_AHRS_QualityChecks dialog
#define WM_UPDATE_ARINC (WM_USER + 120)
class CDialog_AHRS_QualityChecks : public CDialog
{
	DECLARE_DYNAMIC(CDialog_AHRS_QualityChecks)

public:
	CDialog_AHRS_QualityChecks(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_AHRS_QualityChecks();

// Dialog Data
	enum { IDD = IDD_DIALOG_AHRS_QUALITATIVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chkAHRSPitch;
	BOOL m_chkAHRSRoll;
	BOOL m_chkAHRSHeading;
	CString m_strAhrsPitch;
	CString m_strStatusAhrsPitch;
	CString m_strAhrsRoll;
	CString m_strStatusAhrsRoll;
	CString m_strAhrsHeading;
	CString m_strStatusAhrsHeading;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckAhrsPitch();
	afx_msg void OnBnClickedCheckAhrsRoll();
	afx_msg void OnBnClickedCheckAhrsHeading();
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);
	virtual BOOL OnInitDialog();

BOOL m_bThreadRunning;
BOOL m_bStopThread;

static UINT ArincRXThread(LPVOID pParam);

void ExecuteArincRX();
afx_msg void OnDestroy();
	
	CString m_edtAHRSPitch;
	CString m_edtAHRSRoll;
	CString m_edtAHRSHeading;
};
