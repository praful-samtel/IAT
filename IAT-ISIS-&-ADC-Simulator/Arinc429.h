#pragma once

#include "ADT_L1.h"

#define MAX_TX_CHANNELS 16

class CArinc429
{
public:
    CArinc429();
    ~CArinc429();

    // Initialize a TX channel
    BOOL InitializeTxChannel(
        int nTxChannel,
        int nSpeed = 100000,
        int nQueueSize = 10,
        int nMsgNo = 0,
        int nTxpCount = 10);

	BOOL CloseARINC429(
        int nTxChannel,
        int nRxChannel);
    // Send a single ARINC label (DWORD)
    BOOL SendLabel(int nTxChannel, DWORD dwLabel);

	BOOL StartTacanSimulation(
        int nTxChannel,
        DWORD Label1,
        DWORD Label2,
        DWORD Label3);

    // Send a single ARINC label (Hex String)
    BOOL SendLabel(int nTxChannel, CString strHex);

    // Send multiple labels
    BOOL SendLabels(
        int nTxChannel,
        ADT_L0_UINT32* pLabels,
        int nCount);

    // Send the same label continuously
    BOOL SendLabelContinuous(
        int nTxChannel,
        DWORD dwLabel,
        int nRepeat,
        int nDelayMS);

private:

    // Channel initialization status (Index 1-16)
    BOOL m_bChannelInitialized[MAX_TX_CHANNELS + 1];
};

extern CArinc429 gArinc429;