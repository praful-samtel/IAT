/**************************************************************************************** 
*		Project Name		:	MFD86														*				       
*		File Name			:   UserAuthendication.cpp									*					   
*		Author				:	Ashutosh										*		                          
*		Date				:	7th July.2016											*			                      
*		Version of file		:	V1.01													*			                      
*		Description 		:	This file consists of the following declarations:       *                                  
*																				        *                                      
*								CUserAuthendication_Dlg::								*            
*									CUserAuthendication_Dlg(CWnd* pParent):				*						   
*									CDialog(CUserAuthendication_Dlg::IDD, pParent)		*                           
*								void CUserAuthendication_Dlg::							*
*									DoDataExchange(CDataExchange* pDX)                  *                              
*								void CUserAuthendication_Dlg::OnContinue()				*                                                                    
*								HBRUSH UserAuthendication_Dlg::							* 
*									OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)    *
*								void CUserAuthendication::OnAddNewUser()				*                             								*                  
*								void CUserAuthendication::OnLogin()						*
*								void CUserAuthendication::OnClickCancel()				*
*								void CUserAuthendication::OnBtnChangePasswrd()			*
*								BOOL CUserAuthendication::OnInitDialog()				*
*								BOOL CUserAuthendication::PreTranslateMessage(MSG* pMsg)*
*								void CUserAuthendication::OnClose()						*                 
****************************************************************************************/

// UserAuthendication.cpp : implementation file
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "UserAuthendication.h"
#include "MainFrm.h"
#include "AddUser.h"
#include "CHANGEPASSWORD.h"
#include "Macros.h"
#include <io.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserAuthendication dialog
extern char g_cAdminstrator;

CUserAuthendication::CUserAuthendication(CWnd* pParent /*=NULL*/)
	: CDialog(CUserAuthendication::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserAuthendication)
	//m_TxtUserName = _T("Administrator");
	m_TxtUserName = _T("Operator");
	m_TxtEditPassword = _T("");
	//}}AFX_DATA_INIT
//	//brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa)); 
}

/*****************************************************************************
*  Function Name    = DoDataExchange()                                       *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDataExchange* pDX                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to perform data exchange.        *                        							                               
*****************************************************************************/

void CUserAuthendication::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserAuthendication)
	DDX_Text(pDX, IDC_EDIT1, m_TxtUserName);
	DDX_Text(pDX, IDC_EDT_PASSWORD, m_TxtEditPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserAuthendication, CDialog)
	//{{AFX_MSG_MAP(CUserAuthendication)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_ADD_USER, OnAddNewUser)
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnLogin)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnClickCancel)
	ON_BN_CLICKED(IDC_BTN_CHANGE_PASSWRD, OnBtnChangePasswrd)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
//	ON_BN_CLICKED(IDC_BUTTON1, &CUserAuthendication::OnBnClickedButton1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserAuthendication message handlers

/*****************************************************************************
*  Function Name    = OnCtlColor()                                           *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = HBRUSH                                                 *                       
*  Parameters       = CDC* pDC, CWnd* pWnd, UINT nCtlColor                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = It changes attributes of DC when default is desired    *
*					  otherwise return a different brush                     *   							                               
*****************************************************************************/

HBRUSH CUserAuthendication::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
*  Function Name    = OnAddNewUser()                                         *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to add new user into the system  *  							                               
*****************************************************************************/

void CUserAuthendication::OnAddNewUser() 
{
	// TODO: Add your control notification handler code here
	CAddUser dlg_obj;
	dlg_obj.DoModal();

}

