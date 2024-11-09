/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_D_Pin|SEG_E_Pin|SEG_F_Pin
                          |SEG_G_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG_D_Pin SEG_E_Pin SEG_F_Pin
                           SEG_G_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG_D_Pin|SEG_E_Pin|SEG_F_Pin
                          |SEG_G_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void display_7SEG (int num)
{
	  //Turn off all of the segment first
	  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
	  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);

	  switch(num)
	  {
	  	  case 0:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 1:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 2:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 3:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 4:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 5:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 6:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 7:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 8:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 9:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  default:
	  		  break;
	  }

}
const int MAX_LED = 4;        // Maximum number of 7-segment displays
int index_led = 0;            // Index to track which 7-segment is being updated
int led_buffer[4] = {1, 2, 3, 4};  // Array holding the digits to be displayed on the 4 displays
int DOT_counter = 100;
int led_update_counter = 0;

void update7SEG(int index)
{
	switch (index)
	{
		case 0:
			//Display led 1
			display_7SEG(led_buffer[0]);

            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);


            break;

		case 1:
			//Display led 2
			display_7SEG(led_buffer[1]);

            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);


            break;

		case 2:
			 //Display led 3
			 display_7SEG(led_buffer[2]);

            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);


            break;

		case 3:
			//Display led 4
			display_7SEG(led_buffer[3]);

            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);


            break;

		default:
			break;

	}
}

