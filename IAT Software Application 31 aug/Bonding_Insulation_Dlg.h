#pragma once

#include "SIPU_SDU_GndRig.h"
// CBonding_Insulation_Dlg dialog

class CBonding_Insulation_Dlg : public CDialog
{
	DECLARE_DYNAMIC(CBonding_Insulation_Dlg)

public:
	CString m_strMeasuredBondingResistance;
	CString m_strStatusBondingResistance;
	CString m_strMeasuredInsulationResistance;
	CString m_strStatusInsulationResistance;

	CBonding_Insulation_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBonding_Insulation_Dlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_BONDING_INSULATION_RESISTANCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditBonding();
	afx_msg void OnBnClickedOk();
	float m_Edit_fBondingResistance;
	float m_Edit_fInsulationResistance;
};
