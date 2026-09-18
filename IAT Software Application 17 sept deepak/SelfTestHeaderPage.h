#pragma once
#include "gfx_printunit.h"
class SelfTestHeaderPage :
	public GPrintUnit
{
public:
	SelfTestHeaderPage(GPrintJob *pJob);
	virtual ~SelfTestHeaderPage(void);
	BOOL Print();
};

