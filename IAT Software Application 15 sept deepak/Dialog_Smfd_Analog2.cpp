// Dialog_Smfd_Analog2.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Analog2.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Analog2 dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Analog2, CDialog)

CDialog_Smfd_Analog2::CDialog_Smfd_Analog2(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Smfd_Analog2::IDD, pParent)
	, m_edt_hydpresmain(_T(""))
	
{

}

CDialog_Smfd_Analog2::~CDialog_Smfd_Analog2()
{
}

void CDialog_Smfd_Analog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HYDPRESMAIN, m_edt_hydpresmain);
	
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Analog2, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Analog2::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG, &CDialog_Smfd_Analog2::OnBnClickedButtonSmfdAnalog)
END_MESSAGE_MAP()


// CDialog_Smfd_Analog2 message handlers


void CDialog_Smfd_Analog2::OnBnClickedOk()
{
    CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    // -------- HYD PRES MAIN --------
    int val = atoi(m_edt_hydpresmain);
    if (val >= 2910 && val <= 2950)
    {
        m_strHydPresMain = m_edt_hydpresmain;
        m_strStatusHydPresMain = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Main Pressure not in range, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresMain = m_edt_hydpresmain;
        m_strStatusHydPresMain = "NOT OK";
    }



    //// -------- EMER BRAKE --------
    //val = atoi(m_edt_emerbrake);
    //if (val >= 1285 && val <= 1315)
    //{
    //    m_strEmerBrake = m_edt_emerbrake;
    //    m_strStatusEmerBrake = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("Emergency Brake Pressure not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strEmerBrake = m_edt_emerbrake;
    //    m_strStatusEmerBrake = "NOT OK";
    //}

    //// -------- LH BRAKE --------
    //val = atoi(m_edt_Lhbrake);
    //if (val >= 1185 && val <= 1215)
    //{
    //    m_strLhBrake = m_edt_Lhbrake;
    //    m_strStatusLhBrake = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("LH Brake Pressure not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strLhBrake = m_edt_Lhbrake;
    //    m_strStatusLhBrake = "NOT OK";
    //}

    //// -------- RH BRAKE --------
    //val = atoi(m_edt_rhbrake);
    //if (val >= 1185 && val <= 1215)
    //{
    //    m_strRhBrake = m_edt_rhbrake;
    //    m_strStatusRhBrake = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("RH Brake Pressure not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strRhBrake = m_edt_rhbrake;
    //    m_strStatusRhBrake = "NOT OK";
    //}

    //// -------- ENGINE SPEED --------
    //val = atoi(m_edt_enginespd);
    //if (val >= 77 && val <= 81)
    //{
    //    m_strEngineSpd = m_edt_enginespd;
    //    m_strStatusEngineSpd = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("Engine Speed not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strEngineSpd = m_edt_enginespd;
    //    m_strStatusEngineSpd = "NOT OK";
    //}

    //// -------- FUEL LH --------
    //val = atoi(m_edt_fuelLh);
    //if (val >= 163 && val <= 173)
    //{
    //    m_strFuelLh = m_edt_fuelLh;
    //    m_strStatusFuelLh = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("LH Fuel not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strFuelLh = m_edt_fuelLh;
    //    m_strStatusFuelLh = "NOT OK";
    //}

    //// -------- FUEL RH --------
    //val = atoi(m_edt_fuelRh);
    //if (val >= 156 && val <= 166)
    //{
    //    m_strFuelRh = m_edt_fuelRh;
    //    m_strStatusFuelRh = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("RH Fuel not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strFuelRh = m_edt_fuelRh;
    //    m_strStatusFuelRh = "NOT OK";
    //}

    //// -------- COLLECTOR TANK --------
    //val = atoi(m_edt_collectortank);
    //if (val >= 178 && val <= 188)
    //{
    //    m_strCollectorTank = m_edt_collectortank;
    //    m_strStatusCollectorTank = "OK";
    //}
    //else
    //{
    //    g_strMsgStr.Format("Collector Tank Fuel not OK, Continue?");
    //    msgdlg.DoModal();
    //    if (!g_bContinueFlag) return;

    //    m_strCollectorTank = m_edt_collectortank;
    //    m_strStatusCollectorTank = "NOT OK";
    //}

    CDialog::OnOK();
}




void CDialog_Smfd_Analog2::OnBnClickedButtonSmfdAnalog()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	    m_edt_hydpresmain = "2940";  //range = 2930±20 
	   
		
	UpdateData(FALSE);
}
