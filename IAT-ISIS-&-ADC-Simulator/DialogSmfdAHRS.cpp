// DialogSmfdAHRS.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfdAHRS.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialogSmfdAHRS dialog

IMPLEMENT_DYNAMIC(CDialogSmfdAHRS, CDialog)

CDialogSmfdAHRS::CDialogSmfdAHRS(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfdAHRS::IDD, pParent)
	, m_edtSmfdArinc320(0)
	, m_edtSmfdArinc324(0)
	, m_edtSmfdArinc325(0)
	, m_edtSmfdArinc333(0)
	, m_chkSmfdAhrs330(FALSE)
	, m_chkSmfdAhrs332(FALSE)
{

}

CDialogSmfdAHRS::~CDialogSmfdAHRS()
{
}

void CDialogSmfdAHRS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SMFDAR320, m_edtSmfdArinc320);
	DDX_Text(pDX, IDC_EDIT_SMFDAR324, m_edtSmfdArinc324);
	DDX_Text(pDX, IDC_EDIT_SMFDAR325, m_edtSmfdArinc325);
	DDX_Text(pDX, IDC_EDIT_SMFDAR333, m_edtSmfdArinc333);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS330, m_chkSmfdAhrs330);
	DDX_Check(pDX, IDC_CHECK_SMFD_AHRS332, m_chkSmfdAhrs332);
}


BEGIN_MESSAGE_MAP(CDialogSmfdAHRS, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfdAHRS::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SEND_ARINCLABEL, &CDialogSmfdAHRS::OnBnClickedButtonSendArinclabel)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS330, &CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs330)
	ON_BN_CLICKED(IDC_CHECK_SMFD_AHRS332, &CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs332)
END_MESSAGE_MAP()


// CDialogSmfdAHRS message handlers
void SendArincLabel()
{
 
    // Later you will:
    // Convert to HEX
    // Send via ARINC channel
    // Receive response
}

BOOL CDialogSmfdAHRS::OnInitDialog()
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
//	SetTimer(1, TIMER_, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control

	// EXCEPTION: OCX Property Pages should return FALSE
}
void CDialogSmfdAHRS::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(true);
	SendArincLabel();
	// Read Pitch Angle from ARINC 429 (Label 324)
	unsigned char buffArincReadData[4];
	dataArinc = readArincData(buffArincReadData);
	
	// Display pitch value with 2 decimal places
	// strPichVal.Format("%.2f", dataArinc);
	
	UpdateData(false);


	CDialog::OnTimer(nIDEvent);
}

void CDialogSmfdAHRS::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST
	CMessageBox_Dlg msgdlg;

	if(m_edtSmfdArinc320==60)
	{
		m_strStatusSmfdAhrs320 = "OK";
	}else
	{
		g_strMsgStr = "Heading value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs320 = "NOT OK";
	}
	/////////////////////////
		if(m_edtSmfdArinc324==20)
	{
		m_strStatusSmfdAhrs324 = "OK";
	}else
	{
		g_strMsgStr = "Pitch value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs324 = "NOT OK";
	}

	/////////////////////////
		if(m_edtSmfdArinc325==10)
	{
		m_strStatusSmfdAhrs325 = "OK";
	}else
	{
		g_strMsgStr = "Roll value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs325 = "NOT OK";
	}

	/////////////////////////
		if(m_chkSmfdAhrs330)
	{
		m_strStatusSmfdAhrs330 = "OK";
	}else
	{
		g_strMsgStr = "Body yaw Rate value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs330 = "NOT OK";
	}

	/////////////////////////
		if(m_chkSmfdAhrs332)
	{
		m_strStatusSmfdAhrs332 = "OK";
	}else
	{
		g_strMsgStr = "Lateral Acceleration value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs332 = "NOT OK";
	}

	/////////////////////////
		if(m_edtSmfdArinc333==6)
	{
		m_strStatusSmfdAhrs333 = "OK";
	}else
	{
		g_strMsgStr = "Normal Acceleration value invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusSmfdAhrs333 = "NOT OK";
	}
	CDialog::OnOK();
}


void CDialogSmfdAHRS::OnBnClickedButtonSendArinclabel()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edtSmfdArinc320 = 60;
	m_edtSmfdArinc324 = 20;
	m_edtSmfdArinc325 = 10;
	m_edtSmfdArinc333 = 6;
	UpdateData(FALSE);
}


void CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs330()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chkSmfdAhrs330)
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS330)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS330)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialogSmfdAHRS::OnBnClickedCheckSmfdAhrs332()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chkSmfdAhrs332)
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS332)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SMFD_AHRS332)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}
