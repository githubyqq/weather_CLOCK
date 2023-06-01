#include "menu.h"
#include "oled.h"
#include "key.h"
#include "esp8266.h"

 
 
//UI����
//��ҳ
/****************************************************/
//UI��
 
/****************************************************/
 
void (*current_operation_index)();	 
 //����ѡ�����
 /*				����ѡ��
			�Ž�<
			��ɳ
*/
Menu_table  table[30]=
{
    {0,0,1,0,(*home)},	//һ�����棨��ҳ�棩 ����������һ����ȷ�����˳�
		
    {1,2,5,0,(*weather)},	//�������� ����
    {2,3,6,0,(*time)},	//�������� ʱ��
    {3,4,7,0,(*tip)},	//�������� ����
    {4,1,8,0,(*information)},	//�������� ��Ϣ
		
		{5,9,10,1,(*choice_I)},		//�������棺����ѡ�� �Ž�
		{6,6,6,2,(*time_I)},				//�������棺ʱ����ʾ
		{7,7,7,3,(*tip_I)},								//�������棺����
		{8,8,8,4,(*information_I)},				//�������棺���ߺ������Ϣ
		{9,5,11,1,(*choice_II)},		//�������棺����ѡ��	��ɳ
		
		{10,10,10,5,(*weather_I)},		//�ļ����棺������ʾ �Ž�
		{11,11,11,9,(*weather_II)},		//�ļ����棺������ʾ ��ɳ

};
 
uint8_t  func_index = 0;	//�������ʱ���ڳ��������ֵ
 
void  Menu_key_set(void)
{
  if((KEY_Scan(1) == 1))  //B0����==next
  { 
    func_index=table[func_index].next;	//����next���º��������
    OLED_Clear(); 
  }
	
  if((KEY_Scan(1) == 2))	//B1����==enter
  {
    func_index=table[func_index].enter;	//����enter���º��������
    OLED_Clear();
  }
 
	if(KEY_Scan(1) == 3)
  {
    func_index=table[func_index].back;	//����back���º��������
    OLED_Clear(); 
  }
	
  current_operation_index=table[func_index].current_operation;	//ִ�е�ǰ����������Ӧ�Ĺ��ܺ���
  (*current_operation_index)();//ִ�е�ǰ��������
}
 
 //������
void home()
{
	base_jiemian();
}
 //����ָʾ����
void weather()
{
	search_weather();
}
 //����ָʾʱ��
void time()
{
	search_time();
}
 //����ָʾ����
void tip()
{
	search_tip();
}
 //����ָʾ��Ϣ
void information()
{
	search_information();
}
 
 


//��������ѡ��	�Ž�
void choice_I()
{
	choice_city_1();
}
//��������ѡ�� ��ɳ
void choice_II()
{
	choice_city_2();
}
//����ʱ��
void time_I()
{
	display_time();
}
//��������
void tip_I()
{
	display_tip();
}
//������Ϣ
void information_I()
{
	display_information();
}
//�ļ����� �Ž�
void weather_I()
{
	display_weather_1();
}
//�ļ����� ��ɳ
void weather_II()
{
	display_weather_2();
}

 
 
// 
//void RTC_display()				//RTC????
//{
//	  /* Get the RTC current Time */
//	  HAL_RTC_GetTime(&hrtc, &GetTime, RTC_FORMAT_BIN);
//      /* Get the RTC current Date */
//    HAL_RTC_GetDate(&hrtc, &GetData, RTC_FORMAT_BIN);
//	
//		/* Display date Format : yy/mm/dd */
//	
//        /* Display time Format : hh:mm:ss */
//		OLED_ShowNum(40,0,GetTime.Hours,2,16);				//hour
//		OLED_ShowString(57,0,":",16);	
//		OLED_ShowNum(66,0,GetTime.Minutes,2,16);			//min
//		OLED_ShowString(83,0,":",16);	
//		OLED_ShowNum(93,0,GetTime.Seconds,2,16);			//seconds
//}