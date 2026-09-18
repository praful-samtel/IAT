// Dialog_SMFD_FC_ANRBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANRBP.h"
#include "afxdialogex.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"
extern CAnalogOutput g_AnalogOutput;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANRBP, CDialogEx)

CDialog_SMFD_FC_ANRBP::CDialog_SMFD_FC_ANRBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANRBP::IDD, pParent)
	, m_edt_SMFDFC_RBP(_T(""))
{

}

CDialog_SMFD_FC_ANRBP::~CDialog_SMFD_FC_ANRBP()
{
}

void CDialog_SMFD_FC_ANRBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RHBRAKE, m_edt_SMFDFC_RBP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANRBP, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCRBP,
        &CDialog_SMFD_FC_ANRBP::OnBnClickedButtonSmfdAnalogFcrbp
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ANRBP::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ANRBP::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANRBP message handlers

void CDialog_SMFD_FC_ANRBP::OnBnClickedButtonSmfdAnalogFcrbp()
{
    UpdateData(TRUE);

    // Generate Right Hand Brake pressure signal
    // AO Channel 11, Voltage 1.88V
    if (!g_AnalogOutput.SetVoltage(11, 1.88))
    {
        AfxMessageBox(_T("Failed to generate Right Hand Brake voltage."));
        return;
    }

    m_edt_SMFDFC_RBP = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCRBP);

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Monitor ARINC Label 072
    SetSMFDAnalogTarget(GetSafeHwnd(), LABEL_072);
}


void CDialog_SMFD_FC_ANRBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	  CMessageBox_Dlg msgdlg;
  
    int iValue = _ttoi(m_edt_SMFDFC_RBP);

    // Acceptable range: 1200 ± 15 (1185 to 1215)
    if (iValue >= 1185 && iValue <= 1215)
    { m_strRhBrake = m_edt_SMFDFC_RBP;
        m_strStatusRhBrake = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strRhBrake = m_edt_SMFDFC_RBP;
        m_strStatusRhBrake = "NOT OK";
    }

    UpdateData(FALSE);
	CDialogEx::OnOK();
}


LRESULT CDialog_SMFD_FC_ANRBP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_RBP.Format(_T("%.2f"), value);

    UpdateData(FALSE);

    return 0;
}


void CDialog_SMFD_FC_ANRBP::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCRBP);

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}