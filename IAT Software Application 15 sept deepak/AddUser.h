/************************************************************************************************
*		Project Name		:	Universal Tester																*
*		File Name			:	AddUser.h														*
*		Author				:	Chaman Lal Sharma												*
*		Date				:	19th July 2011													*
*		Version of file		:	V1.01															*
*		Description 		:	This File includes the declarations of the following:-          *
*																								*
*								public member functions:-                                       *
*									CAddUser(CWnd* pParent = NULL)                              *
*																								*
*								public member variables:-										*
*									CBrush brushNew												*
*									CToolTipCtrl m_Tooltip										*
*************************************************************************************************/

#if !defined(AFX_ADDUSER_H__A72B07EA_6D5B_4CBA_9498_9AD3A8751DA1__INCLUDED_)
#define AFX_ADDUSER_H__A72B07EA_6D5B_4CBA_9498_9AD3A8751DA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddUser.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddUser dialog

class CAddUser : public CDialog
{
// Construction
public:
	CAddUser(CWnd* pParent = NULL);   // standard constructor
	CBrush brushNew;
	CToolTipCtrl m_Tooltip;
// Dialog Data
	//{{AFX_DATA(CAddUser)
	enum { IDD = IDD_DIAG_ADD_USER };
	CComboBox	m_UsrType;
	CString	m_TxtConfirmPassword;
	CString	m_TxtCurrentPassword;
	CString	m_TxtNewUserName;
	CString	m_TxtNewPassword;
	CString	m_Admin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddUser)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddUser)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnAddUser();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDUSER_H__A72B07EA_6D5B_4CBA_9498_9AD3A8751DA1__INCLUDED_)
