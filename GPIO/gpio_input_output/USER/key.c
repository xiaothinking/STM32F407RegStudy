#include "key.h"

void key_init(void)
{
   	/*���� GPIOF ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��*/
	RCC->AHB1ENR|=((1<<0)|(1<<4));//ʹ��PORTA��PORTEʱ�� 	
	
	/* LED �˿ڳ�ʼ�� */
	
	/*PE MODER2��3��4 = 01b ���ģʽ*/
	GPIOE->MODER  &= ~((0x03<< (2*2))|(0x03<< (2*3))|(0x03<< (2*4)));	
	GPIOA->MODER  &= ~(0x03<< (2*0));	
	
	/*GPIOE PUPDR9���*/
	GPIOE->PUPDR &= ~((0x03<<2*2)|(0x03<<2*3)|(0x03<<2*4));
	/*PF9 PUPDR9 = 01b ����*/
	GPIOE->PUPDR |= ((1<<2*2)|(1<<2*3)|(1<<2*4));
	
	GPIOA->PUPDR &= ~((0x03<<2*0));
	/*PF9 PUPDR9 = 10b ����*/
	GPIOA->PUPDR |= (2<<2*0);
	
}

uint8_t key_scan(void)
{
	uint8_t key=255;
	if((GPIOE->IDR & (1<<2))==0)
    {
			  delay_ms(10);
				if((GPIOE->IDR & (1<<2))==0)
          {						
						key=2; 
					}
		}
  else if((GPIOE->IDR & (1<<3))==0)
    {
			  delay_ms(10);
				if((GPIOE->IDR & (1<<3))==0)
          {						
						key=1; 
					}
		}
	else if((GPIOE->IDR & (1<<4))==0)
    {
			  delay_ms(10);
				if((GPIOE->IDR & (1<<4))==0)
          {						
						key=0; 
					}
		}
	else if((GPIOA->IDR & (1<<0))!=0)
    {
			  delay_ms(10);
				if((GPIOA->IDR & (1<<0))==0)
          {						
						key=3; 
					}
		}
	return key;
}

