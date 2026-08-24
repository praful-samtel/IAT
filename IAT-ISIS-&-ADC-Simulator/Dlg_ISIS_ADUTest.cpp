// Dlg_ISIS_ADUTest.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg_ISIS_ADUTest.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "resource.h"
#include "DataStruct.h"
#include "Arinc429.h"
#include "Globals.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
extern BOOL g_bSimulationMode;
// CDlg_ISIS_ADUTest dialog

IMPLEMENT_DYNAMIC(CDlg_ISIS_ADUTest, CDialog)

CDlg_ISIS_ADUTest::CDlg_ISIS_ADUTest(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_ISIS_ADUTest::IDD, pParent)
	, m_edtISISAirspeed(_T(""))
	, m_edtISISAltitude(_T(""))
	, m_edtISISMach(_T(""))
	, M_ctlChkISISVerticalSpeed(FALSE)
	, m_edtISISAirspeedRC(_T(""))
	, m_edtISISAltitudeRC(_T(""))
	, m_edtISISMachRC(_T(""))
	, M_ctlChkISISVerticalSpeedRC(FALSE)
{
	m_bThreadRunning = FALSE;
    m_bStopThread = FALSE;
}

CDlg_ISIS_ADUTest::~CDlg_ISIS_ADUTest()
{
}

void CDlg_ISIS_ADUTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ISIS_AIRSPEED, m_edtISISAirspeed);
	DDX_Text(pDX, IDC_EDIT_ISIS_ALTITUDE, m_edtISISAltitude);
	DDX_Text(pDX, IDC_EDIT_ISIS_MACH, m_edtISISMach);
	DDX_Check(pDX, IDC_CHECK_ISIS_VERTICAL_SPEED, M_ctlChkISISVerticalSpeed);
	DDX_Text(pDX, IDC_EDIT_ISIS_AIRSPEED2, m_edtISISAirspeedRC);
	DDX_Text(pDX, IDC_EDIT_ISIS_ALTITUDE2, m_edtISISAltitudeRC);
	DDX_Text(pDX, IDC_EDIT_ISIS_MACH2, m_edtISISMachRC);
	DDX_Check(pDX, IDC_CHECK_ISIS_VERTICAL_SPEED2, M_ctlChkISISVerticalSpeedRC);
}


