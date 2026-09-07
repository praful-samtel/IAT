/************************************************************************************************
*		Project Name		:	Universal Tester																*
*		File Name			:	CaptionView .h												    *
*		Author				:	Chaman Lal Sharma												*
*		Date				:	25th May 2011													*
*		Version of file		:	V1.00															*
*		Description 		:	This File includes the declarations of the following:-          *
*																								*
*								public member functions:-                                       *
*									inline CCaptionBar* GetCaptionBar( void );					*
*									inline CWnd* GetClientArea( void );							*
*									inline void GetCaptionRect( LPRECT lpRect ) ;				*
*									virtual ~CCaptionView();									*						
*************************************************************************************************/


//***************************************************************************
// CaptionView.h : interface of the CCaptionView class
//**************************************************************************
//
//***************************************************************************
#if !defined(AFX_CAPTIONVIEW_H__2454F2F1_A5D1_11D2_8F43_3078302C2030__INCLUDED_)
#define AFX_CAPTIONVIEW_H__2454F2F1_A5D1_11D2_8F43_3078302C2030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CaptionBar.h"

//***************************************************************************
//***************************************************************************
class CCaptionView : public CView
{

	CCaptionView();

protected: // create from serialization only

	CCaptionView( CRuntimeClass* prtti ); 

	DECLARE_DYNCREATE(CCaptionView)

// Attributes
public:

// Operations
public:

	inline CCaptionBar* GetCaptionBar( void );
	inline CWnd* GetClientArea( void );
	inline void GetCaptionRect( LPRECT lpRect ) ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptionView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCaptionView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCaptionView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
    CCaptionBar*	m_pCaption;
	CWnd*			m_pCtrl;
};


//***************************************************************************
//***************************************************************************
//			          I N L I N E   F U N C T I O N S 
//***************************************************************************
//***************************************************************************

//***************************************************************************
inline CCaptionBar* CCaptionView::GetCaptionBar( void )
{
	return m_pCaption; 
}
//***************************************************************************
inline CWnd* CCaptionView::GetClientArea( void )
{
	return m_pCtrl; 
}
//***************************************************************************
inline void CCaptionView::GetCaptionRect( LPRECT lpRect ) 
{
	CRect rectClient;
	CWnd::GetClientRect( lpRect );

	int height = m_pCaption->GetCaptionHeight();

	lpRect->top += height;
}

//***************************************************************************

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately 
// before the previous line.

#endif // !defined(AFX_CAPTIONVIEW_H__2454F2F1_A5D1_11D2_8F43_3078302C2030__INCLUDED_)
