// Dialog_Smfd_Discrete.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Discrete.h"
#include "afxdialogex.h"
#include "datastruct.h"
#include "MessageBox_Dlg.h"
#include "Macros.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;



// CDialog_Smfd_Discrete dialog
BOOL BusTieflag = TRUE;
BOOL Canopyflag = TRUE;
BOOL Ecsoffflag = TRUE;
BOOL EcsOvPrflag = TRUE;
BOOL AoaMuteflag = TRUE;
BOOL AlarmMuteflag = TRUE;
BOOL Demistflag = TRUE;
BOOL Startonflag = TRUE;
IMPLEMENT_DYNAMIC(CDialog_Smfd_Discrete, CDialog)

CDialog_Smfd_Discrete::CDialog_Smfd_Discrete(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Discrete::IDD, pParent)
	, m_chkBusTie(FALSE)
	, m_chkCanopy(FALSE)
	, m_chkEcsOff(FALSE)
	, m_chkEcsOvPr(FALSE)
	, m_chkAoaMute(FALSE)
	, m_chkAlarmMute(FALSE)
	, m_chkDemist(FALSE)
	, m_chkStarton(FALSE)
{

}

CDialog_Smfd_Discrete::~CDialog_Smfd_Discrete()
{
}

void CDialog_Smfd_Discrete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BUSTIE, m_chkBusTie);
	DDX_Check(pDX, IDC_CHECK_CANOPY, m_chkCanopy);
	DDX_Check(pDX, IDC_CHECK_ECSOFF, m_chkEcsOff);
	DDX_Check(pDX, IDC_CHECK_ECSOVPR, m_chkEcsOvPr);
	DDX_Check(pDX, IDC_CHECK_AOAMUTE, m_chkAoaMute);
	DDX_Check(pDX, IDC_CHECK_ALARMMUTE, m_chkAlarmMute);
	DDX_Check(pDX, IDC_CHECK_DEMIST, m_chkDemist);
	DDX_Check(pDX, IDC_CHECK_STARTON, m_chkStarton);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Discrete, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Discrete::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_BUSTIE, &CDialog_Smfd_Discrete::OnBnClickedButtonBustie)
	ON_BN_CLICKED(IDC_BUTTON_CANOPY, &CDialog_Smfd_Discrete::OnBnClickedButtonCanopy)
	ON_BN_CLICKED(IDC_BUTTON_ECSOFF, &CDialog_Smfd_Discrete::OnBnClickedButtonEcsoff)
	ON_BN_CLICKED(IDC_BUTTON_ECSOVPR, &CDialog_Smfd_Discrete::OnBnClickedButtonEcsovpr)
	ON_BN_CLICKED(IDC_BUTTON_AOAMUTE, &CDialog_Smfd_Discrete::OnBnClickedButtonAoamute)
	ON_BN_CLICKED(IDC_BUTTON_ALARM_MUTE, &CDialog_Smfd_Discrete::OnBnClickedButtonAlarmMute)
	ON_BN_CLICKED(IDC_BUTTON_DEMIST, &CDialog_Smfd_Discrete::OnBnClickedButtonDemist)
	ON_BN_CLICKED(IDC_BUTTON_STARTON, &CDialog_Smfd_Discrete::OnBnClickedButtonStarton)
	ON_BN_CLICKED(IDC_CHECK_BUSTIE, &CDialog_Smfd_Discrete::OnBnClickedCheckBustie)
	ON_BN_CLICKED(IDC_CHECK_CANOPY, &CDialog_Smfd_Discrete::OnBnClickedCheckCanopy)
	ON_BN_CLICKED(IDC_CHECK_ECSOFF, &CDialog_Smfd_Discrete::OnBnClickedCheckEcsoff)
	ON_BN_CLICKED(IDC_CHECK_ECSOVPR, &CDialog_Smfd_Discrete::OnBnClickedCheckEcsovpr)
	ON_BN_CLICKED(IDC_CHECK_AOAMUTE, &CDialog_Smfd_Discrete::OnBnClickedCheckAoamute)
	ON_BN_CLICKED(IDC_CHECK_ALARMMUTE, &CDialog_Smfd_Discrete::OnBnClickedCheckAlarmmute)
	ON_BN_CLICKED(IDC_CHECK_DEMIST, &CDialog_Smfd_Discrete::OnBnClickedCheckDemist)
	ON_BN_CLICKED(IDC_CHECK_STARTON, &CDialog_Smfd_Discrete::OnBnClickedCheckStarton)
