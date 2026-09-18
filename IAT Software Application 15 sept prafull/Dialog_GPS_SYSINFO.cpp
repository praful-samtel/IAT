// Dialog_GPS_SYSINFO.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_GPS_SYSINFO.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_GPS_SYSINFO dialog

IMPLEMENT_DYNAMIC(CDialog_GPS_SYSINFO, CDialog)

CDialog_GPS_SYSINFO::CDialog_GPS_SYSINFO(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_GPS_SYSINFO::IDD, pParent)
	, m_edtGpsSerialNo(_T(""))
	, m_edtGpsSystemId(_T(""))
	, m_edtGpsSoftwareVr(_T(""))
	, m_edtGpsWaasVr(_T(""))
	, m_ctlChkGpsSrno(FALSE)
	, m_ctlChkGpsSysid(FALSE)
	, m_ctlChkGpsSwVr(FALSE)
	, m_ctlChkGpsWaasSw(FALSE)
{

}

CDialog_GPS_SYSINFO::~CDialog_GPS_SYSINFO()
{
}

void CDialog_GPS_SYSINFO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPS_SNO, m_edtGpsSerialNo);
	DDX_Text(pDX, IDC_EDIT_GPS_SID, m_edtGpsSystemId);
	DDX_Text(pDX, IDC_EDIT_GPS_SWVR, m_edtGpsSoftwareVr);
	DDX_Text(pDX, IDC_EDIT_GPS_WAAS, m_edtGpsWaasVr);
	DDX_Check(pDX, IDC_CHECK_GPS_SR_NO, m_ctlChkGpsSrno);
	DDX_Check(pDX, IDC_CHECK_GPS_SYSID, m_ctlChkGpsSysid);
	DDX_Check(pDX, IDC_CHECK_GPS_SWVR, m_ctlChkGpsSwVr);
	DDX_Check(pDX, IDC_CHECK_GPS_WAAS_SW, m_ctlChkGpsWaasSw);
}


BEGIN_MESSAGE_MAP(CDialog_GPS_SYSINFO, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_GPS_SYSINFO::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_GPS_SR_NO, &CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSrNo)
	ON_BN_CLICKED(IDC_CHECK_GPS_SYSID, &CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSysid)
	ON_BN_CLICKED(IDC_CHECK_GPS_SWVR, &CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSwvr)
	ON_BN_CLICKED(IDC_CHECK_GPS_WAAS_SW, &CDialog_GPS_SYSINFO::OnBnClickedCheckGpsWaasSw)
END_MESSAGE_MAP()


// CDialog_GPS_SYSINFO message handlers


void CDialog_GPS_SYSINFO::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    CMessageBox_Dlg msgdlg;

    // -------- GPS Serial number --------
	 m_strGpsSrno = m_edtGpsSerialNo;
    if (m_ctlChkGpsSrno)
    {
       
        m_strStatusGpsSrno.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Serial number is not corrrect, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        //m_strGpsSrno.Format("Not Available");
        m_strStatusGpsSrno.Format("NOT OK");
    }
	 // -------- GPS System id --------
	 m_strGpsSysid = m_edtGpsSystemId;
    if (m_ctlChkGpsSysid)
    {
       
        m_strStatusGpsSysid.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS System id is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        
        m_strStatusGpsSysid.Format("NOT OK");
    }

	 // -------- GPS software version --------
	 m_strGpsSwVr = m_edtGpsSoftwareVr;
    if (m_ctlChkGpsSwVr)
    {
       
        m_strStatusGpsSwVr.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Software version is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }     
        m_strStatusGpsSwVr.Format("NOT OK");
    }
	 // -------- GPS WAAS version --------
	 m_strGpsWaasSw = m_edtGpsWaasVr;
    if (m_ctlChkGpsSwVr)
    {
       
        m_strStatusGpsWaasSw.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS WAAS version is not Correct, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }     
        m_strStatusGpsWaasSw.Format("NOT OK");
    }
	UpdateData(FALSE);


	CDialog::OnOK();
}


void CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSrNo()
{
	// TODO: Add your control notification handler code here
 UpdateData(TRUE);
    if (m_ctlChkGpsSrno)
	{
		GetDlgItem(IDC_CHECK_GPS_SR_NO)->SetWindowText("Correct");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SR_NO)->SetWindowText("Not Correct");
	}

    UpdateData(FALSE);
}

void CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSysid()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if (m_ctlChkGpsSysid)
	{
		GetDlgItem(IDC_CHECK_GPS_SYSID)->SetWindowText("Correct");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SYSID)->SetWindowText("Not Correct");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_SYSINFO::OnBnClickedCheckGpsSwvr()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if (m_ctlChkGpsSwVr)
	{
		GetDlgItem(IDC_CHECK_GPS_SWVR)->SetWindowText("Correct");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SWVR)->SetWindowText("Not Correct");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_SYSINFO::OnBnClickedCheckGpsWaasSw()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if (m_ctlChkGpsWaasSw)
	{
		GetDlgItem(IDC_CHECK_GPS_WAAS_SW)->SetWindowText("Correct");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_WAAS_SW)->SetWindowText("Not Correct");
	}

    UpdateData(FALSE);
}
