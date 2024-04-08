/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

/**
*   @file
*
*   @internal
*   @addtogroup adc_ipw Adc Ipw
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external Units
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc.h"
#include "Adc_Ipw.h"
#include "Adc_Ipw_Irq.h"
#include "Adc_Ipw_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IPW_VENDOR_ID_IRQ_C                      43
#define ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C       4
#define ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define ADC_IPW_SW_MAJOR_VERSION_IRQ_C               2
#define ADC_IPW_SW_MINOR_VERSION_IRQ_C               0
#define ADC_IPW_SW_PATCH_VERSION_IRQ_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID)
    #error "Adc_Ipw_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_IRQ)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Irq.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Irq.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_IRQ) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_IRQ) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Irq.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same vendor */
#if (ADC_IPW_VENDOR_ID_IRQ_C != ADC_IPW_VENDOR_ID_TYPES)
    #error "Adc_Ipw_Irq.c and Adc_Ipw_Types.h have different vendor ids"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Autosar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_IPW_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_IPW_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

/* Check if Adc_Ipw_Irq.c file and Adc_Ipw_Types.h file are of the same Software version */
#if ((ADC_IPW_SW_MAJOR_VERSION_IRQ_C != ADC_IPW_SW_MAJOR_VERSION_TYPES) || \
     (ADC_IPW_SW_MINOR_VERSION_IRQ_C != ADC_IPW_SW_MINOR_VERSION_TYPES) || \
     (ADC_IPW_SW_PATCH_VERSION_IRQ_C != ADC_IPW_SW_PATCH_VERSION_TYPES) \
    )
  #error "Software Version Numbers of Adc_Ipw_Irq.c and Adc_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same AutoSar version */
#if ((ADC_IPW_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IPW_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Ipw_Irq.c and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
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
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
static inline Std_ReturnType Adc_Ipw_RecordResult(Adc_HwUnitType Unit,
                                                  Adc_GroupType Group,
                                                  Adc_StreamNumSampleType GroupSamples,
                                                  uint32 CoreId);

static inline Adc_StreamNumSampleType Adc_Ipw_GetNumsCurrentSample(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                                   boolean RuntimeChanUpdated);

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
static inline boolean Adc_Ipw_CheckNotification(Adc_GroupType Group,
                                                uint32 CoreId);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
     ((defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint32 CoreId);

static inline void Adc_Ipw_UpdateGroupState(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            Adc_StreamNumSampleType GroupSamples,
                                            boolean InjectedFlag,
                                            uint32 CoreId);
#endif /* defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) ||... */

#ifdef ADC_DMA_SUPPORTED
static inline void Adc_Ipw_UpdateTcdDestAddr(const Adc_GroupConfigurationType * GroupPtr,
                                             const uint32 DmaLogicChannel);

static inline void Adc_Ipw_EnableDmaHwRequest(Adc_HwUnitType Unit,
                                              const Adc_GroupConfigurationType * GroupPtr,
                                              const Adc_Ipw_Config * const AdcIpwConfigPtr);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint32 AdcDmaLogicChId,
                                                             uint32 CoreId);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
     ((defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
static inline void Adc_Ipw_ConfigureRuntimeSoftwareGroup(const Adc_GroupConfigurationType * GroupPtr,
                                                         Adc_HwUnitType PhysicalHwUnitId,
                                                         boolean InjectedFlag,
                                                         uint32 CoreId);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

static inline void Adc_Ipw_EndSoftwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint32 CoreId);
#endif /* defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) ||... */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ( \
        ((defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
        defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED) || \
        defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
        ((defined(ADC_UNIT_0_BCTU_LIST_ISR_USED) || defined(ADC_UNIT_1_BCTU_LIST_ISR_USED) || defined(ADC_UNIT_2_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
static inline Std_ReturnType Adc_Ipw_ConfigureRuntimeHardwareGroup(Adc_HwUnitType Unit,
                                                                   boolean InjectedFlag,
                                                                   uint32 CoreId);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
static inline void Adc_Ipw_DisableHwTriggerSrc(Adc_HwUnitType Unit,
                                               boolean InjectedFlag,
                                               Adc_HwTriggerTimerType TriggerSrc,
                                               uint32 CoreId);
#endif /* ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF */

static inline void Adc_Ipw_EndHardwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint32 CoreId);
#endif /* (((defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || ... */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_0_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_2_NORMAL_ISR_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
static inline void Adc_Ipw_EndNormalChainNotification(const Adc_HwUnitType PhysicalAdcUnit);
#endif /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */

#if (defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_0_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_2_INJECTED_ISR_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
static inline void Adc_Ipw_EndInjectedChainNotification(const Adc_HwUnitType PhysicalAdcUnit);
#endif /* (defined(ADC_UNIT_0_INJECTED_ISR_USED) || ... */

static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * Result,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult);

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint32 CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif  /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) || (defined(ADC_UNIT_1_WDG_ISR_USED)) || \
     (defined(ADC_UNIT_2_WDG_ISR_USED)) || (defined(ADC_UNIT_3_WDG_ISR_USED)) \
    )
#if defined(ADC_WDG_SUPPORTED)
static inline void Adc_Ipw_WdgThresholdNotification(const Adc_HwUnitType PhysicalAdcUnit,
                                                    const Adc_ChannelType PhysicalChanId,
                                                    const uint8 Flags);
#endif /* defined(ADC_WDG_SUPPORTED) */
#endif /* defined(ADC_UNIT_0_WDG_ISR_USED) || ... */


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          This function check if channel is enabled/disabled.
* @details        This function check if channel is enabled/disabled.
*
* @param[in]      LogicalHwUnitId   Hardware index in the structure.
* @param[in]      GroupId           Group index.
* @param[in]      ChIndex           Channel index of group.
* @param[in]      CoreId            Current CoreID.
*
* @return         Std_ReturnType    E_OK or E_NOT_OK.
* @retval         E_OK              Channel is enabled.
* @retval         E_NOT_OK          Channel is disabled.
*
*/
static inline Std_ReturnType Adc_Ipw_IsChannelEnable(Adc_HwUnitType LogicalHwUnitId,
                                                     Adc_GroupType GroupId,
                                                     Adc_ChannelType ChIndex,
                                                     uint32 CoreId)
{
    uint32 ChannelEnBit = 0UL;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;
    const uint32 PhysicalChanId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcConfigPtrArr[LogicalHwUnitId]->ChannelConfigsPtr[ChIndex].ChanIndex;

    if (PhysicalChanId < 32u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[0u] >> PhysicalChanId) & 1UL;
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 1u)
    else if (PhysicalChanId < 64u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[1u] >> (PhysicalChanId % 32u)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 1u) */
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 2u)
    else if (PhysicalChanId < 96u)
    {
        ChannelEnBit = (Adc_axRuntimeChansEnMask[GroupId].ChanMaskArr[2u] >> (PhysicalChanId % 32u)) & 1UL;
    }
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 2u) */
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
    #if (ADC_IPW_NUM_OF_GROUP_CHN > 3u)
    #error "Adc IPW ADC_IPW_NUM_OF_GROUP_CHN out of range."
    #endif /* (ADC_IPW_NUM_OF_GROUP_CHN > 3u) */

    if (1UL == ChannelEnBit)
    {
        ReturnValue = (Std_ReturnType)E_OK;
    }

    return ReturnValue;
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

