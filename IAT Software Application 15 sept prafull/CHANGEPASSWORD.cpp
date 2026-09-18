/**************************************************************************************** 
*		Project Name		:	MFD86														*				       
*		File Name			:   CHANGEPASSWORD.cpp										*					   
*		Author				:	Ashutosh										*		                          
*		Date				:	7th July.2016											*			                      
*		Version of file		:	V1.01													*			                      
*		Description 		:	This file consists of the following declarations:       *                                  
*																				        *                                      
*								CCHANGEPASSWORD::										*            
*									CCHANGEPASSWORD(CWnd* pParent):						*						   
*									CDialog(CCHANGEPASSWORD::IDD, pParent)				*                           
*								void CCHANGEPASSWORD::									*
*									DoDataExchange(CDataExchange* pDX)                  *                              
*								BOOL CCHANGEPASSWORD::OnInitDialog()					*                                                                    
*								HBRUSH UserAuthendication_Dlg::							* 
*									OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)    *
*								void CCHANGEPASSWORD::OnClickCancel()					*
*								void CCHANGEPASSWORD::OnChangePassword()				*						
*								BOOL CCHANGEPASSWORD::PreTranslateMessage(MSG* pMsg)	*
*								void CCHANGEPASSWORD::OnCancel()					    *                 
****************************************************************************************/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "SIPU_SDU_GndRig.h"
#include "CHANGEPASSWORD.h"
#include "Datastruct.h"
#include "UserAuthendication.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <dos.h>
#include <io.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CCHANGEPASSWORD dialog


CCHANGEPASSWORD::CCHANGEPASSWORD(CWnd* pParent /*=NULL*/)
	: CDialog(CCHANGEPASSWORD::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCHANGEPASSWORD)
	m_TxtCurrentPassword = _T("");
	m_TxtNewPassword = _T("");
	m_TxtConfirmPassword = _T("");
	m_TxtUserName = _T("");
	//}}AFX_DATA_INIT
//	brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa)); 
}

/*****************************************************************************
*  Function Name    = DoDataExchange()                                       *                       
*  Class            = CBezel_Key_Dlg66										 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDataExchange* pDX                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to perform data exchange.        *                        							                               
*****************************************************************************/

void CCHANGEPASSWORD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCHANGEPASSWORD)
	DDX_Text(pDX, IDC_EDT_PASSWORD5, m_TxtCurrentPassword);
	DDX_Text(pDX, IDC_EDT_PASSWORD3, m_TxtNewPassword);
	DDX_Text(pDX, IDC_EDT_PASSWORD4, m_TxtConfirmPassword);
	DDX_Text(pDX, IDC_EDIT7, m_TxtUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCHANGEPASSWORD, CDialog)
	//{{AFX_MSG_MAP(CCHANGEPASSWORD)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_BTN_CHANGEPWD, OnChangePassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCHANGEPASSWORD message handlers

/*****************************************************************************
*  Function Name    = OnCtlColor()                                           *                       
*  Class            = CBezel_Key_Dlg66		                                 *                       
*  Return Type      = HBRUSH                                                 *                       
*  Parameters       = CDC* pDC, CWnd* pWnd, UINT nCtlColor                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = It changes attributes of DC when default is desired    *
*					  otherwise return a different brush                     * 
*****************************************************************************/

