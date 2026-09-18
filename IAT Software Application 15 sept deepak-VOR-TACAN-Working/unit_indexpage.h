/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	unit_indexpage.h             				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					IndexUnit(GPrintJob *pJob);                               *
*					virtual ~IndexUnit();                                     *
*					void InitPrintMetrics();                                  *
*					BOOL Print();                                             *
*                                                                             *
*					public member variables:-      			                  *
*					GPrintIndexTree *m_pTree;                                 *
******************************************************************************/
#include "gfx_printunit.h"

class IndexUnit : public GPrintUnit
{
public:
   IndexUnit(GPrintJob *pJob);
   virtual ~IndexUnit();

   void InitPrintMetrics();
   BOOL Print();

   GPrintIndexTree *m_pTree;
};

