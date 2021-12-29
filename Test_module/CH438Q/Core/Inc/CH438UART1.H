
/*

   CH438 UART1 外部函数声明

*/
extern void UART1_UpdateDTR();
extern void UART1_Reset( void );
extern void InitCH438UART1( void );                        /* 初始化CH438 */
extern void UART1_SendByte( UINT8 dat );                   /* CH438串口1发送一字节子程序 */
extern UINT8 UART1_RcvByte();                              /* CH438串口1接收一字节子程序 */
extern void  UART1_SendStr( UINT8 *str );                  /* CH438串口1发送一字符串子程序 */
extern void  CH438Seril1Send( UINT8 *Data, UINT8 Num );    /* 禁用FIFO,CH438串口1发送多字节子程序 */
extern UINT8 CH438Seril1Rcv( UINT8 *buf );                 /* 禁用FIFO,CH438串口1接收多字节子程序*/
extern void CH438UART1Send( UINT8 *Data, UINT8 Num );      /* 启用FIFO,一次最多16字节，CH438串口1发送多字节子程序 */
extern void Auto_HandFlow1_Ctrl( void );                   /* 串口1自动硬件流控制*/
