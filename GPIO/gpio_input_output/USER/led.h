#ifndef _LED_H
#define _LED_H

#include "stm32f4xx.h" 
#include "delay.h" 

void led_init(void);
void led_ctrl(uint8_t mode);
#endif

