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



	CString m_stroiltemp;
	CString m_strStatusoiltemp;
	CString m_stroilpressure;
	CString m_strStatusoilpressure;
	CString m_strtorque;
	CString m_strStatustorque;
	CString m_strrudder;
	CString m_strStatusrudder;
	CString m_strelevator;
	CString m_strStatuselevator;
	CString m_straileron;
	CString m_strStatusaileron;
	CString m_strflap3v;
	CString m_strStatusflap3v;
	CString m_strflap4v;
	CString m_strStatusflap4v;
	CString m_strgenvolt;
	CString m_strStatusgenvolt;
	CString m_strbatvolt;
	CString m_strStatusbatvolt;
	CString m_strcurload;
	CString m_strStatuscurload;
	afx_msg void OnBnClickedButtonSmfdAnalog();

};
