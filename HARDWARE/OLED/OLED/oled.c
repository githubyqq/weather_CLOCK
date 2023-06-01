#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"  	 
#include "delay.h"

extern int weather1_t;
extern int temperature1_t;
extern int weather_t;
extern int temperature_t;
extern int year,month,day,hour,min,sec;
extern int week_t;
void IIC_Start()
{

	OLED_SCLK_Set() ;
	OLED_SDIN_Set();
	OLED_SDIN_Clr();
	OLED_SCLK_Clr();
}


void IIC_Stop()
{
OLED_SCLK_Set() ;
//	OLED_SCLK_Clr();
	OLED_SDIN_Clr();
	OLED_SDIN_Set();
	
}

void IIC_Wait_Ack()
{

	//GPIOB->CRH &= 0XFFF0FFFF;	//设置PB12为上拉输入模式
	//GPIOB->CRH |= 0x00080000;
//	OLED_SDA = 1;
//	delay_us(1);
	//OLED_SCL = 1;
	//delay_us(50000);
/*	while(1)
	{
		if(!OLED_SDA)				//判断是否接收到OLED 应答信号
		{
			//GPIOB->CRH &= 0XFFF0FFFF;	//设置PB12为通用推免输出模式
			//GPIOB->CRH |= 0x00030000;
			return;
		}
	}
*/
	OLED_SCLK_Set() ;
	OLED_SCLK_Clr();
}
/**********************************************
// IIC Write byte
**********************************************/

void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	unsigned char m,da;
	da=IIC_Byte;
	OLED_SCLK_Clr();
	for(i=0;i<8;i++)		
	{
			m=da;
		//	OLED_SCLK_Clr();
		m=m&0x80;
		if(m==0x80)
		{OLED_SDIN_Set();}
		else OLED_SDIN_Clr();
			da=da<<1;
		OLED_SCLK_Set();
		OLED_SCLK_Clr();
		}


}
/**********************************************
// IIC Write Command
**********************************************/
void Write_IIC_Command(unsigned char IIC_Command)
{
   IIC_Start();
   Write_IIC_Byte(0x78);            //Slave address,SA0=0
	IIC_Wait_Ack();	
   Write_IIC_Byte(0x00);			//write command
	IIC_Wait_Ack();	
   Write_IIC_Byte(IIC_Command); 
	IIC_Wait_Ack();	
   IIC_Stop();
}
/**********************************************
// IIC Write Data
**********************************************/
void Write_IIC_Data(unsigned char IIC_Data)
{
   IIC_Start();
   Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
	IIC_Wait_Ack();	
   Write_IIC_Byte(0x40);			//write data
	IIC_Wait_Ack();	
   Write_IIC_Byte(IIC_Data);
	IIC_Wait_Ack();	
   IIC_Stop();
}
void OLED_WR_Byte(unsigned dat,unsigned cmd)
{
	if(cmd)
			{

   Write_IIC_Data(dat);
   
		}
	else {
   Write_IIC_Command(dat);
		
	}


}


/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		OLED_WR_Byte(0xb0+m,0);		//page0-page1
		OLED_WR_Byte(0x00,0);		//low column start address
		OLED_WR_Byte(0x10,0);		//high column start address
		for(n=0;n<128;n++)
			{
				OLED_WR_Byte(fill_Data,1);
			}
	}
}


/***********************Delay****************************************/
void Delay_50ms(unsigned int Del_50ms)
{
	unsigned int m;
	for(;Del_50ms>0;Del_50ms--)
		for(m=6245;m>0;m--);
}

void Delay_1ms(unsigned int Del_1ms)
{
	unsigned char j;
	while(Del_1ms--)
	{	
		for(j=0;j<123;j++);
	}
}



	void OLED_Set_Pos(unsigned char x, unsigned char y) 
{ 	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD); 
}   	  
//开启OLED显示    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //更新显示
}
void OLED_On(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA); 
	} //更新显示
}


//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~7
//mode:0,反白显示;1,正常显示				 
//size:选择字体 16/12 
 
