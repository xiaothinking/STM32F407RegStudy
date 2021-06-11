#include "stm32f4xx.h" 
#include "led.h" 
#include "delay.h"
#include "key.h"
/**
  *   Ö÷º¯Êý
  */
uint8_t g_key =255;
int main(void)
{	
	led_init();
	key_init();
	delay_init(168);
	while(1)
    {
      g_key=key_scan();
			if(g_key!=255)
      {
				
				led_ctrl(g_key);
			}
		}

}
