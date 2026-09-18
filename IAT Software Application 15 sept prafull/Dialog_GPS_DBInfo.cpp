// Dialog_GPS_DBInfo.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_GPS_DBInfo.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_GPS_DBInfo dialog

IMPLEMENT_DYNAMIC(CDialog_GPS_DBInfo, CDialog)

CDialog_GPS_DBInfo::CDialog_GPS_DBInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_GPS_DBInfo::IDD, pParent)
	, m_chkGPSNavi(FALSE)
	, m_chkGPSBasemap(FALSE)
	, m_chkGPSTerrain(FALSE)
	, m_chkGPSObstacle(FALSE)
	, m_chkGPSSafeTaxi(FALSE)
{

}

CDialog_GPS_DBInfo::~CDialog_GPS_DBInfo()
{
}

void CDialog_GPS_DBInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_GPS_NAVI, m_chkGPSNavi);
	DDX_Check(pDX, IDC_CHECK_GPS_BASEMAP, m_chkGPSBasemap);

	DDX_Check(pDX, IDC_CHECK_GPS_TERRAIN, m_chkGPSTerrain);
	DDX_Check(pDX, IDC_CHECK_GPS_OBSTACLE, m_chkGPSObstacle);
	DDX_Check(pDX, IDC_CHECK_GPS_SAFETAXI, m_chkGPSSafeTaxi);
}


BEGIN_MESSAGE_MAP(CDialog_GPS_DBInfo, CDialog)
	ON_BN_CLICKED(IDC_CHECK_GPS_NAVI, &CDialog_GPS_DBInfo::OnBnClickedCheckGpsNavi)
	ON_BN_CLICKED(IDC_CHECK_GPS_BASEMAP, &CDialog_GPS_DBInfo::OnBnClickedCheckGpsBasemap)
	ON_BN_CLICKED(IDC_CHECK_GPS_OBSTACLE, &CDialog_GPS_DBInfo::OnBnClickedCheckGpsObstacle)
	ON_BN_CLICKED(IDC_CHECK_GPS_SAFETAXI, &CDialog_GPS_DBInfo::OnBnClickedCheckGpsSafetaxi)
	ON_BN_CLICKED(IDC_CHECK_GPS_TERRAIN, &CDialog_GPS_DBInfo::OnBnClickedCheckGpsTerrain)
	ON_BN_CLICKED(IDOK, &CDialog_GPS_DBInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_GPS_DBInfo message handlers


void CDialog_GPS_DBInfo::OnBnClickedCheckGpsNavi()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if (m_chkGPSNavi)
	{
		GetDlgItem(IDC_CHECK_GPS_NAVI)->SetWindowText("Available");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_NAVI)->SetWindowText("Not Available");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_DBInfo::OnBnClickedCheckGpsBasemap()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if (m_chkGPSBasemap)
	{
		GetDlgItem(IDC_CHECK_GPS_BASEMAP)->SetWindowText("Available");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_BASEMAP)->SetWindowText("Not Available");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_DBInfo::OnBnClickedCheckGpsObstacle()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
    if (m_chkGPSObstacle)
	{
		GetDlgItem(IDC_CHECK_GPS_OBSTACLE)->SetWindowText("Available");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_OBSTACLE)->SetWindowText("Not Available");
	}

    UpdateData(FALSE);


}


void CDialog_GPS_DBInfo::OnBnClickedCheckGpsSafetaxi()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
    if (m_chkGPSSafeTaxi)
	{
		GetDlgItem(IDC_CHECK_GPS_SAFETAXI)->SetWindowText("Available");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_SAFETAXI)->SetWindowText("Not Available");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_DBInfo::OnBnClickedCheckGpsTerrain()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
    if (m_chkGPSTerrain)
	{
		GetDlgItem(IDC_CHECK_GPS_TERRAIN)->SetWindowText("Available");
	}
	else
	{
		GetDlgItem(IDC_CHECK_GPS_TERRAIN)->SetWindowText("Not Available");
	}

    UpdateData(FALSE);
}


void CDialog_GPS_DBInfo::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    CMessageBox_Dlg msgdlg;

    // -------- GPS Navigation --------
    if (m_chkGPSNavi)
    {
        m_strGPSNavi.Format("Available");
        m_strStatusGPSNavi.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Navigation is not avialable, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strGPSNavi.Format("Not Available");
        m_strStatusGPSNavi.Format("NOT OK");
    }
	// -------- GPS Basemap  --------
	 if (m_chkGPSBasemap)
    {
        m_strGPSBasemap.Format("Available");
        m_strStatusGPSBasemap.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Basemap is not avialable, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strGPSBasemap.Format("Not Available");
        m_strStatusGPSBasemap.Format("NOT OK");
    }
	 // -------- GPS Obsctacle  --------
	 if (m_chkGPSObstacle)
    {
        m_strGPSObstacle.Format("Available");
        m_strStatusGPSObstacle.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Obstacle/Hotline is not avialable, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strGPSObstacle.Format("Not Available");
        m_strStatusGPSObstacle.Format("NOT OK");
    }
	  // -------- GPS Safe Taxi  --------
	 if (m_chkGPSSafeTaxi)
    {
        m_strGPSSafeTaxi.Format("Available");
        m_strStatusGPSSafeTaxi.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS SafeTaxi is not avialable, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strGPSSafeTaxi.Format("Not Available");
        m_strStatusGPSSafeTaxi.Format("NOT OK");
    }

	  // -------- GPS Terrain  --------
	 if (m_chkGPSTerrain)
    {
        m_strGPSTerrain.Format("Available");
        m_strStatusGPSTerrain.Format("OK");
    }
    else
    {
        g_strMsgStr.Format("GPS Terrain is not avialable, Do You want to Continue?");
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            return;
        }

        m_strGPSTerrain.Format("Not Available");
        m_strStatusGPSTerrain.Format("NOT OK");
    }
	 UpdateData(FALSE);
	CDialog::OnOK();
}
