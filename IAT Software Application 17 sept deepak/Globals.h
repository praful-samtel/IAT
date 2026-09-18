#pragma once
class Globals
{
public:
	Globals(void);
	~Globals(void);
	
};
extern BOOL g_bSimulationMode;

extern volatile BOOL g_bStopRequested;



extern BOOL g_bSMFDAnalogThreadRunning;
extern BOOL g_bSMFDAnalogStopThread;

extern float g_fLatestSMFDAnalogValue;
extern CCriticalSection g_csSMFDAnalog;