void OLED_DisShowChar(u8 x,u8 y,u8 chr,u8 size)
{      	
	  unsigned char c=0,i=0;	
		c=chr-' ';//得到偏移后的值			
		if(x>Max_Column-1){x=0;y=y+2;}//#define Max_Column	128
		if(size ==16)
			{
			OLED_Set_Pos(x,y);	//先设置X，Y的坐标位置
			for(i=0;i<8;i++){
			  OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);//发送第一页的上半部分
			}
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++){
			  OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);//发送第一页的下半部分
			}
			
			}
			else if(size == 8){	
 
				OLED_Set_Pos(x,y+1);
				for(i=0;i<6;i++){
					OLED_WR_Byte(F6x8[c][i],OLED_DATA);
				}		
			}			
			else if(size ==24)
{
				OLED_Set_Pos(x,y);	
				for(i=0;i<16;i++){
					OLED_WR_Byte(F8X16[c*48+i],OLED_DATA);
				}
				OLED_Set_Pos(x,y+1);	
				for(i=0;i<16;i++){
					OLED_WR_Byte(F8X16[c*48+i+16],OLED_DATA);
				}
				OLED_Set_Pos(x,y+2);	
				for(i=0;i<16;i++){
					OLED_WR_Byte(F8X16[c*48+i+32],OLED_DATA);
				}
			}
}
//m^n函数
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_DisShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_DisShowChar(x+(size2/2)*t,y,temp+'0',size2); 
	}
} 
//显示一个字符号串
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 Char_Size)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{		OLED_DisShowChar(x,y,chr[j],Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			j++;
	}
}
//显示汉字
void OLED_ShowCHinese(u8 x,u8 y,u8 no)
{      			    
	u8 t,adder=0;
	OLED_Set_Pos(x,y);	
    for(t=0;t<16;t++)
		{
				OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
				adder+=1;
     }	
		OLED_Set_Pos(x,y+1);	
    for(t=0;t<16;t++)
			{	
				OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
				adder+=1;
      }					
}

/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
	    }
	}
} 

//初始化SSD1306					    
void OLED_Init(void)
{ 	 
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PC端口时钟

 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MH

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;				 //PC6,7 OUT推挽输出
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);						 //PC6,7 OUT  输出高


    delay_ms(200);

    
  OLED_WR_Byte(0xAE,OLED_CMD);	//--turn off oled panel
	OLED_WR_Byte(0x00,OLED_CMD);	//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);	//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);	//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);	//--set contrast control register
	OLED_WR_Byte(0xCF,OLED_CMD); 	// Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1,OLED_CMD);	//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	OLED_WR_Byte(0xC8,OLED_CMD);	//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	OLED_WR_Byte(0xA6,OLED_CMD);	//--set normal display
	OLED_WR_Byte(0xA8,OLED_CMD);	//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f,OLED_CMD);	//--1/64 duty
	OLED_WR_Byte(0xD3,OLED_CMD);	//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);	//-not offset
	OLED_WR_Byte(0xd5,OLED_CMD);	//--set display clock divide ratio/oscillator frequency
	OLED_WR_Byte(0x80,OLED_CMD);	//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9,OLED_CMD);	//--set pre-charge period
	OLED_WR_Byte(0xF1,OLED_CMD);	//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA,OLED_CMD);	//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);	//--set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);	//Set VCOM Deselect Level
	OLED_WR_Byte(0x20,OLED_CMD);	//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02,OLED_CMD);	//
	OLED_WR_Byte(0x8D,OLED_CMD);	//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);	//--set(0x10) disable
	OLED_WR_Byte(0xA4,OLED_CMD);	// Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);	// Disable Inverse Display On (0xa6/a7) 
	OLED_WR_Byte(0xAF,OLED_CMD);	//--turn on oled panel
	
	OLED_WR_Byte(0xAF,OLED_CMD); 	//display ON
	OLED_Clear();
	OLED_Set_Pos(0,0);
}

