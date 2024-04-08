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

/**
*   @file
*
*   @addtogroup IntCtrl_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "IntCtrl_Ip.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_VENDOR_ID_C                    43
#define PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C                   2
#define PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C                   0
#define PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C                   0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (PLATFORM_INTCTRL_IP_VENDOR_ID_C != PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "IntCtrl_Ip.c and IntCtrl_Ip.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C != PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C != PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C != PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip.c and IntCtrl_Ip.h are different"
#endif

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
extern uint32 __INT_SRAM_START[1U];
#if defined(INT_CTRL_MCAL_ARM_MARCH_SMU)
#if (INT_CTRL_MCAL_ARM_MARCH_SMU == STD_ON)
static uint16 mscmmap[480] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0, 1, 2, 35, 36, 53, 54, 71, 72, 89, 90, 91, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 180, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 525, 526, 553, 554, 555, 556, 557, 558, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739, 740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775, 776, 778, 779, 781, 782, 783, 784, 785, 786, 787};
#endif /* (INT_CTRL_MCAL_ARM_MARCH_SMU == STD_ON) */
#endif /* INT_CTRL_MCAL_ARM_MARCH_SMU */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                OsIf_Trusted_Call3params(IntCtrl_Ip_InstallHandlerPrivileged,(eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_EnableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_DisableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_SetPriorityPrivileged,(eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPriorityPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearPendingPrivileged,(eIrqNumber))
#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_SetPendingPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPendingPrivileged,(eIrqNumber))
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetActivePrivileged,(eIrqNumber))
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
    #define Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_SetTargetCoresPrivileged,(eIrqNumber),(u8TargetCores))
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged,(eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetDirectedCpuInterruptPrivileged,(eIrqNumber))
#endif
#else /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                IntCtrl_Ip_InstallHandlerPrivileged((eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_EnableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_DisableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                IntCtrl_Ip_SetPriorityPrivileged((eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPriorityPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearPendingPrivileged((eIrqNumber))

#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_SetPendingPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPendingPrivileged((eIrqNumber))
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetActivePrivileged((eIrqNumber))
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
    #define Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores)  \
                IntCtrl_Ip_SetTargetCoresPrivileged((eIrqNumber),(u8TargetCores))
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged((eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)
#endif
#endif /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler);
void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority);
uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber);


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber);
#if (INT_CTRL_IP_CORTEXM == STD_ON)
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber);
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
void IntCtrl_Ip_SetTargetCoresPrivileged(IRQn_Type eIrqNumber, uint8 u8TargetCores);
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget);
void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
#endif

void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    sint32 dev_irqNumber = (sint32)eIrqNumber;
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= dev_irqNumber);
    DevAssert(dev_irqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)    
    DevAssert(S32_SCB->VTOR >= (uint32)__INT_SRAM_START);
#endif /* (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH) */
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    
    OsIf_SuspendAllInterrupts();
    extern uint32 VTABLE[];
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)VTABLE;
        /* Save the former handler pointer */
    if (pfOldHandler != NULL_PTR)
    {
        *pfOldHandler = (IntCtrl_Ip_IrqHandlerType)pVectorRam[((sint32)eIrqNumber)];
    }

    /* Set handler into vector table */
    pVectorRam[((sint32)eIrqNumber)] = pfNewHandler;
    OsIf_ResumeAllInterrupts();
#else
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)S32_SCB->VTOR;

    /* Save the former handler pointer */
    if (pfOldHandler != NULL_PTR)
    {
        *pfOldHandler = (IntCtrl_Ip_IrqHandlerType)pVectorRam[((sint32)eIrqNumber) + 16];
    }

    /* Set handler into vector table */
    pVectorRam[((sint32)eIrqNumber) + 16] = pfNewHandler;
#if (INT_CTRL_IP_INVALIDATE_CACHE == STD_ON)
    /* Invalidate ICache */
    S32_SCB->ICIALLU = 0UL;
#endif
    
#endif /* (INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON) */

    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
}

