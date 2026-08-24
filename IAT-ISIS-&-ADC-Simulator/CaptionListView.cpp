/**************************************************************************************
*		Project Name	:	Universal Tester														  * 							       
*		File Name		:   CaptionListView.cpp										  *								   
*		Author			:	Chaman Lal Sharma										  *		                           
*		Date			:	25th May.2011											  *			                       
*		Version of file	:	V1.00													  *			                       
*		Description 	:	This file consists of the following declarations:         *                                  
*																					  *
*								CCaptionListView::CCaptionListView() :				  *
*									CCaptionView( RUNTIME_CLASS( CMyListView ))		  *
*								CCaptionListView::~CCaptionListView()				  *												                                           
*								void CCaptionListView::Dump(CDumpContext& dc) const   *
*								void CCaptionListView::AssertValid() const			  *
*								void CCaptionListView::OnNcDestroy()				  *
*								void CCaptionListView::RemoveImageList(int nImageList)*
*								BOOL CCaptionListView::OnChildNotify( UINT message,   *
*									WPARAM wParam, LPARAM lParam, LRESULT* pLResult ) * 
*								int CCaptionListView::								  *
*									OnCreate(LPCREATESTRUCT lpCreateStruct)			  *
*								void CCaptionListView::								  *
*									OnClick(NMHDR* pNMHDR, LRESULT* pResult)		  *
*								BOOL CCaptionListView::OnEraseBkgnd(CDC* pDC)		  *
*								void CCaptionListView::OnDraw(CDC* pDC)				  *
**************************************************************************************/

#include "stdafx.h"
#include "HlprFuncs.h"
#include "MyListView.h"
#include "CaptionView.h"
#include "CaptionListView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//**************************************************************************
// CCaptionListView
//***************************************************************************
IMPLEMENT_DYNCREATE(CCaptionListView, CCaptionView)

//***************************************************************************
//***************************************************************************
BEGIN_MESSAGE_MAP(CCaptionListView, CCaptionView)
//BEGIN_MESSAGE_MAP(CCaptionListView, CListView)
	//{{AFX_MSG_MAP(CCaptionListView)
	ON_WM_ERASEBKGND()
	//ON_NOTIFY_REFLECT_EX(NM_CLICK, OnClick)
	ON_WM_CREATE()
	//ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//***************************************************************************
//			        * * * R E A D   T H I S * * *
//***************************************************************************
//  This CCaptionView uses CMyListView for it's ListView window.
//***************************************************************************
CCaptionListView::CCaptionListView() : 
CCaptionView( RUNTIME_CLASS( CMyListView ))  
{

}

//***************************************************************************
//***************************************************************************
CCaptionListView::~CCaptionListView()
{

}

//***************************************************************************
// CCaptionListView drawing
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnDraw()											     *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDC* pDC												 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to draw caption list view		 *                      							                               
*****************************************************************************/

void CCaptionListView::OnDraw(CDC* pDC)
{
	UNUSED_ALWAYS( pDC );
}

//***************************************************************************
// CCaptionListView message handlers
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnEraseBkgnd()										 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = CDC* pDC												 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to erase the background			 *                       							                               
*****************************************************************************/
 
BOOL CCaptionListView::OnEraseBkgnd(CDC* pDC) 
{
	UNUSED_ALWAYS( pDC );
	return TRUE;
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnClick()											     *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = NMHDR* pNMHDR, LRESULT* pResult                        *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used for click						 *                      							                               
*****************************************************************************/
 
void CCaptionListView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UNUSED_ALWAYS( pNMHDR );
	*pResult = 0;
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnCreate()											 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = int                                                    *                       
*  Parameters       = LPCREATESTRUCT lpCreateStruct                          *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to create of caption			 *                      							                               
*****************************************************************************/

int CCaptionListView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CCaptionView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CClientDC dc( this );	// need a DC for GetDeviceCaps() below

	CLogFont lf;

	// 24 point Times bold
	lf.lfHeight			=- MulDiv( 12, dc.GetDeviceCaps(LOGPIXELSX), 72 );
    lf.lfWeight 		= FW_BOLD;
    lf.lfCharSet 		= DEFAULT_CHARSET;
    lf.lfOutPrecision 	= OUT_TT_PRECIS;
    lf.lfClipPrecision 	= CLIP_DEFAULT_PRECIS;
    lf.lfQuality 		= DEFAULT_QUALITY;
    lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;

	strncpy( lf.lfFaceName, _T("Arial"), LF_FACESIZE );
	GetCaptionBar()->SetFont( lf, FALSE );	

	return 0;
}
//***************************************************************************
//***************************************************************************
/*void CCaptionListView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	//m_wndSplitter.MoveWindow(-2,-2,cx+4,cy+4);
}*/
//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnChildNotify()										 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = UINT message, WPARAM wParam, LPARAM lParam,			 *
*						LRESULT* pLResult									 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used for  the notification			 *                      							                               
*****************************************************************************/
 
BOOL CCaptionListView::OnChildNotify( UINT message, 
									  WPARAM wParam, 
									  LPARAM lParam, 
									  LRESULT* pLResult ) 
{
	return CCaptionView::OnChildNotify(message, wParam, lParam, pLResult);
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = RemoveImageList()										 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = int nImageList										 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to remove the image list         *                     							                               
*****************************************************************************/
 
void CCaptionListView::RemoveImageList(int nImageList)
{
	HIMAGELIST hImageList = (HIMAGELIST) SendMessage( LVM_GETIMAGELIST,
											          (WPARAM)nImageList );

	if( NULL != CImageList::FromHandlePermanent( hImageList ) )
	{
		SendMessage( LVM_SETIMAGELIST, 
		             (WPARAM)nImageList, 
					 NULL );
	}
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = OnNcDestroy()											 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None													 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to destroy the caption			 *                      							                               
*****************************************************************************/
 
void CCaptionListView::OnNcDestroy()
{
	RemoveImageList(LVSIL_NORMAL);
	RemoveImageList(LVSIL_SMALL);
	RemoveImageList(LVSIL_STATE);

	CCaptionView::OnNcDestroy();
}


//***************************************************************************
// CCaptionListView diagnostics
//***************************************************************************
#ifdef _DEBUG
/*****************************************************************************
*  Function Name    = AssertValid()											 *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None													 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to Assert the valdity			 *                      							                               
*****************************************************************************/
 
void CCaptionListView::AssertValid() const
{
	CCaptionView::AssertValid();
}

//***************************************************************************
//***************************************************************************
/*****************************************************************************
*  Function Name    = Dump()											     *                       
*  Class            = CCaptionListView										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDumpContext& dc										 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to dump the caption view		 *                     							                               
*****************************************************************************/
void CCaptionListView::Dump(CDumpContext& dc) const
{
	CCaptionView::Dump(dc);
}
//***************************************************************************
//***************************************************************************
#endif //_DEBUG



