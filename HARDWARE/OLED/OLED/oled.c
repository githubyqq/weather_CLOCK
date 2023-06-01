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

	//GPIOB->CRH &= 0XFFF0FFFF;	//����PB12Ϊ��������ģʽ
	//GPIOB->CRH |= 0x00080000;
//	OLED_SDA = 1;
//	delay_us(1);
	//OLED_SCL = 1;
	//delay_us(50000);
/*	while(1)
	{
		if(!OLED_SDA)				//�ж��Ƿ���յ�OLED Ӧ���ź�
		{
			//GPIOB->CRH &= 0XFFF0FFFF;	//����PB12Ϊͨ���������ģʽ
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
//����OLED��ʾ    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//�ر�OLED��ʾ     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	  
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
		OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //������ʾ
}
void OLED_On(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
		OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA); 
	} //������ʾ
}


//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~7
//mode:0,������ʾ;1,������ʾ				 
//size:ѡ������ 16/12 
 
void OLED_DisShowChar(u8 x,u8 y,u8 chr,u8 size)
{      	
	  unsigned char c=0,i=0;	
		c=chr-' ';//�õ�ƫ�ƺ��ֵ			
		if(x>Max_Column-1){x=0;y=y+2;}//#define Max_Column	128
		if(size ==16)
			{
			OLED_Set_Pos(x,y);	//������X��Y������λ��
			for(i=0;i<8;i++){
			  OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);//���͵�һҳ���ϰ벿��
			}
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++){
			  OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);//���͵�һҳ���°벿��
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
//m^n����
u32 oled_pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//��ʾ2������
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//mode:ģʽ	0,���ģʽ;1,����ģʽ
//num:��ֵ(0~4294967295);	 		  
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
//��ʾһ���ַ��Ŵ�
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
//��ʾ����
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

/***********������������ʾ��ʾBMPͼƬ128��64��ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7*****************/
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

//��ʼ��SSD1306					    
void OLED_Init(void)
{ 	 
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PC�˿�ʱ��

 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MH

 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;				 //PC6,7 OUT�������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);						 //PC6,7 OUT  �����


    delay_ms(200);

    
  OLED_WR_Byte(0xAE,OLED_CMD);	//--turn off oled panel
	OLED_WR_Byte(0x00,OLED_CMD);	//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);	//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);	//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);	//--set contrast control register
	OLED_WR_Byte(0xCF,OLED_CMD); 	// Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1,OLED_CMD);	//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
	OLED_WR_Byte(0xC8,OLED_CMD);	//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
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
{//��ӭʹ������ʱ�� ����ϵͳ
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
	//��������
	OLED_ShowCHinese(32,2,8);
	OLED_ShowCHinese(48,2,9);
	OLED_ShowCHinese(64,2,10);
	OLED_ShowCHinese(80,2,11);
}

void wifi_connect_success()
{
	//�����ɹ�
	OLED_ShowCHinese(32,2,10);
	OLED_ShowCHinese(48,2,11);
	OLED_ShowCHinese(64,2,12);
	OLED_ShowCHinese(80,2,13);
}
void wait()
{
	//�����ĵȴ�
	OLED_ShowCHinese(24,4,14);
	OLED_ShowCHinese(40,4,15);
	OLED_ShowCHinese(56,4,16);
	OLED_ShowCHinese(72,4,17);
	OLED_ShowCHinese(88,4,18);
}

void get_data()
{
	//���ڻ�ȡ����
	OLED_ShowCHinese(16,4,19);
	OLED_ShowCHinese(32,4,20);
	OLED_ShowCHinese(48,4,21);
	OLED_ShowCHinese(64,4,22);
	OLED_ShowCHinese(80,4,23);
	OLED_ShowCHinese(96,4,24);
}

void show_temp1()
{
	//��ʾ�¶�����
	int temp_ten=0;
	int temp_one=0;
	temp_ten=temperature_t/10;
	temp_one=temperature_t%10;
	OLED_ShowNum(40,4,temp_ten,1,16);		//�¶�ʮλ
	OLED_ShowNum(48,4,temp_one,1,16);		//�¶ȸ�λ
}

void show_temp2()
{
	//��ʾ�¶�����
	int temp_ten=0;
	int temp_one=0;
	temp_ten=temperature1_t/10;
	temp_one=temperature1_t%10;
	OLED_ShowNum(40,4,temp_ten,1,16);		//�¶�ʮλ
	OLED_ShowNum(48,4,temp_one,1,16);		//�¶ȸ�λ
}


void weather1_judge()
{
	//�ж���������ʾ
	switch(weather_t)
	{
		//С��
		case 13:	OLED_ShowCHinese(40,6,29);
							OLED_ShowCHinese(56,6,30);
							OLED_DrawBMP(112,6,128,8,BMP13);
							break;
		//����
		case 4 :	OLED_ShowCHinese(40,6,27);
							OLED_ShowCHinese(56,6,28);
							OLED_DrawBMP(112,6,128,8,BMP4);
							break;
		//ҹ����
		case 1 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP1);
							break;
		//��
		case 9 :	OLED_ShowCHinese(40,6,71);
							OLED_DrawBMP(112,6,128,8,BMP9);
							break;
		//������
		case 0 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP0);
							break;
		default:
							break;

	}
		
}

