/*******************************************************************************
 * Trace Recorder Library for Tracealyzer v4.4.1
 * Percepio AB, www.percepio.com
 *
 * trcConfig.h
 *
 * Main configuration parameters for the trace recorder library.
 * More settings can be found in trcStreamingConfig.h and trcSnapshotConfig.h.
 *
 * Read more at http://percepio.com/2016/10/05/rtos-tracing/
 *
 * Terms of Use
 * This file is part of the trace recorder library (RECORDER), which is the
 * intellectual property of Percepio AB (PERCEPIO) and provided under a
 * license as follows.
 * The RECORDER may be used free of charge for the purpose of recording data
 * intended for analysis in PERCEPIO products. It may not be used or modified
 * for other purposes without explicit permission from PERCEPIO.
 * You may distribute the RECORDER in its original source code form, assuming
 * this text (terms of use, disclaimer, copyright notice) is unchanged. You are
 * allowed to distribute the RECORDER with minor modifications intended for
 * configuration or porting of the RECORDER, e.g., to allow using it on a
 * specific processor, processor family or with a specific communication
 * interface. Any such modifications should be documented directly below
 * this comment block.
 *
 * Disclaimer
 * The RECORDER is being delivered to you AS IS and PERCEPIO makes no warranty
 * as to its use or performance. PERCEPIO does not and cannot warrant the
 * performance or results you may obtain by using the RECORDER or documentation.
 * PERCEPIO make no warranties, express or implied, as to noninfringement of
 * third party rights, merchantability, or fitness for any particular purpose.
 * In no event will PERCEPIO, its technology partners, or distributors be liable
 * to you for any consequential, incidental or special damages, including any
 * lost profits or lost savings, even if a representative of PERCEPIO has been
 * advised of the possibility of such damages, or for any claim by any third
 * party. Some jurisdictions do not allow the exclusion or limitation of
 * incidental, consequential or special damages, or the exclusion of implied
 * warranties or limitations on how long an implied warranty may last, so the
 * above limitations may not apply to you.
 *
 * Tabs are used for indent in this file (1 tab = 4 spaces)
 *
 * Copyright Percepio AB, 2018.
 * www.percepio.com
 ******************************************************************************/

#ifndef TRC_CONFIG_H
#define TRC_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "trcPortDefines.h"
/******************************************************************************
 * Include of processor header file
 *****************************************************************************/
#include "stm32f0xx.h"

/******************************************************************************
 * Include of processor header file
 *
 * Here you may need to include the header file for your processor. This is
 * required at least for the ARM Cortex-M port, that uses the ARM CMSIS API.
 * Try that in case of build problems. Otherwise, remove the #error line below.
 *****************************************************************************/

/*******************************************************************************
 * Configuration Macro: TRC_CFG_HARDWARE_PORT
 *
 * Specify what hardware port to use (i.e., the "timestamping driver").
 *
 * All ARM Cortex-M MCUs are supported by "TRC_HARDWARE_PORT_ARM_Cortex_M".
 * This port uses the DWT cycle counter for Cortex-M3/M4/M7 devices, which is
 * available on most such devices. In case your device don't have DWT support,
 * you will get an error message opening the trace. In that case, you may
 * force the recorder to use SysTick timestamping instead, using this define:
 *
 * #define TRC_CFG_ARM_CM_USE_SYSTICK
 *
 * For ARM Cortex-M0/M0+ devices, SysTick mode is used automatically.
 *
 * See trcHardwarePort.h for available ports and information on how to
 * define your own port, if not already present.
 ******************************************************************************/
#define TRC_CFG_HARDWARE_PORT TRC_HARDWARE_PORT_ARM_Cortex_M

/*******************************************************************************
 * Configuration Macro: TRC_CFG_RECORDER_MODE
 *
 * Specify what recording mode to use. Snapshot means that the data is saved in
 * an internal RAM buffer, for later upload. Streaming means that the data is
 * transferred continuously to the host PC.
 *
 * For more information, see http://percepio.com/2016/10/05/rtos-tracing/
 * and the Tracealyzer User Manual.
 *
 * Values:
 * TRC_RECORDER_MODE_SNAPSHOT
 * TRC_RECORDER_MODE_STREAMING
 ******************************************************************************/
#define TRC_CFG_RECORDER_MODE TRC_RECORDER_MODE_STREAMING

