#if !defined(AFX_PERREFRESHRATEDLG_H__13A26615_9719_442E_8611_B80FC6A760F0__INCLUDED_)
#define AFX_PERREFRESHRATEDLG_H__13A26615_9719_442E_8611_B80FC6A760F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PerRefreshRatedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPerRefreshRatedlg dialog

class CPerRefreshRatedlg : public CDialog
{
// Construction
public:
	CString m_strMeasured;
	CString m_strStatus;

	CPerRefreshRatedlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CPerRefreshRatedlg)
	enum { IDD = IDD_DIALOG_PER_RESPONSE_TIME };
	int		m_edtVSynch;
	//}}AFX_DATA

	CBrush brushNew;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPerRefreshRatedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPerRefreshRatedlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContinue();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckStatus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERREFRESHRATEDLG_H__13A26615_9719_442E_8611_B80FC6A760F0__INCLUDED_)
