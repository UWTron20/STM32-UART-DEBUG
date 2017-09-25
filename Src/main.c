/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"

#include "uart.h"
#include "hardware.h"

osThreadId defaultTaskHandle;

void StartDefaultTask(void const * argument);

rtc_date_t rtc_date;

int main(void)
{
  HAL_Init();


  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART_UART_Init();
  

  Test_UART();
  printf("RTC Configuration....");
  MX_RTC_Init();
  printf("RTC Configured.");
  Get_Current_Date(&rtc_date);

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

