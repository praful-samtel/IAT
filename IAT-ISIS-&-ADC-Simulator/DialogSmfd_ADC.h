#pragma once
#include "resource.h"

// CDialogSmfd_ADC dialog

class CDialogSmfd_ADC : public CDialog
{
	DECLARE_DYNAMIC(CDialogSmfd_ADC)

public:
	CDialogSmfd_ADC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogSmfd_ADC();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ADC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_edtSmfdArinc203;
	CString m_edtSmfdArinc205;
	CString m_edtSmfdArinc206;
	CString m_edtSmfdArinc212;
	CString m_edtSmfdArinc213;
	CString m_edtSmfdArinc210;
	
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
		float dataArinc;
		CString m_strSmfdAdc203;
		CString m_strStatusSmfdAdc203;
		CString m_strSmfdAdc205;
		CString m_strStatusSmfdAdc205;
		CString m_strSmfdAdc206;
		CString m_strStatusSmfdAdc206;
		CString m_strSmfdAdc212;
		CString m_strStatusSmfdAdc212;
		CString m_strSmfdAdc213;
		CString m_strStatusSmfdAdc213;
		CString m_strSmfdAdc210;
		CString m_strStatusSmfdAdc210;

		afx_msg void OnBnClickedButtonSendarincLabel();
};
