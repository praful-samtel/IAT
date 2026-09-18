#include "stdafx.h"
#include "ProgressDlg.h"

IMPLEMENT_DYNAMIC(CProgressDlg,CDialog)

CProgressDlg::CProgressDlg(CWnd* pParent)
:CDialog(IDD_PROGRESS_DIALOG,pParent)
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);

    DDX_Control(pDX,
                IDC_PROGRESS_STATUS,
                m_Progress);

    DDX_Text(pDX,
             IDC_STATIC_STATUS,
             m_strStatus);
	DDX_Text(pDX,
         IDC_STATIC_PERCENT,
         m_strPercent);
}

BEGIN_MESSAGE_MAP(CProgressDlg,CDialog)
END_MESSAGE_MAP()

BOOL CProgressDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_Progress.SetRange(0,100);

    m_Progress.SetPos(0);

    return TRUE;
}

void CProgressDlg::SetProgress(int nPercent)
{
    m_Progress.SetPos(nPercent);

    m_strPercent.Format("%d%%", nPercent);

    UpdateData(FALSE);
}

void CProgressDlg::SetStatus(CString strStatus)
{
    m_strStatus=strStatus;

    UpdateData(FALSE);
}