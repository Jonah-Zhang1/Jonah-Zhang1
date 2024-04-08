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

#ifndef POWER_IP_PMC_TYPES_H
#define POWER_IP_PMC_TYPES_H

/**
*   @file       Power_Ip_PMC_Types.h
*   @version    2.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif




/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Specific.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PMC_TYPES_VENDOR_ID                       43
#define POWER_IP_PMC_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_PMC_TYPES_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_PMC_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_PMC_TYPES_SW_MAJOR_VERSION                2
#define POWER_IP_PMC_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_PMC_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_PMC_TYPES_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_PMC_Types.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_PMC_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC_Types.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_PMC_TYPES_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_TYPES_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_TYPES_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_PMC_Types.h and Power_Ip_Specific.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if defined(POWER_IP_DERIVATIVE_001) || defined(POWER_IP_DERIVATIVE_006)
/***********************************************************/
/*                        PMC_LVSC                         */
/***********************************************************/

#define PMC_LVSC_RAMP_UP_RESET_FLAGS_RWBITS_MASK32      ((uint32)0x80F30000U)
#define PMC_LVSC_RESET_FLAGS_RWBITS_MASK32              ((uint32)0x83F30000U)
#define PMC_LVSC_OV_UV_STATUS_FLAGS_MASK32              ((uint32)0x00001D00U)
#define PMC_LVSC_OV_UV_IRQ_FLAGS_MASK32                 ((uint32)0x0000001DU)

#define PMC_LVSC_UV_IRQ_FLAGS_MASK32                    ((uint32)0x00000010U)
#define PMC_LVSC_OV_IRQ_FLAGS_MASK32                    ((uint32)0x0000000DU)

#define PMC_LVSC_RWBITS_MASK32                          ((uint32)0x83F3001DU)
#define PMC_LVSC_RESET_MASK32                           ((uint32)0x00001000U)
#define PMC_LVSC_RESERVED_MASK32                        ((uint32)( (uint32)(~PMC_LVSC_RWBITS_MASK32) & PMC_LVSC_RESET_MASK32 ))

/***********************************************************/
/*                       PMC_CONFIG                        */
/***********************************************************/
#define PMC_CONFIG_LVD_INTERRUPTS_ENABLE        ((uint32)PMC_CONFIG_LVDIE_MASK)
#define PMC_CONFIG_LVD_INTERRUPTS_DISABLE       ((uint32)0x00000000U)

#define PMC_CONFIG_HVD_INTERRUPTS_ENABLE        ((uint32)PMC_CONFIG_HVDIE_MASK)
#define PMC_CONFIG_HVD_INTERRUPTS_DISABLE       ((uint32)0x00000000U)

#define PMC_CONFIG_LPM25_ENABLE                 ((uint32)PMC_CONFIG_LPM25EN_MASK)
#define PMC_CONFIG_LPM25_DISABLE                ((uint32)0x00000000U)

#define PMC_CONFIG_FAST_RECOVERY_ENABLE         ((uint32)PMC_CONFIG_FASTREC_MASK)
#define PMC_CONFIG_FAST_RECOVERY_DISABLE        ((uint32)0x00000000U)

#else /* S32K34x, S32K32x and S32K314 */
/***********************************************************/
/*                        PMC_LVSC                         */
/***********************************************************/
#define PMC_LVSC_V15_BELOW_LV                           ((uint32)PMC_LVSC_LVD15S_MASK)
#define PMC_LVSC_V15_ABOVE_LV                           ((uint32)0x00000000U)

#define PMC_LVSC_RAMP_UP_RESET_FLAGS_RWBITS_MASK32      ((uint32)0x80FF0000U)
#define PMC_LVSC_RESET_FLAGS_RWBITS_MASK32              ((uint32)0x83FF0000U)
#define PMC_LVSC_OV_UV_STATUS_FLAGS_MASK32              ((uint32)0x00003F00U)
#define PMC_LVSC_OV_UV_IRQ_FLAGS_MASK32                 ((uint32)0x0000003FU)

