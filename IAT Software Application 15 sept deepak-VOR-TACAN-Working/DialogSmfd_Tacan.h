#pragma once

#include "resource.h"
// CDialogSmfd_Tacan dialog
#define WM_UPDATE_ARINC (WM_USER + 126)

class CDialogSmfd_Tacan : public CDialog
{
	DECLARE_DYNAMIC(CDialogSmfd_Tacan)

public:
	CDialogSmfd_Tacan(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogSmfd_Tacan();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_TACAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	int m_edtTac201;
	int m_edtTac222;
	CString m_strtac145; 
	CString m_strStatustac145; 
	CString m_strtac201; 
	CString m_strStatustac201; 
	CString m_strtac222; 
	CString m_strStatustac222; 
	afx_msg void OnBnClickedOk();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSendarinclabel();
	BOOL m_chk_TacanWord;
	afx_msg void OnBnClickedCheckTacword();

	static UINT ArincRXThread(LPVOID pParam);
	void ExecuteArincRX();
	afx_msg LRESULT OnUpdateArinc(WPARAM wParam, LPARAM lParam);
	
	BOOL m_bThreadRunning;
	BOOL m_bStopThread;
	CWinThread* m_pArincRXThread;
};
