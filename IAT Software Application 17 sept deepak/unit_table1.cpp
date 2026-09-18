/************************************************************************************************
*	Project Name		:	ILT																	*
*	File Name			:   unit_table1.cpp														*
*	Author				:	Chaman Lal Sharma												    *
*	Date				:	19th July.2011														*
*	Version of file		:	V1.01																*
*	Description 		:	This file consists of the following declarations:                   *
*							void Table1Unit::DefineColHeadings()								*
*							void Table1Unit::CreatePrintFonts()									*
*							void Table1Unit::InitPrintMetrics()									*
*							BOOL Table1Unit::Print()											*
*							void Table1Unit::PrintHeader()										*
*							void Table1Unit::PrintFooter()										*
**************************************************************************************************/

#include "stdafx.h"
#include "unit_table1.h"
#include "gfx_printjob.h"
#include "DataStruct.h"
#include "SIPUPowerONPage.h"

//#include "SIPUPowerONPage.h"

extern CString g_strFileName;

extern sTest_Result s_Curr_Test_Result;

Table1Unit::Table1Unit(GPrintJob *pJob) : GPrintUnit(pJob)
{
}

Table1Unit::~Table1Unit()
{
}

/*******************************************************************************
*  Function Name    = DefineColHeadings()				                       *
*  Class            = Table1Unit				                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used to display heading content of report*
********************************************************************************/

void Table1Unit::DefineColHeadings()
{
   // define my four columns...percentages should all up to 1.00
   InsertPrintCol(0, "TestNo", 0.07);
   InsertPrintCol(1, "   Test", 0.42);
   InsertPrintCol(2, "Specification", 0.21);
   InsertPrintCol(3, "Measured Value", 0.18);
   InsertPrintCol(4, "Test Status", 0.11);

   // must call base class
   GPrintUnit::DefineColHeadings();
}

/*******************************************************************************
*  Function Name    = CreatePrintFonts()				                       *
*  Class            = Table1Unit				                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used for the font of printing report.   * 
********************************************************************************/

void Table1Unit::CreatePrintFonts()
{
   LOGFONT logFont;
   GMAKESTNUL(logFont);

	LPCTSTR lpszFaceName = _T("Arial");//I18nok

   //logFont.lfCharSet = DEFAULT_CHARSET;
	logFont.lfCharSet = ANSI_CHARSET;
   logFont.lfHeight = 70;
   lstrcpyn(logFont.lfFaceName, lpszFaceName, GCOUNTOF(logFont.lfFaceName));
   logFont.lfWeight = FW_BOLD;

   m_fontHeading.CreatePointFontIndirect(&logFont, &JDC);
   m_fontPairBody.fontPrinter.CreatePointFont(70, lpszFaceName, &JDC);
   m_fontPairBody.fontScreen.CreatePointFont(70, lpszFaceName);

   m_fontHeader.CreatePointFont(110, _T("landscape"), &JDC);//I18nOK
   m_fontFooter.CreatePointFont(90, _T("landscape"), &JDC);//I18nOK
}

/*******************************************************************************
*  Function Name    = InitPrintMetrics()				                       *
*  Class            = Table1Unit				                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used to fomratting of printing of report*
********************************************************************************/

void Table1Unit::InitPrintMetrics()
{
	TEXTMETRIC tm;
	
	{
		GSELECT_OBJECT(&JDC, &m_fontHeader);
		JDC.GetTextMetrics(&tm);
		
		m_pum.pumHeaderHeight = tm.tmHeight * 2;
		m_pum.pumHeaderLineHeight = tm.tmHeight;
	}

	{
		GSELECT_OBJECT(&JDC, &m_fontFooter);
		JDC.GetTextMetrics(&tm);
		
		m_pum.pumFooterHeight = tm.tmHeight * 2;
		m_pum.pumFooterLineHeight = tm.tmHeight;
	}

	
	{
		GSELECT_OBJECT(&JDC, &(m_fontPairBody.fontPrinter));
		JDC.GetTextMetrics(&tm);
		m_pum.pumLineOfText = tm.tmHeight;
	}

	{
		GSELECT_OBJECT(&JDC, &(m_fontHeading));
		JDC.GetTextMetrics(&tm);
		m_pum.pumHeadingHeight = m_pum.pumLineOfText;
	}

	RealizeMetrics();
}

