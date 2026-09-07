/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	unit_table1.h	             				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					void DefineColHeadings();                                 *
*					void CreatePrintFonts();                                  *
*					void InitPrintMetrics();                                  *
*					void PrintHeader();                                       *
*					void PrintFooter();                                       *
*					BOOL Print();                                             *
*                                                                             *
*					public member variables:-      			                  *
*					CToolTipCtrl m_Tooltip;                                   *
******************************************************************************/
#include "gfx_printunit.h"


class Table1Unit : public GPrintUnit
{
public:
   Table1Unit(GPrintJob *pJob);
   virtual ~Table1Unit();

   void DefineColHeadings();
   void CreatePrintFonts();
   void InitPrintMetrics();

   void PrintHeader();
   void PrintFooter();

   BOOL Print();

protected:
   PUFONTPAIR m_fontPairBody;
   CFont m_fontHeading;

   CFont m_fontHeader;
   CFont m_fontFooter;
};

