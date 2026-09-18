/************************************************************************************************
*		Project Name		:	Universal Tester																*
*		File Name			:	CaptionListView .h												    *
*		Author				:	Chaman Lal Sharma												*
*		Date				:	25th May 2011													*
*		Version of file		:	V1.00															*
*		Description 		:	This File includes the declarations of the following:-          *
*																								*
*								public member functions:-                                       *
*									CWnd* GetListCtrl(void);									*
*									CWnd& GetListCtrl2(void);									* 
*************************************************************************************************/

#if !defined(AFX_CAPTIONLISTVIEW_H__98FA9E77_A734_11D2_8F63_00104B9DFF64__INCLUDED_)
#define AFX_CAPTIONLISTVIEW_H__98FA9E77_A734_11D2_8F63_00104B9DFF64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CaptionView.h"


#include <afxcview.h>


//**************************************************************************
// CCaptionListView view
//***************************************************************************
class CCaptionListView : public CCaptionView
{
protected:
	
	CCaptionListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCaptionListView)

// Attributes
public:

private:

// Operations
public:
	

//	CListCtrl* GetListCtrl(void);
//	CListCtrl& GetListCtrl2(void);

	CWnd* GetListCtrl(void);
	CWnd& GetListCtrl2(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptionListView)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void RemoveImageList(int nImageList);
	//virtual int OnCreate(LPCREATESTRUCT lpCreateStruct); 
	virtual void OnNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	virtual ~CCaptionListView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CCaptionListView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//***************************************************************************
//***************************************************************************
//	                 I N L I N E   F U N C T I O N S 
//***************************************************************************
//***************************************************************************

//***************************************************************************
inline CWnd* CCaptionListView::GetListCtrl(void)
{
	//return static_cast<CListCtrl&>(*m_pCtrl);	
	return static_cast<CWnd*>(m_pCtrl);	
}

//***************************************************************************
inline CWnd& CCaptionListView::GetListCtrl2(void)
{
	//return static_cast<CListCtrl&>(*m_pCtrl);
	return static_cast<CWnd&>(*m_pCtrl);
}

//***************************************************************************
//***************************************************************************
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTIONLISTVIEW_H__98FA9E77_A734_11D2_8F63_00104B9DFF64__INCLUDED_)
