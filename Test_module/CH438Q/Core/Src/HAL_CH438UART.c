/*
 * @Description: 
 * @Author: Wangzhe
 * @Date: 2021-12-28 00:46:05
 * @LastEditors: Wangzhe
 * @LastEditTime: 2021-12-28 16:15:29
 * @FilePath: \CH438Q\Core\Src\HAL_CH438UART.c
 */


#include "HAL_CH438UART.h"
#include <stdint.h>
#include <stdio.h>

#define UART_NUM 8
#define CH438UART_BPS 9600 /* 定义CH438串口通讯波特率 */
#define Fpclk 2666666       /* 定义内部时钟频率    */

uint8_t regLCR[] = {REG_LCR_ADDR,  REG_LCR1_ADDR, REG_LCR2_ADDR, REG_LCR3_ADDR,
                    REG_LCR4_ADDR, REG_LCR5_ADDR, REG_LCR6_ADDR, REG_LCR7_ADDR};
uint8_t regDLL[] = {REG_DLL_ADDR,  REG_DLL1_ADDR, REG_DLL2_ADDR, REG_DLL3_ADDR,
                    REG_DLL4_ADDR, REG_DLL5_ADDR, REG_DLL6_ADDR, REG_DLL7_ADDR};
uint8_t regDLM[] = {REG_DLM_ADDR,  REG_DLM1_ADDR, REG_DLM2_ADDR, REG_DLM3_ADDR,
                    REG_DLM4_ADDR, REG_DLM5_ADDR, REG_DLM6_ADDR, REG_DLM7_ADDR};
uint8_t regFCR[] = {REG_FCR_ADDR,  REG_FCR1_ADDR, REG_FCR2_ADDR, REG_FCR3_ADDR,
                    REG_FCR4_ADDR, REG_FCR5_ADDR, REG_FCR6_ADDR, REG_FCR7_ADDR};
uint8_t regIER[] = {REG_IER_ADDR,  REG_IER1_ADDR, REG_IER2_ADDR, REG_IER3_ADDR,
                    REG_IER4_ADDR, REG_IER5_ADDR, REG_IER6_ADDR, REG_IER7_ADDR};
uint8_t regMCR[] = {REG_MCR_ADDR,  REG_MCR1_ADDR, REG_MCR2_ADDR, REG_MCR3_ADDR,
                    REG_MCR4_ADDR, REG_MCR5_ADDR, REG_MCR6_ADDR, REG_MCR7_ADDR};
uint8_t regIIR[] = {REG_IIR_ADDR,  REG_IIR1_ADDR, REG_IIR2_ADDR, REG_IIR3_ADDR,
                    REG_IIR4_ADDR, REG_IIR5_ADDR, REG_IIR6_ADDR, REG_IIR7_ADDR};
uint8_t regLSR[] = {REG_LSR_ADDR,  REG_LSR1_ADDR, REG_LSR2_ADDR, REG_LSR3_ADDR,
                    REG_LSR4_ADDR, REG_LSR5_ADDR, REG_LSR6_ADDR, REG_LSR7_ADDR};
uint8_t regRBR[] = {REG_RBR_ADDR,  REG_RBR1_ADDR, REG_RBR2_ADDR, REG_RBR3_ADDR,
                    REG_RBR4_ADDR, REG_RBR5_ADDR, REG_RBR6_ADDR, REG_RBR7_ADDR};
uint8_t regTHR[] = {REG_THR_ADDR,  REG_THR1_ADDR, REG_THR2_ADDR, REG_THR3_ADDR,
                    REG_THR4_ADDR, REG_THR5_ADDR, REG_THR6_ADDR, REG_THR7_ADDR};

typedef void (*CH438Send)(uint8_t *data, uint8_t len);
typedef uint8_t (*CH438Recv)(uint8_t *data);

CH438Send ch438Send[UART_NUM];
CH438Recv ch438Recv[UART_NUM];

void CH438_InitAll() {
    uint16_t div;
    uint8_t DLL, DLM, ssr;
    div = (Fpclk >> 4) / CH438UART_BPS;
    DLM = div >> 8;
    DLL = div & 0xff;
    for (int i = 0; i < UART_NUM; ++i) {
        WriteCH438Data(regLCR[i], BIT_LCR_DLAB);
        WriteCH438Data(regIER[i], BIT_IER_RESET);
        uDelay(20);
        WriteCH438Data(regLCR[i], BIT_LCR_DLAB); /* 设置DLAB为1 */
        WriteCH438Data(regDLL[i], DLL); /* 设置波特率 */
        WriteCH438Data(regDLM[i], DLM);
        WriteCH438Data(regFCR[i],
                       BIT_FCR_RECVTG1 | BIT_FCR_RECVTG0 | BIT_FCR_FIFOEN); /* 设置FIFO模式，触发点为112字节 */
        WriteCH438Data(regLCR[i], BIT_LCR_WORDSZ1 | BIT_LCR_WORDSZ0); /* 字长8位，1位停止位、无校验 */
        WriteCH438Data(regIER[i],
                       /*BIT_IER_IEMODEM | */ BIT_IER_IELINES | BIT_IER_IETHRE | BIT_IER_IERECV); /* 使能中断 */

        WriteCH438Data(regMCR[i], BIT_MCR_OUT2 | BIT_MCR_RTS | BIT_MCR_DTR); /* 允许中断输出,DTR,RTS为1 */

        WriteCH438Data(regFCR[i],
                       ReadCH438Data(regFCR[i]) | BIT_FCR_TFIFORST | BIT_FCR_RFIFORST); /* 清空FIFO中的数据 */
    }

    ssr = ReadCH438Data(REG_SSR_ADDR);
    if (ssr != 0) {
        for (int i = 0; i < 8; ++i) {
            if (ssr & (1 << i)) {
                uint8_t t = ReadCH438Data(regIIR[i]);
                if (t == 6) {
                    ReadCH438Data(regLSR[i]);
                } else if (t == 12) {
                    ReadCH438Data(regRBR[i]);
                } else if (t == 2) {
                    ReadCH438Data(regIIR[i]);
                }
                printf("[%d][%X]\r\n", i, ReadCH438Data(regIIR[i]));
            }
        }
        printf("ssr:[%X]\r\n", ssr);
    }
    ch438Send[0] = CH438Seril0Send;
    ch438Send[1] = CH438Seril1Send;
    ch438Send[2] = CH438Seril2Send;
    ch438Send[3] = CH438Seril3Send;
    ch438Send[4] = CH438Seril4Send;
    ch438Send[5] = CH438Seril5Send;
    ch438Send[6] = CH438Seril6Send;
    ch438Send[7] = CH438Seril7Send;
    ch438Recv[0] = CH438Seril0Rcv;
    ch438Recv[1] = CH438Seril1Rcv;
    ch438Recv[2] = CH438Seril2Rcv;
    ch438Recv[3] = CH438Seril3Rcv;
    ch438Recv[4] = CH438Seril4Rcv;
    ch438Recv[5] = CH438Seril5Rcv;
    ch438Recv[6] = CH438Seril6Rcv;
    ch438Recv[7] = CH438Seril7Rcv;
}
