///* USER CODE BEGIN Header */
///**
//  ******************************************************************************
//  * @file           : main.c
//  * @brief          : Main program body
//  ******************************************************************************
//  * @attention
//  *
//  * Copyright (c) 2025 STMicroelectronics.
//  * All rights reserved.
//  *
//  * This software is licensed under terms that can be found in the LICENSE file
//  * in the root directory of this software component.
//  * If no LICENSE file comes with this software, it is provided AS-IS.
//  *
//  ******************************************************************************
//  */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include "aes.h"
//#include "cordic.h"
//#include "crc.h"
//#include "dcache.h"
//#include "flash.h"
//#include "fmac.h"
//#include "gtzc.h"
//#include "hash.h"
//#include "icache.h"
//#include "lptim.h"
//#include "usart.h"
//#include "memorymap.h"
//#include "otfdec.h"
//#include "pka.h"
//#include "rng.h"
//#include "rtc.h"
//#include "gpio.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//#include "stm32u5xx_it.h"
//#include <stdint.h>
//#include <string.h>
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
//
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
//
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//
//COM_InitTypeDef BspCOMInit;
//__IO uint32_t BspButtonState = BUTTON_RELEASED;
//
///* USER CODE BEGIN PV */
//
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void SystemPower_Config(void);
///* USER CODE BEGIN PFP */
//void hal_callback_lptim2_update_event(LPTIM_HandleTypeDef *hlptim);
//void hal_callback_lpuart_tx_complete(UART_HandleTypeDef *huart);
//
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
//
///* USER CODE END 0 */
//
///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//int main(void)
//{
//
//  /* USER CODE BEGIN 1 */
//#if (USE_TIMER == 1U)
//	static uint32_t tick_count_ms;
//#endif
//
//  /* USER CODE END 1 */
//
//  /* MCU Configuration--------------------------------------------------------*/
//
//  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//  HAL_Init();
//
//  /* USER CODE BEGIN Init */
//
//  /* USER CODE END Init */
//
//  /* Configure the System Power */
//  SystemPower_Config();
//
//  /* Configure the system clock */
//  SystemClock_Config();
//  /* GTZC initialisation */
//  MX_GTZC_Init();
//
//  /* USER CODE BEGIN SysInit */
//
//  /* USER CODE END SysInit */
//
//  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_DCACHE1_Init();
//  MX_FLASH_Init();
//  MX_ICACHE_Init();
//  MX_AES_Init();
//  MX_SAES_AES_Init();
//  MX_CORDIC_Init();
//  MX_CRC_Init();
//  MX_FMAC_Init();
//  MX_HASH_Init();
//  MX_LPTIM2_Init();
//  MX_LPTIM3_Init();
//  MX_LPUART1_UART_Init();
//  MX_USART2_UART_Init();
//  MX_RNG_Init();
//  MX_PKA_Init();
//  MX_RTC_Init();
//  MX_OTFDEC1_Init();
//  MX_OTFDEC2_Init();
//  /* USER CODE BEGIN 2 */
//
//  /* USER CODE END 2 */
//
//  /* USER CODE BEGIN BSP */
//
//  /* USER CODE END BSP */
//
//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
//
//
//  HAL_UART_RegisterCallback(&hlpuart1, HAL_UART_TX_COMPLETE_CB_ID, hal_callback_lpuart_tx_complete);
//  HAL_LPTIM_RegisterCallback(&hlptim2, HAL_LPTIM_UPDATE_EVENT_CB_ID, hal_callback_lptim2_update_event);
//  HAL_LPTIM_Counter_Start_IT(&hlptim2);
//
//  HAL_GPIO_WritePin(MUX8_0_EN_GPIO_Port, MUX8_0_EN_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(MUX16_0_EN_GPIO_Port, MUX16_0_EN_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(MUX16_0_A0_GPIO_Port, MUX16_0_A0_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(MUX16_0_A1_GPIO_Port, MUX16_0_A1_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(MUX16_0_A2_GPIO_Port, MUX16_0_A2_Pin, GPIO_PIN_SET);
//
//
//  while (1)
//  {
//    /* USER CODE END WHILE */
//
//    /* USER CODE BEGIN 3 */
//  }
//  /* USER CODE END 3 */
//}
//
///**
//  * @brief System Clock Configuration
//  * @retval None
//  */
//void SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//  /** Configure the main internal regulator output voltage
//  */
//  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Initializes the CPU, AHB and APB buses clocks
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI
//                              |RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI
//                              |RCC_OSCILLATORTYPE_MSIK|RCC_OSCILLATORTYPE_SHSI;
//  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
//  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
//  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
//  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
//  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
//  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
//  RCC_OscInitStruct.LSIDiv = RCC_LSI_DIV1;
//  RCC_OscInitStruct.MSIKClockRange = RCC_MSIKRANGE_4;
//  RCC_OscInitStruct.SHSIState = RCC_SHSI_ON;
//  RCC_OscInitStruct.MSIKState = RCC_MSIK_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Initializes the CPU, AHB and APB buses clocks
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
//                              |RCC_CLOCKTYPE_PCLK3;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
//
//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Enable the force of MSIK in stop mode
//  */
//  __HAL_RCC_MSIKSTOP_ENABLE();
//
//  /** Enable the force of HSI in stop mode
//  */
//  __HAL_RCC_HSISTOP_ENABLE();
//}
//
///**
//  * @brief Power Configuration
//  * @retval None
//  */
//static void SystemPower_Config(void)
//{
//  HAL_PWREx_EnableVddIO2();
//
//  /*
//   * Disable the internal Pull-Up in Dead Battery pins of UCPD peripheral
//   */
//  HAL_PWREx_DisableUCPDDeadBattery();
//
//  /*
//   * Switch to SMPS regulator instead of LDO
//   */
//  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* PWR_S3WU_IRQn interrupt configuration */
//  HAL_NVIC_SetPriority(PWR_S3WU_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(PWR_S3WU_IRQn);
///* USER CODE BEGIN PWR */
///* USER CODE END PWR */
//}
//
///* USER CODE BEGIN 4 */
//void hal_callback_lptim2_update_event(LPTIM_HandleTypeDef *hlptim)
//{
//
//}
//
//void hal_callback_lpuart_tx_complete(UART_HandleTypeDef *huart)
//{
//
//}
//
///* USER CODE END 4 */
//
///**
//  * @brief  Period elapsed callback in non blocking mode
//  * @note   This function is called  when TIM4 interrupt took place, inside
//  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
//  * a global variable "uwTick" used as application time base.
//  * @param  htim : TIM handle
//  * @retval None
//  */
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//  /* USER CODE BEGIN Callback 0 */
//
//  /* USER CODE END Callback 0 */
//  if (htim->Instance == TIM4) {
//    HAL_IncTick();
//  }
//  /* USER CODE BEGIN Callback 1 */
//
//  /* USER CODE END Callback 1 */
//}
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//  /* USER CODE BEGIN 6 */
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//  /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
