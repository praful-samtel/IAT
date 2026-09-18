#pragma once
#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
// CDialog_Smfd_Analog2 dialog

class CDialog_Smfd_Analog2 : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog2)

public:
	CDialog_Smfd_Analog2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog2();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
 afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedButtonSmfdAnalog();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_edt_hydpresmain;

    CString m_strHydPresMain;
    CString m_strStatusHydPresMain;
};
