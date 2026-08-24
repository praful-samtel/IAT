#pragma once
#include "resource.h"

// CDialog_Smfd_Analog_RC dialog

class CDialog_Smfd_Analog_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog_RC)

public:
	CDialog_Smfd_Analog_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_EnOilTemp;
	CString m_edt_SmfdRc_EnOilPress;
	CString m_edt_SmfdRc_EnTor;
	CString m_edt_SmfdRc_RudTrimPos;
	CString m_edt_SmfdRc_ElevTrimPos;
	CString m_edt_SmfdRc_AilTrimPos;
	CString m_edt_SmfdRc_FlPos3V;
	//afx_msg void OnEnChangeEditFlat3v();
	CString m_edt_SmfdRc_FlapPos4V;
	CString m_edt_SmfdRc_GenVol;
	CString m_edt_SmfdRc_Battvol;
	CString m_edt_SmfdRc_CurrLoad;
};
