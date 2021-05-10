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
	delay_init(); //延时函数初始化
	LED_Init();	  //初始化与LED连接的硬件接口
	BEEP_Init();  //初始化蜂鸣器端口
	KEY_Init();	  //初始化与按键连接的硬件接口
	Step_Motor_GPIO_Init();
	
	LED0 = 0;
	BEEP = 0;
	
	while (1)
	{
		key = KEY_Scan(0); //得到键值
		if (key)
		{
			switch (key)
			{
				case WKUP_PRES: // 翻转LED1，电机正转半圈
					LED1 = !LED1;
					/*
						功能：转1/64圈
						步距角5.625 360/5.625=64 减速比1/64
						故64*64个脉冲转一圈
						n 圈数
						direction 方向 1正转 非1反转
						delay delay时长ms >= 2
					*/
					motor_circle(32, 1, 2);
					break;
				case KEY1_PRES: // 翻转LED1，电机正转1圈
					LED1 = !LED1;
					motor_circle(64, 1, 2);
					break;
				case KEY0_PRES: // 翻转LED1，电机反转1圈
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
