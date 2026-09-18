/*************************************************************************************
*		Project Name	:	Universal Tester														 * 							       
*		File Name		:   CaptionBar.cpp											 *								   
*		Author			:	Chaman Lal Sharma										 *		                           
*		Date			:	25th May.2011											 *			                       
*		Version of file	:	V1.00													 *			                       
*		Description 	:	This file consists of the following declarations:        *                                  
*																					 *
*								CCaptionBar::CCaptionBar()							 *
*								CCaptionBar::~CCaptionBar()							 *												                                           
*								BOOL CCaptionBar::Create( LPCTSTR lpszCaption,		 *
*									DWORD dwStyle, const RECT& rect,				 *
*									CWnd* pParentWnd, UINT nID )					 *
*								BOOL CCaptionBar::Create( LPCTSTR lpszClassName,	 * 
*									LPCTSTR lpszWindowName, DWORD dwStyle, UINT nID, *
*									const RECT& rect, CWnd* pParentWnd,				 *
*									CCreateContext* pContext )						 *
*								LRESULT CCaptionBar::								 *
*									SetIcon( WPARAM wParam, LPARAM lParam )			 *
*								BOOL CCaptionBar::									 *
*									SetIcon( HICON hIcon, BOOL bBigIcon )			 *
*								BOOL CCaptionBar::									 *
*									SetFont( const LOGFONT& logfont, BOOL bRedraw )  *
*								int CCaptionBar::SetOptimalBarHeight( void )         *
*								void CCaptionBar::									 *
*									DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct )	 *
*								void CCaptionBar::InitBarColors( void )				 *
*								BOOL CCaptionBar::OnEraseBkgnd(CDC* pDC)			 *
*								void CCaptionBar::(UINT uFlags, LPCTSTR lpszSection) * 
*								void CCaptionBar::OnSysColorChange()				 *
*************************************************************************************/

#include "stdafx.h"
#include "CaptionBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//**************************************************************************
BEGIN_MESSAGE_MAP(CCaptionBar, CButton)
	//{{AFX_MSG_MAP(CCaptionBar)
	ON_WM_SYSCOLORCHANGE()
	ON_WM_ERASEBKGND()
	ON_WM_SETTINGCHANGE()
	ON_MESSAGE( WM_SETICON, SetIcon )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//***************************************************************************
// CCaptionBar
//***************************************************************************
CCaptionBar::CCaptionBar() :
m_hIcon(0),
m_nImageWidth(5),
m_nImageHeight(5),
m_nTextBorderLeft(10),
m_nImageBorderRight(5),
m_nTextShadowOffsetX(2),
m_nTextShadowOffsetY(2),
m_bDoFontShadow( TRUE ),
m_nMaxBarHeight(96),
m_bAutoSizeCaptionBar( TRUE )
{
	InitBarColors();

	LOGFONT lf;				// logical font structure
	::ZeroMemory( &lf, sizeof( lf ) );

	// 24 point Times bold
	lf.lfHeight			=- 16;
    lf.lfWeight 		=  FW_BOLD;
    lf.lfCharSet 		=  DEFAULT_CHARSET;
    lf.lfOutPrecision 	=  OUT_TT_PRECIS;
    lf.lfClipPrecision 	=  CLIP_DEFAULT_PRECIS;
    lf.lfQuality 		=  DEFAULT_QUALITY;
    lf.lfPitchAndFamily =  DEFAULT_PITCH | FF_DONTCARE;

	strncpy( lf.lfFaceName, _T("Arial"), LF_FACESIZE );
	
	m_font.CreateFontIndirect( &lf );

}

//***************************************************************************
//***************************************************************************
CCaptionBar::~CCaptionBar()
{
	if( m_hIcon != 0 )
		DestroyIcon( m_hIcon );
}

//***************************************************************************
//***************************************************************************

/*****************************************************************************
*  Function Name    = Create()											     *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = LPCTSTR lpszCaption, DWORD dwStyle, const RECT& rect,  *
						  CWnd* pParentWnd, UINT nID                         *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is usd to create the caption			 *                       							                               
*****************************************************************************/
BOOL CCaptionBar::Create( LPCTSTR lpszCaption, 
						  DWORD dwStyle,
						  const RECT& rect, 
						  CWnd* pParentWnd, 
						  UINT nID )
{
	dwStyle |= BS_OWNERDRAW
			|  BS_PUSHBUTTON
			|  WS_VISIBLE 
			|  WS_CHILD;

	return CCaptionBar::Create( NULL, lpszCaption, dwStyle, rect, pParentWnd, nID);
}

//***************************************************************************
//***************************************************************************

