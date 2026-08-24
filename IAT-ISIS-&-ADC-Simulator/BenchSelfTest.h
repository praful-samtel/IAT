/******************************************************************************
* Project Name	  :	Universal Tester						    		                      *
* File Name		  :	BenchSelfTest.h             				              *
* Author		  :	Chaman Lal Sharma                           	          *
* Date			  :	19th July 2011							                  *
* Version of file :	V1.01						     		                  *
* Description 	  :	This File includes the declarations of the following:-    *
*                                                                             *
*                   public member functions:-		            			  *
*					void DoSelfTest_LuminanceMeter();           			  *
*					void DoSelfTest_LPB_RS422P2();           			      *
*					void DoSelfTest_LPB_RS422P1();           			      *
*					void DoSelfTest115VAC_Frequency();           			  *
*					void FSEL_Config(unsigned char ucInputType);           	  *
*					void DoSelfTest_DOP_PRES();           			          *
*					void DoSelfTest_DOP_PSMVAL();           			      *
*					void DoSelfTest_DOP_SMDOK();           			          *
*					void DoSelfTest_DIP_MODE_SELECT();           			  *
*					void DoSelfTest_DIP_P1P2();           			          *
*					void DoSelfTest_DIP_DNS();           			          *
*					void DoSelfTest_DIP_SMD_ON();           			      *
*					void DoSelfTest5VAC_Voltage();           			      *
*					void DoSelfTest115VAC_Voltage();           			      *
*					void DoSelfTest28VDC();           			              *
*					void DoSelfTestIOBoard();           			          *
*					void UpdateLED                                            *
*                        (unsigned char ucLEDTYPE, unsigned char ucON_OFF);   *
*                                                                			  *
*					public member variables:-      			                  *
*					unsigned long m_ulTimeCounter;	                          *
*					CLed	m_Led_RS422P2;           			              *
*					CLed	m_Led_RS422P1;           			              *
*					CLed	m_Led115VACFreq;           			              *
*					CLed	m_LedSMD_ON;           			                  *
*					CLed	m_LedSMD_OK;           			                  *
*					CLed	m_LedPSM_VAL;                       			  *
*					CLed	m_LedPRES;           	                 		  *
*					CLed	m_LedP1P2;                          			  *
*					CLed	m_LedMODE2;           			                  *
*					CLed	m_LedDNS;           			                  *
*					CLed	m_Led115VACPHC;           			              *
*					CLed	m_Led115VACPHB;           			              *
*					CLed	m_Led115VACPHA;           			              *
*					CLed	m_Led28VDC1;           			                  *
*					CLed	m_LedIOBoard;           			              *
*					CLed	m_LedLuminMeter;           			              *
*					CLed	m_Led5VAC_VOL;		    				          *
******************************************************************************/

#if !defined(AFX_BENCHSELFTEST_H__46A6D465_2562_4CC1_BD37_09F5C962BC31__INCLUDED_)
#define AFX_BENCHSELFTEST_H__46A6D465_2562_4CC1_BD37_09F5C962BC31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BenchSelfTest.h : header file
//#include "BDaqCtrl.h"

#include "resource.h"
using namespace Automation::BDaq;
#include "BDaqCtrl.h"
using namespace Automation::BDaq;

#include "Led.h"
#if 0
typedef struct tagDevConfParam2
{
	int deviceNumber;
}DevConfParam2, *pDevConfParam2;

 DevConfParam2  m_confParam2;
 #endif

