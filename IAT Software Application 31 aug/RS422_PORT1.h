#pragma once
#include "SIPU_SDU_GndRig.h"

// CRS422_PORT1 dialog

class CRS422_PORT1 : public CDialog
{
	DECLARE_DYNAMIC(CRS422_PORT1)

public:
	CRS422_PORT1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRS422_PORT1();
	CString m_strRS422P1;
	CString m_strStatusRS422P1;
// Dialog Data
	enum { IDD = IDD_DIALOG_RS422_PORT1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButRs422P1();
	virtual BOOL OnInitDialog();
	CString m_Edit_CRS422_TX1;
	CString m_Edit_CRS422_RX1;
};
