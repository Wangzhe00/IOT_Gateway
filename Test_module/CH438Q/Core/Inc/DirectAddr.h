/*
 * @Description: 
 * @Author: Wangzhe
 * @Date: 2021-12-27 17:38:38
 * @LastEditors: Wangzhe
 * @LastEditTime: 2021-12-28 01:01:46
 * @FilePath: \CH438Q\Core\Inc\DirectAddr.h
 */
//#include "CH438INC.H"
/*

   外部函数声明
*/
#include <stdint.h>

extern void CH438_PORT_INIT( void );

extern void WriteCH438Data( uint8_t addr, uint8_t dat);

extern uint8_t ReadCH438Data( uint8_t addr );

extern void WriteCH438Block(uint8_t mAddr, uint8_t mLen, uint8_t *mBuf); /* 向指定起始地址写入数据块 */
