#include <errno.h>
#include <sys/unistd.h>
#include <stdio.h>

#include "uart.h"

void MX_USART_UART_Init(void)
{
#ifdef _NUCLEO64
  huart.Instance = USART2;
#else
  huart.Instance = USART2;
#endif
  huart.Init.BaudRate = 9600;
  huart.Init.WordLength = UART_WORDLENGTH_8B;
  huart.Init.StopBits = UART_STOPBITS_1;
  huart.Init.Parity = UART_PARITY_NONE;
  huart.Init.Mode = UART_MODE_TX_RX;
  huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart.Init.OverSampling = UART_OVERSAMPLING_16;
  huart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART2 init function */
// void MX_USART2_UART_Init(void)
// {

//   huart2.Instance = USART2;
//   huart2.Init.BaudRate = 9600;
//   huart2.Init.WordLength = UART_WORDLENGTH_8B;
//   huart2.Init.StopBits = UART_STOPBITS_1;
//   huart2.Init.Parity = UART_PARITY_NONE;
//   huart2.Init.Mode = UART_MODE_TX_RX;
//   huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//   huart2.Init.OverSampling = UART_OVERSAMPLING_16;
//   huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//   huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//   if (HAL_UART_Init(&huart2) != HAL_OK)
//   {
//     _Error_Handler(__FILE__, __LINE__);
//   }

// }

void Test_UART(void)
{
  printf("------------------------------ RESET -------------------------- \r\n");
    HAL_UART_Transmit(&huart, "UART Running \r\n", 15, 0xFFFF);
}

int _write(int file, char *data, int len)
{
  if((file != STDOUT_FILENO) && (file != STDERR_FILENO))
  {
     errno = EBADF;
     return -1;
  }

  HAL_StatusTypeDef status = HAL_UART_Transmit(&huart, (uint8_t*)data, len, 1000);

  return (status == HAL_OK ? len : 0);
}


