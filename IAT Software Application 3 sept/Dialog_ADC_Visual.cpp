// Dialog_ADC_Visual.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_Visual.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "SIPU_SDU_GndRig.h"

// CDialog_ADC_Visual dialog
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


IMPLEMENT_DYNAMIC(CDialog_ADC_Visual, CDialog)

CDialog_ADC_Visual::CDialog_ADC_Visual(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_ADC_Visual::IDD, pParent)
	, m_ctlChkADCSRNO(FALSE)
	, m_ctlChkADCDamage(FALSE)
	, m_chkADCScratches(FALSE)
	, m_chkADCScrews(FALSE)
	, m_chkADCPins(FALSE)
	, m_edt_adcPN(_T(""))
	, m_chkADC_marking(TRUE)
{

}

CDialog_ADC_Visual::~CDialog_ADC_Visual()
{
}

void CDialog_ADC_Visual::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ADC_PARTNO, m_ctlChkADCSRNO);
	DDX_Check(pDX, IDC_CHECK_ADC_DAMAGE, m_ctlChkADCDamage);
	DDX_Check(pDX, IDC_CHECK_ADC_SCRATCHES, m_chkADCScratches);
	DDX_Check(pDX, IDC_CHECK_ADC_SCREW, m_chkADCScrews);
	DDX_Check(pDX, IDC_CHECK_ADC_PINS, m_chkADCPins);
	DDX_Text(pDX, IDC_EDIT_ADCPN, m_edt_adcPN);
	DDX_Check(pDX, IDC_CHECK_ADC_PINS2, m_chkADC_marking);
}

BEGIN_MESSAGE_MAP(CDialog_ADC_Visual, CDialog)
	ON_BN_CLICKED(IDC_CHECK_ADC_PARTNO, &CDialog_ADC_Visual::OnBnClickedCheckAdcPartno)
	ON_BN_CLICKED(IDC_CHECK_ADC_DAMAGE, &CDialog_ADC_Visual::OnBnClickedCheckDamage)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_Visual::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_ADC_SCRATCHES, &CDialog_ADC_Visual::OnBnClickedCheckAdcScratches)
	ON_BN_CLICKED(IDC_CHECK_ADC_SCREW, &CDialog_ADC_Visual::OnBnClickedCheckAdcScrew)
	ON_BN_CLICKED(IDC_CHECK_ADC_PINS, &CDialog_ADC_Visual::OnBnClickedCheckAdcPins)
	ON_BN_CLICKED(IDC_CHECK_ADC_PINS2, &CDialog_ADC_Visual::OnBnClickedCheckAdcPins2)
END_MESSAGE_MAP()


// CDialog_ADC_Visual message handlers

void CDialog_ADC_Visual::OnBnClickedOk()
{
	  UpdateData(TRUE);  
	  CMessageBox_Dlg msgdlg;


	  if (m_edt_adcPN.Compare("U104.01.0000 ADC 2601 A HTT1")==0)
	{
		m_strADCSrNo.Format("Correct");
		m_strStatusADCSrNo.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("Part Number is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCSrNo.Format("Not Correct");
		m_strStatusADCSrNo.Format("NOT OK");
	}
		if (!m_ctlChkADCDamage)
	{
		m_strADCDamage.Format("NO");
		m_strStatusADCDamage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format(" ADC Condition is not Satisfactory, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCDamage.Format("YES");
		m_strStatusADCDamage.Format("NOT OK");
	}

		if (!m_chkADCScratches)
	{
		m_strADCScratches.Format("NO");
		m_strStatusADCScratches.Format("OK");
	}
	else
	{
		g_strMsgStr.Format(" ADC unit has Scratches, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCScratches.Format("YES");
		m_strStatusADCScratches.Format("NOT OK");
	}
		///screws
		if (!m_chkADCScrews)
	{
		m_strADCScrews.Format("NO");
		m_strStatusADCScrews.Format("OK");
	}
	else
	{
		g_strMsgStr.Format(" ADC unit has loose screws, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCScrews.Format("YES");
		m_strStatusADCScrews.Format("NOT OK");
	}
		//pins
		if (!m_chkADCPins)
	{
		m_strADCPins.Format("NO");
		m_strStatusADCPins.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("ADC connector has bend pins, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCPins.Format("YES");
		m_strStatusADCPins.Format("NOT OK");
	}

		//markings
			if (m_chkADC_marking)
	{
		m_strADCMarking.Format("YES");
		m_strStatusADCMarking.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("Markings are not present on pressure connectors, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strADCMarking.Format("NO");
		m_strStatusADCMarking.Format("NOT OK");
	}
	UpdateData(FALSE);
	CDialog::OnOK();
}

void CDialog_ADC_Visual::OnBnClickedCheckAdcPartno()
{
	// TODO: Add your control notification handler code here
	
		UpdateData(TRUE);
	
	/*if (!m_ctlChkADCSRNO)
	{
		GetDlgItem(IDC_CHECK_ADC_PARTNO)-> SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_PARTNO)-> SetWindowText("YES");	
	}
*/
	UpdateData(FALSE);
}


void CDialog_ADC_Visual::OnBnClickedCheckDamage()
{	
		UpdateData(TRUE);
		if (!m_ctlChkADCDamage)
	{
		GetDlgItem(IDC_CHECK_ADC_DAMAGE)-> SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_DAMAGE)-> SetWindowText("YES");	
	}

	UpdateData(FALSE);
	
}


void CDialog_ADC_Visual::OnBnClickedCheckAdcScratches()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		if (!m_chkADCScratches)
	{
		GetDlgItem(IDC_CHECK_ADC_SCRATCHES)-> SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_SCRATCHES)-> SetWindowText("YES");	
	}

	UpdateData(FALSE);
}


void CDialog_ADC_Visual::OnBnClickedCheckAdcScrew()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		if (!m_chkADCScrews)
	{
		GetDlgItem(IDC_CHECK_ADC_SCREW)-> SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_SCREW)-> SetWindowText("YES");	
	}

	UpdateData(FALSE);
}


void CDialog_ADC_Visual::OnBnClickedCheckAdcPins()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		if (!m_chkADCPins)
	{
		GetDlgItem(IDC_CHECK_ADC_PINS)-> SetWindowText("NO");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_PINS)-> SetWindowText("YES");	
	}

	UpdateData(FALSE);
}


void CDialog_ADC_Visual::OnBnClickedCheckAdcPins2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
		if (m_chkADC_marking)
	{
		GetDlgItem(IDC_CHECK_ADC_PINS2)-> SetWindowText("YES");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ADC_PINS2)-> SetWindowText("NO");	
	}

	UpdateData(FALSE);
}