void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Enable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        IP_GIC500->CPU[cpuId].GICR_SGII.ISENABLER0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif
#else
    S32_NVIC->ISER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Disable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Disable interrupt */
    S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Disable interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        IP_GIC500->CPU[cpuId].GICR_SGII.ICENABLER0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif
#else
    S32_NVIC->ICER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number and priority - dev_irqNumber is used to avoid compiler warning */
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
    DevAssert(u8Priority < (uint8)(1U << INT_CTRL_IP_NVIC_PRIO_BITS));

#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */


#if (INT_CTRL_IP_CORTEXM == STD_ON)
    uint8 shift = (uint8) (8U - INT_CTRL_IP_NVIC_PRIO_BITS);
    /* Set Priority for device specific Interrupts */
    S32_NVIC->IP[(uint32)(eIrqNumber)] = (uint8)((((uint32)u8Priority) << shift) & 0xFFUL);
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    uint8 shift_gic = (uint8) (8U - INT_CTRL_IP_GIC_PRIO_BITS);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
    uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
    /* Clear the old value from the register */
    S32_GICD->GICD_IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
    S32_GICD->GICD_IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
#else
    uint32 cpuId;
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
        IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
    }
    else
    {
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
        /* Clear the old value from the register */
        S32_GICD->GICD_IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
        S32_GICD->GICD_IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
    }
#endif

#else
    uint32 iprVectorId = (uint32)(eIrqNumber) >> 2U;
    uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);

    /* Clear the old value from the register */
    S32_NVIC->IP[iprVectorId] &= ~(0xFFUL << priByteShift);

    S32_NVIC->IP[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift)) & 0xFFUL)) << priByteShift;
#endif
}

uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_IRQ_MIN <= eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);

#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint8 priority;


