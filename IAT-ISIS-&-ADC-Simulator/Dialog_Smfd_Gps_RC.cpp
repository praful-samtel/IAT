// Dialog_Smfd_Gps_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Gps_RC.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CDialog_Smfd_Gps_RC message handlers