BEGIN_MESSAGE_MAP(CDlg_ISIS_ADUTest, CDialog)
	ON_BN_CLICKED(IDOK, &CDlg_ISIS_ADUTest::OnBnClickedOk)
	
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_BN_CLICKED(IDC_CHECK_ISIS_VERTICAL_SPEED, &CDlg_ISIS_ADUTest::OnBnClickedCheckIsisVerticalSpeed)
	ON_BN_CLICKED(IDC_BUTTON_ARINC_SIMULATE, &CDlg_ISIS_ADUTest::OnBnClickedButtonArincSimulate)
	ON_BN_CLICKED(IDC_CHECK_ISIS_VERTICAL_SPEED2, &CDlg_ISIS_ADUTest::OnBnClickedCheckIsisVerticalSpeed2)
	ON_BN_CLICKED(IDC_BUTTON_ARINCRX, &CDlg_ISIS_ADUTest::OnBnClickedButtonArincrx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlg_ISIS_ADUTest message handlers



void CDlg_ISIS_ADUTest::OnBnClickedOk()
{
    CMessageBox_Dlg msgdlg;
    UpdateData(TRUE);

    // ---------------- AIRSPEED ----------------
    double airspeed = _tstof(m_edtISISAirspeed);
    m_strISISAirspeed.Format("%s", m_edtISISAirspeed);
	
    if (airspeed >= 187 && airspeed <= 197)
    {
        m_strStatusISISAirspeed = "OK";
    }
    else
    {
        g_strMsgStr = "9.01 ISIS Airspeed is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_AIRSPEED)->SetFocus();
            return;
        }

        m_strStatusISISAirspeed = "NOT OK";
    }

    // ---------------- ALTITUDE ----------------
    double altitude = _tstof(m_edtISISAltitude);
    m_strISISAltitude.Format("%s", m_edtISISAltitude);
	
    if (altitude >= 9950 && altitude <= 10010)
    {
        m_strStatusISISAltitude = "OK";
    }
    else
    {
        g_strMsgStr = "9.02 ISIS Altitude is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_ALTITUDE)->SetFocus();
            return;
        }

        m_strStatusISISAltitude = "NOT OK";
    }

    // ---------------- MACH ----------------
    double mach = _tstof(m_edtISISMach);
    m_strISISMach.Format("%s", m_edtISISMach);

    if (mach >= 0.36 && mach <= 0.38)
    {
        m_strStatusISISMach = "OK";
    }
    else
    {
        g_strMsgStr = "9.03 ISIS Mach Number is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_MACH)->SetFocus();
            return;
        }

        m_strStatusISISMach = "NOT OK";
    }

    // ---------------- VERTICAL SPEED ----------------
    if (M_ctlChkISISVerticalSpeed)
    {
        m_strISISVertical = "Operational";
        m_strStatusISISVertical = "OK";
    }
    else
    {
        g_strMsgStr = "9.04 Vertical Speed Mark on ISIS DU is not Correct, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strISISVertical = "Not Operational";
        m_strStatusISISVertical = "NOT OK";
    }
	////////////////////////RC////////////////////////////////////

	 // ---------------- AIRSPEED ----------------
    double airspeedRC = _tstof(m_edtISISAirspeedRC);
    m_strISISAirspeedRC.Format("%s", m_edtISISAirspeedRC);
	
    if (airspeedRC >= 187 && airspeedRC <= 197)
    {
        m_strStatusISISAirspeedRC = "OK";
    }
    else
    {
        g_strMsgStr = "9.05 ISIS Airspeed is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_AIRSPEED2)->SetFocus();
            return;
        }

        m_strStatusISISAirspeedRC = "NOT OK";
    }

    // ---------------- ALTITUDE ----------------
    double altitudeRC = _tstof(m_edtISISAltitudeRC);
    m_strISISAltitudeRC.Format("%s", m_edtISISAltitudeRC);
	
    if (altitudeRC >= 9950 && altitudeRC <= 10010)
    {
        m_strStatusISISAltitudeRC = "OK";
    }
    else
    {
        g_strMsgStr = "9.06 ISIS Altitude is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_ALTITUDE2)->SetFocus();
            return;
        }

        m_strStatusISISAltitudeRC = "NOT OK";
    }

    // ---------------- MACH ----------------
    double machRC = _tstof(m_edtISISMachRC);
    m_strISISMachRC.Format("%s", m_edtISISMachRC);
	
    if (machRC >= 0.36 && machRC <= 0.38)
    {
        m_strStatusISISMachRC = "OK";
    }
    else
    {
        g_strMsgStr = "9.07 ISIS Mach Number is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_MACH2)->SetFocus();
            return;
        }

        m_strStatusISISMachRC = "NOT OK";
    }

    // ---------------- VERTICAL SPEED ----------------
    if (M_ctlChkISISVerticalSpeedRC)
    {
        m_strISISVerticalRC = "Operational";
        m_strStatusISISVerticalRC = "OK";
    }
    else
    {
        g_strMsgStr = "9.08 Vertical Speed Mark on ISIS DU is not Correct, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strISISVerticalRC = "Not Operational";
        m_strStatusISISVerticalRC = "NOT OK";
    }

    UpdateData(FALSE);

    CDialog::OnOK();
}

void CDlg_ISIS_ADUTest::OnBnClickedCheckIsisVerticalSpeed()
{
    UpdateData(TRUE);

    if (M_ctlChkISISVerticalSpeed)
        GetDlgItem(IDC_CHECK_ISIS_VERTICAL_SPEED)->SetWindowText("Operational");
    else
        GetDlgItem(IDC_CHECK_ISIS_VERTICAL_SPEED)->SetWindowText("Not Operational");
	UpdateData(FALSE);
}

