// Bezel_5VAC.cpp : implementation file
//

#include "stdafx.h"
#include "Bezel_5VAC.h"
#include "DataStruct.h"
#include "SerialPort.h"



// CBezel_5VAC dialog
extern CSerialPort gCommPort1;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CBezel_5VAC, CDialog)

CBezel_5VAC::CBezel_5VAC(CWnd* pParent /*=NULL*/)
	: CDialog(CBezel_5VAC::IDD, pParent)
	, m_ctlChkKeyKnob(FALSE)
{

}

CBezel_5VAC::~CBezel_5VAC()
{
}

void CBezel_5VAC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BEZ_5VAC, m_ctlChkKeyKnob);
}


BEGIN_MESSAGE_MAP(CBezel_5VAC, CDialog)
	ON_BN_CLICKED(ID_BUT_BEZ_5VAC, &CBezel_5VAC::OnBnClickedButBez5vac)
	ON_BN_CLICKED(ID_BUT_BEZ_5VAC_CONT, &CBezel_5VAC::OnBnClickedButBez5vacCont)
	ON_CBN_SELCHANGE(IDC_COMBO_5VAC, &CBezel_5VAC::OnCbnSelchangeCombo5vac)
	ON_BN_CLICKED(IDC_CHECK_BEZ_5VAC, &CBezel_5VAC::OnBnClickedCheckBez5vac)
END_MESSAGE_MAP()


// CBezel_5VAC message handlers



void CBezel_5VAC::OnBnClickedButBez5vac()
{
	// TODO: Add your control notification handler code here
}


void CBezel_5VAC::OnBnClickedButBez5vacCont()
{
	UpdateData(true);
	
	CMessageBox_Dlg msgdlg;

	if (m_ctlChkKeyKnob)
	{
		m_strBez5VAC.Format("Operational");
		m_strStatusBez5VAC.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("5.05 Brightness Control from bezel (Key SET) Not Operational, Do You want to Continue?");		
		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strBez5VAC.Format("Not Operational");
		m_strStatusBez5VAC.Format("NOT OK");
	}
	
	UpdateData(false);
	OnOK();
}


void CBezel_5VAC::OnCbnSelchangeCombo5vac()
{
	// TODO: Add your control notification handler code here
}


void CBezel_5VAC::OnBnClickedCheckBez5vac()
{
	// TODO: Add your control notification handler code here   
	UpdateData(true);
	
	if (m_ctlChkKeyKnob)
	{
		GetDlgItem(IDC_CHECK_BEZ_5VAC)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_BEZ_5VAC)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}
