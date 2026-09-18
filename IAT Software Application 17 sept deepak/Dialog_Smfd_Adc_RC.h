#pragma once
#include "resource.h"

// CDialog_Smfd_Adc_RC dialog
#define WM_UPDATE_ARINC (WM_USER + 116)
class CDialog_Smfd_Adc_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Adc_RC)

public:
	CDialog_Smfd_Adc_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Adc_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ADC_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_PressAlti;
	CString m_edt_SmfdRc_MachNum;
	CString m_edt_SmfdRc_CompAirSp;
	CString m_edt_SmfdRc_AltiRate;
	CString m_edt_SmfdRc_StaAirTemp;
	CString m_edt_SmfdRc_TrAirSp;

		//virtual BOOL OnInitDialog();
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
		float dataArinc;
		CString m_strSmfdAdc203;
		CString m_strStatusSmfdAdc203;
		CString m_strSmfdAdc205;
		CString m_strStatusSmfdAdc205;
		CString m_strSmfdAdc206;
		CString m_strStatusSmfdAdc206;
		CString m_strSmfdAdc212;
		CString m_strStatusSmfdAdc212;
		CString m_strSmfdAdc213;
		CString m_strStatusSmfdAdc213;
		CString m_strSmfdAdc210;
		CString m_strStatusSmfdAdc210;


		afx_msg void OnBnClickedButtonRcarinc();
		BOOL m_bThreadRunning;
	BOOL m_bStopThread;
	CWinThread* m_pArincRXThread;

	static UINT ArincRXThread(LPVOID pParam);
	void ExecuteArincRX();

		afx_msg void OnDestroy();
	afx_msg LRESULT OnUpdateArinc(WPARAM wParam, LPARAM lParam);
};
