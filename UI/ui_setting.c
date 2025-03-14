#include "ui_setting.h"


static void change_pin(void);
static void add_fr(int id);
static void del_fr(void);

static uint8_t input_id(void);

void ui_setting(void)
{
	 int ret = 0;
	 int pin_data=0;
	int id=0;
	OLED_ShowString(10,20,(uint8_t*)"1:change pin",8,1);	
	OLED_ShowString(10,30,(uint8_t*)"2:add finger",8,1);	
	OLED_ShowString(10,40,(uint8_t*)"3:delete finger",8,1);	
	OLED_ShowString(10,50,(uint8_t*)"4:back home",8,1);	
  OLED_Refresh();
	
	while(1)
	{
			OLED_ShowString(10,20,(uint8_t*)"1:change pin",8,1);	
			OLED_ShowString(10,30,(uint8_t*)"2:add finger",8,1);	
			OLED_ShowString(10,40,(uint8_t*)"3:delete finger",8,1);	
			OLED_ShowString(10,50,(uint8_t*)"4:back home",8,1);	
			OLED_Refresh();
		  	pin_data =MatrixKey();
			  if(pin_data>0)
				{  
					  switch(pin_data)
						{
							case 1:
								OLED_Clear();
							  change_pin();
								break;
							case 2:
								OLED_Clear();
							  id = input_id();
								add_fr(id);
								break;
							case 3:
								OLED_Clear();
						    del_fr();
								break;
							case 5:  //数字为4
								ret = 1;
								OLED_Clear();
								break;
						}
				}
				
				if(ret)
					break;
	}
	
	
}

static void change_pin(void)
{
	  uint8_t one_pin[6],two_pin[6];
	  OLED_ShowString(0,0,(uint8_t*)"input pin first",8,1);	
		OLED_Refresh();
		ui_pin(one_pin,6);
	  for(int i=0;i<3;i++)
		{
			 OLED_Clear();
			 OLED_ShowString(0,0,(uint8_t*)"ensure the pin",8,1);			
			 OLED_Refresh();
			 ui_pin(two_pin,6); 
			 if(memcmp(one_pin,two_pin,6)==0)
			 {
				  memcpy(open_pin,two_pin,6);
					OLED_Clear();
					OLED_ShowString(20,0,(uint8_t*)"pin change ok",8,1);			
					OLED_Refresh();
					HAL_Delay(1000);
				  return;
			 }
			 
		}
		
		//
		OLED_Clear();
		OLED_ShowString(0,0,(uint8_t*)"pin compare error",8,1);			
		OLED_Refresh();
		HAL_Delay(1000);
}



