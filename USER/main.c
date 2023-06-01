#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "oled.h"
#include "key.h"
#include "menu.h"
#include "esp8266.h"
#include <stdio.h>

//中断1s一次，1次秒加1，当秒==60时，分+1，当分==60时，时+1，当时==24时日+1
//5分钟校准一次


int main(void)
{	
	int i=0;
	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	Usart1_Init(115200);//debug串口
	Usart2_Init(115200);//esp8266通信串口
	TIM2_Int_Init(7199,9999);
	OLED_Init();   
	KEY_Init();
	ESP8266_Init();			//esp8266初始化
	ESP_CONNECT();			//连接wifi准备获取数据
	ESP_TIME_LINK();
	ESP_GET_TIME();
	ESP_WEATHER1_LINK();
	ESP_GET_WEATHER_1();
	ESP_WEATHER2_LINK();
	ESP_GET_WEATHER_2();
	OLED_Clear();
	while(1)
	{
		Menu_key_set();
	}
}
