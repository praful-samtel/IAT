#pragma once
#include "resource.h"

// CDialog_ISIS_NAVMODE dialog

class CDialog_ISIS_NAVMODE : public CDialog
{
	DECLARE_DYNAMIC(CDialog_ISIS_NAVMODE)

public:
	CDialog_ISIS_NAVMODE(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ISIS_NAVMODE();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_NAVMODE };
private:
	
static UINT NavModeThread(LPVOID pParam);

void ExecuteNavModeSimulation();

BOOL m_bThreadRunning;

int m_iModeStep;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
		virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chk_ISISFC_NAVMODE;
	BOOL m_chk_ISISRC_NAVMODE;
	afx_msg void OnBnClickedCheckIsisfcNavmode();
	afx_msg void OnBnClickedCheckIsisrcNavmode();
	afx_msg void OnBnClickedOk();
	CString m_strIsisFCNAVMODE;
	CString m_strStatusIsisFCNAVMODE;
	CString m_strIsisRCNAVMODE;
	CString m_strStatusIsisRCNAVMODE;
};