#define PMC_LVSC_UV_IRQ_FLAGS_MASK32                    ((uint32)0x00000030U)
#define PMC_LVSC_OV_IRQ_FLAGS_MASK32                    ((uint32)0x0000000FU)

#define PMC_LVSC_RWBITS_MASK32                          ((uint32)0x83FF003FU)
#define PMC_LVSC_RESET_MASK32                           ((uint32)0x00003000U)
#define PMC_LVSC_RESERVED_MASK32                        ((uint32)( (uint32)(~PMC_LVSC_RWBITS_MASK32) & PMC_LVSC_RESET_MASK32 ))
/***********************************************************/
/*                       PMC_CONFIG                        */
/***********************************************************/
#define PMC_CONFIG_LVD_INTERRUPTS_ENABLE        ((uint32)PMC_CONFIG_LVDIE_MASK)
#define PMC_CONFIG_LVD_INTERRUPTS_DISABLE       ((uint32)0x00000000U)

#define PMC_CONFIG_HVD_INTERRUPTS_ENABLE        ((uint32)PMC_CONFIG_HVDIE_MASK)
#define PMC_CONFIG_HVD_INTERRUPTS_DISABLE       ((uint32)0x00000000U)

#define PMC_CONFIG_LPM25_ENABLE                 ((uint32)PMC_CONFIG_LPM25EN_MASK)
#define PMC_CONFIG_LPM25_DISABLE                ((uint32)0x00000000U)

#define PMC_CONFIG_FAST_RECOVERY_ENABLE         ((uint32)PMC_CONFIG_FASTREC_MASK)
#define PMC_CONFIG_FAST_RECOVERY_DISABLE        ((uint32)0x00000000U)

#define PMC_CONFIG_LVRBLP_ENABLE                ((uint32)PMC_CONFIG_LVRBLPEN_MASK)
#define PMC_CONFIG_LVRBLP_DISABLE               ((uint32)0x00000000U)

#define PMC_CONFIG_LM_BASE_CONTROL_ENABLE       ((uint32)PMC_CONFIG_LMBCTLEN_MASK)
#define PMC_CONFIG_LM_BASE_CONTROL_DISABLE      ((uint32)0x00000000U)

#define PMC_CONFIG_LAST_MILE_REG_ENABLE         ((uint32)PMC_CONFIG_LMEN_MASK)
#define PMC_CONFIG_LAST_MILE_REG_DISABLE        ((uint32)0x00000000U)

#define PMC_CONFIG_LAST_MILE_REG_AUTO_ENABLE    ((uint32)PMC_CONFIG_LMAUTOEN_MASK)
#define PMC_CONFIG_LAST_MILE_REG_AUTO_DISABLE   ((uint32)0x00000000U)

#define PMC_CONFIG_LAST_MILE_REG_ON             ((uint32)PMC_CONFIG_LMSTAT_MASK)
#define PMC_CONFIG_LAST_MILE_REG_OFF            ((uint32)0x00000000U)

#endif  /* #ifdef POWER_IP_DERIVATIVE_001 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration for PMC.
* @details          The power control unit (PMC) acts as a bridge for mapping the PMC peripheral
 *                  to the PMC address space.
*/
typedef struct
{
    uint32 ConfigRegister;         /**< @brief PMC configuration register (CONFIG) */

} Power_Ip_PMC_ConfigType;

#if (defined(POWER_IP_VOLTAGE_ERROR_ISR_USED))
  #if(POWER_IP_VOLTAGE_ERROR_ISR_USED == STD_ON)
typedef enum
{
    PMC_UNINIT = 0,  /**< @brief The PMC driver is uninitialized. */
    PMC_INIT = 1     /**< @brief The PMC driver is initialized. */
} Power_Ip_PMC_StatusType;
  #endif
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_PMC_TYPES_H */
