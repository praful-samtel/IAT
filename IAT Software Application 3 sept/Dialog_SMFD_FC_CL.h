#pragma once
#include "resource.h"

// CDialog_SMFD_FC_CL dialog

class CDialog_SMFD_FC_CL : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_SMFD_FC_CL)

public:
	CDialog_SMFD_FC_CL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_FC_CL();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG_RC_CL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSmfdAnalogRccl();
};
