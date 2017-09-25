/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"

#include "hardware.h"
#include "uart.h"


osThreadId defaultTaskHandle;

void StartDefaultTask(void const * argument);

rtc_date_t rtc_date;
rtc_time_t rtc_time;

int main(void)
{
  HAL_Init();


  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART_UART_Init();
  MX_RTC_Init();  

  Test_UART();

  printf("RTC Configuration \r\n");

  printf("RTC Configured. \r\n");

  Get_Current_Date(&rtc_date);
  Get_Current_Time(&rtc_time);

  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* Start scheduler */
  osKernelStart();

  while (1)
  {

  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
  void _Error_Handler(char * file, int line)
  {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    while(1) 
    {
      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
      HAL_Delay(500);
    }
    /* USER CODE END Error_Handler_Debug */ 
  }
  
  #ifdef USE_FULL_ASSERT
  
  /**
     * @brief Reports the name of the source file and the source line number
     * where the assert_param error has occurred.
     * @param file: pointer to the source file name
     * @param line: assert_param error line source number
     * @retval None
     */
  void assert_failed(uint8_t* file, uint32_t line)
  {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
      ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
  
  }
  
  #endif