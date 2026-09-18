#include "stdafx.h"
#include "unit_selftest_table.h"
#include "gfx_printjob.h"
#include "DataStruct.h"

extern CString          g_strSelfTestFileName;
extern sSelfTest_Header s_SelfTest_IndexPage;
extern sSelfTest_Item   s_Curr_SelfTest_Item;

SelfTestTable1Unit::SelfTestTable1Unit(GPrintJob *pJob) : GPrintUnit(pJob) {}
SelfTestTable1Unit::~SelfTestTable1Unit() {}

void SelfTestTable1Unit::DefineColHeadings()
{
   InsertPrintCol(0, "Item", 0.65);
   InsertPrintCol(1, "Result", 0.35);
   GPrintUnit::DefineColHeadings();
}

void SelfTestTable1Unit::CreatePrintFonts()
{
   LOGFONT logFont;
   GMAKESTNUL(logFont);

   LPCTSTR lpszFaceName = _T("Arial");
   logFont.lfCharSet = ANSI_CHARSET;
   logFont.lfHeight = 70;
   lstrcpyn(logFont.lfFaceName, lpszFaceName, GCOUNTOF(logFont.lfFaceName));
   logFont.lfWeight = FW_BOLD;

   m_fontHeading.CreatePointFontIndirect(&logFont, &JDC);
   m_fontPairBody.fontPrinter.CreatePointFont(70, lpszFaceName, &JDC);
   m_fontPairBody.fontScreen.CreatePointFont(70, lpszFaceName);

   m_fontHeader.CreatePointFont(110, _T("landscape"), &JDC);
   m_fontFooter.CreatePointFont(90, _T("landscape"), &JDC);
}

void SelfTestTable1Unit::InitPrintMetrics()
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

BOOL SelfTestTable1Unit::Print()
{
    GPrintUnit::Print();
    StartPage();

    INDEXITEM ii;
    ii.strName = "INTEGRATED AVIONICS TESTER SELF TEST REPORT";
    ii.wPage = (WORD)JINFO.m_nCurPage;
    ii.nFlags = INDEXF_DASHES|INDEXF_PAGENO;
    AddIndexItem(&ii);

    {
        GSELECT_OBJECT(&JDC, &m_fontHeading);
        PrintColHeadings(DT_LEFT);
    }

    GSELECT_PUFONT(&JDC, &m_fontPairBody);

    CFile fptr;
    if (!(fptr.Open(g_strSelfTestFileName, CFile::typeBinary | CFile::modeRead | CFile::modeNoTruncate)))
    {
        AfxMessageBox("\n File open error");
        return FALSE;
    }

    fptr.SeekToBegin();

    CString strTemp;
    unsigned char ucCol = 0;
    unsigned int uiRow = 1;

    // dummy read, mirrors Table1Unit skipping s_Index_Page
    fptr.Read(&s_SelfTest_IndexPage, sizeof(s_SelfTest_IndexPage));

    while (fptr.Read(&s_Curr_SelfTest_Item, sizeof(s_Curr_SelfTest_Item)))
    {
        if (uiRow >= 70)
        {
            uiRow = 0;
            EndPage();
            StartPage();
            {
                GSELECT_OBJECT(&JDC, &m_fontHeading);
                PrintColHeadings(DT_LEFT);
            }
            GSELECT_PUFONT(&JDC, &m_fontPairBody);
        }

        uiRow++;
        StartRow();
        ucCol = 0;

        strTemp.Format("%s", s_Curr_SelfTest_Item.m_strItemName);
        PrintCol(ucCol++, strTemp, DT_LEFT);

        strTemp.Format("%s", s_Curr_SelfTest_Item.m_strResult);
        PrintCol(ucCol++, strTemp, DT_LEFT);

        EndRow();
    }

    fptr.Close();
    EndPage();
    return TRUE;
}

void SelfTestTable1Unit::PrintHeader()
{
   GSELECT_OBJECT(&JDC, &m_fontHeader);

   CString strHeader = "SHDS";
   strHeader += HFC_CENTER;
   strHeader += "INTEGRATED AVIONICS TESTER SELF TEST REPORT";
   strHeader += HFC_RIGHTJUSTIFY;

   CString strPage;
   strPage.Format("Page: %d", JINFO.m_nCurPage);
   strHeader += strPage;

   PrintHeaderText(strHeader);
}

void SelfTestTable1Unit::PrintFooter()
{
   GSELECT_OBJECT(&JDC, &m_fontFooter);

   CString strFooter;
   strFooter = "Test Engineer";
   strFooter += HFC_CENTER;
   strFooter += "";
   strFooter += HFC_RIGHTJUSTIFY;
   strFooter += "Signature QA";

   PrintFooterText(strFooter);
}