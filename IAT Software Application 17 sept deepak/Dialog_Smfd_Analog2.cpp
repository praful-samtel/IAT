// Dialog_Smfd_Analog2.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog2.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SMFDAnalogMonitor.h"
#include "AnalogOutput.h"
#include "DataStruct.h"	

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

extern CAnalogOutput g_AnalogOutput;

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog2, CDialog)

CDialog_Smfd_Analog2::CDialog_Smfd_Analog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Analog2::IDD, pParent)
	, m_edt_hydpresmain(_T(""))
	
{

}

CDialog_Smfd_Analog2::~CDialog_Smfd_Analog2()
{
}

void CDialog_Smfd_Analog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HYDPRESMAIN, m_edt_hydpresmain);
	
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog2, CDialog)

    ON_BN_CLICKED(
        IDOK,
        &CDialog_Smfd_Analog2::OnBnClickedOk
    )

    ON_BN_CLICKED(
        IDC_BUTTON_SMFD_ANALOG,
        &CDialog_Smfd_Analog2::OnBnClickedButtonSmfdAnalog
    )

    ON_MESSAGE(
        WM_UPDATE_SMFD_ANALOG,
        &CDialog_Smfd_Analog2::OnUpdateSMFDAnalog
    )

    ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDialog_Smfd_Analog2 message handlers


void CDialog_Smfd_Analog2::OnBnClickedOk()
{
    CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    // -------- HYD PRES MAIN --------
    int val = atoi(m_edt_hydpresmain);
    if (val >= 2910 && val <= 2950)
    {
        m_strHydPresMain = m_edt_hydpresmain;
        m_strStatusHydPresMain = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Main Pressure not in range, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresMain = m_edt_hydpresmain;
        m_strStatusHydPresMain = "NOT OK";
    }




    CDialog::OnOK();
}




void CDialog_Smfd_Analog2::OnBnClickedButtonSmfdAnalog()
{
    UpdateData(TRUE);

    // Generate Hydraulic Main Pressure voltage
    if (!g_AnalogOutput.SetVoltage(7, 3.00))
    {
        AfxMessageBox(
            _T("Failed to generate Hydraulic Main Pressure voltage.")
        );

        return;
    }

    m_edt_hydpresmain = _T(" ");
    UpdateData(FALSE);

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG
    );

    if (pButton != NULL)
        pButton->EnableWindow(FALSE);

    // Configure ARINC monitoring
    SetSMFDAnalogTarget(
        GetSafeHwnd(),
        LABEL_S174
    );
}

LRESULT CDialog_Smfd_Analog2::OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
)
{
    UNREFERENCED_PARAMETER(wParam);
    UNREFERENCED_PARAMETER(lParam);

    float value = GetLatestSMFDAnalogValue();

    m_edt_hydpresmain.Format(
        _T("%.2f"),
        value
    );

    UpdateData(FALSE);

    return 0;
}

void CDialog_Smfd_Analog2::OnDestroy()
{
    ClearSMFDAnalogTarget();

    CWnd* pButton = GetDlgItem(
        IDC_BUTTON_SMFD_ANALOG
    );

    if (pButton != NULL)
        pButton->EnableWindow(TRUE);

    g_AnalogOutput.ResetOutputs();

    CDialog::OnDestroy();
}