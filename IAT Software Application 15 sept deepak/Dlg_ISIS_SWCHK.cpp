#include "stdafx.h"
#include "Dlg_ISIS_SWCHK.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Macros.h"
#include "SerialPort.h"
#include "SIPU_SDU_GndRig.h"
#include "Globals.h"
extern CSerialPort gCommPort1,gCommPort2;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

namespace
{
    void BuildSimVersionPacket(BYTE packet[38], const char* mpmVer, const char* blgmVer)
    {
        ZeroMemory(packet, 38);
        packet[CMD_HEADER_INDEX0] = 'A';
        packet[CMD_HEADER_INDEX1] = '5';
        packet[CMD_HEADER_INDEX2] = 'A';
        packet[CMD_HEADER_INDEX3] = '5';

        // expects "01.00" style, 5 chars incl '.'
        packet[CMD_DATA_INDEX0] = mpmVer[0];
        packet[CMD_DATA_INDEX1] = mpmVer[1];
        packet[CMD_DATA_INDEX2] = mpmVer[3];
        packet[CMD_DATA_INDEX3] = mpmVer[4];

        packet[CMD_DATA_INDEX4] = blgmVer[0];
        packet[CMD_DATA_INDEX5] = blgmVer[1];
        packet[CMD_DATA_INDEX6] = blgmVer[3];
        packet[CMD_DATA_INDEX7] = blgmVer[4];
    }

    void BuildSimChecksumPacket(BYTE packet[38], const char* mpmChk, const char* blgmChk)
    {
        ZeroMemory(packet, 38);
        packet[CMD_HEADER_INDEX0] = 'A';
        packet[CMD_HEADER_INDEX1] = '5';
        packet[CMD_HEADER_INDEX2] = 'A';
        packet[CMD_HEADER_INDEX3] = '5';

        // expects 8 hex chars, no "0x" prefix
        packet[CMD_DATA_INDEX0]  = mpmChk[0];
        packet[CMD_DATA_INDEX1]  = mpmChk[1];
        packet[CMD_DATA_INDEX2]  = mpmChk[2];
        packet[CMD_DATA_INDEX3]  = mpmChk[3];
        packet[CMD_DATA_INDEX4]  = mpmChk[4];
        packet[CMD_DATA_INDEX5]  = mpmChk[5];
        packet[CMD_DATA_INDEX6]  = mpmChk[6];
        packet[CMD_DATA_INDEX7]  = mpmChk[7];

        packet[CMD_DATA_INDEX8]  = blgmChk[0];
        packet[CMD_DATA_INDEX9]  = blgmChk[1];
        packet[CMD_DATA_INDEX10] = blgmChk[2];
        packet[CMD_DATA_INDEX11] = blgmChk[3];
        packet[CMD_DATA_INDEX12] = blgmChk[4];
        packet[CMD_DATA_INDEX13] = blgmChk[5];
        packet[CMD_DATA_INDEX14] = blgmChk[6];
        packet[CMD_DATA_INDEX15] = blgmChk[7];
    }
}

IMPLEMENT_DYNAMIC(CDlg_ISIS_SWCHK, CDialog)

CDlg_ISIS_SWCHK::CDlg_ISIS_SWCHK(CWnd* pParent)
	: CDialog(CDlg_ISIS_SWCHK::IDD, pParent)
	
	, m_edt_ISISFC_MPMVR(_T(""))
	, m_edt_ISISFC_MPMCHK(_T(""))
	, m_edt_ISISFC_BLGMVR(_T(""))
	, m_edt_ISISFC_BLGMCHK(_T(""))
	, m_edt_ISISRC_MPMVR(_T(""))
	, m_edt_ISISRC_MPMCHK(_T(""))
	, m_edt_ISISRC_BLGMVR(_T(""))
	, m_edt_ISISRC_BLGMCHK(_T(""))
{
	m_bThreadRunning = FALSE;
}

CDlg_ISIS_SWCHK::~CDlg_ISIS_SWCHK()
{
}

