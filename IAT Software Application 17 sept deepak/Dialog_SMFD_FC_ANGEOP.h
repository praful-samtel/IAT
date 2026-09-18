#pragma once

#include "resource.h"
#include "SMFDAnalogMonitor.h"
// CDialog_SMFD_FC_ANGEOP dialog

#define WM_UPDATE_EOP    (WM_USER + 101)

class CDialog_SMFD_FC_ANGEOP : public CDialogEx
{
    DECLARE_DYNAMIC(CDialog_SMFD_FC_ANGEOP)

public:
    CDialog_SMFD_FC_ANGEOP(CWnd* pParent = NULL);
    virtual ~CDialog_SMFD_FC_ANGEOP();

    enum { IDD = IDD_DIALOG_SMFD_ANALOG_FC_EOP };


protected:
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

public:

    CString m_edt_SMFDFC_EOP;

    CString m_stroilpressure;
    CString m_strStatusoilpressure;

    afx_msg void OnBnClickedButtonSmfdAnalogFceop();
    afx_msg void OnBnClickedOk();

	afx_msg LRESULT OnUpdateSMFDAnalog(WPARAM wParam, LPARAM lParam);
afx_msg void OnDestroy();
 
	virtual BOOL OnInitDialog();




};