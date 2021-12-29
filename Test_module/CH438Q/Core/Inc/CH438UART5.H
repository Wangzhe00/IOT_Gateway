/*
   CH438 UART5外部函数声明
*/

extern void UART5_Reset( void );
extern void InitCH438UART5( void );                       /* 初始化CH438 */
extern void UART5_SendByte( UINT8 dat );                  /* CH438串口5发送一字节子程序 */
extern UINT8 UART5_RcvByte();                             /* CH438串口5接收一字节子程序 */
extern void UART5_SendStr( UINT8 *str );                  /* CH438串口55发送一字符串子程序 */
extern void  CH438Seril5Send( UINT8 *Data, UINT8 Num );   /* 禁用FIFO,CH438串口5发送多字节子程序 */
extern UINT8  CH438Seril5Rcv( UINT8 *buf );               /* 禁用FIFO,CH438串口5接收多字节子程序 */
extern void  CH438UART5Send( UINT8 *Data, UINT8 Num );    /* 启用FIFO,一次最多128字节，CH438串口5发送多字节子程序 */
extern void Auto_HandFlow5_Ctrl( );                       /* 串口5自动硬件流控制 */

