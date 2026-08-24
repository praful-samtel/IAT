#pragma once
#include "SIPU_SDU_GndRig.h"
#include "afxwin.h"

// VisualInspection dialog

class VisualInspection : public CDialog
{
	DECLARE_DYNAMIC(VisualInspection)

public:
	VisualInspection(CWnd* pParent = NULL);   // standard constructor
	virtual ~VisualInspection();
  
	CString m_strProductLabel;
	CString m_strStatusProductLabel;

	CString m_strProductLabelRC;
	CString m_strStatusProductLabelRC;
	
	CString m_strSrNoLabel;
	CString m_strStatusSrNoLabel;
	
	CString m_strManufacturingLabel;
	CString m_strStatusManufacturingLabel;
	
	CString m_strESDLabel;
	CString m_strStatusESDLabel;
	
	CString m_strAmendmentLabel;
	CString m_strStatusAmendmentLabel;
	
	CString m_strRearMarking;
	CString m_strStatusRearMarking;
	
	CString m_strRearPins;
	CString m_strStatusRearPins;
	
	CString m_strKeypadMarking;
	CString m_strStatusKeypadMarking;
	
	CString m_strFinish;
	CString m_strStatusFinish;

	CString m_strISISDamage;
	CString m_strStatusISISDamage;

	CString m_strISISScratches;
	CString m_strStatusISISScratches;

	CString m_strISISScrews;
	CString m_strStatusISISScrews;

	CString m_strISISPins;
	CString m_strStatusISISPins;
	


// Dialog Data
	enum { IDD = IDD_DIALOG_VISUAL_INSPECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOK();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheckProductLabel();
	BOOL m_ctlChkProductLabel;
	afx_msg void OnBnClickedCheckSrnoLabel();
	BOOL m_ctlChkSrNoLabel;
	BOOL m_ctlChkManufacturingLabel;
	afx_msg void OnBnClickedCheckEsdLabel();
	BOOL m_ctlChkESDLabel;
	afx_msg void OnBnClickedCheckAmdenmentLabel();
	BOOL m_ctlChkAmendmentLabel;
	BOOL m_ctlChkRearMarking;
	afx_msg void OnBnClickedCheckRearMarking();
	afx_msg void OnBnClickedCheckRearPins();
	BOOL m_ctlChkRearPins;
	afx_msg void OnBnClickedCheckKeypadMarking();
	BOOL m_ctlChkKeypadMarking;
	afx_msg void OnBnClickedCheckFinish();
	BOOL m_ctlCheckFinish;
	afx_msg void OnBnClickedCheckManfDateLabel();
	virtual BOOL OnInitDialog();
	BOOL m_chkISISdamage;
	BOOL m_chkISISscratches;
	BOOL m_chkISISPins;
	
	BOOL m_chkISISScrews;
	
	CString m_str_isisDUPN;
	CString m_strisisADUPN;
	CString m_strisisMMSPN;
	CString m_strisisAHRSPN;
	CString m_str_isisDUPNRC;
	BOOL m_chkISISdamage2;
	BOOL m_chkISISscratches2;
	BOOL m_chkISISPins2;
	BOOL m_chkISISScrews2;
};
