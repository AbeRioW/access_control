#include "ui_pin.h"

uint8_t admin_pin[6]={0x08,0x08,0x08,0x08,0x08,0x08};
uint8_t open_pin[6]={0x00,0x00,0x00,0x00,0x00,0x00};
void ui_pin(uint8_t *data,int size)
{
	  int position = 0;
	  uint8_t pin_data = 0;
			char show_pin[10]={0};
		uint8_t pin_array[6];
		memset(pin_array,0,6);
	  OLED_ShowString( 10,20,(uint8_t*)"*",16,1);	
		OLED_ShowString( 30,20,(uint8_t*)"*",16,1);	
		OLED_ShowString( 50,20,(uint8_t*)"*",16,1);	
		OLED_ShowString( 70,20,(uint8_t*)"*",16,1);	
		OLED_ShowString( 90,20,(uint8_t*)"*",16,1);	
		OLED_ShowString( 110,20,(uint8_t*)"*",16,1);	
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
				if(position==6)
							break;

		}
		
		memcpy(data,pin_array,6); //数据赋值
		
		return;

}