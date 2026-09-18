#pragma once
#include "resource.h"

class CProgressDlg : public CDialog
{
    DECLARE_DYNAMIC(CProgressDlg)

public:

    CProgressDlg(CWnd* pParent = NULL);
	CString m_strPercent;
    enum { IDD = IDD_PROGRESS_DIALOG };
	
    virtual BOOL OnInitDialog();

    void SetProgress(int Percent);

    void SetStatus(CString strStatus);

protected:

    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

private:

    CProgressCtrl m_Progress;

    CString m_strStatus;
};