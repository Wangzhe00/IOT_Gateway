/*
   CH438 UART2外部函数声明
*/

extern void UART2_Reset( void );
extern void InitCH438UART2( void );                       /* 初始化CH438 */
extern void UART2_SendByte( UINT8 dat );                  /* CH438串口2发送一字节子程序 */
extern UINT8 UART2_RcvByte();                             /* CH438串口2接收一字节子程序 */
extern void UART2_SendStr( UINT8 *str );                  /* CH438串口2发送一字符串子程序 */
extern void  CH438Seril2Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口2发送多字节子程序 */
extern UINT8  CH438Seril2Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口2接收多字节子程序 */
extern void  CH438UART2Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口2发送多字节子程序 */
extern void Auto_HandFlow2_Ctrl( );                       /* 串口0自动硬件流控制 */