END_MESSAGE_MAP()


// CDialog_Smfd_Discrete message handlers
BOOL CDialog_Smfd_Discrete::OnInitDialog()
{
	//InitDiscrete1758();
	TRACE("init 1758 card");
	return TRUE;
}

void CDialog_Smfd_Discrete::OnBnClickedOk()
{
    UpdateData(TRUE);
    CMessageBox_Dlg msgdlg;

    // -------- BUS TIE --------
    if (m_chkBusTie)
    {
        m_strBusTie = "Ok";
        m_strStatusBusTie = "OK";
    }
    else
    {
        g_strMsgStr = "Bus Tie not active. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strBusTie = "NOT OK";
        m_strStatusBusTie = "NOT OK";
    }

    // -------- CANOPY --------
    if (m_chkCanopy)
    {
        m_strCanopy = "OK";
        m_strStatusCanopy = "OK";
    }
    else
    {
        g_strMsgStr = "Canopy status invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strCanopy = "NOT OK";
        m_strStatusCanopy = "NOT OK";
    }

    // -------- ECS OFF --------
    if (m_chkEcsOff)
    {
        m_strEcsoff = "OK";
        m_strStatusEcsoff = "OK";
    }
    else
    {
        g_strMsgStr = "ECS OFF invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strEcsoff = "NOT OK";
        m_strStatusEcsoff = "NOT OK";
    }

    // -------- ECS OVPR --------
    if (m_chkEcsOvPr)
    {
        m_strEcsOvPr = "OK";
        m_strStatusEcsOvPr = "OK";
    }
    else
    {
        g_strMsgStr = "ECS Over Pressure invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strEcsOvPr = "NOT OK";
        m_strStatusEcsOvPr = "NOT OK";
    }

    // -------- AOA MUTE --------
    if (m_chkAoaMute)
    {
        m_strAoamute = "OK";
        m_strStatusAoamute = "OK";
    }
    else
    {
        g_strMsgStr = "AOA Mute invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strAoamute = "NOT OK";
        m_strStatusAoamute = "NOT OK";
    }

    // -------- ALARM MUTE --------
    if (m_chkAlarmMute)
    {
        m_strAlarmMute = "OK";
        m_strStatusAlarmMute = "OK";
    }
    else
    {
        g_strMsgStr = "Alarm Mute invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strAlarmMute = "NOT OK";
        m_strStatusAlarmMute = "NOT OK";
    }

    // -------- DEMIST --------
    if (m_chkDemist)
    {
        m_strDemist = "OK";
        m_strStatusDemist = "OK";
    }
    else
    {
        g_strMsgStr = "Demist invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strDemist = "NOT OK";
        m_strStatusDemist = "NOT OK";
    }

    // -------- START ON --------
    if (m_chkStarton)
    {
        m_strStarton = "OK";
        m_strStatusStarton = "OK";
    }
    else
    {
        g_strMsgStr = "Start Switch invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStarton = "NOT OK";
        m_strStatusStarton = "NOT OK";
    }

    UpdateData(FALSE);
    CDialog::OnOK();
}


