
#include "stdafx.h"
#include "Globals.h"

BOOL g_bSimulationMode = FALSE;
volatile BOOL g_bStopRequested = FALSE;

Globals::Globals(void)
{
}


Globals::~Globals(void)
{
}
BOOL g_bSMFDAnalogThreadRunning = FALSE;
BOOL g_bSMFDAnalogStopThread = FALSE;

float g_fLatestSMFDAnalogValue = 0.0f;

CCriticalSection g_csSMFDAnalog;