/**
* @brief          This function gets the conversion result and save to buffer
* @details        This function gets the conversion result and save to buffer
*
* @param[in]      Unit              The used hardware unit
* @param[in]      Group             The group to be converted
* @param[in]      GroupSamples      Number of group samples
* @param[in]      CoreId            Current CoreID
*
* @return         Std_ReturnType    Checking value
* @retval         E_OK              Result is satisfied limit checking function
* @retval         E_NOT_OK          Result is NOT satisfied limit checking function
*
* @implements Adc_Ipw_RecordResult_Activity
*/
static inline Std_ReturnType Adc_Ipw_RecordResult(Adc_HwUnitType Unit,
                                                  Adc_GroupType Group,
                                                  Adc_StreamNumSampleType GroupSamples,
                                                  uint32 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    Adc_ChannelIndexType Ch = 0U;
    Adc_ChannelType ChIndex = 0U;
    Adc_ValueGroupType * Result = NULL_PTR;
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_GroupDefType * Channel;
    const Adc_Sar_Ip_ConfigType * AdcPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);
    Adc_Sar_Ip_ChanResultType AdcResult;
    Adc_TriggerSourceType GrTriggerSrc = GroupPtr->TriggerSource;

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_GroupType GroupId;
    Std_ReturnType ChannelEnable;
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Flag to set if ADC results are in the range selected */
    boolean Flag;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    Adc_ChannelIndexType ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get channel count at runtime */
    ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;
    Channel = &(Adc_axRuntimeGroupChannel[Group].ChannelPtr[0u]);
#else
    /* Get channel count from configuration */
    ChannelCount = GroupPtr->AssignedChannelCount;
    Channel = &(GroupPtr->AssignmentPtr[0u]);
#endif

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    /* Get the result buffer pointer */
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
    {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        Result = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    }
    else
    {
        Result = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex * ChannelCount]);
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

    for (Ch = 0U; Ch < ChannelCount; Ch++)
    {
        ChIndex = Channel[Ch];

        /* Get the result */
        if (ADC_TRIGG_SRC_SW == GrTriggerSrc)
        {
            Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), (Adc_Sar_Ip_ConvChainType)GroupPtr->Type, &AdcResult);
        }
#if (STD_ON == ADC_HW_TRIGGER_API)
        else
        {
            if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType) ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
            {
                /* Data conversion comes from CTU Trigger */
                Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), ADC_SAR_IP_CONV_CHAIN_CTU, &AdcResult);
            }
            else
            {
                /* Data conversion comes from Normal and Injected Trigger */
                Adc_Sar_Ip_GetConvResult(PhysicalHwUnitId, (uint32)(AdcPtr->ChannelConfigsPtr[ChIndex].ChanIndex), (Adc_Sar_Ip_ConvChainType)GroupPtr->Type, &AdcResult);
            }
        }
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /* Get index of the group with AdcEnableChDisableChGroup enabled */
        GroupId = (Adc_GroupType)GroupPtr->EnableChDisableChGroupIndex;
        /* Check if group have AdcEnableChDisableChGroup enabled */
        if (ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupId)
        {
            /* Check if ChIndex is enabled */
            ChannelEnable = Adc_Ipw_IsChannelEnable(Unit, GroupId, ChIndex, CoreId);
        }
        else
        {
            /* ChIndex is always enabled when AdcEnableChDisableChGroup disabled */
            ChannelEnable = E_OK;
        }
        if ((Std_ReturnType)E_OK == ChannelEnable)
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
        {
            /* If channel is enabled, check valid and result bit */
            if (TRUE == AdcResult.ValidFlag)
            {
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
                /* Checks if conversion values are in the configured range */
                if (
                        (TRUE == GroupPtr->AdcGroupLimitcheck)
#if (ADC_SETCHANNEL_API == STD_ON)
                        || (TRUE == Adc_axRuntimeGroupChannel[Group].AdcRuntimeGroupLimitcheck)
#endif /* ADC_SETCHANNEL_API == STD_ON */
                   )
                {
                    Flag = Adc_Ipw_CheckConversionValuesInRange(AdcResult.ConvData, Unit, ChIndex, CoreId);
                    if (TRUE == Flag)
                    {
                        Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
                    }
                    else
                    {
                        /* SWS_Adc_00448 */
                        /* Return an error */
                        Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
                        Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;

                        ReturnValue = (Std_ReturnType)E_NOT_OK;
                    }
                }
                else /* In case of AdcGroupLimitcheck = FALSE */
                {
                    Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
                    Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
                }
#else
                Adc_Ipw_ReadData(GroupPtr, Result, GroupSamples, Ch, AdcResult.ConvData);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            }
            else /* In case of result is not true for this convert type*/
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
            }

            if ((Std_ReturnType)E_NOT_OK == ReturnValue)
            {
                break;
            }
        }
    }
    return ReturnValue;
}

