#pragma once
#include "resource.h"

// CDialog_GPS_VISUAL dialog

class CDialog_GPS_VISUAL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_GPS_VISUAL)

public:
	CDialog_GPS_VISUAL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_GPS_VISUAL();

// Dialog Data
	enum { IDD = IDD_DIALOG_GPS_VISUAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtGPSPtNo;
	BOOL m_ctlChkGPSDamage;
	afx_msg void OnBnClickedCheckGpsDamage();
	afx_msg void OnBnClickedOk();
	CString m_strGPSPtNo;
	CString m_strStatusGPSPtNo;
	
	CString m_strGPSDamage;
	CString m_strStatusGPSDamage;
	
	CString m_strGPSScratches;
	CString m_strStatusGPSScratches;
	
	CString m_strGPSScrews;
	CString m_strStatusGPSScrews;
	
	CString m_strGPSPins;
	CString m_strStatusGPSPins;
	afx_msg void OnBnClickedCheckSmfdScratches();
	afx_msg void OnBnClickedCheckSmfdScrew();
	afx_msg void OnBnClickedCheckSmfdPins();
	BOOL m_chkGPSScratches;
	BOOL m_chkGPSScrews;
	BOOL m_chkGPSPins;
	afx_msg void OnBnClickedCheckGpsScratches();
	afx_msg void OnBnClickedCheckGpsScrew();
	afx_msg void OnBnClickedCheckGpsPins();
};
