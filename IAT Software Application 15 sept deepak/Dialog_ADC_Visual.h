#pragma once
#include "SIPU_SDU_GndRig.h"
#include "resource.h"
#include "afxwin.h"
// CDialog_ADC_Visual dialog

class CDialog_ADC_Visual : public CDialog
{
	DECLARE_DYNAMIC(CDialog_ADC_Visual)

public:
	CDialog_ADC_Visual(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ADC_Visual();
	CString m_strADCSrNo;
	CString m_strStatusADCSrNo;
	
	CString m_strADCDamage;
	CString m_strStatusADCDamage;

	CString m_strADCScratches;
	CString m_strStatusADCScratches;
	CString m_strADCScrews;
	CString m_strStatusADCScrews;
	CString m_strADCPins;
	CString m_strStatusADCPins;
	CString m_strADCMarking;
	CString m_strStatusADCMarking;

// Dialog Data
	enum { IDD = IDD_DIALOG_ADC_VISUAl };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_ctlChkADCSRNO;
	BOOL m_ctlChkADCDamage;
	afx_msg void OnBnClickedCheckAdcPartno();
	afx_msg void OnBnClickedCheckDamage();
	afx_msg void OnBnClickedOk();
	BOOL m_chkADCScratches;
	BOOL m_chkADCScrews;
	BOOL m_chkADCPins;
	afx_msg void OnBnClickedCheckAdcScratches();
	afx_msg void OnBnClickedCheckAdcScrew();
	afx_msg void OnBnClickedCheckAdcPins();
	CString m_edt_adcPN;
	afx_msg void OnBnClickedCheckAdcPins2();
	BOOL m_chkADC_marking;
};
