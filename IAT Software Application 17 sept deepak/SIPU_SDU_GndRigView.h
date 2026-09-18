// SIPU_SDU_GndRigView.h : interface of the CSIPU_SDU_GndRigView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIPU_SDU_GNDRIGVIEW_H__5F30DFCD_6FB6_4DCE_B30C_64C4784293E2__INCLUDED_)
#define AFX_SIPU_SDU_GNDRIGVIEW_H__5F30DFCD_6FB6_4DCE_B30C_64C4784293E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSIPU_SDU_GndRigView : public CView
{
protected: // create from serialization only
	CSIPU_SDU_GndRigView();
	DECLARE_DYNCREATE(CSIPU_SDU_GndRigView)

// Attributes
public:
	CSIPU_SDU_GndRigDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIPU_SDU_GndRigView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSIPU_SDU_GndRigView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSIPU_SDU_GndRigView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SIPU_SDU_GndRigView.cpp
inline CSIPU_SDU_GndRigDoc* CSIPU_SDU_GndRigView::GetDocument()
   { return (CSIPU_SDU_GndRigDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIPU_SDU_GNDRIGVIEW_H__5F30DFCD_6FB6_4DCE_B30C_64C4784293E2__INCLUDED_)
