/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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

#ifndef ICU_ENVCFG_H
#define ICU_ENVCFG_H

/**
*   @file
*
*   @addtogroup icu Icu Driver
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

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_ENVCFG_VENDOR_ID                        43

#define ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define ICU_ENVCFG_AR_RELEASE_MINOR_VERSION         4
#define ICU_ENVCFG_AR_RELEASE_REVISION_VERSION      0

#define ICU_ENVCFG_SW_MAJOR_VERSION                 2
#define ICU_ENVCFG_SW_MINOR_VERSION                 0
#define ICU_ENVCFG_SW_PATCH_VERSION                 0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define ICU_VALIDATE_GLOBAL_CALL         (ICU_DEV_ERROR_DETECT)
#define ICU_VALIDATE_CALL_AND_CHANNEL    (ICU_DEV_ERROR_DETECT)
#define ICU_VALIDATE_PARAMS              (ICU_DEV_ERROR_DETECT)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


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

#endif /* ICU_ENVCFG_H */
