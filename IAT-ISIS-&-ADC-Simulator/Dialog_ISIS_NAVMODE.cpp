// Dialog_ISIS_NAVMODE.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ISIS_NAVMODE.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Arinc429.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ISIS_NAVMODE dialog

IMPLEMENT_DYNAMIC(CDialog_ISIS_NAVMODE, CDialog)

CDialog_ISIS_NAVMODE::CDialog_ISIS_NAVMODE(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_ISIS_NAVMODE::IDD, pParent)
	, m_chk_ISISFC_NAVMODE(FALSE)
	, m_chk_ISISRC_NAVMODE(FALSE)
{
	m_bThreadRunning = FALSE;
    m_iModeStep = 0;
}

CDialog_ISIS_NAVMODE::~CDialog_ISIS_NAVMODE()
{
}

void CDialog_ISIS_NAVMODE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ISISFC_NAVMODE, m_chk_ISISFC_NAVMODE);
	DDX_Check(pDX, IDC_CHECK_ISISRC_NAVMODE, m_chk_ISISRC_NAVMODE);
}


BEGIN_MESSAGE_MAP(CDialog_ISIS_NAVMODE, CDialog)
	ON_BN_CLICKED(IDC_CHECK_ISISFC_NAVMODE, &CDialog_ISIS_NAVMODE::OnBnClickedCheckIsisfcNavmode)
	ON_BN_CLICKED(IDC_CHECK_ISISRC_NAVMODE, &CDialog_ISIS_NAVMODE::OnBnClickedCheckIsisrcNavmode)
	ON_BN_CLICKED(IDOK, &CDialog_ISIS_NAVMODE::OnBnClickedOk)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_ISIS_NAVMODE message handlers


void CDialog_ISIS_NAVMODE::OnBnClickedCheckIsisfcNavmode()
{
	// TODO: Add your control notification handler code here
		UpdateData(true);
	
	if (m_chk_ISISFC_NAVMODE)
	{
		GetDlgItem(IDC_CHECK_ISISFC_NAVMODE)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISFC_NAVMODE)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_NAVMODE::OnBnClickedCheckIsisrcNavmode()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (m_chk_ISISRC_NAVMODE)
	{
		GetDlgItem(IDC_CHECK_ISISRC_NAVMODE)-> SetWindowText("Operational");
	}
	else
	{
		GetDlgItem(IDC_CHECK_ISISRC_NAVMODE)-> SetWindowText("Not Operational");	
	}

	UpdateData(false);
}


void CDialog_ISIS_NAVMODE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
	UpdateData(true); 
			if (m_chk_ISISFC_NAVMODE)
	{
		m_strIsisFCNAVMODE.Format("Operational");
		m_strStatusIsisFCNAVMODE.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("7.01 ISIS DU FC Navigation mode Check is Not Operational, Do you want to Continue");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisFCNAVMODE.Format("Not Operational");
		m_strStatusIsisFCNAVMODE.Format("NOT OK");
	}

				if (m_chk_ISISRC_NAVMODE)
	{
		m_strIsisRCNAVMODE.Format("Operational");
		m_strStatusIsisRCNAVMODE.Format("OK");
	}
	else
	{
		g_strMsgStr.Format("7.02 ISIS DU RC Navigation mode Check is Not Operational, Do You want to Continue?");		
		msgdlg.DoModal();		
		if (!g_bContinueFlag)
		{
			return;
		}
		m_strIsisRCNAVMODE.Format("Not Operational");
		m_strStatusIsisRCNAVMODE.Format("NOT OK");
	}
				UpdateData(false); 
	CDialog::OnOK();
}


BOOL CDialog_ISIS_NAVMODE::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_bThreadRunning = TRUE;

    AfxBeginThread(NavModeThread,this);

    return TRUE;
}

UINT CDialog_ISIS_NAVMODE::NavModeThread(LPVOID pParam)
{
    CDialog_ISIS_NAVMODE* pDlg =
        (CDialog_ISIS_NAVMODE*)pParam;

    pDlg->ExecuteNavModeSimulation();

    return 0;
}