static inline Adc_StreamNumSampleType Adc_Ipw_GetNumsCurrentSample(const Adc_Ipw_Config * const AdcIpwConfigPtr,
                                                                   const Adc_GroupConfigurationType * const GroupPtr,
                                                                   boolean RuntimeChanUpdated)
{
    Adc_StreamNumSampleType NumsCurrentSample = 0U;
    const Adc_GroupType Group = GroupPtr->GroupId;
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    uint32 CurrentIter = 0U;
    const Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    const Adc_StreamNumSampleType GroupSamples = GroupPtr->NumSamples;
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[LogicalHwUnitId];
    const uint32 AdcCountingDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcCountingDmaChanLogicId[LogicalHwUnitId];

    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        if (1U < (GroupPtr->AssignedChannelCount))
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcCountingDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }
        else
        {
            (void)Dma_Ip_GetLogicChannelParam(AdcDmaLogicChId, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &CurrentIter);
        }

        /* This condition only occurs at half interrupt */
        if (CurrentIter != GroupSamples)
        {
            /* Re-calculate NumsCurrentSample because CITER decrements its value from GroupSamples to 1 */
            NumsCurrentSample = GroupSamples - (Adc_StreamNumSampleType)CurrentIter;
        }
        else
        {
            /* When major loop completed, CITER roll back to be equal to GroupSamples so no need to re-calculate */
            NumsCurrentSample = (Adc_StreamNumSampleType)CurrentIter;
        }
        Adc_axGroupStatus[Group].ResultIndex = NumsCurrentSample;
    }
    else
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
    {
        if (
            (ADC_TRIGG_SRC_SW != GroupPtr->TriggerSource)
#if (ADC_SETCHANNEL_API == STD_ON)
             && (FALSE == RuntimeChanUpdated)
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
           )
        {
            /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
            Adc_axGroupStatus[Group].ResultIndex++;
        }
        NumsCurrentSample = Adc_axGroupStatus[Group].ResultIndex;
    }

    /* Avoid Compiler Warning */
    (void) AdcIpwConfigPtr;
    (void) RuntimeChanUpdated;

    return NumsCurrentSample;
}

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
* @brief          This function checks group notification
* @details        This function checks group notification
*
* @param[in]      Group             The group to be converted
* @param[in]      CoreId            Current CoreID
*
* @return         boolean      Checking result
* @retval         TRUE:        Notification call is available
* @retval         FALSE:       Notification call is NOT available
*
*/
static inline boolean Adc_Ipw_CheckNotification(Adc_GroupType Group,
                                                uint32 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    boolean CallNotification =  FALSE;

    /* SWS_Adc_00080, SWS_Adc_00083 */
    if ((ADC_NOTIFICATION_ENABLED == Adc_axGroupStatus[Group].Notification) && \
        (NULL_PTR != Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].Notification)
       )
    {
        CallNotification =  TRUE;
    }
    return CallNotification;
}
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
     ((defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
/**
* @brief          This function updates queue
* @details        This function updates queue elements after a conversion
*                 and start conversion if requests are still available in queue
*
* @param[in]      Unit              The ADC hardware unit
* @param[in]      CoreId            Current CoreID
*
* @return         void
*
*/
static inline void Adc_Ipw_UpdateQueue(Adc_HwUnitType Unit,
                                       uint32 CoreId)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    /* Remove current request element in queue */
    Adc_Ipw_RemoveFromQueue(Unit, 0U);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    if (Adc_axUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        /* Start conversion if request elements are still available in queue */
        Adc_Ipw_StartNormalConversion(Unit, CoreId);
    }
#endif
#else
    /* No element will be present in the queue */
    Adc_axUnitStatus[Unit].SwNormalQueueIndex= (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
    (void)CoreId;
}

/**
* @brief          This function update state of software conversion according to AutoSar diagrams
* @details        This function update state of software conversion according to AutoSar diagrams
*
* @param[in]      Unit              ADC hardware unit
* @param[in]      Group             ADC group number
* @param[in]      GroupSamples      Number of samples per channel in streaming access mode
* @param[in]      InjectedFlag      Normal or injected conversion
* @param[in]      CoreId            Current CoreID
*
* @return         void
*
*/
static inline void Adc_Ipw_UpdateGroupState(Adc_HwUnitType Unit,
                                            Adc_GroupType Group,
                                            Adc_StreamNumSampleType GroupSamples,
                                            boolean InjectedFlag,
                                            uint32 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);
    Adc_StreamNumSampleType CurrentSampleCount = 0U;
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
#ifdef ADC_DMA_SUPPORTED
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
#endif /* ADC_DMA_SUPPORTED */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    boolean  CallNotification = FALSE;
#endif
    boolean StreamBuffLinear = FALSE;

    CurrentSampleCount = Adc_Ipw_GetNumsCurrentSample(AdcIpwConfigPtr, GroupPtr, FALSE);
    /* At least once the group was converted */
    Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
    {
        /* SWS_Adc_00224 */
        Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
    }

    /* If buffer is full of samples, wrap to 0 */
    if (GroupSamples <= CurrentSampleCount)
    {
        /* Change to stream complete according to AUTOSAR diagram */
        /* SWS_Adc_00325 */
        Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

        if ((ADC_STREAM_BUFFER_LINEAR == GroupPtr->BufferMode) && \
           (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
          )
        {
            StreamBuffLinear = TRUE;
#ifdef ADC_DMA_SUPPORTED
            /* Not required to check AdcWithoutDma == FALSE, because AdcWithoutDma is only supported for SW normal triggered which cannot be ADC_ACCESS_MODE_STREAMING when DMA transfer selected for HW unit */
            if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                /* Disable ADC DMA Request */
                Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
                Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
            }
#endif /* ADC_DMA_SUPPORTED */

            if (Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE) == ADC_SAR_IP_STATUS_SUCCESS)
            {
                Adc_Ipw_ClearValidBit(Unit, Group, CoreId);
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */
                Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);

                /* Update queue and execute new start conversion request from queue if available */
                Adc_Ipw_UpdateQueue(Unit, CoreId);

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                /* Check user notification function and execute if available */
                CallNotification = Adc_Ipw_CheckNotification(Group, CoreId);

                if (TRUE == CallNotification)
                {
                    /* SWS_Adc_00140, SWS_Adc_00060 */
                    GroupPtr->Notification();
                }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
            }
        }
        else
        {
            Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
            if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
                if (((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable) && (1U == GroupPtr->AssignedChannelCount))
                {
                    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                    LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                }
            }
#endif /* ADC_DMA_SUPPORTED */
        }
    }

    if (FALSE == StreamBuffLinear)
    {
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        CallNotification = Adc_Ipw_CheckNotification(Group, CoreId);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

        if (ADC_CONV_MODE_ONESHOT == GroupPtr->Mode)
        {
            /* SWS_Adc_00325 */
            Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;

            if (FALSE == InjectedFlag)
            {
                /* Disable Normal Interrupt Mask */
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */
                Adc_Ipw_UpdateQueue(Unit, CoreId);
            }
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
            else
            {
#if (defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED))
                Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_INJECTED_ISR_USED) || ... */
                /* No element will be present in the sw inj queue */
                Adc_axUnitStatus[Unit].SwInjectedQueueIndex = 0U;
            }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
        }

#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        if (TRUE == InjectedFlag)
        {
            /* Clear injected end of chain interrupt flag */
            Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        }
        else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
        {
            /* Clear normal end of chain interrupt flag */
            Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
        }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        if (TRUE == CallNotification)
        {
            /* Call user notification (SWS_Adc_00140, SWS_Adc_00060) */
            GroupPtr->Notification();
        }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* Update the Next Destination Address for Streaming Group. For Software Single Group, the DMA will be re-configured by Adc_StartGroupConversion */
                if (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode)
                {
                    Adc_Ipw_UpdateTcdDestAddr(GroupPtr, AdcDmaLogicChId);
                }
                Adc_Ipw_EnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
            }
        }
#endif /* ADC_DMA_SUPPORTED */
    }
}
#endif /* defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) ||... */

#ifdef ADC_DMA_SUPPORTED

/**
* @brief        This function updates TCD Destination Address of Next Result Buffer for Streaming Group
* @details      This function is called after one sample completes the conversion. The next address of
*               Result Buffer should be updated if number of channel in the Group greater than one.
*
* @param[in]    GroupPtr           The pointer to the group configuration structure.
* @param[in]    DmaLogicChannel  The Logical Dma Channel Id that was configured.
*
* @return       void
*
*/
static inline void Adc_Ipw_UpdateTcdDestAddr(const Adc_GroupConfigurationType * GroupPtr,
                                             const uint32 DmaLogicChannel)
{
    uint8 Index;
    const Adc_StreamNumSampleType GroupNumSample = GroupPtr->NumSamples;
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_ChannelIndexType ChannelCount = GroupPtr->AssignedChannelCount;
    uint32 DestAddOff;
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];

    if ( \
            (1U < ChannelCount)
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
         && (FALSE == GroupPtr->AdcOptimizeDmaStream)
#endif /* ADC_OPTIMIZE_DMA_STREAMING_GROUPS = STD_ON */
       )
    {
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        if (FALSE == GroupPtr->StreamResultGroupMultiSets)
        {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
            DestAddOff = (uint32)Adc_axGroupStatus[Group].ResultIndex << 1UL;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
        }
        else
        {
            DestAddOff = ((uint32)Adc_axGroupStatus[Group].ResultIndex * ChannelCount) << 1UL;
        }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

        for (Index = 0; Index < ChannelCount; Index++)
        {
            LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;

#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
            if (FALSE == GroupPtr->StreamResultGroupMultiSets)
            {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index * GroupNumSample])) + DestAddOff;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
            }
            else
            {
                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Index])) + DestAddOff;
            }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */

            /* Write TCD Configuration for each channel */
            (void)Dma_Ip_SetLogicChannelScatterGatherList(DmaLogicChannel, Index, LocTransferList, 1U);
        }
        /* Write the first Software TCD to the Hardware. The next one will be loaded automaticaly by Scatter/Gather Programming */
        (void)Dma_Ip_SetLogicChannelScatterGatherConfig(DmaLogicChannel, 0U);
    }
}

