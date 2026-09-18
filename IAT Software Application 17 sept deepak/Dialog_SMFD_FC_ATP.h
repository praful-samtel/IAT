#pragma once
#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_ATP dialog

class CDialog_SMFD_FC_ATP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ATP)

public:
    CDialog_SMFD_FC_ATP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ATP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_ATP };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    CString m_edt_SMFDFC_ATP;

    afx_msg void OnBnClickedButtonSmfdAnalogFcatp();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_straileron;
    CString m_strStatusaileron;
};