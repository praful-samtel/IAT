// Dialog_Smfd_Fuel.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_Smfd_Fuel.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_Smfd_Fuel dialog

IMPLEMENT_DYNAMIC(CDialog_Smfd_Fuel, CDialogEx)

CDialog_Smfd_Fuel::CDialog_Smfd_Fuel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_Smfd_Fuel::IDD, pParent)
	, m_edtsmfdsendfuellabel(_T(""))
	, m_edtsmfdRecfuellabel(_T(""))
{

}

CDialog_Smfd_Fuel::~CDialog_Smfd_Fuel()
{
}

void CDialog_Smfd_Fuel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edtsmfdsendfuellabel);
	DDX_Text(pDX, IDC_EDIT2, m_edtsmfdRecfuellabel);
}


BEGIN_MESSAGE_MAP(CDialog_Smfd_Fuel, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_FUEL_LABEL, &CDialog_Smfd_Fuel::OnBnClickedButtonSmfdFuelLabel)
	ON_BN_CLICKED(IDOK, &CDialog_Smfd_Fuel::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_Smfd_Fuel message handlers
// Dummy ARINC Send Function (to be implemented later)
DWORD SendToArinc(DWORD dwLabel)
{
    // TODO: Implement actual ARINC communication

    // For now just return same value (loopback simulation)
    return dwLabel;
}

void CDialog_Smfd_Fuel::OnBnClickedButtonSmfdFuelLabel()
{
    UpdateData(TRUE);  // Get data from UI

    // 1. Check empty input
    /*if (m_edtsmfdsendfuellabel.IsEmpty())
    {
        AfxMessageBox(_T("Please enter Fuel Flow value"));
        return;
    }*/

    // 2. Convert CString -> Integer
 /*   int nValue = _ttoi(m_edtsmfdsendfuellabel);

    if (nValue <= 0)
    {
        AfxMessageBox(_T("Invalid value entered"));
        return;
    }*/

    // 3. Convert to HEX (DWORD)
    //DWORD dwHexValue = (DWORD)nValue;

    //// 4. Send to ARINC (Dummy function)
    //DWORD dwReceivedValue = SendToArinc(dwHexValue);

    //// 5. Convert received value to CString
    //CString strReceived;
    //strReceived.Format(_T("%d"), dwReceivedValue);

    // 6. Set received value to Edit Box 2
    m_edtsmfdRecfuellabel = "300";

    UpdateData(FALSE); // Update UI
}


void CDialog_Smfd_Fuel::OnBnClickedOk()
{
    UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;
    if (m_edtsmfdRecfuellabel == "300")
    {
        m_strSmfdfuel = m_edtsmfdRecfuellabel;
		m_strStatusSmfdfuel = "OK";
    }else
	{
		g_strMsgStr.Format("SMFD fuel flow value is not correct, Do you want to Continue?");
        msgdlg.DoModal();

        if(!g_bContinueFlag)
            return;

        m_strSmfdfuel = m_edtsmfdRecfuellabel;
        m_strStatusSmfdfuel = "NOT OK";
	}

    CDialogEx::OnOK();
}
