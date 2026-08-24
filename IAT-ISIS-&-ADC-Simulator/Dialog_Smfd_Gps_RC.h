#pragma once
#include "resource.h"

// CDialog_Smfd_Gps_RC dialog

class CDialog_Smfd_Gps_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Gps_RC)

public:
	CDialog_Smfd_Gps_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Gps_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_GPS_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edt_SmfdRc_GpsGrSp;
	CString m_edt_SmfdRc_GpsTrTrack;
	CString m_edt_SmfdRc_GpsMagTrack;
	CString m_edt_SmfdRc_UtcTime;
};