static uint8_t input_id(void)
{
	 char show_pin[10]={0};
	  int pin_data=0,position=0;
			uint8_t pin_array[2];
		memset(pin_array,0,2);
	 			OLED_ShowString(0,0,(uint8_t*)"input finer id:",8,1);	
			OLED_ShowString(0,10,(uint8_t*)"#:ensure",8,1);	
	  OLED_ShowString(10,20,(uint8_t*)"*",16,1);	
		OLED_ShowString(30,20,(uint8_t*)"*",16,1);	
		OLED_Refresh();
	  while(1)
		{
			  pin_data =MatrixKey();
			  if(pin_data>0)
				{  
						switch (pin_data)
            {
							//数字按键
							case 1:
							case 2:
							case 3:
								 sprintf(show_pin,"%d",pin_data);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data;
								 position++;
							break;
							
							case 5:
							case 6:
							case 7:
								 sprintf(show_pin,"%d",pin_data-1);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							     pin_array[position]=pin_data-1;
								 position++;
							break;
							
							case 9:
							case 10:
							case 11:
								 sprintf(show_pin,"%d",pin_data-2);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data-2;
								 position++;
							break;
							
							case 14:
								 sprintf(show_pin,"%d",pin_data-14);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data-14;
								 position++;
							break;
							
							//特殊按键
							case 13:  //推格按键 <
								 OLED_ShowString(10+position*20,20,(uint8_t*)"*",16,1);	
							   OLED_Refresh();
								 position--;
							break;
							
							case 15:  //全部重输入 R
									OLED_ShowString( 10,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 30,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 50,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 70,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 90,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 110,20,(uint8_t*)"*",16,1);	
									OLED_Refresh();
							    memset(pin_array,0,6);
									position=0;
							break;
							
						}
				}
				if((position==2)&&(pin_data==16))
							break;

		}
		OLED_Clear();
	  return (pin_array[0]*10+pin_array[1]);
}
static void add_fr(int id)
{
	 char show_frid[10];
	uint8_t i=0,ensure ,processnum=0;
	uint16_t ID;
	while(1)
	{
		switch (processnum)
		{
			case 0:
				i++;
			  		OLED_Clear();
				OLED_ShowString(10,10,(uint8_t*)"finger touch",8,1);	
				OLED_Refresh();
				ensure=GZ_GetImage();
				if(ensure==0x00) 
				{
					ensure=GZ_GenChar(CharBuffer1);//生成特征
					if(ensure==0x00)
					{
						i=0;
						processnum=1;//跳到第二步						
					}			
				}						
				break;
			
			case 1:
				i++;
				ensure=GZ_GetImage();
				if(ensure==0x00) 
				{
					ensure=GZ_GenChar(CharBuffer2);//生成特征			
					if(ensure==0x00)
					{
						i=0;
						processnum=2;//跳到第三步
					}
				}	
				break;

			case 2:
				ensure=GZ_Match();
				if(ensure==0x00) 
				{
					processnum=3;//跳到第四步
				}
				else 
				{
					i=0;
					processnum=0;//跳回第一步		
				}
				HAL_Delay(1000);
				break;

			case 3:

				ensure=GZ_RegModel();
				if(ensure==0x00) 
				{
					processnum=4;//跳到第五步
				}else {processnum=0;}
				HAL_Delay(1000);
				break;
				
			case 4:	

//		  	ID=0;
//				ensure=GZ_StoreChar(CharBuffer2,ID);//储存模板
			   //GZ_ValidTempleteNum(&ValidN);//读库指纹个数
				ensure=GZ_StoreChar(CharBuffer2,id);//储存模板
				if(ensure==0x00) 
				{			
					sprintf(show_frid,"ID:%d",id);
					OLED_Clear();
										OLED_ShowString(10,10,(uint8_t*)"finger store",8,1);	
					OLED_ShowString(10,20,(uint8_t*)show_frid,16,1);	
					OLED_Refresh();
					GZ_ValidTempleteNum(&ValidN);//读库指纹个数
					printf("ValidN%d\r\n",ValidN);
					HAL_Delay(1500);//延时后清除显示	
					OLED_Clear();
					return ;
				}else {processnum=0;}					
				break;				
		}
		HAL_Delay(800);
		if(i==10)//超过10次没有按手指则退出
		{
					OLED_Clear();
					OLED_ShowString(10,10,(uint8_t*)"timeout",8,1);	
					OLED_Refresh();
				  HAL_Delay(1500);//延时后清除显示	
			break;	
		}				
	}
}

static void del_fr(void)
{
	
	  int id = 0;
	  int position = 0;
	  uint8_t pin_data = 0;
			char show_pin[10]={0};
		uint8_t pin_array[2];
		memset(pin_array,0,2);
			OLED_ShowString(0,0,(uint8_t*)"input finer id:",8,1);	
			OLED_ShowString(0,10,(uint8_t*)"#:ensure",8,1);	
	  OLED_ShowString(10,20,(uint8_t*)"*",16,1);	
		OLED_ShowString(30,20,(uint8_t*)"*",16,1);	
		OLED_Refresh();
	  while(1)
		{
			  pin_data =MatrixKey();
			  if(pin_data>0)
				{  
						switch (pin_data)
            {
							//数字按键
							case 1:
							case 2:
							case 3:
								 sprintf(show_pin,"%d",pin_data);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data;
								 position++;
							break;
							
							case 5:
							case 6:
							case 7:
								 sprintf(show_pin,"%d",pin_data-1);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							     pin_array[position]=pin_data-1;
								 position++;
							break;
							
							case 9:
							case 10:
							case 11:
								 sprintf(show_pin,"%d",pin_data-2);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data-2;
								 position++;
							break;
							
							case 14:
								 sprintf(show_pin,"%d",pin_data-14);
								 OLED_ShowString(10+position*20,20,(uint8_t*)show_pin,16,1);	
							   OLED_Refresh();
							   pin_array[position]=pin_data-14;
								 position++;
							break;
							
							//特殊按键
							case 13:  //推格按键 <
								 OLED_ShowString(10+position*20,20,(uint8_t*)"*",16,1);	
							   OLED_Refresh();
								 position--;
							break;
							
							case 15:  //全部重输入 R
									OLED_ShowString( 10,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 30,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 50,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 70,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 90,20,(uint8_t*)"*",16,1);	
									OLED_ShowString( 110,20,(uint8_t*)"*",16,1);	
									OLED_Refresh();
							    memset(pin_array,0,6);
									position=0;
							break;
							
						}
				}
				if((position==2)&&(pin_data==16))
							break;

		}
		
	  id = pin_array[0]*10+pin_array[1];
		GZ_DeletChar(id,1);//删除单个指纹
		return;

}