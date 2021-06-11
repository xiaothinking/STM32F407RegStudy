#include "led.h" 

void led_init(void)
{
   	/*开启 GPIOF 时钟，使用外设时都要先开启它的时钟*/
	RCC->AHB1ENR|=1<<5;//使能PORTF时钟 	
	
	/* LED 端口初始化 */
	
	/*GPIOF MODER9清空*/
	GPIOF->MODER  &= ~((0x03<< (2*9))|(0x03<< (2*10)));	
	/*PF9 MODER9 = 01b 输出模式*/
	GPIOF->MODER |= ((1<<2*9)|(1<<2*10));
	
	/*GPIOF OTYPER9清空*/
	GPIOF->OTYPER &= ~((1<<1*9)|(1<<1*10));
	/*PF9 OTYPER9 = 0b 推挽模式*/
	GPIOF->OTYPER |= ((0<<1*9)|(0<<1*10));
	
	/*GPIOF OSPEEDR9清空*/
	GPIOF->OSPEEDR &= ~((0x03<<2*9)|(0x03<<2*10));
	/*PF9 OSPEEDR9 = 10b 速率50MHz*/
	GPIOF->OSPEEDR |= ((2<<2*9)|(2<<2*10));
	
	/*GPIOF PUPDR9清空*/
	GPIOF->PUPDR &= ~((0x03<<2*9)|(0x03<<2*10));
	/*PF9 PUPDR9 = 00b 无上下拉*/
	GPIOF->PUPDR |= ((0<<2*9)|(0<<2*10));
	
	/*PF9 BSRR寄存器的 BR9置1，使引脚输出低电平*/
	GPIOF->BSRRH |= (1<<9);
	
	/*PF9 BSRR寄存器的 BS9置1，使引脚输出高电平*/
//	GPIOF->BSRRL |= (1<<9);
  GPIOF->BSRRL |= (1<<10);
}

void led_ctrl(uint8_t mode)
{
	switch(mode)
    {
		case 0x00:
			    GPIOF->BSRRL |= (1<<9);
					GPIOF->BSRRL |= (1<<10);
			   break;
	  case 0x01:
			    GPIOF->BSRRH |= (1<<9);
					GPIOF->BSRRL |= (1<<10);
			   break;
		case 0x02:
			    GPIOF->BSRRL |= (1<<9);
					GPIOF->BSRRH |= (1<<10);
			   break;
	  case 0x03:
			   	GPIOF->BSRRH |= (1<<9);
					GPIOF->BSRRH |= (1<<10);
			   break;
		default:
			   break;

		} 
}

