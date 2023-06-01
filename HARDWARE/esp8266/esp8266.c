
//��Ƭ��ͷ�ļ�
#include "stm32f10x.h"

//�����豸����
#include "esp8266.h"

//Ӳ������
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"
//C��
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//#define ESP8266_WIFI_INFO		"AT+CWJAP=\"fuqi\",\"13755228725\"\r\n"   //wifi�˺�����
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"Xiaomi_E417\",\"703703703\"\r\n"   //wifi�˺�����
#define ESP8266_WEATHER_INFO  "GET https://api.seniverse.com/v3/weather/now.json?key=SBHCbw5MrmOr6BLqN&location=jiujiang&language=zh-Hans&unit=c\n\r"
#define ESP8266_WEATHER_INFO1  "GET https://api.seniverse.com/v3/weather/now.json?key=SBHCbw5MrmOr6BLqN&location=changsha&language=zh-Hans&unit=c\n\r"
#define ESP8266_TIME_INFO		"GET http://api.k780.com:88/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json\n\r"	
#define ESP8266_EXIT "+++"
unsigned char esp8266_buf[512];
unsigned short esp8266_cnt = 0, esp8266_cntPre = 0;
int weather_t=0,weather1_t=0;
int temperature_t=0,temperature1_t=0;
int week_t=0;
int j=0;
int NowTime[6];
int year,month,day,hour,min,sec;
//==========================================================
//	�������ƣ�	ESP8266_Clear
//
//	�������ܣ�	��ջ���
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void ESP8266_Clear(void)
{

	memset(esp8266_buf, 0, sizeof(esp8266_buf));
	esp8266_cnt = 0;

}

//==========================================================
//	�������ƣ�	ESP8266_WaitRecive
//
//	�������ܣ�	�ȴ��������
//
//	��ڲ�����	��
//
//	���ز�����	REV_OK-�������		REV_WAIT-���ճ�ʱδ���
//
//	˵����		ѭ�����ü���Ƿ�������
//==========================================================
_Bool ESP8266_WaitRecive(void)
{

	if(esp8266_cnt == 0) 							//������ռ���Ϊ0 ��˵��û�д��ڽ��������У�����ֱ����������������
		return REV_WAIT;
		
	if(esp8266_cnt == esp8266_cntPre)				//�����һ�ε�ֵ�������ͬ����˵���������
	{
		esp8266_cnt = 0;							//��0���ռ���
			
		return REV_OK;								//���ؽ�����ɱ�־
	}
		
	esp8266_cntPre = esp8266_cnt;					//��Ϊ��ͬ
	
	return REV_WAIT;								//���ؽ���δ��ɱ�־

}

//==========================================================
//	�������ƣ�	ESP8266_SendCmd
//
//	�������ܣ�	��������
//
//	��ڲ�����	cmd������
//				res����Ҫ���ķ���ָ��
//
//	���ز�����	0-�ɹ�	1-ʧ��
//
//	˵����		
//==========================================================
_Bool ESP8266_SendCmd(char *cmd, char *res)
{
	
	unsigned char timeOut = 200;

	Usart_SendString(USART2, (unsigned char *)cmd, strlen((const char *)cmd));
	
	while(timeOut--)
	{
		if(ESP8266_WaitRecive() == REV_OK)							//����յ�����
		{
			if(strstr((const char *)esp8266_buf, res) != NULL)		//����������ؼ���
			{
				ESP8266_Clear();									//��ջ���
				
				return 0;
			}
		}
		
		delay_ms(10);
	}
	
	return 1;

}

//==========================================================
//	�������ƣ�	ESP8266_SendData
//
//	�������ܣ�	��������
//
//	��ڲ�����	data������
//				len������
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void ESP8266_SendData(unsigned char *data, unsigned short len)
{

	char cmdBuf[32];
	
	ESP8266_Clear();								//��ս��ջ���
	sprintf(cmdBuf, "AT+CIPSEND=%d\r\n", len);		//��������
	if(!ESP8266_SendCmd(cmdBuf, ">"))				//�յ���>��ʱ���Է�������
	{
		Usart_SendString(USART2, data, len);		//�����豸������������
	}

}

//==========================================================
//	�������ƣ�	ESP8266_GetIPD
//
//	�������ܣ�	��ȡƽ̨���ص�����
//
//	��ڲ�����	�ȴ���ʱ��(����10ms)
//
//	���ز�����	ƽ̨���ص�ԭʼ����
//
//	˵����		��ͬ�����豸���صĸ�ʽ��ͬ����Ҫȥ����
//				��ESP8266�ķ��ظ�ʽΪ	"+IPD,x:yyy"	x�������ݳ��ȣ�yyy����������
//==========================================================
unsigned char *ESP8266_GetIPD(unsigned short timeOut)
{

	char *ptrIPD = NULL;
	
	do
	{
		if(ESP8266_WaitRecive() == REV_OK)								//����������
		{
			ptrIPD = strstr((char *)esp8266_buf, "IPD,");				//������IPD��ͷ
			if(ptrIPD == NULL)											//���û�ҵ���������IPDͷ���ӳ٣�������Ҫ�ȴ�һ�ᣬ�����ᳬ���趨��ʱ��
			{
				//UsartPrintf(USART_DEBUG, "\"IPD\" not found\r\n");
			}
			else
			{
				ptrIPD = strchr(ptrIPD, ':');							//�ҵ�':'
				if(ptrIPD != NULL)
				{
					ptrIPD++;
					return (unsigned char *)(ptrIPD);
				}
				else
					return NULL;
				
			}
		}
		
		delay_ms(5);													//��ʱ�ȴ�
		timeOut--;
	} while(timeOut > 0);
	
	return NULL;														//��ʱ��δ�ҵ������ؿ�ָ��

}

