
#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    	
#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	 

 					   

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_8)    //SCL IIC�ӿڵ�ʱ���ź�
#define OLED_SCLK_Set() GPIO_SetBits(GPIOB,GPIO_Pin_8)    

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_9)    //SDA IIC�ӿڵ������ź�
#define OLED_SDIN_Set() GPIO_SetBits(GPIOB,GPIO_Pin_9)

 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


void OLED_WR_Byte(unsigned dat,unsigned cmd);  
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_DisShowChar(u8 x,u8 y,u8 chr,u8 size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);
void fill_picture(unsigned char fill_Data);
void Picture();
void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);
void base_jiemian();
void wifi_connect();
void wifi_connect_success();
void wait();
void get_data();
void display_time(void);
void display_weather_1(void);
void display_weather_2(void);
void show_temp1();
void show_temp2();
void display_tip();
void IIC_Wait_Ack();
void search_information();
void search_weather();
void search_time();
void search_tip();
void display_information();
void week_judge();
void choice_city_1();
void choice_city_2();
void weather1_judge();
void weather2_judge();
void wifi_choice1();
void wifi_choice2();
#endif  
	 



