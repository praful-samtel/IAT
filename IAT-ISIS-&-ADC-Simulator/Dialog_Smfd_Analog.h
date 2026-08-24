#pragma once
#include "afxwin.h"
#include "resource.h"

// CDialog_Smfd_Analog dialog

class CDialog_Smfd_Analog : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog)

public:
	CDialog_Smfd_Analog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	CString m_edtoiltemp;
	CString m_edtoilpressure;
	CString m_edttorque;
	CString m_edtrudder;
	CString m_edtelevator;
	CString m_edtaileron;
	CString m_edtflap4v;
	CString m_edtgenvol;
	CString m_edtbattvol;
	CString m_edtcurvol;
	CString m_edtflap3V;
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
	afx_msg void OnBnClickedOk();
};