//==========================================================
//	�������ƣ�	ESP8266_Init
//
//	�������ܣ�	��ʼ��ESP8266
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void ESP8266_Init(void)
{
	
	GPIO_InitTypeDef GPIO_Initure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	//ESP8266��λ����
	GPIO_Initure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initure.GPIO_Pin = GPIO_Pin_14;					//GPIOC14-��λ
	GPIO_Initure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Initure);
	
	GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_RESET);
	delay_ms(250);
	GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_SET);
	delay_ms(500);
	
	ESP8266_Clear();
}

void ESP_CONNECT(void)
{
	wifi_connect();
	wait();
	UsartPrintf(USART_DEBUG,"0. AT\r\n");
	while(ESP8266_SendCmd("AT\r\n", "OK"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"1. RST\r\n");
	while(ESP8266_SendCmd("AT+RST\r\n", ""))
		delay_ms(500);
	while(ESP8266_SendCmd("AT+CIPCLOSE\r\n", ""))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"2. CWMODE\r\n");
	while(ESP8266_SendCmd("AT+CWMODE=1\r\n", "OK"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"3. CONNECT WIFI\r\n");
	while(ESP8266_SendCmd(ESP8266_WIFI_INFO, "GOT IP"))
		delay_ms(500);
	LED0=0;
	OLED_Clear();
	wifi_connect_success();
	get_data();
	
}
void ESP_TIME_LINK()
{
	if(j!=0)
	{
		UsartPrintf(USART_DEBUG,"11. CIPCLOSE\r\n");
		while(ESP8266_SendCmd("AT+CIPCLOSE\r\n", "OK"))
			delay_ms(500);
		UsartPrintf(USART_DEBUG,"12. CWMODE\r\n");
		while(ESP8266_SendCmd("AT+CWMODE=1\r\n", "OK"))
			delay_ms(500);
	}
	UsartPrintf(USART_DEBUG,"4. TCP time connect\r\n");
	while(ESP8266_SendCmd("AT+CIPSTART=\"TCP\",\"api.k780.com\",80\r\n", "CONNECT"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"5. CIPMODE\r\n");
	while(ESP8266_SendCmd("AT+CIPMODE=1\r\n", "OK"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"6. CIPSEND\r\n");
	while(ESP8266_SendCmd("AT+CIPSEND\r\n", "OK"))
		delay_ms(500);
	j++;
}

void ESP_WEATHER1_LINK()
{
	UsartPrintf(USART_DEBUG,"7. CIPCLOSE\r\n");
	while(ESP8266_SendCmd("AT+CIPCLOSE\r\n", "OK"))
		delay_ms(500);
	UsartPrintf(USART_DEBUG,"7. CWMODE\r\n");
	while(ESP8266_SendCmd("AT+CWMODE=1\r\n", "OK"))
		delay_ms(500);
	UsartPrintf(USART_DEBUG,"8. TCP weather connect\r\n");
	while(ESP8266_SendCmd("AT+CIPSTART=\"TCP\",\"api.seniverse.com\",80\r\n", "CONNECT"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"9. CIPMODE\r\n");
	while(ESP8266_SendCmd("AT+CIPMODE=1\r\n", "OK"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"10. CIPSEND\r\n");
	while(ESP8266_SendCmd("AT+CIPSEND\r\n", "OK"))
		delay_ms(500);
}

void ESP_WEATHER2_LINK()
{
	UsartPrintf(USART_DEBUG,"9. CIPMODE\r\n");
	while(ESP8266_SendCmd("AT+CIPMODE=1\r\n", "OK"))
		delay_ms(500);
	
	UsartPrintf(USART_DEBUG,"10. CIPSEND\r\n");
	while(ESP8266_SendCmd("AT+CIPSEND\r\n", "OK"))
		delay_ms(500);
}

void ESP_GET_TIME(void)
{
	char *str,*week;
	int i,j;
	char Week[1]={0};
	char buf[19];
	Usart_SendString(USART2, (unsigned char *)ESP8266_TIME_INFO, strlen((const char *)ESP8266_TIME_INFO));
	delay_ms(500);
	UsartPrintf(USART_DEBUG,"get time data:%s\n",esp8266_buf);
	str = strstr((const char *)esp8266_buf,(const char *)"\"datetime_1\":")+14;
	week = strstr((const char *)esp8266_buf,(const char *)"\"week_1\":")+10;
	Week[0] = *week++;
	week_t = atoi(&Week[0]);
	UsartPrintf(USART_DEBUG,"week=%d\n",week_t);
	sscanf(str,"%[^\"]",buf);
	UsartPrintf(USART_DEBUG,"time=%s\n",buf);
	//�����
  NowTime[0] = (buf[0]-'0')*1000+(buf[1]-'0')*100+(buf[2]-'0')*10+(buf[3]-'0');

	//�½���
	NowTime[1] = (buf[5]-'0')*10+(buf[6]-'0');	
	
	//�ս���
	NowTime[2] = (buf[8]-'0')*10 + (buf[9]-'0');	

	//ʱ����
	NowTime[3] = (buf[11]-'0')*10 + (buf[12]-'0');	
	//�ֽ���
	NowTime[4] = (buf[14]-'0')*10 + (buf[15]-'0');	
	//�����
	NowTime[5] = (buf[17]-'0')*10 + (buf[18]-'0');	
	year=NowTime[0];
	month=NowTime[1];
	day=NowTime[2];
	hour=NowTime[3];
	min=NowTime[4];
	sec=NowTime[5]+1;
	Usart_SendString(USART2,(unsigned char *)ESP8266_EXIT,strlen((const char *)ESP8266_EXIT));
	delay_ms(1000);
}

void ESP_GET_WEATHER_1(void)
{
	int i;
	char *temperature=(char*) malloc(sizeof(char)*2);
	char *weather=(char*) malloc(sizeof(char)*2);
	char *location=(char*) malloc(sizeof(char)*6);
	char Location[6]={0};
	char Weather[2]={0};
	char Temperature[2]={0};
	Usart_SendString(USART2, (unsigned char *)ESP8266_WEATHER_INFO, strlen((const char *)ESP8266_WEATHER_INFO));
	delay_ms(500);
	UsartPrintf(USART_DEBUG,"get weather data:%s\n",esp8266_buf);
	location = strstr((const char *)esp8266_buf,(const char *)"\"name\":")+8;
	weather = strstr((const char *)esp8266_buf,(const char *)"\"code\":")+8;
	temperature = strstr((const char *) esp8266_buf,(const char *)"\"temperature\":") + 15; 
	for(i=0;i<6;i++)
	{
		Location[i]=*location++;
	}
	for(i=0;i<2;i++)
	{
		Weather[i]=*weather++;
		Temperature[i]=*temperature++;
	}
	free(weather);
	free(location);
	free(temperature);
	weather_t=atoi(&Weather[0]);
	temperature_t=atoi(&Temperature[0]);
	UsartPrintf(USART_DEBUG,"location=%s\n",Location);
	UsartPrintf(USART_DEBUG,"weather=%s\n",Weather);
	UsartPrintf(USART_DEBUG,"temperature=%s\n",Temperature);
	Usart_SendString(USART2,(unsigned char *)ESP8266_EXIT,strlen((const char *)ESP8266_EXIT));
	delay_ms(1000);
}

void ESP_GET_WEATHER_2(void)
{
	int i;
	char *weather1 = NULL;   //�洢������ʼ��ַ
	char *temperature1 = NULL;  //�洢�¶���ʼ��ַ
	char	*location1 = NULL;
	
	char Location1[6]={0};
	char Weather1[2]={0};
	char Temperature1[2]={0};
	Usart_SendString(USART2, (unsigned char *)ESP8266_WEATHER_INFO1, strlen((const char *)ESP8266_WEATHER_INFO1));
	delay_ms(500);
	UsartPrintf(USART_DEBUG,"get weather data:%s\n",esp8266_buf);
	location1 = strstr((const char *)esp8266_buf,(const char *)"\"name\":")+8;
	weather1 = strstr((const char *)esp8266_buf,(const char *)"\"code\":")+8;
	temperature1 = strstr((const char *) esp8266_buf,(const char *)"\"temperature\":") + 15; 
	for(i=0;i<6;i++)
	{
		Location1[i]=*location1++;
	}
	UsartPrintf(USART_DEBUG,"location1=%s\n",Location1);
	for(i=0;i<2;i++)
	{
		Weather1[i]=*weather1++;
		Temperature1[i]=*temperature1++;
	}
	weather1_t=atoi(&Weather1[0]);
	temperature1_t=atoi(&Temperature1[0]);
	UsartPrintf(USART_DEBUG,"weather1=%s\n",Weather1);
	UsartPrintf(USART_DEBUG,"temperature1=%s\n",Temperature1);
	Usart_SendString(USART2,(unsigned char *)ESP8266_EXIT,strlen((const char *)ESP8266_EXIT));
	delay_ms(1000);
	while(ESP8266_SendCmd("AT+CIPCLOSE\r\n", "OK"))
		delay_ms(500);
}

//==========================================================
//	�������ƣ�	USART2_IRQHandler
//
//	�������ܣ�	����2�շ��ж�
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//= =========================================================
void USART2_IRQHandler(void)
{

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) //�����ж�
	{
		if(esp8266_cnt >= sizeof(esp8266_buf))	esp8266_cnt = 0; //��ֹ���ڱ�ˢ��
		esp8266_buf[esp8266_cnt++] = USART2->DR;
		
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}
}
