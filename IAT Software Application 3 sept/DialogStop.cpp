// DialogStop.cpp : implementation file
//

#include "stdafx.h"
#include "DialogStop.h"
#include "afxdialogex.h"
#include "Globals.h"

// CDialogStop dialog

IMPLEMENT_DYNAMIC(CDialogStop, CDialogEx)

CDialogStop::CDialogStop(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogStop::IDD, pParent)
{

}

CDialogStop::~CDialogStop()
{
}

void CDialogStop::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogStop, CDialogEx)
	ON_BN_CLICKED(ID_STOP, &CDialogStop::OnBnClickedStop)
END_MESSAGE_MAP()


// CDialogStop message handlers



void CDialogStop::OnBnClickedStop()
{
    g_bStopRequested = TRUE;

    EnableWindow(FALSE);

    SetDlgItemText(ID_STOP,"Stopping...");
}