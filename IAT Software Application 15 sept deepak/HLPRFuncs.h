
#if !defined(HLPRFUNCS_H_INCLUDED_)
#define HLPRFUNCS_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//**************************************************************************
struct CLogFont : public LOGFONT
{
public:
	CLogFont() { ZeroMemory( this, sizeof(LOGFONT) ); }
};

//***************************************************************************
//
//
//***************************************************************************
BOOL DrawVerticalText
( 
	CDC* pDC, 
	const CRect& rectWindow, 
	LPCSTR szcText, 
	const DWORD dwStyle 
);

//***************************************************************************
//
//
//***************************************************************************
void GradientFill
( 
	CDC* pDC, 
	const CRect& rectWindow,
	const COLORREF crFace,
	const COLORREF crShadow,
	const BOOL bHorizontal 
);

//***************************************************************************
//
//
//***************************************************************************
void GetWindowBitmap( CWnd* pWnd, CBitmap* bmpWindow );


//***************************************************************************
//
//
//***************************************************************************
BYTE TransitionColor
( 
	const BYTE bySource, 
	const BYTE byDestination, 
	const int nIndex, 
	const float nDelta 
);


#endif // HLPRFUNCS_H_INCLUDED_




