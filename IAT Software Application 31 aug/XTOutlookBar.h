
//////////////////////////////////////////////////////////////////////

#if !defined(__XTOUTLOOKBAR_H__)
#define __XTOUTLOOKBAR_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxtempl.h>

////////////////////////////////////////////////////////////////////////////
// XT_CONTENT_ITEM

struct XT_CONTENT_ITEM
{
	HICON   m_hIcon;   // Icon handle for menu item.
    int     m_nIndex;  // Zero based index for menu item.
    CString m_strText; // Text label for menu item.
};

/////////////////////////////////////////////////////////////////////////////
// CCXTOutlookBar is a CListBox derived class that implements a Outlook Bar 
// style control, can only be used with the LBS_OWNERDRAWVARIABLE style bit set.

class CXTOutlookBar : public CListBox
{
    DECLARE_DYNAMIC(CXTOutlookBar)

public:

    // -> Remarks:  Constructs a CXTOutlookBar object.
    CXTOutlookBar();

    // -> Remarks:  Destroys a CXTOutlookBar object, handles cleanup and de-allocation.
    virtual ~CXTOutlookBar();

protected:

	int        m_cxIcon;         // width of menu icon.
	int        m_cyIcon;         // height of menu icon.
    int        m_nIndex;         // currently selected menu index
    bool       m_bHilight;       // true when menu item is selected
    bool       m_bLBDown;        // true when left mouse button is pressed
    CPoint     m_point;          // holds the cursor position
    COLORREF   m_clrBack;        // backgound color
    COLORREF   m_clrText;        // text color

	CList<XT_CONTENT_ITEM*,XT_CONTENT_ITEM*> m_arContentItems;

public:

	// -> Input:   dwStyle    - Specifies the window style attributes.
	//             rect       - The size and position of the window, in client coordinates of 
	//                          pParentWnd.
	//             pParentWnd - The parent window.
	//             nID        - The ID of the child window.
	// -> Returns: Nonzero if successful; otherwise 0.
	// -> Remarks: Creates an Outlook Bar control.
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

    // -> Input:   clrText - COLORREF value for text
    //             clrBack - COLORREF value for the background
    // -> Remarks: Call this member function to set the text and background colors for
    //             the outlook bar.
    void SetColors(COLORREF clrText, COLORREF clrBack);

	// -> Input:   iIndex   - Specifies the zero-based index of the position to insert the
	//                        menu item. If this parameter is –1, the menu item is added to 
	//                        the end of the list.
	//             nIconID  - Resource id of the icon associated with this menu item.
	//             lpszText - Points to the null-terminated string for the menu item.
	// -> Returns: The zero-based index of the position at which the menu item was inserted.
	//             The return value is LB_ERR if an error occurs; the return value is 
	//             LB_ERRSPACE if insufficient space is available to store the new menu item.
	// -> Remarks: Inserts a menu item into the outlook bar. Unlike the AddMenuItem member
	//             function, InsertMenuItem does not cause a outlook bar with the LBS_SORT 
	//             style to be sorted.
	int InsertMenuItem(int iIndex, UINT nIconID, LPCTSTR lpszText);

	// -> Input:   nIconID  - Resource id of the icon associated with this menu item.
	//             lpszText - Points to the null-terminated string for the menu item.
	// -> Returns: The zero-based index to the menu item in the outlook bar. The return 
	//             value is LB_ERR if an error occurs; the return value is LB_ERRSPACE if 
	//             insufficient space is available to store the new menu item.
	// -> Remarks: Call this member function to add a menu item to a outlook bar. If the 
	//             outlook bar was not created with the LBS_SORT style, the menu item is 
	//             added to the end of the outlook bar. Otherwise, the menu item is inserted
	//             into the outlook bar, and the outlook bar is sorted. If the outlook bar 
	//             was created with the LBS_SORT style but not the LBS_HASSTRINGS style, the
	//             framework sorts the outlook bar by one or more calls to the CompareItem 
	//             member function.  Use InsertMenuItem to insert a menu item into a specific
	//             location within the outlook bar.
	int AddMenuItem(UINT nIconID, LPCTSTR lpszText);

	// -> Input:   iItem - Specifies the zero-based index of the menu item to retrieve.
	// -> Returns: A XT_CONTENT_ITEM pointer.
	// -> Remarks: Call this member function to return a XT_CONTENT_ITEM object that 
	//             represents the menu item specified by iItem.
	XT_CONTENT_ITEM* GetMenuItem(int iItem);

    //{{AFX_VIRTUAL(CXTOutlookBar)
    public:
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
    //}}AFX_VIRTUAL

protected:

	// -> Input:   pDC - Points to the current device context.
	// -> Remarks: This member function is called by the control to for flicker
	//             free drawing.
	void OnNoFlickerPaint(CDC* pDC);

    //{{AFX_MSG(CXTOutlookBar)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnWindowPosChanged(WINDOWPOS FAR* lpwndpos);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////

AFX_INLINE void CXTOutlookBar::SetColors(COLORREF clrText, COLORREF clrBack) {
    m_clrBack = clrBack; m_clrText = clrText;
}

/////////////////////////////////////////////////////////////////////////////

#define XTWM_OUTBAR_NOTIFY		(WM_USER+1019)

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // #if !defined(__XTOUTLOOKBAR_H__)

