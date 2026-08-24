/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	unitheaderpage.h             				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					HeaderPage(GPrintJob *pJob);                              *
*					virtual ~HeaderPage();                                    *
*					BOOL Print();                                             *
*                                                                             *
*					public member variables:-      			                  *
*					None                                                      *
******************************************************************************/

#include "gfx_printunit.h"



class HeaderPage : public GPrintUnit
{
public:
   
   HeaderPage(GPrintJob *pJob);
   virtual ~HeaderPage();

   BOOL Print();
};

