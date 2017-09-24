#ifndef __HARDWARE
#define __HARDWARE

#include "stm32f0xx_hal.h"

RTC_HandleTypeDef hrtc;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);

#endif /* __HARDWARE */