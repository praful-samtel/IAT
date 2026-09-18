// Dialog_Smfd_VORILS.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_VORILS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>
#include "Arinc429.h"
#include "Globals.h"
extern CSerialPort gCommPort1;


extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_VORILS dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_VORILS, CDialog)

CDialog_Smfd_VORILS::CDialog_Smfd_VORILS(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_VORILS::IDD, pParent)

	, m_edtvorbrg(0)
	, m_chk_SMFD_VorFreq(FALSE)
	, m_chk_SMFD_IlsFreq(FALSE)
	, m_edt_LocDev173(_T(""))
	, m_edt_GlsDev174(_T(""))
	, m_bThreadRunning(FALSE)
	, m_bStopThread(FALSE)
	, m_pArincRXThread(NULL)
{

}

CDialog_Smfd_VORILS::~CDialog_Smfd_VORILS()
{
}

void CDialog_Smfd_VORILS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_VORBRG, m_edtvorbrg);

	DDX_Check(pDX, IDC_CHECK_VORFREQ, m_chk_SMFD_VorFreq);
	DDX_Check(pDX, IDC_CHECK_ILS_FREQ, m_chk_SMFD_IlsFreq);
	DDX_Text(pDX, IDC_EDIT_LOCDEV173, m_edt_LocDev173);
	DDX_Text(pDX, IDC_EDIT_GLSDEV174, m_edt_GlsDev174);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_VORILS, CDialog)

	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_VORILS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_VORFREQ, &CDialog_Smfd_VORILS::OnBnClickedCheckVorfreq)
	ON_BN_CLICKED(IDC_CHECK_ILS_FREQ, &CDialog_Smfd_VORILS::OnBnClickedCheckIlsFreq)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CDialog_Smfd_VORILS::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}

void CDialog_Smfd_VORILS::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);

	////m_edtvorbrg  = 90;
	//UpdateData(FALSE);

	if (m_bThreadRunning)
		return;

	InitArincRX(9); //change

	m_bStopThread = FALSE;
	m_bThreadRunning = TRUE;

	m_pArincRXThread = AfxBeginThread(
		ArincRXThread,
		this,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);

	if (m_pArincRXThread == NULL)
	{
		m_bThreadRunning = FALSE;
		AfxMessageBox("Unable to start ARINC RX thread.");
		return;
	}

	m_pArincRXThread->m_bAutoDelete = FALSE;
	m_pArincRXThread->ResumeThread();
}


