/*************************************************************************************
*		Project Name	:	Universal Tester														 * 							       
*		File Name		:   Cursor.cpp												 *								   
*		Author			:	Chaman Lal Sharma										 *		                           
*		Date			:	25th May.2011											 *			                       
*		Version of file	:	V1.00													 *			                       
*		Description 	:	This file consists of the following declarations:        *                                  
*																					 *
*								 BOOL Cursor :: LoadHandCursor( HCURSOR& hCursor )	 *
*************************************************************************************/

#include "Stdafx.h"
#include "Cursor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/*****************************************************************************
*  Function Name    = LoadHandCursor()										 *                       
*  Class            = CCaptionView											 *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = HCURSOR& hCursor										 *
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to retrieve cursor from  the	 *
*					  windows directory which consists of a hand pointer     *                     							                               
*****************************************************************************/
BOOL LoadHandCursor( HCURSOR& hCursor )
{
	BOOL bResult = FALSE;

    // Get the windows directory
    CString strWndDir;
    GetWindowsDirectory( strWndDir.GetBuffer(MAX_PATH), MAX_PATH );
	strWndDir.ReleaseBuffer();

    strWndDir += _T("\\winhlp32.exe");

    // This retrieves cursor #106 from winhlp32.exe, which is a hand pointer
    HMODULE hModule = LoadLibrary(strWndDir);

    if( hModule ) 
	{
        HCURSOR hHandCursor = ::LoadCursor( hModule, MAKEINTRESOURCE(106) );

        if (hHandCursor)
		{
            hCursor = CopyCursor(hHandCursor);
			bResult = TRUE;
		}
    }

    FreeLibrary(hModule);

	return bResult;
}