/**
* @brief        This function enables DMA Hardware request
* @details      This function enables DMA Hardware request which was disabled automatically (by enabling DREQ) at the end of DMA major loop.
*
* @param[in]    Unit                  Physical HW unit index.
* @param[in]    GroupPtr             Configuration pointer of group.
* @param[in]    AdcIpwConfigPtr      Configuration pointer contains DMA channel ID.
*
* @return       void
*
*/
static inline void Adc_Ipw_EnableDmaHwRequest(Adc_HwUnitType Unit,
                                              const Adc_GroupConfigurationType * GroupPtr,
                                              const Adc_Ipw_Config * const AdcIpwConfigPtr)
{
    uint32 AdcDmaLogicChId = (uint32) AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
    Adc_GroupType Group = GroupPtr->GroupId;

    if (TRUE == GroupPtr->AdcOptimizeDmaStream)
    {
        if ((ADC_STREAM_COMPLETED == Adc_axGroupStatus[Group].Conversion) && (1U == (GroupPtr->AssignedChannelCount)))
        {
            /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
            (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
        }
    }
    else
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
    {
        /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
        (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
        /* Avoid Compiler Warning */
        (void)GroupPtr;
    }
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          This function checks the conversion result when Limit Check and DMA are enabled.
* @details        This function checks the conversion result when Limit Check and DMA are enabled.
*
* @param[in]      GroupPtr         The Adc Group Pointer.
* @param[in]      AdcDmaLogicChId  Dma logical channel
* @param[in]      CoreId           Current CoreID
*
* @return         Std_ReturnType
*
*/
static inline Std_ReturnType Adc_Ipw_CheckGroupConvResultDma(const Adc_GroupConfigurationType * GroupPtr,
                                                             uint32 AdcDmaLogicChId,
                                                             uint32 CoreId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    const Adc_GroupType Group = GroupPtr->GroupId;
    const Adc_HwUnitType Unit = GroupPtr->AdcLogicalUnitId;
    const uint8 AvailableResolutions[4U] = ADC_IPW_AVAILABLE_RESOLUTIONS;
    Adc_ValueGroupType * ResultData = &(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]);
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    Adc_ValueGroupType LocalValue = ResultData[0];

    if (TRUE == GroupPtr->AdcGroupLimitcheck)
    {
        if (FALSE == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->BypassResolution)
        {
            /* Shift the result right to have the correct resolution for limit checking. */
            LocalValue >>= (ADC_SAR_IP_RESULT_RESOLUTION - AvailableResolutions[(uint8)(Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcConfigPtrArr[Unit]->AdcResolution)]);
        }
        /* Assumption: because of SWS_Adc_00451, the number of channels configured for a group when limit checking is disabled, must be one.*/
        if (FALSE == Adc_Ipw_CheckConversionValuesInRange(LocalValue, Unit, GroupPtr->AssignmentPtr[0], CoreId))
        {
            /* SWS_Adc_00448 */
            /* Return an error */
            Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            Adc_axGroupStatus[Group].LimitCheckFailed = TRUE;
            ResultData[0] = 0U;
            ReturnValue = (Std_ReturnType) E_NOT_OK;
            if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
            {
                /* If the Result Conversion is out of range, need to reset Destination Address to previous Buffer Address. */
                /* Because the Destination Offset for Streaming Group that has one channel configured be 2U to reducing additional in the callback. */
                if (GroupPtr->AccessMode == ADC_ACCESS_MODE_STREAMING)
                {
                    LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                    LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                    (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                }
                /* DMA Hardware Request was disabled after transfer completed, to avoid overwriting any new results before this gets processed. Re-enable DMA here. */
                (void)Dma_Ip_SetLogicChannelCommand(AdcDmaLogicChId, DMA_IP_CH_SET_HARDWARE_REQUEST);
            }
        }
        else
        {
            Adc_axGroupStatus[Group].LimitCheckFailed = FALSE;
        }
    }

    return ReturnValue;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED) || \
     defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
     ((defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED)) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief          This function reconfigures runtime updated channels
* @details        This function reconfigures runtime updated channels for software trigger groups
*
* @param[in]      GroupPtr                  Group configuration pointer
* @param[in]      PhysicalHwUnitId          Adc Physical Unit Id
* @param[in]      InjectedFlag              Injected (TRUE) or Normal (FALSE) group
* @param[in]      CoreId                    Current CoreID
*
* @return         void.
*/
static inline void Adc_Ipw_ConfigureRuntimeSoftwareGroup(const Adc_GroupConfigurationType * GroupPtr,
                                                         Adc_HwUnitType PhysicalHwUnitId,
                                                         boolean InjectedFlag,
                                                         uint32 CoreId)
{
    Adc_Sar_Ip_ConvChainType ChainType = ADC_SAR_IP_CONV_CHAIN_NORMAL;
    uint32 EndChainFlag = ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN;
    Adc_GroupType Group = GroupPtr->GroupId;
    Adc_HwUnitType LogicalHwUnitId = GroupPtr->AdcLogicalUnitId;
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;

    if (ADC_SAR_IP_STATUS_SUCCESS == Adc_Sar_Ip_AbortChain(PhysicalHwUnitId, TRUE, FALSE))
    {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        if (TRUE == InjectedFlag)
        {
            ChainType = ADC_SAR_IP_CONV_CHAIN_INJECTED;
            EndChainFlag = ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN;
        }
#else
        (void)InjectedFlag;
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

        Adc_axGroupStatus[Group].ResultIndex = 0U;
        /* Get run-time configuration and update normal conversion mask registers */
        Adc_Ipw_GetCmrRegister(LogicalHwUnitId, Group, &CmrMask, CoreId);
        Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ChainType);
        /* Clear pending ISR request which might occur with continuous groups */
        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, EndChainFlag);
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated = FALSE;

        /* Restart group conversion */
        Adc_Sar_Ip_StartConversion(PhysicalHwUnitId, ChainType);
    }
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

/**
* @brief          This function handles the normal conversion ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit                the current HW Unit.
* @param[in]      InjectedFlag        Normal or Injected conversion.
* @param[in]      CoreId              Current CoreID
*
* @return         void
*
* @api
* @implements     Adc_Ipw_EndSoftwareConv_Activity
*/
static inline void Adc_Ipw_EndSoftwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint32 CoreId)
{
    Adc_GroupType GroupIndex = 0U;
    Adc_GroupType Group = 0U;
    /* Streaming num samples should be at least 1U */
    Adc_StreamNumSampleType GroupSamples;
    Std_ReturnType CheckingStatus = (Std_ReturnType) E_OK;
#if defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON)
    const Adc_GroupConfigurationType * GroupPtr; /* Pointer to AdcGroup */
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON) */
#ifdef ADC_DMA_SUPPORTED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Std_ReturnType LimitCheckDmaStatus = (Std_ReturnType) E_OK;
    const uint32 AdcDmaLogicChId = (uint32) Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
#endif /*ADC_DMA_SUPPORTED*/
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Get the group to be converted */
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
    if (TRUE == InjectedFlag)
    {
        Group = Adc_axUnitStatus[Unit].SwInjectedQueue[0];
    }
    else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
    {
        Group = Adc_axUnitStatus[Unit].SwNormalQueue[0];
    }

    GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    GroupSamples = Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].NumSamples;

