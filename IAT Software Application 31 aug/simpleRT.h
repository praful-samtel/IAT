/* ----------------------------------------------------------------------------
 *                            HOLT Integrated Circuits 
 * ----------------------------------------------------------------------------
 *
 *    file	simpleRT.h
 *    brief     This file demonstrates RT1 traffic displayed on the console
 *              similar to the output on the Simple RT demo (non API).

*/


#define T_R 0x0400 
#define TRUE 1
#define FALSE 0



void displayRT1Traffic(PLX_DEVICE_OBJECT *pDevice);
void modifyRTSADataBlock(PLX_DEVICE_OBJECT *pDevice);
U16 MessageRX_Poll(PLX_DEVICE_OBJECT *pDevice);
U16 modeCode16DataLoad(PLX_DEVICE_OBJECT *pDevice,U16 vector);
U16 modeCode19DataLoad(PLX_DEVICE_OBJECT *pDevice,U16 bit);
U16 simpleRT1EnabledIntCheck(void);
void simpleRT1DisableInt(void);
void simpleRT1EnableInt(void);
