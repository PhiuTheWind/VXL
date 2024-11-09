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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SEGA1_Pin GPIO_PIN_4
#define SEGA1_GPIO_Port GPIOA
#define SEGB1_Pin GPIO_PIN_5
#define SEGB1_GPIO_Port GPIOA
#define SEGC1_Pin GPIO_PIN_6
#define SEGC1_GPIO_Port GPIOA
#define SEGD1_Pin GPIO_PIN_7
#define SEGD1_GPIO_Port GPIOA
#define RED_1_Pin GPIO_PIN_0
#define RED_1_GPIO_Port GPIOB
#define YELLOW_1_Pin GPIO_PIN_1
#define YELLOW_1_GPIO_Port GPIOB
#define GREEN_1_Pin GPIO_PIN_2
#define GREEN_1_GPIO_Port GPIOB
#define SEG_D_Pin GPIO_PIN_10
#define SEG_D_GPIO_Port GPIOB
#define SEG_E_Pin GPIO_PIN_11
#define SEG_E_GPIO_Port GPIOB
#define SEG_F_Pin GPIO_PIN_12
#define SEG_F_GPIO_Port GPIOB
#define SEG_G_Pin GPIO_PIN_13
#define SEG_G_GPIO_Port GPIOB
#define SEGE1_Pin GPIO_PIN_8
#define SEGE1_GPIO_Port GPIOA
#define SEGF1_Pin GPIO_PIN_9
#define SEGF1_GPIO_Port GPIOA
#define SEGG1_Pin GPIO_PIN_10
#define SEGG1_GPIO_Port GPIOA
#define RED_8_Pin GPIO_PIN_11
#define RED_8_GPIO_Port GPIOA
#define RED_9_Pin GPIO_PIN_12
#define RED_9_GPIO_Port GPIOA
#define RED_10_Pin GPIO_PIN_13
#define RED_10_GPIO_Port GPIOA
#define RED_11_Pin GPIO_PIN_14
#define RED_11_GPIO_Port GPIOA
#define RED_12_Pin GPIO_PIN_15
#define RED_12_GPIO_Port GPIOA
#define RED_2_Pin GPIO_PIN_4
#define RED_2_GPIO_Port GPIOB
#define YELLOW_2_Pin GPIO_PIN_5
#define YELLOW_2_GPIO_Port GPIOB
#define GREEN_2_Pin GPIO_PIN_6
#define GREEN_2_GPIO_Port GPIOB
#define SEG_A_Pin GPIO_PIN_7
#define SEG_A_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_8
#define SEG_B_GPIO_Port GPIOB
#define SEG_C_Pin GPIO_PIN_9
#define SEG_C_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