HBRUSH CCHANGEPASSWORD::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( (nCtlColor == CTLCOLOR_DLG) || (nCtlColor == CTLCOLOR_STATIC) )   
	{
		pDC->SetBkMode(BACKGROUND_COLOR);
		return brushNew;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

/*****************************************************************************
*  Function Name    = OnInitDialog()                                         *                       
*  Class            = CBezel_Key_Dlg66                                       *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to initialize the dialog box     *                    							                               
*****************************************************************************/

BOOL CCHANGEPASSWORD::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	UpdateData (true);
	m_Tooltip.Create(this);
	m_Tooltip.Activate (true);
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_CHANGEPWD),"Click here to change the password");
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_CANCEL),"Click here to cancel the entries");
	UpdateData (false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*****************************************************************************
*  Function Name    = OnCancel()                                             *                       
*  Class            = CBezel_Key_Dlg66				                         *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None				                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to cancel the process			 *        							                               
*****************************************************************************/
void CCHANGEPASSWORD::OnCancel() 
{
	// TODO: Add your control notification handler code here
	OnOK();	
}

/*****************************************************************************
*  Function Name    = OnChangePassword()                                     *                       
*  Class            = CBezel_Key_Dlg66				                         *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None				                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to start the procedure of        *
*				      changing the password, this procedure consists of      *
*					  various constraints & conditions     					 *		                               
*****************************************************************************/
void CCHANGEPASSWORD::OnChangePassword() 
{
	//variable declaration
	unsigned short usLoopIndex = 0,usUserFlag = 0,usSubLoop = 0,usUserNameLength = 0,usPassWordLength = 0;
	int iFileReturnValue = 0;
	int iFileRetVal = 0,iFilenum = 0;
	unsigned long ulNumberOfUsers = 0,ulFileLength = 0;
	char arr_cNewPassword[100]={'\0'};
	CString csUserName = "";

	FILE *pfUserDetails;
	USER_DETAILS UserDetails,UserDetailsEncoded,UserDetailsDecoded,UserDetailsToBeDecoded;
	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();


	UpdateData(true);		

	if(m_TxtUserName == _T(""))
	{
		AfxMessageBox("Please Enter a valid User Name");
		return;
	}

	char carrSysDir1[512], carrSysDir[512], carrUserDetailsFilePath[512];
	unsigned long ulSysDirPathLen;
	ulSysDirPathLen = GetSystemDirectory(carrSysDir, 512);
	GetCurrentDirectory(_MAX_PATH,carrSysDir);
	strcpy(carrUserDetailsFilePath, carrSysDir);
	strcat(carrUserDetailsFilePath, "UserDetails.txt");

	//if(strlen(carrSysDir) == ulSysDirPathLen && ulSysDirPathLen > 1)
	{
		//Append the File path to the system path
		//if(carrSysDir[ulSysDirPathLen - 1] != '\\')
		{
			//strcat(carrSysDir, "\\");
		}

		strcpy(carrUserDetailsFilePath, carrSysDir);
		strcat(carrUserDetailsFilePath, "UserDetails.txt");
	}
	//else
	{
		//AfxMessageBox("Failed to get the system path");
		//return;
	}
	
	pfUserDetails = fopen("UserDetails.txt","a+");
	fseek(pfUserDetails,0,SEEK_SET);
	if(pfUserDetails == NULL)
	{
		AfxMessageBox("File Open Error");
	}
	
	fseek(pfUserDetails,0,SEEK_SET);
	//Get the number of users from the file
	iFileRetVal = fread(&ulNumberOfUsers,sizeof(unsigned long),1,pfUserDetails);
	if(iFileRetVal == 0)
	{
		AfxMessageBox("Sample");
		return;
	}

	iFilenum = _fileno(pfUserDetails);
	ulFileLength = _filelength(iFilenum);

	//Check if the corresponding user name exists
	csUserName = m_TxtUserName;
	fseek(pfUserDetails,0,SEEK_SET);
	for(usLoopIndex = 0;usLoopIndex < ulNumberOfUsers;usLoopIndex++)
	{
		iFileRetVal = fread(&UserDetailsToBeDecoded,sizeof(USER_DETAILS),1,pfUserDetails);

		if(iFileRetVal == 0)
		{
			//AfxMessageBox("File Read Fail");
			return;
			break;
		}
		
		//Decode the structure obtained from the file before comparision
		usUserNameLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cUserNames);
		usPassWordLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cPassword);
		for(usSubLoop = 0;usSubLoop < usUserNameLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cUserNames[usSubLoop] = ((UserDetailsToBeDecoded.arr_cUserNames[usSubLoop] ^ 0xaa) - 0x20);
		}
		for(usSubLoop = 0;usSubLoop < usPassWordLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cPassword[usSubLoop] = ((UserDetailsToBeDecoded.arr_cPassword[usSubLoop] ^ 0xaa) - 0x20);
		}
		pMainFrame->m_UserDetails[usLoopIndex] = UserDetailsDecoded;
		pMainFrame->m_NumberOfUsers.ulNumberofUsers = ulNumberOfUsers;


		if(csUserName == UserDetailsDecoded.arr_cUserNames)
		{
			usUserFlag = 1;
		}
		else
		{
			usUserFlag = 0;
			break;
		}		
	}
	if(usUserFlag == 1)
	{
		AfxMessageBox("Invalid User Name");
		return;
	}

	//Check if the password matches with the corresponding User ID
	if(UserDetailsDecoded.arr_cPassword == m_TxtCurrentPassword)
	{
		AfxMessageBox("Invalid Password");
		return;
	}

	//Check if the new pwd matches with the confirming pwd
	if(m_TxtNewPassword != m_TxtConfirmPassword)
	{
		AfxMessageBox("Invalid Password");
		return;
	}
	fclose(pfUserDetails);
	//pfUserDetails = fopen(carrUserDetailsFilePath,"rb");
	pfUserDetails = fopen("UserDetails.txt","a+");

	//Change the old password
	fseek(pfUserDetails,0,SEEK_SET);
	//iFileRetVal = fread(&ulNumberOfUsers,sizeof(unsigned long),1,pfUserDetails);
	for(usLoopIndex = 0;usLoopIndex < ulNumberOfUsers;usLoopIndex++)
	{
		iFileRetVal = fread(&UserDetailsToBeDecoded,sizeof(USER_DETAILS),1,pfUserDetails);

		if(iFileRetVal == 0)
		{
			//AfxMessageBox("File Read Fail");
			//return;
			break;
		}
		
		//Decode the structure obtained from the file before comparision
		usUserNameLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cUserNames);
		usPassWordLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cPassword);
		for(usSubLoop = 0;usSubLoop < usUserNameLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cUserNames[usSubLoop] = ((UserDetailsToBeDecoded.arr_cUserNames[usSubLoop] ^ 0xaa) - 0x20);
		}
		for(usSubLoop = 0;usSubLoop < usPassWordLength;usSubLoop++)
		{
			UserDetailsDecoded.arr_cPassword[usSubLoop] = ((UserDetailsToBeDecoded.arr_cPassword[usSubLoop] ^ 0xaa) - 0x20);
		}
		

		if(UserDetailsDecoded.arr_cUserNames == m_TxtUserName)
		{
			fseek(pfUserDetails,(-1 * (long)sizeof(USER_DETAILS)),SEEK_CUR);
			sprintf(arr_cNewPassword,"%s",m_TxtNewPassword);
			strcpy(UserDetailsDecoded.arr_cPassword,arr_cNewPassword);
			strcpy(UserDetails.arr_cPassword,arr_cNewPassword);	
			usUserNameLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cUserNames);
			usPassWordLength = sizeof(pMainFrame->m_UserDetails[usLoopIndex].arr_cPassword);
			for(usSubLoop = 0;usSubLoop < usUserNameLength;usSubLoop++)
			{
				UserDetailsEncoded.arr_cUserNames[usSubLoop] = ((UserDetailsDecoded.arr_cUserNames[usSubLoop] + 0x20) ^ 0xaa);
			}
			for(usSubLoop = 0;usSubLoop < usPassWordLength;usSubLoop++)
			{
				UserDetailsEncoded.arr_cPassword[usSubLoop] = ((UserDetailsDecoded.arr_cPassword[usSubLoop] + 0x20) ^ 0xaa);
			}
			UserDetailsEncoded.uc_Type = ((UserDetails.uc_Type + 0x20) ^ 0xaa);
			UserDetailsEncoded.uc_Type = ((UserDetailsDecoded.uc_Type + 0x20) ^ 0xaa);
			iFileReturnValue =	fwrite((const void *)&UserDetailsEncoded,sizeof(UserDetailsDecoded),1,pfUserDetails);
			if(iFileRetVal == 0)
			{
				AfxMessageBox("File Write Failed");
				return;
			}
			
			break;
		}
	}
	fclose(pfUserDetails);
	AfxMessageBox("Password Changed Successfully");
}

/*****************************************************************************
*  Function Name    = PreTranslateMessage()                                  *                       
*  Class            = CBezel_Key_Dlg66                                       *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = MSG* pMsg                                              *                       
*  Visibility       = Protected                                              *                       
*  Description      =                     							                               
*****************************************************************************/

BOOL CCHANGEPASSWORD::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_Tooltip.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
