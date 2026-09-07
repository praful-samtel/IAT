// FormEmpty.cpp : implementation file
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "FormEmpty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormEmpty

IMPLEMENT_DYNCREATE(CFormEmpty, CFormView)

CFormEmpty::CFormEmpty()
	: CFormView(CFormEmpty::IDD)
{
	//{{AFX_DATA_INIT(CFormEmpty)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFormEmpty::~CFormEmpty()
{
}

void CFormEmpty::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormEmpty)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormEmpty, CFormView)
	//{{AFX_MSG_MAP(CFormEmpty)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormEmpty diagnostics

#ifdef _DEBUG
void CFormEmpty::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormEmpty::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormEmpty message handlers
