/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	Splach.h                				                  *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					enum { IDD = IDD_DLG_SPLASH };                            *
*														                      *
*					public member variables:-      			                  *
*					CBrush brushNew;                                          *
*					CComboBox	m_ctlCboHoldTime;                             *
*                   int		m_radTestType;                                    *
*					CButton	m_ButtonLogin;                                    *
*					CString	m_TxtUserName;                                    *
*					CString	m_TxtEditPassword;                                *
******************************************************************************/

#if !defined(AFX_SPLACH_H__F13B0AE8_20AB_4D2B_99B0_AFD19DECE01A__INCLUDED_)
#define AFX_SPLACH_H__F13B0AE8_20AB_4D2B_99B0_AFD19DECE01A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splach.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplach dialog

class CSplach : public CDialog
{
private:
	unsigned int m_uiTimeElapsed;
	unsigned int m_uiTimeHold;
	
	// Construction
public:
	CSplach(CWnd* pParent = NULL);   // standard constructor
	CBrush brushNew;

// Dialog Data
	//{{AFX_DATA(CSplach)
	enum { IDD = IDD_DLG_SPLASH };
	CComboBox	m_ctlCboHoldTime;
	int		m_radTestType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplach)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSplach)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnButContinue();
	afx_msg void OnSelchangeComboHoldTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticExeChecksum();
	afx_msg void OnBnClickedRadTesttype();
	afx_msg void OnBnClickedRadIltLumCentering();
    afx_msg void OnBnClickedRadIltselftest();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLACH_H__F13B0AE8_20AB_4D2B_99B0_AFD19DECE01A__INCLUDED_)
