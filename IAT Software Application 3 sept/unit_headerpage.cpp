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

BOOL HeaderPage::Print()
{   
    char strOutput[1000] = {0};

    unsigned int performed[DU_ATP_MAX_NO_OF_TEST] = {0};
	CString failed[DU_ATP_MAX_NO_OF_TEST] = {};

    int perfCount = 0, failCount = 0;
    BOOL bAllOK = TRUE;

    int x = 800, y = 200, gap = 150, lineNo = 0;


    GPrintUnit::Print();
    StartPage();
	
    CFont font;
    font.CreatePointFont(90, "Arial Bold", &JDC);
    GSELECT_OBJECT(&JDC, &font);
	// ================= PAGE 1 HEADER =================
CString strLeft = "SHDS";
CString strCenter = "INTEGRATED AVIONICS TESTER TEST REPORT";
CString strRight = "Page: 1";

int pageWidth = JDC.GetDeviceCaps(HORZRES);

CSize leftSize = JDC.GetTextExtent(strLeft);
CSize centerSize = JDC.GetTextExtent(strCenter);
CSize rightSize = JDC.GetTextExtent(strRight);

JDC.TextOut(100, 50, strLeft);

JDC.TextOut(
    (pageWidth - centerSize.cx) / 2,
    50,
    strCenter
);

JDC.TextOut(
    pageWidth - rightSize.cx - 100,
    50,
    strRight
);

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
	
  //  DRAW("<<< INTEGRATED AVIONICS TESTER TEST REPORT >>>");
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
		else if(lruname == "SMFD & MFD FC")
		{
			DRAW(CString("SMFD FC Serial No: ") + s_Index_Page.m_strSmfdFc);
                 DRAW(CString("MFD FC Serial No: ") + s_Index_Page.m_strMfdFc);
			  DRAW(CString("TEST DESCRIPTION: ") + s_Index_Page.m_strTestDescription);
           DRAW(CString("DATE: ") + s_Index_Page.m_strDateTime);
           DRAW(CString("EXECUTION MODE: ") + s_Index_Page.m_strExecMode);
          DRAW(CString("FILE NAME: ") + s_Index_Page.m_strFileName);
		}
			else if(lruname == "SMFD & MFD RC")
		{
			
	         DRAW(CString("SMFD RC Serial No: ") + s_Index_Page.m_strSmfdRc);
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
            failed[failCount++] = s_Curr_Test_Result.m_strMinorTestName;
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
#if 1
  if (!bAllOK)
{
    DRAW("FAILED TEST Names:");

    CString failStr = "";

    for (int i = 0; i < failCount; i++)
    {
        failStr += failed[i];
        failStr += ", ";
    }

    // Print failed test names with proper line wrapping
    while (!failStr.IsEmpty())
    {
        int maxChars = 80;
        int breakPos = min(maxChars, failStr.GetLength());

        if (failStr.GetLength() > maxChars)
        {
            // Find the last space before the limit
            int spacePos = failStr.Left(maxChars).ReverseFind(' ');

            if (spacePos > 0)
                breakPos = spacePos;
        }

        CString line = failStr.Left(breakPos);
        failStr = failStr.Mid(breakPos);

        // Remove leading spaces/commas from next line
        while (!failStr.IsEmpty() &&
               (failStr[0] == ' ' || failStr[0] == ','))
        {
            failStr.Delete(0, 1);
        }

        DRAW(line);
    }
}

#endif
    // ================= SIGNATURE =================
    lineNo += 10;
    DRAW("Test Engineer                                                                           HAL(Q)");

    fptr.Close();
    EndPage();

    return TRUE;
}