void CDlg_ISIS_SWCHK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT_ISISFC_MPMVR, m_edt_ISISFC_MPMVR);
	DDX_Text(pDX, IDC_EDIT_ISISFC_MPMCHK, m_edt_ISISFC_MPMCHK);
	DDX_Text(pDX, IDC_EDIT_ISISFC_BLGMVR, m_edt_ISISFC_BLGMVR);
	DDX_Text(pDX, IDC_EDIT_ISISFC_BLGMCHK, m_edt_ISISFC_BLGMCHK);
	DDX_Text(pDX, IDC_EDIT_ISISRC_MPMVR, m_edt_ISISRC_MPMVR);
	DDX_Text(pDX, IDC_EDIT_ISISRC_MPMCHK, m_edt_ISISRC_MPMCHK);
	DDX_Text(pDX, IDC_EDIT_ISISRC_BLGMVR, m_edt_ISISRC_BLGMVR);
	DDX_Text(pDX, IDC_EDIT_ISISRC_BLGMCHK, m_edt_ISISRC_BLGMCHK);
}

BEGIN_MESSAGE_MAP(CDlg_ISIS_SWCHK, CDialog)
	
	ON_BN_CLICKED(IDOK, &CDlg_ISIS_SWCHK::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ISIS_SW, &CDlg_ISIS_SWCHK::OnBnClickedButtonIsisSw)
	ON_MESSAGE(WM_UPDATE_SOFTWARE, OnUpdateSoftware)
	ON_MESSAGE(WM_PROGRESS_UPDATE, OnProgressUpdate)
    ON_MESSAGE(WM_PROGRESS_CLOSE, OnProgressClose)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL CDlg_ISIS_SWCHK::OnInitDialog()
{

	
	 InitializeSerialPort("com1");
	InitializeSerialPort("com2");
	CDialog::OnInitDialog();
	return TRUE;
}

// -------- CHECK HANDLERS --------



// -------- OK BUTTON --------

void CDlg_ISIS_SWCHK::OnOK()
{
	
	CDialog::OnOK();   // 🔥 MUST
}

void CDlg_ISIS_SWCHK::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);  // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// -------- MPM VERSION --------
	if (m_edt_ISISFC_MPMVR.Compare("01.00") == 0)
	{
		m_strISISMPMVer = m_edt_ISISFC_MPMVR;
		m_strStatusISISMPMVer = "OK";
	}
	else
	{
		g_strMsgStr = "3.01  ISIS-DU FC MPM VERSION is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISMPMVer = m_edt_ISISFC_MPMVR;
		m_strStatusISISMPMVer = "NOT OK";
	}

	// -------- MPM CHECKSUM --------
	if (m_edt_ISISFC_MPMCHK.Compare("0xCA347B86") == 0)
	{
		m_strISISMPMCSum = m_edt_ISISFC_MPMCHK;
		m_strStatusISISMPMCSum = "OK";
	}
	else
	{
		g_strMsgStr = "3.02  ISIS-DU FC MPM CHECKSUM is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISMPMCSum = m_edt_ISISFC_MPMCHK;
		m_strStatusISISMPMCSum = "NOT OK";
	}

	// -------- BLGM VERSION --------
	if (m_edt_ISISFC_BLGMVR.Compare("01.00") == 0)
	{
		m_strISISSWVer = m_edt_ISISFC_BLGMVR;
		m_strStatusISISSWVer = "OK";
	}
	else
	{
		g_strMsgStr = "3.03  ISIS-DU FC BLGM VERSION is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISSWVer = m_edt_ISISFC_BLGMVR;
		m_strStatusISISSWVer = "NOT OK";
	}

	// -------- BLGM CHECKSUM --------
	if (m_edt_ISISFC_BLGMCHK.Compare("0x43760D0A") == 0)
	{
		m_strISISSWCsum = m_edt_ISISFC_BLGMCHK;
		m_strStatusISISSWCsum = "OK";
	}
	else
	{
		g_strMsgStr = "3.04  ISIS-DU FC BLGM CHECKSUM is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISSWCsum = m_edt_ISISFC_BLGMCHK;
		m_strStatusISISSWCsum = "NOT OK";
	}

	////////////RC///////////////////////////


	
	// -------- MPM VERSION --------
	if (m_edt_ISISFC_MPMVR.Compare("01.00") == 0)
	{
		m_strISISRCMPMVer = m_edt_ISISFC_MPMVR;
		m_strStatusISISRCMPMVer = "OK";
	}
	else
	{
		g_strMsgStr = "3.05  ISIS-DU RC MPM VERSION is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISRCMPMVer = m_edt_ISISFC_MPMVR;
		m_strStatusISISRCMPMVer = "NOT OK";
	}

	// -------- MPM CHECKSUM --------
	if (m_edt_ISISFC_MPMCHK.Compare("0xCA347B86") == 0)
	{
		m_strISISRCMPMCSum = m_edt_ISISFC_MPMCHK;
		m_strStatusISISRCMPMCSum = "OK";
	}
	else
	{
		g_strMsgStr = "3.06  ISIS-DU RC MPM CHECKSUM is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISRCMPMCSum = m_edt_ISISFC_MPMCHK;
		m_strStatusISISRCMPMCSum = "NOT OK";
	}

	// -------- BLGM VERSION --------
	if (m_edt_ISISFC_BLGMVR.Compare("01.00") == 0)
	{
		m_strISISRCSWVer = m_edt_ISISFC_BLGMVR;
		m_strStatusISISRCSWVer = "OK";
	}
	else
	{
		g_strMsgStr = "3.07 ISIS-DU RC BLGM VERSION is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISRCSWVer = m_edt_ISISFC_BLGMVR;
		m_strStatusISISRCSWVer = "NOT OK";
	}

	// -------- BLGM CHECKSUM --------
	if (m_edt_ISISFC_BLGMCHK.Compare("0x43760D0A") == 0)
	{
		m_strISISRCSWCsum = m_edt_ISISFC_BLGMCHK;
		m_strStatusISISRCSWCsum = "OK";
	}
	else
	{
		g_strMsgStr = "3.08  ISIS-DU RC BLGM CHECKSUM is not correct. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;

		m_strISISRCSWCsum = m_edt_ISISFC_BLGMCHK;
		m_strStatusISISRCSWCsum = "NOT OK";
	}
	UpdateData(FALSE);

	CDialog::OnOK();
}