#if defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON)
    GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Check if channel was updated before interrupt of previous conversions */
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        Adc_Ipw_ConfigureRuntimeSoftwareGroup(GroupPtr, PhysicalHwUnitId, InjectedFlag, CoreId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA != Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
        {
#endif /*ADC_DMA_SUPPORTED*/
            /* Get the conversion result and save to buffer */
            CheckingStatus = Adc_Ipw_RecordResult(Unit, Group, GroupSamples, CoreId);
#ifdef ADC_DMA_SUPPORTED
            Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
            Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        else
        {
            LimitCheckDmaStatus = Adc_Ipw_CheckGroupConvResultDma(GroupPtr, AdcDmaLogicChId, CoreId);
        }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /*ADC_DMA_SUPPORTED*/

#if (defined(ADC_DMA_SUPPORTED) && (ADC_ENABLE_LIMIT_CHECK == STD_ON))
        if ((Std_ReturnType)E_OK == LimitCheckDmaStatus)
#endif /* defined(ADC_DMA_SUPPORTED) && (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
            /* Call extra notification (if available) before updating registers (SWS_Adc_00060) */
            Adc_Ipw_CallExtraNotification(Group, CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
            if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
            {
                Adc_Ipw_ConfigureRuntimeSoftwareGroup(GroupPtr, PhysicalHwUnitId, InjectedFlag, CoreId);
            }
            else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
            {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
                if (TRUE == InjectedFlag)
                {
    #ifdef ADC_DMA_SUPPORTED
        #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
                    if (ADC_DMA == Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                    {
                        if (Adc_axUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
                        {
                            /* Restart normal conversion */
                            Adc_Ipw_StartNormalConversion(Unit, CoreId);
                        }
                    }
        #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
    #endif /* ADC_DMA_SUPPORTED */
                    if ((Std_ReturnType)E_NOT_OK == CheckingStatus)
                    {
                        Adc_axGroupStatus[Group].ResultIndex = 0U;
                    }
                }
                else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
                {
                    if ((Std_ReturnType)E_NOT_OK == CheckingStatus)
                    {
                        if (ADC_CONV_MODE_ONESHOT == Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].Mode)
                        {
                            /* Disable end of chain interrupt mask */
#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED))
                            Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */
                        }

                        /* Clear normal interrupt flag */
                        Adc_Sar_Ip_ClearStatusFlags(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
                    }
#ifdef ADC_DMA_SUPPORTED
#if (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS)
                    if (FALSE == GroupPtr->AdcOptimizeDmaStream)
#endif /* (STD_ON == ADC_OPTIMIZE_DMA_STREAMING_GROUPS) */
#endif /* ADC_DMA_SUPPORTED */
                    {
                        if ((Std_ReturnType)E_OK == CheckingStatus)
                        {
                            /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
                            Adc_axGroupStatus[Group].ResultIndex++;
                        }
                    }
                }
            }
            if ((Std_ReturnType)E_OK == CheckingStatus)
            {
                /* Update group state and continue conversion */
                Adc_Ipw_UpdateGroupState(Unit, Group, GroupSamples, InjectedFlag, CoreId);
            }
        }
    }
}
#endif /* defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) ||... */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ( \
        ((defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED)) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) || \
        defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED) || \
        defined(ADC_UNIT_0_DMA_TRANSFER_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) || \
        ((defined(ADC_UNIT_0_BCTU_LIST_ISR_USED) || defined(ADC_UNIT_1_BCTU_LIST_ISR_USED) || defined(ADC_UNIT_2_BCTU_LIST_ISR_USED)) && (ADC_IPW_BCTU_AVAILABLE == STD_ON)) \
    )
#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief          This function configs command lists for trigger unit
*                 channel in adc unit when a hardware conversion ends
*
* @details        This function configs command lists for trigger unit
*                 channel in adc unit when a hardware conversion ends
*
* @param[in]      Unit                  The current HW Unit.
* @param[in]      InjectedFlag          Normal or Injected conversion.
* @param[in]      CoreId                Current CoreID
*
* @return         Std_ReturnType
*
* @api
* @implements     Adc_Ipw_ConfigureRuntimeHardwareGroup_Activity
*/
static inline Std_ReturnType Adc_Ipw_ConfigureRuntimeHardwareGroup(Adc_HwUnitType Unit,
                                                                   boolean InjectedFlag,
                                                                   uint32 CoreId)
{
    Adc_Sar_Ip_ChansIdxMaskType CmrMask;
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;

#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
    uint8 ChanList[ADC_MAX_CHANNEL_PER_HW_UNIT];
    Adc_ChannelIndexType ChannelCount;
    Bctu_Ip_TrigConfigType TrigConfig;
    Bctu_Ip_StatusType BctuStatus;
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    const Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Get the group to be converted */
    Adc_GroupType Group = Adc_axUnitStatus[Unit].OngoingHwGroup;
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    const Adc_GroupConfigurationType * GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);

#if ((ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_CTU_AVAILABLE == STD_ON) || (ADC_IPW_BCTU_AVAILABLE == STD_ON)))
    if (GroupPtr->HwTriggerSource <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        Bctu_Ip_SetGlobalTriggerEn(ADC_IPW_CTU_UNIT_USED, FALSE);

        /* Get index of List channel register */
        TrigConfig.TrigIndex       = (uint8)GroupPtr->HwTriggerSource;
        TrigConfig.LoopEn         = FALSE;
        TrigConfig.DataDest       = BCTU_IP_DATA_DEST_ADC_DATA_REG;
        TrigConfig.HwTriggersEn   = TRUE;
        TrigConfig.AdcTargetMask = (1u << PhysicalHwUnitId);
        TrigConfig.TrigType = BCTU_IP_TRIG_TYPE_LIST;
        /* Use list address start index allocated for the HW unit */
        TrigConfig.AdcChanOrListStart = AdcIpwConfigPtr->CtuListStartIndex[Unit];

        BctuStatus = Bctu_Ip_ConfigTrigger(ADC_IPW_CTU_UNIT_USED, &TrigConfig);
        if (BctuStatus == BCTU_IP_STATUS_SUCCESS)
        {
            ChannelCount = Adc_axRuntimeGroupChannel[Group].ChannelCount;

            Adc_Ipw_GetCtuChanList(ChanList, (uint8)ChannelCount, Group, Unit, CoreId);

            Bctu_Ip_ConfigChanListSimple(ADC_IPW_CTU_UNIT_USED, AdcIpwConfigPtr->CtuListStartIndex[Unit], ChanList, ChannelCount);

            Bctu_Ip_SetGlobalTriggerEn(ADC_IPW_CTU_UNIT_USED, TRUE);
        }
        else
        {
            ReturnStatus = (Std_ReturnType)E_NOT_OK;
        }
#else /* ADC_IPW_CTU_AVAILABLE */
        ReturnStatus = Adc_Ipw_CtuTriggerEnable(Group, GroupPtr->HwTriggerSource, TRUE, TRUE, CoreId);
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
    }
    else
