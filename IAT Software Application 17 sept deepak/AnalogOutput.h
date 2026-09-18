#pragma once
#include "bdaqctrl.h"
using namespace Automation::BDaq;

class CAnalogOutput
{
public:
    CAnalogOutput();
    ~CAnalogOutput();
    BOOL Initialize();
    BOOL SetVoltage(int channel, double voltage);
    BOOL SetVoltageRange(int channel, ValueRange range);
    void ResetOutputs();
    void Close();

private:
    InstantAoCtrl* m_pCtrl;
    BOOL m_bInitialized;
};