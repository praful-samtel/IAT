// Dialog_SMFD_FC_ANGEOP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANGEOP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "AnalogOutput.h"
#include "DataStruct.h"
extern CAnalogOutput g_AnalogOutput;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_FC_ANGEOP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_ANGEOP, CDialogEx)

CDialog_SMFD_FC_ANGEOP::CDialog_SMFD_FC_ANGEOP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_ANGEOP::IDD, pParent)
	, m_edt_SMFDFC_EOP(_T(""))
	
{
	
}

CDialog_SMFD_FC_ANGEOP::~CDialog_SMFD_FC_ANGEOP()
{
}

void CDialog_SMFD_FC_ANGEOP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILPRES, m_edt_SMFDFC_EOP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_ANGEOP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCEOP, &CDialog_SMFD_FC_ANGEOP::OnBnClickedButtonSmfdAnalogFceop)
		ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_ANGEOP::OnBnClickedOk)
ON_MESSAGE(WM_UPDATE_SMFD_ANALOG,&CDialog_SMFD_FC_ANGEOP::OnUpdateSMFDAnalog)
ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANGEOP message handlers

BOOL CDialog_SMFD_FC_ANGEOP::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    return TRUE;
}


void CDialog_SMFD_FC_ANGEOP::OnBnClickedButtonSmfdAnalogFceop()
{
    UpdateData(TRUE);

    // Generate Oil Pressure input: 40 mV
    if (!g_AnalogOutput.SetVoltage(0, 0.040))
    {
        AfxMessageBox(
            _T("Failed to generate Oil Pressure voltage.")
        );

        return;
    }

    // Clear previous displayed value
    m_edt_SMFDFC_EOP = _T(" ");
    UpdateData(FALSE);

    // Disable button after successful voltage generation
    CWnd* pButton =
        GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCEOP);

    if (pButton != NULL)
    {
        pButton->EnableWindow(FALSE);
    }

    // Set this dialog as the active ARINC target
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_317
    );
}
void CDialog_SMFD_FC_ANGEOP::OnBnClickedOk()
{

	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	// TODO: Add your control notification handler code here
	  // -------- OIL PRESSURE --------
    val = _tstof(m_edt_SMFDFC_EOP);
    if (val >= 37 && val <= 43)
    {
        m_stroilpressure = m_edt_SMFDFC_EOP;
        m_strStatusoilpressure = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Pressure out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroilpressure = m_edt_SMFDFC_EOP;
        m_strStatusoilpressure = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}

void CDialog_SMFD_FC_ANGEOP::OnDestroy()
{
    // Remove this dialog as the active ARINC target
    ClearSMFDAnalogTarget();

    // Enable simulation button
    CWnd* pButton =
        GetDlgItem(IDC_BUTTON_SMFD_ANALOG_FCEOP);

    if (pButton != NULL)
    {
        pButton->EnableWindow(TRUE);
    }

    // Reset AO0 back to 0 V
    g_AnalogOutput.ResetOutputs();

    CDialogEx::OnDestroy();
}

LRESULT CDialog_SMFD_FC_ANGEOP::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_SMFDFC_EOP.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

