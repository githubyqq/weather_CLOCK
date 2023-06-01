#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"
/*

����Ϊ0���ɿ�Ϊ1
*/


//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTA,PORTEʱ��
	
	
	//��ʼ�� KEY0-->GPIOB.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//KEY0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.0

	
	//��ʼ�� KEY1-->GPIOB.1   ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;//KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.1
	
	//��ʼ�� KEY1-->GPIOB.10   ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;//KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.1

}
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==0||KEY1==0||KEY2==0))
	{
		delay_ms(70);//ȥ���� 
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
	}
	else if(KEY0==1&&KEY1==1&&KEY2==1)
		key_up=1; 	    
 	return 0;// �ް�������
}
