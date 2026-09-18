// Dialog_SMFD_FC_FP4.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_FP4.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

extern CAnalogOutput g_AnalogOutput;

// CDialog_SMFD_FC_FP4 dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_FP4, CDialogEx)

CDialog_SMFD_FC_FP4::CDialog_SMFD_FC_FP4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_FP4::IDD, pParent)
	, m_edt_SMFDFC_FP4(_T(""))
{

}

CDialog_SMFD_FC_FP4::~CDialog_SMFD_FC_FP4()
{
}

void CDialog_SMFD_FC_FP4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FLAP4V, m_edt_SMFDFC_FP4);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_FP4, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCFP4,
        &CDialog_SMFD_FC_FP4::OnBnClickedButtonSmfdAnalogFcfp4
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_FP4::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_FP4::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_FP4 message handlers

void CDialog_SMFD_FC_FP4::OnBnClickedButtonSmfdAnalogFcfp4()
{
    UpdateData(TRUE);

    // Generate Flap 4V voltage
    if (!g_AnalogOutput.SetVoltage(6, 4.31))
    {
        AfxMessageBox(
            _T("Failed to generate Flap 4V voltage.")
        );

        return;
    }

    m_edt_SMFDFC_FP4 = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCFP4
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Configure ARINC monitoring
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_137
    );
}


void CDialog_SMFD_FC_FP4::OnBnClickedOk()
{

	    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	// TODO: Add your control notification handler code here
	    //// -------- FLAP 4V --------
    if (m_edt_SMFDFC_FP4.Find("yellow") != -1)
    {
        m_strflap4v = m_edt_SMFDFC_FP4;
        m_strStatusflap4v = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 4V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strflap4v = m_edt_SMFDFC_FP4;
        m_strStatusflap4v = "NOT OK";
    }

		    UpdateData(FALSE);
	CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_FP4::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_FP4.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}
void CDialog_SMFD_FC_FP4::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCFP4
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}