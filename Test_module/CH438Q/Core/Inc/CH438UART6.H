/*
   CH438 UART6外部函数声明
*/

extern void UART6_Reset( void );
extern void InitCH438UART6( void );                       /* 初始化CH438 */
extern void UART6_SendByte( UINT8 dat );                  /* CH438串口6发送一字节子程序 */
extern UINT8 UART6_RcvByte();                             /* CH438串口6接收一字节子程序 */
extern void UART6_SendStr( UINT8 *str );                  /* CH438串口6发送一字符串子程序 */
extern void  CH438Seril6Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口6发送多字节子程序 */
extern UINT8  CH438Seril6Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口6接收多字节子程序 */
extern void  CH438UART6Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口6发送多字节子程序 */
extern void Auto_HandFlow6_Ctrl( );                       /* 串口6自动硬件流控制 */

