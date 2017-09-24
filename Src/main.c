/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"

#include "uart.h"
#include "hardware.h"

osThreadId defaultTaskHandle;

void StartDefaultTask(void const * argument);

int main(void)
{
  HAL_Init();


  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_RTC_Init();

  Test_UART();

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