#if (INT_CTRL_IP_CORTEXM == STD_ON)
    uint8 shift = (uint8)(8U - INT_CTRL_IP_NVIC_PRIO_BITS);
    /* Get Priority for device specific Interrupts  */
    priority = (uint8)(S32_NVIC->IP[(uint32)(eIrqNumber)] >> shift);
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    uint8 shift_gic = (uint8) (8U - INT_CTRL_IP_GIC_PRIO_BITS);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
    uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
    priority = ((uint8)(S32_GICD->GICD_IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
#else
    uint32 cpuId;
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        priority = ((uint8)(IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
    }
    else
    {
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
        priority = ((uint8)(S32_GICD->GICD_IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
    }
#endif
#else
    uint32 iprVectorId = (uint32)(eIrqNumber) >> 2U;
    uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
    priority = ((uint8)(S32_NVIC->IP[iprVectorId] >> priByteShift)) >> shift;
#endif
    return priority;
}

void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Clear Pending Interrupt */
    S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Clear Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        IP_GIC500->CPU[cpuId].GICR_SGII.ICPENDR0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));

    }
    else
    {
        S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif

#else
    /* Clear Pending Interrupt */
    S32_NVIC->ICPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Set Pending Interrupt */
    S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Set Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        IP_GIC500->CPU[cpuId].GICR_SGII.ISPENDR0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif

#else
    /* Set Pending Interrupt */
    S32_NVIC->ISPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}

uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
/* Get Pending Interrupt */
    return ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#else
    uint32 cpuId;
/* Get Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
        return ((IP_GIC500->CPU[cpuId].GICR_SGII.ISPENDR0 & (1U << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL ? TRUE : FALSE);
    }
    else
    {
        return ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL) - 1] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
    }

#endif

#else
    /* Get Pending Interrupt */
    return ((((S32_NVIC->ISPR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#endif
}
#if (INT_CTRL_IP_CORTEXM == STD_ON)
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Get Active Interrupt */
    return ((((S32_NVIC->IABR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
}
#endif
#endif /*#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)*/

#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 * @implements    IntCtrl_Ip_SetTargetCores_Activity
 */
void IntCtrl_Ip_SetTargetCoresPrivileged(IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
#if defined(S32ZSE)   
#if (INT_CTRL_MCAL_ARM_MARCH_SMU == STD_ON) 
    uint16 MscmId = 0;
#endif    
#endif
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
    /* Check interrupt routing is not locked for this IRQ */
#if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)     
    DevAssert((IP_MSCM->IRSPRC[eIrqNumber] & (uint16)(MSCM_IRSPRC_LOCK_MASK)) == (uint16)MSCM_IRSPRC_LOCK(0));
#endif
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    DevAssert(((uint16)u8TargetCores) <= (uint16)INTCTRL_IP_CORE_MASK);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    IP_MSCM->IRSPRC[eIrqNumber - 32] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
#elif (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
    if(eIrqNumber >= INT_CTRL_MSCM_MAP_GICID)
    {
        IP_MSCM->IRSPRC[eIrqNumber - INT_CTRL_MSCM_MAP_GICID] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
    }
#else
     /* CORTEX M*/
    #if defined(S32ZSE)
        #if (INT_CTRL_MCAL_ARM_MARCH_SMU == STD_ON)
        MscmId = mscmmap[eIrqNumber];
        if((uint16)MscmId != (uint16)0xffff)
        {
            IP_MSCM->IRSPRC[MscmId] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
        }
        #endif
    #else
        IP_MSCM->IRSPRC[eIrqNumber] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
    #endif
#endif
}



#endif

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)

void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= eIrqNumber);
    DevAssert((sint32)eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint32 currentCpu;
    uint32 irqId;

    currentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
    irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;
    /* Clear Directed CPU Pending Interrupt */
    MSCM_IRCPnIRx->IRCPnIRx[currentCpu][irqId].IntStatusR = 0x7FU;

}

uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= eIrqNumber);
    DevAssert(eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */


    uint32 currentCpu;
    uint32 irqId;

    currentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
    irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;

    return ((MSCM_IRCPnIRx->IRCPnIRx[currentCpu][irqId].IntStatusR != 0U) ? TRUE : FALSE);
}


void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif

    uint32 irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;
    uint32 core;
    uint32 target;

    if (eCpuTarget == INTCTRL_IP_TARGET_OTHERS)
    {
        for (core = 0U; core < INT_CTRL_IP_MSI_CORE_CNT; core++)
        {
            /* Add Fault Injection point for processor number */
                MCAL_FAULT_INJECTION_POINT(PLATFORM_CPN_ERROR_CPUINTERRUPT);
            /* Generate a Directed CPU Interrupt to every other core */
            if (core != (MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM)))
            {
                MSCM_IRCPnIRx->IRCPnIRx[core][irqId].IGR = 0x1U;
            }
        }
    }
    else
    {
        if (eCpuTarget == INTCTRL_IP_TARGET_SELF)
        {
            target = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
        }
        else
        {
            target = (uint32)eCpuTarget;
        }

        /* Generate Directed CPU Interrupt to target core */
        MSCM_IRCPnIRx->IRCPnIRx[target][irqId].IGR = 0x1U;
    }
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/





/**
 * @internal
 * @brief         Initializes the configured interrupts at interrupt controller level.
 * @implements    IntCtrl_Ip_Init_Activity
 */
IntCtrl_Ip_StatusType IntCtrl_Ip_Init(const IntCtrl_Ip_CtrlConfigType *pIntCtrlCtrlConfig)
{

#if (INT_CTRL_IP_ENABLE_VTOR_CONFIG == STD_ON)
    S32_SCB->VTOR = pIntCtrlCtrlConfig->u32VectorTableAddress;
#endif

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pIntCtrlCtrlConfig != NULL_PTR);
    DevAssert(pIntCtrlCtrlConfig->u32ConfigIrqCount <= INT_CTRL_IP_IRQ_COUNT);
#endif
    uint32 irqIdx;
    for (irqIdx = 0; irqIdx < pIntCtrlCtrlConfig->u32ConfigIrqCount; irqIdx++)
    {
        IntCtrl_Ip_ClearPending(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        IntCtrl_Ip_SetPriority(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber,
                               pIntCtrlCtrlConfig->aIrqConfig[irqIdx].u8IrqPriority);

        if (pIntCtrlCtrlConfig->aIrqConfig[irqIdx].bIrqEnabled)
        {
            IntCtrl_Ip_EnableIrq(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        }
        else
        {
            IntCtrl_Ip_DisableIrq(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        }
    }

    return INTCTRL_IP_STATUS_SUCCESS;
}

#if (INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON)
/**
 * @internal
 * @brief         Initializes the configured routing interrupts.
 * @implements    IntCtrl_Ip_ConfigIrqRouting_Activity
 */
IntCtrl_Ip_StatusType IntCtrl_Ip_ConfigIrqRouting(const IntCtrl_Ip_GlobalRouteConfigType *routeConfig)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(routeConfig != NULL_PTR);
    DevAssert(routeConfig->u32ConfigIrqCount <= INT_CTRL_IP_IRQ_COUNT);
#endif
    uint32 irqIdx;
    for (irqIdx = 0; irqIdx < routeConfig->u32ConfigIrqCount; irqIdx++)
    {
#if (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON)
        /* Configure routing */
        IntCtrl_Ip_SetTargetCores(routeConfig->aIrqConfig[irqIdx].eIrqNumber,
                                  routeConfig->aIrqConfig[irqIdx].u8TargetCores);
#endif
        /* Install the configured handler */
        IntCtrl_Ip_InstallHandler(routeConfig->aIrqConfig[irqIdx].eIrqNumber,
                                  routeConfig->aIrqConfig[irqIdx].pfHandler,
                                  NULL_PTR);
    }
    return INTCTRL_IP_STATUS_SUCCESS;
}
#endif

/**
 * @internal
 * @brief         Installs a handler for an IRQ.
 * @implements    IntCtrl_Ip_InstallHandler_Activity
 */
void IntCtrl_Ip_InstallHandler(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
    Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler);
}

/**
 * @internal
 * @brief         Enables an interrupt request.
 * @implements    IntCtrl_Ip_EnableIrq_Activity
 */
void IntCtrl_Ip_EnableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Disables an interrupt request.
 * @implements    IntCtrl_Ip_DisableIrq_Activity
 */
void IntCtrl_Ip_DisableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Sets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_SetPriority_Activity
 */
void IntCtrl_Ip_SetPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority);
}

/**
 * @internal
 * @brief         Gets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_GetPriority_Activity
 */
uint8 IntCtrl_Ip_GetPriority(IRQn_Type eIrqNumber)
{
    return (uint8)Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Clears the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_ClearPending_Activity
 */
void IntCtrl_Ip_ClearPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber);
}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
/**
 * @internal
 * @brief         Sets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_SetPending_Activity
 */
