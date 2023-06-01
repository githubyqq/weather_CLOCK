#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"


//�ⲿ�ж�0�������
void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    KEY_Init();	 //	�����˿ڳ�ʼ��

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

    //GPIOB.0 �ж����Լ��жϳ�ʼ������   �����ش���
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0); //KEY0

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;									//0���ж���
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//�ж��¼�
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�����ش���
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									//�ж���ʹ��
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

    //GPIOB.1	  �ж����Լ��жϳ�ʼ������ �½��ش��� //KEY1
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);	//KEY1
  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;									//1���ж���
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;				//�ж��¼�
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�½��ش���
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;									////�ж���ʹ��
  	EXTI_Init(&EXTI_InitStructure);	  	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
 
}

////�ⲿ�ж�0������� 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY0==1)	 	 //KEY0����
	{				 
		LED0=!LED0;	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}
 
//�ⲿ�ж�1�������
void EXTI1_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY1==0)	  //����KEY1
	{
		
	}		 
	EXTI_ClearITPendingBit(EXTI_Line1);  //���LINE2�ϵ��жϱ�־λ  
}

 
