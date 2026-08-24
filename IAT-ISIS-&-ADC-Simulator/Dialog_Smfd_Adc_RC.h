#pragma once
#include "resource.h"

// CDialog_Smfd_Adc_RC dialog

class CDialog_Smfd_Adc_RC : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Adc_RC)

public:
	CDialog_Smfd_Adc_RC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Adc_RC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ADC_RC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_edt_SmfdRc_PressAlti;
	CString m_edt_SmfdRc_MachNum;
	CString m_edt_SmfdRc_CompAirSp;
	CString m_edt_SmfdRc_AltiRate;
	CString m_edt_SmfdRc_StaAirTemp;
	CString m_edt_SmfdRc_TrAirSp;
};