#endif /* (ADC_IPW_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_IPW_CTU_AVAILABLE == STD_ON) || (ADC_IPW_BCTU_AVAILABLE == STD_ON)) */
    {
        Adc_Ipw_GetCmrRegister(Unit, Group, &CmrMask, CoreId);
        if (TRUE == InjectedFlag)
        {
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_INJECTED);
        }
    #if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        else
        {
            Adc_Sar_Ip_ChainConfig(PhysicalHwUnitId, &CmrMask, ADC_SAR_IP_CONV_CHAIN_NORMAL);
        }
    #endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    }

    if (ReturnStatus == (Std_ReturnType)E_OK)
    {
        Adc_axGroupStatus[Group].ResultIndex = 0U;
        Adc_axRuntimeGroupChannel[Group].RuntimeUpdated =  FALSE;
    }

    return ReturnStatus;
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function disable trigger source and notifications.
* @details        This function disable trigger source and notifications.
*
* @param[in]      Unit                 The current HW Unit.
* @param[in]      InjectedFlag         Normal or Injected conversion.
* @param[in]      TriggerSrc           Hardware trigger source
* @param[in]      CoreId               Current CoreID
*
* @return         void
*
* @api
* @implements     Adc_Ipw_DisableHwTriggerSrc_Activity
*/
static inline void Adc_Ipw_DisableHwTriggerSrc(Adc_HwUnitType Unit,
                                               boolean InjectedFlag,
                                               Adc_HwTriggerTimerType TriggerSrc,
                                               uint32 CoreId)
{
    Adc_HwUnitType PhysicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];

    /* Stop Conversion */
    if (TRUE == InjectedFlag)
    {
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
        if (TriggerSrc <= (Adc_HwTriggerTimerType)ADC_IPW_MAX_CTU_TRIG_SOURCE_ID)
        {
            /* Conversion triggered by BCTU/CTU */
            Bctu_Ip_DisableHwTrigger(ADC_IPW_CTU_UNIT_USED, (uint8)TriggerSrc);

            /* Not needed to clear interrupt flags status, because this is already done in IPL interrupt,
            before calling the IPW function as notification */
        }
        else
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */
        {
            /* Conversion is External Trigger */
            /* Disable injected external trigger input */
            Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_INJECTED_EXT_TRIG);
#if (defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_2_INJECTED_ISR_USED))
            Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_INJECTED_ISR_USED) || ... */
        }
    }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    else
    {
        /* Disable normal external trigger input */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
        Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_ALL_NORMAL_EXT_TRIG);
#else
        Adc_Sar_Ip_SetExternalTrigger(PhysicalHwUnitId, ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, ADC_SAR_IP_NORMAL_EXT_TRIG);
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_2_NORMAL_ISR_USED))
        Adc_Sar_Ip_DisableNotifications(PhysicalHwUnitId, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN);
#endif /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */
    }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

    Adc_axUnitStatus[Unit].OngoingHwGroup = ADC_INVALID_HW_GROUP_ID;
}
#endif /* ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF */

/**
* @brief          This function handles the conversion by hardware trigger ending.
* @details        When a hardware conversion ends, and the end of conversion
*                 ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit                The current HW Unit.
* @param[in]      InjectedFlag        Normal or Injected conversion.
* @param[in]      CoreId              Current CoreID
*
* @return         void
*
* @api
* @implements     Adc_Ipw_EndHardwareConv_Activity
*/
static inline void Adc_Ipw_EndHardwareConv(Adc_HwUnitType Unit,
                                           boolean InjectedFlag,
                                           uint32 CoreId)
{
    Adc_GroupType GroupIndex;
    Adc_GroupType Group;
    /* Streaming num samples should be at least 1U */
    Adc_StreamNumSampleType GroupSamples;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    boolean  CallNotification = FALSE;
#endif /* ADC_GRP_NOTIF_CAPABILITY */
    Std_ReturnType  ReturnStatus = (Std_ReturnType) E_OK;
#if (ADC_SETCHANNEL_API == STD_ON)
    Std_ReturnType  TempStatus = (Std_ReturnType) E_OK;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    const Adc_GroupConfigurationType * GroupPtr = NULL_PTR;
#if (defined(ADC_DMA_SUPPORTED) || (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF))
    const Adc_Ipw_Config * const AdcIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
#endif /* defined(ADC_DMA_SUPPORTED) || (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    Dma_Ip_LogicChannelScatterGatherListType LocTransferList[1U];
    boolean StreamLinearDone = FALSE;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
    Adc_HwUnitType PhysicalHwUnitId = AdcIpwConfigPtr->AdcPhysicalIdArr[Unit];
    const uint32 AdcDmaLogicChId = AdcIpwConfigPtr->Mapping.AdcDmaChannelLogicId[Unit];
#endif /* defined(ADC_DMA_SUPPORTED) */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    boolean RuntimeChanUpdated = FALSE;
    Adc_StreamNumSampleType CurrentSampleCount = 0U;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

    /* Get the group to be converted. There is only one Hardware Group working at a time. */
    Group = Adc_axUnitStatus[Unit].OngoingHwGroup;
    GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];
    GroupPtr = &(Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex]);