UINT CDlg_ISIS_SWCHK::SoftwareThread(LPVOID pParam)
{
    CDlg_ISIS_SWCHK* pDlg =
        (CDlg_ISIS_SWCHK*)pParam;

    try
    {
        pDlg->ExecuteSoftwareRead();
    }
    catch(...)
    {
    }

    pDlg->PostCloseProgress();

    pDlg->m_bThreadRunning = FALSE;

    return 0;
}
void CDlg_ISIS_SWCHK::OnBnClickedButtonIsisSw()
{
    if(m_bThreadRunning)
        return;

    // In simulation mode the PC transmits the specification response packets
    // and must receive the same packets back through the physical loopback.
    // Do this before starting the worker thread so the user can cancel safely.
    if (g_bSimulationMode)
    {
        const int answer = AfxMessageBox(
            _T("ISIS software-check simulation is enabled.\n\n")
            _T("Connect the loopback connector to the ISIS DU X port(s) ")
            _T("configured as COM1 (FC) and COM2 (RC), then press OK.\n\n")
            _T("The test will transmit the specification software versions ")
            _T("and checksums and decode the returned loopback data."),
            MB_OKCANCEL | MB_ICONINFORMATION);

        if (answer != IDOK)
            return;
    }

m_ProgressDlg.Create(
        IDD_PROGRESS_DIALOG,
        this);

m_ProgressDlg.ShowWindow(SW_SHOW);

EnableWindow(FALSE);

m_bThreadRunning = TRUE;

    CWinThread* pThread=AfxBeginThread(SoftwareThread,this);

    if(pThread==NULL)
    {
        m_bThreadRunning=FALSE;

  

        AfxMessageBox("Unable to start Software Check.");
    }
}

LRESULT CDlg_ISIS_SWCHK::OnUpdateSoftware(WPARAM, LPARAM)
{
    UpdateData(FALSE);

    return 0;
}


