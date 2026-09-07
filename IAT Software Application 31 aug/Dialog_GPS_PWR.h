#pragma once
#include "resource.h"

// CDialog_GPS_PWR dialog

class CDialog_GPS_PWR : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_GPS_PWR)

public:
	CDialog_GPS_PWR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_GPS_PWR();


// Dialog Data
	enum { IDD = IDD_DIALOG_GPS_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	
	CString m_strGPSCurrent;
	CString m_strStatusGPSCurrent;
	CString m_strGPS28V;
	CString m_strStatusGPS28V;


	afx_msg void OnBnClickedOk();
	CString m_edtGPSVoltage;
	CString m_edtGPSCurrent;
	afx_msg void OnBnClickedButtonGpsPwr();
};
