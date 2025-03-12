#ifndef __AS608_H
#define __AS608_H
 
#include "main.h"
#include "usart.h"
#include "string.h"
#include "stdio.h"

#define UART2_MAX_REC_LEN 400
 
extern uint8_t UART2_RX_BUF[UART2_MAX_REC_LEN];
extern uint8_t USART2_RX_STA;//串口是否接收到数据
 typedef struct  
{
	uint16_t pageID;//指纹ID
	uint16_t mathscore;//匹配得分
}SearchResult;
 
typedef struct
{
	uint16_t PS_max;//指纹最大容量
	uint8_t  PS_level;//安全等级
	uint32_t PS_addr;
	uint8_t  PS_size;//通讯数据包大小
	uint8_t  PS_N;//波特率基数N
}SysPara;


uint8_t as608_init(void);
uint8_t PS_GetImage(void);
uint8_t PS_GenChar(uint8_t BufferID);
uint8_t PS_Match(void);
const char *EnsureMessage(uint8_t ensure);
uint8_t PS_Search(uint8_t BufferID,uint16_t StartPage,uint16_t PageNum,SearchResult *p);
uint8_t PS_RegModel(void);
uint8_t PS_StoreChar(uint8_t BufferID,uint16_t PageID);
uint8_t PS_DeletChar(uint16_t PageID,uint16_t N);
uint8_t PS_Empty(void);
uint8_t PS_WriteReg(uint8_t RegNum,uint8_t DATA);
uint8_t PS_ReadSysPara(SysPara *p);
uint8_t PS_SetAddr(uint32_t PS_addr);
uint8_t PS_WriteNotepad(uint8_t NotePageNum,uint8_t *Byte32);
uint8_t PS_ReadNotepad(uint8_t NotePageNum,uint8_t *Byte32);
uint8_t PS_HighSpeedSearch(uint8_t BufferID,uint16_t StartPage,uint16_t PageNum,SearchResult *p);
uint8_t PS_ValidTempleteNum(uint16_t *ValidN);
uint8_t PS_HandShake(uint32_t *PS_Addr);
#endif
