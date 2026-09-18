// Dialog_Smfd_Discrete_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Discrete_RC.h"
#include "afxdialogex.h"
#include "datastruct.h"
#include "MessageBox_Dlg.h"
#include "Macros.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_Smfd_Discrete_RC dialog
BOOL BusTieflagRC = TRUE;
BOOL CanopyflagRC = TRUE;
BOOL EcsoffflagRC = TRUE;
BOOL EcsOvPrflagRC = TRUE;
BOOL AoaMuteflagRC = TRUE;
BOOL AlarmMuteflagRC = TRUE;
BOOL DemistflagRC = TRUE;
BOOL StartonflagRC = TRUE;
IMPLEMENT_DYNAMIC(CDialog_Smfd_Discrete_RC, CDialogEx)

CDialog_Smfd_Discrete_RC::CDialog_Smfd_Discrete_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Discrete_RC::IDD, pParent)
	, m_chk_SmfdRc_BusTie(FALSE)
	, m_chk_SmfdRc_Canopy(FALSE)
	, m_chk_SmfdRc_EcsOff(FALSE)
	, m_chk_SmfdRc_EcsOvPr(FALSE)
	, m_chk_SmfdRc_AoaMute(FALSE)
	, m_chk_SmfdRc_Demist(FALSE)
	, m_chk_SmfdRc_StOn(FALSE)
{
	
}

CDialog_Smfd_Discrete_RC::~CDialog_Smfd_Discrete_RC()
{
}

void CDialog_Smfd_Discrete_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BUSTIE_RC, m_chk_SmfdRc_BusTie);
	DDX_Check(pDX, IDC_CHECK_CANOPY_RC, m_chk_SmfdRc_Canopy);
	DDX_Check(pDX, IDC_CHECK_ECSOFF_RC, m_chk_SmfdRc_EcsOff);
	DDX_Check(pDX, IDC_CHECK_ECSOVPR_RC, m_chk_SmfdRc_EcsOvPr);
	DDX_Check(pDX, IDC_CHECK_AOAMUTE_RC, m_chk_SmfdRc_AoaMute);
	DDX_Control(pDX, IDC_CHECK_ALARMMUTE_RC, m_chk_SmfdRc_AlMu);
	DDX_Check(pDX, IDC_CHECK_DEMIST_RC, m_chk_SmfdRc_Demist);
	DDX_Check(pDX, IDC_CHECK_STARTON_RC, m_chk_SmfdRc_StOn);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Discrete_RC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BUSTIE, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonBustie)
	ON_BN_CLICKED(IDC_BUTTON_CANOPY, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonCanopy)
	ON_BN_CLICKED(IDC_CHECK_ECSOFF_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsoffRc)
	ON_BN_CLICKED(IDC_BUTTON_ECSOVPR, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonEcsovpr)
	ON_BN_CLICKED(IDC_BUTTON_AOAMUTE, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonAoamute)
	ON_BN_CLICKED(IDC_BUTTON_ALARM_MUTE, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonAlarmMute)
	ON_BN_CLICKED(IDC_BUTTON_DEMIST, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonDemist)
	ON_BN_CLICKED(IDC_BUTTON_STARTON, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonStarton)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Discrete_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_BUSTIE_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckBustieRc)
	ON_BN_CLICKED(IDC_CHECK_CANOPY_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckCanopyRc)
	ON_BN_CLICKED(IDC_CHECK_ECSOVPR_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsovprRc)
	ON_BN_CLICKED(IDC_CHECK_AOAMUTE_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckAoamuteRc)
	ON_BN_CLICKED(IDC_CHECK_ALARMMUTE_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckAlarmmuteRc)
	ON_BN_CLICKED(IDC_CHECK_DEMIST_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckDemistRc)
	ON_BN_CLICKED(IDC_BUTTON_ECSOFF, &CDialog_Smfd_Discrete_RC::OnBnClickedButtonEcsoff)
	ON_BN_CLICKED(IDC_CHECK_STARTON_RC, &CDialog_Smfd_Discrete_RC::OnBnClickedCheckStartonRc)
END_MESSAGE_MAP()


