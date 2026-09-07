/**************************************************************************************
*		Project Name	:	Universal Tester													 	  * 							       
*		File Name		:   CaptionView.cpp										      *								   
*		Author			:	Chaman Lal Sharma										  *		                           
*		Date			:	25th May.2011											  *			                       
*		Version of file	:	V1.00													  *			                       
*		Description 	:	This file consists of the following declarations:         *                                  
*																					  *
*								CCaptionView::CCaptionView() : m_pCaption(NULL),      *
*									m_pCtrl(NULL)									  *
*								CCaptionView::~CCaptionView()						  *												                                           
*								void CCaptionView::Dump(CDumpContext& dc) const		  *
*								void CCaptionView::AssertValid() const			      *
*								BOOL CCaptionView::OnChildNotify( UINT message,       *
*									WPARAM wParam, LPARAM lParam, LRESULT* pLResult ) * 
*								int CCaptionView::								      *
*									OnCreate(LPCREATESTRUCT lpCreateStruct)			  *
*								void CCaptionView::OnSize(UINT nType, int cx, int cy) *
*								LRESULT CCaptionView::DefWindowProc(UINT message,     * 
*									WPARAM wParam, LPARAM lParam)					  *
*								void CCaptionView::OnPaint()						  *
*								BOOL CCaptionView::OnEraseBkgnd(CDC* pDC)		      *
*								void CCaptionView::OnDraw(CDC* pDC)				      *
**************************************************************************************/

#include "stdafx.h"
#include "CaptionView.h"
#include "CaptionBar.h"

#include "AfxPriv.h"
//#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//**************************************************************************
// CCaptionView
//***************************************************************************
IMPLEMENT_DYNCREATE(CCaptionView, CView)


//***************************************************************************
//***************************************************************************
BEGIN_MESSAGE_MAP(CCaptionView, CView)
	//{{AFX_MSG_MAP(CCaptionView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
END_MESSAGE_MAP()


//***************************************************************************
// CCaptionView construction/destruction
//***************************************************************************
CCaptionView::CCaptionView() : 
m_pCaption(NULL),
m_pCtrl(NULL)
{
	//
	// The default constructor should never be called!
	//
	ASSERT( FALSE );

}

//***************************************************************************
//***************************************************************************
//  Derived classed pass in the RTTI of the window.
//***************************************************************************
CCaptionView::CCaptionView( CRuntimeClass* prtti ) :
m_pCaption(NULL),
m_pCtrl(NULL)
{
	m_pCaption = new (CCaptionBar);
	ASSERT_VALID( m_pCaption );

	m_pCtrl = STATIC_DOWNCAST( CWnd,  prtti->CreateObject() );
	ASSERT_VALID( m_pCtrl );
}


//***************************************************************************
//***************************************************************************
CCaptionView::~CCaptionView()
{
	if( m_pCaption )
	{
		delete m_pCaption;
		m_pCaption = NULL;
	}
}


//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = PreCreateWindow()										 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = CREATESTRUCT& cs										 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to create pre window			 *                     							                               
*****************************************************************************/
BOOL CCaptionView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

//***************************************************************************
// CCaptionView drawing
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnDraw()											     *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDC* pDC												 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to draw caption list view		 *                     							                               
*****************************************************************************/
void CCaptionView::OnDraw(CDC* pDC)
{
	UNUSED_ALWAYS( pDC );

	// TODO: add draw code for native data here
}


//***************************************************************************
//
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnCreate()											 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = int                                                    *                       
*  Parameters       = LPCREATESTRUCT lpCreateStruct                          *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to create of caption			 *                      							                               
*****************************************************************************/

int CCaptionView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	int nResult = 0;

	nResult = CView::OnCreate(lpCreateStruct);

	if( -1 == nResult )
		return nResult;

	nResult = m_pCaption->Create( NULL, 
							    WS_VISIBLE 
							   |WS_CHILD 
							   |BS_OWNERDRAW, 
							    CRect(0,0,0,0), 
							    this, 
								1 );

	if( -1 == nResult )
	{
		TRACE0(_T("FAILED TO CREATE CAPTION-BAR WINDOW!\n"));
		return nResult;
	}

	nResult = m_pCtrl->Create( NULL, 
				               NULL, 
							   WS_CHILD,
							   CRect(0,0,0,0), 
							   this, 
							   2 );

	m_pCtrl->SetOwner( this );
	m_pCaption->SetOwner( this );

	if( -1 == nResult )
	{
		TRACE0(_T("FAILED TO CREATE CUSTOM CONTROL WINDOW!\n"));
		return nResult;
	}

    return nResult;
}