void base_jiemian()
{//欢迎使用天气时钟 进入系统
	OLED_ShowCHinese(0,0,0);			
	OLED_ShowCHinese(16,0,1);
	OLED_ShowCHinese(32,0,2);
	OLED_ShowCHinese(48,0,3);
	OLED_ShowCHinese(64,0,4);
	OLED_ShowCHinese(80,0,5);
	OLED_ShowCHinese(96,0,6);
	OLED_ShowCHinese(112,0,7);
	OLED_ShowCHinese(32,4,52);
	OLED_ShowCHinese(48,4,53);
	OLED_ShowCHinese(64,4,54);
	OLED_ShowCHinese(80,4,55);
	OLED_DrawBMP(96,4,112,6,BMP37);
}

void wifi_connect()
{
	//正在联网
	OLED_ShowCHinese(32,2,8);
	OLED_ShowCHinese(48,2,9);
	OLED_ShowCHinese(64,2,10);
	OLED_ShowCHinese(80,2,11);
}

void wifi_connect_success()
{
	//联网成功
	OLED_ShowCHinese(32,2,10);
	OLED_ShowCHinese(48,2,11);
	OLED_ShowCHinese(64,2,12);
	OLED_ShowCHinese(80,2,13);
}
void wait()
{
	//请耐心等待
	OLED_ShowCHinese(24,4,14);
	OLED_ShowCHinese(40,4,15);
	OLED_ShowCHinese(56,4,16);
	OLED_ShowCHinese(72,4,17);
	OLED_ShowCHinese(88,4,18);
}

void get_data()
{
	//正在获取数据
	OLED_ShowCHinese(16,4,19);
	OLED_ShowCHinese(32,4,20);
	OLED_ShowCHinese(48,4,21);
	OLED_ShowCHinese(64,4,22);
	OLED_ShowCHinese(80,4,23);
	OLED_ShowCHinese(96,4,24);
}

void show_temp1()
{
	//显示温度数字
	int temp_ten=0;
	int temp_one=0;
	temp_ten=temperature_t/10;
	temp_one=temperature_t%10;
	OLED_ShowNum(40,4,temp_ten,1,16);		//温度十位
	OLED_ShowNum(48,4,temp_one,1,16);		//温度个位
}

void show_temp2()
{
	//显示温度数字
	int temp_ten=0;
	int temp_one=0;
	temp_ten=temperature1_t/10;
	temp_one=temperature1_t%10;
	OLED_ShowNum(40,4,temp_ten,1,16);		//温度十位
	OLED_ShowNum(48,4,temp_one,1,16);		//温度个位
}


void weather1_judge()
{
	//判断天气并显示
	switch(weather_t)
	{
		//小雨
		case 13:	OLED_ShowCHinese(40,6,29);
							OLED_ShowCHinese(56,6,30);
							OLED_DrawBMP(112,6,128,8,BMP13);
							break;
		//多云
		case 4 :	OLED_ShowCHinese(40,6,27);
							OLED_ShowCHinese(56,6,28);
							OLED_DrawBMP(112,6,128,8,BMP4);
							break;
		//夜晚晴
		case 1 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP1);
							break;
		//阴
		case 9 :	OLED_ShowCHinese(40,6,71);
							OLED_DrawBMP(112,6,128,8,BMP9);
							break;
		//白天晴
		case 0 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP0);
							break;
		default:
							break;

	}
		
}

void weather2_judge()
{
	//判断天气并显示
	switch(weather1_t)
	{
		//小雨
		case 13:	OLED_ShowCHinese(40,6,29);
							OLED_ShowCHinese(56,6,30);
							OLED_DrawBMP(112,6,128,8,BMP13);
							break;
		//多云
		case 4 :	OLED_ShowCHinese(40,6,27);
							OLED_ShowCHinese(56,6,28);
							OLED_DrawBMP(112,6,128,8,BMP4);
							break;
		//晴
		case 1 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP1);
							break;
		//阴
		case 9 :	OLED_ShowCHinese(40,6,71);
							OLED_DrawBMP(112,6,128,8,BMP9);
							break;
		//白天晴
		case 0 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP0);
							break;
		default:
							break;

	}
		
}


