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

//�ж�1sһ�Σ�1�����1������==60ʱ����+1������==60ʱ��ʱ+1����ʱ==24ʱ��+1
//5����У׼һ��


int main(void)
{	
	int i=0;
	delay_init();	    //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	Usart1_Init(115200);//debug����
	Usart2_Init(115200);//esp8266ͨ�Ŵ���
	TIM2_Int_Init(7199,9999);
	OLED_Init();   
	KEY_Init();
	ESP8266_Init();			//esp8266��ʼ��
	ESP_CONNECT();			//����wifi׼����ȡ����
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
