// Dialog_SMFD_FC_ETP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ETP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

extern CAnalogOutput g_AnalogOutput;


// CDialog_SMFD_FC_ETP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ETP, CDialogEx)

CDialog_SMFD_FC_ETP::CDialog_SMFD_FC_ETP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ETP::IDD, pParent)
	, m_edt_SMFDFC_ETP(_T(""))
{

}

CDialog_SMFD_FC_ETP::~CDialog_SMFD_FC_ETP()
{
}

void CDialog_SMFD_FC_ETP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ELEVATOR, m_edt_SMFDFC_ETP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ETP, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCETP,
        &CDialog_SMFD_FC_ETP::OnBnClickedButtonSmfdAnalogFcetp
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ETP::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ETP::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ETP message handlers


void CDialog_SMFD_FC_ETP::OnBnClickedButtonSmfdAnalogFcetp()
{
    UpdateData(TRUE);

    // Generate Elevator Trim Position voltage
    if (!g_AnalogOutput.SetVoltage(4, 1.60))
    {
        AfxMessageBox(
            _T("Failed to generate Elevator Trim Position voltage.")
        );

        return;
    }

    m_edt_SMFDFC_ETP = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCETP
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Configure ARINC monitoring
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_315
    );
}


void CDialog_SMFD_FC_ETP::OnBnClickedOk()
{

	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	// TODO: Add your control notification handler code here
	  //// -------- ELEVATOR --------
    if (m_edt_SMFDFC_ETP.Find("green") != -1)
    {
        m_strelevator = m_edt_SMFDFC_ETP;
        m_strStatuselevator = "OK";
    }
    else
    {
        g_strMsgStr = "Elevator value incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strelevator = m_edt_SMFDFC_ETP;
        m_strStatuselevator = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_ETP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_ETP.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

void CDialog_SMFD_FC_ETP::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCETP
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}