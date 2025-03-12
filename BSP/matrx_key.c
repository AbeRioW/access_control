#include "matrx_key.h"


uint8_t key_state[4][4]={0};

void scanMatrix(void) {
    for (int row = 0; row < 4; row++) {
        // 设置当前行为低电平
          HAL_GPIO_WritePin(GPIOB, ROW3_KEY_Pin|ROW2_KEY_Pin|ROW1_KEY_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, ROW4_KEY_Pin, GPIO_PIN_RESET);

            // 读取列0引脚状态
			      (HAL_GPIO_ReadPin(GPIOB, COL1_KEY_Pin) == GPIO_PIN_RESET)?(key_state[row][0] = 1):(key_state[row][0] = 0);
            // 读取列0引脚状态
			      (HAL_GPIO_ReadPin(GPIOB, COL2_KEY_Pin) == GPIO_PIN_RESET)?(key_state[row][1] = 1):(key_state[row][1] = 0);
            // 读取列0引脚状态
			      (HAL_GPIO_ReadPin(GPIOB, COL3_KEY_Pin) == GPIO_PIN_RESET)?(key_state[row][2] = 1):(key_state[row][2] = 0);
            // 读取列0引脚状态
			      (HAL_GPIO_ReadPin(GPIOB, COL4_KEY_Pin) == GPIO_PIN_RESET)?(key_state[row][3] = 1):(key_state[row][3] = 0);

			      HAL_Delay(50);
        // 设置当前行为高电平
           HAL_GPIO_WritePin(GPIOB, ROW3_KEY_Pin|ROW2_KEY_Pin|ROW1_KEY_Pin, GPIO_PIN_SET);
					 HAL_GPIO_WritePin(GPIOA, ROW4_KEY_Pin, GPIO_PIN_SET);
			

    }
}