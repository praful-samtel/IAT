#pragma once

#include "SIPU_SDU_GndRig.h"
// CRS422_Port2 dialog

class CRS422_Port2 : public CDialog
{
	DECLARE_DYNAMIC(CRS422_Port2)

public:
	CRS422_Port2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRS422_Port2();
	CString m_strRS422P2;
	CString m_strStatusRS422P2;
// Dialog Data
	enum { IDD = IDD_DIALOG_RS422_PORT2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButRs422P2();
	virtual BOOL OnInitDialog();
	CString m_Edit_CRS422_RX2;
	CString m_Edit_CRS422_TX2;
};
