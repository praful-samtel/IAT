#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_ANEB dialog

class CDialog_SMFD_FC_ANEB : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ANEB)

public:
    CDialog_SMFD_FC_ANEB(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ANEB();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_EB };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonSmfdAnalogFceb();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_edt_SMFDFC_EB;
    CString m_strEmerBrake;
    CString m_strStatusEmerBrake;
};