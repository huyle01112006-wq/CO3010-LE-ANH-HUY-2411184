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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearAllClock(void)
{
    HAL_GPIO_WritePin(
        GPIOA, GPIO_PIN_4  | GPIO_PIN_5  | GPIO_PIN_6  | GPIO_PIN_7 |
        GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 | GPIO_PIN_11 |
        GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
        GPIO_PIN_SET
    );
}

void clearNumberOnClock(int num)
{
    if (num < 0 || num > 11)
        return;
    HAL_GPIO_WritePin(GPIOA, (1 << (num + 4)), GPIO_PIN_SET);
}
void setNumberOnClock(int num)
{
    if (num < 0 || num > 11)
        return;
  //  clearAllClock();
    HAL_GPIO_WritePin(GPIOA, (1 << (num + 4)), GPIO_PIN_RESET);

}
void leds_12(){
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4) ;
	  HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7) ;  HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8) ;  HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_13) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_14) ;   HAL_Delay(10);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15) ;   HAL_Delay(10);
	  HAL_Delay(1000);
}
void turn_on_12leds(){
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14,0) ;
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,0 ) ;

}

 void display_clock(int hour, int minute, int second){

	    minute += second / 60;
	    second %= 60;
	    hour += minute / 60;
	    minute %= 60 ;
	    clearAllClock() ;
	 setNumberOnClock(hour % 12 ) ;
	 setNumberOnClock((int) minute / 5) ;
	 setNumberOnClock((int) second /5) ;
 }
 int counter = 9 ;
void display_7SEG(int count){
	switch(count){
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
			HAL_Delay(100);
			break;

		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
			HAL_Delay(100);
			break ;

	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
		HAL_Delay(100);
		break ;

	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
		HAL_Delay(100);
		break ;

		case 4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
			HAL_Delay(100);
			break ;

			case 5:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
			HAL_Delay(100);
		break;
			case 6:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
			HAL_Delay(100);
		break ;
			case 7:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
			HAL_Delay(100);
		break ;
			case 8:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
			HAL_Delay(100);
			break ;

			case 9:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
			HAL_Delay(100);
			break ;
		}
}
void led_traffic_with_7seg(int count) {
    if (count >= 5) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
    } else if (count >= 3) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
    } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,0);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
    }
    HAL_Delay(100);
}
void led_traffic_with_7seg1(int count) {
    if (count >= 5) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 1);
    } else if (count >= 3) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 0);
    } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 1);
    }
    HAL_Delay(100);
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
  clearAllClock() ;
  /* USER CODE BEGIN 2 */
int num = 10 ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Excercise 1
/*
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))? 0 : 1) ;
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))? 0 : 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))? 0 : 1) ;
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6))? 0 : 1) ;
*/
/*
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
	  HAL_Delay(100) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
	  HAL_Delay(100);
	  */

/*
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6) ;
	  HAL_Delay(100) ;
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6) ;
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5) ;
	  HAL_Delay(100);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5) ;
  */
/*
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	  HAL_Delay(2000);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
*/

	  // Excercise 1
	  // Excercise 2 3
	 /*
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0) ;
	  HAL_Delay(3000);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1) ;
	  HAL_Delay(2000);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1) ;
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1) ;
	  HAL_Delay(5000) ;
*/
	  // excercise 4
	  /*
if ( counter >= 10) counter = 0;
 display7SEG ( counter ++) ;
HAL_Delay (1000) ;
*/
	  // EXCERCISE 5

	  /*

	   if (counter < 0) {counter = 9;}
	       display_7SEG(counter--);
	  	  	 led_traffic_with_7seg(counter) ;
	  	  	 led_traffic_with_7seg1(counter) ;
	  	  	 */



	  //excercise 6
	 //leds_12();
	  //excercise 7
/*
	  turn_on_12leds() ;
	  HAL_Delay(10);
	  clearAllClock();
	  HAL_Delay(10);
*/
	  //excercise 8
	  //setNumberOnClock(num) ;
	  //excecise 9

	  turn_on_12leds() ;
	  HAL_Delay(100);
	  clearNumberOnClock(num) ;
	  HAL_Delay(100);

	  // excercise 10
//	  display_clock(10,59,20) ;
  }
  /* USER CODE END 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7 
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11 
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 
                           PA4 PA5 PA6 PA7 
                           PA8 PA9 PA10 PA11 
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7 
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11 
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
