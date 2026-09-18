/******************************************************************************************************
*		Project Name		:	MFD86																  *
*		File Name			:	AddUser.cpp															  *
*		Author				:	Ashutosh															  *
*		Date				:	7th July.2016														  *
*		Version of file		:	V1.01																  *
*		Description 		:	This file consists of the following declarations:                     *
*																									  *
*									CAddUser::CAddUser(CWnd* pParent)                                 *
*										: CDialog(CAddUser::IDD, pParent)                             *
*									void CAddUser::DoDataExchange(CDataExchange* pDX)                 *
*									HBRUSH CAddUser::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) *
*									void CAddUser::OnAddUser()                                        *
*									BOOL CAddUser::OnInitDialog()                                     *
*									BOOL CAddUser::PreTranslateMessage(MSG* pMsg)                     *
*									void CAddUser::OnBtnCancel()                                      * 
*									void CAddUser::OnChangeEdit2()                                    *
*******************************************************************************************************/


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "SIPU_SDU_GndRig.h"
#include "AddUser.h"
#include "Datastruct.h"
#include "UserAuthendication.h"
#include<iostream>
#include <conio.h>
#include <string>
#include<dos.h>
#include <io.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddUser dialog


CAddUser::CAddUser(CWnd* pParent /*=NULL*/)
	: CDialog(CAddUser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddUser)
	m_TxtConfirmPassword = _T("");
	m_TxtCurrentPassword = _T("");
	m_TxtNewUserName = _T("");
	m_TxtNewPassword = _T("");
	m_Admin = _T("");
	//}}AFX_DATA_INIT
//	brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa)); 
}

/****************************************************************************************************
*  Function Name    = DoDataExchange()                                                              *
*  Class            = CAddUser                                                                      *
*  Return Type      = void                                                                          *
*  Parameters       = CDataExchange* pDX                                                            *
*  Visibility       = Protected                                                                     *
*  Description      = This function is used to perform data exchange.																		                              
*****************************************************************************************************/

void CAddUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddUser)
	DDX_Control(pDX, IDC_COMBO1, m_UsrType);
	DDX_Text(pDX, IDC_EDT_PASSWORD2, m_TxtConfirmPassword);
	DDX_Text(pDX, IDC_EDIT3, m_TxtCurrentPassword);
	DDX_Text(pDX, IDC_EDIT1, m_TxtNewUserName);
	DDX_Text(pDX, IDC_EDT_PASSWORD, m_TxtNewPassword);
	DDX_Text(pDX, IDC_EDIT2, m_Admin);
	//}}AFX_DATA_MAP

}


BEGIN_MESSAGE_MAP(CAddUser, CDialog)
	//{{AFX_MSG_MAP(CAddUser)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_ADD, OnAddUser)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddUser message handlers

/****************************************************************************************************
*  Function Name    = OnCtlColor()                                                                  *
*  Class            = CAddUser                                                                      *
*  Return Type      = HBRUSH		                                                                *
*  Parameters       = CDC* pDC, CWnd* pWnd, UINT nCtlColor                                          *
*  Visibility       = Protected                                                                     *
*  Description      = It changes attributes of DC when default is desired otherwise return a 		*
*					  different brush.																*                      
*****************************************************************************************************/

