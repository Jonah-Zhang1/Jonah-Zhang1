/*
*   (c) Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Port.h"
#include "Eth.h"
#include "OsIf.h"
#include "Dio.h"
//#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Transmit & receive in internal loopback mode
* @details
*/
int main(void)
{
    Eth_BufIdxType BufferIndex;
    uint8 *PayloadBuffer;
    uint16 PayloadLength = 64U;
    uint8 Gmac_0_MacAddr[6U] = {0};
    Eth_RxStatusType Status;
    boolean Pass = TRUE;

    OsIf_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    Dio_Init(NULL_PTR);

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    Mcu_SetMode(McuModeSettingConf_0);

    Eth_Init(NULL_PTR);

    Eth_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE);

    Eth_ProvideTxBuffer(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &BufferIndex, &PayloadBuffer, &PayloadLength);

    Eth_GetPhysAddr(EthConf_EthCtrlConfig_EthCtrlConfig_0, Gmac_0_MacAddr);

    Eth_Transmit(EthConf_EthCtrlConfig_EthCtrlConfig_0, BufferIndex, (Eth_FrameType)46U, TRUE, 46U, Gmac_0_MacAddr);

    Eth_TxConfirmation(EthConf_EthCtrlConfig_EthCtrlConfig_0);

    Eth_Receive(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &Status);

    if (ETH_RECEIVED != Status)
    {
        Pass = FALSE;
    }

    Eth_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_DOWN);

    //Exit_Example(Pass);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */