#include "AT24C02.h"

//注意这里的型号是256,地址的增量是I2C_MEMADD_SIZE_16BIT,如果选用02型号的，就是I2C_MEMADD_SIZE_8BIT
uint8_t at24_init(void)
{
	  uint8_t read_data;
	  return(HAL_I2C_Mem_Read(&hi2c1,AT24_READ,0x00,I2C_MEMADD_SIZE_16BIT,&read_data,1,0xffff)==HAL_OK);
}

uint8_t at24_write_byte(uint8_t reg,uint8_t data)
{
	  HAL_StatusTypeDef status = HAL_OK;

		status = HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,reg,I2C_MEMADD_SIZE_16BIT,&data,1,0xffff);
	
    HAL_Delay(20);
	  
		return status;
}

uint8_t at24_read_byte(uint8_t reg)
{
		uint8_t r_data=0;
	  HAL_I2C_Mem_Read(&hi2c1,AT24_READ,reg,I2C_MEMADD_SIZE_16BIT,&r_data,1,0xffff);
	  HAL_Delay(20);
	  return r_data;
}

/*
 *AT24C256有256个bit,即32KB,寻址空间为0~0x7fff
 *分为两个字节,地址1为0~0x7f,地址AT24C256_ADDR_LEN为0~0xff,
 *一页有64个字节,分为512页
 */

void at24_writeMultiByte(uint16_t addr,uint8_t *dat,uint16_t n)
{
		uint16_t i=0,cnt=0,head,left,tail;
	  
	  if((n+addr-1)/AT24_PAGE_SIAE==addr/AT24_PAGE_SIAE)   //不满一页直接写
		{
				HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr,I2C_MEMADD_SIZE_16BIT,dat,n,0xffff);
			  HAL_Delay(20);
		}
		else
		{
			  //签名不是一页的写下
				head=(addr/AT24_PAGE_SIAE+1)*AT24_PAGE_SIAE-addr;
			  left = n-head;
			  tail = left-left/AT24_PAGE_SIAE*AT24_PAGE_SIAE;
			  HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr,I2C_MEMADD_SIZE_16BIT,dat,head,0xffff);
			  HAL_Delay(2*head);
			  
			  //是完整也的写入
			  for(i=0;i<left/AT24_PAGE_SIAE;i++)
			  {
						HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr+head+i*AT24_PAGE_SIAE,I2C_MEMADD_SIZE_16BIT,dat+head+i*AT24_PAGE_SIAE,AT24_PAGE_SIAE,0xffff);
					  HAL_Delay(2*AT24_PAGE_SIAE);
				}
				
				//最后剩下的写入
				HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr+head+i*AT24_PAGE_SIAE,I2C_MEMADD_SIZE_16BIT,dat+head+i*AT24_PAGE_SIAE,tail,0xffff);
				HAL_Delay(2*tail);
		}
}


void at24_readMultiByte(uint8_t addr,uint8_t* dat,uint16_t n)
{
		 if(addr+n<0x8000)
		 {
				HAL_I2C_Mem_Read(&hi2c1,AT24_READ,addr,I2C_MEMADD_SIZE_16BIT,dat,n,0xffff);
		 }
}