#pragma once

#include "resource.h"
// CDlg_ISIS_ADUTest dialog
#define WM_UPDATE_ARINC (WM_USER + 110)

class CDlg_ISIS_ADUTest : public CDialog
{
	DECLARE_DYNAMIC(CDlg_ISIS_ADUTest)


public:
	CDlg_ISIS_ADUTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlg_ISIS_ADUTest();
	CString m_strISISAirspeed;
	CString m_strStatusISISAirspeed;
	
	CString m_strISISAltitude;
	CString m_strStatusISISAltitude;
	
	CString m_strISISMach;
	CString m_strStatusISISMach;
	
	CString m_strISISVertical;
	CString m_strStatusISISVertical;

	//RC
	CString m_strISISAirspeedRC;
	CString m_strStatusISISAirspeedRC;
	
	CString m_strISISAltitudeRC;
	CString m_strStatusISISAltitudeRC;
	
	CString m_strISISMachRC;
	CString m_strStatusISISMachRC;
	
	CString m_strISISVerticalRC;
	CString m_strStatusISISVerticalRC;
	afx_msg LRESULT OnUpdateArinc(WPARAM, LPARAM);

BOOL m_bThreadRunning;
BOOL m_bStopThread;

static UINT ArincRXThread(LPVOID pParam);

void ExecuteArincRX();
afx_msg void OnDestroy();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_ADU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL m_ctlChkISISAirspeed;
	BOOL m_ctlChkISISAltitude;
	BOOL m_ctlChkISISMach;
	BOOL m_ctlChkISISVertical;
	afx_msg void OnBnClickedCheckIsisAirspeed();
	afx_msg void OnBnClickedCheckIsisAltitude();
	afx_msg void OnBnClickedCheckIsisMach();
	afx_msg void OnBnClickedCheckIsisVerticalspeed();

	CString m_edtISISAirspeed;
	CString m_edtISISAltitude;
	CString m_edtISISMach;
	CString m_edtISISVertical;
	afx_msg void OnEnChangeEditIsisAirspeed();
	afx_msg void OnEnChangeEditIsisAltitude();
	afx_msg void OnEnChangeEditIsisMach();
	afx_msg void OnEnChangeEditIsisVertical();
	BOOL m_ctlChkISISVerticalSpeed;
	afx_msg void OnBnClickedCheckIsisVertical();
	afx_msg void OnBnClickedCheckIsisVerticalSpeed();
	BOOL M_ctlChkISISVerticalSpeed;
	afx_msg void OnBnClickedButtonArincSimulate();
	CString m_edtISISAirspeedRC;
	CString m_edtISISAltitudeRC;
	CString m_edtISISMachRC;
	BOOL M_ctlChkISISVerticalSpeedRC;
	afx_msg void OnBnClickedCheckIsisVerticalSpeed2();
	afx_msg void OnBnClickedButtonArincrx();
};
