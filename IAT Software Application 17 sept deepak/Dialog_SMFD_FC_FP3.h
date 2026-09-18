#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_FP3 dialog

class CDialog_SMFD_FC_FP3 : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_FP3)

public:
    CDialog_SMFD_FC_FP3(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_FP3();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_FP3 };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonSmfdAnalogFcfp3();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_strflap3v;
    CString m_strStatusflap3v;
    CString m_edt_SMFDFC_FP3;
};