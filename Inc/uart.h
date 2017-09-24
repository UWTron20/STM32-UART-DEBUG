#ifndef __UART_H
#define __UART_H

#include <string.h>
#include <stdio.h>

#include "stm32f0xx_hal.h"

#define DATA_SEND_TIMEOUT 100

UART_HandleTypeDef huart2;

// implement this function in your code to act on commands received from the
// serial port
// DO NOT change this empty implementation
// __weak void executeSerialCommand(char str[]) {
    
// }

// // Function to enable printf for debugging
// int _write(int file, char* data, int len) {
//     HAL_UART_Transmit(&huart, (uint8_t*)data, len, DATA_SEND_TIMEOUT);
//     return len;
// }

void MX_USART2_UART_Init(void);

void Test_UART(void);

#endif /* __UART_H */