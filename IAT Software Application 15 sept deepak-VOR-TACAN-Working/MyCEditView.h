#if !defined(AFX_MYCEDITVIEW_H__80055FED_28ED_4F26_BE91_810A0C136FED__INCLUDED_)
#define AFX_MYCEDITVIEW_H__80055FED_28ED_4F26_BE91_810A0C136FED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyCEditView.h : header file
//

////////////////////////////////////////////////////////////////////////////
// MyCEditView view

class MyCEditView : public CEditView
{
protected:
	CBrush m_redbrush;
	CBrush m_bluebrush;
	COLORREF m_redcolor;
	COLORREF m_bluecolor;
	COLORREF m_textcolor;

	MyCEditView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(MyCEditView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyCEditView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~MyCEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(MyCEditView)
	afx_msg BOOL OnEditChange();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor); 
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCEDITVIEW_H__80055FED_28ED_4F26_BE91_810A0C136FED__INCLUDED_)
