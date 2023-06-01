#ifndef __MENU_H
#define __MENU_H
 
#include "sys.h"

#define  u8 unsigned char
 

 
 
typedef struct
{
    u8 current;	//当前状态索引号
    u8 next; 		//向下一个
    u8 enter; 	//确定
		u8 back; 		//退出
    void (*current_operation)(void); //当前状态应该执行的操作
} Menu_table;
 
//界面UI
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