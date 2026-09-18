// Dialog_SMFD_FC_ANEB.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANEB.h"
#include "afxdialogex.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"

extern CAnalogOutput g_AnalogOutput;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANEB, CDialogEx)

CDialog_SMFD_FC_ANEB::CDialog_SMFD_FC_ANEB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANEB::IDD, pParent)
	, m_edt_SMFDFC_EB(_T(""))
{

}

CDialog_SMFD_FC_ANEB::~CDialog_SMFD_FC_ANEB()
{
}

void CDialog_SMFD_FC_ANEB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ACCUMPRES, m_edt_SMFDFC_EB);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANEB, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCEB,
        &CDialog_SMFD_FC_ANEB::OnBnClickedButtonSmfdAnalogFceb
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ANEB::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ANEB::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANEB message handlers

void CDialog_SMFD_FC_ANEB::OnBnClickedButtonSmfdAnalogFceb()
{
    UpdateData(TRUE);

    // Generate Emergency Brake voltage
    if (!g_AnalogOutput.SetVoltage(9, 2.00))
    {
        AfxMessageBox(
            _T("Failed to generate Emergency Brake voltage.")
        );

        return;
    }

    m_edt_SMFDFC_EB = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCEB
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Configure ARINC monitoring
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_070
    );
}


void CDialog_SMFD_FC_ANEB::OnBnClickedOk()
{
    UpdateData(TRUE);
	  CMessageBox_Dlg msgdlg;
  
    int iValue = _ttoi(m_edt_SMFDFC_EB);

    // Acceptable range: 1300 ± 15 (1285 to 1315)
    if (iValue >= 1285 && iValue <= 1315)
    { m_strEmerBrake = m_edt_SMFDFC_EB;
        m_strStatusEmerBrake = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strEmerBrake = m_edt_SMFDFC_EB;
        m_strStatusEmerBrake = "NOT OK";
    }

    UpdateData(FALSE);

    CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_ANEB::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_EB.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}


void CDialog_SMFD_FC_ANEB::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG_FCEB
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}
