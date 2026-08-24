// DialogSmfd_ADC.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfd_ADC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialogSmfd_ADC dialog

IMPLEMENT_DYNAMIC(CDialogSmfd_ADC, CDialog)

CDialogSmfd_ADC::CDialogSmfd_ADC(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfd_ADC::IDD, pParent)
	, m_edtSmfdArinc203(_T(""))
	, m_edtSmfdArinc205(_T(""))
	, m_edtSmfdArinc206(_T(""))
	, m_edtSmfdArinc212(_T(""))
	, m_edtSmfdArinc213(_T(""))
	, m_edtSmfdArinc210(_T(""))
{

}

CDialogSmfd_ADC::~CDialogSmfd_ADC()
{
}

void CDialogSmfd_ADC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR203, m_edtSmfdArinc203);
	DDX_Text(pDX, IDC_EDIT_SMFDAR205, m_edtSmfdArinc205);
	DDX_Text(pDX, IDC_EDIT_SMFDAR206, m_edtSmfdArinc206);
	DDX_Text(pDX, IDC_EDIT_SMFDAR212, m_edtSmfdArinc212);
	DDX_Text(pDX, IDC_EDIT_SMFDAR213, m_edtSmfdArinc213);
	DDX_Text(pDX, IDC_EDIT_SMFDAR210, m_edtSmfdArinc210);
}


BEGIN_MESSAGE_MAP(CDialogSmfd_ADC, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfd_ADC::OnBnClickedOk)
	
	ON_BN_CLICKED(IDC_BUTTON_SENDARINC_LABEL, &CDialogSmfd_ADC::OnBnClickedButtonSendarincLabel)
END_MESSAGE_MAP()


// CDialogSmfd_ADC message handlers



void CDialogSmfd_ADC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;

	double a1 = atof(m_edtSmfdArinc203);
	double a2 = atof(m_edtSmfdArinc205);
	double a3 = atof(m_edtSmfdArinc206);
	double a4 = atof(m_edtSmfdArinc212);
	double a5 = atof(m_edtSmfdArinc213);
    double a6 = atof(m_edtSmfdArinc210);
	m_strSmfdAdc203 = m_edtSmfdArinc203;
	m_strSmfdAdc205 = m_edtSmfdArinc205;
	m_strSmfdAdc206 = m_edtSmfdArinc206;
	m_strSmfdAdc212 = m_edtSmfdArinc212;
	m_strSmfdAdc213 = m_edtSmfdArinc213;
	m_strSmfdAdc210 = m_edtSmfdArinc210;

	if(a1==5000)
	{
		m_strStatusSmfdAdc203 = "OK";
	}else
	{
		g_strMsgStr = "Altitude value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc203 = "NOT OK";
	}
	/////////////////////////
		if(a2==0.5)
	{
		m_strStatusSmfdAdc205 = "OK";
	}else
	{
		g_strMsgStr = "Mach value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc205 = "NOT OK";
	}

	/////////////////////////
		if(a3==100)
	{
		m_strStatusSmfdAdc206 = "OK";
	}else
	{
		g_strMsgStr = "Airspeed value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc206 = "NOT OK";
	}

	/////////////////////////
		if(a4==1500)
	{
		m_strStatusSmfdAdc212 = "OK";
	}else
	{
		g_strMsgStr = "Altutude Rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc212 = "NOT OK";
	}

	/////////////////////////
		if(a5==25)
	{
		m_strStatusSmfdAdc213 = "OK";
	}else
	{
		g_strMsgStr = "Static Air Temp value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc213 = "NOT OK";
	}

	/////////////////////////
		if(a6==100)
	{
		m_strStatusSmfdAdc210 = "OK";
	}else
	{
		g_strMsgStr = "True Airspeed value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAdc210 = "NOT OK";
	}
	CDialog::OnOK();
}

BOOL CDialogSmfd_ADC::OnInitDialog()
{
	CDialog::OnInitDialog();
#if 0
	// Initialize ARINC 429 if not already done
	if (!InitializeARINC429())
	{
		AfxMessageBox("Failed to initialize ARINC 429! Check hardware connection.");
		EndDialog(IDCANCEL);
		return FALSE;
	}
#endif	
//SetTimer(1, DATA_RD_TIME, NULL);
	//SetTimer(1, TIMER_, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control

	// EXCEPTION: OCX Property Pages should return FALSE
}
void CDialogSmfd_ADC::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(true);
	//SendArincLabel();
	// Read Pitch Angle from ARINC 429 (Label 324)
	unsigned char buffArincReadData[4];
	dataArinc = readArincData(buffArincReadData);
	
	// Display pitch value with 2 decimal places
	// strPichVal.Format("%.2f", dataArinc);
	
	UpdateData(false);


	CDialog::OnTimer(nIDEvent);
}



void CDialogSmfd_ADC::OnBnClickedButtonSendarincLabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edtSmfdArinc203 = "5000";
	m_edtSmfdArinc205 = "0.5";
	m_edtSmfdArinc206 = "100";
	m_edtSmfdArinc212 = "1500";
	m_edtSmfdArinc213 = "25";
	m_edtSmfdArinc210 = "100";
	UpdateData(FALSE);
	//SendArincLabel();
}
