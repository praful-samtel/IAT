/*************************************************************************************************
*	Project Name		:	ILT																	 *
*	File Name			:   SIPU_SDU_GndRigDoc.cpp               								 *
*	Author				:	Chaman Lal Sharma												     *
*	Date				:	19th July.2011														 *
*	Version of file		:	V1.01																 *
*	Description 		:	This file consists of the following declarations:                    *
*	BOOL OnNewDocument()																		 *
*	void Serialize(CArchive& ar)																 *
*	void AssertValid() const																	 *	
*	void Dump(CDumpContext& dc) const															 *
**************************************************************************************************/

// SIPU_SDU_GndRigDoc.cpp : implementation of the CSIPU_SDU_GndRigDoc class
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"

#include "SIPU_SDU_GndRigDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigDoc

IMPLEMENT_DYNCREATE(CSIPU_SDU_GndRigDoc, CDocument)

BEGIN_MESSAGE_MAP(CSIPU_SDU_GndRigDoc, CDocument)
	//{{AFX_MSG_MAP(CSIPU_SDU_GndRigDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigDoc construction/destruction

CSIPU_SDU_GndRigDoc::CSIPU_SDU_GndRigDoc()
{
	// TODO: add one-time construction code here

}

CSIPU_SDU_GndRigDoc::~CSIPU_SDU_GndRigDoc()
{
}

/*******************************************************************************
*  Function Name    = OnNewDocument()								           *
*  Class            = CSIPU_SDU_GndRigDoc          		                       *
*  Return Type      = BOOL                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      =														   * 
********************************************************************************/

BOOL CSIPU_SDU_GndRigDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigDoc serialization
/*******************************************************************************
*  Function Name    = erialize(CArchive& ar)						           *
*  Class            = CSIPU_SDU_GndRigDoc          		                       *
*  Return Type      = void                                                     *
*  Parameters       = CArchive& ar		                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used for serialization.				   * 
********************************************************************************/

void CSIPU_SDU_GndRigDoc::Serialize(CArchive& ar)
{

}

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigDoc diagnostics

#ifdef _DEBUG

/*******************************************************************************
*  Function Name    = AssertValid() const							           *
*  Class            = CSIPU_SDU_GndRigDoc          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used for diagnositc					   * 
********************************************************************************/

void CSIPU_SDU_GndRigDoc::AssertValid() const
{
	CDocument::AssertValid();
}

/*******************************************************************************
*  Function Name    = Dump(CDumpContext& dc) const							   *
*  Class            = CSIPU_SDU_GndRigDoc          		                       *
*  Return Type      = void                                                     *
*  Parameters       = CDumpContext& dc				                           *
*  Visibility       = Public	                                               *
*  Description      = This function is used for dignositcs					   * 
********************************************************************************/
void CSIPU_SDU_GndRigDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigDoc commands
