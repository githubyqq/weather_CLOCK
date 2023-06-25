#ifndef _ESP8266_H_
#define _ESP8266_H_





#define REV_OK		0	//������ɱ�־
#define REV_WAIT	1	//����δ��ɱ�־


void ESP8266_Init(void);
void ESP_CONNECT1(void);	//wifi 1
void ESP_CONNECT2(void);	//wifi 2
void ESP_WEATHER1_LINK();	//�Ž�������ȡǰ
void ESP_WEATHER2_LINK();	//����������ȡǰ
void ESP_TIME_LINK();			//ʱ���ȡǰ
void ESP_GET_WEATHER_1(void);	//��ȡ�Ž�����
void ESP_GET_WEATHER_2(void);	//��ȡ��������
void ESP_GET_TIME(void);			//��ȡʱ��
void ESP8266_Clear(void);
void ESP8266_SendData(unsigned char *data, unsigned short len);

unsigned char *ESP8266_GetIPD(unsigned short timeOut);


#endif
