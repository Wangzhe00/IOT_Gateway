
/*

   CH438 UART1 �ⲿ��������

*/
extern void UART1_UpdateDTR();
extern void UART1_Reset( void );
extern void InitCH438UART1( void );                        /* ��ʼ��CH438 */
extern void UART1_SendByte( UINT8 dat );                   /* CH438����1����һ�ֽ��ӳ��� */
extern UINT8 UART1_RcvByte();                              /* CH438����1����һ�ֽ��ӳ��� */
extern void  UART1_SendStr( UINT8 *str );                  /* CH438����1����һ�ַ����ӳ��� */
extern void  CH438Seril1Send( UINT8 *Data, UINT8 Num );    /* ����FIFO,CH438����1���Ͷ��ֽ��ӳ��� */
extern UINT8 CH438Seril1Rcv( UINT8 *buf );                 /* ����FIFO,CH438����1���ն��ֽ��ӳ���*/
extern void CH438UART1Send( UINT8 *Data, UINT8 Num );      /* ����FIFO,һ�����16�ֽڣ�CH438����1���Ͷ��ֽ��ӳ��� */
extern void Auto_HandFlow1_Ctrl( void );                   /* ����1�Զ�Ӳ��������*/