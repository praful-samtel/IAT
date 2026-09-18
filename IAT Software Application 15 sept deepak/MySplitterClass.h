// MySplitterClass.h: interface for the MySplitterClass class.
//
/////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSPLITTERCLASS_H__14AE2BB5_98B1_4C5D_A592_F0FDA10AEEA3__INCLUDED_)
#define AFX_MYSPLITTERCLASS_H__14AE2BB5_98B1_4C5D_A592_F0FDA10AEEA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class MySplitterClass  : public CSplitterWnd
{
public:
	MySplitterClass();
	virtual ~MySplitterClass();

	virtual void OnDrawSplitter( CDC* pDC, ESplitType nType, const CRect& rect );

protected:
	void OnSize(UINT i, int cx,int cy)
	{
		CSplitterWnd::OnSize(i,cx,cy);

	}

	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_MYSPLITTERCLASS_H__14AE2BB5_98B1_4C5D_A592_F0FDA10AEEA3__INCLUDED_)
