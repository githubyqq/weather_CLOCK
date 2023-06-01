
//单片机头文件
#include "stm32f10x.h"

//网络设备驱动
#include "esp8266.h"

//硬件驱动
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"
//C库
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//#define ESP8266_WIFI_INFO		"AT+CWJAP=\"fuqi\",\"13755228725\"\r\n"   //wifi账号密码
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"Xiaomi_E417\",\"703703703\"\r\n"   //wifi账号密码
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
//	函数名称：	ESP8266_Clear
//
//	函数功能：	清空缓存
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：		
//==========================================================
void ESP8266_Clear(void)
{

	memset(esp8266_buf, 0, sizeof(esp8266_buf));
	esp8266_cnt = 0;

}

//==========================================================
//	函数名称：	ESP8266_WaitRecive
//
//	函数功能：	等待接收完成
//
//	入口参数：	无
//
//	返回参数：	REV_OK-接收完成		REV_WAIT-接收超时未完成
//
//	说明：		循环调用检测是否接收完成
//==========================================================
_Bool ESP8266_WaitRecive(void)
{

	if(esp8266_cnt == 0) 							//如果接收计数为0 则说明没有处于接收数据中，所以直接跳出，结束函数
		return REV_WAIT;
		
	if(esp8266_cnt == esp8266_cntPre)				//如果上一次的值和这次相同，则说明接收完毕
	{
		esp8266_cnt = 0;							//清0接收计数
			
		return REV_OK;								//返回接收完成标志
	}
		
	esp8266_cntPre = esp8266_cnt;					//置为相同
	
	return REV_WAIT;								//返回接收未完成标志

}

//==========================================================
//	函数名称：	ESP8266_SendCmd
//
//	函数功能：	发送命令
//
//	入口参数：	cmd：命令
//				res：需要检查的返回指令
//
//	返回参数：	0-成功	1-失败
//
//	说明：		
//==========================================================
_Bool ESP8266_SendCmd(char *cmd, char *res)
{
	
	unsigned char timeOut = 200;

	Usart_SendString(USART2, (unsigned char *)cmd, strlen((const char *)cmd));
	
	while(timeOut--)
	{
		if(ESP8266_WaitRecive() == REV_OK)							//如果收到数据
		{
			if(strstr((const char *)esp8266_buf, res) != NULL)		//如果检索到关键词
			{
				ESP8266_Clear();									//清空缓存
				
				return 0;
			}
		}
		
		delay_ms(10);
	}
	
	return 1;

}

//==========================================================
//	函数名称：	ESP8266_SendData
//
//	函数功能：	发送数据
//
//	入口参数：	data：数据
//				len：长度
//
//	返回参数：	无
//
//	说明：		
//==========================================================
void ESP8266_SendData(unsigned char *data, unsigned short len)
{

	char cmdBuf[32];
	
	ESP8266_Clear();								//清空接收缓存
	sprintf(cmdBuf, "AT+CIPSEND=%d\r\n", len);		//发送命令
	if(!ESP8266_SendCmd(cmdBuf, ">"))				//收到‘>’时可以发送数据
	{
		Usart_SendString(USART2, data, len);		//发送设备连接请求数据
	}

}

//==========================================================
//	函数名称：	ESP8266_GetIPD
//
//	函数功能：	获取平台返回的数据
//
//	入口参数：	等待的时间(乘以10ms)
//
//	返回参数：	平台返回的原始数据
//
//	说明：		不同网络设备返回的格式不同，需要去调试
//				如ESP8266的返回格式为	"+IPD,x:yyy"	x代表数据长度，yyy是数据内容
//==========================================================
unsigned char *ESP8266_GetIPD(unsigned short timeOut)
{

	char *ptrIPD = NULL;
	
	do
	{
		if(ESP8266_WaitRecive() == REV_OK)								//如果接收完成
		{
			ptrIPD = strstr((char *)esp8266_buf, "IPD,");				//搜索“IPD”头
			if(ptrIPD == NULL)											//如果没找到，可能是IPD头的延迟，还是需要等待一会，但不会超过设定的时间
			{
				//UsartPrintf(USART_DEBUG, "\"IPD\" not found\r\n");
			}
			else
			{
				ptrIPD = strchr(ptrIPD, ':');							//找到':'
				if(ptrIPD != NULL)
				{
					ptrIPD++;
					return (unsigned char *)(ptrIPD);
				}
				else
					return NULL;
				
			}
		}
		
		delay_ms(5);													//延时等待
		timeOut--;
	} while(timeOut > 0);
	
	return NULL;														//超时还未找到，返回空指针

}

//==========================================================
//	函数名称：	ESP8266_Init
//
//	函数功能：	初始化ESP8266
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：		
//==========================================================
void ESP8266_Init(void)
{
	
	GPIO_InitTypeDef GPIO_Initure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	//ESP8266复位引脚
	GPIO_Initure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initure.GPIO_Pin = GPIO_Pin_14;					//GPIOC14-复位
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
	//年解析
  NowTime[0] = (buf[0]-'0')*1000+(buf[1]-'0')*100+(buf[2]-'0')*10+(buf[3]-'0');

	//月解析
	NowTime[1] = (buf[5]-'0')*10+(buf[6]-'0');	
	
	//日解析
	NowTime[2] = (buf[8]-'0')*10 + (buf[9]-'0');	

	//时解析
	NowTime[3] = (buf[11]-'0')*10 + (buf[12]-'0');	
	//分解析
	NowTime[4] = (buf[14]-'0')*10 + (buf[15]-'0');	
	//秒解析
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
	char *weather1 = NULL;   //存储天气起始地址
	char *temperature1 = NULL;  //存储温度起始地址
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
//	函数名称：	USART2_IRQHandler
//
//	函数功能：	串口2收发中断
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：		
//= =========================================================
void USART2_IRQHandler(void)
{

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) //接收中断
	{
		if(esp8266_cnt >= sizeof(esp8266_buf))	esp8266_cnt = 0; //防止串口被刷爆
		esp8266_buf[esp8266_cnt++] = USART2->DR;
		
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}
}
