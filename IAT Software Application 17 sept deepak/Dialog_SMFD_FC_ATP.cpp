// Dialog_SMFD_FC_ATP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ATP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

extern CAnalogOutput g_AnalogOutput;


// CDialog_SMFD_FC_ATP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ATP, CDialogEx)

CDialog_SMFD_FC_ATP::CDialog_SMFD_FC_ATP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ATP::IDD, pParent)
	, m_edt_SMFDFC_ATP(_T(""))
{

}

CDialog_SMFD_FC_ATP::~CDialog_SMFD_FC_ATP()
{
}

void CDialog_SMFD_FC_ATP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AILERON, m_edt_SMFDFC_ATP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ATP, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCATP,
        &CDialog_SMFD_FC_ATP::OnBnClickedButtonSmfdAnalogFcatp
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ATP::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ATP::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ATP message handlers


void CDialog_SMFD_FC_ATP::OnBnClickedButtonSmfdAnalogFcatp()
{
    UpdateData(TRUE);

    // Generate Aileron Trim Position voltage
    if (!g_AnalogOutput.SetVoltage(5, 1.60))
    {
        AfxMessageBox(
            _T("Failed to generate Aileron Trim Position voltage.")
        );

        return;
    }

    m_edt_SMFDFC_ATP = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCATP
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Configure ARINC monitoring
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_311
    );
}


void CDialog_SMFD_FC_ATP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	
    //// -------- AILERON --------
    if (m_edt_SMFDFC_ATP.Find("green") != -1)
    {
        m_straileron = m_edt_SMFDFC_ATP;
        m_strStatusaileron = "OK";
    }
    else
    {
        g_strMsgStr = "Aileron not in green range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_straileron = m_edt_SMFDFC_ATP;
        m_strStatusaileron = "NOT OK";
    }

		UpdateData(FALSE);
	CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_ATP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_ATP.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

void CDialog_SMFD_FC_ATP::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCATP
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}