/*****************************************************************************
*  Function Name    = OnLogin()	                                             *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to login into the system, in this*
*					  function various validity checks is imposed i.e        * 
*					  username & password is necessary for login etc.		 *					                               
*****************************************************************************/
void CUserAuthendication::OnLogin()
{
	UpdateData(true);

	int iFileRetVal = 0;
	unsigned short usLoopIndex = 0;
	unsigned long ulNumberOfUsers = 0, ulFileLength = 0;
	int iFilenum = 0, iFileReturnValue = 0;
	unsigned short usSubLoop, usUserNameLength = 0, usPassWordLength = 0;
	CString csUserName = "";

	FILE *pfUserDetails;
	USER_DETAILS UserDetailsEncoded, UserDetailsDecoded, UserDetailsToBeDecoded, UserDetails;
	memset(&UserDetailsEncoded,     0, sizeof(USER_DETAILS));
	memset(&UserDetailsDecoded,     0, sizeof(USER_DETAILS));
	memset(&UserDetailsToBeDecoded, 0, sizeof(USER_DETAILS));
	memset(&UserDetails,            0, sizeof(USER_DETAILS));

	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

	pMainFrame->bDPAdminFlag = false;
	pMainFrame->m_strLogin_UserName = m_TxtUserName;

	if(m_TxtUserName == _T(""))
	{
		AfxMessageBox("Please Enter a valid User Name");
		return;
	}

	pfUserDetails = fopen("UserDetails.txt", "a+");
	fseek(pfUserDetails, 0, SEEK_END);
	int size = ftell(pfUserDetails);

	if(size == 0)
	{
		// ---- First run: no file yet, seed default Administrator / Operator accounts ----
		fclose(pfUserDetails);
		pfUserDetails = fopen("UserDetails.txt", "a+");
		fseek(pfUserDetails, 0, SEEK_SET);

		strcpy(pMainFrame->m_UserDetails[0].arr_cUserNames, "Administrator");
		strcpy(pMainFrame->m_UserDetails[0].arr_cPassword, "admin");
		pMainFrame->m_UserDetails[0].uc_Type = 1;

		strcpy(pMainFrame->m_UserDetails[1].arr_cUserNames, "Operator");
		strcpy(pMainFrame->m_UserDetails[1].arr_cPassword, "operator");
		pMainFrame->m_UserDetails[1].uc_Type = 0;

		ulNumberOfUsers = 2;

		iFileRetVal = fwrite(&ulNumberOfUsers, sizeof(unsigned long), 1, pfUserDetails);
		if(iFileRetVal == 0)
		{
			AfxMessageBox("File Write Failed");
			fclose(pfUserDetails);
			return;
		}

		for(usLoopIndex = 0; usLoopIndex < ulNumberOfUsers; usLoopIndex++)
		{
			UserDetails = pMainFrame->m_UserDetails[usLoopIndex];

			for(usSubLoop = 0; usSubLoop < sizeof(UserDetails.arr_cUserNames); usSubLoop++)
				UserDetailsEncoded.arr_cUserNames[usSubLoop] = ((UserDetails.arr_cUserNames[usSubLoop] + 0x20) ^ 0xaa);

			for(usSubLoop = 0; usSubLoop < sizeof(UserDetails.arr_cPassword); usSubLoop++)
				UserDetailsEncoded.arr_cPassword[usSubLoop] = ((UserDetails.arr_cPassword[usSubLoop] + 0x20) ^ 0xaa);

			UserDetailsEncoded.uc_Type = ((UserDetails.uc_Type + 0x20) ^ 0xaa);

			iFileReturnValue = fwrite((const void *)&UserDetailsEncoded, sizeof(USER_DETAILS), 1, pfUserDetails);
			if(iFileReturnValue == 0)
			{
				AfxMessageBox("File Write Failed");
				fclose(pfUserDetails);
				return;
			}
		}
		fclose(pfUserDetails);

		// Seeded accounts only just now created; user still needs to log in properly next time.
		AfxMessageBox("Default accounts created. Please log in again.");
		return;
	}
	else
	{
		// ---- File already exists: read user count, then search for a matching user ----
		fclose(pfUserDetails);
		pfUserDetails = fopen("UserDetails.txt", "a+");
		fseek(pfUserDetails, 0, SEEK_SET);

		iFileRetVal = fread(&ulNumberOfUsers, sizeof(unsigned long), 1, pfUserDetails);
		if(iFileRetVal == 0)
		{
			AfxMessageBox("File Read Failed");
			fclose(pfUserDetails);
			return;
		}

		iFilenum = _fileno(pfUserDetails);
		ulFileLength = _filelength(iFilenum);

		csUserName = m_TxtUserName;

		BOOL bUserFound = FALSE;
		USER_DETAILS MatchedUser;
		memset(&MatchedUser, 0, sizeof(USER_DETAILS));

		for(usLoopIndex = 0; usLoopIndex < ulNumberOfUsers; usLoopIndex++)
		{
			iFileRetVal = fread(&UserDetailsToBeDecoded, sizeof(USER_DETAILS), 1, pfUserDetails);
			if(iFileRetVal == 0)
				break;

			// Decode this record
			usUserNameLength = sizeof(UserDetailsToBeDecoded.arr_cUserNames);
			usPassWordLength = sizeof(UserDetailsToBeDecoded.arr_cPassword);

			for(usSubLoop = 0; usSubLoop < usUserNameLength; usSubLoop++)
				UserDetailsDecoded.arr_cUserNames[usSubLoop] = ((UserDetailsToBeDecoded.arr_cUserNames[usSubLoop] ^ 0xaa) - 0x20);

			for(usSubLoop = 0; usSubLoop < usPassWordLength; usSubLoop++)
				UserDetailsDecoded.arr_cPassword[usSubLoop] = ((UserDetailsToBeDecoded.arr_cPassword[usSubLoop] ^ 0xaa) - 0x20);

			UserDetailsDecoded.uc_Type = ((UserDetailsToBeDecoded.uc_Type ^ 0xaa) - 0x20);

			pMainFrame->m_UserDetails[usLoopIndex] = UserDetailsDecoded;

			if(csUserName == UserDetailsDecoded.arr_cUserNames)
			{
				bUserFound = TRUE;
				MatchedUser = UserDetailsDecoded;
				break;   // stop as soon as we find the matching user
			}
		}

		pMainFrame->m_NumberOfUsers.ulNumberofUsers = ulNumberOfUsers;

		if(!bUserFound)
		{
			fclose(pfUserDetails);
			AfxMessageBox("Invalid User Name");
			return;
		}

		if(m_TxtEditPassword != MatchedUser.arr_cPassword)
		{
			fclose(pfUserDetails);
			AfxMessageBox("Invalid Password");
			m_TxtEditPassword = "";
			UpdateData(false);
			return;
		}

		// Success: set admin flag and admin/operator marker based on the matched user's type
		if(MatchedUser.uc_Type == 1)
		{
			pMainFrame->bDPAdminFlag = true;
			g_cAdminstrator = 1;
		}
		else
		{
			g_cAdminstrator = 2;
		}

		fclose(pfUserDetails);
	}

	CDialog::OnOK();
}

/*****************************************************************************
*  Function Name    = OnClickCancel()	                                     *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to exit.						 *   							                               
*****************************************************************************/

void CUserAuthendication::OnClickCancel() 
{
	//PostQuitMessage(15) ;
	exit(0);
}

/*****************************************************************************
*  Function Name    = OnBtnChangePasswrd()                                   *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to change the password of the    *
*					  user   							                     *          
*****************************************************************************/

void CUserAuthendication::OnBtnChangePasswrd() 
{
	CCHANGEPASSWORD dlg_obj;
	dlg_obj.DoModal();
	// TODO: Add your control notification handler code here
	
}

/*****************************************************************************
*  Function Name    = OnInitDialog()                                         *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = None													 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to initialize the dialog box     *  							                               
*****************************************************************************/

BOOL CUserAuthendication::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData (true);
	m_Tooltip.Create(this);
	m_Tooltip.Activate (true);
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_LOGIN),"Login");
    m_Tooltip.AddTool(GetDlgItem (IDC_BTN_CHANGE_PASSWRD),"Modify Password");
	m_Tooltip.AddTool(GetDlgItem (IDC_BTN_ADD_USER),"Create New User Account");
	//m_Tooltip.AddTool(GetDlgItem (IDC_BTN_CANCEL),"Click here to quit from the application");
	UpdateData (false);

	//CMenu* mnu = this->GetSystemMenu(FALSE);
	//mnu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*****************************************************************************
*  Function Name    = PreTranslateMessage()                                  *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = MSG* pMsg                                              *                       
*  Visibility       = Protected                                              *                       
*  Description      =                      
*****************************************************************************/

BOOL CUserAuthendication::PreTranslateMessage(MSG* pMsg) 
{
	/* check for Esc Key press, if so exit */
	if(pMsg->message==WM_KEYDOWN)
    {
         if(pMsg->wParam==VK_ESCAPE)
         {
		 	 exit(0);
		 }
    } 

	m_Tooltip.RelayEvent(pMsg);	
	return CDialog::PreTranslateMessage(pMsg);
}

/*****************************************************************************
*  Function Name    = OnClose()	                                             *                       
*  Class            = CUserAuthendication									 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to close the dialog box			 *   							                               
*****************************************************************************/

void CUserAuthendication::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnClose();
	exit(0);
}

/*void CUserAuthendication::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
		CDialog::OnClose();
		exit(0);
}*/
