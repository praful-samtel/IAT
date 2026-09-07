#pragma once
#include "resource.h"
#include "afxwin.h"
#include "ProgressDlg.h"
#define WM_UPDATE_SOFTWARE (WM_USER + 2)

class CDlg_ISIS_SWCHK : public CDialog
{
	DECLARE_DYNAMIC(CDlg_ISIS_SWCHK)

public:
	CDlg_ISIS_SWCHK(CWnd* pParent = NULL);
	virtual ~CDlg_ISIS_SWCHK();

	  static UINT SoftwareThread(LPVOID pParam);
    void ExecuteSoftwareRead();

    afx_msg LRESULT OnUpdateSoftware(WPARAM, LPARAM);
	afx_msg LRESULT OnProgressUpdate(WPARAM, LPARAM);
afx_msg LRESULT OnProgressClose(WPARAM, LPARAM);

    BOOL m_bThreadRunning;

	// Result values
	CString m_strISISMPMVer;
	CString m_strStatusISISMPMVer;

	CString m_strISISMPMCSum;
	CString m_strStatusISISMPMCSum;

	CString m_strISISSWVer;
	CString m_strStatusISISSWVer;

	CString m_strISISSWCsum;
	CString m_strStatusISISSWCsum;

	CString m_strISISRCMPMVer;
	CString m_strStatusISISRCMPMVer;

	CString m_strISISRCMPMCSum;
	CString m_strStatusISISRCMPMCSum;

	CString m_strISISRCSWVer;
	CString m_strStatusISISRCSWVer;

	CString m_strISISRCSWCsum;
	CString m_strStatusISISRCSWCsum;

	// Checkbox states
	

	enum { IDD = IDD_DIALOG_ISIS_SWCHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg void OnBnClickedCheckIsisMpmsv();
	afx_msg void OnBnClickedCheckIsisMpmsc();
	afx_msg void OnBnClickedCheckIsisBlgmsv();
	afx_msg void OnBnClickedCheckIsisBlgmsc();
	afx_msg void OnBnClickedOk();
	CString m_edt_ISISFC_MPMVR;
	CString m_edt_ISISFC_MPMCHK;
	CString m_edt_ISISFC_BLGMVR;
	CString m_edt_ISISFC_BLGMCHK;
	CString m_edt_ISISRC_MPMVR;
	CString m_edt_ISISRC_MPMCHK;
	CString m_edt_ISISRC_BLGMVR;
	CString m_edt_ISISRC_BLGMCHK;
	afx_msg void OnBnClickedButtonIsisSw();
	afx_msg void OnClose();

private:

BOOL ReadVersion(CString& strMainVersion,
                 CString& strCoVersion);

BOOL ReadChecksum(CString& strMainChecksum,
                  CString& strCoChecksum);
 CProgressDlg m_ProgressDlg;

 void PostProgress(int nPercent,LPCTSTR pszText);
 void PostCloseProgress();
};