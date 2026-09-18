// Dialog_Smfd_Gps_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Gps_RC.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_Smfd_Gps_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Gps_RC, CDialogEx)

CDialog_Smfd_Gps_RC::CDialog_Smfd_Gps_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Gps_RC::IDD, pParent)
	, m_edt_SmfdRc_GpsGrSp(_T(""))
	, m_edt_SmfdRc_GpsTrTrack(_T(""))
	, m_edt_SmfdRc_GpsMagTrack(_T(""))
	, m_edt_SmfdRc_UtcTime(_T(""))
{

}

CDialog_Smfd_Gps_RC::~CDialog_Smfd_Gps_RC()
{
}

void CDialog_Smfd_Gps_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPSGRSPD_RC, m_edt_SmfdRc_GpsGrSp);
	DDX_Text(pDX, IDC_EDIT_GPSTRUETRACK_RC, m_edt_SmfdRc_GpsTrTrack);
	DDX_Text(pDX, IDC_EDIT_GPSMAGTRACK_RC, m_edt_SmfdRc_GpsMagTrack);
	DDX_Text(pDX, IDC_EDIT_GPSTIME_RC, m_edt_SmfdRc_UtcTime);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Gps_RC, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Gps_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINC_RC, &CDialog_Smfd_Gps_RC::OnBnClickedButtonSendarincRc)
END_MESSAGE_MAP()


// CDialog_Smfd_Gps_RC message handlers





void CDialog_Smfd_Gps_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;

    double grSpd   = atof(m_edt_SmfdRc_GpsGrSp);
    double trueTrk = atof(m_edt_SmfdRc_GpsTrTrack);
    double magTrk  = atof(m_edt_SmfdRc_GpsMagTrack);

    // Store measured values
    m_strSmfdGpsGrSpd      = m_edt_SmfdRc_GpsGrSp;
    m_strSmfdGpsTrueTrack  = m_edt_SmfdRc_GpsTrTrack;
    m_strSmfdGpsMagTrack   = m_edt_SmfdRc_GpsMagTrack;
    m_strSmfdGpsTime       = m_edt_SmfdRc_UtcTime;

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
    if (!m_edt_SmfdRc_UtcTime.IsEmpty())
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
	CDialogEx::OnOK();
}


void CDialog_Smfd_Gps_RC::OnBnClickedButtonSendarincRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_GpsGrSp = "1000";
	m_edt_SmfdRc_GpsTrTrack = "90";
	m_edt_SmfdRc_GpsMagTrack = "90";
	m_edt_SmfdRc_UtcTime = "";
	UpdateData(FALSE);
}
