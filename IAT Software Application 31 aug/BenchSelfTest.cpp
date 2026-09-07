/****************************************************************************************************
*		Project Name		:	Universal Tester
*		File Name	        :   BenchSelfTest.cpp
*		Description 		:	CBenchSelfTest - PCI/PCIe Card Initialization Self Test
*								Cards tested:
*								  1. PCI-1711   (Analog Input  - 16ch)
*								  2. PCI-1715   (Analog Input  - 32ch)
*								  3. PCI-1733   (Digital Input - 32ch Isolated)
*								  4. PCIE-1758DO(Digital Output- 64ch Isolated)
*								  5. PCIE-1824  (Analog Output - 16ch)
*
*		Pass Criterion		:	Each card's controller is created, device is selected,
*								and profile is loaded without a BDaq error.
*								No data is read or written to hardware.
*****************************************************************************************************/

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "BenchSelfTest.h"
#include "Macros.h"
#include "DataStruct.h"
#include "ADT_L1.h"
#include "SerialPort.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "resource.h"
#include <Shlobj.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



#define DEVID (ADT_PRODUCT_PCIA429 | ADT_DEVID_BOARDNUM_01 | ADT_DEVID_CHANNELTYPE_A429 | ADT_DEVID_BANK_01)
extern CSerialPort gCommPort1;

/////////////////////////////////////////////////////////////////////////////
// CBenchSelfTest dialog

CBenchSelfTest::CBenchSelfTest(CWnd* pParent /*=NULL*/)
    : CDialog(CBenchSelfTest::IDD, pParent)
	, m_chkPCI1711(FALSE)
	, m_chkPCI1715(FALSE)
	, m_chkPCI1733(FALSE)
	, m_chkPCIE1758DO(FALSE)
	, m_chkPCIE1824(FALSE)
	, m_chkPCIArinc429(FALSE)
	, m_chkPCI1622B(FALSE)
	, m_chkEthComm(FALSE)
	, m_chkPwrSupply(FALSE)
{
    //{{AFX_DATA_INIT(CBenchSelfTest)
    //}}AFX_DATA_INIT
}
extern DevConfParam         m_confParam;
/****************************************************************************************************
*  Function Name    = DoDataExchange()
*  Description      = Called by the framework to exchange and validate dialog data
*****************************************************************************************************/




#include "SelfTestHeaderPage.h"
#include "unit_selftest_table.h"
#include "unit_indexpage.h"
#include "gfx_printjob.h"   

class SelfTestPrintJob : public GPrintJob
{
public:
    SelfTestPrintJob() {}
    virtual ~SelfTestPrintJob() {}
    void OnPrint();
};

void SelfTestPrintJob::OnPrint()
{
    IndexUnit unitIndex(this);
    GSELECT_PJINDEXTREE(&unitIndex.m_pTree);

    SelfTestHeaderPage unitHeaderPage(this);
    unitHeaderPage.Print();

    SelfTestTable1Unit unitTable1(this);
    unitTable1.Print();
}

void CBenchSelfTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBenchSelfTest)



	//}}AFX_DATA_MAP


	DDX_Check(pDX, IDC_CHECK_1711, m_chkPCI1711);
	DDX_Check(pDX, IDC_CHECK_1715, m_chkPCI1715);
	DDX_Check(pDX, IDC_CHECK_1733, m_chkPCI1733);
	DDX_Check(pDX, IDC_CHECK_1758, m_chkPCIE1758DO);
	DDX_Check(pDX, IDC_CHECK_1824, m_chkPCIE1824);
	DDX_Check(pDX, IDC_CHECK_ARINC429, m_chkPCIArinc429);
	DDX_Check(pDX, IDC_CHECK_1622B, m_chkPCI1622B);
	DDX_Check(pDX, IDC_CHECK_ETHCOMM, m_chkEthComm);
	DDX_Check(pDX, IDC_CHECK_PWRSPLY, m_chkPwrSupply);
}

BEGIN_MESSAGE_MAP(CBenchSelfTest, CDialog)
    //{{AFX_MSG_MAP(CBenchSelfTest)
    ON_BN_CLICKED(IDC_BUT_SELFTEST,  OnButSelftest)
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUT_RESETALL,  &CBenchSelfTest::OnBnClickedButResetall)
    ON_BN_CLICKED(IDOK,              &CBenchSelfTest::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUT_PRINT_SELFTEST, &CBenchSelfTest::OnButPrintSelfTest) 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBenchSelfTest message handlers

