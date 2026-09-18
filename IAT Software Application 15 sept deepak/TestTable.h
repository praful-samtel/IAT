#pragma once
#include <atlstr.h>

struct SUB_TEST
{
	CString name;
	float id;
};

struct MAIN_TEST
{
	CString name;
	SUB_TEST* subTests;
	int subCount;
};

struct LRU_TEST
{
	CString name;
	MAIN_TEST* mainTests;
	int mainCount;
};

extern LRU_TEST LRU_Table[];
extern int g_LRU_Count;