// CDialog_Smfd_Discrete_RC message handlers


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonBustie()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(BusTieflagRC)
	{
	  SwitchDiscrete(BUS_TIE_CONTACTOR_DEENERGIZED_SMFD_RC,ON);
	    GetDlgItem(IDC_BUTTON_BUSTIE)->SetWindowText("ON");
	  BusTieflagRC = FALSE;

	}else
	{SwitchDiscrete(BUS_TIE_CONTACTOR_DEENERGIZED_SMFD_RC,OFF);
	GetDlgItem(IDC_BUTTON_BUSTIE)->SetWindowText("OFF");
	 BusTieflagRC = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonCanopy()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(CanopyflagRC)
	{
	  SwitchDiscrete(CANOPY_SW_SMFD_RC,ON);
	   GetDlgItem(IDC_BUTTON_CANOPY)->SetWindowText("ON");
	  CanopyflagRC = FALSE;
	}else
	{SwitchDiscrete(CANOPY_SW_SMFD_RC,OFF);
	 GetDlgItem(IDC_BUTTON_CANOPY)->SetWindowText("OFF");
	CanopyflagRC = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonEcsoff()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(EcsoffflagRC)
	{
	  SwitchDiscrete(ECS_OFF_SMFD_RC,ON);
	   GetDlgItem(IDC_BUTTON_ECSOFF)->SetWindowText("ON");
	  EcsoffflagRC = FALSE;
	}else
	{SwitchDiscrete(ECS_OFF_SMFD_RC,OFF);
	 GetDlgItem(IDC_BUTTON_ECSOFF)->SetWindowText("OFF");
	EcsoffflagRC = TRUE;
	}
		UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonEcsovpr()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(EcsOvPrflagRC)
	{
	  SwitchDiscrete(ECS_OVER_PRESSURE_SMFD_RC,ON);
	   GetDlgItem(IDC_BUTTON_ECSOVPR)->SetWindowText("ON");
	  EcsOvPrflagRC = FALSE;
	}else
	{SwitchDiscrete(ECS_OVER_PRESSURE_SMFD_RC,OFF);
	 GetDlgItem(IDC_BUTTON_ECSOVPR)->SetWindowText("OFF");
	EcsOvPrflagRC = TRUE;
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonAoamute()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(AoaMuteflagRC)
	{
	  SwitchDiscrete(AOA_MUTE_SMFD_RC,ON);
	  GetDlgItem(IDC_BUTTON_AOAMUTE)->SetWindowText("ON");
	  AoaMuteflagRC = FALSE;
	}else
	{SwitchDiscrete(AOA_MUTE_SMFD_RC,OFF);
	GetDlgItem(IDC_BUTTON_AOAMUTE)->SetWindowText("OFF");
	AoaMuteflagRC = TRUE;}
	  UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonAlarmMute()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(AlarmMuteflagRC)
	{
	  SwitchDiscrete(ALARM_MUTE_SMFD_RC,ON);
	  GetDlgItem(IDC_BUTTON_ALARM_MUTE)->SetWindowText("ON");
	   AlarmMuteflagRC = FALSE;
	}else
	{SwitchDiscrete(ALARM_MUTE_SMFD_RC,OFF);
	GetDlgItem(IDC_BUTTON_ALARM_MUTE)->SetWindowText("OFF");
	   AlarmMuteflagRC = TRUE;
	   }
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonDemist()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(DemistflagRC)
	{
	  SwitchDiscrete(DEMIST_ON_SMFD_RC,ON);
	    GetDlgItem(IDC_BUTTON_DEMIST)->SetWindowText("ON");
	  DemistflagRC = FALSE;
	}else
	{SwitchDiscrete(DEMIST_ON_SMFD_RC,OFF);
	  GetDlgItem(IDC_BUTTON_DEMIST)->SetWindowText("OFF");
	  DemistflagRC = TRUE;
	  }
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedButtonStarton()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
	if(StartonflagRC)
	{
	  SwitchDiscrete(START_ON_SMFD_RC,ON);
	  GetDlgItem(IDC_BUTTON_STARTON)->SetWindowText("ON");
	  StartonflagRC = FALSE;
	}else
	{SwitchDiscrete(START_ON_SMFD_RC,OFF);
	GetDlgItem(IDC_BUTTON_STARTON)->SetWindowText("OFF");
        StartonflagRC = TRUE;	
	}
	UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
    CMessageBox_Dlg msgdlg;

    // -------- BUS TIE --------
    if (m_chk_SmfdRc_BusTie)
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
    if (m_chk_SmfdRc_Canopy)
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
    if (m_chk_SmfdRc_EcsOff)
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
    if (m_chk_SmfdRc_EcsOvPr)
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
    if (m_chk_SmfdRc_AoaMute)
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
    if (m_chk_SmfdRc_AlMu)
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
    if (m_chk_SmfdRc_Demist)
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
    if (m_chk_SmfdRc_StOn)
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
	CDialogEx::OnOK();
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckBustieRc()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

  
    if (m_chk_SmfdRc_BusTie)
	{
		GetDlgItem(IDC_CHECK_BUSTIE_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_BUSTIE_RC)->SetWindowText("Not Ok");
	}

    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckCanopyRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	 
    if (m_chk_SmfdRc_Canopy)
	{
		GetDlgItem(IDC_CHECK_CANOPY_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_CANOPY_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}
void CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsoffRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	 
    if (m_chk_SmfdRc_EcsOff)
	{
		GetDlgItem(IDC_CHECK_ECSOFF_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ECSOFF_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
	
}

void CDialog_Smfd_Discrete_RC::OnBnClickedCheckEcsovprRc()
{
	// TODO: Add your control notification handler code 
		UpdateData(TRUE);	 
    if (m_chk_SmfdRc_EcsOvPr)
	{
		GetDlgItem(IDC_CHECK_ECSOVPR_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ECSOVPR_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckAoamuteRc()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);	 
    if (m_chk_SmfdRc_AoaMute)
	{
		GetDlgItem(IDC_CHECK_AOAMUTE_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_AOAMUTE_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckAlarmmuteRc()
{
	// TODO: Add your control notification handler code here
	
		UpdateData(TRUE);	 
    if (m_chk_SmfdRc_AlMu)
	{
		GetDlgItem(IDC_CHECK_ALARMMUTE_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ALARMMUTE_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}


void CDialog_Smfd_Discrete_RC::OnBnClickedCheckDemistRc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);	 
    if (m_chk_SmfdRc_Demist)
	{
		GetDlgItem(IDC_CHECK_DEMIST_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_DEMIST_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}




void CDialog_Smfd_Discrete_RC::OnBnClickedCheckStartonRc()
{
	// TODO: Add your control notification handler code here
	
		 UpdateData(TRUE);	 
    if (m_chk_SmfdRc_StOn)
	{
		GetDlgItem(IDC_CHECK_STARTON_RC)->SetWindowText("Ok");
	}
	else
	{
		GetDlgItem(IDC_CHECK_STARTON_RC)->SetWindowText("Not Ok");
	}
    UpdateData(FALSE);
}
