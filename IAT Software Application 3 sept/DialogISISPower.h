#pragma once


// CDialogISISPower dialog

class CDialogISISPower : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogISISPower)

public:
	CDialogISISPower(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogISISPower();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_PWR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnIsisPwr();
	bool m_ctlChkPwr;
};
