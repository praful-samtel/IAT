/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	helper.h          		        		                  *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	25th May 2011							                  *
* Version of file :	V1.00						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*			 CListCtrlPrintJob(CListCtrl *pCtrl, BOOL bPrintToDefaultPrinter);*
*					CDialog	*CreatePrintDialog();                             *
*                   void OnPrint();                                           *
*                   CListCtrlHeaderPage(GPrintJob *pJob);                     *
*                   BOOL Print();                                             *
*CListCtrlDataPage(GPrintJob *pJob, CListCtrl *pCtrl, int firstCol, int lastCol);*
*               	BOOL Print();                                             *
*               	void StartPage();                                         *
*               	void DefineColHeadings();                                 *
*               	void CreatePrintFonts();                                  *
*               	void InitPrintMetrics();                                  *
*               	void PrintColHeadings(UINT nFormat, UINT nEffects=0);     *
*               	void PrintHeader();                                       *
*               	void PrintFooter();                                       *
*                                                                             *
*					public member variables:-      			                  *
*					None                                                      *
******************************************************************************/

#ifndef __SOME_HELPER__H__
#define __SOME_HELPER__H__

#include "gfx_printjob.h"

BOOL SortListCtrl(CListCtrl *pCtrl, int nCol, BOOL bAscending, int low = 0, int high = -1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CListCtrlPrintJob
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CListCtrlPrintJob : public GPrintJob
{
public:
	CListCtrlPrintJob(CListCtrl *pCtrl, BOOL bPrintToDefaultPrinter);
	virtual ~CListCtrlPrintJob();
   
	CDialog		*CreatePrintDialog();
	void		OnPrint();

protected:
	CListCtrl	*m_pListCtrl;
	int			m_ColCount;
	BOOL		m_bPrintToDefault;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CListCtrlHeaderPage
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CListCtrlHeaderPage : public GPrintUnit
{
public:
   CListCtrlHeaderPage(GPrintJob *pJob);
   virtual ~CListCtrlHeaderPage();

   BOOL		Print();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CListCtrlDataPage
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CListCtrlDataPage : public GPrintUnit
{
public:
	CListCtrlDataPage(GPrintJob *pJob, CListCtrl *pCtrl, int firstCol, int lastCol);
	virtual ~CListCtrlDataPage();

	BOOL		Print();
	void		StartPage();
	void		DefineColHeadings();
	void		CreatePrintFonts();
	void		InitPrintMetrics();
	void		PrintColHeadings(UINT nFormat, UINT nEffects=0);

	void		PrintHeader();
	void		PrintFooter();

protected:
	PUFONTPAIR		m_fontPairBody;
	CFont			m_fontHeading;
	CFont			m_fontHeader;
	CFont			m_fontFooter;
	int				m_firstCol,
					m_lastCol;
	CListCtrl		*m_pListCtrl;
};


#endif
