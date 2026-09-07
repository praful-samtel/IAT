/************************************************************************************************
*	Project Name		:	ILT																	*
*	File Name			:   unit_indexpage.cpp            										*
*	Author				:	Chaman Lal Sharma												    *
*	Date				:	19th July.2011														*
*	Version of file		:	V1.01																*
*	Description 		:	This file consists of the following declarations:                   *
*							void IndexUnit::InitPrintMetrics()  								*
*							BOOL IndexUnit::Print()                         					*
*************************************************************************************************/

#include "stdafx.h"
#include "gfx_printjob.h"
#include "unit_indexpage.h"

IndexUnit::IndexUnit(GPrintJob *pJob) : GPrintUnit(pJob)
{
   m_pTree = new GPrintIndexTree();
}

IndexUnit::~IndexUnit()
{
   delete m_pTree;
}

/*******************************************************************************
*  Function Name    = InitPrintMetrics()				                       *
*  Class            = IndexUnit              	                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used for formatting of index page.	   * 
********************************************************************************/
void IndexUnit::InitPrintMetrics()
{
   TEXTMETRIC tm;
   JDC.GetTextMetrics(&tm);

   GMAKESTNUL(m_pum);
   m_pum.pumLineOfText = tm.tmHeight;

   RealizeMetrics();
}

/*******************************************************************************
*  Function Name    = Print()              				                       *
*  Class            = IndexUnit              	                               *
*  Return Type      = BOOL                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is sued to display title of Index page     * 
********************************************************************************/
BOOL IndexUnit::Print()
{
   GPrintUnit::Print();

   StartPage();

   // add a title to the page
   CString strLine;
   strLine.Format("%cIndex\n", HFC_CENTER);
   PrintTextLine(strLine);

   PrintTree(m_pTree);
   EndPage();

   return TRUE;
}
