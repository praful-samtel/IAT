#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"

// CDialog_SMFD_FC_ANLBP dialog

class CDialog_SMFD_FC_ANLBP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ANLBP)

public:
    CDialog_SMFD_FC_ANLBP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ANLBP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_LBP };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:
    CString m_edt_SMFDFC_LBP;
    CString m_strLhBrake;
    CString m_strStatusLhBrake;

    afx_msg void OnBnClickedButtonSmfdAnalogFclbp();
    afx_msg void OnBnClickedOk();
    afx_msg LRESULT OnUpdateSMFDAnalog(WPARAM wParam, LPARAM lParam);
    afx_msg void OnDestroy();
};