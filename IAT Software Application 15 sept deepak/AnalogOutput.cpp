#include "stdafx.h"
#include "AnalogOutput.h"
CAnalogOutput g_AnalogOutput;
CAnalogOutput::CAnalogOutput()
{
    m_pCtrl = NULL;
    m_bInitialized = FALSE;
}

CAnalogOutput::~CAnalogOutput()
{
    Close();
}

BOOL CAnalogOutput::Initialize()
{
	 if (m_bInitialized && m_pCtrl != NULL)
        return TRUE;
    ErrorCode ret;

    m_pCtrl = AdxInstantAoCtrlCreate();

    if (m_pCtrl == NULL)
        return FALSE;

    DeviceInformation devInfo(static_cast<int32>(0));

    ret = m_pCtrl->setSelectedDevice(devInfo);

    if (BioFailed(ret))
    {
        m_pCtrl->Dispose();
        m_pCtrl = NULL;
        return FALSE;
    }

    AoChannelCollection* channels = m_pCtrl->getChannels();

    if (channels == NULL || channels->getCount() <= 0)
    {
        m_pCtrl->Dispose();
        m_pCtrl = NULL;
        return FALSE;
    }

    // Configure the required AO channels
    for (int i = 0; i < channels->getCount(); i++)
    {
        ret = channels->getItem(i).setValueRange(V_0To10);

        if (BioFailed(ret))
        {
            m_pCtrl->Dispose();
            m_pCtrl = NULL;
            return FALSE;
        }
    }

    m_bInitialized = TRUE;

    // Start with all outputs at 0 V
    ResetOutputs();

    return TRUE;
}
BOOL CAnalogOutput::SetVoltage(int channel, double voltage)
{
    if (!m_bInitialized || m_pCtrl == NULL)
        return FALSE;
	if (voltage < 0.0 || voltage > 10.0)
        return FALSE;
    AoChannelCollection* channels = m_pCtrl->getChannels();

    if (channels == NULL)
        return FALSE;

    if (channel < 0 || channel >= channels->getCount())
        return FALSE;

    double value = voltage;

    ErrorCode ret = m_pCtrl->Write(channel, 1, &value);

    return !BioFailed(ret);
}

BOOL CAnalogOutput::SetVoltageRange(int channel, ValueRange range)
{
    if (!m_bInitialized || m_pCtrl == NULL)
        return FALSE;

    AoChannelCollection* channels = m_pCtrl->getChannels();
	  if (channels == NULL)
        return FALSE;
    if (channel < 0 || channel >= channels->getCount())
        return FALSE;

    ErrorCode ret = channels->getItem(channel).setValueRange(range);
    return !BioFailed(ret);
}

void CAnalogOutput::ResetOutputs()
{
    if (!m_bInitialized || m_pCtrl == NULL)
        return;

    AoChannelCollection* channels = m_pCtrl->getChannels();

    if (channels == NULL)
        return;

    for (int i = 0; i < channels->getCount(); i++)
    {
        double value = 0.0;

        m_pCtrl->Write(i, 1, &value);
    }
}

void CAnalogOutput::Close()
{
    if (m_pCtrl != NULL)
    {
        ResetOutputs();
        m_pCtrl->Dispose();   // Dispose() destroys the instance; don't call Cleanup() after Dispose()
        m_pCtrl = NULL;
		TRACE("PCI Analog 1824 closed success");
    }
    m_bInitialized = FALSE;
}