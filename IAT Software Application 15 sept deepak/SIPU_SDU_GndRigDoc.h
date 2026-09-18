/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	SIPU_SDU_GndRigDoc.h          				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					virtual BOOL OnNewDocument();                             *
*					virtual void Serialize(CArchive& ar);                     *
*					virtual ~CSIPU_SDU_GndRigDoc();                           *
*					virtual void AssertValid() const                          *
*					virtual void Dump(CDumpContext& dc) const;                *
*                                                                             *
*					public member variables:-      			                  *
*					None                                                      *
******************************************************************************/
// SIPU_SDU_GndRigDoc.h : interface of the CSIPU_SDU_GndRigDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIPU_SDU_GNDRIGDOC_H__00A6CE96_3A76_44B7_BEEF_B571F4274E64__INCLUDED_)
#define AFX_SIPU_SDU_GNDRIGDOC_H__00A6CE96_3A76_44B7_BEEF_B571F4274E64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSIPU_SDU_GndRigDoc : public CDocument
{
protected: // create from serialization only
	CSIPU_SDU_GndRigDoc();
	DECLARE_DYNCREATE(CSIPU_SDU_GndRigDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIPU_SDU_GndRigDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSIPU_SDU_GndRigDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSIPU_SDU_GndRigDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIPU_SDU_GNDRIGDOC_H__00A6CE96_3A76_44B7_BEEF_B571F4274E64__INCLUDED_)
