#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_FP4 dialog

class CDialog_SMFD_FC_FP4 : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_FP4)

public:
    CDialog_SMFD_FC_FP4(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_FP4();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FP4 };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonSmfdAnalogFcfp4();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_edt_SMFDFC_FP4;
    CString m_strflap4v;
    CString m_strStatusflap4v;
};