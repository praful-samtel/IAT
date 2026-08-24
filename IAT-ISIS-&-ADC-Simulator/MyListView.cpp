//***************************************************************************

#include "stdafx.h"

#include "MyListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//**************************************************************************
// CMyListView
//***************************************************************************
IMPLEMENT_DYNCREATE(CMyListView, CListView)

//***************************************************************************
//***************************************************************************
CMyListView::CMyListView()
{

}
//***************************************************************************
//***************************************************************************
CMyListView::~CMyListView()
{
}

//***************************************************************************
//***************************************************************************
BEGIN_MESSAGE_MAP(CMyListView, CListView)
	//{{AFX_MSG_MAP(CMyListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//***************************************************************************
// CMyListView drawing
//***************************************************************************
void CMyListView::OnDraw(CDC* pDC)
{
	UNUSED_ALWAYS( pDC );

	//CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

//***************************************************************************
// CMyListView diagnostics
//***************************************************************************
#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

//***************************************************************************
//***************************************************************************
void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG


//***************************************************************************
// CMyListView message handlers
//***************************************************************************
BOOL CMyListView::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style	 = WS_CHILD 
			     //| LVS_LIST 
			     | LVS_ICON   
		         //| WS_BORDER 
				 | WS_VISIBLE;

	return CListView::PreCreateWindow(cs);
}