//二级指示天气
void search_weather()
{
	OLED_ShowCHinese(24,0,56);
	OLED_ShowCHinese(40,0,57);
	OLED_ShowCHinese(56,0,4);
	OLED_ShowCHinese(72,0,5);
	OLED_DrawBMP(88,0,104,2,BMP37);
	
	OLED_ShowCHinese(24,2,56);
	OLED_ShowCHinese(40,2,57);
	OLED_ShowCHinese(56,2,58);
	OLED_ShowCHinese(72,2,59);
	
	OLED_ShowCHinese(24,4,56);
	OLED_ShowCHinese(40,4,57);
	OLED_ShowCHinese(56,4,50);
	OLED_ShowCHinese(72,4,51);
	
	OLED_ShowCHinese(24,6,56);
	OLED_ShowCHinese(40,6,57);
	OLED_ShowCHinese(56,6,60);
	OLED_ShowCHinese(72,6,61);
}
//二级指示时间
void search_time()
{
	OLED_ShowCHinese(24,0,56);
	OLED_ShowCHinese(40,0,57);
	OLED_ShowCHinese(56,0,4);
	OLED_ShowCHinese(72,0,5);
	
	OLED_ShowCHinese(24,2,56);
	OLED_ShowCHinese(40,2,57);
	OLED_ShowCHinese(56,2,58);
	OLED_ShowCHinese(72,2,59);
	OLED_DrawBMP(88,2,104,4,BMP37);
	
	OLED_ShowCHinese(24,4,56);
	OLED_ShowCHinese(40,4,57);
	OLED_ShowCHinese(56,4,50);
	OLED_ShowCHinese(72,4,51);
	
	OLED_ShowCHinese(24,6,56);
	OLED_ShowCHinese(40,6,57);
	OLED_ShowCHinese(56,6,60);
	OLED_ShowCHinese(72,6,61);
}
//二级指示提示
void search_tip()
{
	OLED_ShowCHinese(24,0,56);
	OLED_ShowCHinese(40,0,57);
	OLED_ShowCHinese(56,0,4);
	OLED_ShowCHinese(72,0,5);
	
	OLED_ShowCHinese(24,2,56);
	OLED_ShowCHinese(40,2,57);
	OLED_ShowCHinese(56,2,58);
	OLED_ShowCHinese(72,2,59);
	
	OLED_ShowCHinese(24,4,56);
	OLED_ShowCHinese(40,4,57);
	OLED_ShowCHinese(56,4,50);
	OLED_ShowCHinese(72,4,51);
	OLED_DrawBMP(88,4,104,6,BMP37);
	
	OLED_ShowCHinese(24,6,56);
	OLED_ShowCHinese(40,6,57);
	OLED_ShowCHinese(56,6,60);
	OLED_ShowCHinese(72,6,61);
}
//二级指示信息
void search_information()
{
	OLED_ShowCHinese(24,0,56);
	OLED_ShowCHinese(40,0,57);
	OLED_ShowCHinese(56,0,4);
	OLED_ShowCHinese(72,0,5);
	
	OLED_ShowCHinese(24,2,56);
	OLED_ShowCHinese(40,2,57);
	OLED_ShowCHinese(56,2,58);
	OLED_ShowCHinese(72,2,59);
	
	OLED_ShowCHinese(24,4,56);
	OLED_ShowCHinese(40,4,57);
	OLED_ShowCHinese(56,4,50);
	OLED_ShowCHinese(72,4,51);
	
	OLED_ShowCHinese(24,6,56);
	OLED_ShowCHinese(40,6,57);
	OLED_ShowCHinese(56,6,60);
	OLED_ShowCHinese(72,6,61);
		OLED_DrawBMP(88,6,104,8,BMP37);
}
//三级城市选择1
void choice_city_1()
{
	OLED_ShowCHinese(32,0,87);	//城
	OLED_ShowCHinese(48,0,88);	//市
	OLED_ShowCHinese(64,0,89);	//选
	OLED_ShowCHinese(80,0,90);	//择
	
	OLED_ShowCHinese(0,2,25);		//九
	OLED_ShowCHinese(16,2,26);	//江
	OLED_ShowCHinese(32,2,88);	//市
	
	OLED_ShowCHinese(0,4,85);	//长
	OLED_ShowCHinese(16,4,86);	//沙
	OLED_ShowCHinese(32,4,88);	//市
	OLED_DrawBMP(48,2,64,4,BMP37);
}
//三级城市选择2
void choice_city_2()
{
	OLED_ShowCHinese(32,0,87);	//城
	OLED_ShowCHinese(48,0,88);	//市
	OLED_ShowCHinese(64,0,89);	//选
	OLED_ShowCHinese(80,0,90);	//择
	
	OLED_ShowCHinese(0,2,25);		//九
	OLED_ShowCHinese(16,2,26);	//江
	OLED_ShowCHinese(32,2,88);	//市
	
	OLED_ShowCHinese(0,4,85);	//长
	OLED_ShowCHinese(16,4,86);	//沙
	OLED_ShowCHinese(32,4,88);	//市
	OLED_DrawBMP(48,4,64,6,BMP37);
}
//四级天气 1
void display_weather_1(void)
{
	OLED_ShowCHinese(16,0,81);		//江
	OLED_ShowCHinese(32,0,82);		//西
	OLED_ShowCHinese(48,0,83);		//省
	OLED_ShowCHinese(64,0,25);		//九
	OLED_ShowCHinese(80,0,26);		//江
	OLED_ShowCHinese(96,0,88);		//市
	OLED_ShowCHinese(0,6,4);			//天
	OLED_ShowCHinese(16,6,5);			//气
	OLED_DisShowChar(32,6,58,8);	//：
	OLED_ShowCHinese(0,4,31);			//温
	OLED_ShowCHinese(16,4,32);		//度
	OLED_DisShowChar(32,4,58,8);	//：
	show_temp1();
	weather1_judge();
}
//四级天气 2
void display_weather_2(void)
{
	OLED_ShowCHinese(16,0,91);		//湖
	OLED_ShowCHinese(32,0,92);		//南
	OLED_ShowCHinese(48,0,83);		//省
	OLED_ShowCHinese(64,0,85);		//长
	OLED_ShowCHinese(80,0,86);		//沙
	OLED_ShowCHinese(96,0,88);		//市
	OLED_ShowCHinese(0,6,4);			//天
	OLED_ShowCHinese(16,6,5);			//气
	OLED_DisShowChar(32,6,58,8);	//：
	OLED_ShowCHinese(0,4,31);			//温
	OLED_ShowCHinese(16,4,32);		//度
	OLED_DisShowChar(32,4,58,8);	//：
	show_temp2();
	weather2_judge();
}
//判断星期
void week_judge()
{
	//判断星期几并显示
	switch(week_t)
	{
		case 1:		OLED_ShowCHinese(72,5,74);
							break;
		case 2:		OLED_ShowCHinese(72,5,75);
							break;
		case 3:		OLED_ShowCHinese(72,5,76);
							break;
		case 4:		OLED_ShowCHinese(72,5,77);
							break;
		case 5:		OLED_ShowCHinese(72,5,78);
							break;
		case 6:		OLED_ShowCHinese(72,5,79);
							break;
		case 7:		OLED_ShowCHinese(72,5,80);
							break;
		default:
							break;

	}
		
}

