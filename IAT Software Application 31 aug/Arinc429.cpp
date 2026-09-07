#include "stdafx.h"
#include "Arinc429.h"
#include "DataStruct.h"
#include "ADT_L1.h"
#include "Globals.h"

#define DEVID (ADT_PRODUCT_PCIA429 | ADT_DEVID_BOARDNUM_01 | ADT_DEVID_CHANNELTYPE_A429 | ADT_DEVID_BANK_01)

CArinc429 gArinc429;

void ShowSimulationLoopbackNotice(LPCTSTR lpszUnitName,
                                  int txChannelX,
                                  int txChannelY,
                                  int rxPinP,
                                  int rxPinQ)
{
    if (!g_bSimulationMode)
        return;

    CString message;
    message.Format(
        _T("Connect loopback connector on TX channel %d & %d pins and RX channel %d & %d pins."),
        txChannelX,
        txChannelY,
        rxPinP,
        rxPinQ);

    ::MessageBox(AfxGetMainWnd() ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                 message,
                 lpszUnitName,
                 MB_OK | MB_ICONINFORMATION);
}

CArinc429::CArinc429()
{
    memset(m_bChannelInitialized, FALSE, sizeof(m_bChannelInitialized));
}

CArinc429::~CArinc429()
{
}

void CArinc429::ResetChannelState()
{
    memset(m_bChannelInitialized, FALSE, sizeof(m_bChannelInitialized));
}

/////////////////////////////////////////////////////////////////////////////
// Initialize TX Channel
/////////////////////////////////////////////////////////////////////////////

