#include "stdafx.h"
#include "SelfTestHeaderPage.h"
#include "gfx_printjob.h"
#include "DataStruct.h"

extern CString          g_strSelfTestFileName;
extern sSelfTest_Header s_SelfTest_IndexPage;
extern sSelfTest_Item   s_Curr_SelfTest_Item;

#define MAX_SELFTEST_ITEMS 32

SelfTestHeaderPage::SelfTestHeaderPage(GPrintJob *pJob) : GPrintUnit(pJob) {}
SelfTestHeaderPage::~SelfTestHeaderPage() {}

BOOL SelfTestHeaderPage::Print()
{
    CString failed[MAX_SELFTEST_ITEMS];
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
    CString strCenter = "INTEGRATED AVIONICS TESTER SELF TEST REPORT";
    CString strRight = "Page: 1";

    int pageWidth = JDC.GetDeviceCaps(HORZRES);
    CSize centerSize = JDC.GetTextExtent(strCenter);
    CSize rightSize = JDC.GetTextExtent(strRight);

    JDC.TextOut(100, 50, strLeft);
    JDC.TextOut((pageWidth - centerSize.cx) / 2, 50, strCenter);
    JDC.TextOut(pageWidth - rightSize.cx - 100, 50, strRight);

    CFile fptr;
    if (!fptr.Open(g_strSelfTestFileName, CFile::modeRead | CFile::typeBinary))
    {
        AfxMessageBox("File open error");
        return FALSE;
    }

    fptr.SeekToBegin();
    fptr.Read(&s_SelfTest_IndexPage, sizeof(s_SelfTest_IndexPage));

    CString str;
    CSize size;
    CRect rect;

#define DRAW(txt) \
    lineNo++; \
    str = txt; \
    size = JDC.GetTextExtent(str); \
    rect = CRect(x, y + gap * lineNo, x + size.cx, y + gap * lineNo + size.cy); \
    JDC.DrawText(str, &rect, DT_SINGLELINE);

    DRAW(CString("Operator Name: ") + s_SelfTest_IndexPage.m_strOperator);
    DRAW(CString("DATE: ")          + s_SelfTest_IndexPage.m_strDateTime);
    DRAW(CString("FILE NAME: ")     + s_SelfTest_IndexPage.m_strFileName);

    // ================= READ RESULTS =================
    while (fptr.Read(&s_Curr_SelfTest_Item, sizeof(s_Curr_SelfTest_Item)))
    {
        if (perfCount >= MAX_SELFTEST_ITEMS)
            break;

        perfCount++;

        if (strcmp(s_Curr_SelfTest_Item.m_strResult, "OK") != 0)
        {
            bAllOK = FALSE;
            failed[failCount++] = s_Curr_SelfTest_Item.m_strItemName;
        }
    }

    // ================= FINAL RESULT =================
    lineNo += 2;
    if (bAllOK){
        DRAW("************ FINAL RESULT : PASS ************");
	}else{
        DRAW("************ FINAL RESULT : FAIL ************");
	}
    // ================= FAILED ITEMS =================
    if (!bAllOK)
    {
        DRAW("FAILED ITEMS:");

        CString failStr = "";
        for (int i = 0; i < failCount; i++)
        {
            failStr += failed[i];
            failStr += ", ";
        }

        while (!failStr.IsEmpty())
        {
            int maxChars = 80;
            int breakPos = min(maxChars, failStr.GetLength());

            if (failStr.GetLength() > maxChars)
            {
                int spacePos = failStr.Left(maxChars).ReverseFind(' ');
                if (spacePos > 0)
                    breakPos = spacePos;
            }

            CString line = failStr.Left(breakPos);
            failStr = failStr.Mid(breakPos);

            while (!failStr.IsEmpty() && (failStr[0] == ' ' || failStr[0] == ','))
                failStr.Delete(0, 1);

            DRAW(line);
        }
    }

    // ================= SIGNATURE =================
    lineNo += 10;
    DRAW("Test Engineer                                                                           HAL(Q)");

    fptr.Close();
    EndPage();

    return TRUE;
}