/*
 * @Description: 
 * @Author: Wangzhe
 * @Date: 2021-12-27 17:38:38
 * @LastEditors: Wangzhe
 * @LastEditTime: 2021-12-28 02:23:08
 * @FilePath: \CH438Q\Core\Inc\CH438UART0.H
 */

/*
   CH438 UART0外部函数声明
*/

extern void UART0_UpdateDTR();
extern void UART0_Reset( void );
extern void CH438_LowPower( void );
extern void InitCH438UART0( void );                       /* 初始化CH438 */
extern void UART0_SendByte( uint8_t dat );                  /* CH438串口0发送一字节子程序 */
extern uint8_t UART0_RcvByte();                             /* CH438串口0接收一字节子程序 */
extern void UART0_SendStr( uint8_t *str );                  /* CH438串口0发送一字符串子程序 */
extern void  CH438Seril0Send( uint8_t *Data, uint8_t Num );   /* 禁用FIFO,CH438串口0发送多字节子程序 */
extern uint8_t  CH438Seril0Rcv( uint8_t *buf );               /* 禁用FIFO,CH438串口0接收多字节子程序 */
extern void  CH438UART0Send( uint8_t *Data, uint8_t Num );    /* 启用FIFO,一次最多16字节，CH438串口0发送多字节子程序 */
extern void Auto_HandFlow0_Ctrl( );                       /* 串口0自动硬件流控制 */
