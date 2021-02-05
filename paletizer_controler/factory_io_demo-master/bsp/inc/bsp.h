/*
 * bsp.h
 *
 *  Created on: 5 août 2017
 *      Author: Laurent
 */

#ifndef BSP_INC_BSP_H_
#define BSP_INC_BSP_H_

#include "stm32f0xx.h"
#include "main.h"
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5

/*
 * LED driver functions
 */

void	BSP_LED_Init	(void);
void	BSP_LED_On		(void);
void	BSP_LED_Off		(void);
void	BSP_LED_Toggle	(void);


/*
 * Push-Button driver functions
 */

void	BSP_PB_Init		(void);
uint8_t	BSP_PB_GetState	(void);


/*
 * Debug Console driver functions
 */

void	BSP_Console_Init	(void);


/*
 * BSP_NVIC_Init()
 * Setup NVIC controller for desired interrupts
 */

void BSP_NVIC_Init();


#endif /* BSP_INC_BSP_H_ */
