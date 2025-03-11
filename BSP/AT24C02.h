#ifndef __AT24C02_H
#define __AT24C02_H

#include "main.h"
#include "i2c.h"

#define AT24_WRITE 						0xa0   //写24C02的时候，从器件的地址是0xa0
#define AT24_READ 					  0xa1   //读24C02的时候，从器件的地址是0xa1

#define AT24_PAGE_SIAE        64

uint8_t at24_init(void);
uint8_t at24_write_byte(uint8_t reg,uint8_t data);
uint8_t at24_read_byte(uint8_t reg);

void at24_writeMultiByte(uint16_t addr,uint8_t *dat,uint16_t n);
void at24_readMultiByte(uint8_t addr,uint8_t* dat,uint16_t n);

#endif

