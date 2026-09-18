#pragma once
#include "resource.h"

// CDialogStop dialog

class CDialogStop : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogStop)

public:
	CDialogStop(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogStop();

// Dialog Data
	enum { IDD = IDD_DIALOG_STOP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStop();
};