/*******************************************************************************
*  Function Name    = Print()							                       *
*  Class            = Table1Unit				                               *
*  Return Type      = BOOL                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used to display formatting and s.no. of *
*  ATP test.																   *
********************************************************************************/

BOOL Table1Unit::Print()
{
	GPrintUnit::Print();

	StartPage();

	INDEXITEM ii;
	ii.strName = "INTEGRATED AVIONICS TESTER TEST REPORT";
	ii.wPage = (WORD)JINFO.m_nCurPage;
	ii.nFlags = INDEXF_DASHES|INDEXF_PAGENO;

	AddIndexItem(&ii);


	{
		GSELECT_OBJECT(&JDC, &m_fontHeading);
		PrintColHeadings(DT_LEFT);
	}


	GSELECT_PUFONT(&JDC, &m_fontPairBody);
	
   	// open the file to read the data from the test result file
	//char strFileName[250];

	CFile fptr;

	//GetCurrentDirectory(100,strFileName);
	//strcat(strFileName,"\\TestReport.bin");

	if(!(fptr.Open(g_strFileName, CFile::typeBinary | CFile::modeRead| CFile::modeNoTruncate))) 
	{
		AfxMessageBox("\n File open error");
		return FALSE;
	}

	fptr.SeekToBegin();

	//char cMinorTestName[100];
	unsigned long usReadData=0;
	//int iFileRetVal;

	CString strTemp;
	unsigned char ucCol = 0;
	unsigned int uiRow = 1;
	BOOL b_PrintMajorName = FALSE;

	//Dummy Read
	fptr.Read(&s_Index_Page,sizeof(s_Index_Page));

	while(fptr.Read(&s_Curr_Test_Result,sizeof(s_Curr_Test_Result)))
	{
		//if(uiRow >= 60)
		if(uiRow >= 70)
		{
			uiRow = 0;

			EndPage();
			StartPage();
			{
				GSELECT_OBJECT(&JDC, &m_fontHeading);
				PrintColHeadings(DT_LEFT);
			}


			GSELECT_PUFONT(&JDC, &m_fontPairBody);

			//Drawing Line
			uiRow++;
			StartRow();
			ucCol = 0;
			strTemp.Format("--------------------------------------------------------------------------");
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			EndRow();

		}
	
		if(s_Curr_Test_Result.m_uiMinor_Test_ID%100 == 1)
		{
			b_PrintMajorName = TRUE;
		}
		else
		{
			b_PrintMajorName = FALSE;
		}

		if(b_PrintMajorName)
		{
			//Drawing Line
			uiRow++;
			StartRow();
			ucCol = 0;
			strTemp.Format("-------------------------------------------------------------------------");
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			EndRow();


			//Write the Major Test Name

			char strMajorTestName[100];//,strTemp1[50];
			//Temporarily put in 1 and 2 nd column

			uiRow++;
			StartRow();
			ucCol = 0;
			//strTemp.Format("%d. %s",(s_Curr_Test_Result.m_uiMinor_Test_ID / 100),s_Curr_Test_Result.m_strMajorTestName);
			sprintf(strMajorTestName,"%d.",(s_Curr_Test_Result.m_uiMinor_Test_ID / 100));
			PrintCol(ucCol++, strMajorTestName, DT_LEFT); 

			sprintf(strMajorTestName,"%s",s_Curr_Test_Result.m_strMajorTestName);
			PrintCol(ucCol++, strMajorTestName, DT_LEFT); 

			EndRow();
			
			//Drawing Line
			uiRow++;
			StartRow();
			ucCol = 0;
			strTemp.Format("--------------------------------------------------------------------------");
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			PrintCol(ucCol++, strTemp, DT_LEFT); 
			EndRow();

		}

		uiRow++;
		StartRow();

		ucCol = 0;

		strTemp.Format("%.2f",(s_Curr_Test_Result.m_uiMinor_Test_ID / 100.0));
		PrintCol(ucCol++, strTemp, DT_LEFT); 

		strTemp.Format("%10s",s_Curr_Test_Result.m_strMinorTestName);
		PrintCol(ucCol++, strTemp, DT_LEFT); 

		strTemp.Format("%10s",s_Curr_Test_Result.m_strSpec);
		PrintCol(ucCol++, strTemp, DT_LEFT); 

		strTemp.Format("%10s",s_Curr_Test_Result.m_strMeasuered_Val);
		PrintCol(ucCol++, strTemp, DT_LEFT); 

		strTemp.Format("%10s",s_Curr_Test_Result.m_strTestStatus);
		PrintCol(ucCol++, strTemp, DT_LEFT); 

		EndRow();

		//Drawing Line
		uiRow++;
		StartRow();
		ucCol = 0;
		strTemp.Format("-----------------------------------------------------------------------------");
		PrintCol(ucCol++, strTemp, DT_LEFT); 
		PrintCol(ucCol++, strTemp, DT_LEFT); 
		PrintCol(ucCol++, strTemp, DT_LEFT); 
		PrintCol(ucCol++, strTemp, DT_LEFT); 
		PrintCol(ucCol++, strTemp, DT_LEFT); 
		EndRow();

	}


	fptr.Close();

   EndPage();
   return TRUE;
}

