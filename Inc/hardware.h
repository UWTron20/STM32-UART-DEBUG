#ifndef __HARDWARE
#define __HARDWARE

#include <stdio.h>
#include <string.h>

#include "stm32f0xx_hal.h"

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA

RTC_HandleTypeDef hrtc;

// Hex representation (Converted form BCD)
typedef struct {
    uint8_t date;
    uint8_t month;
    uint8_t year;
} rtc_date_t;

// Hex representation (Converted form BCD)
typedef struct {
    uint8_t second;
    uint8_t min;
    uint8_t hour;
} rtc_time_t;

void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_RTC_Init(void);

void Get_Current_Date(rtc_date_t * date);
void Get_Current_Time(rtc_time_t * time);
void Toggle_Nucleo_LED(uint32_t time, uint32_t number_of_flash);

#endif /* __HARDWARE */