void CDlg_ISIS_SWCHK::ExecuteSoftwareRead()
{
    BOOL bTrsFlag;
    int iCount;
    unsigned char ucByte1, ucByte2, ucByte3, ucByte4;
    unsigned char ucByte5, ucByte6, ucByte7, ucByte8;
	
	if(g_bSimulationMode)
	{
		 TRACE(_T("Entering: %hs\n"), __FUNCTION__); 
	}



    CString strRecHeader;
#if 1
    //////////////////////////////////////////////
    // FC VERSION
    //////////////////////////////////////////////

    if (!g_bSimulationMode)
    {
        SwitchDiscrete(ISIS_DU_FC_ON, ON);
        SwitchDiscrete(ISIS_DU_RC_ON, ON);
        PostProgress(10, "Powering ON ISIS-DU Please wait 1 min...");
        Sleep(50000);
    }
    else
    {
        // Simulation does not operate discrete hardware or wait for LRU power-up.
        PostProgress(10, "Loopback connected. Starting ISIS software-check simulation...");
    }

  
	 PostProgress(30,
               "Feteching the software version and checksum of ISIS-DU FC...");
    // Send Version Command
		CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();
    BYTE TxData[7] =
    {
        0x5B,
        0xA5,
        0x05,
        0x01,
        0x0F,
        0x16,
        0x2B
    };

 BOOL bHeaderFound = FALSE;

for(int retry = 0; retry < 3; retry++)
{
    // Clear receive buffer
    memset(pMainFrame->ucMFD_CommReadArray, 0,
           sizeof(pMainFrame->ucMFD_CommReadArray));

		if (g_bSimulationMode)
		{
			BYTE simPacket[38];
			BuildSimVersionPacket(simPacket, "01.00", "01.00");   // FC MPM ver, FC BLGM ver
			gCommPort1.WriteByte1(simPacket, 38);
		}
		else
		{
			for(iCount=0; iCount<7; iCount++)
				gCommPort1.WriteByte(TxData[iCount]);
		}

    Sleep(250);

    // Read response
    for(iCount=0; iCount<38; iCount++)
        gCommPort1.ReadByte(pMainFrame->ucMFD_CommReadArray[iCount]);

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX3];

    strRecHeader.Format("%c%c%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    if(strRecHeader.Compare("A5A5") == 0)
    {
        bHeaderFound = TRUE;
        break;
    }

    TRACE("Version Retry %d Failed. Header = %s\n",
          retry + 1,
          strRecHeader);
	
}

if(bHeaderFound)
{
    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX3];

    m_edt_ISISFC_MPMVR.Format("%c%c.%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX4];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX5];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX6];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX7];

    m_edt_ISISFC_BLGMVR.Format("%c%c.%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);
}
else
{
    TRACE("Failed to receive valid Version response after 3 retries.\n");
	m_edt_ISISFC_MPMVR.Format("COM FAIL");
	m_edt_ISISFC_BLGMVR.Format("COM FAIL");
}
   

    PostMessage(WM_UPDATE_SOFTWARE);

    //////////////////////////////////////////////
    // FC CHECKSUM
    //////////////////////////////////////////////
	Sleep(1000);
    TxData[5] = 0x17;
    TxData[6] = 0x2C;

 bHeaderFound = FALSE;

for(int retry=0; retry<3; retry++)
{
    memset(pMainFrame->ucMFD_CommReadArray,0,
           sizeof(pMainFrame->ucMFD_CommReadArray));

		if (g_bSimulationMode)
		{
			BYTE simPacket[38];
			BuildSimChecksumPacket(simPacket, "CA347B86", "43760D0A");  // FC MPM chk, FC BLGM chk
			gCommPort1.WriteByte1(simPacket, 38);
		}
		else
		{
			for(iCount=0;iCount<7;iCount++)
				gCommPort1.WriteByte(TxData[iCount]);
		}

    Sleep(250);

    for(iCount=0;iCount<38;iCount++)
        gCommPort1.ReadByte(pMainFrame->ucMFD_CommReadArray[iCount]);

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX3];

    strRecHeader.Format("%c%c%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    if(strRecHeader.Compare("A5A5")==0)
    {
        bHeaderFound = TRUE;
        break;
    }

    TRACE("Checksum Retry %d Failed. Header=%s\n",
          retry+1,
          strRecHeader);
}

if(bHeaderFound)
{
    // Existing checksum extraction code
	
   if(strRecHeader.Compare("A5A5") == 0)
    {
        ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX0];
        ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX1];
        ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX2];
        ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX3];
        ucByte5 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX4];
        ucByte6 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX5];
        ucByte7 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX6];
        ucByte8 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX7];

        m_edt_ISISFC_MPMCHK.Format(
            "0x%c%c%c%c%c%c%c%c",
            ucByte1,
            ucByte2,
            ucByte3,
            ucByte4,
            ucByte5,
            ucByte6,
            ucByte7,
            ucByte8);

        ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX8];
        ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX9];
        ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX10];
        ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX11];
        ucByte5 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX12];
        ucByte6 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX13];
        ucByte7 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX14];
        ucByte8 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX15];

        m_edt_ISISFC_BLGMCHK.Format(
            "0x%c%c%c%c%c%c%c%c",
            ucByte1,
            ucByte2,
            ucByte3,
            ucByte4,
            ucByte5,
            ucByte6,
            ucByte7,
            ucByte8);
    }
}
else
{
    TRACE("Failed to receive valid Checksum response after 3 retries.\n");
	m_edt_ISISFC_MPMCHK.Format("COM FAIL");
	m_edt_ISISFC_BLGMCHK.Format("COM FAIL");
}


    PostMessage(WM_UPDATE_SOFTWARE);
		 PostProgress(50,
               "Fetched successfully Now powering on ISIS-DU RC Please wait for 1 min...");
    //SwitchDiscrete(ISIS_DU_FC_ON, OFF);

    ///////////////////////////////////////////////////////
    // RC
    ///////////////////////////////////////////////////////