//三级时间
void display_time(void)
{
	if(month>=10 && day>=10)
	{
		OLED_ShowNum(24,0,year,4,16);
		OLED_DisShowChar(56,0,'/',16);
		OLED_ShowNum(64,0,month,2,16);
		OLED_DisShowChar(80,0,'/',16);
		OLED_ShowNum(88,0,day,2,16);
	}
	else if(month<10 && day>=10)
	{
		OLED_ShowNum(24,0,year,4,16);
		OLED_DisShowChar(56,0,'/',16);
		OLED_ShowNum(64,0,month,1,16);
		OLED_DisShowChar(72,0,'/',16);
		OLED_ShowNum(80,0,day,2,16);
	}
	else if(month>=10 && day<10)
	{
		OLED_ShowNum(24,0,year,4,16);
		OLED_DisShowChar(56,0,'/',16);
		OLED_ShowNum(64,0,month,2,16);
		OLED_DisShowChar(80,0,'/',16);
		OLED_ShowNum(88,0,day,1,16);
	}
	if(month<10 && day<10)
	{
		OLED_ShowNum(24,0,year,4,16);
		OLED_DisShowChar(56,0,'/',16);
		OLED_ShowNum(64,0,month,1,16);
		OLED_DisShowChar(72,0,'/',16);
		OLED_ShowNum(80,0,0,1,16);
		OLED_ShowNum(88,0,day,1,16);
	}
	if(sec>=10)
	{
		OLED_ShowNum(80,3,sec,2,16);
	}
	else if(sec<10)
	{
		OLED_ShowNum(80,3,0,1,16);
		OLED_ShowNum(88,3,sec,1,16);
	}
	
	if(min>=10)
	{
		OLED_ShowNum(56,3,min,2,16);
	}
	else if(min<10)
	{
		OLED_ShowNum(56,3,0,1,16);
		OLED_ShowNum(64,3,min,1,16);
	}
	
	if(hour>=10)
	{
		OLED_ShowNum(32,3,hour,2,16);
	}
	else if(hour<10)
	{
		OLED_ShowNum(32,3,0,1,16);
		OLED_ShowNum(40,3,min,1,16);
	}
	OLED_DisShowChar(48,3,':',16);
	OLED_DisShowChar(72,3,':',16);
	OLED_ShowCHinese(40,5,72);
	OLED_ShowCHinese(56,5,73);
	week_judge();
	
}
//三级提示
void display_tip()
{
	OLED_ShowCHinese(16,0,33);
	OLED_ShowCHinese(32,0,34);
	OLED_ShowCHinese(48,0,35);
	OLED_ShowCHinese(64,0,36);
	OLED_ShowCHinese(80,0,37);
	OLED_ShowCHinese(96,0,38);
	
	OLED_ShowCHinese(16,2,39);
	OLED_ShowCHinese(32,2,40);
	OLED_ShowCHinese(48,2,41);
	OLED_ShowCHinese(64,2,42);
	OLED_ShowCHinese(80,2,43);
	OLED_ShowCHinese(96,2,44);
	
	OLED_ShowString(0,6,"--",16);
	OLED_ShowCHinese(16,6,45);
	OLED_ShowCHinese(32,6,46);
	OLED_ShowCHinese(48,6,47);
	OLED_ShowCHinese(64,6,48);
	OLED_ShowCHinese(80,6,49);
	OLED_ShowCHinese(96,6,50);
	OLED_ShowCHinese(112,6,51);
}
//三级信息
void display_information()
{
	OLED_ShowCHinese(0,0,62);		//出
	OLED_ShowCHinese(16,0,63);		//版
	OLED_ShowCHinese(32,0,64);			//人
	OLED_DisShowChar(48,0,58,8);	//：
	OLED_ShowCHinese(56,0,65);		//余
	OLED_ShowCHinese(72,0,66);		//清
	OLED_ShowCHinese(88,0,67);			//强
	OLED_ShowCHinese(0,2,62);		//出
	OLED_ShowCHinese(16,2,63);		//版
	OLED_ShowCHinese(32,2,58);		//时
	OLED_ShowCHinese(48,2,59);		//间
	OLED_DisShowChar(64,2,58,8);	//：
	OLED_ShowString(72,2,"2023/5/25",16);
	OLED_ShowCHinese(0,6,68);		//微
	OLED_ShowCHinese(16,6,69);		//信
	OLED_DisShowChar(32,6,58,8);	//：
	OLED_ShowString(40,6,"yqq0833",16);
}
	

