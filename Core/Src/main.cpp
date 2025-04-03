/*
 * main.cpp
 *
 *  Created on: Apr 2, 2025
 *      Author: wilson
 */

#include "main.h"
#include "aes.h"
#include "cordic.h"
#include "crc.h"
#include "dcache.h"
#include "flash.h"
#include "fmac.h"
#include "gtzc.h"
#include "hash.h"
#include "icache.h"
#include "lptim.h"
#include "usart.h"
#include "memorymap.h"
#include "otfdec.h"
#include "pka.h"
#include "rng.h"
#include "rtc.h"
#include "gpio.h"

#include "stm32u5xx_it.h"
#include <stdint.h>
#include <string.h>

COM_InitTypeDef BspCOMInit;
__IO uint32_t BspButtonState = BUTTON_RELEASED;

void SystemClock_Config(void);
static void SystemPower_Config(void);

void hal_callback_lptim2_update_event(LPTIM_HandleTypeDef *hlptim);
void hal_callback_lpuart_tx_complete(UART_HandleTypeDef *huart);

int main()
{
  HAL_Init();
  SystemPower_Config();
  SystemClock_Config();
  MX_GTZC_Init();
  MX_GPIO_Init();
  MX_DCACHE1_Init();
  MX_FLASH_Init();
  MX_ICACHE_Init();
  MX_AES_Init();
  MX_SAES_AES_Init();
  MX_CORDIC_Init();
  MX_CRC_Init();
  MX_FMAC_Init();
  MX_HASH_Init();
  MX_LPTIM2_Init();
  MX_LPTIM3_Init();
  MX_LPUART1_UART_Init();
  MX_USART2_UART_Init();
  MX_RNG_Init();
  MX_PKA_Init();
  MX_RTC_Init();
  MX_OTFDEC1_Init();
  MX_OTFDEC2_Init();

  HAL_UART_RegisterCallback(&hlpuart1, HAL_UART_TX_COMPLETE_CB_ID, hal_callback_lpuart_tx_complete);
  HAL_LPTIM_RegisterCallback(&hlptim2, HAL_LPTIM_UPDATE_EVENT_CB_ID, hal_callback_lptim2_update_event);
  HAL_LPTIM_Counter_Start_IT(&hlptim2);

  HAL_GPIO_WritePin(MUX8_0_EN_GPIO_Port, MUX8_0_EN_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(MUX16_0_EN_GPIO_Port, MUX16_0_EN_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(MUX16_0_A0_GPIO_Port, MUX16_0_A0_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(MUX16_0_A1_GPIO_Port, MUX16_0_A1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(MUX16_0_A2_GPIO_Port, MUX16_0_A2_Pin, GPIO_PIN_SET);

  while (1)
  {

  }
}

void SystemClock_Config()
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE3) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI
                              |RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI
                              |RCC_OSCILLATORTYPE_MSIK|RCC_OSCILLATORTYPE_SHSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.LSIDiv = RCC_LSI_DIV1;
  RCC_OscInitStruct.MSIKClockRange = RCC_MSIKRANGE_4;
  RCC_OscInitStruct.SHSIState = RCC_SHSI_ON;
  RCC_OscInitStruct.MSIKState = RCC_MSIK_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  __HAL_RCC_MSIKSTOP_ENABLE();
  __HAL_RCC_HSISTOP_ENABLE();
}

static void SystemPower_Config()
{
  HAL_PWREx_EnableVddIO2();
  HAL_PWREx_DisableUCPDDeadBattery();

  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_NVIC_SetPriority(PWR_S3WU_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(PWR_S3WU_IRQn);
}

void hal_callback_lptim2_update_event(LPTIM_HandleTypeDef *hlptim)
{

}

void hal_callback_lpuart_tx_complete(UART_HandleTypeDef *huart)
{

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
}

void Error_Handler()
{
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