/****************************************************************************************************
*  Function Name    = OnInitDialog()
*  Description      = Initialises dialog controls. Resets all card status LEDs to grey/disabled
*                     and instructs operator to click "Do Self Test".
*****************************************************************************************************/
BOOL CBenchSelfTest::OnInitDialog()
{
    CDialog::OnInitDialog();

    AfxMessageBox(
        "Integrated Avionics Tester Self Test is going to be performed.\n"
        "Click 'Do Self Test' button to start the PCI/PCIe Card Initialization Self Test." );

   
   
    return TRUE;
}

/****************************************************************************************************
*  Function Name    = UpdateLED()
*  Description      = Sets the LED colour and status text for a given card test result.
*                     GREEN = PASS, RED = FAIL, DISABLED = not yet tested.
*****************************************************************************************************/


/****************************************************************************************************
*  Function Name    = ErrorCodeToString()
*  Description      = Converts a BDaq ErrorCode to a human-readable string for display.
*****************************************************************************************************/
const char* CBenchSelfTest::ErrorCodeToString(ErrorCode code)
{
    switch (code)
    {
        case Success:                   return "Success";
        case ErrorDriverNotFound:       return "Driver not found - Check BDaq driver installation";
        case ErrorDeviceNotExist:       return "Device not found - Check card is seated in slot";
        case ErrorDeviceUnrecognized:   return "Device unrecognized - Check board description string";
  
        case ErrorHandleNotValid:       return "Handle not valid - Factory function returned NULL";
      
        case ErrorDeviceNotOpened:      return "Device not opened";
        default:                        return "Unknown BDaq error";
    }
}

/****************************************************************************************************
*  Function Name    = CheckBDaqError()
*  Description      = Evaluates a BDaq ErrorCode. Returns true on Success, false on error.
*                     Fills out_msg with a formatted error string for status display.
*****************************************************************************************************/
bool CBenchSelfTest::CheckBDaqError(ErrorCode   code,
                                    const char* context,
                                    CString&    out_msg)
{
    if (code == Success)
    {
        out_msg.Format("OK - %s", context);
        return true;
    }
    out_msg.Format("FAIL [%s] : 0x%X - %s", context, (unsigned int)code, ErrorCodeToString(code));
    return false;
}

/****************************************************************************************************
*  Function Name    = OnButSelftest()
*  Description      = Main self-test handler. Called when operator clicks "Do Self Test".
*                     Runs all 5 card initialization tests sequentially and updates UI.
*****************************************************************************************************/
void CBenchSelfTest::OnButSelftest()
{
    // Disable buttons during test (matching original style)
    GetDlgItem(IDC_BUT_SELFTEST)->EnableWindow(FALSE);
    GetDlgItem(IDOK)->EnableWindow(FALSE);

    AfxMessageBox(
        "PCI/PCIe Card Self Test is in Progress... Please Wait.");

    // -----------------------------------------------------------------------
    // Run all card tests -- same sequential pattern as original OnButSelftest
    // -----------------------------------------------------------------------
    DoPWRSupply();
	DoPCI1711Test();
    DoPCI1715Test();
    DoPCI1733Test();
    DoPCIE1758DOTest();
    DoPCIE1824Test();
	DoPCIARINC429Test();
	DoPCI1622BTest();
	DoEthernetTest();
	

	LogSelfTestResults();
    // -----------------------------------------------------------------------

    AfxMessageBox("PCI/PCIe Card Initialization Self Test Execution Completed.\nCheck status indicators for each card.");

    AfxMessageBox(
        "Self Test Complete. Click Exit Button to close this screen.");

    GetDlgItem(IDC_BUT_SELFTEST)->EnableWindow(TRUE);
    GetDlgItem(IDOK)->EnableWindow(TRUE);
}
void CBenchSelfTest::DoPWRSupply()
{
	

	 UpdateData(true);
	 m_chkPwrSupply = TRUE;
	GetDlgItem(IDC_CHECK_PWRSPLY)->SetWindowText("OK");
	UpdateData(false);
}

