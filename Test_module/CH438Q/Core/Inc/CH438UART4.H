/*
   CH438 UART4�ⲿ��������
*/

extern void UART4_Reset( void );
extern void InitCH438UART4( void );                       /* ��ʼ��CH438 */
extern void UART4_SendByte( UINT8 dat );                  /* CH438����4����һ�ֽ��ӳ��� */
extern UINT8 UART4_RcvByte();                             /* CH438����4����һ�ֽ��ӳ��� */
extern void UART4_SendStr( UINT8 *str );                  /* CH438����4����һ�ַ����ӳ��� */
extern void  CH438Seril4Send( UINT8 *Data, UINT8 Num );   /* ����FIFO,CH438����4���Ͷ��ֽ��ӳ��� */
extern UINT8  CH438Seril4Rcv( UINT8 *buf );               /* ����FIFO,CH438����4���ն��ֽ��ӳ��� */
extern void  CH438UART4Send( UINT8 *Data, UINT8 Num );    /* ����FIFO,һ�����128�ֽڣ�CH438����4���Ͷ��ֽ��ӳ��� */
extern void Auto_HandFlow4_Ctrl( );                       /* ����4�Զ�Ӳ�������� */