UINT CDialog_Smfd_VORILS::ArincRXThread(LPVOID pParam)
{
	CDialog_Smfd_VORILS* pDlg = (CDialog_Smfd_VORILS*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}

//
//void CDialog_Smfd_VORILS::ExecuteArincRX()
//{
//    float value = 0.0f;
//    DWORD phaseStartTick = GetTickCount();
//    BOOL  bVorPhase = TRUE;   // start on VOR phase
//
//    while (!m_bStopThread)
//    {
//        DWORD now = GetTickCount();
//        if (now - phaseStartTick >= 5000)
//        {
//            bVorPhase = !bVorPhase;
//            phaseStartTick = now;
//        }
//
//        ADT_L0_UINT32 Labels[3];
//        int labelCount = 0;
//
//        if (bVorPhase)
//        {
//            Labels[labelCount++] = 0x62001038;   // LABEL_034, VOR-tuned, 108.00 MHz
//            Labels[labelCount++] = 0xE8000049;   // LABEL_222, VOR Bearing = 90 deg
//        }
//        else
//        {
//            Labels[labelCount++] = 0x62043038;   // LABEL_034, ILS-tuned, 108.10 MHz
//            Labels[labelCount++] = 0xE31400DE;   // LABEL_173, Localizer Deviation = 0.077
//            Labels[labelCount++] = 0x71BD003E;   // LABEL_174, Glideslope Deviation = -0.087
//        }
//
//        gArinc429.SendLabels(SMFD_SIM_LOOPBACK_TX_CHANNEL_X, Labels, labelCount);
//
//        if (g_bSimulationMode)
//        {
//            TRACE("Simulation Mode On :: %s phase :: Sending DATA\n", bVorPhase ? "VOR" : "ILS");
//
//            ReadVorIlsTacanRX(SMFD_SIM_LOOPBACK_RX_PIN_P);
//
//            if (bVorPhase)
//            {
//                if (GetARINCValue(SMFD_SIM_LOOPBACK_RX_PIN_P, LABEL_034, &value))
//                    m_chk_SMFD_VorFreq = (value == 0.0f) ? TRUE : FALSE;   // 0 = VOR-tuned confirmed
//
//                if (GetARINCValue(SMFD_SIM_LOOPBACK_RX_PIN_P, LABEL_222, &value))
//                    m_edtvorbrg = (int)value;
//            }
//            else
//            {
//                if (GetARINCValue(SMFD_SIM_LOOPBACK_RX_PIN_P, LABEL_034, &value))
//                    m_chk_SMFD_IlsFreq = (value == 1.0f) ? TRUE : FALSE;   // 1 = ILS-tuned confirmed
//
//                if (GetARINCValue(SMFD_SIM_LOOPBACK_RX_PIN_P, LABEL_173, &value))
//                {
//                    CString str;
//                    str.Format(_T("%.3f"), value);
//                    m_edt_LocDev173 = str;
//                }
//
//                if (GetARINCValue(SMFD_SIM_LOOPBACK_RX_PIN_P, LABEL_174, &value))
//                {
//                    CString str;
//                    str.Format(_T("%.3f"), value);
//                    m_edt_GlsDev174 = str;
//                }
//            }
//        }
//        else
//        {
//            // Real hardware: word(s) already sent above via gArinc429.SendLabels();
//            // nothing further to do here.
//        }
//
//        PostMessage(WM_UPDATE_ARINC);
//        Sleep(100);
//    }
//}


void CDialog_Smfd_VORILS::ExecuteArincRX()
{
	float value = 0.0f;
    DWORD phaseStartTick = GetTickCount();
    BOOL  bVorPhase = TRUE;   // start on VOR phase

	while (!m_bStopThread)
	{
		DWORD now = GetTickCount();
        if (now - phaseStartTick >= 5000)
        {
            bVorPhase = !bVorPhase;
            phaseStartTick = now;
        }

        ADT_L0_UINT32 Labels[3];
        int labelCount = 0;

        if (bVorPhase)
        {
            Labels[labelCount++] = 0x62001038;   // LABEL_034, VOR-tuned, 108.00 MHz
            Labels[labelCount++] = 0xE8000049;   // LABEL_222, VOR Bearing = 90 deg
        }
        else
        {
            Labels[labelCount++] = 0x62043038;   // LABEL_034, ILS-tuned, 108.10 MHz
            Labels[labelCount++] = 0xE31400DE;   // LABEL_173, Localizer Deviation = 0.077
            Labels[labelCount++] = 0x71BD003E;   // LABEL_174, Glideslope Deviation = -0.087
        }

		//		Test	Value	Word
//10.01/10.03 VOR Frequency 108.00 MHz	Tuned=VOR (bit14=0)	0x62001338
//10.03 ILS Frequency 108.10 MHz	Tuned=ILS (bit14=1)	0x62043338
//11.01 TACAN Channel 12, X-mode	Air-to-Ground	0x460C21A6
		
		gArinc429.SendLabels(3, Labels, 4);
		
		if(g_bSimulationMode) 
		{
			TRACE("Simulation Mode On CDialogSmfd_ADC::ExecuteArincRX ::::::::::::::: Sending DATA ");
		
			ReadVorIlsTacanRX(9);

			 if (bVorPhase)
            {
				if (GetARINCValue(9, LABEL_222, &value))
					m_edtvorbrg = (int)value;

				if (GetARINCValue(9, LABEL_034, &value))
					 m_chk_SMFD_VorFreq = (value == 0.0f) ? TRUE : FALSE;   // 0 = VOR-tuned confirmed
			}
			 else
            {
                if (GetARINCValue(9, LABEL_034, &value))
                    m_chk_SMFD_IlsFreq = (value == 1.0f) ? TRUE : FALSE;   // 1 = ILS-tuned confirmed

                if (GetARINCValue(9, LABEL_173, &value))
                {
                    CString str;
                    str.Format(_T("%.3f"), value);
                    m_edt_LocDev173 = str;
                }

                if (GetARINCValue(9, LABEL_174, &value))
                {
                    CString str;
                    str.Format(_T("%.3f"), value);
                    m_edt_GlsDev174 = str;
                }
            }

		}
		if(!g_bSimulationMode)
		{
			gArinc429.SendLabels(4, Labels, 6); //SMFD
			//Send same data to SMFD & MFD FC to reflect data on SMFD
		}
		PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

void CDialog_Smfd_VORILS::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;

	m_strlocalizer = m_edt_LocDev173;
	m_strglideslope = m_edt_GlsDev174;
	
	m_strvorbrg = "90";

   if(m_chk_SMFD_VorFreq)
	{
		m_strvorfreq = "Displayed";
		m_strStatusvorfreq = "OK";
	}else
	{
		g_strMsgStr = "VOR frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strvorfreq = "Not Displayed";
		m_strStatusvorfreq = "NOT OK";
	}
	/////////////////////////
	if(m_chk_SMFD_IlsFreq)
	{
		m_strilsfreq = "Displayed";
		m_strStatusilsfreq = "OK";
	}else
	{
		g_strMsgStr = "ILS frequency invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strilsfreq = "Not Displayed";
		m_strStatusilsfreq = "NOT OK";
	}

	////////////////////
	if(m_strvorbrg=="90")
	{
		m_strStatusvorbrg = "OK";
	}else
	{
		g_strMsgStr = "VOR Bearing invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusvorfreq = "NOT OK";
	}

	//////////
	if(m_edt_LocDev173 == "0.077")
	{   
		
		m_strStatuslocalizer = "OK";
	}else
	{
		g_strMsgStr = "Localizer deviation invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatuslocalizer = "NOT OK";
	}

	/////////////////
	if(m_edt_GlsDev174 == "0.087")
	{   
		
		m_strStatusglideslope = "OK";
	}else
	{
		g_strMsgStr = "glideslope deviation invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatuslocalizer = "NOT OK";
	}
	UpdateData(FALSE);
	CDialog::OnOK();
}


void CDialog_Smfd_VORILS::OnBnClickedCheckVorfreq()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_SMFD_VorFreq)
	{
		GetDlgItem(IDC_CHECK_VORFREQ)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_VORFREQ)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_VORILS::OnBnClickedCheckIlsFreq()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);

   if (m_chk_SMFD_IlsFreq)
	{
		GetDlgItem(IDC_CHECK_ILS_FREQ)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ILS_FREQ)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}

void CDialog_Smfd_VORILS::OnDestroy()
{
	m_bStopThread = TRUE;

	if (m_pArincRXThread != NULL)
	{
		WaitForSingleObject(m_pArincRXThread->m_hThread, INFINITE);
		delete m_pArincRXThread;
		m_pArincRXThread = NULL;
	}

	//m_bThreadRunning = FALSE;

	CloseRx(8);

	CDialog::OnDestroy();
}
