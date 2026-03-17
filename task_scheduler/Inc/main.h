/*
 * main.h
 *
 *  Created on: Mar 1, 2026
 *      Author: ambeshkumar
 */

#ifndef MAIN_H_
#define MAIN_H_

#define RAM_START             0x20000000U
#define RAM_SIZE              ((192U) * (1024U))
#define RAM_END               ((RAM_START) + (RAM_SIZE))

#define TASK_STACK_SIZE       1024U
#define SCHED_STACK_SIZE      1024U

#define SCHED_STACK_START     ((RAM_END) - (TASK_STACK_SIZE))
#define T1_STACK_START        ((SCHED_STACK_START) - (TASK_STACK_SIZE))
#define T2_STACK_START        ((T1_STACK_START) - (TASK_STACK_SIZE))
#define T3_STACK_START        ((T2_STACK_START) - (TASK_STACK_SIZE))
#define T4_STACK_START        ((T3_STACK_START) - (TASK_STACK_SIZE))
#define TI_STACK_START        ((T4_STACK_START) - (TASK_STACK_SIZE))

#define TASK_STATE_READY      0x00U
#define TASK_STATE_BLOCKED    0xFFU

#define MAX_TASKS             5U

#define DUMMY_XPSR            0x01000000U

#define TICK_HZ               1000U
#define HSI_CLK               16000000U
#define SYSTICK_TIM_CLK       (HSI_CLK)


#define INTERRUPED_DISABLE() do{__asm volatile("MOV R0, #0x01"); __asm volatile("MSR PRIMASK , R0");  }while(0)

#define INTERRUPED_ENABLE() do{__asm volatile("MOV R0, #0x00"); __asm volatile("MSR PRIMASK , R0");  }while(0)



#endif /* MAIN_H_ */