#if 1
    // Repeat the exact same sequence after

   

    // Version Command

    // Checksum Command

    // Fill:

    // m_edt_ISISRC_MPMVR

    // m_edt_ISISRC_BLGMVR

    // m_edt_ISISRC_MPMCHK

    // m_edt_ISISRC_BLGMCHK

	 
	  PostProgress(60,
               "Feteching the software version and checksum of ISIS-DU RC...");
	BYTE TxData2[7] =
    {
        0x5B,
        0xA5,
        0x05,
        0x01,
        0x0F,
        0x16,
        0x2B
    };

 bHeaderFound = FALSE;

for(int retry = 0; retry < 3; retry++)
{
    // Clear receive buffer
    memset(pMainFrame->ucMFD_CommReadArray, 0,
           sizeof(pMainFrame->ucMFD_CommReadArray));

		if (g_bSimulationMode)
		{
			BYTE simPacket[38];
			BuildSimVersionPacket(simPacket, "01.00", "01.00");   // RC MPM ver, RC BLGM ver
			gCommPort2.WriteByte1(simPacket, 38);
		}
		else
		{
			for(iCount=0; iCount<7; iCount++)
				gCommPort2.WriteByte(TxData2[iCount]);   // fixed: TxData2, not TxData
		}

    Sleep(250);

    // Read response
    for(iCount=0; iCount<38; iCount++)
        gCommPort2.ReadByte(pMainFrame->ucMFD_CommReadArray[iCount]);

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX3];

    strRecHeader.Format("%c%c%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    if(strRecHeader.Compare("A5A5") == 0)
    {
        bHeaderFound = TRUE;
        break;
    }

    TRACE("Version Retry %d Failed. Header = %s\n",
          retry + 1,
          strRecHeader);
}

if(bHeaderFound)
{
    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX3];

    m_edt_ISISRC_MPMVR.Format("%c%c.%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX4];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX5];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX6];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX7];

    m_edt_ISISRC_BLGMVR.Format("%c%c.%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);
}
else
{
    TRACE("Failed to receive valid Version response after 3 retries.\n");
	m_edt_ISISRC_MPMVR.Format("COM FAIL");
	m_edt_ISISRC_BLGMVR.Format("COM FAIL");
}
   
    PostMessage(WM_UPDATE_SOFTWARE);

    //////////////////////////////////////////////
    // RC CHECKSUM
    //////////////////////////////////////////////

    TxData2[5] = 0x17;
    TxData2[6] = 0x2C;

   bHeaderFound = FALSE;

for(int retry=0; retry<3; retry++)
{
    memset(pMainFrame->ucMFD_CommReadArray,0,
           sizeof(pMainFrame->ucMFD_CommReadArray));

		if (g_bSimulationMode)
		{
			BYTE simPacket[38];
			BuildSimChecksumPacket(simPacket, "CA347B86", "43760D0A");  // RC MPM chk, RC BLGM chk
			gCommPort2.WriteByte1(simPacket, 38);
		}
		else
		{
			for(iCount=0;iCount<7;iCount++)
				gCommPort2.WriteByte(TxData2[iCount]);   // fixed: TxData2 on gCommPort2
		}

    Sleep(250);

    for(iCount=0;iCount<38;iCount++)
			gCommPort2.ReadByte(pMainFrame->ucMFD_CommReadArray[iCount]);   // fixed: gCommPort2

    ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX0];
    ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX1];
    ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX2];
    ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_HEADER_INDEX3];

    strRecHeader.Format("%c%c%c%c",
        ucByte1,
        ucByte2,
        ucByte3,
        ucByte4);

    if(strRecHeader.Compare("A5A5")==0)
    {
        bHeaderFound = TRUE;
        break;
    }

    TRACE("Checksum Retry %d Failed. Header=%s\n",
          retry+1,
          strRecHeader);
}