/*****************************************************************************
*  Function Name    = Create()					                             *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = LPCTSTR lpszClassName, LPCTSTR lpszWindowName,		 *
*						  DWORD dwStyle, const RECT& rect, UINT nID,		 *
*						  CWnd* pParentWnd, CCreateContext* pContext         *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is usd to create the caption according   *
*					  the requirements.										 *                         							                               
*****************************************************************************/
BOOL CCaptionBar::Create( LPCTSTR lpszClassName, 
						  LPCTSTR lpszWindowName, 
						  DWORD dwStyle, 
						  const RECT& rect, 
						  CWnd* pParentWnd, 
						  UINT nID, 
						  CCreateContext* pContext ) 
{
	UNUSED( lpszClassName );

	dwStyle |= BS_OWNERDRAW
			|  BS_PUSHBUTTON
			|  WS_VISIBLE 
			|  WS_CHILD;


	return CWnd::Create( _T("BUTTON"), 
						 lpszWindowName, 
						 dwStyle, 
						 rect, 
						 pParentWnd, 
						 nID );
}

//***************************************************************************
//***************************************************************************

/*****************************************************************************
*  Function Name    = SetIcon()						                         *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = LRESULT                                                *                       
*  Parameters       = WPARAM wParam, LPARAM lParam                           *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to set the icon	on the caption	 *                        							                               
*****************************************************************************/
LRESULT CCaptionBar::SetIcon( WPARAM wParam, LPARAM lParam )
{
	BOOL bResult = FALSE;

	bResult = SetIcon( (HICON) lParam, wParam>0 );

	Redraw();

	return bResult;
}

//***************************************************************************
//
//***************************************************************************

/*****************************************************************************
*  Function Name    = SetIcon()										         *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = HICON hIcon, BOOL bBigIcon                             *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to set the icon	on the caption	 *                      							                               
*****************************************************************************/
 
BOOL CCaptionBar::SetIcon( HICON hIcon, BOOL bBigIcon )
{
	if( m_hIcon != 0 )
		DestroyIcon( m_hIcon );

	m_hIcon = CopyIcon( hIcon );

	if( NULL == m_hIcon )
		return FALSE;

	if( bBigIcon )
		m_nImageHeight = m_nImageWidth = 32;
	else
		m_nImageHeight = m_nImageWidth = 16;

	if( m_bAutoSizeCaptionBar )
		SetOptimalBarHeight();

	return TRUE;
}

//***************************************************************************
//
// 
//
//***************************************************************************

/*****************************************************************************
*  Function Name    = SetFont()				                                 *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = const LOGFONT& logfont, BOOL bRedraw                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to set the font.				 *                       							                               
*****************************************************************************/
 
BOOL CCaptionBar::SetFont( const LOGFONT& logfont, BOOL bRedraw )
{

	BOOL bResult = FALSE;

	m_font.DeleteObject();

	bResult = m_font.CreateFontIndirect( &logfont );

	if( TRUE == bResult )
	{
		CWnd::SetFont( &m_font, bRedraw );
	}

	if( bResult && m_bAutoSizeCaptionBar )
		SetOptimalBarHeight();

	return bResult>0;
}

//***************************************************************************
//
//
//***************************************************************************

/*****************************************************************************
*  Function Name    = SetOptimalBarHeight()                                  *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = int                                                    *                       
*  Parameters       = void				                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to set the optimal bar height    *
*					  and return its value.									 *                        							                               
*****************************************************************************/
 
int CCaptionBar::SetOptimalBarHeight( void )
{
	CDC *pDC = GetDC();

	//
	//  1 - Make sure we use the proper font...
	//
	CFont *pOldFont = pDC->SelectObject( &m_font );

	//
	// 2  - Dummy string used to get text sizing...  However, this string is true!
	//
	CSize  sizeText;
	sizeText = pDC->GetTextExtent( CString(_T("Pacific Bell SUCKS!")) );

	//
	// 3 - Calculate text amd image sizes.  
	//
	int nTextSize  = min( (int)((float)sizeText.cy   *1.7f), m_nMaxBarHeight );
	int nImageSize = min( (int)((float)m_nImageHeight*1.5f), m_nMaxBarHeight );

	//
	// 4 - Use the max of the text or image size.
	//
	int nNewBarHeight = max( nTextSize, nImageSize );
	int	nOldBarHeight = GetCaptionHeight();

	//
	// 5 - Avoid unnecessary bar sizing by compairing new height and old height...
	//
	if( nNewBarHeight != nOldBarHeight )
	{
		SetCaptionHeight( nNewBarHeight );

		CRect rc;
		GetParent()->GetClientRect( rc );

		GetParent()->SendMessage( WM_SIZE,SIZE_RESTORED, 
								  MAKELPARAM(rc.Width(), rc.Height()) ); 
	}
	else
	{
		nNewBarHeight = nOldBarHeight;
	}

	//
	// 6 - Return the size of the Captiontiionbar - new or old...
	//
	return nNewBarHeight;
}


