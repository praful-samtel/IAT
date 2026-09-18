#pragma once
#include "afxwin.h"
#include "resource.h"
#include "DataStruct.h"
#include "SMFDAnalogMonitor.h"
// CDialog_Smfd_Analog dialog
#define WM_UPDATE_OILTEMP (WM_USER + 102)
class CDialog_Smfd_Analog : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Smfd_Analog)

public:
	CDialog_Smfd_Analog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_Smfd_Analog();
    afx_msg LRESULT OnUpdateOilTemp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateSMFDAnalog(
    WPARAM wParam,
    LPARAM lParam
);

    static UINT ArincMonitorThread(LPVOID pParam);
// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_ANALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	CString m_edtoiltemp;
	CString m_stroiltemp;
	CString m_strStatusoiltemp;


	afx_msg void OnBnClickedButtonSmfdAnalog();
	afx_msg void OnBnClickedOk();
private:
    CString m_strOilTempValue;
};
