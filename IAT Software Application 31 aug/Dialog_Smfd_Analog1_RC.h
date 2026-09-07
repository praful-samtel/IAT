#pragma once
#include "resource.h"

// CDialog_Smfd_Analog1_RC dialog

class CDialog_Smfd_Analog1_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog1_RC)

public:
	CDialog_Smfd_Analog1_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog1_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG1_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_HyPrMain;
	CString m_edt_SmfdRc_HyPrEm;
	CString m_edt_SmfdRc_EmBr;
	CString m_edt_SmfdRc_LHBr;
	CString m_edt_SmfdRc_RhBr;
	CString m_edt_SmfdRc_EnSpeed;
	CString m_edt_SmfdRc_FuelTankLH;
	CString m_edt_SmfdRc_FuelTankRH;
	CString m_edt_SmfdRc_CoTank;

	afx_msg void OnBnClickedButtonSmfdAnalog();


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
afx_msg void OnBnClickedButtonSmfdAnalogRc();
};