#define WM_CUSTOME_CFG_CHGED   (WM_USER + 0x1001) 
#define WM_UPDATEMSG           (WM_USER + 0x1002)
#if 0
class CBenchSelfTest : public CDialog
{
	class CntrEventHandler:public CntrEventListener
   {
   public:
      CntrEventHandler()
      {
         eventCount = 0;
      }
      HWND m_hwnd;
      virtual void BDAQCALL CntrEvent(void * sender, CntrEventArgs * args)
      {
         ++eventCount;
         ::PostMessage(m_hwnd, WM_UPDATEMSG, eventCount, 0);
      }
   private:
      LONG eventCount;
   };


	
// Construction
public:
	void CheckError_ST(ErrorCode errorCode);
	void DoSelfTest_LuminanceMeter();
	void DoSelfTest_LPB_RS422P2();
	void DoSelfTest_LPB_RS422P1();
	void DoSelfTest115VAC_Frequency();
	void FSEL_Config(unsigned char ucInputType);
	void DoSelfTest_DOP_PRES();
	void DoSelfTest_DOP_PSMVAL();
	void DoSelfTest_DOP_SMDOK();
	void DoSelfTest_DIP_MODE_SELECT();
	void DoSelfTest_DIP_P1P2();
	void DoSelfTest_DIP_DNS();
	void DoSelfTest_DIP_SMD_ON();
	void DoSelfTest5VAC_Voltage();
	void DoSelfTest115VAC_Voltage();
	void DoSelfTest28VDC();
	void DoSelfTestIOBoard();
	unsigned long m_ulTimeCounter;
	void UpdateLED(unsigned char ucLEDTYPE, unsigned char ucON_OFF);

	CBenchSelfTest(CWnd* pParent = NULL);   // standard constructor

	void UpdateDlgCtrl(unsigned char ucPortNum, BYTE BPortVal);

	//CString m_strDlgCaption;

// Dialog Data
	//{{AFX_DATA(CBenchSelfTest)
	enum { IDD = IDD_DIALOG_BENCH_SELFTEST };
	CLed	m_Led_RS422P2;
	CLed	m_Led_RS422P1;
	CLed	m_Led115VACFreq;
	CLed	m_LedSMD_ON;
	CLed	m_LedSMD_OK;
	CLed	m_LedPSM_VAL;
	CLed	m_LedPRES;
	CLed	m_LedP1P2;
	CLed	m_LedMODE2;
	CLed	m_LedDNS;
	CLed	m_Led115VACPHC;
	CLed	m_Led115VACPHB;
	CLed	m_Led115VACPHA;
	CLed	m_Led28VDC1;
	CLed	m_LedIOBoard;
	CLed	m_LedLuminMeter;
	CLed	m_Led5VAC_VOL;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBenchSelfTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBenchSelfTest)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButSelftest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	
	
	//afx_msg void OnStnClickedStcStatus();
	
	afx_msg void OnBnClickedButResetall();
	BOOL m_chk28VDC;
	BOOL m_chk5VDC;
	BOOL m_chk5VAC;
	//BOOL m_chkDisplayTest;
	BOOL m_chkDataloadEnable;
	BOOL m_chkDayNight;
	//BOOL m_chkAutoManual;
	BOOL m_chkRs422Port1;
	BOOL m_chkRs422Port2;
	BOOL m_chkDisplayTest;
	afx_msg void OnBnClickedOk();
	BOOL m_DispValid;
	BOOL m_ChkDispValid;
	BOOL m_chkValid;
	BOOL m_chkDispValid;
	BOOL m_chkRS422Port1;
	BOOL m_chkRS422Port2;
	CString m_strMeasVolt;
	void Do28VDCTest(void);
	void Opreate28VDCPowerSupply(bool bFlagONOFF);

	
	void DoDisOutDNSTest(void);
	void DoDisOutModeTest(void);
	void DoDisOutFC_RCTest(void);
	void DoDisOutDU_STAUS_TXTest(void);
	void DoDisOutDU_STAUS_RXTest(void);
	void DoRS422P1Test(void);
	void DoRS422P2Test(void);
	void DoArinc429TX1Test(void);
	void DoArinc429TX2Test(void);
	void DoArinc429TX3Test(void);
	void DoArinc429TX4Test(void);
	void DoArinc429RX1Test(void);
	void DoArinc429RX2Test(void);

	void CPulseOutputwithTimerInterruptDlg(void);


	

	private:
		CntrEventHandler     m_eventHandler;

public:
	BOOL m_chkArincTX1;
	BOOL m_chkArincTX2;
	BOOL m_chkArincTX3;
	BOOL m_chkArincTX4;
	BOOL m_chkArincRX1;
	BOOL m_chkArincRX2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	BOOL m_chkPCIArinc429;
	BOOL m_chkPCI1622B;
	BOOL m_chkEthComm;
	BOOL m_chkPwrSupply;
};
#endif
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BENCHSELFTEST_H__46A6D465_2562_4CC1_BD37_09F5C962BC31__INCLUDED_)

