#pragma once
#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_ETP dialog

class CDialog_SMFD_FC_ETP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ETP)

public:
    CDialog_SMFD_FC_ETP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ETP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_ETP };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    CString m_edt_SMFDFC_ETP;

    afx_msg void OnBnClickedButtonSmfdAnalogFcetp();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_strelevator;
    CString m_strStatuselevator;
};