// SIPU_SDU_GndRigView.cpp : implementation of the CSIPU_SDU_GndRigView class
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"

#include "SIPU_SDU_GndRigDoc.h"
#include "SIPU_SDU_GndRigView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView

IMPLEMENT_DYNCREATE(CSIPU_SDU_GndRigView, CView)

BEGIN_MESSAGE_MAP(CSIPU_SDU_GndRigView, CView)
	//{{AFX_MSG_MAP(CSIPU_SDU_GndRigView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView construction/destruction

CSIPU_SDU_GndRigView::CSIPU_SDU_GndRigView()
{
	// TODO: add construction code here

}

CSIPU_SDU_GndRigView::~CSIPU_SDU_GndRigView()
{
}

BOOL CSIPU_SDU_GndRigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView drawing

void CSIPU_SDU_GndRigView::OnDraw(CDC* pDC)
{
	CSIPU_SDU_GndRigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView printing

BOOL CSIPU_SDU_GndRigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSIPU_SDU_GndRigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSIPU_SDU_GndRigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView diagnostics

#ifdef _DEBUG
void CSIPU_SDU_GndRigView::AssertValid() const
{
	CView::AssertValid();
}

void CSIPU_SDU_GndRigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSIPU_SDU_GndRigDoc* CSIPU_SDU_GndRigView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSIPU_SDU_GndRigDoc)));
	return (CSIPU_SDU_GndRigDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigView message handlers
