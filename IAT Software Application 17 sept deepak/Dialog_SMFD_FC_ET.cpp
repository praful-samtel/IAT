// Dialog_SMFD_FC_ET.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ET.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "AnalogOutput.h"
#include "DataStruct.h"
extern CAnalogOutput g_AnalogOutput;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_FC_ET dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ET, CDialogEx)

CDialog_SMFD_FC_ET::CDialog_SMFD_FC_ET(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ET::IDD, pParent)
	, m_edt_SMFDFC_ET(_T(""))
{

}

CDialog_SMFD_FC_ET::~CDialog_SMFD_FC_ET()
{
}

void CDialog_SMFD_FC_ET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TORQUE, m_edt_SMFDFC_ET);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ET, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCET,
        &CDialog_SMFD_FC_ET::OnBnClickedButtonSmfdAnalogFcet
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ET::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ET::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ET message handlers


void CDialog_SMFD_FC_ET::OnBnClickedButtonSmfdAnalogFcet()
{
    UpdateData(TRUE);

    // Generate Torque input: 2.00 V
    if (!g_AnalogOutput.SetVoltage(1, 2.00))
    {
        AfxMessageBox(
            _T("Failed to generate Torque voltage.")
        );

        return;
    }

    // Clear previous displayed value
    m_edt_SMFDFC_ET = _T(" ");
    UpdateData(FALSE);

    // Disable simulation button
    CWnd* pButton =
        GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCET);

    if (pButton != NULL)
    {
        pButton->EnableWindow(FALSE);
    }

    // Set this dialog as active ARINC target
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_336
    );
}


void CDialog_SMFD_FC_ET::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

	    // -------- TORQUE --------
    val = _tstof(m_edt_SMFDFC_ET);
    if (val >= 1736 && val <= 1744)
    {
        m_strtorque = m_edt_SMFDFC_ET;
        m_strStatustorque = "OK";
    }
    else
    {
        g_strMsgStr = "Torque invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strtorque = m_edt_SMFDFC_ET;
        m_strStatustorque = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_ET::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_ET.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

void CDialog_SMFD_FC_ET::OnDestroy()
{
    // Clear this dialog as the active ARINC target
    ClearSMFDAnalogTarget();

    // Enable simulation button
    CWnd* pButton =
        GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCET);

    if (pButton != NULL)
    {
        pButton->EnableWindow(TRUE);
    }

    // Reset analog output to 0 V
    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}