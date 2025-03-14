#ifndef __MATRX_KEY_H
#define __MATRX_KEY_H

#include "main.h"
#include "gpio.h"
#include "stdio.h"

extern uint8_t key_state[4][4];

void scanMatrix(void);

uint8_t MatrixKey(void);

#endif
 