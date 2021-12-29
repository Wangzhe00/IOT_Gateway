/*
   CH438 UART7外部函数声明
*/

extern void UART7_Reset( void );
extern void InitCH438UART7( void );                       /* 初始化CH438 */
extern void UART7_SendByte( UINT8 dat );                  /* CH438串口7发送一字节子程序 */
extern UINT8 UART7_RcvByte();                             /* CH438串口7接收一字节子程序 */
extern void UART7_SendStr( UINT8 *str );                  /* CH438串口7发送一字符串子程序 */
extern void  CH438Seril7Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口7发送多字节子程序 */
extern UINT8  CH438Seril7Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口7接收多字节子程序 */
extern void  CH438UART7Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口7发送多字节子程序 */
extern void Auto_HandFlow7_Ctrl( );                       /* 串口7自动硬件流控制 */

