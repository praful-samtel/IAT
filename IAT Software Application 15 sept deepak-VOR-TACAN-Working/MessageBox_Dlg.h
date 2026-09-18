/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	MessageBox_Dlg.h               				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*                   None                                                      *
*                                                                             *
*					public member variables:-      			                  *
*					unsigned long m_ulTimercount;                             *
******************************************************************************/
#if !defined(AFX_MESSAGEBOX_DLG_H__7779E47F_8B93_425B_A29D_752D5A6108A7__INCLUDED_)
#define AFX_MESSAGEBOX_DLG_H__7779E47F_8B93_425B_A29D_752D5A6108A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MessageBox_Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMessageBox_Dlg dialog

class CMessageBox_Dlg : public CDialog
{
// Construction
public:
	unsigned long m_ulTimercount;

	CMessageBox_Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMessageBox_Dlg)
	enum { IDD = IDD_DIALOG_MSGBOX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CBrush brushNew;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageBox_Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMessageBox_Dlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_strDlgCaption;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGEBOX_DLG_H__7779E47F_8B93_425B_A29D_752D5A6108A7__INCLUDED_)
