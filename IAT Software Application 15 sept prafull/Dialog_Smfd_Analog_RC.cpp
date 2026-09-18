// Dialog_Smfd_Analog_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_Smfd_Analog_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog_RC, CDialogEx)

CDialog_Smfd_Analog_RC::CDialog_Smfd_Analog_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Analog_RC::IDD, pParent)
	, m_edt_SmfdRc_EnOilTemp(_T(""))
	, m_edt_SmfdRc_EnOilPress(_T(""))
	, m_edt_SmfdRc_EnTor(_T(""))
	, m_edt_SmfdRc_RudTrimPos(_T(""))
	, m_edt_SmfdRc_ElevTrimPos(_T(""))
	, m_edt_SmfdRc_AilTrimPos(_T(""))
	, m_edt_SmfdRc_FlPos3V(_T(""))
	, m_edt_SmfdRc_FlapPos4V(_T(""))
	, m_edt_SmfdRc_GenVol(_T(""))
	, m_edt_SmfdRc_Battvol(_T(""))
	, m_edt_SmfdRc_CurrLoad(_T(""))
{

}

CDialog_Smfd_Analog_RC::~CDialog_Smfd_Analog_RC()
{
}

void CDialog_Smfd_Analog_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edt_SmfdRc_EnOilTemp);
	DDX_Text(pDX, IDC_EDIT_OILPRES, m_edt_SmfdRc_EnOilPress);
	DDX_Text(pDX, IDC_EDIT_TORQUE, m_edt_SmfdRc_EnTor);
	DDX_Text(pDX, IDC_EDIT_RUDER, m_edt_SmfdRc_RudTrimPos);
	DDX_Text(pDX, IDC_EDIT_ELEVATOR, m_edt_SmfdRc_ElevTrimPos);
	DDX_Text(pDX, IDC_EDIT_AILERON, m_edt_SmfdRc_AilTrimPos);
	DDX_Text(pDX, IDC_EDIT_FLAT3V, m_edt_SmfdRc_FlPos3V);
	DDX_Text(pDX, IDC_EDIT_FLAP4V, m_edt_SmfdRc_FlapPos4V);
	DDX_Text(pDX, IDC_EDIT_GENERAL_V, m_edt_SmfdRc_GenVol);
	DDX_Text(pDX, IDC_EDIT_BATTERY_VOLT, m_edt_SmfdRc_Battvol);
	DDX_Text(pDX, IDC_EDIT_CURR, m_edt_SmfdRc_CurrLoad);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog_RC::OnBnClickedButtonSmfdAnalog)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog_RC message handlers


void CDialog_Smfd_Analog_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    
    UpdateData(FALSE);

	CDialogEx::OnOK();
}


void CDialog_Smfd_Analog_RC::OnBnClickedButtonSmfdAnalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	    m_edt_SmfdRc_EnOilTemp = "61";
	    m_edt_SmfdRc_EnOilPress = "41";
		m_edt_SmfdRc_EnTor = "1742";
		m_edt_SmfdRc_RudTrimPos = "Nose at center white line";
		m_edt_SmfdRc_ElevTrimPos = "-1.2 deg";
		m_edt_SmfdRc_AilTrimPos = "wing at green line";
		m_edt_SmfdRc_FlPos3V = "Flaps 20 in green";
		m_edt_SmfdRc_FlapPos4V = "Flaps 30 in yellow";
		m_edt_SmfdRc_GenVol = "28";
		m_edt_SmfdRc_Battvol = "28";
		m_edt_SmfdRc_CurrLoad = "202";
	UpdateData(FALSE);
}
