#ifndef __MENU_H
#define __MENU_H
 
#include "sys.h"

#define  u8 unsigned char
 

 
 
typedef struct
{
    u8 current;	//��ǰ״̬������
    u8 next; 		//����һ��
    u8 enter; 	//ȷ��
		u8 back; 		//�˳�
    void (*current_operation)(void); //��ǰ״̬Ӧ��ִ�еĲ���
} Menu_table;
 
//����UI
void home();
void weather();
void time();
void tip();
void information();
void  Menu_key_set(void);
 
void choice_I();
void choice_II();
void time_I();
void tip_I();
void information_I();
void weather_I();
void weather_II();
//void RTC_display();
 
#endif