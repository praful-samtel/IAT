#pragma once

#include "resource.h"
#include "ProgressDlg.h"
// CDlg_ISIS_PWR dialog
#define WM_UPDATE_CURRENT (WM_USER + 1)

class CDlg_ISIS_PWR : public CDialog
{
	DECLARE_DYNAMIC(CDlg_ISIS_PWR)
	CString m_strISISPWR;
	CString m_strStatusISISPWR;
	CString m_strMeasISISDURCPWR;
	CString m_strStatusCurrentISISDURC;
	CString m_strMeasISISADUPWR;
	CString m_strStatusCurrentISISADU;
	CString m_strMeasISISAHRSPWR;
	CString m_strStatusCurrentISISAHRS;
	
	struct PROGRESS_MSG
{
    int nPercent;
    CString strStatus;
};
 void PostProgress(int nPercent, LPCTSTR pszText);
void PostCloseProgress();

afx_msg LRESULT OnProgressUpdate(WPARAM, LPARAM);
afx_msg LRESULT OnProgressClose(WPARAM, LPARAM);
  CProgressDlg m_ProgressDlg;
public:
	CDlg_ISIS_PWR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlg_ISIS_PWR();
	static UINT PowerOnThread(LPVOID pParam);

    void ExecutePowerOnSequence();

    BOOL m_bThreadRunning;

	afx_msg LRESULT OnUpdateCurrent(WPARAM, LPARAM);

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnIsisPwr();
	virtual BOOL OnInitDialog();
	
	CString m_strCurrent28V;
	CString m_strStatusCurrent28V;
	CString m_strCurrentISISDURC;
	CString m_strCurrentISISADU;
	CString m_strCurrentISISAHRS;
	
	afx_msg void OnBnClickedButtonIsispwr();
};
