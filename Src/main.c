/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"

#include "hardware.h"
#include "uart.h"


osThreadId defaultTaskHandle;

void StartDefaultTask(void const * argument);
void task_rtc_check_time(void const * argument);

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

  Get_RTC_Status();
  Get_Current_Date(&rtc_date);
  Get_Current_Time(&rtc_time);

  osThreadDef(defaultTask, task_rtc_check_time, osPriorityNormal, 0, 128);
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

void task_rtc_check_time(void const * argument)
{

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    Get_Current_Time(&rtc_time);
    osDelay(5000);
  }
  /* USER CODE END 5 */ 
}

