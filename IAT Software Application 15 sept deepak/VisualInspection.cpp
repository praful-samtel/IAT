// VisualInspection.cpp : implementation file
//

#include "stdafx.h"
#include "VisualInspection.h"
#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// VisualInspection dialog

IMPLEMENT_DYNAMIC(VisualInspection, CDialog)

VisualInspection::VisualInspection(CWnd* pParent /*=NULL*/)
	: CDialog(VisualInspection::IDD, pParent)
	, m_chkISISdamage(FALSE)
	, m_chkISISscratches(FALSE)
	, m_chkISISPins(FALSE)
	, m_chkISISScrews(FALSE)
	, m_str_isisDUPN(_T(""))
	, m_strisisADUPN(_T(""))
	, m_strisisMMSPN(_T(""))
	, m_strisisAHRSPN(_T(""))
	, m_str_isisDUPNRC(_T(""))
	, m_chkISISdamage2(FALSE)
	, m_chkISISscratches2(FALSE)
	, m_chkISISPins2(FALSE)
	, m_chkISISScrews2(FALSE)
{

}

VisualInspection::~VisualInspection()
{
}

void VisualInspection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	DDX_Check(pDX, IDC_CHECK_ISIS_DAMAGE, m_chkISISdamage);
	DDX_Check(pDX, IDC_CHECK_ISIS_SCRATCHES, m_chkISISscratches);

	DDX_Check(pDX, IDC_CHECK_ISIS_PINS, m_chkISISPins);
	DDX_Check(pDX, IDC_CHECK_ISIS_SCREW, m_chkISISScrews);
	DDX_Text(pDX, IDC_EDIT_ISISDUPN, m_str_isisDUPN);
	DDX_Text(pDX, IDC_EDIT_ISISADUPN, m_strisisADUPN);
	DDX_Text(pDX, IDC_EDIT_ISISMMSPN, m_strisisMMSPN);
	DDX_Text(pDX, IDC_EDIT_ISISAHRSPN, m_strisisAHRSPN);
	DDX_Text(pDX, IDC_EDIT_ISISDUPNRC, m_str_isisDUPNRC);

}


BEGIN_MESSAGE_MAP(VisualInspection, CDialog)
	ON_BN_CLICKED(IDOK, &VisualInspection::OnBnClickedOk)
	
//	ON_BN_CLICKED(IDC_CHECK_REAR_PINS, &VisualInspection::OnBnClickedCheckRearPins)
	
	
END_MESSAGE_MAP()


// VisualInspection message handlers
void VisualInspection::OnOK()
{
	CMessageBox_Dlg msgdlg;
        UpdateData(TRUE); 
	//1  Product Label///////////////////////////////////////////////////////////////////////////////////////////////////
		if (m_str_isisDUPN.Compare("IS2100000000")== 0)
	{
		m_strProductLabel.Format("IS2100000000");
		m_strStatusProductLabel.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.01 Part Number on ISIS DU FC is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strProductLabel = m_str_isisDUPN;
		m_strStatusProductLabel.Format("NOT OK");
	}

		/*********************2*****************************///////////

			if (m_str_isisDUPNRC.Compare("IS2100000000")== 0)
	{
		m_strProductLabelRC.Format("IS2100000000");
		m_strStatusProductLabelRC.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.02 Part Number on ISIS DU RC is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strProductLabelRC = m_str_isisDUPNRC;
		m_strStatusProductLabelRC.Format("NOT OK");
	}
//2 Sr No Label///////////////////////////////////////////////////////////////////////////////////////////////////
	if (m_strisisADUPN.Compare("AN-014-ADU-V00")== 0)
	{
		m_strSrNoLabel.Format("AN-014-ADU-V00");
		m_strStatusSrNoLabel.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.03 ADU Part Number is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strSrNoLabel = m_strisisADUPN;
		m_strStatusSrNoLabel.Format("NOT OK");
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	if (m_strisisMMSPN.Compare("AN-015-MMS-V00")== 0)
	{
		m_strESDLabel.Format("AN-015-MMS-V00");
		m_strStatusESDLabel.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.04 MMS Part Number is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strESDLabel = m_strisisMMSPN;
		m_strStatusESDLabel.Format("NOT OK");
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	if (m_strisisAHRSPN.Compare("1901400000000")== 0)
	{
		m_strRearMarking.Format("1901400000000");
		m_strStatusRearMarking.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.05 AHRS Part Number is not Correct, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strRearMarking = m_strisisAHRSPN;
		m_strStatusRearMarking.Format("NOT OK");
	}
	// rear pins

		
		if (!m_chkISISdamage)
	{
		m_strISISDamage.Format("NO");
		m_strStatusISISDamage.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.06 Corrosion present on ISIS System, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strISISDamage.Format("YES");
		m_strStatusISISDamage.Format("NOT OK");
	}

		//scratces
			if (!m_chkISISscratches)
	{
		m_strISISScratches.Format("NO");
		m_strStatusISISScratches.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.07 Foreign material detected on ISIS System, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strISISScratches.Format("YES");
		m_strStatusISISScratches.Format("NOT OK");
	}
			//screws
			if (!m_chkISISScrews)
	{
		m_strISISScrews.Format("NO");
		m_strStatusISISScrews.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.08 ISIS System has Loose screws, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strISISScrews.Format("YES");
		m_strStatusISISScrews.Format("NOT OK");
	}
			//bend of pins of conectors
			if (!m_chkISISPins)
	{
		m_strISISPins.Format("NO");
		m_strStatusISISPins.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("1.09 ISIS System connectors has bend of pins, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strISISPins.Format("YES");
		m_strStatusISISPins.Format("NOT OK");
	}
			UpdateData(FALSE); 
CDialog::OnOK();
}
void VisualInspection::OnBnClickedOk()
{
	OnOK();
}

void VisualInspection::OnBnClickedCheckProductLabel()
{
	UpdateData(true);
	
	if (m_ctlChkProductLabel)
	{
		GetDlgItem(IDC_CHECK_PRODUCT_LABEL)-> SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_PRODUCT_LABEL)-> SetWindowText("Not OK");	
	}

	UpdateData(false);
}

void VisualInspection::OnBnClickedCheckSrnoLabel()
{
	UpdateData(true);
	
	if (m_ctlChkSrNoLabel)
	{
		GetDlgItem(IDC_CHECK_SRNO_LABEL)-> SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_SRNO_LABEL)-> SetWindowText("Not OK");	
	}

	UpdateData(false);
}

void VisualInspection::OnBnClickedCheckEsdLabel()
{
	UpdateData(true);
	
	if (m_ctlChkESDLabel)
	{
		GetDlgItem(IDC_CHECK_ESD_LABEL)-> SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ESD_LABEL)-> SetWindowText("Not OK");	
	}

	UpdateData(false);
}



void VisualInspection::OnBnClickedCheckRearMarking()
{
	UpdateData(true);
	
	if (m_ctlChkRearMarking)
	{
		GetDlgItem(IDC_CHECK_REAR_MARKING)-> SetWindowText("OK");
	}
	else
	{
		GetDlgItem(IDC_CHECK_REAR_MARKING)-> SetWindowText("Not OK");	
	}

	UpdateData(false);
}






BOOL VisualInspection::OnInitDialog()
{
	CDialog::OnInitDialog();

	return 0;
}

