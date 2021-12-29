/*
   CH438 UART4外部函数声明
*/

extern void UART4_Reset( void );
extern void InitCH438UART4( void );                       /* 初始化CH438 */
extern void UART4_SendByte( UINT8 dat );                  /* CH438串口4发送一字节子程序 */
extern UINT8 UART4_RcvByte();                             /* CH438串口4接收一字节子程序 */
extern void UART4_SendStr( UINT8 *str );                  /* CH438串口4发送一字符串子程序 */
extern void  CH438Seril4Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口4发送多字节子程序 */
extern UINT8  CH438Seril4Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口4接收多字节子程序 */
extern void  CH438UART4Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口4发送多字节子程序 */
extern void Auto_HandFlow4_Ctrl( );                       /* 串口4自动硬件流控制 */