//***************************************************************************
// CCaptionBar message handlers
//***************************************************************************

/*****************************************************************************
*  Function Name    = DrawItem()			                                 *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = LPDRAWITEMSTRUCT lpDrawItemStruct                      *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to draw the item to reduce       * 
*					  flicker.												 *            							                               
*****************************************************************************/
 
void CCaptionBar::DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct ) 
{
    // 
    // Create DC object
    // 
	//  To reduce flicker...I should be using an off-screen DC.  
	//  I'll leave that as an TODO...
	CDC dc;
    dc.Attach( lpDrawItemStruct->hDC );

    CRect rectFace( &lpDrawItemStruct->rcItem );
    rectFace.DeflateRect( 2, 4 );

    dc.FillSolidRect( &lpDrawItemStruct->rcItem, m_dwColorBorder );
    dc.FillSolidRect( &rectFace, m_dwColorFace );
	
	dc.SetTextColor( m_dwColorFontFace );

	CString	strText;
	GetWindowText( strText );

	rectFace.left  += m_nTextBorderLeft;
	rectFace.right -= (m_nImageBorderRight + m_nImageWidth);

	CFont * pOldFont = dc.SelectObject( &m_font );

	if( TRUE == m_bDoFontShadow )
	{
		dc.SetBkMode( TRANSPARENT );

		CRect rectShadow( rectFace );
		dc.SetTextColor( m_dwColorFontShadow );
		rectShadow.OffsetRect( m_nTextShadowOffsetX, m_nTextShadowOffsetY );

		DrawTextEx( dc.GetSafeHdc(), 
					(LPTSTR)(LPCTSTR)strText, 
					strText.GetLength(), 
					rectShadow, 
					DT_LEFT 
				   |DT_SINGLELINE
				   |DT_VCENTER 
				   |DT_END_ELLIPSIS, 
					NULL );
	}

	dc.SetTextColor( m_dwColorFontFace );

	DrawTextEx( dc.GetSafeHdc(), 
				(LPTSTR)(LPCTSTR)strText, 
				strText.GetLength(), 
				rectFace, 
				DT_LEFT 
			   |DT_SINGLELINE
			   |DT_VCENTER 
			   |DT_END_ELLIPSIS, 
			    NULL );

	if( m_hIcon )
	{
	    CRect rectClient( &lpDrawItemStruct->rcItem );

		dc.DrawState( CPoint( rectFace.right+2, (rectClient.Height()/2)-(m_nImageHeight/2) ), 
					  CSize( rectFace.Height(), rectFace.Width() ), 
					  m_hIcon, 
					  DST_ICON 
					 |DSS_NORMAL, 
					 (CBrush*)NULL );
	}

    // 
    // Cleanup
    // 
	dc.SelectObject( pOldFont );
	dc.Detach();
}

//***************************************************************************
//***************************************************************************

/*****************************************************************************
*  Function Name    = InitBarColors()                                        *                        
*  Class            = CCaptionBar											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = void				                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This fuction is used to fill the bar colours			 *                       							                               
*****************************************************************************/
 
void CCaptionBar::InitBarColors( void )
{
	m_dwColorBorder		= ::GetSysColor( COLOR_3DFACE );
	m_dwColorFace		= ::GetSysColor( COLOR_3DSHADOW );
	m_dwColorFontFace	= ::GetSysColor( COLOR_CAPTIONTEXT );
	m_dwColorFontShadow	= ::GetSysColor( COLOR_3DDKSHADOW );
}

//***************************************************************************
//***************************************************************************

/*****************************************************************************
*  Function Name    = OnEraseBkgnd()                                         *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = Bool                                                   *                       
*  Parameters       = CDC* pDC											     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to erase the back ground		 *                       							                               
*****************************************************************************/
 
BOOL CCaptionBar::OnEraseBkgnd(CDC* pDC) 
{
	//
	// No flicker here!
	//

	return TRUE;
}

//***************************************************************************
//
//***************************************************************************


/*****************************************************************************
*  Function Name    = OnSettingChange()                                      *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = UINT uFlags, LPCTSTR lpszSection                       *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to change the setting and return *
*				  	  the value.											 *                         							                               
*****************************************************************************/
 
void CCaptionBar::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
	CButton::OnSettingChange(uFlags, lpszSection);

	if( m_bAutoSizeCaptionBar )
		SetOptimalBarHeight();

	InitBarColors();
	Redraw();

	return;
}

//***************************************************************************
//
// 
//***************************************************************************

/*****************************************************************************
*  Function Name    = OnSysColorChange()                                     *                       
*  Class            = CCaptionBar											 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None				                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to change system color           *                        							                               
*****************************************************************************/
 
void CCaptionBar::OnSysColorChange() 
{
	InitBarColors();
	Redraw();

	return;
}

