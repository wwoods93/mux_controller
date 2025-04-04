/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    aes.c
  * @brief   This file provides code for the configuration
  *          of the AES instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "aes.h"

/* USER CODE BEGIN 0 */
#include <string.h>
/* USER CODE END 0 */

CRYP_HandleTypeDef hcryp;
__ALIGN_BEGIN static const uint32_t pKeyAES[4] __ALIGN_END = {
                            0x00000000,0x00000000,0x00000000,0x00000000};
__ALIGN_BEGIN static const uint32_t pKeySAES[4] __ALIGN_END = {
                            0x00000000,0x00000000,0x00000000,0x00000000};

/* AES init function */
void MX_AES_Init(void)
{

  /* USER CODE BEGIN AES_Init 0 */

  /* USER CODE END AES_Init 0 */

  /* USER CODE BEGIN AES_Init 1 */
//  hcryp->Init.pKey = (uint32_t*)key;
  /* USER CODE END AES_Init 1 */
  hcryp.Instance = AES;
  hcryp.Init.DataType = CRYP_NO_SWAP;
  hcryp.Init.KeySize = CRYP_KEYSIZE_128B;
  hcryp.Init.pKey = (uint32_t *)pKeyAES;
  hcryp.Init.Algorithm = CRYP_AES_ECB;
  hcryp.Init.DataWidthUnit = CRYP_DATAWIDTHUNIT_WORD;
  hcryp.Init.HeaderWidthUnit = CRYP_HEADERWIDTHUNIT_WORD;
  hcryp.Init.KeyIVConfigSkip = CRYP_KEYIVCONFIG_ALWAYS;
  hcryp.Init.KeyMode = CRYP_KEYMODE_NORMAL;
  if (HAL_CRYP_Init(&hcryp) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN AES_Init 2 */

  /* USER CODE END AES_Init 2 */

}
/* SAES init function */

void MX_SAES_AES_Init(void)
{

  /* USER CODE BEGIN SAES_Init 0 */

  /* USER CODE END SAES_Init 0 */

  /* USER CODE BEGIN SAES_Init 1 */

  /* USER CODE END SAES_Init 1 */
  hcryp.Instance = SAES;
  hcryp.Init.DataType = CRYP_NO_SWAP;
  hcryp.Init.KeySize = CRYP_KEYSIZE_128B;
  hcryp.Init.pKey = (uint32_t *)pKeySAES;
  hcryp.Init.Algorithm = CRYP_AES_ECB;
  hcryp.Init.DataWidthUnit = CRYP_DATAWIDTHUNIT_WORD;
  hcryp.Init.KeyIVConfigSkip = CRYP_KEYIVCONFIG_ALWAYS;
  hcryp.Init.KeyMode = CRYP_KEYMODE_NORMAL;
  hcryp.Init.KeySelect = CRYP_KEYSEL_NORMAL;
  hcryp.Init.KeyProtection = CRYP_KEYPROT_DISABLE;
  if (HAL_CRYP_Init(&hcryp) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SAES_Init 2 */

  /* USER CODE END SAES_Init 2 */

}

void HAL_CRYP_MspInit(CRYP_HandleTypeDef* crypHandle)
{

  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(crypHandle->Instance==AES)
  {
  /* USER CODE BEGIN AES_MspInit 0 */

  /* USER CODE END AES_MspInit 0 */

    /* AES clock enable */
    __HAL_RCC_AES_CLK_ENABLE();

    /* AES interrupt Init */
    HAL_NVIC_SetPriority(AES_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(AES_IRQn);
  /* USER CODE BEGIN AES_MspInit 1 */

  /* USER CODE END AES_MspInit 1 */
  }
  else if(crypHandle->Instance==SAES)
  {
  /* USER CODE BEGIN SAES_MspInit 0 */

  /* USER CODE END SAES_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_SAES;
    PeriphClkInit.SaesClockSelection = RCC_SAESCLKSOURCE_SHSI;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* SAES clock enable */
    __HAL_RCC_SAES_CLK_ENABLE();
  /* USER CODE BEGIN SAES_MspInit 1 */

  /* USER CODE END SAES_MspInit 1 */
  }
}

void HAL_CRYP_MspDeInit(CRYP_HandleTypeDef* crypHandle)
{

  if(crypHandle->Instance==AES)
  {
  /* USER CODE BEGIN AES_MspDeInit 0 */

  /* USER CODE END AES_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_AES_CLK_DISABLE();

    /* AES interrupt Deinit */
    HAL_NVIC_DisableIRQ(AES_IRQn);
  /* USER CODE BEGIN AES_MspDeInit 1 */

  /* USER CODE END AES_MspDeInit 1 */
  }
  else if(crypHandle->Instance==SAES)
  {
  /* USER CODE BEGIN SAES_MspDeInit 0 */

  /* USER CODE END SAES_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SAES_CLK_DISABLE();
  /* USER CODE BEGIN SAES_MspDeInit 1 */

  /* USER CODE END SAES_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void hal_cryp_aes_set_aes_key_word_at_index(uint32_t arg_word, uint8_t arg_index)
{
//	pKeyAES[arg_index] = arg_word;
}

uint32_t hal_cryp_aes_get_word_of_key(uint8_t arg_index)
{
	return pKeyAES[arg_index];
}



void hal_cryp_aes_write_aes_key_to_array(uint8_t* arg_array)
{
//	uint8_t tmp[16];
//	memset(&tmp0, '\0', sizeof(tmp0));
	memset(&arg_array, '\0', sizeof(arg_array));
//	memset(&tmp, '\0', sizeof(tmp));
	memcpy(&arg_array, &pKeyAES, sizeof(pKeyAES));
//	memcpy(&arg_array, &pKeyAES, sizeof(pKeyAES));
//	for (uint8_t i = 0U; i < 16U; ++i)
//	{
//		arg_array[i] = tmp[i];
//	}

}
/* USER CODE END 1 */
