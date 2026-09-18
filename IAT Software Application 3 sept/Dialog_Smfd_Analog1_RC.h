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
















afx_msg void OnBnClickedButtonSmfdAnalogRc();
};
