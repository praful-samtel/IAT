// Dialog_SMFD_FC_RTP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_RTP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "AnalogOutput.h"
#include "DataStruct.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

extern CAnalogOutput g_AnalogOutput;


// CDialog_SMFD_FC_RTP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_RTP, CDialogEx)

CDialog_SMFD_FC_RTP::CDialog_SMFD_FC_RTP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_RTP::IDD, pParent)
	, m_edt_SMFDFC_RTP(_T(""))
{

}

CDialog_SMFD_FC_RTP::~CDialog_SMFD_FC_RTP()
{
}

void CDialog_SMFD_FC_RTP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RUDER, m_edt_SMFDFC_RTP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_RTP, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCRTP,
        &CDialog_SMFD_FC_RTP::OnBnClickedButtonSmfdAnalogFcrtp
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_RTP::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_RTP::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_RTP message handlers


void CDialog_SMFD_FC_RTP::OnBnClickedButtonSmfdAnalogFcrtp()
{
    UpdateData(TRUE);

    // Generate Rudder Trim Position voltage
    if (!g_AnalogOutput.SetVoltage(0, 1.25))
    {
        AfxMessageBox(
            _T("Failed to generate Rudder Trim Position voltage.")
        );

        return;
    }

    m_edt_SMFDFC_RTP = _T("");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCRTP
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Replace LABEL_RUDDER with the actual ARINC label
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_313
    );
}

void CDialog_SMFD_FC_RTP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	    //// -------- RUDDER --------
    if (m_edt_SMFDFC_RTP.Find("center") != -1)
    {
        m_strrudder = m_edt_SMFDFC_RTP;
        m_strStatusrudder = "OK";
    }
    else
    {
        g_strMsgStr = "Rudder position incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strrudder = m_edt_SMFDFC_RTP;
        m_strStatusrudder = "NOT OK";
    }

	 UpdateData(FALSE);
	CDialogEx::OnOK();
}


LRESULT CDialog_SMFD_FC_RTP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_RTP.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

void CDialog_SMFD_FC_RTP::OnDestroy()
{
    // Clear this dialog as the active analog target
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCRTP
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    // Reset analog output
    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}