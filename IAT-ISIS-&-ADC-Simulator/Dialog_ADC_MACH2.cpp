// Dialog_ADC_MACH2.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_ADC_MACH2.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Arinc429.h"
#include "Globals.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_ADC_MACH2 dialog

IMPLEMENT_DYNAMIC(CDialog_ADC_MACH2, CDialogEx)

CDialog_ADC_MACH2::CDialog_ADC_MACH2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_ADC_MACH2::IDD, pParent)
	, m_edtADCMach2(_T(""))
{

}

CDialog_ADC_MACH2::~CDialog_ADC_MACH2()
{
}

void CDialog_ADC_MACH2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADC_MACH2, m_edtADCMach2);
}


BEGIN_MESSAGE_MAP(CDialog_ADC_MACH2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_ADC_MACH2::OnBnClickedOk)
	ON_MESSAGE(WM_UPDATE_ARINC, &CDialog_ADC_MACH2::OnUpdateArinc)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_ADC_MACH2 message handlers


void CDialog_ADC_MACH2::OnBnClickedOk()
{
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);   //  MUST

	CMessageBox_Dlg msgdlg;
	// TODO: Add your control notification handler code here
	m_strMach2.Format("%s",m_edtADCMach2);

	double m2 = atof(m_edtADCMach2);

	if ( m2 >= 0.35 && m2<= 0.37)
		m_strStatusMach2 = "OK";
	else
	{
		g_strMsgStr = "Mach values invalid. Continue?";
		msgdlg.DoModal();
		if (!g_bContinueFlag) return;
		m_strStatusMach2 = "NOT OK";
	}
UpdateData(FALSE);
KillTimer(1);
	CDialogEx::OnOK();
}

BOOL CDialog_ADC_MACH2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

	 if(!g_bADCThreadRunning)
    {
        g_bADCStopThread    = FALSE;
        g_bADCThreadRunning = TRUE;

        AfxBeginThread(RxThread, this);
    }

    SetTimer(1, 3000, NULL);      // Update 5 times/sec

    return TRUE;
}

void CDialog_ADC_MACH2::OnTimer(UINT_PTR nIDEvent)
{
    if(nIDEvent == 1)
    {
        float value;

		//if(g_bSimulationMode)
		//{	
		//	TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
		//	ADT_L0_UINT32 Labels[1];
		//	Labels[0] = 0x61680085;   // LABEL_205, Mach 0.36
		//	gArinc429.SendLabels(8, Labels, 1);
		//}

        if(GetARINCValue(9, LABEL_205, &value))
        {
            CString str;
            str.Format("%.2f", value);

            if(str != m_edtADCMach2)      // update only if changed
            {
                m_edtADCMach2 = str;
                UpdateData(FALSE);
            }
        }
    }

    CDialogEx::OnTimer(nIDEvent);
}


void CDialog_ADC_MACH2::OnDestroy()
{
 
    g_bADCStopThread = TRUE;

    while(g_bADCThreadRunning)
        Sleep(10);

    CloseRx(8);

    CDialogEx::OnDestroy();
}

UINT CDialog_ADC_MACH2::RxThread(LPVOID pParam)
{
	CDialog_ADC_MACH2* pDlg =
        reinterpret_cast<CDialog_ADC_MACH2*>(pParam);

    if (pDlg == NULL)
        return 0;

    while(!g_bADCStopThread)
    {
		if(g_bSimulationMode)
		{
			TRACE("Simulation Mode On ::::::::::::::: Sending DATA ");
			ADT_L0_UINT32 Labels[1];
			//Labels[0] = 0xE0EA6083;
			Labels[0] = 0x616800A1;     // Mach 0.36
			gArinc429.SendLabels(3, Labels, 1);
			//0xE12200A1   // Mach 0.29
			//0x614000A1   // Mach 0.32
			//0xE16800A1   // Mach 0.36
		}

        ReadADCRX(9);
        Sleep(20);

		 float value;

        if(GetARINCValue(9, LABEL_205, &value))
        {
            CString str;
            str.Format(_T("%.2f"), value);

            pDlg->m_strADCMach2 = str;
    	 if (::IsWindow(pDlg->GetSafeHwnd()))
        {
            pDlg->PostMessage(WM_UPDATE_ARINC, 0, 0);
        }
    }
	}
    g_bADCThreadRunning = FALSE;

    return 0;
}

LRESULT CDialog_ADC_MACH2::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    m_edtADCMach2 = m_strADCMach2;

    UpdateData(FALSE);

    return 0;
}	