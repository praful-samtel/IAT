#pragma once
#include "resource.h"


// CDialogSIGNAL dialog

class CDialogSIGNAL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogSIGNAL)

public:
	CDialogSIGNAL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogSIGNAL();
	CString m_strGPSSignal;
	CString m_strStatusGPSSignal;

// Dialog Data
	enum { IDD = IDD_DIALOG_GPS_SIGACQ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_ctlChkGPSSignal;
	afx_msg void OnBnClickedCheckGpsSignal();
	afx_msg void OnBnClickedOk();
};