void IntCtrl_Ip_SetPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Gets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetPending_Activity
 */
boolean IntCtrl_Ip_GetPending(IRQn_Type eIrqNumber)
{
    return (Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}

/**
 * @internal
 * @brief         Gets the active flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetActive_Activity
 */
#if (INT_CTRL_IP_CORTEXM == STD_ON)
boolean IntCtrl_Ip_GetActive(IRQn_Type eIrqNumber)
{
    /*Gets the active flag for an interrupt request */
    return (Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
#endif
#endif /* INT_CTRL_IP_STANDALONE_APIS*/

#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 * @implements    IntCtrl_Ip_SetTargetCores_Activity
 */
void IntCtrl_Ip_SetTargetCores(IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
    /* Sets the target cores for an interrupt request */
    Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores);
}
#endif


#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
/**
 * @internal
 * @brief         Clear directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged_Activity
 */
void IntCtrl_Ip_ClearDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber);
}
/**
 * @internal
 * @brief         Get directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_GetDirectedCpuInterrupt_Activity
 */
boolean IntCtrl_Ip_GetDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    return (Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
/**
 * @internal
 * @brief         Generates an interrupt request to a CPU target.
 * @implements    IntCtrl_Ip_GenerateDirectedCpuInterrupt_Activity
 */
void IntCtrl_Ip_GenerateDirectedCpuInterrupt(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
    Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget);
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */
