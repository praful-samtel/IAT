// Dialog_Smfd_Analog_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_Smfd_Analog_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog_RC, CDialogEx)

CDialog_Smfd_Analog_RC::CDialog_Smfd_Analog_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Analog_RC::IDD, pParent)
	, m_edt_SmfdRc_EnOilTemp(_T(""))
	, m_edt_SmfdRc_EnOilPress(_T(""))
	, m_edt_SmfdRc_EnTor(_T(""))
	, m_edt_SmfdRc_RudTrimPos(_T(""))
	, m_edt_SmfdRc_ElevTrimPos(_T(""))
	, m_edt_SmfdRc_AilTrimPos(_T(""))
	, m_edt_SmfdRc_FlPos3V(_T(""))
	, m_edt_SmfdRc_FlapPos4V(_T(""))
	, m_edt_SmfdRc_GenVol(_T(""))
	, m_edt_SmfdRc_Battvol(_T(""))
	, m_edt_SmfdRc_CurrLoad(_T(""))
{

}

CDialog_Smfd_Analog_RC::~CDialog_Smfd_Analog_RC()
{
}

void CDialog_Smfd_Analog_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edt_SmfdRc_EnOilTemp);
	DDX_Text(pDX, IDC_EDIT_OILPRES, m_edt_SmfdRc_EnOilPress);
	DDX_Text(pDX, IDC_EDIT_TORQUE, m_edt_SmfdRc_EnTor);
	DDX_Text(pDX, IDC_EDIT_RUDER, m_edt_SmfdRc_RudTrimPos);
	DDX_Text(pDX, IDC_EDIT_ELEVATOR, m_edt_SmfdRc_ElevTrimPos);
	DDX_Text(pDX, IDC_EDIT_AILERON, m_edt_SmfdRc_AilTrimPos);
	DDX_Text(pDX, IDC_EDIT_FLAT3V, m_edt_SmfdRc_FlPos3V);
	DDX_Text(pDX, IDC_EDIT_FLAP4V, m_edt_SmfdRc_FlapPos4V);
	DDX_Text(pDX, IDC_EDIT_GENERAL_V, m_edt_SmfdRc_GenVol);
	DDX_Text(pDX, IDC_EDIT_BATTERY_VOLT, m_edt_SmfdRc_Battvol);
	DDX_Text(pDX, IDC_EDIT_CURR, m_edt_SmfdRc_CurrLoad);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog_RC::OnBnClickedButtonSmfdAnalog)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog_RC message handlers


void CDialog_Smfd_Analog_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- OIL TEMP --------
    val = _tstof(m_edt_SmfdRc_EnOilTemp);
    if (val >= 58 && val <= 62)
    {
        m_stroiltemp = m_edt_SmfdRc_EnOilTemp;
        m_strStatusoiltemp = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Temperature out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroiltemp = m_edt_SmfdRc_EnOilTemp;
        m_strStatusoiltemp = "NOT OK";
    }

    // -------- OIL PRESSURE --------
    val = _tstof(m_edt_SmfdRc_EnOilPress);
    if (val >= 37 && val <= 43)
    {
        m_stroilpressure = m_edt_SmfdRc_EnOilPress;
        m_strStatusoilpressure = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Pressure out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroilpressure = m_edt_SmfdRc_EnOilPress;
        m_strStatusoilpressure = "NOT OK";
    }

    // -------- TORQUE --------
    val = _tstof(m_edt_SmfdRc_EnTor);
    if (val >= 1736 && val <= 1744)
    {
        m_strtorque = m_edt_SmfdRc_EnTor;
        m_strStatustorque = "OK";
    }
    else
    {
        g_strMsgStr = "Torque invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strtorque = m_edt_SmfdRc_EnTor;
        m_strStatustorque = "NOT OK";
    }

    // -------- RUDDER --------
    if (m_edt_SmfdRc_RudTrimPos.Find("center") != -1)
    {
        m_strrudder = m_edt_SmfdRc_RudTrimPos;
        m_strStatusrudder = "OK";
    }
    else
    {
        g_strMsgStr = "Rudder position incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strrudder = m_edt_SmfdRc_RudTrimPos;
        m_strStatusrudder = "NOT OK";
    }

    // -------- ELEVATOR --------
    if (m_edt_SmfdRc_ElevTrimPos.Find("deg") != -1)
    {
        m_strelevator = m_edt_SmfdRc_ElevTrimPos;
        m_strStatuselevator = "OK";
    }
    else
    {
        g_strMsgStr = "Elevator value incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strelevator = m_edt_SmfdRc_ElevTrimPos;
        m_strStatuselevator = "NOT OK";
    }

    // -------- AILERON --------
    if (m_edt_SmfdRc_AilTrimPos.Find("green") != -1)
    {
        m_straileron = m_edt_SmfdRc_AilTrimPos;
        m_strStatusaileron = "OK";
    }
    else
    {
        g_strMsgStr = "Aileron not in green range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_straileron = m_edt_SmfdRc_AilTrimPos;
        m_strStatusaileron = "NOT OK";
    }

    // -------- FLAP 3V --------
    if (m_edt_SmfdRc_FlPos3V.Find("green") != -1)
    {
        m_strflap3v = m_edt_SmfdRc_FlPos3V;
        m_strStatusflap3v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap3v = m_edt_SmfdRc_FlPos3V;
        m_strStatusflap3v = "NOT OK";
    }

    // -------- FLAP 4V --------
    if (m_edt_SmfdRc_FlapPos4V.Find("yellow") != -1)
    {
        m_strflap4v = m_edt_SmfdRc_FlapPos4V;
        m_strStatusflap4v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 4V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap4v = m_edt_SmfdRc_FlapPos4V;
        m_strStatusflap4v = "NOT OK";
    }

    // -------- GENERATOR VOLTAGE --------
    val = _tstof(m_edt_SmfdRc_GenVol);
    if (val >= 27 && val <= 29)
    {
        m_strgenvolt = m_edt_SmfdRc_GenVol;
        m_strStatusgenvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Generator voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strgenvolt = m_edt_SmfdRc_GenVol;
        m_strStatusgenvolt = "NOT OK";
    }

    // -------- BATTERY VOLTAGE --------
    val = _tstof(m_edt_SmfdRc_Battvol);
    if (val >= 27 && val <= 29)
    {
        m_strbatvolt = m_edt_SmfdRc_Battvol;
        m_strStatusbatvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Battery voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strbatvolt = m_edt_SmfdRc_Battvol;
        m_strStatusbatvolt = "NOT OK";
    }

    // -------- CURRENT LOAD --------
    val = _tstof(m_edt_SmfdRc_CurrLoad);
    if (val >= 190 && val <= 210)
    {
        m_strcurload = m_edt_SmfdRc_CurrLoad;
        m_strStatuscurload = "OK";
    }
    else
    {
        g_strMsgStr = "Current load invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strcurload = m_edt_SmfdRc_CurrLoad;
        m_strStatuscurload = "NOT OK";
    }

    UpdateData(FALSE);

	CDialogEx::OnOK();
}


void CDialog_Smfd_Analog_RC::OnBnClickedButtonSmfdAnalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	    m_edt_SmfdRc_EnOilTemp = "61";
	    m_edt_SmfdRc_EnOilPress = "41";
		m_edt_SmfdRc_EnTor = "1742";
		m_edt_SmfdRc_RudTrimPos = "Nose at center white line";
		m_edt_SmfdRc_ElevTrimPos = "-1.2 deg";
		m_edt_SmfdRc_AilTrimPos = "wing at green line";
		m_edt_SmfdRc_FlPos3V = "Flaps 20 in green";
		m_edt_SmfdRc_FlapPos4V = "Flaps 30 in yellow";
		m_edt_SmfdRc_GenVol = "28";
		m_edt_SmfdRc_Battvol = "28";
		m_edt_SmfdRc_CurrLoad = "202";
	UpdateData(FALSE);
}
