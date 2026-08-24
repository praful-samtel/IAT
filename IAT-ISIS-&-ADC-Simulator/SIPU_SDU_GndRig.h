/******************************************************************************
* Project Name	  :	ILT						    		                      *
* File Name		  :	SIPU_SDU_GndRig.h                				          *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
             *
*               	void OnTerminateTestSeq();                                *

*               	void OnPrintRepFromFile();                                *
*	                CSIPU_SDU_GndRigApp();                                    *
*                   virtual BOOL InitInstance();                              *
*               	virtual BOOL OnIdle(LONG lCount);                         *
*                	virtual int ExitInstance();                               *
*                   afx_msg void OnAppAbout();                                *
*                   void SerialComCmd();                                      *
*                                                                             *
*					public member variables:-      			                  *
*					CRichEditCtrl ClientCEdit;                                *	
*                	CWnd *m_pDynamicViewWnd;	                              *
*               	CBrush ManualModeBrush;                                   *
*               	CBrush AutoModeBrush;                                     *
*                	CBrush SelfTestBrush;                                     *
*               	CBrush SplashBrush;                                       *
*                	CBrush StaticBrush;                                       *
*               	CFont Viewfont;                                           *
*                	NUMBER_OF_USERS	m_NumberOfUsers;                          *
*	                BOOL bDPAdminFlag;                                        *
*                 	BOOL m_bTestStopFlag;                                     *
*                	BOOL m_bTestAbortFlag;                                    *
*				   CString m_strReadSWVersion55;                              *	
*                	CString m_strReadBSIM_Checksum55;                         *
*               	CString m_strReadBLGM_Checksum55;                         *
*               	CString m_strReadPSGM_Checksum55;                         *
*                	CString m_strReadVSPM_VID_Size55;                         *
*               	CString m_strReadVSPM_CTRL_Size55;                        *
*                	CString m_strReadSWVersion66;                             *
*               	CString m_strReadBSIM_Checksum66;                         *
*               	CString m_strReadBLGM_Checksum66;                         *
*                	CString m_strReadPSGM_Checksum66;                         *
*	                CString m_strReadVSPM_VID_Size66;                         *
*                 	CString m_strReadVSPM_CTRL_Size66;                        *
*                	unsigned char uc_ViewBackFlag;                            *
******************************************************************************/
// SIPU_SDU_GndRig.h : main header file for the SIPU_SDU_GNDRIG application
//

#if !defined(AFX_SIPU_SDU_GNDRIG_H__7585BD8B_3D0F_4204_81DC_C332455F06CA__INCLUDED_)
#define AFX_SIPU_SDU_GNDRIG_H__7585BD8B_3D0F_4204_81DC_C332455F06CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "MySplitterClass.h"
#include "Structures.h"
#include "MessageBox_Dlg.h"
#include "bdaqctrl.h"
using namespace Automation::BDaq;
#define WM_CUSTOME_CFG_CHGED   (WM_USER + 0x1001) 
// CConfigureForm dialog

typedef struct tagDevConfParam
{
	int         deviceNumber;				 
	int			channelCount;				
	int			channelStart;			
	int			vrgType;
}DevConfParam, *pDevConfParam;

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigApp:
// See SIPU_SDU_GndRig.cpp for the implementation of this class
//
#define BACKGROUND_COLOR RGB(0xbf,0xdf,0xfa)
#define BACKGROUND_WARN RGB(0x00,0x00,0x00)

class CSIPU_SDU_GndRigApp : public CWinApp
{
public:
	
	InstantDoCtrl *      m_instantDoCtrl;
	InstantAiCtrl *     m_instantAiCtrl;
    DevConfParam         m_confParam; // the device's configure information from config form.
   // CConfigurationDlg	   m_confDlg;
	int   m_portNum0;
	BOOL InitializePCI_Board();

	void ConfigureDevice();
	void CheckError(ErrorCode errorCode);
	BOOL InitializeARINC429Hardware();
	BOOL InitializePowerSupplyPort();
	void OnTerminateTestSeq();
	void OnPrintRepFromFile();
	CSIPU_SDU_GndRigApp();
	 
//	MySplitterClass		RightViewSplitter;
	//CNeuListCtrl		DynListCtrl;
	//CListCtrl			DynListCtrl;

	CRichEditCtrl		ClientCEdit;	
	CWnd				*m_pDynamicViewWnd;	
	CBrush				ManualModeBrush;
	CBrush				AutoModeBrush;
	CBrush				SelfTestBrush;
	CBrush				SplashBrush;
	CBrush				StaticBrush;
	CFont				Viewfont;
	USER_DETAILS		m_UserDetails[10];	
	NUMBER_OF_USERS		m_NumberOfUsers;
	BOOL				bDPAdminFlag;
	BOOL m_bTestStopFlag;
	BOOL m_bTestAbortFlag;
	
	unsigned char ucMFD_CommWriteArray[18];
	unsigned char ucMFD_CommReadArray[70];


	
	CString				m_strLogin_UserName;
	unsigned char ucIOBRDComWriteArray[10];
	unsigned char ucIOBRDComReadArray[10];
	unsigned char uc_ViewBackFlag;
	//Global File name for report logging
	//Manual Mode	
	char				MMemTstRpt[_MAX_PATH];
	char				MInterFaceTstRpt[_MAX_PATH];
	char				MAnlgInpTstRpt[_MAX_PATH];
	char				MFrqInpTstRpt[_MAX_PATH];	
	char				MDesInpTstRpt[_MAX_PATH];	
	char				MIntrInptRpt[_MAX_PATH];	
	char				MSDUTstRpt[_MAX_PATH];

	/* for SIPU Auto mode report */
	char				ASIPUTstRpt[_MAX_PATH];
	char				SDUTstRpt[_MAX_PATH];
	char				SDUViewRpt[_MAX_PATH];
	char				ViewARINCRpt[_MAX_PATH];
	char				str_dataPathWTC[_MAX_PATH];
	
		/*ARINC 4299*/
/*	unsigned short us_NoofBrds;
	unsigned long  ul_DP4299DevHandle;
	unsigned char  ucActiveBrd,ucModeType;
	char c_ErrorMsg[80];
	bool bIntEnDis[49];
	bool bNotFound;

	struct TxWordLength
	{
		unsigned char WLength:1;
	}TxNo[9];

	unsigned short usTxConfigFlag[9];
	unsigned short usRxConfigFlag[9];*/
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIPU_SDU_GndRigApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual int ExitInstance();

	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSIPU_SDU_GndRigApp)
	afx_msg void OnAppAbout();
	// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	void SwitchOFFPowerSupply(void);
};
void SerialComCmd();

#ifdef ENABLE_THREAD
UINT App_IntHandler(LPVOID lpParam);
#endif
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIPU_SDU_GNDRIG_H__7585BD8B_3D0F_4204_81DC_C332455F06CA__INCLUDED_)
