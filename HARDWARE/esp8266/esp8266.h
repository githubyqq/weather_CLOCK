#ifndef _ESP8266_H_
#define _ESP8266_H_





#define REV_OK		0	//接收完成标志
#define REV_WAIT	1	//接收未完成标志


void ESP8266_Init(void);
void ESP_CONNECT1(void);	//wifi 1
void ESP_CONNECT2(void);	//wifi 2
void ESP_WEATHER1_LINK();	//九江天气获取前
void ESP_WEATHER2_LINK();	//温州天气获取前
void ESP_TIME_LINK();			//时间获取前
void ESP_GET_WEATHER_1(void);	//获取九江天气
void ESP_GET_WEATHER_2(void);	//获取温州天气
void ESP_GET_TIME(void);			//获取时间
void ESP8266_Clear(void);
void ESP8266_SendData(unsigned char *data, unsigned short len);

unsigned char *ESP8266_GetIPD(unsigned short timeOut);


#endif
