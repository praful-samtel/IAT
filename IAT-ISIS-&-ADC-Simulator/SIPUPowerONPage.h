/******************************************************************************
* Project Name	  :	ISIS						    		                      *
* File Name		  :	SIPUPowerONPage.h           				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					void ReceiveElapsedTimeCount();                           *
*					void ReadBackCmdBytes(int iByteCount);                    *
*					enum { IDD = IDD_DLG_MAINPANEL }                          *
*                                                                             *
*					public member variables:-      			                  *
*					                             *
*					CComboBox	m_Combo_Stop_On_Fault;                        *
*					CComboBox	m_Cambo_Mode;                                 *
*					CListBox	m_List_Sub_Test;                              *
*					CListBox	m_List_Main_List;                             *
*					CString	m_cmdStrSelectedType;                             *
*					CString	m_cmdStrSubTest;                                  *
*					CString	m_Edit_MFD_No;                                    *
*					float	m_fEdit_TestStart;                                *
*					float	m_fEdit_TestEnd;                                  *
******************************************************************************/

#if !defined(AFX_SIPUPOWERONPAGE_H__A2308D38_48F6_4D3A_AF63_189F8F95081F__INCLUDED_)
#define AFX_SIPUPOWERONPAGE_H__A2308D38_48F6_4D3A_AF63_189F8F95081F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SIPUPowerONPage.h : header file
//

#include "XListCtrl.h"
#include "Macros.h"
#include "afxwin.h"
#include "resource.h" 
#include "BDaqCtrl.h"
using namespace Automation::BDaq;
/////////////////////////////////////////////////////////////////////////////
// CSIPUPowerONPage form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif





//extern sTest_Result s_Curr_Test_Result;
class CSIPUPowerONPage : public CFormView
{
public:

	//BOOL InitializePCI_Boards();
	void ReceiveElapsedTimeCount();
	void ReadBackCmdBytes(int iByteCount);
	void OnSize(UINT nType, int cx, int cy);
	CSIPUPowerONPage();           // protected constructor used by dynamic creation
//protected:	
	DECLARE_DYNCREATE(CSIPUPowerONPage)
	CBrush brushNew;
	CToolTipCtrl m_Tooltip;

// Form Data
public:
	//{{AFX_DATA(CSIPUPowerONPage)
	enum { IDD = IDD_DLG_MAINPANEL };


	CComboBox	m_Combo_Stop_On_Fault;
	CComboBox	m_Cambo_Mode;
	CListBox	m_List_Sub_Test;
	CListBox	m_List_Main_List;
	CString	m_cmdStrSelectedType;
	CString	m_cmdStrSubTest;
	CString	m_Edit_MFD_No;
	float	m_fEdit_TestStart;
	float	m_fEdit_TestEnd;
	//}}AFX_DATA

// Attributes
public:
	
	CXListCtrl *DynListCtrl;
	unsigned char m_ucMode;
	unsigned char m_ucStoponFault;
	
// structure for storing the test results
struct sTest_Result
{
	char m_strMajorTestName[100];
	char m_strMinorTestName[100];
	char m_strSpec[100];
	char m_strMeasuered_Val[100];
	char m_strTestStatus[100];
	unsigned int m_uiMinor_Test_ID;
}s_Curr_Test_Result;


// Operations
public:
	void ResetListCtrl(CXListCtrl &list);
	void FillListCtrl(CXListCtrl& list);
	void InitListCtrl(CXListCtrl& list);

	void Fill_Mapping_Table();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIPUPowerONPage)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
//protected:
	public:
		
		
		void ExecuteLRUTestSequence();
		void ExecuteDUConfig2Sequence();
		void UpdateListBoxData();
		void ProcessTest(
    int iCurrentTest,
    int& bDlgFlag,
    int& iResult,
    CDialog* pDlg,
    BOOL bLastInGroup,
    CFile* pUseFile);
		void ProcessTestRC(
    int iCurrentTest,
    int& bDlgFlag,
    int& iResult,
    CDialog* pDlg,
    BOOL bLastInGroup,
    CFile* pUseFile);
		void EnableLRUSerialInputs(int lru);
		int m_iStartTestNo;
		CString m_strStoppedReportName;

		int CheckForTestStopped();
		void LogTestStoppedInfo(int iCurrentTest);
		
		void SetSelectedControls(int iTestNumber);
		void DisplayPartialControls();
		void HidePartialControls();
	virtual ~CSIPUPowerONPage();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSIPUPowerONPage)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnMainSIPUDetailSensor();
	afx_msg void OnViewsensorDet();
	afx_msg void OnsSIPUST();
	afx_msg void OnFileLog();
	afx_msg void OnBtnViewarinc();
	afx_msg void OnButtonExec();
	afx_msg void OnCloseupComboMode();
	afx_msg void OnCloseupComboStopOnFault();
	afx_msg void OnKillfocusListMainTest();
	afx_msg void OnSetfocusListSubTest();
	afx_msg void OnSelchangeListMainTest();
	afx_msg void OnSelchangeListSubTest();
	afx_msg void OnButtonExit();
	afx_msg void OnButPrint();
	afx_msg void OnButtonSer();
	afx_msg void OnUpdateEdit7();
	afx_msg void OnSelchangeComboMode();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnButPrintFile();
	afx_msg void OnSelchangeComboMfdMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeComboDuType();
	CString m_Edit_DU_No;
	CComboBox m_ctlCboDUType;

//	afx_msg void OnEnChangeEditDuSno();

void ExecuteISISSequence(CFile* pFile);
void ExecuteSMFDSequence(CFile* pFile);
void ExecuteSMFDSequenceRC(CFile* pFile);
void ExecuteADCSequence(CFile* pFile);
void ExecuteAHRSTestSequence(CFile* pFile);
void ExecuteGPSTestSequence(CFile* pFile);
void ExecuteVORILSTACTestSequence(CFile* pFile);
BOOL ValidateUserInput(CString &strTmpName);
BOOL CheckSerial(const CString& serial, UINT controlID, const CString& name);
	afx_msg void OnClose();
	CString m_edtStrTestDesc;
	// Test Description


// SMFD/MFD
CString m_strSMFD1SNO;
CString m_strSMFD2SNO;
CString m_strMFD1SNO;
CString m_strMFD2SNO;

// ISIS
CString m_strISIS_DU1_SNO;
CString m_strISIS_DU2_SNO;
CString m_strISIS_ADU_SNO;
CString m_strISIS_AHRS_SNO;
CString m_strISIS_MGM_SNO;

// ADC
CString m_strADC_SNO;

// AHRS
CString m_strAHRS_SNO;

// GPS
CString m_strGPS_SNO;

// NAV
CString m_strNAV_SNO;
CString m_strNAVTAC_SNO;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIPUPOWERONPAGE_H__A2308D38_48F6_4D3A_AF63_189F8F95081F__INCLUDED_)