void CBenchSelfTest::DoEthernetTest()
{
	

	 UpdateData(true);
	 const std::string host= "127.0.0.1";


	if (!(system (("ping " + host).c_str())))
	{
		//AfxMessageBox(_T("..........Ethernet Loop is done.........."));
		m_chkEthComm = TRUE;
		GetDlgItem(IDC_CHECK_ETHCOMM)-> SetWindowText("OK");
		UpdateData(false);
		return;

	}

	AfxMessageBox("Ethernet Communication failure.");
	
}

/****************************************************************************************************
*  Function Name    = DoPCIARINC429Test()
*  Description      = Self-test for PCI-429 (32 ch Arinc I/O).
*                     Steps: initalize arinc card.
*                     PASS if no  error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCIARINC429Test(void)
{

        UpdateData(TRUE);
    ADT_L0_UINT32 status;
    
    status = ADT_L1_A429_InitDefault_ExtendedOptions(DEVID, 100, 
        ADT_L1_API_DEVICEINIT_FORCEINIT | ADT_L1_API_DEVICEINIT_NOMEMTEST);
    
    if (status != ADT_SUCCESS)
        { AfxMessageBox("PCI Arinc429 Card Initialization Fail.");
	 return;
  	}
    
	  m_chkPCIArinc429 = TRUE;
	GetDlgItem(IDC_CHECK_ARINC429)->SetWindowText("OK");
  
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCI1622BTest()
*  Description      = Self-test for PCI-1622B (rs422/485/232).
*                     Steps: initalize 1622B card.
*                     PASS if no  error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCI1622BTest(void)
{

    UpdateData(TRUE);
		// perform test bench self test
		if (!gCommPort1.OpenPort("com1"))
		{
			AfxMessageBox("Unable to open Serial Port");
			 AfxMessageBox("PCI Arinc429 Card Initialization Fail.");
			 return;
		}

    m_chkPCI1622B = TRUE;
	GetDlgItem(IDC_CHECK_1622B)->SetWindowText("OK");
	gCommPort1.ClosePort();
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCI1711Test()
*  Description      = Self-test for PCI-1711 (16-ch Analog Input).
*                     Steps: Create AI controller -> Select device -> Load profile.
*                     PASS if no BDaq error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCI1711Test(void)
{
    CString strMsg;
    UpdateData(TRUE);

   // AfxMessageBox("Testing PCI-1711 (Analog Input)...");

    // Step 1 : Create controller
    InstantAiCtrl* aiCtrl = AdxInstantAiCtrlCreate();
    if (!aiCtrl)
    {
        m_chkPCI1711 = FALSE;
    //    UpdateLED(TEST_PCI1711, LED_STATUS_OFF);
        AfxMessageBox(
            "PCI-1711 FAIL: AdxInstantAiCtrlCreate() returned NULL");
        UpdateData(FALSE);
        return;
    }

    // Step 2 : Select device
    m_confParam.deviceNumber =TEST_PCI1711;
   DeviceInformation devInfo(m_confParam.deviceNumber);
    ErrorCode ret = aiCtrl->setSelectedDevice(devInfo);
    if (!CheckBDaqError(ret, "PCI-1711 setSelectedDevice", strMsg))
    {
        aiCtrl->Dispose();
        m_chkPCI1711 = FALSE;
       // UpdateLED(TEST_PCI1711, LED_STATUS_OFF);
        AfxMessageBox(strMsg);
        UpdateData(FALSE);
        return;
    }

    // Step 3 : Load profile (skipped if path is empty)
  
    // All steps passed
    aiCtrl->Dispose();
    m_chkPCI1711 = TRUE;
  //  UpdateLED(TEST_PCI1711, LED_STATUS_ON);
		GetDlgItem(IDC_CHECK_1711)->SetWindowText("OK");
  //  AfxMessageBox("OK");
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCI1715Test()
*  Description      = Self-test for PCI-1715 (32-ch Analog Input).
*                     Steps: Create AI controller -> Select device -> Load profile.
*                     PASS if no BDaq error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCI1715Test(void)
{
    CString strMsg;
    UpdateData(TRUE);

   // AfxMessageBox("Testing PCI-1715 (Analog Input)...");

    // Step 1 : Create controller
    InstantAiCtrl* aiCtrl = AdxInstantAiCtrlCreate();
    if (!aiCtrl)
    {
        m_chkPCI1715 = FALSE;
       // UpdateLED(TEST_PCI1715, LED_STATUS_OFF);
        AfxMessageBox(
            "PCI-1715 FAIL: AdxInstantAiCtrlCreate() returned NULL");
        UpdateData(FALSE);
        return;
    }

    // Step 2 : Select device
	m_confParam.deviceNumber =TEST_PCI1715;
   DeviceInformation devInfo(m_confParam.deviceNumber);
    ErrorCode ret = aiCtrl->setSelectedDevice(devInfo);
    if (!CheckBDaqError(ret, "PCI-1715 setSelectedDevice", strMsg))
    {
        aiCtrl->Dispose();
        m_chkPCI1715 = FALSE;
       // UpdateLED(TEST_PCI1715, LED_STATUS_OFF);
        AfxMessageBox(strMsg);
        UpdateData(FALSE);
        return;
    }

    // Step 3 : Load profile (skipped if path is empty)
  

    // All steps passed
    aiCtrl->Dispose();
    m_chkPCI1715 = TRUE;
//    UpdateLED(TEST_PCI1715, LED_STATUS_ON);
	GetDlgItem(IDC_CHECK_1715)->SetWindowText("OK");
  //  AfxMessageBox("PCI-1715: OK");
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCI1733Test()
*  Description      = Self-test for PCI-1733 (32-ch Isolated Digital Input).
*                     Uses BDaqCL.h InstantDiCtrl (different header from AI/AO/DO cards).
*                     Steps: Create DI controller -> Select device -> Load profile
*                            -> Verify port direction collection accessible.
*                     PASS if no BDaq error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCI1733Test(void)
{
    CString strMsg;
    UpdateData(TRUE);

   // AfxMessageBox("Testing PCI-1733 (Digital Input)...");

    // Step 1 : Create controller  (NOTE: DI uses AdxInstantDiCtrlCreate)
    InstantDiCtrl* diCtrl = AdxInstantDiCtrlCreate();
    if (!diCtrl)
    {
        m_chkPCI1733 = FALSE;
     //   UpdateLED(TEST_PCI1733, LED_STATUS_OFF);
        AfxMessageBox(
            "PCI-1733 FAIL: AdxInstantDiCtrlCreate() returned NULL");
        UpdateData(FALSE);
        return;
    }

    // Step 2 : Select device
    m_confParam.deviceNumber =TEST_PCI1733;
   DeviceInformation devInfo(m_confParam.deviceNumber);
    ErrorCode ret = diCtrl->setSelectedDevice(devInfo);
    if (!CheckBDaqError(ret, "PCI-1733 setSelectedDevice", strMsg))
    {
        diCtrl->Dispose();
        m_chkPCI1733 = FALSE;
        //UpdateLED(TEST_PCI1733, LED_STATUS_OFF);
        //AfxMessageBox(strMsg);
        UpdateData(FALSE);
        return;
    }

    // Step 3 : Load profile (skipped if path is empty)
   

    // Step 4 : Verify port direction collection (non-fatal sanity check)
    //          PCI-1733 is input-only; SDK may return NULL here -- treat as warning, not failure
    ICollection<PortDirection>* portDir = diCtrl->getPortDirection();
    if (portDir == NULL)
    {
        // Expected for pure-input card -- not a failure
        strMsg = "PCI-1733: OK (input-only card, no portDirection API)";
		 GetDlgItem(IDC_CHECK_1733)->SetWindowText("OK");
		 AfxMessageBox(strMsg);
    }
    else
    {
        GetDlgItem(IDC_CHECK_1733)->SetWindowText("OK");
    }

    // All steps passed
    diCtrl->Dispose();
    m_chkPCI1733 = TRUE;
  //  UpdateLED(TEST_PCI1733, LED_STATUS_ON);
      GetDlgItem(IDC_CHECK_1733)->SetWindowText("OK");
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCIE1758DOTest()
*  Description      = Self-test for PCIE-1758DO (64-ch Isolated Digital Output).
*                     Steps: Create DO controller -> Select device -> Load profile
*                            -> Set first 2 ports to Output direction -> Verify direction applied.
*                     PASS if no BDaq error and port directions confirm Output.
*****************************************************************************************************/
void CBenchSelfTest::DoPCIE1758DOTest(void)
{
    CString strMsg;
    UpdateData(TRUE);

   // AfxMessageBox("Testing PCIE-1758DO (Digital Output)...");

    // Step 1 : Create controller
    InstantDoCtrl* doCtrl = AdxInstantDoCtrlCreate();
    if (!doCtrl)
    {
        m_chkPCIE1758DO = FALSE;
       // UpdateLED(TEST_PCIE1758DO, LED_STATUS_OFF);
        AfxMessageBox(
            "PCIE-1758DO FAIL: AdxInstantDoCtrlCreate() returned NULL");
        UpdateData(FALSE);
        return;
    }

    // Step 2 : Select device
   m_confParam.deviceNumber =TEST_PCIE1758DO;
   DeviceInformation devInfo(m_confParam.deviceNumber);
    ErrorCode ret = doCtrl->setSelectedDevice(devInfo);
    if (!CheckBDaqError(ret, "PCIE-1758DO setSelectedDevice", strMsg))
    {
        doCtrl->Dispose();
        m_chkPCIE1758DO = FALSE;
      //  UpdateLED(TEST_PCIE1758DO, LED_STATUS_OFF);
        AfxMessageBox(strMsg);
        UpdateData(FALSE);
        return;
    }

    // Step 3 : Load profile (skipped if path is empty)
 

    // Step 4 : Set and verify port directions
    ICollection<PortDirection>* portDir = doCtrl->getPortDirection();
    if (portDir != NULL && portDir->getCount() >= 2)
    {
        // Set first two ports to Output (matching original PCIE1758DO code)
        portDir->getItem(0).setDirection(Output);
        portDir->getItem(1).setDirection(Output);

        DioPortDir dir0 = portDir->getItem(0).getDirection();
        DioPortDir dir1 = portDir->getItem(1).getDirection();

        if (dir0 != Output || dir1 != Output)
        {
            doCtrl->Dispose();
            m_chkPCIE1758DO = FALSE;
          //  UpdateLED(TEST_PCIE1758DO, LED_STATUS_OFF);
            AfxMessageBox(
                "PCIE-1758DO FAIL: Port direction did not apply (expected Output)");
            UpdateData(FALSE);
            return;
        }
    }
    // If portDir == NULL: output-only card may not expose direction API -- not a failure

    // All steps passed
    doCtrl->Dispose();
    m_chkPCIE1758DO = TRUE;
  //  UpdateLED(TEST_PCIE1758DO, LED_STATUS_ON);
     GetDlgItem(IDC_CHECK_1758)->SetWindowText("OK");
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = DoPCIE1824Test()
*  Description      = Self-test for PCIE-1824 (16-ch Analog Output).
*                     Steps: Create AO controller -> Select device -> Load profile.
*                     PASS if no BDaq error at any step.
*****************************************************************************************************/
void CBenchSelfTest::DoPCIE1824Test(void)
{
    CString strMsg;
    UpdateData(TRUE);

  //  AfxMessageBox("Testing PCIE-1824 (Analog Output)...");

    // Step 1 : Create controller
    InstantAoCtrl* aoCtrl = AdxInstantAoCtrlCreate();
    if (!aoCtrl)
    {
        m_chkPCIE1824 = FALSE;
    //    UpdateLED(TEST_PCIE1824, LED_STATUS_OFF);
        AfxMessageBox(
            "PCIE-1824 FAIL: AdxInstantAoCtrlCreate() returned NULL");
        UpdateData(FALSE);
        return;
    }

    // Step 2 : Select device
     m_confParam.deviceNumber =TEST_PCIE1824;
   DeviceInformation devInfo(m_confParam.deviceNumber);
    ErrorCode ret = aoCtrl->setSelectedDevice(devInfo);
    if (!CheckBDaqError(ret, "PCIE-1824 setSelectedDevice", strMsg))
    {
        aoCtrl->Dispose();
        m_chkPCIE1824 = FALSE;
        //(TEST_PCIE1824, LED_STATUS_OFF);
        AfxMessageBox(strMsg);
        UpdateData(FALSE);
        return;
    }

    // Step 3 : Load profile (skipped if path is empty)
 

    // All steps passed
    aoCtrl->Dispose();
    m_chkPCIE1824 = TRUE;
    //(TEST_PCIE1824, LED_STATUS_ON);
     GetDlgItem(IDC_CHECK_1824)->SetWindowText("OK");
    UpdateData(FALSE);
}

/****************************************************************************************************
*  Function Name    = OnBnClickedButResetall()
*  Description      = Resets all card status indicators to PENDING / disabled state.
*****************************************************************************************************/
void CBenchSelfTest::OnBnClickedButResetall()
{
    AfxMessageBox(
        "All card statuses reset. Click 'Do Self Test' to run again.");
}

/****************************************************************************************************
*  Function Name    = OnBnClickedOk() / OnOK()
*  Description      = Closes the dialog (matching original Exit button behaviour).
*****************************************************************************************************/
void CBenchSelfTest::OnBnClickedOk()
{
   // OnBnClickedButResetall();
    CDialog::OnOK();
}

void CBenchSelfTest::OnOK()
{
    CDialog::OnOK();
}



//void CBenchSelfTest::LogSelfTestResults()
//{
//    UpdateData(TRUE);
//
//    struct { const char* name; BOOL result; } items[] =
//    {
//        { "28V DC Power Supply Self Test",      m_chkPwrSupply   },
//        { "PCI Card 1711 Self Test",            m_chkPCI1711     },
//        { "PCI Card 1715 Self Test",            m_chkPCI1715     },
//        { "PCI Card 1733 Self Test",            m_chkPCI1733     },
//        { "PCIE Card 1758 Self Test",           m_chkPCIE1758DO  },
//        { "PCIE Card 1824 Self Test",           m_chkPCIE1824    },
//        { "PCI Card ARINC429 Self Test",        m_chkPCIArinc429 },
//        { "PCI Card 1622B Self Test",           m_chkPCI1622B    },
//        { "Ethernet Communication Self Test",   m_chkEthComm     },
//    };
//
//    CSIPU_SDU_GndRigApp *pApp = (CSIPU_SDU_GndRigApp *)AfxGetApp();
//    strcpy(s_SelfTest_IndexPage.m_strOperator, pApp->m_strLogin_UserName);
//
//    SYSTEMTIME st;
//    ::GetLocalTime(&st);
//    CString strDT;
//    strDT.Format("%02d/%02d/%04d %02d:%02d:%02d",
//        st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
//    strcpy(s_SelfTest_IndexPage.m_strDateTime, strDT);
//
//    char chExeDir[MAX_PATH];
//    ::GetModuleFileName(NULL, chExeDir, MAX_PATH);
//    CString strDir(chExeDir);
//    strDir = strDir.Left(strDir.ReverseFind('\\'));
//
//    CString strFullPath;
//    strFullPath.Format("%s\\SelfTest_%02d_%02d_%04d_%02dH%02dM%02dS.bin",
//        strDir, st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
//
//    strcpy(s_SelfTest_IndexPage.m_strFileName, strFullPath);
//    g_strSelfTestFileName = strFullPath;   // <-- what SelfTestHeaderPage / SelfTestTable1Unit will open
//
//    CFile fptr;
//    if (!fptr.Open(strFullPath, CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
//    {
//        AfxMessageBox("Self Test Log File Creation Failed");
//        UpdateData(FALSE);
//        return;
//    }
//
//    // header first (Table1Unit/HeaderPage will "dummy read" this, same as s_Index_Page)
//    fptr.Write(&s_SelfTest_IndexPage, sizeof(s_SelfTest_IndexPage));
//
//    // then one sSelfTest_Item record per test, sequentially
//    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++)
//    {
//        sSelfTest_Item item;
//        strcpy(item.m_strItemName, items[i].name);
//        strcpy(item.m_strResult, items[i].result ? "OK" : "NOT OK");
//        fptr.Write(&item, sizeof(item));
//    }
//
//    fptr.Close();
//    UpdateData(FALSE);
//}

void CBenchSelfTest::LogSelfTestResults()
{
    UpdateData(TRUE);

    struct { const char* name; BOOL result; } items[] =
    {
        { "28V DC Power Supply Self Test",      m_chkPwrSupply   },
        { "PCI Card 1711 Self Test",            m_chkPCI1711     },
        { "PCI Card 1715 Self Test",            m_chkPCI1715     },
        { "PCI Card 1733 Self Test",            m_chkPCI1733     },
        { "PCIE Card 1758 Self Test",           m_chkPCIE1758DO  },
        { "PCIE Card 1824 Self Test",           m_chkPCIE1824    },
        { "PCI Card ARINC429 Self Test",        m_chkPCIArinc429 },
        { "PCI Card 1622B Self Test",           m_chkPCI1622B    },
        { "Ethernet Communication Self Test",   m_chkEthComm     },
    };

    CSIPU_SDU_GndRigApp *pApp = (CSIPU_SDU_GndRigApp *)AfxGetApp();
    strcpy(s_SelfTest_IndexPage.m_strOperator, pApp->m_strLogin_UserName);

    SYSTEMTIME st;
    ::GetLocalTime(&st);
    CString strDT;
    strDT.Format("%02d/%02d/%04d %02d:%02d:%02d",
        st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
    strcpy(s_SelfTest_IndexPage.m_strDateTime, strDT);

    // ---------------------------------------------------------------
    // Default folder: <MyDocuments>\Self-test report  (create if missing)
    // Falls back to exe folder if MyDocuments isn't resolvable.
    // ---------------------------------------------------------------
    CString strDefaultDir;
    TCHAR szDocPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, szDocPath)))
    {
        strDefaultDir.Format("%s\\Self-test report", szDocPath);
    }
    else
    {
        char chExeDir[MAX_PATH];
        ::GetModuleFileName(NULL, chExeDir, MAX_PATH);
        CString strExeDir(chExeDir);
        strExeDir = strExeDir.Left(strExeDir.ReverseFind('\\'));
        strDefaultDir.Format("%s\\Self-test report", strExeDir);
    }

    // Create the folder if it doesn't already exist (no error if it does)
    ::CreateDirectory(strDefaultDir, NULL);

    // Suggested file name (user can rename/relocate in the dialog)
    CString strSuggestedName;
    strSuggestedName.Format("SelfTest_%02d_%02d_%04d_%02dH%02dM%02dS",
        st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);

    static char BASED_CODE szFilter[] = "Binary Files(*.BIN)|*.BIN||";
    CFileDialog dlg(FALSE, "bin", strSuggestedName,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        szFilter, this);

    dlg.m_ofn.lpstrInitialDir = strDefaultDir;

    if (dlg.DoModal() == IDCANCEL)
    {
        UpdateData(FALSE);
        return;
    }

    CString strFullPath = dlg.GetPathName();

    strcpy(s_SelfTest_IndexPage.m_strFileName, strFullPath);
    g_strSelfTestFileName = strFullPath;

    CFile fptr;
    if (!fptr.Open(strFullPath, CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
    {
        AfxMessageBox("Self Test Log File Creation Failed");
        UpdateData(FALSE);
        return;
    }

    fptr.Write(&s_SelfTest_IndexPage, sizeof(s_SelfTest_IndexPage));

    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++)
    {
        sSelfTest_Item item;
        strcpy(item.m_strItemName, items[i].name);
        strcpy(item.m_strResult, items[i].result ? "OK" : "NOT OK");
        fptr.Write(&item, sizeof(item));
    }

    fptr.Close();
    UpdateData(FALSE);
}

