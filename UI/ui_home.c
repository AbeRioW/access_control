#include "ui_home.h"
#include "bobao.h"
void ui_home(void)
{
	    int open_count=0;
	    int f_count=0;
	   	SearchResult seach;
			uint8_t ensure;
      int pin_data;
	   uint8_t input_code[6];
	   memset(input_code,0,6);
	   while(1)
		 {
			    OLED_ShowString( 0,0,(uint8_t*)"# to input pin or ",8,1);	
					OLED_ShowString( 0,20,(uint8_t*)"finger touch",8,1);	
			    OLED_ShowString( 20,50,(uint8_t*)"S:Admin setting",8,1);	
					OLED_Refresh();

   			  ensure=GZ_GetImage();  //获取图片
			    if(ensure==0x00) //生成特征成功
					{		

							//ensure=GZ_HighSpeedSearch(CharBuffer1,0,300,&seach);
						ensure=GZ_Search(CharBuffer1,0,300,&seach);
						  printf("ensure %02x\r\n",ensure);
							if(ensure==0x00)//搜索成功
							{	
									if(seach.mathscore>100)
										{
											//匹配上了
											OLED_Clear();
											OLED_ShowString( 0,20,(uint8_t*)"Match,Welcome!",8,1);	
											OLED_Refresh();
											qingjin();  //语音播报
														HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_SET);  //继电器开
											
									HAL_Delay(500);
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //继电器开
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //继电器开
											HAL_Delay(4000);
											OLED_Clear();
											continue;
										}
										else
										{
											//没匹配上了
                      f_count++;
											OLED_Clear();
											OLED_ShowString( 0,20,(uint8_t*)"Sorry,don't match!",8,1);	
											OLED_Refresh();
																						cuowu();
											HAL_Delay(4000);
											OLED_Clear();
										}

						}
						else
						{
							    f_count++;
									//没匹配上
							    		cuowu();
									OLED_Clear();
											OLED_ShowString( 0,20,(uint8_t*)"Srry,don't match!",8,1);	
												OLED_Refresh();
											HAL_Delay(4000);
							
											OLED_Clear();
						}

					}
					
					if(f_count==3)
					{
						  f_count=0;
							call_admin();
						  continue;
              						
					}
					
					 pin_data =MatrixKey();
					 if(pin_data==16) //#号，意思是需要输入密码
					 {
						    OLED_Clear();
							  break;
					 } 
					 
					 if(pin_data==4) //S进入setting界面
					 {
						    OLED_Clear();
							  break;							
					 }
	  }
		 
		if(pin_data==4) 
		{
					pin_data=0;
					for(int i=0;i<3;i++)
					{
							OLED_ShowString(30,0,(uint8_t*)"input admin pin",8,1);	
							OLED_Refresh();
							ui_pin(input_code,6);
							if(memcmp(input_code,admin_pin,6)==0)
							{
									OLED_Clear();
									//这里是密码正确了，进入管理员界面
								  ui_setting();

									break;  //打断for循环
							}
							else
							{
									OLED_Clear();
									//这里是密码正确了，要开门
									OLED_ShowString(20,20,(uint8_t*)"sorry,don't macth",8,1);	
									OLED_Refresh();
									HAL_Delay(3000);
								  OLED_Clear();
								  
							}
					
					}
		}
		
		
		if(pin_data==16)
		{ 
			    printf("fuck\r\n");
			    pin_data=0;
					for(open_count=0;open_count<3;open_count++)
					{
							OLED_ShowString( 0,0,(uint8_t*)"input pin to open",8,1);	
							OLED_Refresh();
							ui_pin(input_code,6);
							if(memcmp(input_code,open_pin,6)==0)
							{
								  											qingjin();  //语音播报
									OLED_Clear();
									//这里是密码正确了，要开门
									OLED_ShowString(20,20,(uint8_t*)"match,Welcome!!",8,1);	
									OLED_Refresh();
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_SET);  //继电器开
									HAL_Delay(500);
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //继电器开
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //继电器开
									HAL_Delay(1000);
									break;  //打断for循环
							}
							else
							{
								  //密码错误
									OLED_Clear();
																    		cuowu();
									OLED_ShowString(20,20,(uint8_t*)"sorry,don't macth",8,1);	
									OLED_Refresh();
									HAL_Delay(3000);
								  OLED_Clear();

							}
					
					}
					
					if(open_count==3)
					{
								call_admin();
					}
					

		}


		
}