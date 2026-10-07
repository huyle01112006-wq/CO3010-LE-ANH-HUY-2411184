/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LED7.h"
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
TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t num = 0 ;
uint8_t flag = 0b00 ;

#define MAX_LED  4
int led_buffer[MAX_LED]; //= {1,2,3,4} ;
int id =0 ;

int hour = 15, minute = 10, second = 0;
int timer_counter = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
/*
	if(htim ->Instance == htim1.Instance){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_7, 1);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5) ;
	if(flag ==0 ){
		LED7_Display(num) ;
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, 0) ;
		flag =1 ;
	}
	else {
		LED7_Display(num) ;
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 0) ;
			 flag =0 ;
	}
	}
*/

	// excercise 1
/*
	if(htim->Instance == htim1.Instance){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4) ;
		if(flag == 0b00){

				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 1) ;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 1) ;
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9, 1) ;
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, 0) ;
					LED7_Display(1) ;
					flag = 0b01 ;
		}else if (flag == 0b01){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, 1) ;
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 0) ;
			LED7_Display(2) ;
			flag = 0b10 ;
		}
		else if( flag == 0b10){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 1) ;
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 0) ;
			LED7_Display(3) ;
			flag = 0b11 ;
		}
		else {
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 1) ;
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9, 0) ;
			LED7_Display(0) ;
						flag = 0b00 ;
		}
	}
*/
	 // EXCERCISE 2
/*
	if(htim->Instance == htim1.Instance){
		update7SEG(id) ;
		++id;
		if (id >= MAX_LED) id =0 ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1);
	}
	*/
	// EXCERCISE 3
/*
	if(htim->Instance == htim1.Instance){
		if(id >= MAX_LED) id =0;
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4) ;
			if(flag == 0b00){

					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 1) ;
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 1) ;
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9, 1) ;
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, 0) ;
						update7SEG(id++) ;
						flag = 0b01 ;
			}else if (flag == 0b01){
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, 1) ;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 0) ;
				update7SEG(id++) ;
				flag = 0b10 ;
			}
			else if( flag == 0b10){
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, 1) ;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 0) ;
				update7SEG(id++) ;
				flag = 0b11 ;
			}
			else {
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8, 1) ;
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9, 0) ;
				update7SEG(id++) ;
							flag = 0b00 ;
			}
		}
		//excercise 4
*/
/*
	if (htim->Instance == htim1.Instance) {
	        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, GPIO_PIN_SET);

	        switch (id) {
	            case 0:
	                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	                update7SEG(0);
	                break;
	            case 1:
	                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	                update7SEG(1);
	                break;
	            case 2:
	                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	                update7SEG(2);
	                break;
	            case 3:
	                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	                update7SEG(3);
	                break;
	        }

	        id = (id + 1) % MAX_LED;
	        timer_counter++;
	        if (timer_counter >= 4) {
	            timer_counter = 0 ;
	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	            second++;
	            if (second >= 60) {
	                second = 0;
	                minute++;
	                if (minute >= 60) {
	                    minute = 0;
	                    hour++;
	                }
	                if(hour >= 24) hour =0 ;
	            }
	            updateClockBuffer(hour, minute);
	        }
	    }
	    //excercise 5
*/


	// excercise 6

if(htim->Instance == htim1.Instance){
	timer_run() ;

}

}

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int TIMER_CYCLE = 10;
void setTimer0(int duration){
timer0_counter = duration /TIMER_CYCLE;
timer0_flag = 0;
}
void timer_run(){
if(timer0_counter > 0){
timer0_counter--;
if(timer0_counter == 0) timer0_flag = 1;
}
if(timer1_counter > 0){
timer1_counter--;
if(timer1_counter == 0) timer1_flag = 1;
}
}