#if (ADC_SETCHANNEL_API == STD_ON)
    if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
    {
        /* Configure the new list of channels even recording results were incorrect.*/
        (void)Adc_Ipw_ConfigureRuntimeHardwareGroup(Unit, InjectedFlag, CoreId);
    }
    else
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    {
        if (((ADC_CONV_TYPE_INJECTED == GroupPtr->Type) && (FALSE == InjectedFlag)) || \
            ((ADC_CONV_TYPE_NORMAL == GroupPtr->Type) && ((boolean)TRUE == InjectedFlag)) \
           )
        {
            /* Return when group conversion type doesn't match the ISR handler type (normal/injected) */
            ReturnStatus = (Std_ReturnType) E_NOT_OK;
        }

        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
            GroupSamples = GroupPtr->NumSamples;

#ifdef ADC_DMA_SUPPORTED
            if (ADC_DMA != AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
            {
#endif /*ADC_DMA_SUPPORTED*/
                /* Get the conversion result and save to buffer */
                ReturnStatus = Adc_Ipw_RecordResult(Unit, Group, GroupSamples, CoreId);
#ifdef ADC_DMA_SUPPORTED
                Adc_Sar_Ip_DisableDma(PhysicalHwUnitId);
                Adc_Sar_Ip_DisableChannelDma(PhysicalHwUnitId, GroupPtr->LastCh);
            }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            else
            {
                ReturnStatus = Adc_Ipw_CheckGroupConvResultDma(GroupPtr, AdcDmaLogicChId, CoreId);
            }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /*ADC_DMA_SUPPORTED*/
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /* Call extra notification (if available) before updating registers (SWS_Adc_00060) */
            Adc_Ipw_CallExtraNotification(Group, CoreId);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
            if (TRUE == Adc_axRuntimeGroupChannel[Group].RuntimeUpdated)
            {
                /* Configure the new list of channels even recording results were incorrect.*/
                TempStatus = Adc_Ipw_ConfigureRuntimeHardwareGroup(Unit, InjectedFlag, CoreId);
                if ((Std_ReturnType)E_NOT_OK == TempStatus)
                {
                    ReturnStatus = (Std_ReturnType)E_NOT_OK;
                }
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                else
                {
                    RuntimeChanUpdated = TRUE;
                }
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
            }
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

            if ((Std_ReturnType)E_OK == ReturnStatus)
            {
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                CurrentSampleCount = Adc_Ipw_GetNumsCurrentSample(AdcIpwConfigPtr, GroupPtr, RuntimeChanUpdated);
                /* At least once the group was converted */
                Adc_axGroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
                if (ADC_BUSY == Adc_axGroupStatus[Group].Conversion)
                {
                    /* SWS_Adc_00224 */
                    Adc_axGroupStatus[Group].Conversion = ADC_COMPLETED;
                }

                /* If all samples completed, wrap to 0 */
                if (GroupSamples <= CurrentSampleCount)
                {
                    /* SWS_Adc_00325 */
                    Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
                    if ((ADC_STREAM_BUFFER_LINEAR == GroupPtr->BufferMode) && (ADC_ACCESS_MODE_STREAMING == GroupPtr->AccessMode))
                    {
#ifdef ADC_DMA_SUPPORTED
                        StreamLinearDone = TRUE;
#endif /* ADC_DMA_SUPPORTED */
                        /* Disable trigger source and notification from trigger unit */
                        Adc_Ipw_DisableHwTriggerSrc(Unit, InjectedFlag, GroupPtr->HwTriggerSource, CoreId);
                    }
                    else
                    {
                        Adc_axGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_DMA_SUPPORTED
                        if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                        {
                            if (((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable) && (1U == GroupPtr->AssignedChannelCount))
                            {
                                LocTransferList[0].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                                LocTransferList[0].Value = (uint32)(&(Adc_axGroupStatus[Group].ResultsBufferPtr[Adc_axGroupStatus[Group].ResultIndex]));
                                (void)Dma_Ip_SetLogicChannelTransferList(AdcDmaLogicChId, LocTransferList, 1U);
                            }
                        }
#endif /* ADC_DMA_SUPPORTED */
                    }
                }
#else
                /* SWS_Adc_00325 */
                Adc_axGroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
                CallNotification = Adc_Ipw_CheckNotification(Group, CoreId);
                if (TRUE == CallNotification)
                {
                    /* SWS_Adc_00140, SWS_Adc_00060 */
                    GroupPtr->Notification();
                }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                if (FALSE == StreamLinearDone)
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
                {
                    if (ADC_DMA == AdcIpwConfigPtr->Mapping.AdcDmaInterruptSoftware[Unit])
                    {
                        if ((uint8)STD_OFF == GroupPtr->AdcExtDMAChanEnable)
                        {
                            /* Update the Next Destination Address for Streaming Group and Hardware Group */
                            Adc_Ipw_UpdateTcdDestAddr(GroupPtr, AdcDmaLogicChId);
                            Adc_Ipw_EnableDmaHwRequest(Unit, GroupPtr, AdcIpwConfigPtr);
                        }
                    }
                }
#endif /* ADC_DMA_SUPPORTED */
            }
        }
    }
}
#endif /* (((defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || ... */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_0_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_1_NORMAL_ISR_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_2_NORMAL_ISR_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
/**
* @brief          This function handles the Normal conversion ending.
* @details        When a normal conversion finishes, in callback of ISR, this function
*                 is called to update status, get the result of conversion.
*
* @param[in]      PhysicalAdcUnit   ADC Hardware Unit Physical
*
* @return         void
*
* @implements Adc_Ipw_EndNormalChainNotification_Activity
*/
static inline void Adc_Ipw_EndNormalChainNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    volatile uint32 CoreId;
    Adc_HwUnitType LogicalAdcUnit;
    Adc_QueueIndexType SwNormalQueueIndex;

    /* Check that ADC unit is assigned to current core partition */
    CoreId = Adc_GetCoreID();

    LogicalAdcUnit = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        SwNormalQueueIndex = Adc_axUnitStatus[LogicalAdcUnit].SwNormalQueueIndex;
        /*Software Normal queue is not empty and End of Normal chain conversion occurred (PR-MCAL-3272.adc) */
        if (SwNormalQueueIndex > (Adc_QueueIndexType)0)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndSoftwareConv(LogicalAdcUnit, FALSE, CoreId);
        }

#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        /* Hardware Normal queue is not empty and End of Normal chain conversion occurred (PR-MCAL-3272.adc) */
        if (ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndHardwareConv(LogicalAdcUnit, FALSE, CoreId);
        }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    }
}
#endif /* defined(ADC_UNIT_0_NORMAL_ISR_USED) || ... */

#if (defined(ADC_UNIT_0_INJECTED_ISR_USED) || defined(ADC_UNIT_0_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_1_INJECTED_ISR_USED) || defined(ADC_UNIT_1_DMA_TRANSFER_USED) || \
     defined(ADC_UNIT_2_INJECTED_ISR_USED) || defined(ADC_UNIT_2_DMA_TRANSFER_USED) \
    )
/**
* @brief          This function handles the Injected conversion ending.
* @details        When a injected conversion finishes, in callback of ISR, this function
*                 is called to update status, get the result of conversion.
*
* @param[in]      PhysicalAdcUnit   ADC Hardware Unit Physical
*
* @return         void
*
* @implements Adc_Ipw_EndInjectedChainNotification_Activity
*/
static inline void Adc_Ipw_EndInjectedChainNotification(const Adc_HwUnitType PhysicalAdcUnit)
{
    volatile uint32 CoreId;
    Adc_HwUnitType LogicalAdcUnit;
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
    Adc_QueueIndexType SwInjectedQueueIndex;
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

    /* Check that ADC unit is assigned to current core partition */
    CoreId = Adc_GetCoreID();

    LogicalAdcUnit = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        SwInjectedQueueIndex = Adc_axUnitStatus[LogicalAdcUnit].SwInjectedQueueIndex;
        /* Software Injected queue is not empty and End of Injected chain conversion occurred (PR-MCAL-3272.adc) */
        if (SwInjectedQueueIndex > (Adc_QueueIndexType)0)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndSoftwareConv(LogicalAdcUnit, TRUE, CoreId);
        }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
        /* Hardware Injected queue is not empty and End of Injected chain conversion occurred (PR-MCAL-3272.adc) */
        if (ADC_INVALID_HW_GROUP_ID != Adc_axUnitStatus[LogicalAdcUnit].OngoingHwGroup)
        {
            /* Handle the end of conversion */
            Adc_Ipw_EndHardwareConv(LogicalAdcUnit, TRUE, CoreId);
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    }
}
#endif /* (defined(ADC_UNIT_0_INJECTED_ISR_USED) || ... */


/**
* @brief          This function read conversion results
* @details        This function read conversion results
*
* @param[in]      GroupPtr      Group Pointer
* @param[in]      Result       Pointer to conversion results
* @param[in]      GroupSamples  Number of samples
* @param[in]      Index         Current index of result
* @param[in]      ConvResult    Conversion result
*
* @return         void
*/
static inline void Adc_Ipw_ReadData(const Adc_GroupConfigurationType * GroupPtr,
                                    Adc_ValueGroupType * Result,
                                    const Adc_StreamNumSampleType GroupSamples,
                                    const Adc_ChannelIndexType Index,
                                    const uint16 ConvResult)
{
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    if (FALSE == GroupPtr->StreamResultGroupMultiSets)
    {
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
        Result[(Index * GroupSamples)] = ConvResult;
        (void)GroupPtr;
#if (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON)
    }
    else
    {
        Result[Index] = ConvResult;
    }
#endif /* (ADC_ENABLE_GROUP_STREAMING_RESULTS_REORDER == STD_ON) */
}