//***************************************************************************
//
//***************************************************************************

/*****************************************************************************
*  Function Name    = OnSize()											     *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = UINT nType, int cx, int cyt                            *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to check the size    			 *                      							                               
*****************************************************************************/
void CCaptionView::OnSize(UINT nType, int cx, int cy) 
{
	//
	//  1 - Make sure windows are valid...
	//
	ASSERT( IsWindow( m_pCaption->GetSafeHwnd() ) );
	ASSERT( IsWindow( m_pCtrl->GetSafeHwnd()  ) );

	CRect rectCaption;
	m_pCaption->GetClientRect( rectCaption );

	HDWP dwp = BeginDeferWindowPos( 2 ); // number of windows

	if( NULL != dwp )
	{
		dwp = DeferWindowPos(  dwp,
							   m_pCaption->GetSafeHwnd(),
							   HWND_BOTTOM,
							   0,
							   0,
							   cx,
							   rectCaption.bottom,
							   SWP_NOZORDER );

		dwp = DeferWindowPos(  dwp,
							   m_pCtrl->GetSafeHwnd(),
							   HWND_BOTTOM,
							   0,
							   rectCaption.bottom,
							   cx,
							   cy - rectCaption.bottom,
							   SWP_NOZORDER );

		VERIFY
		( 
			EndDeferWindowPos( dwp ) 
		);
	}

	CView::OnSize(nType, cx, cy);
}


//***************************************************************************
//
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnEraseBkgnd()										 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = CDC* pDC												 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to erase the background			 *                       							                               
*****************************************************************************/

BOOL CCaptionView::OnEraseBkgnd(CDC* pDC) 
{
	UNUSED_ALWAYS(pDC);

	return TRUE;
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = DefWindowProc()										 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = LRESULT                                                *                       
*  Parameters       = UINT message, WPARAM wParam, LPARAM lParam			 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to define the window parameter   *                       							                               
*****************************************************************************/
 
LRESULT CCaptionView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	LRESULT lResult = 0;

	switch( message )
	{
	case WM_NOTIFY :
		{
			NMHDR*	pNMHDR = (NMHDR*)lParam;
			int		nCode  = pNMHDR->code;

			AFX_NOTIFY notify;

			notify.pResult = &lResult;
			notify.pNMHDR  = pNMHDR;

			CWnd::OnCmdMsg( 0, 
				            MAKELONG(nCode, WM_REFLECT_BASE+WM_NOTIFY), 
							&notify, 
							NULL );
		}
		break;

	case WM_SETTEXT :
		{
			lResult = m_pCaption->SendMessage( message, wParam, lParam );
		}
		break;

	case WM_SETICON :
		{
			lResult = m_pCaption->SendMessage( message, wParam, lParam );
		}

	default : 
		
		lResult = CView::DefWindowProc(message, wParam, lParam);

		break;
	}
	
	return lResult;
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnPaint()											     *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None													 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to Paint the caption view		 *                     							                               
*****************************************************************************/
void CCaptionView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rectClient;
	GetClientRect( rectClient );

	dc.FillSolidRect( rectClient, GetSysColor(COLOR_APPWORKSPACE) );
	
	// Do not call CView::OnPaint() for painting messages
}


//***************************************************************************
// CCaptionView diagnostics
//***************************************************************************
#ifdef _DEBUG
/*****************************************************************************
*  Function Name    = AssertValid()											 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None													 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to Assert the valdity			 *                      							                               
*****************************************************************************/
void CCaptionView::AssertValid() const
{
	CView::AssertValid();
}
#endif //_DEBUG

//***************************************************************************
//***************************************************************************
#ifdef _DEBUG
/*****************************************************************************
*  Function Name    = Dump()											     *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDumpContext& dc										 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to dump the caption view		 *                     							                               
*****************************************************************************/
void CCaptionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

