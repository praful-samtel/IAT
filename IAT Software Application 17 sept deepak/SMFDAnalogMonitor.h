#pragma once

#include "stdafx.h"
#include "Globals.h"

// Message sent to the active analog dialog
#define WM_UPDATE_SMFD_ANALOG (WM_USER + 103)

// Start and stop monitor
BOOL StartSMFDAnalogMonitor();
void StopSMFDAnalogMonitor();

// Configure active test
void SetSMFDAnalogTarget(HWND hWnd, UINT label);

// Clear active dialog
void ClearSMFDAnalogTarget();

// Get latest ARINC value
float GetLatestSMFDAnalogValue();

// Worker thread
UINT SMFDAnalogMonitorThread(LPVOID pParam);