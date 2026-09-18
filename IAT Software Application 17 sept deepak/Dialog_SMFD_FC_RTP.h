#pragma once
#include "resource.h"
#include "SMFDAnalogMonitor.h"


// CDialog_SMFD_FC_RTP dialog

class CDialog_SMFD_FC_RTP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_RTP)

public:
    CDialog_SMFD_FC_RTP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_RTP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_RTP };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonSmfdAnalogFcrtp();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_edt_SMFDFC_RTP;
    CString m_strrudder;
    CString m_strStatusrudder;
};