if(bHeaderFound)
{
    // Existing checksum extraction code
	
   if(strRecHeader.Compare("A5A5") == 0)
    {
        ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX0];
        ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX1];
        ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX2];
        ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX3];
        ucByte5 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX4];
        ucByte6 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX5];
        ucByte7 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX6];
        ucByte8 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX7];

        m_edt_ISISRC_MPMCHK.Format(
            "0x%c%c%c%c%c%c%c%c",
            ucByte1,
            ucByte2,
            ucByte3,
            ucByte4,
            ucByte5,
            ucByte6,
            ucByte7,
            ucByte8);

        ucByte1 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX8];
        ucByte2 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX9];
        ucByte3 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX10];
        ucByte4 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX11];
        ucByte5 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX12];
        ucByte6 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX13];
        ucByte7 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX14];
        ucByte8 = pMainFrame->ucMFD_CommReadArray[CMD_DATA_INDEX15];

        m_edt_ISISRC_BLGMCHK.Format(
            "0x%c%c%c%c%c%c%c%c",
            ucByte1,
            ucByte2,
            ucByte3,
            ucByte4,
            ucByte5,
            ucByte6,
            ucByte7,
            ucByte8);
    }
}
else
{
    TRACE("Failed to receive valid Checksum response after 3 retries.\n");
		m_edt_ISISRC_MPMCHK.Format("COM FAIL");
	m_edt_ISISRC_BLGMCHK.Format("COM FAIL");
}



    PostMessage(WM_UPDATE_SOFTWARE);
	 PostProgress(90,
               "ISIS Software checksum and version test complete...");
   // SwitchDiscrete(ISIS_DU_RC_ON, OFF);
	 PostProgress(100,
    "Completed Successfully.");


    PostMessage(WM_UPDATE_SOFTWARE);
#endif
#endif
}




void CDlg_ISIS_SWCHK::PostProgress(int nPercent,
                                   LPCTSTR pszText)
{
    PROGRESS_MSG* pMsg = new PROGRESS_MSG;

    pMsg->nPercent = nPercent;
    pMsg->strStatus = pszText;

    PostMessage(WM_PROGRESS_UPDATE,
                0,
                (LPARAM)pMsg);
}

void CDlg_ISIS_SWCHK::PostCloseProgress()
{
    PostMessage(WM_PROGRESS_CLOSE);
}


LRESULT CDlg_ISIS_SWCHK::OnProgressUpdate(
        WPARAM,
        LPARAM lParam)
{
    PROGRESS_MSG* pMsg =
        (PROGRESS_MSG*)lParam;

    if(::IsWindow(m_ProgressDlg.GetSafeHwnd()))
    {
        m_ProgressDlg.SetProgress(
                pMsg->nPercent);

        m_ProgressDlg.SetStatus(
                pMsg->strStatus);
    }

    delete pMsg;

    return 0;
}

LRESULT CDlg_ISIS_SWCHK::OnProgressClose(
        WPARAM,
        LPARAM)
{
    if(::IsWindow(m_ProgressDlg.GetSafeHwnd()))
        m_ProgressDlg.DestroyWindow();

    EnableWindow(TRUE);

    return 0;
}


void CDlg_ISIS_SWCHK::OnClose()
{
    if(m_bThreadRunning)
    {
        AfxMessageBox(
            "Software Check is in progress.\nPlease wait until it completes.");

        return;
    }

    gCommPort1.ClosePort();
    gCommPort2.ClosePort();

    CDialog::OnClose();
}
