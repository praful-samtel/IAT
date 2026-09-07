// Dialog_Smfd_Analog1_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog1_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Analog1_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog1_RC, CDialogEx)

CDialog_Smfd_Analog1_RC::CDialog_Smfd_Analog1_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Analog1_RC::IDD, pParent)
	, m_edt_SmfdRc_HyPrMain(_T(""))
	, m_edt_SmfdRc_HyPrEm(_T(""))
	, m_edt_SmfdRc_EmBr(_T(""))
	, m_edt_SmfdRc_LHBr(_T(""))
	, m_edt_SmfdRc_RhBr(_T(""))
	, m_edt_SmfdRc_EnSpeed(_T(""))
	, m_edt_SmfdRc_FuelTankLH(_T(""))
	, m_edt_SmfdRc_FuelTankRH(_T(""))
	, m_edt_SmfdRc_CoTank(_T(""))
{

}

CDialog_Smfd_Analog1_RC::~CDialog_Smfd_Analog1_RC()
{
}

void CDialog_Smfd_Analog1_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HYDPRESMAIN, m_edt_SmfdRc_HyPrMain);
	DDX_Text(pDX, IDC_EDIT_HYDPRESEMER, m_edt_SmfdRc_HyPrEm);
	DDX_Text(pDX, IDC_EDIT_ACCUMPRES, m_edt_SmfdRc_EmBr);
	DDX_Text(pDX, IDC_EDIT_LHBRAKE, m_edt_SmfdRc_LHBr);
	DDX_Text(pDX, IDC_EDIT_RHBRAKE, m_edt_SmfdRc_RhBr);
	DDX_Text(pDX, IDC_EDIT_ENGSPD, m_edt_SmfdRc_EnSpeed);
	DDX_Text(pDX, IDC_EDIT_LHFUEL, m_edt_SmfdRc_FuelTankLH);
	DDX_Text(pDX, IDC_EDIT_RHFUEL, m_edt_SmfdRc_FuelTankRH);
	DDX_Text(pDX, IDC_EDIT_COLLECTORANK, m_edt_SmfdRc_CoTank);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog1_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog1_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RC, &CDialog_Smfd_Analog1_RC::OnBnClickedButtonSmfdAnalogRc)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog1_RC message handlers


void CDialog_Smfd_Analog1_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    // -------- HYD PRES MAIN --------
    int val = atoi(m_edt_SmfdRc_HyPrMain);
    if (val >= 2910 && val <= 2950)
    {
        m_strHydPresMain = m_edt_SmfdRc_HyPrMain;
        m_strStatusHydPresMain = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Main Pressure not in range, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresMain = m_edt_SmfdRc_HyPrMain;
        m_strStatusHydPresMain = "NOT OK";
    }

    // -------- HYD PRES EMER --------
    val = atoi(m_edt_SmfdRc_HyPrEm);
    if (val >= 3310 && val <= 3350)
    {
        m_strHydPresEmer = m_edt_SmfdRc_HyPrEm;
        m_strStatusHydPresEmer = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Emergency Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresEmer = m_edt_SmfdRc_HyPrEm;
        m_strStatusHydPresEmer = "NOT OK";
    }

    // -------- EMER BRAKE --------
    val = atoi(m_edt_SmfdRc_EmBr);
    if (val >= 1285 && val <= 1315)
    {
        m_strEmerBrake = m_edt_SmfdRc_EmBr;
        m_strStatusEmerBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("Emergency Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strEmerBrake = m_edt_SmfdRc_EmBr;
        m_strStatusEmerBrake = "NOT OK";
    }

    // -------- LH BRAKE --------
    val = atoi(m_edt_SmfdRc_LHBr);
    if (val >= 1185 && val <= 1215)
    {
        m_strLhBrake = m_edt_SmfdRc_LHBr;
        m_strStatusLhBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("LH Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strLhBrake = m_edt_SmfdRc_LHBr;
        m_strStatusLhBrake = "NOT OK";
    }

    // -------- RH BRAKE --------
    val = atoi(m_edt_SmfdRc_RhBr);
    if (val >= 1185 && val <= 1215)
    {
        m_strRhBrake = m_edt_SmfdRc_RhBr;
        m_strStatusRhBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("RH Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strRhBrake = m_edt_SmfdRc_RhBr;
        m_strStatusRhBrake = "NOT OK";
    }

    // -------- ENGINE SPEED --------
    val = atoi(m_edt_SmfdRc_EnSpeed);
    if (val >= 77 && val <= 81)
    {
        m_strEngineSpd = m_edt_SmfdRc_EnSpeed;
        m_strStatusEngineSpd = "OK";
    }
    else
    {
        g_strMsgStr.Format("Engine Speed not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strEngineSpd = m_edt_SmfdRc_EnSpeed;
        m_strStatusEngineSpd = "NOT OK";
    }

    // -------- FUEL LH --------
    val = atoi(m_edt_SmfdRc_FuelTankLH);
    if (val >= 163 && val <= 173)
    {
        m_strFuelLh = m_edt_SmfdRc_FuelTankLH;
        m_strStatusFuelLh = "OK";
    }
    else
    {
        g_strMsgStr.Format("LH Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strFuelLh = m_edt_SmfdRc_FuelTankLH;
        m_strStatusFuelLh = "NOT OK";
    }

    // -------- FUEL RH --------
    val = atoi(m_edt_SmfdRc_FuelTankRH);
    if (val >= 156 && val <= 166)
    {
        m_strFuelRh = m_edt_SmfdRc_FuelTankRH;
        m_strStatusFuelRh = "OK";
    }
    else
    {
        g_strMsgStr.Format("RH Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strFuelRh = m_edt_SmfdRc_FuelTankRH;
        m_strStatusFuelRh = "NOT OK";
    }

    // -------- COLLECTOR TANK --------
    val = atoi(m_edt_SmfdRc_CoTank);
    if (val >= 178 && val <= 188)
    {
        m_strCollectorTank = m_edt_SmfdRc_CoTank;
        m_strStatusCollectorTank = "OK";
    }
    else
    {
        g_strMsgStr.Format("Collector Tank Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strCollectorTank = m_edt_SmfdRc_CoTank;
        m_strStatusCollectorTank = "NOT OK";
    }

	CDialogEx::OnOK();
}





void CDialog_Smfd_Analog1_RC::OnBnClickedButtonSmfdAnalogRc()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
	    m_edt_SmfdRc_HyPrMain = "2940";  //range = 2930±20 
	    m_edt_SmfdRc_HyPrEm = "3340";   // 3330± 20 psi
		m_edt_SmfdRc_EmBr = "1307";   // 1300± 15 psi
		m_edt_SmfdRc_LHBr = "1205"; //1200± 15 psi
		m_edt_SmfdRc_RhBr = "1205"; //1200± 15 psi
		m_edt_SmfdRc_EnSpeed = "80"; //79±2 % rpm
		m_edt_SmfdRc_FuelTankLH = "170"; //168±5 lb
		m_edt_SmfdRc_FuelTankRH = "162"; //168±5 lb
		m_edt_SmfdRc_CoTank = "185";  //183±5 lb
		
	UpdateData(FALSE);
}
