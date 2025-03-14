#ifndef __UI_PIN_H
#define __UI_PIN_H

#include "oled.h"
#include "matrx_key.h"
#include "string.h"

extern uint8_t admin_pin[6];
extern uint8_t open_pin[6];
void ui_pin(uint8_t *data,int size);


#endif