/*
   CH438 UART3外部函数声明
*/

extern void UART3_Reset( void );
extern void InitCH438UART3( void );                       /* 初始化CH438 */
extern void UART3_SendByte( UINT8 dat );                  /* CH438串口3发送一字节子程序 */
extern UINT8 UART3_RcvByte();                             /* CH438串口3接收一字节子程序 */
extern void UART3_SendStr( UINT8 *str );                  /* CH438串口3发送一字符串子程序 */
extern void  CH438Seril3Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口3发送多字节子程序 */
extern UINT8  CH438Seril3Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口3接收多字节子程序 */
extern void  CH438UART3Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口3发送多字节子程序 */
extern void Auto_HandFlow3_Ctrl( );                       /* 串口3自动硬件流控制 */

