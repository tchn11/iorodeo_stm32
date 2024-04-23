/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "potentiostat.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern "C" void timerCallback();
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DAC_GAIN_A0_Pin GPIO_PIN_9
#define DAC_GAIN_A0_GPIO_Port GPIOC
#define DAC_GAIN_A1_Pin GPIO_PIN_8
#define DAC_GAIN_A1_GPIO_Port GPIOA
#define SW_WRK_ELECT_Pin GPIO_PIN_13
#define SW_WRK_ELECT_GPIO_Port GPIOA
#define SW_CTR_ELECT_Pin GPIO_PIN_4
#define SW_CTR_ELECT_GPIO_Port GPIOB
#define SW_REF_ELECT_Pin GPIO_PIN_5
#define SW_REF_ELECT_GPIO_Port GPIOB
#define TIA_GAIN_A1_Pin GPIO_PIN_6
#define TIA_GAIN_A1_GPIO_Port GPIOB
#define REF_GAIN_A0_Pin GPIO_PIN_7
#define REF_GAIN_A0_GPIO_Port GPIOB
#define REF_GAIN_A1_Pin GPIO_PIN_8
#define REF_GAIN_A1_GPIO_Port GPIOB
#define TIA_GAIN_A0_Pin GPIO_PIN_9
#define TIA_GAIN_A0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
