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
    GPIOAallset();   //全置为高电平
    HAL_GPIO_WritePin(GPIOB, ROW1_KEY_Pin, GPIO_PIN_RESET);    //开始检测第一行
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
			}
				//当按钮处于被按下的状态的时候，程序一直卡在循环读取按钮的状态，避免多按钮同时按下时读取错误
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
		
    GPIOAallset();   //全置为高电平
    HAL_GPIO_WritePin(GPIOB, ROW2_KEY_Pin, GPIO_PIN_RESET);    //开始检测第二行
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
					
			}
			//当按钮处于被按下的状态的时候，程序一直卡在循环读取按钮的状态，避免多按钮同时按下时读取错误
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
    HAL_GPIO_WritePin(GPIOB, ROW3_KEY_Pin, GPIO_PIN_RESET);    //PA2置0，开始检测第三行
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
					
			}
			//当按钮处于被按下的状态的时候，程序一直卡在循环读取按钮的状态，避免多按钮同时按下时读取错误
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
		
		
    GPIOAallset();   //全置为高电平
    HAL_GPIO_WritePin(GPIOA, ROW4_KEY_Pin, GPIO_PIN_RESET);    //PA3置0，开始检测第四行
    if(HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin)==0)   
		{ 
			HAL_Delay(10);   
			while(!HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin))
			{
		
			}
			//当按钮处于被按下的状态的时候，程序一直卡在循环读取按钮的状态，避免多按钮同时按下时读取错误
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