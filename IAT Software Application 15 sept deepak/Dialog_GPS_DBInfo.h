#pragma once
#include "resource.h"
#include "afxwin.h"


// CDialog_GPS_DBInfo dialog

class CDialog_GPS_DBInfo : public CDialog
{
	DECLARE_DYNAMIC(CDialog_GPS_DBInfo)

public:
	CDialog_GPS_DBInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_GPS_DBInfo();

// Dialog Data
	enum { IDD = IDD_DIALOG_GPS_DATAINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chkGPSNavi;
	BOOL m_chkGPSBasemap;	
	BOOL m_chkGPSTerrain;
	BOOL m_chkGPSObstacle;
	BOOL m_chkGPSSafeTaxi;
	CString m_strGPSNavi;
	CString m_strStatusGPSNavi;	
	CString m_strGPSBasemap;
	CString m_strStatusGPSBasemap;	
	CString m_strGPSObstacle;
	CString m_strStatusGPSObstacle;
	CString m_strGPSTerrain;
	CString m_strStatusGPSTerrain;
	CString m_strGPSSafeTaxi;
	CString m_strStatusGPSSafeTaxi;
	afx_msg void OnBnClickedCheckGpsNavi();
	afx_msg void OnBnClickedCheckGpsBasemap();
	afx_msg void OnBnClickedCheckGpsObstacle();
	afx_msg void OnBnClickedCheckGpsSafetaxi();
	afx_msg void OnBnClickedCheckGpsTerrain();
	afx_msg void OnBnClickedOk();
};
