/*
    FreeRTOS V8.2.0 - Copyright (C) 2015 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

	***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
	***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
	the FAQ page "My application does not run, what could be wrong?".  Have you
	defined configASSERT()?

	http://www.FreeRTOS.org/support - In return for receiving this top quality
	embedded software for free we request you assist our global community by
	participating in the support forum.

	http://www.FreeRTOS.org/training - Investing in training allows your team to
	be as productive as possible as early as possible.  Now you can receive
	FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
	Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

#ifndef MPU_WRAPPERS_H
#define MPU_WRAPPERS_H

/* This file redefines API functions to be called through a wrapper macro, but
only for ports that are using the MPU. */
#if portUSING_MPU_WRAPPERS

	/* MPU_WRAPPERS_INCLUDED_FROM_API_FILE will be defined when this file is
	included from queue.c or task.c to prevent it from having an effect within
	those files. */
	#ifndef MPU_WRAPPERS_INCLUDED_FROM_API_FILE

		#define xTaskGenericCreate				MPU_xTaskGenericCreate
		#define esp_vTaskAllocateMPURegions			MPU_vTaskAllocateMPURegions
		#define esp_vTaskDelete						MPU_vTaskDelete
		#define esp_vTaskDelayUntil					MPU_vTaskDelayUntil
		#define esp_vTaskDelay						MPU_vTaskDelay
		#define esp_uxTaskPriorityGet				MPU_uxTaskPriorityGet
		#define esp_vTaskPrioritySet				MPU_vTaskPrioritySet
		#define esp_eTaskGetState					MPU_eTaskGetState
		#define esp_vTaskSuspend					MPU_vTaskSuspend
		#define esp_vTaskResume						MPU_vTaskResume
		#define esp_vTaskSuspendAll					MPU_vTaskSuspendAll
		#define esp_xTaskResumeAll					MPU_xTaskResumeAll
		#define esp_xTaskGetTickCount				MPU_xTaskGetTickCount
		#define esp_uxTaskGetNumberOfTasks			MPU_uxTaskGetNumberOfTasks
		#define vTaskList						MPU_vTaskList
		#define vTaskGetRunTimeStats			MPU_vTaskGetRunTimeStats
		#define vTaskSetApplicationTaskTag		MPU_vTaskSetApplicationTaskTag
		#define xTaskGetApplicationTaskTag		MPU_xTaskGetApplicationTaskTag
		#define xTaskCallApplicationTaskHook	MPU_xTaskCallApplicationTaskHook
		#define esp_uxTaskGetStackHighWaterMark		MPU_uxTaskGetStackHighWaterMark
		#define esp_xTaskGetCurrentTaskHandle		MPU_xTaskGetCurrentTaskHandle
		#define esp_xTaskGetSchedulerState			MPU_xTaskGetSchedulerState
		#define xTaskGetIdleTaskHandle			MPU_xTaskGetIdleTaskHandle
		#define uxTaskGetSystemState			MPU_uxTaskGetSystemState

		#define esp_xQueueGenericCreate				MPU_xQueueGenericCreate
		#define esp_xQueueCreateMutex				MPU_xQueueCreateMutex
		#define esp_xQueueGiveMutexRecursive		MPU_xQueueGiveMutexRecursive
		#define esp_xQueueTakeMutexRecursive		MPU_xQueueTakeMutexRecursive
		#define esp_xQueueCreateCountingSemaphore	MPU_xQueueCreateCountingSemaphore
		#define esp_xQueueGenericSend				MPU_xQueueGenericSend
		#define xQueueAltGenericSend			MPU_xQueueAltGenericSend
		#define xQueueAltGenericReceive			MPU_xQueueAltGenericReceive
		#define esp_xQueueGenericReceive			MPU_xQueueGenericReceive
		#define esp_uxQueueMessagesWaiting			MPU_uxQueueMessagesWaiting
		#define esp_vQueueDelete					MPU_vQueueDelete
		#define esp_xQueueGenericReset				MPU_xQueueGenericReset
		#define esp_xQueueCreateSet					MPU_xQueueCreateSet
		#define esp_xQueueSelectFromSet				MPU_xQueueSelectFromSet
		#define esp_xQueueAddToSet					MPU_xQueueAddToSet
		#define esp_xQueueRemoveFromSet				MPU_xQueueRemoveFromSet
		#define esp_xQueuePeekFromISR				MPU_xQueuePeekFromISR
		#define esp_xQueueGetMutexHolder			MPU_xQueueGetMutexHolder

		#define esp_pvPortMalloc					MPU_pvPortMalloc
		#define esp_vPortFree						MPU_vPortFree
		#define esp_xPortGetFreeHeapSize			MPU_xPortGetFreeHeapSize
		#define vPortInitialiseBlocks			MPU_vPortInitialiseBlocks

		#if configQUEUE_REGISTRY_SIZE > 0
			#define vQueueAddToRegistry				MPU_vQueueAddToRegistry
			#define vQueueUnregisterQueue			MPU_vQueueUnregisterQueue
		#endif

		/* Remove the privileged function macro. */
		#define PRIVILEGED_FUNCTION

	#else /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE */

		/* Ensure API functions go in the privileged execution section. */
		#define PRIVILEGED_FUNCTION __attribute__((section("privileged_functions")))
		#define PRIVILEGED_DATA __attribute__((section("privileged_data")))

	#endif /* MPU_WRAPPERS_INCLUDED_FROM_API_FILE */

#else /* portUSING_MPU_WRAPPERS */

	#define PRIVILEGED_FUNCTION
	#define PRIVILEGED_DATA
	#define portUSING_MPU_WRAPPERS 0

#endif /* portUSING_MPU_WRAPPERS */


#endif /* MPU_WRAPPERS_H */

