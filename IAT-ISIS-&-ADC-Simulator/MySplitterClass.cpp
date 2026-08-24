// MySplitterClass.cpp: implementation of the MySplitterClass class.
//

#include "stdafx.h"
#include "MySplitterClass.h"
#include "CaptionListView.h"
//#include "RightView.h"
#include "SIPU_SDU_GndRig.h"

/////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(MySplitterClass, CSplitterWnd)
	//{{AFX_MSG_MAP(MyCView)
	ON_WM_SIZE()
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()



MySplitterClass::MySplitterClass()
{

}

MySplitterClass::~MySplitterClass()
{

}

void MySplitterClass::OnDrawSplitter( CDC* pDC, 
											  ESplitType nType, 
											  const CRect& rect )
{
	CSplitterWnd::OnDrawSplitter( pDC, nType, rect );

	if ( nType == splitBar )
	{
		/*static DWORD c =0;
		TRACE1("splitbar drawing %d\n",c++);*/		

		CCaptionListView* pCLV = (CCaptionListView*)GetPane(1,0);
		CWnd* pTmp = pCLV->GetClientArea();
		CRect rt;
		pTmp->GetClientRect(rt);								
		((CSIPU_SDU_GndRigApp *)AfxGetApp())->ClientCEdit.MoveWindow(rt,TRUE);

		if( ((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd != NULL)
		{

			pCLV = (CCaptionListView*)GetPane(0,0);
			pTmp = pCLV->GetClientArea();		
			pTmp->GetClientRect(rt);								

			/*int xMain = rt.Width();
		    int yMain = rt.Height();

			CRect rectView;
			((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->GetWindowRect(&rectView);
			int xView = rectView.Width();
			int yView = rectView.Height();

			int x = (xMain - xView) / 2;
		    int y = (yMain - yView) / 2;*/

			if(IsWindow(((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->m_hWnd))
			((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->MoveWindow(rt,TRUE);
			//((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->MoveWindow(x, y, xView, yView, TRUE);		

		}
	}
	
}