void update7SEG(int idx){
	// default using en0
	switch(idx){
	case 0: LED7_Display(led_buffer[0]); break ;
	case 1: LED7_Display(led_buffer[1]); break ;
	case 2: LED7_Display(led_buffer[2]); break ;
	case 3: LED7_Display(led_buffer[3]); break ;
	default: break ;
	}
}
void updateClockBuffer(int hour, int minute){
	led_buffer[0] = hour / 10 ;
	led_buffer[1] = hour % 10 ;
	led_buffer[2] = minute / 10 ;
	led_buffer[3] = minute % 10 ;
}
void setTimer1(int duration){
    timer1_counter = duration / TIMER_CYCLE;
    timer1_flag = 0;
}
void display_7_LEDS(){
	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, GPIO_PIN_SET);
				  update7SEG(id) ;
		  switch (id) {
			            case 0:
			                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			                break;
			            case 1:
			                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			                break;
			            case 2:
			                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			                break;
			            case 3:
			                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			                break;
			        }
			     id = (id + 1) % MAX_LED;
}
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = { 0x00, 0x7C, 0x0A, 0x09, 0x09, 0x0A, 0x7C, 0x00 };
static const uint16_t COL_PINS[8] = {
    GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_10, GPIO_PIN_11,
    GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15
};
#define COL_MASK (GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_10 | GPIO_PIN_11 | \
                  GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15)
#define ROW_MASK 0xFF00U   /* PB8..PB15 */

void updateLEDMatrix(int index) {
    HAL_GPIO_WritePin(GPIOA, COL_MASK, GPIO_PIN_SET);
    uint16_t rows = ((uint16_t)((uint8_t)~matrix_buffer[index])) << 8;
    GPIOB->BSRR = (uint32_t)rows | ((uint32_t)(~rows & ROW_MASK) << 16);
    HAL_GPIO_WritePin(GPIOA, COL_PINS[index], GPIO_PIN_RESET);
}

void shift_matrix_left(void) {
    uint8_t temp = matrix_buffer[0];
    for (int i = 0; i < MAX_LED_MATRIX - 1; i++) {
        matrix_buffer[i] = matrix_buffer[i + 1];
    }
    matrix_buffer[MAX_LED_MATRIX - 1] = temp;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
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
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim1);
  LED7_Init() ;
 updateClockBuffer(hour, minute) ;
  setTimer0(1000) ;
//  setTimer1(500) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
/*
	  second++;
	     if (second >= 60){
	         second = 0;
	         minute++;
	     }
	     if(minute >= 60){
	         minute = 0;
	         hour++;
	     }
	     if(hour >=24){
	         hour = 0;
	     }
	     updateClockBuffer(hour, minute);
	     display_7_LEDS();
	     HAL_Delay(1000);
	     */
	  // EXCECISE 1
/*
	  HAL_Delay(500);
	  num = (num + 1 ) % 10;
*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // excercise 6
	  if ( timer0_flag == 1) {
	   HAL_GPIO_TogglePin ( GPIOA, GPIO_PIN_5 ) ;
	   setTimer0 (2000) ;
	   }
	  // excercise 8
	  /*
	  if(timer1_flag ==1){
		  setTimer1(20);
		  display_7_LEDS();
	  }
	  if(timer0_flag ==1 ){
		 setTimer0(1000) ;
		 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4) ;
		 second++;
		 if(second >=60){
			second = 0;
			minute++;
		 }
		 if(minute >=60){
			 minute = 0;
			 hour++;
		 }
		 if(hour >= 24) hour =0 ;
	  updateClockBuffer(hour, minute) ;
	  }
	  */
/*
	  if(timer0_flag == 1){
		  timer0_flag =0 ;
	  setTimer0(2) ;
	 updateLEDMatrix(index_led_matrix);
	  index_led_matrix = (index_led_matrix + 1 ) % MAX_LED_MATRIX;
	  }

	if (timer1_flag == 1) {
		timer1_flag =0;
	            setTimer1(500);
	            shift_matrix_left();
	        }
*/
  /* USER CODE END 3 */
}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 7999; // 799
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 9;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4 
                           PA5 PA6 PA7 PA8 
                           PA9 PA10 PA11 PA12 
                           PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10 
                           PB11 PB12 PB13 PB14 
                           PB15 PB3 PB4 PB5 
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
