#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_ANRBP dialog

class CDialog_SMFD_FC_ANRBP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ANRBP)

public:
    CDialog_SMFD_FC_ANRBP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ANRBP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_RBP };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    CString m_edt_SMFDFC_RBP;
    CString m_strRhBrake;
    CString m_strStatusRhBrake;

    afx_msg void OnBnClickedButtonSmfdAnalogFcrbp();
    afx_msg void OnBnClickedOk();
    afx_msg LRESULT OnUpdateSMFDAnalog(WPARAM wParam, LPARAM lParam);
    afx_msg void OnDestroy();
};