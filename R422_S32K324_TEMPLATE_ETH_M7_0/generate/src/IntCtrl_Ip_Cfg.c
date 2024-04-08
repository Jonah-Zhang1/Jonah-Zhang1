/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K3_RTD_2_0_0_D2203_ASR_REL_4_4_REV_0000_20220331
*
*   (c) Copyright 2020 - 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   2
#define PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/* List of configurations for interrupts */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
    {INT0_IRQn, (boolean)FALSE, 0U},
    {INT1_IRQn, (boolean)FALSE, 0U},
    {INT2_IRQn, (boolean)FALSE, 0U},
    {INT3_IRQn, (boolean)FALSE, 0U},
    {DMATCD0_IRQn, (boolean)FALSE, 0U},
    {DMATCD1_IRQn, (boolean)FALSE, 0U},
    {DMATCD2_IRQn, (boolean)FALSE, 0U},
    {DMATCD3_IRQn, (boolean)FALSE, 0U},
    {DMATCD4_IRQn, (boolean)FALSE, 0U},
    {DMATCD5_IRQn, (boolean)FALSE, 0U},
    {DMATCD6_IRQn, (boolean)FALSE, 0U},
    {DMATCD7_IRQn, (boolean)FALSE, 0U},
    {DMATCD8_IRQn, (boolean)FALSE, 0U},
    {DMATCD9_IRQn, (boolean)FALSE, 0U},
    {DMATCD10_IRQn, (boolean)FALSE, 0U},
    {DMATCD11_IRQn, (boolean)FALSE, 0U},
    {DMATCD12_IRQn, (boolean)FALSE, 0U},
    {DMATCD13_IRQn, (boolean)FALSE, 0U},
    {DMATCD14_IRQn, (boolean)FALSE, 0U},
    {DMATCD15_IRQn, (boolean)FALSE, 0U},
    {DMATCD16_IRQn, (boolean)FALSE, 0U},
    {DMATCD17_IRQn, (boolean)FALSE, 0U},
    {DMATCD18_IRQn, (boolean)FALSE, 0U},
    {DMATCD19_IRQn, (boolean)FALSE, 0U},
    {DMATCD20_IRQn, (boolean)FALSE, 0U},
    {DMATCD21_IRQn, (boolean)FALSE, 0U},
    {DMATCD22_IRQn, (boolean)FALSE, 0U},
    {DMATCD23_IRQn, (boolean)FALSE, 0U},
    {DMATCD24_IRQn, (boolean)FALSE, 0U},
    {DMATCD25_IRQn, (boolean)FALSE, 0U},
    {DMATCD26_IRQn, (boolean)FALSE, 0U},
    {DMATCD27_IRQn, (boolean)FALSE, 0U},
    {DMATCD28_IRQn, (boolean)FALSE, 0U},
    {DMATCD29_IRQn, (boolean)FALSE, 0U},
    {DMATCD30_IRQn, (boolean)FALSE, 0U},
    {DMATCD31_IRQn, (boolean)FALSE, 0U},
    {ERM_0_IRQn, (boolean)FALSE, 0U},
    {ERM_1_IRQn, (boolean)FALSE, 0U},
    {MCM_IRQn, (boolean)FALSE, 0U},
    {STM0_IRQn, (boolean)FALSE, 0U},
    {STM1_IRQn, (boolean)FALSE, 0U},
    {SWT0_IRQn, (boolean)FALSE, 0U},
    {CTI0_IRQn, (boolean)FALSE, 0U},
    {FLASH_0_IRQn, (boolean)FALSE, 0U},
    {FLASH_1_IRQn, (boolean)FALSE, 0U},
    {FLASH_2_IRQn, (boolean)FALSE, 0U},
    {RGM_IRQn, (boolean)FALSE, 0U},
    {PMC_IRQn, (boolean)FALSE, 0U},
    {SIUL_0_IRQn, (boolean)FALSE, 0U},
    {SIUL_1_IRQn, (boolean)FALSE, 0U},
    {SIUL_2_IRQn, (boolean)FALSE, 0U},
    {SIUL_3_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_0_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_1_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_2_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_3_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_4_IRQn, (boolean)FALSE, 0U},
    {EMIOS0_5_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_0_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_1_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_2_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_3_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_4_IRQn, (boolean)FALSE, 0U},
    {EMIOS1_5_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_0_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_1_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_2_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_3_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_4_IRQn, (boolean)FALSE, 0U},
    {EMIOS2_5_IRQn, (boolean)FALSE, 0U},
    {WKPU_IRQn, (boolean)FALSE, 0U},
    {CMU0_IRQn, (boolean)FALSE, 0U},
    {CMU1_IRQn, (boolean)FALSE, 0U},
    {CMU2_IRQn, (boolean)FALSE, 0U},
    {BCTU_IRQn, (boolean)FALSE, 0U},
    {LCU0_IRQn, (boolean)FALSE, 0U},
    {LCU1_IRQn, (boolean)FALSE, 0U},
    {PIT0_IRQn, (boolean)FALSE, 0U},
    {PIT1_IRQn, (boolean)FALSE, 0U},
    {PIT2_IRQn, (boolean)FALSE, 0U},
    {RTC_IRQn, (boolean)FALSE, 0U},
    {EMAC_0_IRQn, (boolean)FALSE, 0U},
    {EMAC_1_IRQn, (boolean)FALSE, 0U},
    {EMAC_2_IRQn, (boolean)FALSE, 0U},
    {EMAC_3_IRQn, (boolean)FALSE, 0U},
    {FlexCAN0_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN0_1_IRQn, (boolean)FALSE, 0U},
    {FlexCAN0_2_IRQn, (boolean)FALSE, 0U},
    {FlexCAN0_3_IRQn, (boolean)FALSE, 0U},
    {FlexCAN1_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN1_1_IRQn, (boolean)FALSE, 0U},
    {FlexCAN1_2_IRQn, (boolean)FALSE, 0U},
    {FlexCAN2_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN2_1_IRQn, (boolean)FALSE, 0U},
    {FlexCAN2_2_IRQn, (boolean)FALSE, 0U},
    {FlexCAN3_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN3_1_IRQn, (boolean)FALSE, 0U},
    {FlexCAN4_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN4_1_IRQn, (boolean)FALSE, 0U},
    {FlexCAN5_0_IRQn, (boolean)FALSE, 0U},
    {FlexCAN5_1_IRQn, (boolean)FALSE, 0U},
    {FLEXIO_IRQn, (boolean)FALSE, 0U},
    {LPUART0_IRQn, (boolean)FALSE, 0U},
    {LPUART1_IRQn, (boolean)FALSE, 0U},
    {LPUART2_IRQn, (boolean)FALSE, 0U},
    {LPUART3_IRQn, (boolean)FALSE, 0U},
    {LPUART4_IRQn, (boolean)FALSE, 0U},
    {LPUART5_IRQn, (boolean)FALSE, 0U},
    {LPUART6_IRQn, (boolean)FALSE, 0U},
    {LPUART7_IRQn, (boolean)FALSE, 0U},
    {LPUART8_IRQn, (boolean)FALSE, 0U},
    {LPUART9_IRQn, (boolean)FALSE, 0U},
    {LPUART10_IRQn, (boolean)FALSE, 0U},
    {LPUART11_IRQn, (boolean)FALSE, 0U},
    {LPUART12_IRQn, (boolean)FALSE, 0U},
    {LPUART13_IRQn, (boolean)FALSE, 0U},
    {LPUART14_IRQn, (boolean)FALSE, 0U},
    {LPUART15_IRQn, (boolean)FALSE, 0U},
    {LPI2C0_IRQn, (boolean)FALSE, 0U},
    {LPI2C1_IRQn, (boolean)FALSE, 0U},
    {LPSPI0_IRQn, (boolean)FALSE, 0U},
    {LPSPI1_IRQn, (boolean)FALSE, 0U},
    {LPSPI2_IRQn, (boolean)FALSE, 0U},
    {LPSPI3_IRQn, (boolean)FALSE, 0U},
    {LPSPI4_IRQn, (boolean)FALSE, 0U},
    {LPSPI5_IRQn, (boolean)FALSE, 0U},
    {QSPI_IRQn, (boolean)FALSE, 0U},
    {SAI0_IRQn, (boolean)FALSE, 0U},
    {SAI1_IRQn, (boolean)FALSE, 0U},
    {JDC_IRQn, (boolean)FALSE, 0U},
    {ADC0_IRQn, (boolean)FALSE, 0U},
    {ADC1_IRQn, (boolean)FALSE, 0U},
    {ADC2_IRQn, (boolean)FALSE, 0U},
    {LPCMP0_IRQn, (boolean)FALSE, 0U},
    {LPCMP1_IRQn, (boolean)FALSE, 0U},
    {LPCMP2_IRQn, (boolean)FALSE, 0U},
    {FCCU_0_IRQn, (boolean)FALSE, 0U},
    {FCCU_1_IRQn, (boolean)FALSE, 0U},
    {STCU_LBIST_MBIST_IRQn, (boolean)FALSE, 0U},
    {HSE_MU0_TX_IRQn, (boolean)FALSE, 0U},
    {HSE_MU0_RX_IRQn, (boolean)FALSE, 0U},
    {HSE_MU0_ORED_IRQn, (boolean)FALSE, 0U},
    {HSE_MU1_TX_IRQn, (boolean)FALSE, 0U},
    {HSE_MU1_RX_IRQn, (boolean)FALSE, 0U},
    {HSE_MU1_ORED_IRQn, (boolean)FALSE, 0U},
    {SoC_PLL_IRQn, (boolean)FALSE, 0U},
};

/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    146U,
    
    aIrqConfiguration
    
};
    

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