/*******************************************************************************
*  Function Name    = PrintHeader()						                       *
*  Class            = Table1Unit				                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used to display Header content in	   *
*  printing report.															   *
********************************************************************************/

void Table1Unit::PrintHeader()
{
   GSELECT_OBJECT(&JDC, &m_fontHeader);

   CString strDateTime;
   // get the current time
   SYSTEMTIME sysTime;
   GetLocalTime(&sysTime);
   // format it...
   TCHAR szBuf[100];
   GMAKENUL(szBuf);
   // get the time
   GetDateFormat(LOCALE_USER_DEFAULT, NULL, &sysTime, NULL, szBuf, sizeof(szBuf));
   strDateTime = szBuf;
   strDateTime += " ";
   // get the date
   GetTimeFormat(LOCALE_USER_DEFAULT, NULL, &sysTime, NULL, szBuf, sizeof(szBuf));
   strDateTime += szBuf;

   //CString strHeader = strDateTime;
   CString strHeader = "IAT TEST REPORT";
   strHeader += HFC_CENTER;
   CString lruname = s_Index_Page.m_strEquipment;
CString mode =  s_Index_Page.m_strExecMode;

if(mode == "Integration")
{
     strHeader += "Integrated Test";
}else
{
	 strHeader += lruname;
}
 
   strHeader += HFC_RIGHTJUSTIFY;
  
   CString strPage;
   strPage.Format("Page: %d", JINFO.m_nCurPage);
	
   strHeader += strPage;

   PrintHeaderText(strHeader);
}

/*******************************************************************************
*  Function Name    = PrintFooter()						                       *
*  Class            = Table1Unit				                               *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Protected                                                *
*  Description      = This function is used to display Footer content in	   *
*  printing report.															   *
********************************************************************************/

void Table1Unit::PrintFooter()
{
   GSELECT_OBJECT(&JDC, &m_fontFooter);

   CString strFooter;

   strFooter = "Test Engineer";
   strFooter += HFC_CENTER;
   strFooter += "";
   strFooter += HFC_RIGHTJUSTIFY;
   strFooter += "Engineer QA";

   PrintFooterText(strFooter);
}