void CDialog_Smfd_Discrete::OnBnClickedButtonBustie()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(BusTieflag)
	{
	  SwitchDiscrete1758(BUS_TIE_CONTACTOR_DEENERGIZED_SMFD_FC,ON);
	  GetDlgItem(IDC_BUTTON_BUSTIE)->SetWindowText("ON");
	  BusTieflag = FALSE;

	}else
	{ 
	SwitchDiscrete1758(BUS_TIE_CONTACTOR_DEENERGIZED_SMFD_FC,OFF);
	GetDlgItem(IDC_BUTTON_BUSTIE)->SetWindowText("OFF");
	 BusTieflag = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonCanopy()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(Canopyflag)
	{
	  SwitchDiscrete1758(CANOPY_SW_SMFD_FC,ON);
	    GetDlgItem(IDC_BUTTON_CANOPY)->SetWindowText("ON");
	  Canopyflag = FALSE;
	}else
	{SwitchDiscrete1758(CANOPY_SW_SMFD_FC,OFF);
	  GetDlgItem(IDC_BUTTON_CANOPY)->SetWindowText("OFF");
	Canopyflag = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonEcsoff()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(Ecsoffflag)
	{
	  SwitchDiscrete1758(ECS_OFF_SMFD_FC,ON);
	  GetDlgItem(IDC_BUTTON_ECSOFF)->SetWindowText("ON");
	  Ecsoffflag = FALSE;
	}else
	{SwitchDiscrete1758(ECS_OFF_SMFD_FC,OFF);
	GetDlgItem(IDC_BUTTON_ECSOFF)->SetWindowText("OFF");
	Ecsoffflag = TRUE;
	}
		UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonEcsovpr()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(EcsOvPrflag)
	{
	  SwitchDiscrete1758(ECS_OVER_PRESSURE_SMFD_FC,ON);
	   GetDlgItem(IDC_BUTTON_ECSOVPR)->SetWindowText("ON");
	  EcsOvPrflag = FALSE;
	}else
	{SwitchDiscrete1758(ECS_OVER_PRESSURE_SMFD_FC,OFF);
	 GetDlgItem(IDC_BUTTON_ECSOVPR)->SetWindowText("OFF");
	EcsOvPrflag = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonAoamute()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(AoaMuteflag)
	{
	  SwitchDiscrete1758(AOA_MUTE_SMFD_FC,ON);
	  GetDlgItem(IDC_BUTTON_AOAMUTE)->SetWindowText("ON");
	  AoaMuteflag = FALSE;
	}else
	{SwitchDiscrete1758(AOA_MUTE_SMFD_FC,OFF);
	GetDlgItem(IDC_BUTTON_AOAMUTE)->SetWindowText("OFF");
	AoaMuteflag = TRUE;}
	  UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonAlarmMute()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(AlarmMuteflag)
	{
	  SwitchDiscrete1758(ALARM_MUTE_SMFD_FC,ON);
	  GetDlgItem(IDC_BUTTON_ALARM_MUTE)->SetWindowText("ON");
	   AlarmMuteflag = FALSE;
	}else
	{SwitchDiscrete1758(ALARM_MUTE_SMFD_FC,OFF);
	GetDlgItem(IDC_BUTTON_ALARM_MUTE)->SetWindowText("OFF");
	   AlarmMuteflag = TRUE;
	   }
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonDemist()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(Demistflag)
	{
	  SwitchDiscrete1758(DEMIST_ON_SMFD_FC,ON);
	   GetDlgItem(IDC_BUTTON_DEMIST)->SetWindowText("ON");
	  Demistflag = FALSE;
	}else
	{SwitchDiscrete1758(DEMIST_ON_SMFD_FC,OFF);
	 GetDlgItem(IDC_BUTTON_DEMIST)->SetWindowText("OFF");
	  Demistflag = TRUE;
	  }
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedButtonStarton()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(Startonflag)
	{
	  SwitchDiscrete1758(START_ON_SMFD_FC,ON);
	  GetDlgItem(IDC_BUTTON_STARTON)->SetWindowText("ON");
	  Startonflag = FALSE;
	}else
	{SwitchDiscrete1758(START_ON_SMFD_FC,OFF);
	GetDlgItem(IDC_BUTTON_STARTON)->SetWindowText("OFF");
        Startonflag = TRUE;	
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckBustie()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

  
    if (m_chkBusTie)
	{
		GetDlgItem(IDC_CHECK_BUSTIE)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_BUSTIE)->SetWindowText("Not Ok");
	}

    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckCanopy()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkCanopy)
	{
		GetDlgItem(IDC_CHECK_CANOPY)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_CANOPY)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckEcsoff()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkEcsOff)
	{
		GetDlgItem(IDC_CHECK_ECSOFF)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ECSOFF)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckEcsovpr()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkEcsOvPr)
	{
		GetDlgItem(IDC_CHECK_ECSOVPR)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ECSOVPR)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckAoamute()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkAoaMute)
	{
		GetDlgItem(IDC_CHECK_AOAMUTE)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_AOAMUTE)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckAlarmmute()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkAlarmMute)
	{
		GetDlgItem(IDC_CHECK_ALARMMUTE)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ALARMMUTE)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckDemist()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkDemist)
	{
		GetDlgItem(IDC_CHECK_DEMIST)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_DEMIST)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete::OnBnClickedCheckStarton()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chkStarton)
	{
		GetDlgItem(IDC_CHECK_STARTON)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_STARTON)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}
