#ifndef PLXINIT_H
#define PLXINIT_H

/******************************************************************************
 *
 * File Name:
 *
 *      PlxInit.h
 *
 * Description:
 *
 *      Header file for the PlxInit.c module
 *
 * Revision History:
 *
 *      12-01-07 : PLX SDK v5.20
 *
 ******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif




/******************************
*        Definitions
******************************/
#define MAX_DEVICES_TO_LIST        100
//extern S16 SelectDevice( PLX_DEVICE_KEY *pKey);


#if 1
typedef struct _API_ERRORS1
{
    PLX_STATUS  code;
    char       *text;
} API_ERRORS1;

/********************************************************************************
*        Functions
*********************************************************************************/


//extern PLX_STATUS EXPORT PlxPci_DeviceFind(PLX_DEVICE_KEY DevKey, U16 i);

char* PlxSdkErrorText( PLX_STATUS code );

void PlxSdkErrorDisplay(PLX_STATUS code );
#endif
#ifdef __cplusplus
}
#endif

#endif
