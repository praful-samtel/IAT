// Bez_5VDC.cpp : implementation file
//

#include "stdafx.h"
#include "Bez_5VDC.h"
#include "DataStruct.h"
#include "SerialPort.h"



// CBez_5VDC dialog
extern CSerialPort gCommPort1;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC(CBez_5VDC, CDialog)

CBez_5VDC::CBez_5VDC(CWnd* pParent /*=NULL*/)
	: CDialog(CBez_5VDC::IDD, pParent)
	, m_ctlChk5VDC(FALSE)
{

}

CBez_5VDC::~CBez_5VDC()
{
}

void CBez_5VDC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Combo5VDC);
	DDX_Check(pDX, IDC_CHECK_BEZ_5VDC, m_ctlChk5VDC);
}


BEGIN_MESSAGE_MAP(CBez_5VDC, CDialog)
	
	ON_BN_CLICKED(ID_BUT_BEZ_5VDC, &CBez_5VDC::OnBnClickedButBez5vdc)
	ON_BN_CLICKED(ID_BUT_BEZ_5VDC_CONT, &CBez_5VDC::OnBnClickedButBez5vdcCont)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CBez_5VDC::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK_BEZ_5VDC, &CBez_5VDC::OnBnClickedCheckBez5vdc)
END_MESSAGE_MAP()


// CBez_5VDC message handlers



void CBez_5VDC::OnBnClickedButBez5vdc()
{
	// TODO: Add your control notification handler code here
}


void CBez_5VDC::OnBnClickedButBez5vdcCont()
{
	CMessageBox_Dlg msgdlg;

	if (m_ctlChk5VDC)
	{
		m_strBez5VDC.Format("Operational");
		m_strStatusBez5VDC.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("5.04 Bezel Lighting at 0-5 VDC Not Operational, Do You want to Continue?");		
		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strBez5VDC.Format("Not Operational");
		m_strStatusBez5VDC.Format("NOT OK");
	}
	
	UpdateData(false);
	OnOK();
}


void CBez_5VDC::OnCbnSelchangeCombo1()
{
	////    m_Combo5VDC
	//if (m_Combo5VDC== 0)
	{

	}

}


void CBez_5VDC::OnBnClickedCheckBez5vdc()
{
	// TODO: Add your control notification handler code here  m_ctlChk5VDC
	UpdateData(true);
	if (m_ctlChk5VDC)
	{
		GetDlgItem(IDC_CHECK_BEZ_5VDC)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_BEZ_5VDC)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}
