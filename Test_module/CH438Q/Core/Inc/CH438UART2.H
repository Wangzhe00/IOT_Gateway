/*
   CH438 UART2�ⲿ��������
*/

extern void UART2_Reset( void );
extern void InitCH438UART2( void );                       /* ��ʼ��CH438 */
extern void UART2_SendByte( UINT8 dat );                  /* CH438����2����һ�ֽ��ӳ��� */
extern UINT8 UART2_RcvByte();                             /* CH438����2����һ�ֽ��ӳ��� */
extern void UART2_SendStr( UINT8 *str );                  /* CH438����2����һ�ַ����ӳ��� */
extern void  CH438Seril2Send( UINT8 *Data, UINT8 Num );   /* ����FIFO,CH438����2���Ͷ��ֽ��ӳ��� */
extern UINT8  CH438Seril2Rcv( UINT8 *buf );               /* ����FIFO,CH438����2���ն��ֽ��ӳ��� */
extern void  CH438UART2Send( UINT8 *Data, UINT8 Num );    /* ����FIFO,һ�����128�ֽڣ�CH438����2���Ͷ��ֽ��ӳ��� */
extern void Auto_HandFlow2_Ctrl( );                       /* ����0�Զ�Ӳ�������� */
