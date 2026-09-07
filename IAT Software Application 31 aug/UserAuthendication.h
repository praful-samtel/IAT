/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	UserAuthendication.h    				                  *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					CUserAuthendication(CWnd* pParent = NULL);                *
*					enum { IDD = IDD_DIAG_USER_AUTHENTICATION };    		  *	
*														                      *
*					public member variables:-      			                  *
*					CBrush brushNew;                                          *
*					CToolTipCtrl m_Tooltip;                                   *
*                   CButton	m_ButtonCancel;                                   *
*					CButton	m_ButtonLogin;                                    *
*					CString	m_TxtUserName;                                    *
*					CString	m_TxtEditPassword;                                *
******************************************************************************/

#if !defined(AFX_USERAUTHENDICATION_H__95BB98F0_CC93_4CD7_B690_0695D7C8FDCE__INCLUDED_)
#define AFX_USERAUTHENDICATION_H__95BB98F0_CC93_4CD7_B690_0695D7C8FDCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserAuthendication.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserAuthendication dialog

class CUserAuthendication : public CDialog
{
// Construction
public:
	CUserAuthendication(CWnd* pParent = NULL);   // standard constructor
	CBrush brushNew;
	CToolTipCtrl m_Tooltip;
// Dialog Data
	//{{AFX_DATA(CUserAuthendication)
	enum { IDD = IDD_DIAG_USER_AUTHENTICATION };
	CButton	m_ButtonCancel;
	CButton	m_ButtonLogin;
	CString	m_TxtUserName;
	CString	m_TxtEditPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserAuthendication)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserAuthendication)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnAddNewUser();
	afx_msg void OnLogin();
	afx_msg void OnClickCancel();
	afx_msg void OnBtnChangePasswrd();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERAUTHENDICATION_H__95BB98F0_CC93_4CD7_B690_0695D7C8FDCE__INCLUDED_)