/******************************************************************************
 * TRC_CFG_FREERTOS_VERSION
 *
 * Specify what version of FreeRTOS that is used (don't change unless using the
 * trace recorder library with an older version of FreeRTOS).
 *
 * TRC_FREERTOS_VERSION_7_3_X				If using FreeRTOS v7.3.X
 * TRC_FREERTOS_VERSION_7_4_X				If using FreeRTOS v7.4.X 
 * TRC_FREERTOS_VERSION_7_5_X				If using FreeRTOS v7.5.X
 * TRC_FREERTOS_VERSION_7_6_X				If using FreeRTOS v7.6.X
 * TRC_FREERTOS_VERSION_8_X_X				If using FreeRTOS v8.X.X
 * TRC_FREERTOS_VERSION_9_0_0				If using FreeRTOS v9.0.0
 * TRC_FREERTOS_VERSION_9_0_1				If using FreeRTOS v9.0.1
 * TRC_FREERTOS_VERSION_9_0_2				If using FreeRTOS v9.0.2
 * TRC_FREERTOS_VERSION_10_0_0				If using FreeRTOS v10.0.0
 * TRC_FREERTOS_VERSION_10_0_1				If using FreeRTOS v10.0.1
 * TRC_FREERTOS_VERSION_10_1_0				If using FreeRTOS v10.1.0
 * TRC_FREERTOS_VERSION_10_1_1				If using FreeRTOS v10.1.1
 * TRC_FREERTOS_VERSION_10_2_0				If using FreeRTOS v10.2.0
 * TRC_FREERTOS_VERSION_10_2_1				If using FreeRTOS v10.2.1
 * TRC_FREERTOS_VERSION_10_3_0				If using FreeRTOS v10.3.0
 * TRC_FREERTOS_VERSION_10_3_1				If using FreeRTOS v10.3.1
 * TRC_FREERTOS_VERSION_10_4_0				If using FreeRTOS v10.4.0
 * TRC_FREERTOS_VERSION_10_4_1				If using FreeRTOS v10.4.1 or later
 *****************************************************************************/
#define TRC_CFG_FREERTOS_VERSION TRC_FREERTOS_VERSION_10_2_1

#define TRC_CFG_SCHEDULING_ONLY                 0
#define TRC_CFG_INCLUDE_MEMMANG_EVENTS          0
#define TRC_CFG_INCLUDE_USER_EVENTS             0    // <- A voir, si vous les utilisez
#define TRC_CFG_INCLUDE_ISR_TRACING             0
#define TRC_CFG_INCLUDE_READY_EVENTS            1
#define TRC_CFG_INCLUDE_OSTICK_EVENTS           0
#define TRC_CFG_INCLUDE_EVENT_GROUP_EVENTS      1    // <- A voir, si vous les utilisez
#define TRC_CFG_INCLUDE_TIMER_EVENTS            0
#define TRC_CFG_INCLUDE_PEND_FUNC_CALL_EVENTS   0
#define TRC_CFG_INCLUDE_STREAM_BUFFER_EVENTS    0

#define TRC_CFG_ENABLE_STACK_MONITOR            0    // <- Vous essaierez �a plus tard...
#define TRC_CFG_STACK_MONITOR_MAX_TASKS         10
#define TRC_CFG_STACK_MONITOR_MAX_REPORTS       0

#define TRC_CFG_CTRL_TASK_PRIORITY              1    // <- Il peut �tre utile de r�gler �a
#define TRC_CFG_CTRL_TASK_DELAY                 10   // <- et �a aussi...
#define TRC_CFG_CTRL_TASK_STACK_SIZE           (configMINIMAL_STACK_SIZE * 2)
#define TRC_CFG_RECORDER_BUFFER_ALLOCATION     TRC_RECORDER_BUFFER_ALLOCATION_STATIC
#define TRC_CFG_MAX_ISR_NESTING                8

/******************************************************************************
 * TRC_CFG_ACKNOWLEDGE_QUEUE_SET_SEND
 *
 * When using FreeRTOS v10.3.0 or v10.3.1, please make sure that the trace
 * point in prvNotifyQueueSetContainer() in queue.c is renamed from
 * traceQUEUE_SEND to traceQUEUE_SET_SEND in order to tell them apart from
 * other traceQUEUE_SEND trace points. Then set this to TRC_ACKNOWLEDGED.
 *****************************************************************************/
#define TRC_CFG_ACKNOWLEDGE_QUEUE_SET_SEND 0 /* TRC_ACKNOWLEDGED */

/* Specific configuration, depending on Streaming/Snapshot mode */
#if (TRC_CFG_RECORDER_MODE == TRC_RECORDER_MODE_SNAPSHOT)
#include "trcSnapshotConfig.h"
#elif (TRC_CFG_RECORDER_MODE == TRC_RECORDER_MODE_STREAMING)
#include "trcStreamingConfig.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* _TRC_CONFIG_H */
