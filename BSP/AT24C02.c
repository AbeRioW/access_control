#include "AT24C02.h"

//ע��������ͺ���256,��ַ��������I2C_MEMADD_SIZE_16BIT,���ѡ��02�ͺŵģ�����I2C_MEMADD_SIZE_8BIT
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
 *AT24C256��256��bit,��32KB,Ѱַ�ռ�Ϊ0~0x7fff
 *��Ϊ�����ֽ�,��ַ1Ϊ0~0x7f,��ַAT24C256_ADDR_LENΪ0~0xff,
 *һҳ��64���ֽ�,��Ϊ512ҳ
 */

void at24_writeMultiByte(uint16_t addr,uint8_t *dat,uint16_t n)
{
		uint16_t i=0,cnt=0,head,left,tail;
	  
	  if((n+addr-1)/AT24_PAGE_SIAE==addr/AT24_PAGE_SIAE)   //����һҳֱ��д
		{
				HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr,I2C_MEMADD_SIZE_16BIT,dat,n,0xffff);
			  HAL_Delay(20);
		}
		else
		{
			  //ǩ������һҳ��д��
				head=(addr/AT24_PAGE_SIAE+1)*AT24_PAGE_SIAE-addr;
			  left = n-head;
			  tail = left-left/AT24_PAGE_SIAE*AT24_PAGE_SIAE;
			  HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr,I2C_MEMADD_SIZE_16BIT,dat,head,0xffff);
			  HAL_Delay(2*head);
			  
			  //������Ҳ��д��
			  for(i=0;i<left/AT24_PAGE_SIAE;i++)
			  {
						HAL_I2C_Mem_Write(&hi2c1,AT24_WRITE,addr+head+i*AT24_PAGE_SIAE,I2C_MEMADD_SIZE_16BIT,dat+head+i*AT24_PAGE_SIAE,AT24_PAGE_SIAE,0xffff);
					  HAL_Delay(2*AT24_PAGE_SIAE);
				}
				
				//���ʣ�µ�д��
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