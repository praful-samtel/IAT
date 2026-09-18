// DialogSmfd_Tacan.cpp : implementation file
//

#include "stdafx.h"
#include "DialogSmfd_Tacan.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"
#include <string>
#include "Arinc429.h"
#include "Globals.h"
extern CSerialPort gCommPort1;

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialogSmfd_Tacan dialog

IMPLEMENT_DYNAMIC(CDialogSmfd_Tacan, CDialog)

CDialogSmfd_Tacan::CDialogSmfd_Tacan(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSmfd_Tacan::IDD, pParent)
	, m_edtTac201(0)
	, m_edtTac222(0)
	, m_chk_TacanWord(FALSE)
	, m_bThreadRunning(FALSE)
{

}

CDialogSmfd_Tacan::~CDialogSmfd_Tacan()
{
}

void CDialogSmfd_Tacan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_TAC201, m_edtTac201);
	DDX_Text(pDX, IDC_EDIT_TAC222, m_edtTac222);
	DDX_Check(pDX, IDC_CHECK_TACWORD, m_chk_TacanWord);
}


BEGIN_MESSAGE_MAP(CDialogSmfd_Tacan, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogSmfd_Tacan::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SENDARINCLABEL, &CDialogSmfd_Tacan::OnBnClickedButtonSendarinclabel)
	ON_BN_CLICKED(IDC_CHECK_TACWORD, &CDialogSmfd_Tacan::OnBnClickedCheckTacword)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialogSmfd_Tacan message handlers
LRESULT CDialogSmfd_Tacan::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
	UpdateData(FALSE);
	return 0;
}


void CDialogSmfd_Tacan::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);//  MUST
	CMessageBox_Dlg msgdlg;

	m_strtac201.Format("%d", m_edtTac201);
	m_strtac222.Format("%d", m_edtTac222);

	if(m_chk_TacanWord)
	{  
		m_strtac145 = "Displayed";
		m_strStatustac145 = "OK";
	}else
	{
		g_strMsgStr = "TACAN control word invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strtac145 = "Not Displayed";
		m_strStatustac145 = "NOT OK";
	}

	if(m_strtac201=="300")
	{
		m_strStatustac201 = "OK";
	}else
	{
		g_strMsgStr = "TACAN Distance invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatustac201 = "NOT OK";
	}
	if(m_strtac222=="90")
	{
		m_strStatustac222 = "OK";
	}else
	{
		g_strMsgStr = "TACAN Distance invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatustac222 = "NOT OK";
	}

	UpdateData(FALSE);
	CDialog::OnOK();
}


void CDialogSmfd_Tacan::OnBnClickedButtonSendarinclabel()
{
	TRACE("m_bThreadRunning ::: %d",m_bThreadRunning);
	// TODO: Add your control notification handler code here
	if (m_bThreadRunning)
		return;
	TRACE(" On Button Click Send Arinc Label Simulation Mode On :::: ");
	InitArincRX(9); //change

	m_bStopThread = FALSE;
	m_bThreadRunning = TRUE;

	m_pArincRXThread = AfxBeginThread(
		ArincRXThread,
		this,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);

	if (m_pArincRXThread == NULL)
	{
		m_bThreadRunning = FALSE;
		AfxMessageBox("Unable to start ARINC RX thread.");
		return;
	}

	m_pArincRXThread->m_bAutoDelete = FALSE;
	m_pArincRXThread->ResumeThread();
}

UINT CDialogSmfd_Tacan::ArincRXThread(LPVOID pParam)
{
	CDialogSmfd_Tacan* pDlg = (CDialogSmfd_Tacan*)pParam;

	if (pDlg != NULL)
	{
		pDlg->ExecuteArincRX();
		pDlg->m_bThreadRunning = FALSE;
	}

	return 0;
}



void CDialogSmfd_Tacan::ExecuteArincRX()
{
	float value = 0.0f;
	while (!m_bStopThread)
	{

        ADT_L0_UINT32 Labels[3];
        int labelCount = 0;

		Labels[0] = 0x460C21A6;   // LABEL_145, TACAN Channel 12, X-mode, Air-to-Ground
		Labels[1] = 0xF8000081;   // LABEL_201, TACAN Distance 300 Nm
		Labels[2] = 0xE8000049;   // LABEL_222, TACAN Bearing 90 deg

		gArinc429.SendLabels(3, Labels, 3);
		
		if(g_bSimulationMode) 
		{
			TRACE("Simulation Mode On CDialogSmfd_Tacan::ExecuteArincRX ::::::::::::::: Sending DATA ");
		
			ReadVorIlsTacanRX(9);

			if (GetARINCValue(9, LABEL_145, &value))
                    m_chk_TacanWord = (value == 1.0f) ? TRUE : FALSE;   // 1 = ILS-tuned confirmed

                if (GetARINCValue(9, LABEL_201, &value))
                {
                    m_edtTac201 = (int)value;
                }

                if (GetARINCValue(9, LABEL_222, &value))
                {
                    m_edtTac222 = (int)value;
                }
		}
		else
		{
			gArinc429.SendLabels(4, Labels, 6); //SMFD
			//Send same data to SMFD & MFD FC to reflect data on SMFD
		}
		PostMessage(WM_UPDATE_ARINC);

		Sleep(100);
	}
}

void CDialogSmfd_Tacan::OnBnClickedCheckTacword()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

   if (m_chk_TacanWord)
	{
		GetDlgItem(IDC_CHECK_TACWORD)->SetWindowText("Displayed");
	}
	else
	{
		GetDlgItem(IDC_CHECK_TACWORD)->SetWindowText("Not Displayed");
	}
    UpdateData(FALSE);
}

void CDialogSmfd_Tacan::OnDestroy()
{
	m_bStopThread = TRUE;

	if (m_pArincRXThread != NULL)
	{
		WaitForSingleObject(m_pArincRXThread->m_hThread, INFINITE);
		delete m_pArincRXThread;
		m_pArincRXThread = NULL;
	}

	m_bThreadRunning = FALSE;

	CloseRx(8);

	CDialog::OnDestroy();
}
