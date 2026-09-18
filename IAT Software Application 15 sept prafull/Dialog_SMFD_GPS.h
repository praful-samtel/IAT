#pragma once
#include "resource.h"
#include "afxwin.h"

// CDialog_SMFD_GPS dialog

class CDialog_SMFD_GPS : public CDialog
{
	DECLARE_DYNAMIC(CDialog_SMFD_GPS)

public:
	CDialog_SMFD_GPS(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_SMFD_GPS();

// Dialog Data
	enum { IDD = IDD_DIALOG_SMFD_GPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSendarinclabel();
	afx_msg void OnBnClickedOk();
	CString m_edtGpsGrSpd;
	CString m_edtGpsTrueTrack;
	CString m_edtGpsMagTrack;
	CString m_edtGpsTime;
	CString m_strSmfdGpsGrSpd;
	CString m_strStatusSmfdGpsGrSpd;
	CString m_strSmfdGpsTrueTrack;
	CString m_strStatusSmfdGpsTrueTrack;
	CString m_strSmfdGpsMagTrack;
	CString m_strStatusSmfdGpsMagTrack;
	CString m_strSmfdGpsTime;
	CString m_strStatusSmfdGpsTime;
};
