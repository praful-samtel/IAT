// Dialog_SMFD_GPS.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_GPS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include <string>
#include "Arinc429.h"
#include "Globals.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_SMFD_GPS dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_GPS, CDialog)

CDialog_SMFD_GPS::CDialog_SMFD_GPS(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_SMFD_GPS::IDD, pParent)
	, m_edtGpsGrSpd(_T(""))
	, m_edtGpsTrueTrack(_T(""))
	, m_edtGpsMagTrack(_T(""))
	, m_edtGpsTime(_T(""))
{

}

CDialog_SMFD_GPS::~CDialog_SMFD_GPS()
{
}

void CDialog_SMFD_GPS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPSGRSPD, m_edtGpsGrSpd);
	DDX_Text(pDX, IDC_EDIT_GPSTRUETRACK, m_edtGpsTrueTrack);
	DDX_Text(pDX, IDC_EDIT_GPSMAGTRACK, m_edtGpsMagTrack);

	DDX_Text(pDX, IDC_EDIT_GPSTIME, m_edtGpsTime);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_GPS, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialog_SMFD_GPS::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_GPS::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
END_MESSAGE_MAP()


// CDialog_SMFD_GPS message handlers
BOOL CDialog_SMFD_GPS::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}

LRESULT CDialog_SMFD_GPS::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}
void CDialog_SMFD_GPS::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	//m_edtGpsGrSpd = "1000";
	//m_edtGpsTrueTrack = "90";
	//m_edtGpsMagTrack = "90";
	//m_edtGpsTime = "";
	//UpdateData(FALSE);     // ReadGpsRX

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


UINT CDialog_SMFD_GPS::ArincRXThread(LPVOID pParam)
{
	CDialog_SMFD_GPS* pDlg = (CDialog_SMFD_GPS*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}

void CDialog_SMFD_GPS::ExecuteArincRX()
{
	float value = 0.0f;

	while (!m_bStopThread)
	{
		ADT_L0_UINT32 Labels[4];

		Labels[0] = 0x00100050;   // LABEL_012, GPS Ground Speed = 1000 Km
		Labels[1] = 0x000900D0;   // LABEL_013, GPS True Track = 90.0 deg
		Labels[2] = 0x800900D4;   // LABEL_053, GPS Mag Track = 90.0 deg
		Labels[3] = 0x848000AA;   // LABEL_125, GPS Time = 12:00:00

		if (g_bSimulationMode)
		{
			TRACE("Simulation Mode On CDialog_SMFD_GPS::ExecuteArincRX ::::::::::::::: Sending DATA ");

			gArinc429.SendLabels(9, Labels, 4);   // TX ch 9 -- matches InitArincRX(9) self-loopback

			ReadGpsRX(9);

			if (GetARINCValue(9, LABEL_012, &value))
			{
				CString str;
				str.Format(_T("%.0f"), value);
				m_edtGpsGrSpd = str;
			}

			if (GetARINCValue(9, LABEL_013, &value))
			{
				CString str;
				str.Format(_T("%.1f"), value);
				m_edtGpsTrueTrack = str;
			}

			if (GetARINCValue(9, LABEL_053, &value))
			{
				CString str;
				str.Format(_T("%.1f"), value);
				m_edtGpsMagTrack = str;
			}

			if (GetARINCValue(9, LABEL_125, &value))
			{
				// DecodeGpsArincData packs HH:MM:SS into a single number
				// as (hh*10000 + mm*100 + ss), e.g. 120000 for 12:00:00.
				int packed = (int)(value + 0.5f);
				int hh = packed / 10000;
				int mm = (packed / 100) % 100;
				int ss = packed % 100;

				CString str;
				str.Format(_T("%02d:%02d:%02d"), hh, mm, ss);
				m_edtGpsTime = str;
			}
		}
		else
		{
			// Real hardware: forward the same words out to the SMFD/MFD FC
			// display channel. Confirm the actual target channel before
			// relying on this -- '4' is carried over from the VOR/ILS/TACAN
			// dialogs' pattern and hasn't been verified for GPS specifically.
			gArinc429.SendLabels(4, Labels, 4);
		}

		PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

void CDialog_SMFD_GPS::OnBnClickedOk()
{
    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;

    double grSpd   = atof(m_edtGpsGrSpd);
    double trueTrk = atof(m_edtGpsTrueTrack);
    double magTrk  = atof(m_edtGpsMagTrack);

    // Store measured values
    m_strSmfdGpsGrSpd      = m_edtGpsGrSpd;
    m_strSmfdGpsTrueTrack  = m_edtGpsTrueTrack;
    m_strSmfdGpsMagTrack   = m_edtGpsMagTrack;
    m_strSmfdGpsTime       = m_edtGpsTime;

    // -------- Ground Speed --------
    if (grSpd == 1000)   // expected value (change as per SRS)
    {
        m_strStatusSmfdGpsGrSpd = "OK";
    }
    else
    {
        g_strMsgStr = "Ground Speed value invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusSmfdGpsGrSpd = "NOT OK";
    }

    // -------- True Track --------
    if (trueTrk == 90)
    {
        m_strStatusSmfdGpsTrueTrack = "OK";
    }
    else
    {
        g_strMsgStr = "True Track value invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusSmfdGpsTrueTrack = "NOT OK";
    }

    // -------- Magnetic Track --------
    if (magTrk == 90)
    {
        m_strStatusSmfdGpsMagTrack = "OK";
    }
    else
    {
        g_strMsgStr = "Magnetic Track value invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusSmfdGpsMagTrack = "NOT OK";
    }

    // -------- GPS Time --------
    if (!m_edtGpsTime.IsEmpty())
    {
        m_strStatusSmfdGpsTime = "OK";
    }
    else
    {
        g_strMsgStr = "GPS Time invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusSmfdGpsTime = "NOT OK";
    }

    CDialog::OnOK();
}
