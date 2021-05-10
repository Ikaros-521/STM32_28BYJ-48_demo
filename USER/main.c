#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "beep.h"
#include "step.h"

//IN4: PB6  d
//IN3: PB5  c
//IN2: PB4  b
//IN1: PB3  a

int main(void)
{
	vu8 key = 0;
	uint8_t time = 0;
	delay_init(); //��ʱ������ʼ��
	LED_Init();	  //��ʼ����LED���ӵ�Ӳ���ӿ�
	BEEP_Init();  //��ʼ���������˿�
	KEY_Init();	  //��ʼ���밴�����ӵ�Ӳ���ӿ�
	Step_Motor_GPIO_Init();
	
	LED0 = 0;
	BEEP = 0;
	
	while (1)
	{
		key = KEY_Scan(0); //�õ���ֵ
		if (key)
		{
			switch (key)
			{
				case WKUP_PRES: // ��תLED1�������ת��Ȧ
					LED1 = !LED1;
					/*
						���ܣ�ת1/64Ȧ
						�����5.625 360/5.625=64 ���ٱ�1/64
						��64*64������תһȦ
						n Ȧ��
						direction ���� 1��ת ��1��ת
						delay delayʱ��ms >= 2
					*/
					motor_circle(32, 1, 2);
					break;
				case KEY1_PRES: // ��תLED1�������ת1Ȧ
					LED1 = !LED1;
					motor_circle(64, 1, 2);
					break;
				case KEY0_PRES: // ��תLED1�������ת1Ȧ
					LED1 = !LED1;
					motor_circle(64, 0, 2);
					break;
			}
		}
		
		time++;
		if(time % 100 == 0)
		{
			LED0 = !LED0;
		}
	
		delay_ms(10);
	}
}