void weather2_judge()
{
	//�ж���������ʾ
	switch(weather1_t)
	{
		//С��
		case 13:	OLED_ShowCHinese(40,6,29);
							OLED_ShowCHinese(56,6,30);
							OLED_DrawBMP(112,6,128,8,BMP13);
							break;
		//����
		case 4 :	OLED_ShowCHinese(40,6,27);
							OLED_ShowCHinese(56,6,28);
							OLED_DrawBMP(112,6,128,8,BMP4);
							break;
		//��
		case 1 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP1);
							break;
		//��
		case 9 :	OLED_ShowCHinese(40,6,71);
							OLED_DrawBMP(112,6,128,8,BMP9);
							break;
		//������
		case 0 :	OLED_ShowCHinese(40,6,70);
							OLED_DrawBMP(112,6,128,8,BMP0);
							break;
		default:
							break;

	}
		
}


//����ָʾ����
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
//����ָʾʱ��
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
//����ָʾ��ʾ
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
//����ָʾ��Ϣ
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
//��������ѡ��1
void choice_city_1()
{
	OLED_ShowCHinese(32,0,87);	//��
	OLED_ShowCHinese(48,0,88);	//��
	OLED_ShowCHinese(64,0,89);	//ѡ
	OLED_ShowCHinese(80,0,90);	//��
	
	OLED_ShowCHinese(0,2,25);		//��
	OLED_ShowCHinese(16,2,26);	//��
	OLED_ShowCHinese(32,2,88);	//��
	
	OLED_ShowCHinese(0,4,85);	//��
	OLED_ShowCHinese(16,4,86);	//ɳ
	OLED_ShowCHinese(32,4,88);	//��
	OLED_DrawBMP(48,2,64,4,BMP37);
}
//��������ѡ��2
void choice_city_2()
{
	OLED_ShowCHinese(32,0,87);	//��
	OLED_ShowCHinese(48,0,88);	//��
	OLED_ShowCHinese(64,0,89);	//ѡ
	OLED_ShowCHinese(80,0,90);	//��
	
	OLED_ShowCHinese(0,2,25);		//��
	OLED_ShowCHinese(16,2,26);	//��
	OLED_ShowCHinese(32,2,88);	//��
	
	OLED_ShowCHinese(0,4,85);	//��
	OLED_ShowCHinese(16,4,86);	//ɳ
	OLED_ShowCHinese(32,4,88);	//��
	OLED_DrawBMP(48,4,64,6,BMP37);
}
//�ļ����� 1
void display_weather_1(void)
{
	OLED_ShowCHinese(16,0,81);		//��
	OLED_ShowCHinese(32,0,82);		//��
	OLED_ShowCHinese(48,0,83);		//ʡ
	OLED_ShowCHinese(64,0,25);		//��
	OLED_ShowCHinese(80,0,26);		//��
	OLED_ShowCHinese(96,0,88);		//��
	OLED_ShowCHinese(0,6,4);			//��
	OLED_ShowCHinese(16,6,5);			//��
	OLED_DisShowChar(32,6,58,8);	//��
	OLED_ShowCHinese(0,4,31);			//��
	OLED_ShowCHinese(16,4,32);		//��
	OLED_DisShowChar(32,4,58,8);	//��
	show_temp1();
	weather1_judge();
}
//�ļ����� 2
void display_weather_2(void)
{
	OLED_ShowCHinese(16,0,91);		//��
	OLED_ShowCHinese(32,0,92);		//��
	OLED_ShowCHinese(48,0,83);		//ʡ
	OLED_ShowCHinese(64,0,85);		//��
	OLED_ShowCHinese(80,0,86);		//ɳ
	OLED_ShowCHinese(96,0,88);		//��
	OLED_ShowCHinese(0,6,4);			//��
	OLED_ShowCHinese(16,6,5);			//��
	OLED_DisShowChar(32,6,58,8);	//��
	OLED_ShowCHinese(0,4,31);			//��
	OLED_ShowCHinese(16,4,32);		//��
	OLED_DisShowChar(32,4,58,8);	//��
	show_temp2();
	weather2_judge();
}
//�ж�����
void week_judge()
{
	//�ж����ڼ�����ʾ
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

//����ʱ��
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
//������ʾ
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
//������Ϣ
void display_information()
{
	OLED_ShowCHinese(0,0,62);		//��
	OLED_ShowCHinese(16,0,63);		//��
	OLED_ShowCHinese(32,0,64);			//��
	OLED_DisShowChar(48,0,58,8);	//��
	OLED_ShowCHinese(56,0,65);		//��
	OLED_ShowCHinese(72,0,66);		//��
	OLED_ShowCHinese(88,0,67);			//ǿ
	OLED_ShowCHinese(0,2,62);		//��
	OLED_ShowCHinese(16,2,63);		//��
	OLED_ShowCHinese(32,2,58);		//ʱ
	OLED_ShowCHinese(48,2,59);		//��
	OLED_DisShowChar(64,2,58,8);	//��
	OLED_ShowString(72,2,"2023/5/25",16);
	OLED_ShowCHinese(0,6,68);		//΢
	OLED_ShowCHinese(16,6,69);		//��
	OLED_DisShowChar(32,6,58,8);	//��
	OLED_ShowString(40,6,"yqq0833",16);
}
	