HBRUSH CAddUser::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
		// TODO: Change any attributes of the DC here
	if( (nCtlColor == CTLCOLOR_DLG) || (nCtlColor == CTLCOLOR_STATIC) )   
	{
		pDC->SetBkMode(BACKGROUND_COLOR);
		return brushNew;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

/****************************************************************************************************
*  Function Name    = OnAddUser()                                                                   *
*  Class            = CAddUser                                                                      *
*  Return Type      = void                                                                          *
*  Parameters       = None                                                                          *
*  Visibility       = Protected                                                                     *
*  Description      = This function create a new user account. The user details are encoded in the  *                      
*                     userdetails.txt file															*
*****************************************************************************************************/

void CAddUser::OnAddUser() 
{
	
	int iFileRetVal,iFilenum;
	unsigned long ulNumberOfUsers,ulFileLength,ulTotalUsers;
	unsigned short usUserNameLength,usPassWordLength,usUserFlag = 0,usLoopIndex,usSubLoop;
	char arr_cNewPassword[500]={'\0'},arr_cNewUserName[20];
	char carrSysDir1[512], carrSysDir[512], carrUserDetailsFilePath[512];
	unsigned long ulSysDirPathLen;
	CString csListOfUsers;
	CString csComboString;
	FILE *pfUserDetails, *pfUserDetails1;
	USER_DETAILS UserDetails,UserDetailsDecoded,UserDetailsEncoded;


	UpdateData(true);
	ulSysDirPathLen = GetSystemDirectory(carrSysDir, 512);
	GetCurrentDirectory(_MAX_PATH,carrSysDir);
	strcpy(carrUserDetailsFilePath, carrSysDir);
	strcat(carrUserDetailsFilePath, "UserDetails.txt");
 	//ulSysDirPathLen = GetSystemDirectory(carrSysDir, 512);

	//if(strlen(carrSysDir) == ulSysDirPathLen && ulSysDirPathLen > 1)
	{
		//Append the File path to the system path
		//if(carrSysDir[ulSysDirPathLen - 1] != '\\')
		{
			//strcat(carrSysDir, "\\");
			//strcpy(carrSysDir1, "C:\PC-SW-BACKUP\ATP_SW\Latest\ISIS_UT_TSQ_1V00_8_8_17\Debug");
		}

		strcpy(carrUserDetailsFilePath, carrSysDir1);
		strcat(carrUserDetailsFilePath, "UserDetails.txt");
	}
	//else
	{
		//AfxMessageBox("Failed to get the system path");
		//return;
	}


	if(m_TxtNewUserName == "")
	{
		AfxMessageBox("Invalid UserName");
		return;
	}

	if(m_TxtNewPassword != m_TxtConfirmPassword)
	{
		AfxMessageBox("Invalid Password");
		return;
	}
	
	pfUserDetails = fopen("UserDetails.txt","a+");
	fseek(pfUserDetails,0,SEEK_SET);
	if(pfUserDetails == NULL)
	{
		AfxMessageBox("File Open Failed");
		return;
	}

	UpdateData(false);

	fseek(pfUserDetails,0,SEEK_SET);
	iFileRetVal = fread(&ulNumberOfUsers,sizeof(unsigned long),1,pfUserDetails);
	//fclose(pfUserDetails);
	
	iFilenum = _fileno(pfUserDetails);
	ulFileLength = _filelength(iFilenum);
	ulTotalUsers = ulNumberOfUsers + 1;

	//fseek(pfUserDetails,0,SEEK_SET);
	
	//iFileRetVal = fwrite(&ulTotalUsers,sizeof(unsigned long),1,pfUserDetails);
	/*if(iFileRetVal == 0)
	{
		AfxMessageBox("File Write Failed");
		return;
	}*/

	//for(usLoopIndex = 0;usLoopIndex < ulNumberOfUsers;usLoopIndex++)
	for(usLoopIndex = 0;usLoopIndex < ulNumberOfUsers;usLoopIndex++)
	{
		iFileRetVal = fread(&UserDetails,sizeof(USER_DETAILS),1,pfUserDetails);
		if(iFileRetVal == 0)
		{
			//AfxMessageBox("File Read Fail");
			//return;
			//break;
		}

		//Decode the structure obtained from the file before comparision
		usUserNameLength = sizeof(UserDetails.arr_cUserNames);
		usPassWordLength = sizeof(UserDetails.arr_cPassword);
		for(usSubLoop = 0;usSubLoop < usUserNameLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cUserNames[usSubLoop] = ((UserDetails.arr_cUserNames[usSubLoop] ^ 0xaa) - 0x20);
		}
		for(usSubLoop = 0;usSubLoop < usUserNameLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cPassword[usSubLoop] = ((UserDetails.arr_cPassword[usSubLoop] ^ 0xaa) - 0x20);
		}
		UserDetailsDecoded.uc_Type = ((UserDetails.uc_Type ^ 0xaa) - 0x20);
		
		if(m_Admin == UserDetailsDecoded.arr_cUserNames)
		{
			usUserFlag = 1;
		}
		else if(m_TxtCurrentPassword == UserDetailsDecoded.arr_cPassword)
		{
			usUserFlag = 1;			
		}
		else if(UserDetailsDecoded.uc_Type != 1)
		{
			usUserFlag = 1;			
		}
		else
		{
			usUserFlag = 0;
			break;
		}
		//csListOfUsers.Format("%s",UserDetailsDecoded.arr_cUserNames);
	}
	fclose(pfUserDetails);

	//Verify If the User is Valid To create a new User
	if(m_Admin == "Operator" || m_TxtCurrentPassword == "operator"){
		AfxMessageBox("No Access to create Users");
		return;
	}
	if(usUserFlag == 0)
	{
		AfxMessageBox("No Access to create Users");
		return;
	}
	
	//Open the file in append mode

	pfUserDetails = fopen("UserDetails.txt","a+");
	fseek(pfUserDetails,0,SEEK_SET);
	if(pfUserDetails == NULL)
	{
		AfxMessageBox("File Open Error");
		return;
	}

	sprintf(arr_cNewUserName,"%s",m_TxtNewUserName);
	strcpy(UserDetails.arr_cUserNames,arr_cNewUserName);
	sprintf(arr_cNewPassword,"%s",m_TxtNewPassword);
	strcpy(UserDetails.arr_cPassword,arr_cNewPassword);	
	if(m_UsrType.GetCurSel() == 0)
	UserDetails.uc_Type=1;
	else
	UserDetails.uc_Type=2;
	usUserNameLength = sizeof(UserDetails.arr_cUserNames);
	usPassWordLength = sizeof(UserDetails.arr_cPassword);
	for(usLoopIndex = 0;usLoopIndex < usUserNameLength;usLoopIndex++)
	{
		UserDetailsEncoded.arr_cUserNames[usLoopIndex] = ((UserDetails.arr_cUserNames[usLoopIndex] + 0x20) ^ 0xaa);
	}
	for(usLoopIndex = 0;usLoopIndex < usPassWordLength;usLoopIndex++)
	{
		UserDetailsEncoded.arr_cPassword[usLoopIndex] = ((UserDetails.arr_cPassword[usLoopIndex] + 0x20) ^ 0xaa);
	}
	UserDetailsEncoded.uc_Type= ((UserDetails.uc_Type + 0x20) ^ 0xaa);
	for(usLoopIndex = 0;usLoopIndex < ulNumberOfUsers;usLoopIndex++)
	{
		//m_CboListOfUsers.GetLBText(usLoopIndex, csComboString);
		
		if(UserDetailsDecoded.arr_cUserNames == m_TxtNewUserName)
		{
			AfxMessageBox("Cannot Create User.The User Already Exists");
			pfUserDetails = fopen("UserDetails.txt","a+");
			fseek(pfUserDetails,0,SEEK_SET);
			iFileRetVal = fwrite(&ulNumberOfUsers,sizeof(unsigned long),1,pfUserDetails);
			if(iFileRetVal == 0)
			{
				AfxMessageBox("File Write Failed");
				return;
			}
			fclose(pfUserDetails);

			return;
		}
		break;
	}

	iFileRetVal = fwrite((const void *)&UserDetailsEncoded,sizeof(UserDetails),1,pfUserDetails);
	if(iFileRetVal == 0)
	{
		AfxMessageBox("File Write Failed");
		return;
	}
	fclose(pfUserDetails);

	//Update the Combo Box
//	m_CboListOfUsers.InsertString((m_CboListOfUsers.GetCount()),m_TxtNewUserName);
	//m_CboListOfUsers.SetCurSel((m_CboListOfUsers.GetCount()-1));

	AfxMessageBox("New User Created Successfully");

	UpdateData(false);
}

/****************************************************************************************************
*  Function Name    = OnInitDialog()                                                                *
*  Class            = CAddUser                                                                      *
*  Return Type      = Boolean                                                                       *
*  Parameters       = None                                                                          *
*  Visibility       = Protected                                                                     *
*  Description      = This function is used to initialize dialog box which consists of two buttons  *
                      i.e Add New User button to add new user and Cancel button to close dialog box *                 
*****************************************************************************************************/

BOOL CAddUser::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData (true);
	m_Tooltip.Create(this);
	m_Tooltip.Activate (true);
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_ADD),"Click here to add new user");
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_CANCEL),"Click here to cancel the entries");
	UpdateData (false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/****************************************************************************************************
*  Function Name    = PreTranslateMessage()                                                         *
*  Class            = CAddUser                                                                      *
*  Return Type      = Boolean                                                                       *
*  Parameters       = MSG* pMsg                                                                     *
*  Visibility       = Protected                                                                     *
*  Description      = This function return the dialog box with written message before translation	*																		                      
*****************************************************************************************************/

BOOL CAddUser::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_Tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

/****************************************************************************************************
*  Function Name    = OnBtnCancel()                                                                 *
*  Class            = CAddUser                                                                      *
*  Return Type      = void                                                                          *
*  Parameters       = None                                                                          *
*  Visibility       = Protected                                                                     *
*  Description      = This function closes the  AddUser dialog box.							        *                      
*****************************************************************************************************/

void CAddUser::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnCancel();

}