void CDialog_ISIS_NAVMODE::ExecuteNavModeSimulation()
{
    ADT_L0_UINT32 Labels[3];

    //-------------------------------------------------------
    // Initialize channels once
    //-------------------------------------------------------

    if(!gArinc429.InitializeTxChannel(3))
    {
        TRACE("Failed to initialize TX Channel 3\n");
        return;
    }

    if(!gArinc429.InitializeTxChannel(1))
    {
        TRACE("Failed to initialize TX Channel 1\n");
        return;
    }

    while(m_bThreadRunning)
    {
        //---------------------------------------------------
        // VOR
        //---------------------------------------------------

        if(m_iModeStep < 5)
        {
            Labels[0] = 0x65195738;

            switch(m_iModeStep)
            {
            case 0:
                Labels[1] = 0x62C00349;
                break;

            case 1:
                Labels[1] = 0x62C00349;
                break;

            case 2:
                Labels[1] = 0x68010349;
                break;

            case 3:
                Labels[1] = 0x6FFFF349;
                break;

            case 4:
                Labels[1] = 0x7FFFF349;
                break;
            }

            gArinc429.SendLabels(3, Labels, 2);

            //------------------------------------------------
            // TACAN follows same bearing sequence
            //------------------------------------------------

            switch(m_iModeStep)
            {
            case 0:
                gArinc429.StartTacanSimulation(
                    1,
                    0x600221A6,
                    0x62C00349,
                    0x60000141);
                break;

            case 1:
                gArinc429.StartTacanSimulation(
                    1,
                    0x600221A6,
                    0x65600349,
                    0x60540141);
                break;

            case 2:
                gArinc429.StartTacanSimulation(
                    1,
                    0x600221A6,
                    0x68010349,
                    0x61DC0141);
                break;

            case 3:
                gArinc429.StartTacanSimulation(
                    1,
                    0x600221A6,
                    0x6FFFF349,
                    0x63B00141);
                break;

            case 4:
                gArinc429.StartTacanSimulation(
                    1,
                    0x600221A6,
                    0x7FFFF349,
                    0x66440141);
                break;
            }
        }

        //---------------------------------------------------
        // ILS
        //---------------------------------------------------

        else
        {
            Labels[0] = 0x65197738;

            switch(m_iModeStep - 5)
            {
            case 0:
                Labels[1] = 0xF0B8033E;
                Labels[2] = 0xE0D803DE;
                break;

            case 1:
                Labels[1] = 0xF0B8033E;
                Labels[2] = 0xE31A03DE;
                break;

            case 2:
                Labels[1] = 0xF1C0033E;
                Labels[2] = 0xF63503DE;
                break;

            case 3:
                Labels[1] = 0xE381033E;
                Labels[2] = 0xE7C003DE;
                break;

            case 4:
                Labels[1] = 0xE460033E;
                Labels[2] = 0xE7C003DE;
                break;
            }

            gArinc429.SendLabels(3, Labels, 3);

            //------------------------------------------------
            // Keep TACAN alive during ILS
            //------------------------------------------------

            gArinc429.StartTacanSimulation(
                1,
                0x600221A6,
                0x62C00349,
                0x60000141);
        }

        //---------------------------------------------------
        // Next Step
        //---------------------------------------------------

        m_iModeStep++;

        if(m_iModeStep >= 10)
            m_iModeStep = 0;

        Sleep(1000);
    }

    //-------------------------------------------------------
    // Stop TX
    //-------------------------------------------------------

  /*  gArinc429.CloseARINC429(0,-1);
	 gArinc429.CloseARINC429(1,-1);*/

}

void CDialog_ISIS_NAVMODE::OnDestroy()
{
    m_bThreadRunning=FALSE;
	gArinc429.CloseARINC429(0,-1);
	gArinc429.CloseARINC429(1,-1);
    Sleep(200);

    CDialog::OnDestroy();
}