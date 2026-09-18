#include "stdafx.h"
#include "Dialog_Smfd_Analog_401.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog_401, CDialogEx)

CDialog_Smfd_Analog_401::CDialog_Smfd_Analog_401(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Analog_401::IDD, pParent)
	, m_edtoiltemp(_T(""))
{
}

CDialog_Smfd_Analog_401::~CDialog_Smfd_Analog_401()
{
}

void CDialog_Smfd_Analog_401::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edtoiltemp);
}

BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog_401, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog_401::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog_401::OnBnClickedButtonSmfdAnalog)
END_MESSAGE_MAP()

void CDialog_Smfd_Analog_401::OnBnClickedButtonSmfdAnalog()
{
	UpdateData(TRUE);
	m_edtoiltemp = "61";
	UpdateData(FALSE);
}

void CDialog_Smfd_Analog_401::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;

    double val = _tstof(m_edtoiltemp);
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
	CDialogEx::OnOK();
}
