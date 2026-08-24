// Dialog_SMFD_GPS.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_GPS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

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
END_MESSAGE_MAP()


// CDialog_SMFD_GPS message handlers


void CDialog_SMFD_GPS::OnBnClickedButtonSendarinclabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edtGpsGrSpd = "1000";
	m_edtGpsTrueTrack = "90";
	m_edtGpsMagTrack = "90";
	m_edtGpsTime = "";
	UpdateData(FALSE);
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
