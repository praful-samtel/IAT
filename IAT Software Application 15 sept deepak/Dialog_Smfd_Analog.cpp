// Dialog_Smfd_Analog.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "AnalogOutput.h"
extern CAnalogOutput g_AnalogOutput;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Analog dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog, CDialog)

CDialog_Smfd_Analog::CDialog_Smfd_Analog(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Analog::IDD, pParent)
	, m_edtoiltemp(_T(""))
	
{

}

CDialog_Smfd_Analog::~CDialog_Smfd_Analog()
{
}

void CDialog_Smfd_Analog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edtoiltemp);
	
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog::OnBnClickedButtonSmfdAnalog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog message handlers

BOOL CDialog_Smfd_Analog::OnInitDialog()
{
	CDialog::OnInitDialog();
	if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;
    }
	return TRUE;
}

void CDialog_Smfd_Analog::OnBnClickedButtonSmfdAnalog()
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	//    m_edtoiltemp = "61";
	//   
	//UpdateData(FALSE);
}



void CDialog_Smfd_Analog::OnBnClickedOk()
{
    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- OIL TEMP --------
    val = _tstof(m_edtoiltemp);
    if (val >= 58 && val <= 62)
    {
        m_stroiltemp = m_edtoiltemp;
        m_strStatusoiltemp = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Temperature out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroiltemp = m_edtoiltemp;
        m_strStatusoiltemp = "NOT OK";
    }

      UpdateData(FALSE);

    CDialog::OnOK();
}