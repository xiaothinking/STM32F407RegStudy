#include "led.h" 

void led_init(void)
{
   	/*���� GPIOF ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��*/
	RCC->AHB1ENR|=1<<5;//ʹ��PORTFʱ�� 	
	
	/* LED �˿ڳ�ʼ�� */
	
	/*GPIOF MODER9���*/
	GPIOF->MODER  &= ~((0x03<< (2*9))|(0x03<< (2*10)));	
	/*PF9 MODER9 = 01b ���ģʽ*/
	GPIOF->MODER |= ((1<<2*9)|(1<<2*10));
	
	/*GPIOF OTYPER9���*/
	GPIOF->OTYPER &= ~((1<<1*9)|(1<<1*10));
	/*PF9 OTYPER9 = 0b ����ģʽ*/
	GPIOF->OTYPER |= ((0<<1*9)|(0<<1*10));
	
	/*GPIOF OSPEEDR9���*/
	GPIOF->OSPEEDR &= ~((0x03<<2*9)|(0x03<<2*10));
	/*PF9 OSPEEDR9 = 10b ����50MHz*/
	GPIOF->OSPEEDR |= ((2<<2*9)|(2<<2*10));
	
	/*GPIOF PUPDR9���*/
	GPIOF->PUPDR &= ~((0x03<<2*9)|(0x03<<2*10));
	/*PF9 PUPDR9 = 00b ��������*/
	GPIOF->PUPDR |= ((0<<2*9)|(0<<2*10));
	
	/*PF9 BSRR�Ĵ����� BR9��1��ʹ��������͵�ƽ*/
	GPIOF->BSRRH |= (1<<9);
	
	/*PF9 BSRR�Ĵ����� BS9��1��ʹ��������ߵ�ƽ*/
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

