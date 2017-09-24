#ifndef __UART_H
#define __UART_H

#include <string.h>
#include <stdio.h>

#include "stm32f0xx_hal.h"

#define DATA_SEND_TIMEOUT 100
#define _NUCLEO64

UART_HandleTypeDef huart;
UART_HandleTypeDef huart2;

void MX_USART2_UART_Init(void);
void MX_USART_UART_Init(void);

void Test_UART(void);

// CUBEMX error handling functions
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

#endif /* __UART_H */