void CDlg_ISIS_ADUTest::OnBnClickedButtonArincSimulate()
{
	// TODO: Add your control notification handler code here
	 ADT_L0_UINT32 Labels[3];

Labels[0] = 0x65195738;
Labels[1] = 0x62C00349;
Labels[2] = 0xE0D803DE;

gArinc429.SendLabels(0, Labels, 3);
}


void CDlg_ISIS_ADUTest::OnBnClickedCheckIsisVerticalSpeed2()
{
	// TODO: Add your control notification handler code here
	    UpdateData(TRUE);

    if (M_ctlChkISISVerticalSpeedRC)
        GetDlgItem(IDC_CHECK_ISIS_VERTICAL_SPEED2)->SetWindowText("Operational");
    else
        GetDlgItem(IDC_CHECK_ISIS_VERTICAL_SPEED2)->SetWindowText("Not Operational");
	UpdateData(FALSE);
}


void CDlg_ISIS_ADUTest::OnBnClickedButtonArincrx()
{
    if(m_bThreadRunning)
        return;

    //InitializeARINC429();
	TRACE(_T("Entering: %hs\n"), __FUNCTION__);
    InitArincRX(8); //FC
    InitArincRX(9);  //RC

    m_bStopThread = FALSE;
    m_bThreadRunning = TRUE;

    AfxBeginThread(ArincRXThread,this);
}

UINT CDlg_ISIS_ADUTest::ArincRXThread(LPVOID pParam)
{
    CDlg_ISIS_ADUTest* pDlg =
        (CDlg_ISIS_ADUTest*)pParam;

    pDlg->ExecuteArincRX();

    pDlg->m_bThreadRunning = FALSE;

    return 0;
}
//23 35    24 36
void CDlg_ISIS_ADUTest::ExecuteArincRX()
{
    float value;

    while(!m_bStopThread)
    {

		if(g_bSimulationMode)
		{	
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
				ADT_L0_UINT32 Labels[3];
				Labels[0] = 0xE137E0C1;     
				Labels[1] = 0xE17200A1;
				Labels[2] = 0x63000061;
//ARINC Label Sent Successfully | Channel: 0 | Word: 0xE137E0C1
//Altitude  above 203

//ARINC Label Sent Successfully | Channel: 0 | Word: 0xE17200A1
//Mach above 205
				
//ARINC Label Sent Successfully | Channel: 0 | Word: 0x63000061
//Airspeed above 206

				gArinc429.SendLabels(0, Labels, 3); //FC

				gArinc429.SendLabels(1, Labels, 3); //RC
		}

        ReadRX(8);

        ReadRX(9);

        //
        // FC
        //



if(GetARINCValue(8,LABEL_203,&value))
    m_edtISISAltitude.Format("%.0f",value);

if(GetARINCValue(8,LABEL_205,&value))
    m_edtISISMach.Format("%.2f",value);

if(GetARINCValue(8,LABEL_206,&value))
    m_edtISISAirspeed.Format("%.0f",value);
        //
        // RC
        //

if(GetARINCValue(9,LABEL_203,&value))
    m_edtISISAltitudeRC.Format("%.0f",value);

if(GetARINCValue(9,LABEL_205,&value))
    m_edtISISMachRC.Format("%.2f",value);

if(GetARINCValue(9,LABEL_206,&value))
    m_edtISISAirspeedRC.Format("%.0f",value);

        PostMessage(WM_UPDATE_ARINC);

        Sleep(100);
    }
}


void CDlg_ISIS_ADUTest::OnDestroy()
{
    // Stop worker thread
    m_bStopThread = TRUE;

    // Wait for thread to exit
    while(m_bThreadRunning)
        Sleep(10);
  CloseRx(8);
  CloseRx(9);
  SwitchDiscrete(ISIS_DU_FC_ON,OFF);
  SwitchDiscrete(ISIS_DU_RC_ON,OFF);
    CDialog::OnClose();
}

LRESULT CDlg_ISIS_ADUTest::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    UpdateData(FALSE);

    return 0;
}