/******************************************************************************
* Project Name	  :	Universal Tester						    		                      *
* File Name		  :	CHANGEPASSWORD.h            				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					CCHANGEPASSWORD(CWnd* pParent = NULL);                    *
*														                      *
*					public member variables:-      			                  *
*					CToolTipCtrl m_Tooltip;                                   *
******************************************************************************/

#if !defined(AFX_CHANGEPASSWORD_H__6BD10C27_9A4E_4528_868B_683E9AE9BDC8__INCLUDED_)
#define AFX_CHANGEPASSWORD_H__6BD10C27_9A4E_4528_868B_683E9AE9BDC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CHANGEPASSWORD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCHANGEPASSWORD dialog

class CCHANGEPASSWORD : public CDialog
{
// Construction
public:
	CCHANGEPASSWORD(CWnd* pParent = NULL);  // standard constructor
	CToolTipCtrl m_Tooltip;

// Dialog Data
	//{{AFX_DATA(CCHANGEPASSWORD)
	enum { IDD = IDD_DIAG_CHANGE_PASSWORD };
	CString	m_TxtCurrentPassword;
	CString	m_TxtNewPassword;
	CString	m_TxtConfirmPassword;
	CString	m_TxtUserName;
	//}}AFX_DATA


// Overrides
	//BOOL ValidatePassWrd();
	//BOOL Decrypt(CString in_strData, CString &out_strData);
	//BOOL Encrypt(CString in_strData, CString &out_strData);
	DWORD m_dwChkSum;
	CString m_strRegSection, m_strRegEntry1, m_strRegEntry2, m_strRegVal;
	DWORD m_dwRegChkSum;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCHANGEPASSWORD)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	CBrush brushNew;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCHANGEPASSWORD)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel();
	afx_msg void OnChangePassword();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEPASSWORD_H__6BD10C27_9A4E_4528_868B_683E9AE9BDC8__INCLUDED_)
