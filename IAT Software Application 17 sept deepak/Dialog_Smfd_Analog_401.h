#pragma once
#include "afxwin.h"
#include "resource.h"

class CDialog_Smfd_Analog_401 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog_401)

public:
	CDialog_Smfd_Analog_401(CWnd* pParent = NULL);
	virtual ~CDialog_Smfd_Analog_401();

	enum { IDD = IDD_DIALOG_SMFD_ANALOG_401 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()

public:
	CString m_edtoiltemp;
	CString m_stroiltemp;
	CString m_strStatusoiltemp;
	afx_msg void OnBnClickedButtonSmfdAnalog();
	afx_msg void OnBnClickedOk();
};
