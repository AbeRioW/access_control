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

   			  ensure=GZ_GetImage();  //��ȡͼƬ
			    if(ensure==0x00) //���������ɹ�
					{		

							//ensure=GZ_HighSpeedSearch(CharBuffer1,0,300,&seach);
						ensure=GZ_Search(CharBuffer1,0,300,&seach);
						  printf("ensure %02x\r\n",ensure);
							if(ensure==0x00)//�����ɹ�
							{	
									if(seach.mathscore>100)
										{
											//ƥ������
											OLED_Clear();
											OLED_ShowString( 0,20,(uint8_t*)"Match,Welcome!",8,1);	
											OLED_Refresh();
											qingjin();  //��������
														HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_SET);  //�̵�����
											
									HAL_Delay(500);
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //�̵�����
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //�̵�����
											HAL_Delay(4000);
											OLED_Clear();
											continue;
										}
										else
										{
											//ûƥ������
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
									//ûƥ����
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
					 if(pin_data==16) //#�ţ���˼����Ҫ��������
					 {
						    OLED_Clear();
							  break;
					 } 
					 
					 if(pin_data==4) //S����setting����
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
									//������������ȷ�ˣ��������Ա����
								  ui_setting();

									break;  //���forѭ��
							}
							else
							{
									OLED_Clear();
									//������������ȷ�ˣ�Ҫ����
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
								  											qingjin();  //��������
									OLED_Clear();
									//������������ȷ�ˣ�Ҫ����
									OLED_ShowString(20,20,(uint8_t*)"match,Welcome!!",8,1);	
									OLED_Refresh();
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_SET);  //�̵�����
									HAL_Delay(500);
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //�̵�����
									HAL_GPIO_WritePin(GPIOA,LAY_Pin, GPIO_PIN_RESET);  //�̵�����
									HAL_Delay(1000);
									break;  //���forѭ��
							}
							else
							{
								  //�������
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