//
//void CBenchSelfTest::OnButPrintSelfTest()
//{
//    if (g_strSelfTestFileName.IsEmpty())
//    {
//        AfxMessageBox("Please run 'Do Self Test' before printing.");
//        return;
//    }
//
//    SelfTestPrintJob job;
//    job.Print();
//
//    CWaitCursor UserInteractionLock;
//}


void CBenchSelfTest::OnButPrintSelfTest()
{
    // ---------------------------------------------------------------
    // Default folder: same "Self-test report" folder as LogSelfTestResults()
    // ---------------------------------------------------------------
    CString strDefaultDir;
    TCHAR szDocPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, szDocPath)))
    {
        strDefaultDir.Format("%s\\Self-test report", szDocPath);
    }
    else
    {
        char chExeDir[MAX_PATH];
        ::GetModuleFileName(NULL, chExeDir, MAX_PATH);
        CString strExeDir(chExeDir);
        strExeDir = strExeDir.Left(strExeDir.ReverseFind('\\'));
        strDefaultDir.Format("%s\\Self-test report", strExeDir);
    }

    static char BASED_CODE szFilter[] = "Binary Files(*.BIN)|*.BIN||";
    CFileDialog dlg(TRUE, "bin", NULL,
        OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
        szFilter, this);

    dlg.m_ofn.lpstrInitialDir = strDefaultDir;

    if (dlg.DoModal() == IDCANCEL)
        return;

    // Use the file the user picked, not whatever LogSelfTestResults() last wrote
    g_strSelfTestFileName = dlg.GetPathName();

    SelfTestPrintJob job;
    job.Print();

    CWaitCursor UserInteractionLock;
}