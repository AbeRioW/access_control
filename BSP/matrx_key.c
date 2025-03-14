#include "matrx_key.h"






void GPIOAallset()
{
    HAL_GPIO_WritePin(GPIOB, ROW1_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW2_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW3_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ROW4_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, COL1_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, COL2_KEY_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, COL3_KEY_Pin, GPIO_PIN_SET);   
    HAL_GPIO_WritePin(GPIOB, COL4_KEY_Pin, GPIO_PIN_SET);
}


/*
   1 2 3 S 
   4 5 6 
	 7 8 9
	 < 0 R  #
*/


uint8_t MatrixKey(void)
{
    uint8_t KeyNumber=0;
    GPIOAallset();   //ȫ��Ϊ�ߵ�ƽ
    HAL_GPIO_WritePin(GPIOB, ROW1_KEY_Pin, GPIO_PIN_RESET);    //��ʼ����һ��
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
			}
				//����ť���ڱ����µ�״̬��ʱ�򣬳���һֱ����ѭ����ȡ��ť��״̬������ఴťͬʱ����ʱ��ȡ����
        HAL_Delay(10);
        KeyNumber=1;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin))
				{
				}
        HAL_Delay(10);
        KeyNumber=2;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin))
				{
				}
        HAL_Delay(10);
        KeyNumber=3;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin))
				{
						
				}
        HAL_Delay(10);
        KeyNumber=4;
    }
		
    GPIOAallset();   //ȫ��Ϊ�ߵ�ƽ
    HAL_GPIO_WritePin(GPIOB, ROW2_KEY_Pin, GPIO_PIN_RESET);    //��ʼ���ڶ���
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
					
			}
			//����ť���ڱ����µ�״̬��ʱ�򣬳���һֱ����ѭ����ȡ��ť��״̬������ఴťͬʱ����ʱ��ȡ����
        HAL_Delay(10);
        KeyNumber=5;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin))
			{
					
			}
        HAL_Delay(10);
        KeyNumber=6;
    }
		
		
    if(HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin))
			{
				
			}
      HAL_Delay(10);
      KeyNumber=7;
    }
		
		
    if(HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin))
				{
					
				}
        HAL_Delay(10);
        KeyNumber=8;
    }
		
		
		
    GPIOAallset();   
    HAL_GPIO_WritePin(GPIOB, ROW3_KEY_Pin, GPIO_PIN_RESET);    //PA2��0����ʼ��������
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
					
			}
			//����ť���ڱ����µ�״̬��ʱ�򣬳���һֱ����ѭ����ȡ��ť��״̬������ఴťͬʱ����ʱ��ȡ����
        HAL_Delay(10);
        KeyNumber=9;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin))
				{
					
				}
        HAL_Delay(10);
        KeyNumber=10;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin)==0)   
		{ 
				HAL_Delay(10);   
				while(!HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin))
				{
				}
        HAL_Delay(10);
        KeyNumber=11;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin))
      {
					
			}				
       HAL_Delay(10);
       KeyNumber=12;
    }
		
		
    GPIOAallset();   //ȫ��Ϊ�ߵ�ƽ
    HAL_GPIO_WritePin(GPIOA, ROW4_KEY_Pin, GPIO_PIN_RESET);    //PA3��0����ʼ��������
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
		
			}
			//����ť���ڱ����µ�״̬��ʱ�򣬳���һֱ����ѭ����ȡ��ť��״̬������ఴťͬʱ����ʱ��ȡ����
        HAL_Delay(10);
        KeyNumber=13;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin))
			{
					
			}
        HAL_Delay(10);
        KeyNumber=14;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin))
			{
				
			}
        HAL_Delay(10);
        KeyNumber=15;
    }
		
    if(HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin))
			{
				 
			}
        HAL_Delay(10);
        KeyNumber=16;
    }
    return KeyNumber;
}