/****************************************************************************************************
*		Project Name		:	Universal Tester
*		File Name	        :   BenchSelfTest.h
*		Description 		:	Header for CBenchSelfTest dialog - PCI/PCIe Card Initialization
*								Self Test for PCI-1711, PCI-1715, PCI-1733, PCIE-1758DO, PCIE-1824
*****************************************************************************************************/




// ---------------------------------------------------------------------------
// LED status constants  (matching original code convention)
// ---------------------------------------------------------------------------
#define LED_STATUS_ON       1
#define LED_STATUS_OFF      0
#define LED_STATUS_DISABLE  2

// ---------------------------------------------------------------------------
// Test index constants  (one per card, used in UpdateLED switch)
// ---------------------------------------------------------------------------
#define TEST_PCI1711        1
#define TEST_PCI1715        2
#define TEST_PCI1733        3
#define TEST_PCIE1758DO     4
#define TEST_PCIE1824       5

// ---------------------------------------------------------------------------
// Device description strings  -- change BID# if you have multiple boards
// ---------------------------------------------------------------------------
#define DEV_DESC_PCI1711        "PCI-1711,BID#0"
#define DEV_DESC_PCI1715        "PCI-1715,BID#0"
#define DEV_DESC_PCI1733        "PCI-1733,BID#0"
#define DEV_DESC_PCIE1758DO     "PCIE-1758DO,BID#0"
#define DEV_DESC_PCIE1824       "PCIE-1824,BID#0"

// ---------------------------------------------------------------------------
// Profile paths  -- set to "" to skip LoadProfile and use device defaults
// ---------------------------------------------------------------------------
#define PROFILE_PCI1711         ""
#define PROFILE_PCI1715         ""
#define PROFILE_PCI1733         ""
#define PROFILE_PCIE1758DO      ""
#define PROFILE_PCIE1824        ""

/////////////////////////////////////////////////////////////////////////////
// CBenchSelfTest dialog

class CBenchSelfTest : public CDialog
{
// Construction
public:
    CBenchSelfTest(CWnd* pParent = NULL);

// Dialog Data
    //{{AFX_DATA(CBenchSelfTest)
    enum { IDD = IDD_DIALOG_BENCH_SELFTEST };

    CLed    m_LedPCI1711;
    CLed    m_LedPCI1715;
    CLed    m_LedPCI1733;
    CLed    m_LedPCIE1758DO;
    CLed    m_LedPCIE1824;



    //}}AFX_DATA

// Overrides
    //{{AFX_VIRTUAL(CBenchSelfTest)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    //}}AFX_VIRTUAL

// Implementation
protected:

    // -----------------------------------------------------------------------
    // Per-card test functions (one per card, matching original style)
    // -----------------------------------------------------------------------
    void DoPCI1711Test(void);
    void DoPCI1715Test(void);
    void DoPCI1733Test(void);
    void DoPCIE1758DOTest(void);
    void DoPCIE1824Test(void);
	void DoPCIARINC429Test(void);
	void DoPCI1622BTest(void);
	void DoEthernetTest();
	void DoPWRSupply();

    // -----------------------------------------------------------------------
    // UI helpers  (same signatures as original)
    // -----------------------------------------------------------------------
    //void UpdateLED(unsigned char ucLEDTYPE, unsigned char ucON_OFF);

    // -----------------------------------------------------------------------
    // Shared BDaq error helper
    // -----------------------------------------------------------------------
    const char* ErrorCodeToString(ErrorCode code);
    bool        CheckBDaqError(ErrorCode code,
                               const char* context,
                               CString&    out_msg);

    //{{AFX_MSG(CBenchSelfTest)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    afx_msg void OnButSelftest();
    afx_msg void OnBnClickedButResetall();
    afx_msg void OnBnClickedOk();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
public:

	BOOL m_chkPCI1711;
	BOOL m_chkPCI1715;
	BOOL m_chkPCI1733;
	BOOL m_chkPCIE1758DO;
	BOOL m_chkPCIE1824;
	BOOL m_chkPCIArinc429;
	BOOL m_chkPCI1622B;
	BOOL m_chkEthComm;
	BOOL m_chkPwrSupply;
};


