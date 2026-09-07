// MyCEditView.cpp : implementation file
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "MyCEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////
// MyCEditView

IMPLEMENT_DYNCREATE(MyCEditView, CEditView)

MyCEditView::MyCEditView()
{
}

MyCEditView::~MyCEditView()
{
}


BEGIN_MESSAGE_MAP(MyCEditView, CEditView)
	//{{AFX_MSG_MAP(MyCEditView)
	ON_CONTROL_REFLECT_EX(EN_CHANGE, OnEditChange)
	ON_WM_CTLCOLOR_REFLECT()
			// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyCEditView drawing

void MyCEditView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// MyCEditView diagnostics

#ifdef _DEBUG
void MyCEditView::AssertValid() const
{
	CEditView::AssertValid();
}

void MyCEditView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MyCEditView message handlers

BOOL MyCEditView::OnEditChange()
{
	return FALSE;
}


HBRUSH MyCEditView::CtlColor(CDC* pDC, UINT nCtlColor) 
{


 m_redcolor=RGB(255,0,0);                      // red
 m_bluecolor=RGB(0,0,255);                     // blue
 m_textcolor=RGB(255,255,255);                 // white text

 m_redbrush.CreateSolidBrush(m_redcolor);      // red background
 m_bluebrush.CreateSolidBrush(m_bluecolor);    // blue 

 pDC->SetBkColor(m_redcolor); 
 pDC->SetTextColor(m_textcolor);

 return NULL;

}
