#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_HPE dialog

class CDialog_SMFD_FC_HPE : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_HPE)

public:
    CDialog_SMFD_FC_HPE(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_HPE();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_HPE };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    CString m_edt_SMFDFC_HPE;

    afx_msg void OnBnClickedButtonSmfdAnalogFchpe();
    afx_msg void OnBnClickedOk();

    afx_msg LRESULT OnUpdateSMFDAnalog(
        WPARAM wParam,
        LPARAM lParam
    );

    afx_msg void OnDestroy();

    CString m_strHydPresEmer;
    CString m_strStatusHydPresEmer;
};