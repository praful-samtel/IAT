#pragma once
#include "resource.h"

// CDialog_GPS_SYSINFO dialog

class CDialog_GPS_SYSINFO : public CDialog
{
	DECLARE_DYNAMIC(CDialog_GPS_SYSINFO)

public:
	CDialog_GPS_SYSINFO(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_GPS_SYSINFO();

// Dialog Data
	enum { IDD = IDD_DIALOG_GPS_SYSINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtGpsSerialNo;
	CString m_edtGpsSystemId;
	CString m_edtGpsSoftwareVr;
	CString m_edtGpsWaasVr;
	BOOL m_ctlChkGpsSrno;
	BOOL m_ctlChkGpsSysid;
	BOOL m_ctlChkGpsSwVr;
	BOOL m_ctlChkGpsWaasSw;
	CString m_strGpsSrno;
	CString m_strStatusGpsSrno;
	CString m_strGpsSysid;
	CString m_strStatusGpsSysid;
	CString m_strGpsSwVr;
	CString m_strStatusGpsSwVr;
	CString m_strGpsWaasSw;
	CString m_strStatusGpsWaasSw;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckGpsSrNo();
	afx_msg void OnBnClickedCheckGpsSysid();
	afx_msg void OnBnClickedCheckGpsSwvr();
	afx_msg void OnBnClickedCheckGpsWaasSw();
};
