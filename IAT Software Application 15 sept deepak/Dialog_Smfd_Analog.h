#pragma once
#include "afxwin.h"
#include "resource.h"
#include "DataStruct.h"
// CDialog_Smfd_Analog dialog

class CDialog_Smfd_Analog : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog)

public:
	CDialog_Smfd_Analog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	CString m_edtoiltemp;
	CString m_stroiltemp;
	CString m_strStatusoiltemp;


	afx_msg void OnBnClickedButtonSmfdAnalog();
	afx_msg void OnBnClickedOk();
};
