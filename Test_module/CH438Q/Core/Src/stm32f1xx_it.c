/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "HAL_CH438UART.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define UART_NUM 8
#define BUF_SIZE 256

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
typedef void (*CH438Send)(uint8_t *data, uint8_t len);
typedef uint8_t (*CH438Recv)(uint8_t *data);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */
extern uint8_t regLCR[];                
extern uint8_t regDLL[];                
extern uint8_t regDLM[];                
extern uint8_t regFCR[];                
extern uint8_t regIER[];                
extern uint8_t regMCR[];                
extern uint8_t regIIR[];                
extern uint8_t regLSR[];                
extern uint8_t regRBR[];
extern uint8_t regTHR[];
extern CH438Send ch438Send[UART_NUM];
extern CH438Recv ch438Recv[UART_NUM];

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */

uint8_t buf[BUF_SIZE];

#define DELAY_0_HIGH HAL_GPIO_WritePin(TEST_DELAY_0_GPIO_Port, TEST_DELAY_0_Pin, GPIO_PIN_SET);
#define DELAY_0_LOW  HAL_GPIO_WritePin(TEST_DELAY_0_GPIO_Port, TEST_DELAY_0_Pin, GPIO_PIN_RESET);
#define DELAY_1_HIGH HAL_GPIO_WritePin(TEST_DELAY_1_GPIO_Port, TEST_DELAY_1_Pin, GPIO_PIN_SET);
#define DELAY_1_LOW  HAL_GPIO_WritePin(TEST_DELAY_1_GPIO_Port, TEST_DELAY_1_Pin, GPIO_PIN_RESET);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    volatile uint8_t status, recvCnt, modemStatus, data;
    if (GPIO_Pin == INT__Pin) {
        // DELAY_0_HIGH
        // printf("Yes, recv!\r\n");
        status = ReadCH438Data(REG_SSR_ADDR);
         for (int i = 0; i < 8; ++i) {
            if (status & (1 << i)) {
                status = ReadCH438Data(regIIR[i]) & 0x3F;
                // printf("status:[%x]\r\n", status);
                if (status & 0x01) {
                    // DELAY_0_LOW
                    return ;
                } else {
                    switch (status) {
                        case INT_NOINT: /* 没有中断 */
                            break;
                        case INT_THR_EMPTY: /* 发送保持寄存器空中断 */
                            // UART0_SendStr( "UART0 THR Empty \n" );
                            break;
                        case INT_RCV_SUCCESS: /* 串口接收可用数据中断 */
                        case INT_RCV_OVERTIME: /* 接收数据超时中断 */
                        case INT_RCV_LINES:    /* 接收线路状态中断 */
                            // printf("err:[%x]\r\n", ReadCH438Data(regLSR[i]));
                            // recvCnt = ch438Recv[i](buf);
                            // ch438Send[i](buf, recvCnt);
                            while (ReadCH438Data(regLSR[i]) & BIT_LSR_DATARDY) {
                                if (!(ReadCH438Data(REG_LSR_ADDR) &
                                      (BIT_LSR_BREAKINT | BIT_LSR_FRAMEERR | BIT_LSR_PARERR | BIT_LSR_OVERR))) {
                                    while (ReadCH438Data(regLSR[i]) & BIT_LSR_DATARDY) {
                                        // DELAY_0_LOW
                                        data = ReadCH438Data(regRBR[i]);
                                        // DELAY_1_HIGH
                                        while ((ReadCH438Data(regLSR[i]) & BIT_LSR_THRE) == 0)
                                            ; /* 等待数据发送完成 */
                                        // DELAY_1_LOW
                                        WriteCH438Data(regTHR[i], data);
                                    }
                                } else {
                                    ReadCH438Data(regRBR[i]);   /* 数据直接丢弃 */
                                }
                            }
                            break;
                        case INT_MODEM_CHANGE:
                            // modemStatus = ReadCH438Data(REG_MSR_ADDR);
                            // UART0_SendStr(" Modem Change \n");
                            // if (modemStatus == 0x30) /* Modem信号发�?�数据变�? */
                            // {
                            //     //                       UART0_SendStr( "DSR CTS is Free \n" );
                            // } else if (modemStatus == 0x11) /* Modem 信号接收数据变化 */
                            // {
                            //     //                      UART0_SendStr( "DSR CTS is Free \n" );
                            // } else if (modemStatus == 0x22) /* Modem 信号接收数据变化 */
                            // {
                            //     s = ReadCH438Data(REG_RBR_ADDR);
                            //     //                       UART0_SendStr( "DSR has changed \n" );
                            // }
                            break;

                        default: /* 不可能发生的中断 */
                            break;
                    }
                }
            }
        }
        // DELAY_0_LOW
    }
	
}



/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
