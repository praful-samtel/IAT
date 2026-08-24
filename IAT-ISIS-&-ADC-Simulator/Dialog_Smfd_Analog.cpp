// Dialog_Smfd_Analog.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Analog dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog, CDialog)

CDialog_Smfd_Analog::CDialog_Smfd_Analog(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Analog::IDD, pParent)
	, m_edtoiltemp(_T(""))
	, m_edtoilpressure(_T(""))
	, m_edttorque(_T(""))
	, m_edtrudder(_T(""))
	, m_edtelevator(_T(""))
	, m_edtaileron(_T(""))
	, m_edtflap4v(_T(""))
	, m_edtgenvol(_T(""))
	, m_edtbattvol(_T(""))
	, m_edtcurvol(_T(""))
	, m_edtflap3V(_T(""))
{

}

CDialog_Smfd_Analog::~CDialog_Smfd_Analog()
{
}

void CDialog_Smfd_Analog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edtoiltemp);
	DDX_Text(pDX, IDC_EDIT_OILPRES, m_edtoilpressure);
	DDX_Text(pDX, IDC_EDIT_TORQUE, m_edttorque);
	DDX_Text(pDX, IDC_EDIT_RUDER, m_edtrudder);
	DDX_Text(pDX, IDC_EDIT_ELEVATOR, m_edtelevator);
	DDX_Text(pDX, IDC_EDIT_AILERON, m_edtaileron);
	DDX_Text(pDX, IDC_EDIT_FLAP4V, m_edtflap4v);
	DDX_Text(pDX, IDC_EDIT_GENERAL_V, m_edtgenvol);
	DDX_Text(pDX, IDC_EDIT_BATTERY_VOLT, m_edtbattvol);
	DDX_Text(pDX, IDC_EDIT_CURR, m_edtcurvol);
	DDX_Text(pDX, IDC_EDIT_FLAT3V, m_edtflap3V);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog::OnBnClickedButtonSmfdAnalog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog message handlers



void CDialog_Smfd_Analog::OnBnClickedButtonSmfdAnalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	    m_edtoiltemp = "61";
	    m_edtoilpressure = "41";
		m_edttorque = "1742";
		m_edtrudder = "Nose at center white line";
		m_edtelevator = "-1.2 deg";
		m_edtaileron = "wing at green line";
		m_edtflap3V = "Flaps 20 in green";
		m_edtflap4v = "Flaps 30 in yellow";
		m_edtgenvol = "28";
		m_edtbattvol = "28";
		m_edtcurvol = "202";
	UpdateData(FALSE);
}



void CDialog_Smfd_Analog::OnBnClickedOk()
{
    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- OIL TEMP --------
    val = _tstof(m_edtoiltemp);
    if (val >= 58 && val <= 62)
    {
        m_stroiltemp = m_edtoiltemp;
        m_strStatusoiltemp = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Temperature out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroiltemp = m_edtoiltemp;
        m_strStatusoiltemp = "NOT OK";
    }

    // -------- OIL PRESSURE --------
    val = _tstof(m_edtoilpressure);
    if (val >= 37 && val <= 43)
    {
        m_stroilpressure = m_edtoilpressure;
        m_strStatusoilpressure = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Pressure out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroilpressure = m_edtoilpressure;
        m_strStatusoilpressure = "NOT OK";
    }

    // -------- TORQUE --------
    val = _tstof(m_edttorque);
    if (val >= 1736 && val <= 1744)
    {
        m_strtorque = m_edttorque;
        m_strStatustorque = "OK";
    }
    else
    {
        g_strMsgStr = "Torque invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strtorque = m_edttorque;
        m_strStatustorque = "NOT OK";
    }

    // -------- RUDDER --------
    if (m_edtrudder.Find("center") != -1)
    {
        m_strrudder = m_edtrudder;
        m_strStatusrudder = "OK";
    }
    else
    {
        g_strMsgStr = "Rudder position incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strrudder = m_edtrudder;
        m_strStatusrudder = "NOT OK";
    }

    // -------- ELEVATOR --------
    if (m_edtelevator.Find("deg") != -1)
    {
        m_strelevator = m_edtelevator;
        m_strStatuselevator = "OK";
    }
    else
    {
        g_strMsgStr = "Elevator value incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strelevator = m_edtelevator;
        m_strStatuselevator = "NOT OK";
    }

    // -------- AILERON --------
    if (m_edtaileron.Find("green") != -1)
    {
        m_straileron = m_edtaileron;
        m_strStatusaileron = "OK";
    }
    else
    {
        g_strMsgStr = "Aileron not in green range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_straileron = m_edtaileron;
        m_strStatusaileron = "NOT OK";
    }

    // -------- FLAP 3V --------
    if (m_edtflap3V.Find("green") != -1)
    {
        m_strflap3v = m_edtflap3V;
        m_strStatusflap3v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap3v = m_edtflap3V;
        m_strStatusflap3v = "NOT OK";
    }

    // -------- FLAP 4V --------
    if (m_edtflap4v.Find("yellow") != -1)
    {
        m_strflap4v = m_edtflap4v;
        m_strStatusflap4v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 4V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap4v = m_edtflap4v;
        m_strStatusflap4v = "NOT OK";
    }

    // -------- GENERATOR VOLTAGE --------
    val = _tstof(m_edtgenvol);
    if (val >= 27 && val <= 29)
    {
        m_strgenvolt = m_edtgenvol;
        m_strStatusgenvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Generator voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strgenvolt = m_edtgenvol;
        m_strStatusgenvolt = "NOT OK";
    }

    // -------- BATTERY VOLTAGE --------
    val = _tstof(m_edtbattvol);
    if (val >= 27 && val <= 29)
    {
        m_strbatvolt = m_edtbattvol;
        m_strStatusbatvolt = "OK";
    }
    else
    {
        g_strMsgStr = "Battery voltage out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strbatvolt = m_edtbattvol;
        m_strStatusbatvolt = "NOT OK";
    }

    // -------- CURRENT LOAD --------
    val = _tstof(m_edtcurvol);
    if (val >= 190 && val <= 210)
    {
        m_strcurload = m_edtcurvol;
        m_strStatuscurload = "OK";
    }
    else
    {
        g_strMsgStr = "Current load invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strcurload = m_edtcurvol;
        m_strStatuscurload = "NOT OK";
    }

    UpdateData(FALSE);

    CDialog::OnOK();
}