/*************************************************************************************************
*	Project Name		:	ILT																	 *
*	File Name			:   unit_headerpage.cpp			           								 *
*	Author				:	Chaman Lal Sharma												     *
*	Date				:	19th July.2011														 *
*	Version of file		:	V1.01																 *
*	Description 		:	This file consists of the following declarations:                    *
*	BOOL HeaderPage::Print()																     *
**************************************************************************************************/

#include "stdafx.h"
#include "unit_headerpage.h"
#include "gfx_printjob.h"
#include "SIPUPowerONPage.h"
#include "DataStruct.h"
#include "TestTable.h"
#include <math.h>

extern CString g_strFileName;
sTest_Result s_Curr_Test_Result;


HeaderPage::HeaderPage(GPrintJob *pJob) : GPrintUnit(pJob)
{
}

HeaderPage::~HeaderPage()
{
}
/*******************************************************************************
*  Function Name    = Print											           *
*  Class            = HeaderPage			     		                       *
*  Return Type      = BOOL					                                   *
*  Parameters       = None					                                   *
*  Visibility       = Public	                                               *
*  Description      = This function is used for printing header page		   * 
********************************************************************************/
/*
BOOL HeaderPage::Print()
{
	//char strTemp[200], strTemp1[100],strOutput[300];
	char strTemp[1000], strTemp1[1000],strOutput[1000];
	unsigned int iNo_of_Test_performed = 0, i_Performed_Test_ID[DU_ATP_MAX_NO_OF_TEST], iTmpNum; 
	unsigned int i_Tests_NOTOK[DU_ATP_MAX_NO_OF_TEST], i_Test_NOK_Count = 0, iTmp;
	BOOL b_AllTest_OK = TRUE;
	int iString_Start_X_Pos = 800, iString_Start_Y_Pos = 200, iString_Gap = 150, iString_No = 0, iMinorTestID = 0, iAfterded = 0;
	unsigned int bTestTable[20];
	CString strL, strR, strFinal, strMFDMake;
	
	for (iTmp = 0; iTmp < 20; iTmp++)
	{
		bTestTable[iTmp] = 0;
	}

	for (iTmp = 0; iTmp < 800; iTmp++)
	{
		strTemp[iTmp] = ' ';
		strTemp1[iTmp] = ' ';
		strOutput[iTmp] = ' ';
	}
		
	GPrintUnit::Print();

	StartPage();

	CFont font;
	font.CreatePointFont(90, "Arial Bold", &JDC);
	GSELECT_OBJECT(&JDC, &font);

	//Open the Test Report File selected by the Common Dialog Box
	CFile fptr;
	if(!(fptr.Open(g_strFileName, CFile::typeBinary | CFile::modeRead| CFile::modeNoTruncate))) 
	{
		AfxMessageBox("\n File open error");
		return FALSE;
	}

	//Read the Index Page details stored in the File
	fptr.SeekToBegin();
	fptr.Read(&s_Index_Page,sizeof(s_Index_Page));

	//Form the First string to be display
	CString str;
	
	str.Format("<<<HARDWARE TEST PROCEDURE(HTP) for ISIS DU >>>");
	
	//Calculate the size
	CSize size = JDC.GetTextExtent(str);
	//Derive the Current X and Y display positions form the size
	CRect rect;
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;
	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);
	//Second String
	iString_No++;
	
	str.Format("                                                                                                                                              Page 1");
	//Calculate the size
	size = JDC.GetTextExtent(str);
	//Derive the Current X and Y display positions form the size
	rect;
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;
	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);
	
	//Second String
	iString_No++;
	str.Format("UNIT SERIAL NUMBER: %s",s_Index_Page.m_strSerialNo);

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);

	//Third String
	iString_No++;
	str.Format("TEST DESCRIPTION: %s",s_Index_Page.m_strOperator);

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);


	//4th String
	iString_No++;
	str.Format("DATE(DD/MM/YYYY): %s",s_Index_Page.m_strDateTime);

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);

	//Fifth String
	iString_No++;
	str.Format("EXECUTION MODE: %s",s_Index_Page.m_strExecMode);

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);
	//Sixth String
	iString_No++;

	str.Format("FILE NAME: %s",s_Index_Page.m_strFileName);

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);

	//Seventh String
	iString_No++;
	str.Format("BENCH APPLICATION SW: Version 1.01 Release Date 11-01-2017");

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);


	//Read and check what are the tests are Ok and Not Ok
	while(fptr.Read(&s_Curr_Test_Result,sizeof(s_Curr_Test_Result)))
	{
	
		if(iNo_of_Test_performed > DU_ATP_MAX_NO_OF_TEST)
		{
			break;
		}

		i_Performed_Test_ID[iNo_of_Test_performed++] = s_Curr_Test_Result.m_uiMinor_Test_ID;
			

		//Check for NOK Condition
		if(strcmp(s_Curr_Test_Result.m_strTestStatus,"OK") != 0)
		{
			b_AllTest_OK = FALSE;
			i_Tests_NOTOK[i_Test_NOK_Count++] = s_Curr_Test_Result.m_uiMinor_Test_ID;
		}
	}


	//Test Performed - Section

	iString_Start_X_Pos = 300;

	iString_No++;iString_No++;iString_No++;
	
	str.Format("************TESTS PERFORMED************");

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);

	
	strcpy(strTemp,"");
	str.Format("");
	
	for(int i=0; i < iNo_of_Test_performed; i++)
	{
		//str.Format("%d,", i_Performed_Test_ID[i]);
		//strcat(strTemp,str);

		str.Format("%d", i_Performed_Test_ID[i]);
		iMinorTestID = atoi(str);
		
		iMinorTestID = iMinorTestID / 100;
			
			iTmpNum = bTestTable[iMinorTestID]; 
			
			if (!iTmpNum)
			{
				bTestTable[iMinorTestID] = 1;

				switch (iMinorTestID)
					{
					case 1:
						str.Format(" 1)VISUAL INSPECTION,");
						break;
					case 2:
						str.Format(" 2)MECHANICAL DIMENSIONS and WEIGHT,");
						break;
					case 3:
						str.Format(" 3)BONDING RESISTANCE,");
						break;
					case 4:
						str.Format(" 4)POWER CONSUMPTION,");
						break;
					case 5:
						str.Format(" 5)BEZEL TESTS,");
						break;
					case 6:
						str.Format(" 6)ATTITUDE SENSOR MODULE TEST,");
						break;
					case 7:
						str.Format(" 7) DISPLAY TEST");
						break;
					case 8:
						str.Format(" 8)OPTICAL TESTS");
						break;
					case 9:
						str.Format(" 9)LCD PANEL CHECKS (POWER ON)");
						break;
					default:
						str.Format("");
				}
				
				strcat(strTemp,str);					
			}
		
	}
	strcpy(strOutput,strTemp);

	while(strlen(strOutput) > 0)
	{
		iString_No++;

		if(strlen(strOutput) < 100)
		{
			//Calculate the size
			size = JDC.GetTextExtent(strOutput);

			//Derive the Current X and Y display positions form the size
			rect.left = iString_Start_X_Pos;
			rect.right = rect.left + size.cx;
			rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
			rect.bottom = rect.top + size.cy;

			// Draw the string on the x and Y location
			JDC.DrawText(strOutput, &rect, DT_SINGLELINE);

			strcpy(strOutput,"");

		}
		else
		{

			strncpy(strTemp1,strOutput,100);
			//strncpy(strTemp1,strOutput,strlen(strOutput));

			strTemp1[200] = 0;

			//Calculate the size
			size = JDC.GetTextExtent(strTemp1);

			//Derive the Current X and Y display positions form the size
			rect.left = iString_Start_X_Pos;
			rect.right = rect.left + size.cx;
			rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
			rect.bottom = rect.top + size.cy;

			// Draw the string on the x and Y location
			JDC.DrawText(strTemp1, &rect, DT_SINGLELINE);

			strcpy(strOutput,strOutput + 100);
		}
	}


	iString_No++;iString_No++;iString_No++;

	if(b_AllTest_OK)
	{
		str.Format("************ALL TESTS PERFORMED ARE OK************");

		//Calculate the size
		size = JDC.GetTextExtent(str);

		//Derive the Current X and Y display positions form the size
		rect.left = iString_Start_X_Pos;
		rect.right = rect.left + size.cx;
		rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
		rect.bottom = rect.top + size.cy;

		// Draw the string on the x and Y location
		JDC.DrawText(str, &rect, DT_SINGLELINE);
	}
	else
	{
		str.Format("*************TESTS FAILED***************");

		//Calculate the size
		size = JDC.GetTextExtent(str);

		//Derive the Current X and Y display positions form the size
		rect.left = iString_Start_X_Pos;
		rect.right = rect.left + size.cx;
		rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
		rect.bottom = rect.top + size.cy;

		// Draw the string on the x and Y location
		JDC.DrawText(str, &rect, DT_SINGLELINE);

		strcpy(strTemp,"");
		
		// initialize array
		for (iTmp = 0; iTmp < 20; iTmp++)
		{
			bTestTable[iTmp] = 0;
		}
		
		for(int i=0; i < i_Test_NOK_Count; i++)
		{
			//str.Format("%d,",i_Tests_NOTOK[i]);
			
			str.Format("%d,",i_Tests_NOTOK[i]);
			iMinorTestID = atoi(str);
		
			iAfterded = iMinorTestID % 100;
			
			iMinorTestID = iMinorTestID / 100;
			
			iTmpNum = bTestTable[iMinorTestID]; 
			
			if (!iTmpNum)
			{
				bTestTable[iMinorTestID] = 1;
				
				switch (iMinorTestID)
					{
					case 1:
						str.Format(" 1)VISUAL INSPECTION,");
						break;
					case 2:
						str.Format(" 2)MECHANICAL DIMENSIONS and WEIGHT,");
						break;
					case 3:
						str.Format(" 3)BONDING RESISTANCE,");
						break;
					case 4:
						str.Format(" 4)POWER CONSUMPTION,");
						break;
					case 5:
						str.Format(" 5)BEZEL TESTS,");
						break;
					case 6:
						str.Format(" 6)ATTITUDE SENSOR MODULE TEST,");
						break;
					case 7:
						str.Format(" 7) DISPLAY TEST");
						break;
					case 8:
						str.Format(" 8)OPTICAL TESTS");
						break;
					case 9:
						str.Format(" 9)LCD PANEL CHECKS (POWER ON)");
						break;

					default:
						str.Format("");
					}
				
				strcat(strTemp,str);
				
			}
			
			if (iAfterded < 10)
			{
				str.Format("%d.0%d,",iMinorTestID, iAfterded);
			}
			else
			{
				str.Format("%d.%d,",iMinorTestID, iAfterded);
			}
			
			strcat(strTemp,str);
		}
		strcpy(strOutput,strTemp);

#if 1
	while(strlen(strOutput) > 0)
	{
		iString_No++;
		
		if(strlen(strOutput) < 100)
		{
			//Calculate the size
			size = JDC.GetTextExtent(strOutput);
			
			//Derive the Current X and Y display positions form the size
			rect.left = iString_Start_X_Pos;
			rect.right = rect.left + size.cx;
			rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
			rect.bottom = rect.top + size.cy;
			
			// Draw the string on the x and Y location
			JDC.DrawText(strOutput, &rect, DT_SINGLELINE);
			
			strcpy(strOutput,"");
			
		}
		else
		{
			
			strncpy(strTemp1,strOutput,100);
			
			strTemp1[100] = 0;
			
			//Calculate the size
			size = JDC.GetTextExtent(strTemp1);
			
			//Derive the Current X and Y display positions form the size
			rect.left = iString_Start_X_Pos;
			rect.right = rect.left + size.cx;
			rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
			rect.bottom = rect.top + size.cy;
			
			// Draw the string on the x and Y location
			JDC.DrawText(strTemp1, &rect, DT_SINGLELINE);
			
			strcpy(strOutput,strOutput + 100);
		}
	}
#endif

	}

	fptr.Close();

	iString_No = iString_No + 5;

	str.Format("Observations:");

	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);

	str.Format("Test Engineer                 Signature SHDS QA                    Signature HAL(Q)                      Signature ORDAQA   ");
	iString_No = iString_No + 7;
	//Calculate the size
	size = JDC.GetTextExtent(str);

	//Derive the Current X and Y display positions form the size
	rect.left = iString_Start_X_Pos;
	rect.right = rect.left + size.cx;
	rect.top = iString_Start_Y_Pos + (iString_Gap * iString_No);
	rect.bottom = rect.top + size.cy;

	// Draw the string on the x and Y location
	JDC.DrawText(str, &rect, DT_SINGLELINE);
	EndPage();

	return TRUE;
}
*/
BOOL HeaderPage::Print()
{   
    char strOutput[1000] = {0};

    unsigned int performed[DU_ATP_MAX_NO_OF_TEST] = {0};
    unsigned int failed[DU_ATP_MAX_NO_OF_TEST] = {0};

    int perfCount = 0, failCount = 0;
    BOOL bAllOK = TRUE;

    int x = 800, y = 200, gap = 150, lineNo = 0;

    GPrintUnit::Print();
    StartPage();

    CFont font;
    font.CreatePointFont(90, "Arial Bold", &JDC);
    GSELECT_OBJECT(&JDC, &font);

    CFile fptr;
    if (!fptr.Open(g_strFileName, CFile::modeRead | CFile::typeBinary))
    {
        AfxMessageBox("File open error");
        return FALSE;
    }

    fptr.SeekToBegin();
    fptr.Read(&s_Index_Page, sizeof(s_Index_Page));

    CString str;
    CSize size;
    CRect rect;

#define DRAW(txt) \
    lineNo++; \
    str = txt; \
    size = JDC.GetTextExtent(str); \
    rect = CRect(x, y + gap * lineNo, x + size.cx, y + gap * lineNo + size.cy); \
    JDC.DrawText(str, &rect, DT_SINGLELINE);
	CString mode =  s_Index_Page.m_strExecMode;
    // ================= HEADER =================
    DRAW("<<< INTEGRATED AVIONICS TEST REPORT >>>");
	DRAW(CString("Operator Name: ") + s_Index_Page.m_strOperator);
	if(mode == "Integration")
	{

	DRAW(CString("SMFD FC Serial No: ") + s_Index_Page.m_strSmfdFc);
	DRAW(CString("SMFD RC Serial No: ") + s_Index_Page.m_strSmfdRc);
	DRAW(CString("MFD FC Serial No: ") + s_Index_Page.m_strMfdFc);
	DRAW(CString("MFD RC Serial No: ") + s_Index_Page.m_strMfdRc);
	DRAW(CString("ISIS DU FC Serial No: ") + s_Index_Page.m_strIsisDuFc);
	DRAW(CString("ISIS DU RC Serial No: ") + s_Index_Page.m_strIsisDuRc);
	DRAW(CString("ISIS ADU Serial No: ") + s_Index_Page.m_strIsisAdu);
	DRAW(CString("ISIS AHRS Serial No: ") + s_Index_Page.m_strIsisAhrs);
	DRAW(CString("ISIS MMS Serial No: ") + s_Index_Page.m_strIsisMms);
	DRAW(CString("ADC Serial No: ") + s_Index_Page.m_strAdc);
	DRAW(CString("AHRS Serial No: ") + s_Index_Page.m_strAhrs);
	DRAW(CString("GPS Serial No: ") + s_Index_Page.m_strGps);
	DRAW(CString("VOR Rx Serial No: ") + s_Index_Page.m_strVorrx);
	DRAW(CString("TACAN Rx Serial No: ") + s_Index_Page.m_strTacrx);
	DRAW(CString("CDU Serial No: ") + s_Index_Page.m_strCdu);
    DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
    DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
    DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
    DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
	}else
	{
		CString lruname = s_Index_Page.m_strEquipment;
		if(lruname == "SMFD")
		{
				DRAW(CString("SMFD FC Serial No: ") + s_Index_Page.m_strSmfdFc);
	         DRAW(CString("SMFD RC Serial No: ") + s_Index_Page.m_strSmfdRc);
               	DRAW(CString("MFD FC Serial No: ") + s_Index_Page.m_strMfdFc);
	           DRAW(CString("MFD RC Serial No: ") + s_Index_Page.m_strMfdRc);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
		else if(lruname == "ISIS")
		{DRAW(CString("ISIS DU FC Serial No: ") + s_Index_Page.m_strIsisDuFc);
	DRAW(CString("ISIS DU RC Serial No: ") + s_Index_Page.m_strIsisDuRc);
	DRAW(CString("ISIS ADU Serial No: ") + s_Index_Page.m_strIsisAdu);
	DRAW(CString("ISIS AHRS Serial No: ") + s_Index_Page.m_strIsisAhrs);
	DRAW(CString("ISIS MMS Serial No: ") + s_Index_Page.m_strIsisMms);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
		else if(lruname == "ADC")
		{
		DRAW(CString("ADC Serial No: ") + s_Index_Page.m_strAdc);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
		else if(lruname == "AHRS")
		{
		DRAW(CString("AHRS Serial No: ") + s_Index_Page.m_strAhrs);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
		else if(lruname == "GPS")
		{
		DRAW(CString("GPS Serial No: ") + s_Index_Page.m_strGps);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
	else if(lruname == "VOR")
		{
		DRAW(CString("VOR Rx Serial No: ") + s_Index_Page.m_strVorrx);
	DRAW(CString("TACAN Rx Serial No: ") + s_Index_Page.m_strTacrx);
	DRAW(CString("CDU Serial No: ") + s_Index_Page.m_strCdu);
           DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}


	}
   

    // ================= READ RESULTS =================
    while (fptr.Read(&s_Curr_Test_Result, sizeof(s_Curr_Test_Result)))
    {
        if (perfCount >= DU_ATP_MAX_NO_OF_TEST)
            break;

        performed[perfCount++] = s_Curr_Test_Result.m_uiMinor_Test_ID;

        if (strcmp(s_Curr_Test_Result.m_strTestStatus, "OK") != 0)
        {
            bAllOK = FALSE;
            failed[failCount++] = s_Curr_Test_Result.m_uiMinor_Test_ID;
        }
    }

   // ================= TESTS PERFORMED =================
lineNo += 2;
#if 0
DRAW("************ TESTS PERFORMED ************");

CString reportStr = "";

int lruCount = g_LRU_Count;

for (int i = 0; i < lruCount; i++)
{
    BOOL lruPrinted = FALSE;

    for (int j = 0; j < LRU_Table[i].mainCount; j++)
    {
        BOOL mainPrinted = FALSE;   //  prevents duplicate main test

        for (int k = 0; k < perfCount; k++)
        {
            float testID = performed[k] / 100.0f;

            for (int s = 0; s < LRU_Table[i].mainTests[j].subCount; s++)
            {
                float tableID = LRU_Table[i].mainTests[j].subTests[s].id;

                if (fabs(testID - tableID) < 0.001f)
                {
                    // print LRU only once
                    if (!lruPrinted)
                    {
                        reportStr += "\n";
                        reportStr += LRU_Table[i].name + " : ";
                        lruPrinted = TRUE;
                    }

                    // print MAIN TEST only once
                    if (!mainPrinted)
                    {
                        reportStr += LRU_Table[i].mainTests[j].name;
                        reportStr += ", ";
                        mainPrinted = TRUE;
                    }

                    break; // break sub-test loop
                }
            }

            if (mainPrinted)
                break; //  stop checking more performed tests for this main
        }
    }
}

    // PRINT MULTILINE SAFE
    while (!reportStr.IsEmpty())
    {
        CString line = reportStr.Left(100);
        reportStr = reportStr.Mid(min(100, reportStr.GetLength()));
        DRAW(line);
    }
#endif
    // ================= FINAL RESULT =================
    lineNo += 2;

    if (bAllOK)
	{ DRAW("************ FINAL RESULT : PASS ************");}
    else
	{  DRAW("************ FINAL RESULT : FAIL ************");}

    // ================= FAILED TEST IDs =================
#if 0
    if (!bAllOK)
    {
        DRAW("FAILED TEST IDs:");

        CString failStr = "";

        for (int i = 0; i < failCount; i++)
        {
            CString tmp;
            tmp.Format("%d ", failed[i]);
            failStr += tmp;
        }

        DRAW(failStr);
    }
#endif
    // ================= SIGNATURE =================
    lineNo += 4;
    DRAW("Test Engineer                     QA                               HAL(Q)                              ORDAQA");

    fptr.Close();
    EndPage();

    return TRUE;
}