void updateClockBuffer(int minute, int hour)
{
	if(hour >= 10)
	{
		led_buffer[0] = hour/10;
		led_buffer[1] = hour%10;
	}
	else
	{
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	if (minute >= 10)
	{
		led_buffer[2] = minute/10;
		led_buffer[3] = minute%10;
	}
	else
	{
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
}

/* USER CODE BEGIN 0 */

//Timer 0
int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;


void setTimer0(int duration) {
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}

//Timer 1
int timer1_counter = 0;
int timer1_flag = 0;


void setTimer1(int duration)
{
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

//Timer 2
int timer2_counter = 0;
int timer2_flag = 0;
void setTimer2(int duration)
{
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

int timer3_counter = 0;
int timer3_flag = 0;
void setTimer3(int duration)
{
	timer3_counter = duration / TIMER_CYCLE;
	timer3_flag = 0;
}


void timer_run()
{
    if (timer0_counter > 0) {
        timer0_counter--;  // Decrement the counter
        if (timer0_counter == 0) {
            timer0_flag = 1;  // Set the flag when the counter reaches 0
        }
    }

    if (timer1_counter > 0) {
           timer1_counter--;  // Decrement the counter
           if (timer1_counter == 0) {
               timer1_flag = 1;  // Set the flag when the counter reaches 0
           }
       }

    if (timer2_counter > 0) {
            timer2_counter--;  // Decrement the counter
            if (timer2_counter == 0) {
                timer2_flag = 1;  // Set the flag when the counter reaches 0
            }
        }
    if (timer3_counter > 0) {
               timer3_counter--;  // Decrement the counter
               if (timer3_counter == 0) {
                   timer3_flag = 1;  // Set the flag when the counter reaches 0
               }
           }
}
/* USER CODE END 0 */



const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
//Mảng chứa dữ liệu hiển thị chữ "A"
uint8_t matrix_buffer[8] = {
    0x3C,  // 00111100
    0x42,  // 01000010
    0x81,  // 10000001
    0x81,  // 10000001
    0xFF,  // 01000010
	0x81,  // 01000010
	0x81,  // 01000010
	0x81,  // 01000010
};
//uint8_t matrix_buffer[8] = {
//    0x3C,  // 00111100
//	0x3C,  // 01000010
//	0x3C,  // 10000001
//	0x3C,  // 10000001
//	0x3C,  // 01000010
//	0xFF,  // 01000010
//	0x3C,  // 01000010
//	0x18,  // 01000010
//};
void updateLEDMatrix(int index) {
    // Turn off all ENM pins before updating the current column
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);

    // Activate the current column by setting the corresponding ENM pin to LOW
    switch (index) {
    case 0:
        HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_RESET);
        break;
    case 1:
        HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, GPIO_PIN_RESET);
        break;
    case 2:
        HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, GPIO_PIN_RESET);
        break;
    case 3:
        HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, GPIO_PIN_RESET);
        break;
    case 4:
        HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, GPIO_PIN_RESET);
        break;
    case 5:
        HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, GPIO_PIN_RESET);
        break;
    case 6:
        HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, GPIO_PIN_RESET);
        break;
    case 7:
        HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, GPIO_PIN_RESET);
        break;
    default:
        break;
    }

    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (matrix_buffer[index] & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (matrix_buffer[index] & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (matrix_buffer[index] & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (matrix_buffer[index] & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (matrix_buffer[index] & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (matrix_buffer[index] & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (matrix_buffer[index] & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (matrix_buffer[index] & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}


void shiftLeft(uint8_t matrix_buffer[8])
{
	for (int i = 0; i < 8; i++) {
		// Lấy bit ngoài cùng bên trái (bit thứ 7)
		uint8_t leftBit = (matrix_buffer[i] & 0x80) >> 7;

		// Dịch trái toàn bộ hàng và nối bit ngoài cùng bên trái vào bên phải
		matrix_buffer[i] = (matrix_buffer[i] << 1) | leftBit;
	}
}

//EX4
	void ex4()
	{
	    // Update counters
	    led_update_counter++;
	    DOT_counter--;

	    // Update 7-segment display every 250ms (25 * 10ms)
	    if (led_update_counter >= 25)
	    {
	        // Update 7-segment display with current index
	        update7SEG(index_led);

	        // Increment index and wrap around after MAX_LED
	        index_led++;
	        if (index_led >= MAX_LED) {
	            index_led = 0;
	        }

	        // Reset the 7-segment update counter
	        led_update_counter = 0;
	    }

	    // Toggle DOT LED every 1 second (100 * 10ms)
	    if (DOT_counter <= 0)
	    {
	        HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);  // Toggle the DOT pin
	        DOT_counter = 100;  // Reset the counter for next toggle
	    }
	}

int counter = 50;
int led_state = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//ex4();
	timer_run();
//
//	counter--;
//	    if(counter <= 0) {
//	        if (led_state == 0)
//	                {
//	                    // Enable the first display (EN0), disable the second one (EN1)
//	                    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);  // EN0 on
//	                    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET); // EN1 off
//
//	                    // Display the number '1' on the first seven-segment
//	                    display_7SEG(1);
//
//	                    led_state = 1;  // Switch state for next interrupt
//	                }
//	                else if (led_state == 1)
//	                {
//	                    // Enable the second display (EN1), disable the first one (EN0)
//	                    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET); // EN0 off
//	                    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);   // EN1 on
//
//	                    // Display the number '2' on the second seven-segment
//	                    display_7SEG(2);
//
//	                    led_state = 0;  // Switch back for next interrupt
//	                }
//	        counter = 50;
//	    }

}


int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int hour = 15, minute = 8, second = 50;
  setTimer0(1000);  // Set the timer for Dot (1 second)
  setTimer1(3000); 	// Set the timer for Segment leds
  setTimer2(1000);  //Set the timer for updateClockBuffer
  setTimer3(50);	//EX10
  int index = 0;
while (1)
{
      if (timer0_flag == 1)
      {
    	  second++;
    	  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
          setTimer0(1000);  // Set the timer for 1000 ms (1 seconds)
      }

      if (timer1_flag == 1)
      {
    	  switch (index)
    	  	{
    	  		case 0:
    	  			//Display led 1
    	  			display_7SEG(led_buffer[0]);

    	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
    	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
    	              break;

    	  		case 1:
    	  			//Display led 2
    	  			display_7SEG(led_buffer[1]);

    	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
    	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
    	              break;

    	  		case 2:
    	  			 //Display led 3
    	  			 display_7SEG(led_buffer[2]);

    	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
    	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
    	              break;

    	  		case 3:
    	  			//Display led 4
    	  			display_7SEG(led_buffer[3]);

    	              HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
    	              HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
    	              break;

    	  		default:
    	  			break;
    	  		}
    	  	index++;
    	  	if(index >= 4)
    	  	{
    	  		index = 0;
    	  	}
    	  	setTimer1(3000);
      }

      if(timer2_flag == 1)
      {
    	  if(second >= 60)
    	  {
    	      minute++;
    	      second = 0;
    	  }
    	  if(minute >= 60)
    	  {
    		  hour++;
    		  minute = 0;
    	  }
          if (hour >= 24)
          {
        	  hour = 0;
          }
          updateClockBuffer(minute, hour);
          setTimer2(1000);
      }

	  if (timer3_flag == 1)
	 	      {
	 	    	  updateLEDMatrix(index_led_matrix);
	 	    	  index_led_matrix++;
	 			  if (index_led_matrix >= 8)
	 			  {
	 				  shiftLeft(matrix_buffer);
	 				  index_led_matrix = 0;
	 			  }
	 	          setTimer3(50);
	 	      }
}
//  	  //EX4
//	  while (1)
//	  {
//
//	  }
}


/**
  * @brief System Clock Configuration
  * @retval None
  */

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
