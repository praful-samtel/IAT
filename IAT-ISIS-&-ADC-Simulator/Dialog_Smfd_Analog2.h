#pragma once
#include "resource.h"

// CDialog_Smfd_Analog2 dialog

class CDialog_Smfd_Analog2 : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog2)

public:
	CDialog_Smfd_Analog2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog2();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonSmfdAnalog();
	CString m_edt_hydpresmain;
	CString m_edt_hydpresemer;
	CString m_edt_emerbrake;
	CString m_edt_Lhbrake;
	CString m_edt_rhbrake;
	CString m_edt_enginespd;
	CString m_edt_fuelLh;
	CString m_edt_fuelRh;
	CString m_edt_collectortank;
	// -------- HYDRAULIC --------
CString m_strHydPresMain;
CString m_strStatusHydPresMain;

CString m_strHydPresEmer;
CString m_strStatusHydPresEmer;

// -------- BRAKE --------
CString m_strEmerBrake;
CString m_strStatusEmerBrake;

CString m_strLhBrake;
CString m_strStatusLhBrake;

CString m_strRhBrake;
CString m_strStatusRhBrake;

// -------- ENGINE --------
CString m_strEngineSpd;
CString m_strStatusEngineSpd;

// -------- FUEL --------
CString m_strFuelLh;
CString m_strStatusFuelLh;

CString m_strFuelRh;
CString m_strStatusFuelRh;

CString m_strCollectorTank;
CString m_strStatusCollectorTank;
};
