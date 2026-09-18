#pragma once
#include "resource.h"

// CDialog_Smfd_AHRS_RC dialog
#define WM_UPDATE_ARINC (WM_USER + 121)
class CDialog_Smfd_AHRS_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_AHRS_RC)

public:
	CDialog_Smfd_AHRS_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_AHRS_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_AHRS_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int m_edt_SmfdRc_MagHead;
	int m_edt_SmfdRc_PitAng;
	int m_edt_SmfdRc_RollAng;
	int m_edt_SmfdRc_NorAcc;
	//virtual BOOL OnInitDialog();
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
		float dataArinc;
	    CString m_strSmfdAhrs320;
		CString m_strStatusSmfdAhrs320;
	    CString m_strSmfdAhrs324;
		CString m_strStatusSmfdAhrs324;
		CString m_strSmfdAhrs325;
		CString m_strStatusSmfdAhrs325;
		  CString m_strSmfdAhrs330;
		CString m_strStatusSmfdAhrs330;
		  CString m_strSmfdAhrs332;
		CString m_strStatusSmfdAhrs332;
		  CString m_strSmfdAhrs333;
		CString m_strStatusSmfdAhrs333;
		
		

		
		BOOL m_chkSmfdAhrs330RC;
		BOOL m_chkSmfdAhrs332RC;
		afx_msg void OnBnClickedCheckSmfdAhrs330rc();
		afx_msg void OnBnClickedCheckSmfdAhrs332rc();
		afx_msg void OnBnClickedButtonAhrsRc();
		
	BOOL m_bThreadRunning;
	BOOL m_bStopThread;
	CWinThread* m_pArincRXThread;
		afx_msg LRESULT OnUpdateArinc(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();

	static UINT ArincRXThread(LPVOID pParam);
	void ExecuteArincRX();
};