#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
/**
* @brief          This function calls extra notification
* @details        This function calls extra notification
*
* @param[in]      Group         The channel group to be converted
* @param[in]      CoreId        Current CoreID
*
* @return         void
* CPR-MCAL-797.adc, SWS_Adc_00140
*/
static inline void Adc_Ipw_CallExtraNotification(Adc_GroupType Group,
                                                 uint32 CoreId)
{
    Adc_GroupType GroupIndex = Adc_apxCfgPtr[CoreId]->GroupIdToIndexMapPtr[Group];

    /* Call notification if available */
    if (Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].ExtraNotification != NULL_PTR)
    {
        Adc_apxCfgPtr[CoreId]->GroupsPtr[GroupIndex].ExtraNotification();
    }
}
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif  /* (defined(ADC_UNIT_0_NORMAL_ISR_USED) || defined(ADC_UNIT_1_NORMAL_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) || (defined(ADC_UNIT_1_WDG_ISR_USED)) || \
     (defined(ADC_UNIT_2_WDG_ISR_USED)) || (defined(ADC_UNIT_3_WDG_ISR_USED)) \
    )
#ifdef ADC_WDG_SUPPORTED
/**
* @brief          This function handles the watchdog threshold ending.
* @details        When a conversion result is out of threshold range, in callback of ISR, this function
*                 is called to call watchdog threshold notification.
*
* @param[in]      PhysicalAdcUnit   ADC Physical Hardware Unit
* @param[in]      PhysicalChanId    ADC Physical Channel ID
*
* @return         void
*
* @implements Adc_Ipw_WdgThresholdNotification_Activity
*/
static inline void Adc_Ipw_WdgThresholdNotification(const Adc_HwUnitType PhysicalAdcUnit,
                                                    const Adc_ChannelType PhysicalChanId,
                                                    const uint8 Flags)
{
    volatile uint32 CoreId;
    Adc_HwUnitType LogicalAdcUnit;
    Adc_ChannelType LogicalChanId;
    Adc_Ipw_Config const * AdcIpwConfigPtr;

    /* Check that ADC unit is assigned to current core partition */
    CoreId = Adc_GetCoreID();

    AdcIpwConfigPtr = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr;
    LogicalAdcUnit = AdcIpwConfigPtr->Mapping.HwLogicalId[PhysicalAdcUnit];

    if (LogicalAdcUnit == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        /* Call notification callback */
        LogicalChanId = AdcIpwConfigPtr->Mapping.ChannelLogicalId[LogicalAdcUnit][PhysicalChanId];

        AdcIpwConfigPtr->AdcIpwChannelConfig[LogicalAdcUnit][LogicalChanId].WdgNotification(Flags);
    }
}
#endif /* ADC_WDG_SUPPORTED */
#endif /* defined(ADC_UNIT_0_WDG_ISR_USED) || ... */

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                          ADC HW UNIT 0
==================================================================================================*/
#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_0_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_0_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_0_NORMAL_ISR_USED */

#ifdef ADC_UNIT_0_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_0_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc0DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 0U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
#if ((defined(ADC_UNIT_1_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_1_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_1_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_1_NORMAL_ISR_USED */

#ifdef ADC_UNIT_1_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 1.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 1.
*
* @return         void
*
*/
void Adc_Ipw_Adc1EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_1_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc1DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 1U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          ADC HW UNIT 2
==================================================================================================*/
#if ((defined(ADC_UNIT_2_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED)))
/**
* @brief          This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the Wdg threshold notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2WdgThresholdNotification(const uint16 PhysicalChanId,
                                          const uint8 Flags)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_WdgThresholdNotification(PhysicalAdcUnit, (Adc_ChannelType)PhysicalChanId, Flags);
}
#endif /* ((defined(ADC_UNIT_2_WDG_ISR_USED)) && (defined(ADC_WDG_SUPPORTED))) */

#ifdef ADC_UNIT_2_NORMAL_ISR_USED
/**
* @brief          This function implements the end of normal chain notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2EndNormalChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_2_NORMAL_ISR_USED */

#ifdef ADC_UNIT_2_INJECTED_ISR_USED
/**
* @brief          This function implements the end of injected chain notification for
*                 ADC Hardware Unit 2.
* @details        This function implements the end of injected chain notification for
*                 ADC Hardware Unit 2.
*
* @return         void
*
*/
void Adc_Ipw_Adc2EndInjectedChainNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;

    Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
}
#endif /* ADC_UNIT_2_INJECTED_ISR_USED */

#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_2_DMA_TRANSFER_USED))
/**
* @brief          This function implements the end of dma transfer notification for
*                 ADC Hardware Unit 0.
* @details        This function implements the end of normal chain notification for
*                 ADC Hardware Unit 0.
*
* @return         void
*
*/
void Adc_Ipw_Adc2DmaTransferCompleteNotification(void)
{
    const Adc_HwUnitType PhysicalAdcUnit = 2U;
    uint32 AdcStatusFlag;

    AdcStatusFlag = Adc_Sar_Ip_GetStatusFlags(PhysicalAdcUnit);

    if ((AdcStatusFlag & ADC_SAR_IP_STATUS_FLAG_NORMAL_ENDCHAIN) != 0U)
    {
        Adc_Ipw_EndNormalChainNotification(PhysicalAdcUnit);
    }
    else if ((AdcStatusFlag & (ADC_SAR_IP_STATUS_FLAG_INJECTED_ENDCHAIN | ADC_SAR_IP_STATUS_FLAG_CTU_EOC)) != 0U)
    {
        Adc_Ipw_EndInjectedChainNotification(PhysicalAdcUnit);
    }
    else
    {
        ; /* Empty else branch to avoid MISRA */
    }
}
#endif /* (defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_2_DMA_TRANSFER_USED)) */

/*==================================================================================================
                                          BCTU UNIT 0
==================================================================================================*/
#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_IPW_BCTU_AVAILABLE == STD_ON)
#ifdef ADC_UNIT_0_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC0
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc0(void)
{
    const volatile uint32 CoreId = Adc_GetCoreID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[0U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, CoreId);
    }
}
#endif /* ADC_UNIT_0_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_1_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC1
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc1(void)
{
    const volatile uint32 CoreId = Adc_GetCoreID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[1U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, CoreId);
    }
}
#endif /* ADC_UNIT_1_BCTU_LIST_ISR_USED */

#ifdef ADC_UNIT_2_BCTU_LIST_ISR_USED

/**
* @brief          This function handles internal ADC updates after the BCTU list is complete, in Triggered Mode
* @details        The function is a notification to be called by BCTU IPL, corresponding to execution of the last conversion in a LIST of conversions for ADC2
*
* @return         void
*/
void Adc_Ipw_BctuEndListNotificationAdc2(void)
{
    const volatile uint32 CoreId = Adc_GetCoreID();
    const Adc_HwUnitType LogicalHwUnitId = Adc_apxCfgPtr[CoreId]->AdcIpwConfigPtr->Mapping.HwLogicalId[2U];

    if (LogicalHwUnitId == ADC_IPW_INVALID_LOGICAL_UNIT_ID)
    {
        /* The interrupt is spurious or ADC unit assigned to invalid core partition.
        No DEM or DET error reporting inside ISR functions.
        Rationale: The DEM or DET callback is long in its full implementation, delaying the ISR. */
    }
    else
    {
        Adc_Ipw_EndHardwareConv(LogicalHwUnitId, TRUE, CoreId);
    }
}
#endif /* ADC_UNIT_2_BCTU_LIST_ISR_USED */

#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_IPW_BCTU_AVAILABLE == STD_ON) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
