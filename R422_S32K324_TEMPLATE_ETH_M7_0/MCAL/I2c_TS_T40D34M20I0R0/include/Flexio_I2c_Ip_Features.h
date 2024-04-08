/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
#ifndef FLEXIO_I2C_IP_FEATURES_H
#define FLEXIO_I2C_IP_FEATURES_H

/**
*     @file
*
*     @addtogroup FLEXIO_I2C_DRIVER Flexio_I2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_FEATURES_VENDOR_ID                     43
#define FLEXIO_I2C_IP_FEATURES_MODULE_ID                     255
#define FLEXIO_I2C_IP_FEATURES_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_I2C_IP_FEATURES_AR_RELEASE_MINOR_VERSION      4
#define FLEXIO_I2C_IP_FEATURES_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_I2C_IP_FEATURES_SW_MAJOR_VERSION              2
#define FLEXIO_I2C_IP_FEATURES_SW_MINOR_VERSION              0
#define FLEXIO_I2C_IP_FEATURES_SW_PATCH_VERSION              0
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/** Number of Flexio i2c logical channel. */
#define FEATURE_FLEXIO_MAX_CHANNEL_COUNT  (4U)

/** Number of instances of the FLEXIO module. */
#define FLEXIO_I2C_IP_INSTANCE_COUNT                    (1u)


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* FLEXIO_I2C_IP_FEATURES_H*/
