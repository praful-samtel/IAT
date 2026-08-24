#pragma once
#include "SIPU_SDU_GndRig.h"

// CDU_General_SelfTest dialog

class CDU_General_SelfTest : public CDialog
{
	DECLARE_DYNAMIC(CDU_General_SelfTest)

public:
	CDU_General_SelfTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDU_General_SelfTest();

	CString m_strMeasuredGenPOST;
	CString m_strStatusGenPOST;
	
	CString m_strMeasuredGenSDRAM;
	CString m_strStatusGenSDRAM;
	
	CString m_strMeasuredGenGrphcsCnt;
	CString m_strStatusGenGrphcsCnt;

	CString m_strMeasuredGenGrphcsMem;
	CString m_strStatusGenGrphcsMem;

	CString m_strMeasuredGenMIL1553B;
	CString m_strStatusGenMIL1553B;

// Dialog Data
	enum { IDD = IDD_DIALOG_GENERAL_SELFTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButGenSlfTest();
	BOOL m_ctlChkProSelf;
	BOOL m_ctlChkSDRAM;
	BOOL m_ctlChkGraphicsController;
	BOOL m_ctlChkGraphicsMemory;
	BOOL m_ctlChkMIL;
};