BOOL CArinc429::InitializeTxChannel(
    int nTxChannel,
    int nSpeed,
    int nQueueSize,
    int nMsgNo,
    int nTxpCount)
{
    TRACE("InitializeTxChannel() Channel=%d\n", nTxChannel);

    ADT_L0_UINT32 status;

    if (nTxChannel < 0 || nTxChannel > 16)
    {
        TRACE("Invalid Channel\n");
        return FALSE;
    }

    // A Stop closes the device, so a later procedure must reopen it before
    // configuring or transmitting on a TX channel.
    if (!InitializeARINC429())
        return FALSE;

    if (m_bChannelInitialized[nTxChannel])
    {
        TRACE("Channel %d already initialized\n", nTxChannel);
        return TRUE;
    }

    status = ADT_L1_A429_TX_Channel_Init(
        DEVID,
        nTxChannel,
        nSpeed,
        nQueueSize);

    TRACE("Channel_Init Status = %lu\n", status);

    if (status != ADT_SUCCESS)
    {
        TRACE("TX Channel Init Failed\n");
        return FALSE;
    }

    status = ADT_L1_A429_TX_Channel_CB_TXPAllocate(
        DEVID,
        nTxChannel,
        nMsgNo,
        nTxpCount);

    TRACE("CB_TXPAllocate Status = %lu\n", status);

    if (status != ADT_SUCCESS)
    {
        TRACE("TXP Allocate Failed\n");
        return FALSE;
    }

    m_bChannelInitialized[nTxChannel] = TRUE;

    TRACE("Channel %d Initialized Successfully\n", nTxChannel);

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Send One Label (DWORD)
/////////////////////////////////////////////////////////////////////////////

BOOL CArinc429::SendLabel(int nTxChannel, DWORD dwLabel)
{
    TRACE("SendLabel() Channel=%d Label=0x%08X\n",
            nTxChannel,
            dwLabel);

    if (!InitializeTxChannel(nTxChannel))
    {
        TRACE("InitializeTxChannel Failed\n");
        return FALSE;
    }

    ADT_L0_UINT32 Label[1];
    Label[0] = dwLabel;

    ADT_L0_UINT32 status =
        ADT_L1_A429_TX_Channel_SendLabelBlock(
            DEVID,
            nTxChannel,
            1,
            Label);

    TRACE("SendLabel Status = %lu\n", status);

    return (status == ADT_SUCCESS);
}

/////////////////////////////////////////////////////////////////////////////
// Send One Label (Hex String)
/////////////////////////////////////////////////////////////////////////////

BOOL CArinc429::SendLabel(int nTxChannel, CString strHex)
{
    DWORD dwLabel = 0;

    _stscanf_s(strHex, _T("%x"), &dwLabel);

    return SendLabel(nTxChannel, dwLabel);
}

/////////////////////////////////////////////////////////////////////////////
// Send Multiple Labels
/////////////////////////////////////////////////////////////////////////////

BOOL CArinc429::SendLabels(
    int nTxChannel,
    ADT_L0_UINT32* pLabels,
    int nCount)
{
    if (!InitializeTxChannel(nTxChannel))
        return FALSE;

    ADT_L0_UINT32 status;

    status = ADT_L1_A429_TX_Channel_SendLabelBlock(
        DEVID,
        nTxChannel,
        nCount,
        pLabels);

    return (status == ADT_SUCCESS);
}

/////////////////////////////////////////////////////////////////////////////
// Send Same Label Continuously
/////////////////////////////////////////////////////////////////////////////

BOOL CArinc429::SendLabelContinuous(
    int nTxChannel,
    DWORD dwLabel,
    int nRepeat,
    int nDelayMS)
{
    for (int i = 0; i < nRepeat; i++)
    {
        if (!SendLabel(nTxChannel, dwLabel))
            return FALSE;

        Sleep(nDelayMS);
    }

    return TRUE;
}

BOOL CArinc429::StartTacanSimulation(
    int nTxChannel,
    DWORD Label1,
    DWORD Label2,
    DWORD Label3)
{
    if(!InitializeTxChannel(nTxChannel))
    {
        TRACE("InitializeTxChannel Failed\n");
        return FALSE;
    }

    ADT_L0_UINT32 status;

    TRACE("\n========== Start TACAN Simulation ==========\n");
    TRACE("TX Channel : %d\n", nTxChannel);

    //-----------------------------------------------------
    // Write Control Block
    //-----------------------------------------------------

    ADT_L1_A429_TXCB txcb;
    memset(&txcb, 0, sizeof(txcb));

    txcb.NextTxcbNum = ADT_L1_A429_TXCB_NO_NEXT_TXCB;
    txcb.Control     = 0;
    txcb.TxPeriod500us = 0;

    status = ADT_L1_A429_TX_Channel_CB_Write(
                    DEVID,
                    nTxChannel,
                    0,
                    &txcb);

    TRACE("CB Write Status = 0x%08X\n", status);

    if(status != ADT_SUCCESS)
        return FALSE;

    //-----------------------------------------------------
    // TXP0
    //-----------------------------------------------------

    ADT_L1_A429_TXP txp;

    memset(&txp,0,sizeof(txp));

    txp.Control =
        ADT_L1_A429_TXP_CONTROL_PARITYON |
        ADT_L1_A429_TXP_CONTROL_PARITYODD;

    txp.Delay = 400;
    txp.Data  = Label1;

    status = ADT_L1_A429_TX_Channel_CB_TXPWrite(
                    DEVID,
                    nTxChannel,
                    0,
                    0,
                    &txp);

    TRACE("TXP0 Status = 0x%08X  Label = 0x%08X\n",
            status,
            Label1);

    if(status != ADT_SUCCESS)
        return FALSE;

    //-----------------------------------------------------
    // TXP1
    //-----------------------------------------------------

    txp.Data = Label2;

    status = ADT_L1_A429_TX_Channel_CB_TXPWrite(
                    DEVID,
                    nTxChannel,
                    0,
                    1,
                    &txp);

    TRACE("TXP1 Status = 0x%08X  Label = 0x%08X\n",
            status,
            Label2);

    if(status != ADT_SUCCESS)
        return FALSE;

    //-----------------------------------------------------
    // TXP2
    //-----------------------------------------------------

    txp.Data = Label3;

    status = ADT_L1_A429_TX_Channel_CB_TXPWrite(
                    DEVID,
                    nTxChannel,
                    0,
                    2,
                    &txp);

    TRACE("TXP2 Status = 0x%08X  Label = 0x%08X\n",
            status,
            Label3);

    if(status != ADT_SUCCESS)
        return FALSE;

    //-----------------------------------------------------
    // Start Transmission
    //-----------------------------------------------------

    status = ADT_L1_A429_TX_Channel_Start(
                    DEVID,
                    nTxChannel,
                    0);

    TRACE("TX Start Status = 0x%08X\n", status);

    if(status != ADT_SUCCESS)
    {
        TRACE("TX Start Failed\n");
        return FALSE;
    }

    TRACE("TACAN Simulation Started Successfully\n");
    TRACE("===========================================\n\n");

    return TRUE;
}

BOOL CArinc429::CloseARINC429(
        int nTxChannel,
        int nRxChannel)
{
    ADT_L0_UINT32 status;

    TRACE("\n==============================\n");
    TRACE("Closing ARINC429...\n");

    //////////////////////////////////////////////////////
    // Close RX Channel
    //////////////////////////////////////////////////////

    if(nRxChannel >= 0)
    {
        TRACE("Closing RX Channel %d...\n", nRxChannel);

        status = ADT_L1_A429_RX_Channel_Close(
                    DEVID,
                    nRxChannel);

        TRACE("RX Close Status = 0x%08X\n", status);

        if(status != ADT_SUCCESS)
            TRACE("RX Channel Close Failed.\n");
    }

    //////////////////////////////////////////////////////
    // Stop TX Channel
    //////////////////////////////////////////////////////

    if(nTxChannel >= 0)
    {
        TRACE("Stopping TX Channel %d...\n", nTxChannel);

        status = ADT_L1_A429_TX_Channel_Stop(
                    DEVID,
                    nTxChannel);

        TRACE("TX Stop Status = 0x%08X\n", status);

        if(status != ADT_SUCCESS)
            TRACE("TX Stop Failed.\n");

        m_bChannelInitialized[nTxChannel] = FALSE;
    }

    //////////////////////////////////////////////////////
    // Close Device
    //////////////////////////////////////////////////////
/*
    TRACE("Closing Device...\n");

    status = ADT_L1_CloseDevice(DEVID);

    TRACE("Device Close Status = 0x%08X\n", status);

    if(status != ADT_SUCCESS)
    {
        TRACE("Device Close Failed.\n");
        return FALSE;
    }

    TRACE("ARINC429 Closed Successfully.\n");
    TRACE("==============================\n\n");
*/
    return TRUE;
}

/* 
one label : gArinc429.SendLabel(3, 0x65195738);
gArinc429.SendLabel(5, "0x68010349");



multiple label : 
ADT_L0_UINT32 Labels[3];

Labels[0] = 0x65195738;
Labels[1] = 0x62C00349;
Labels[2] = 0xE0D803DE;

gArinc429.SendLabels(3, Labels, 3);


gArinc429.SendLabelContinuous(
    3,
    0x65195738,
    100,
    100);
*/
