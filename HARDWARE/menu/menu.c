#include "menu.h"
#include "oled.h"
#include "key.h"
#include "esp8266.h"

 
 
//UI界面
//主页
/****************************************************/
//UI库
 
/****************************************************/
 
void (*current_operation_index)();	 
 //城市选择界面
 /*				城市选择
			九江<
			长沙
*/
Menu_table  table[30]=
{
    {0,0,1,0,(*home)},	//一级界面（主页面） 索引，向下一个，确定，退出
		
    {1,2,5,0,(*weather)},	//二级界面 天气
    {2,3,6,0,(*time)},	//二级界面 时间
    {3,4,7,0,(*tip)},	//二级界面 提醒
    {4,1,8,0,(*information)},	//二级界面 信息
		
		{5,9,10,1,(*choice_I)},		//三级界面：城市选择 九江
		{6,6,6,2,(*time_I)},				//三级界面：时间显示
		{7,7,7,3,(*tip_I)},								//三级界面：提醒
		{8,8,8,4,(*information_I)},				//三级界面：作者和相关信息
		{9,5,11,1,(*choice_II)},		//三级界面：城市选择	长沙
		
		{10,10,10,5,(*weather_I)},		//四级界面：天气显示 九江
		{11,11,11,9,(*weather_II)},		//四级界面：天气显示 长沙

};
 
uint8_t  func_index = 0;	//主程序此时所在程序的索引值
 
void  Menu_key_set(void)
{
  if((KEY_Scan(1) == 1))  //B0按下==next
  { 
    func_index=table[func_index].next;	//按键next按下后的索引号
    OLED_Clear(); 
  }
	
  if((KEY_Scan(1) == 2))	//B1按下==enter
  {
    func_index=table[func_index].enter;	//按键enter按下后的索引号
    OLED_Clear();
  }
 
	if(KEY_Scan(1) == 3)
  {
    func_index=table[func_index].back;	//按键back按下后的索引号
    OLED_Clear(); 
  }
	
  current_operation_index=table[func_index].current_operation;	//执行当前索引号所对应的功能函数
  (*current_operation_index)();//执行当前操作函数
}
 
 //主界面
void home()
{
	base_jiemian();
}
 //二级指示天气
void weather()
{
	search_weather();
}
 //二级指示时间
void time()
{
	search_time();
}
 //二级指示提醒
void tip()
{
	search_tip();
}
 //二级指示信息
void information()
{
	search_information();
}
 
 


//三级城市选择	九江
void choice_I()
{
	choice_city_1();
}
//三级城市选择 长沙
void choice_II()
{
	choice_city_2();
}
//三级时间
void time_I()
{
	display_time();
}
//三级提醒
void tip_I()
{
	display_tip();
}
//三级信息
void information_I()
{
	display_information();
}
//四级天气 九江
void weather_I()
{
	display_weather_1();
}
//四级天气 长沙
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