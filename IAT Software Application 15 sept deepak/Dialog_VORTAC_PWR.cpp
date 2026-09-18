// Dialog_VORTAC_PWR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_VORTAC_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Globals.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_VORTAC_PWR dialog

IMPLEMENT_DYNAMIC(CDialog_VORTAC_PWR, CDialog)

CDialog_VORTAC_PWR::CDialog_VORTAC_PWR(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_VORTAC_PWR::IDD, pParent)
	, m_edtVorTac_PWR(_T(""))
{

}

CDialog_VORTAC_PWR::~CDialog_VORTAC_PWR()
{
}

void CDialog_VORTAC_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_VORTAC_PWR, m_edtVorTac_PWR);
}


BEGIN_MESSAGE_MAP(CDialog_VORTAC_PWR, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_VORTAC_PWR::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_VORSYS_PWR, &CDialog_VORTAC_PWR::OnBnClickedButtonVorsysPwr)
END_MESSAGE_MAP()


// CDialog_VORTAC_PWR message handlers


void CDialog_VORTAC_PWR::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// -------- VALIDATION --------


	// -------- STORE VALUE --------
	m_strVORTACCurrent = m_edtVorTac_PWR;

	// -------- SIMPLE CHECK (you can refine later) --------
	double current = atof(m_edtVorTac_PWR);

	if (current <= 3)   // basic validation
	{
		m_strStatusVORTACCurrent = "OK";
	}
	else
	{
		g_strMsgStr = "VOR/ILS TAC Current is invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusVORTACCurrent = "NOT OK";
	}

	CDialog::OnOK();
}


void CDialog_VORTAC_PWR::OnBnClickedButtonVorsysPwr()
{

	 if(g_bSimulationMode)
		{	
		
		CString message;
		CString LRU = "VOR/ILS TACAN";
		FORMAT_CONNECT_LOAD_MSG(message, "VOR/ILS TACAN", VORILS_PWR_PIN_X, VORILS_PWR_PIN_Y, VORILS_PWR_CONNECTOR);

		::MessageBox(AfxGetMainWnd() ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
					 message,
					 "VOR/ILS TACAN PWR",
					 MB_OK | MB_ICONINFORMATION);
	 }


	// TODO: Add your control notification handler code here
	SwitchDiscrete(VOR_ON,ON);
	Sleep(2000);
	double current = ReadPowerSupplyValue('V');
	m_edtVorTac_PWR.Format("%.3f", current);

}
