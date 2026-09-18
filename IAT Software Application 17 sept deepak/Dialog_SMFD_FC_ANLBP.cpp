// Dialog_SMFD_FC_ANLBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANLBP.h"
#include "afxdialogex.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"

extern CAnalogOutput g_AnalogOutput;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_SMFD_FC_ANLBP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANLBP, CDialogEx)

CDialog_SMFD_FC_ANLBP::CDialog_SMFD_FC_ANLBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANLBP::IDD, pParent)
	, m_edt_SMFDFC_LBP(_T(""))
{

}

CDialog_SMFD_FC_ANLBP::~CDialog_SMFD_FC_ANLBP()
{
}

void CDialog_SMFD_FC_ANLBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LHBRAKE, m_edt_SMFDFC_LBP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANLBP, CDialogEx)

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG_FCLBP,
        &CDialog_SMFD_FC_ANLBP::OnBnClickedButtonSmfdAnalogFclbp
    )

    ON_BN_CLICKED(
        IDOK,
        &CDialog_SMFD_FC_ANLBP::OnBnClickedOk
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_SMFD_FC_ANLBP::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANLBP message handlers


void CDialog_SMFD_FC_ANLBP::OnBnClickedButtonSmfdAnalogFclbp()
{
    UpdateData(TRUE);

    // Generate Left Hand Brake pressure signal
    // AO Channel 10, Voltage 1.88V
    if (!g_AnalogOutput.SetVoltage(10, 1.88))
    {
        AfxMessageBox(_T("Failed to generate Left Hand Brake voltage."));
        return;
    }

    m_edt_SMFDFC_LBP = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCLBP);

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Start monitoring ARINC Label 071
    SetSMFDAnalogTarget(GetSafeHwnd(), LABEL_071);
}


void CDialog_SMFD_FC_ANLBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	  CMessageBox_Dlg msgdlg;
  
    int iValue = _ttoi(m_edt_SMFDFC_LBP);

    // Acceptable range: 1200 ± 15 (1185 to 1215)
    if (iValue >= 1185 && iValue <= 1215)
    { m_strLhBrake = m_edt_SMFDFC_LBP;
        m_strStatusLhBrake = "OK";
    }
    else
    {
        g_strMsgStr = "Flap 3V incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strLhBrake = m_edt_SMFDFC_LBP;
        m_strStatusLhBrake = "NOT OK";
    }

    UpdateData(FALSE);
	CDialogEx::OnOK();
}

LRESULT CDialog_SMFD_FC_ANLBP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_LBP.Format(_T("%.2f"), value);

    UpdateData(FALSE);

    return 0;
}

void CDialog_SMFD_FC_ANLBP::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCLBP);

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}