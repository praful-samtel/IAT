#include "resource.h"

// CDialog_ISIS_ALN dialog

class CDialog_ISIS_ALN : public CDialog
{
	DECLARE_DYNAMIC(CDialog_ISIS_ALN)

public:
	CDialog_ISIS_ALN(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_ISIS_ALN();

// Dialog Data
	enum { IDD = IDD_DIALOG_ISIS_ALN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chk_ISISFC_ALN;
	BOOL m_chk_ISISRC_ALN;
	afx_msg void OnBnClickedCheckIsisfcAln();
	afx_msg void OnBnClickedCheckIsisrcAln();
	afx_msg void OnBnClickedOk();
	CString m_strIsisFCALN;
	CString m_strStatusIsisFCALN;
	CString m_strIsisRCALN;
	CString m_strStatusIsisRCALN;
};
