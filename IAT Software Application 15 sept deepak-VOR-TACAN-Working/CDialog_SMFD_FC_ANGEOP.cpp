// Dialog_SMFD_FC_ANGEOP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_ANGEOP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "AnalogOutput.h"
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
END_MESSAGE_MAP()


// CDialog_SMFD_FC_ANGEOP message handlers


void CDialog_SMFD_FC_ANGEOP::OnBnClickedButtonSmfdAnalogFceop()
{
	// TODO: Add your control notification handler code here
	
	 UpdateData(TRUE);
	// g_AnalogOutput.SetVoltage(0,0.040);
	 //read 317 EOP label
	  m_edt_SMFDFC_EOP = "40";


	  UpdateData(FALSE);
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
