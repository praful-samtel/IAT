// Dialog_Smfd_Fuel_RC.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Fuel_RC.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_Smfd_Fuel_RC dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Fuel_RC, CDialogEx)

CDialog_Smfd_Fuel_RC::CDialog_Smfd_Fuel_RC(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Fuel_RC::IDD, pParent)
	, m_edt_SmfdRc_Fuel(_T(""))
	, m_edt_SmfdRc_FuelResponse(_T(""))
{

}

CDialog_Smfd_Fuel_RC::~CDialog_Smfd_Fuel_RC()
{
}

void CDialog_Smfd_Fuel_RC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1_RC, m_edt_SmfdRc_Fuel);
	DDX_Text(pDX, IDC_EDIT2_RC, m_edt_SmfdRc_FuelResponse);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Fuel_RC, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Fuel_RC::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_FUEL_LABEL, &CDialog_Smfd_Fuel_RC::OnBnClickedButtonSmfdFuelLabel)
	ON_BN_CLICKED(IDC_BUTTON_FUELFLOW_RC, &CDialog_Smfd_Fuel_RC::OnBnClickedButtonFuelflowRc)
END_MESSAGE_MAP()


// CDialog_Smfd_Fuel_RC message handlers


void CDialog_Smfd_Fuel_RC::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;
    if (m_edt_SmfdRc_FuelResponse == "300")
    {
        m_strSmfdfuel = m_edt_SmfdRc_FuelResponse;
		m_strStatusSmfdfuel = "OK";
    }else
	{
		g_strMsgStr.Format("SMFD1 Current out of limit, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strSmfdfuel = m_edt_SmfdRc_FuelResponse;
        m_strStatusSmfdfuel = "NOT OK";
	}
	CDialogEx::OnOK();
}

//DWORD SendToArinc(DWORD dwLabel)
//{
//    // TODO: Implement actual ARINC communication
//
//    // For now just return same value (loopback simulation)
//    return dwLabel;
//}
void CDialog_Smfd_Fuel_RC::OnBnClickedButtonSmfdFuelLabel()
{
    UpdateData(TRUE);  // Get data from UI

    // 1. Check empty input
   /* if (m_edt_SmfdRc_Fuel.IsEmpty())
    {
        AfxMessageBox(_T("Please enter Fuel Flow value"));
        return;
    }
*/
    // 2. Convert CString -> Integer
    int nValue = _ttoi(m_edt_SmfdRc_Fuel);

    if (nValue <= 0)
    {
        AfxMessageBox(_T("Invalid value entered"));
        return;
    }

    //// 3. Convert to HEX (DWORD)
    //DWORD dwHexValue = (DWORD)nValue;

    //// 4. Send to ARINC (Dummy function)
    //DWORD dwReceivedValue = SendToArinc(dwHexValue);

    //// 5. Convert received value to CString
    //CString strReceived;
    //strReceived.Format(_T("%d"), dwReceivedValue);

    //// 6. Set received value to Edit Box 2
    //m_edt_SmfdRc_FuelResponse = strReceived;

    UpdateData(FALSE); // Update UI
}




void CDialog_Smfd_Fuel_RC::OnBnClickedButtonFuelflowRc()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	 m_edt_SmfdRc_FuelResponse.Format("300");
	 UpdateData(FALSE);
}
