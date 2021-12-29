/* 2011.8.26
****************************************
**  Copyright  (C)        1999-2011   **
**  Web:  http://www.winchiphead.com  **
****************************************
**  TC2.0@PC, KC7.0@MCS51             **
****************************************
*/

/*
********************************************** 
**
**  CH438 转多串口接口芯片 
**
**  硬件接口层定义 直接地址方式   
**
**********************************************
*/


#include "include.h"
#include "main.h"


GPIO_InitTypeDef GPIO_InitStruct_Input = {D0_Pin|D1_Pin|D2_Pin|D3_Pin|D4_Pin|D5_Pin|D6_Pin|D7_Pin,
																					GPIO_MODE_INPUT,
																					GPIO_NOPULL,
																					0};
GPIO_InitTypeDef GPIO_InitStruct_Output = {D0_Pin|D1_Pin|D2_Pin|D3_Pin|D4_Pin|D5_Pin|D6_Pin|D7_Pin,
																					GPIO_MODE_OUTPUT_PP,
																					GPIO_NOPULL,
																					GPIO_SPEED_FREQ_LOW};
// GPIO_SPEED_FREQ_HIGH   GPIO_SPEED_FREQ_MEDIUM   GPIO_SPEED_FREQ_LOW

																					
#define DELAY_2 2
																					
/*

    定义CH438中断引脚

*/
//#define CH438_INT_WIRE    P3^2
// (port) = 0x00FF00FF&(((uint8_t)~(val)) << 16u | (val));
	
	
/*
  单片机IO端口模拟总线时序
*/


void uDelay(volatile uint16_t val) {
    while(val--);
}


#define ADDR_BSRR  GPIOB->BSRR  
#define DATA_BSRR  GPIOA->BSRR
#define CHANGE_BSRR(port, val) \
	do { \
		(port) = 0x00FF0000; \
		uDelay(200); \
		(port) = (uint16_t)(val); \
	} while(0)	

/*
   采用直接地址方式
*/

/*********************************************************************************************************
** 函数名称: WriteCH438Data
** 功能描述: 接口函数，用于往CH438地址写入数据
** 输　入: 地址,数据
**
** 输　出: 无
**         
** 日　期: 2011年8月26日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void WriteCH438Data(volatile uint8_t addr, volatile uint8_t dat)
{
			HAL_GPIO_WritePin(CS__GPIO_Port, CS__Pin, GPIO_PIN_RESET);// 选中芯片
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_Output);
			// uDelay(40);
			//GPIOA->CRL = 0x33333333;																	//D0-D7 I/O置为输出
		  //CHANGE_BSRR(ADDR_BSRR, addr);														  // 读取地址
			ADDR_BSRR = 0x04FF0000; 
			// uDelay(DELAY_2); 
			ADDR_BSRR = (uint16_t)((addr&0XFB) | ((addr&0x04) << 8)); 
			// uDelay(DELAY_2);
			DATA_BSRR = 0x00FF0000; 
			// uDelay(DELAY_2); 
			DATA_BSRR = (uint16_t)(dat); 
			// uDelay(DELAY_2);
			//CHANGE_BSRR(DATA_BSRR, dat);															  // 写数据
			// uDelay(DELAY_2);
			HAL_GPIO_WritePin(WR__GPIO_Port, WR__Pin, GPIO_PIN_RESET);// 打开写
			// uDelay(DELAY_2);
			HAL_GPIO_WritePin(WR__GPIO_Port, WR__Pin, GPIO_PIN_SET);  // 关闭写
			// uDelay(DELAY_2);
		  HAL_GPIO_WritePin(CS__GPIO_Port, CS__Pin, GPIO_PIN_SET);  // 取消选中
			// uDelay(DELAY_2);
}







/*********************************************************************************************************
** 函数名称: Read_CH438Data
** 功能描述: 接口函数，从CH438地址读取数据
** 输　入: 地址
**
** 输　出: 数据
**         
** 日　期: 2011年8月26日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
UINT8 ReadCH438Data( UINT8 addr )
{
  UINT8 dat;
  dat = dat;      /* 防止编译器出现警告 */

/*
    使用51单片机外部总线接口操作CH438
	总线硬件接口 
	硬件接口 
	     MCU			CH438
	  PA.0~P0.7  <==>	D0~D7
	  PB.0~PB.6  <==>	A0~A6
	     PB.9    <==> 	WR
         PB.8    <==>	RD
		 PB.10    <==>   CS
		 PD.1    <==> 	INT
*/
//    CH438_CS_WIRE = 0;
//	dat = *((volatile unsigned char   xdata *)(0x8000|(addr<<8)));	   /* 占用总线地址空间0x8000~0x804F */
//    CH438_CS_WIRE = 1;

//	return (dat);	



/*
    使用单片机通用IO端口模拟直接地址时序

	硬件接口 
	     MCU			CH438
	  PA.0~P0.7  <==>	D0~D7
	  PB.0~PB.6  <==>	A0~A6
	     PB.9    <==> 	WR
         PB.8    <==>	RD
		 PB.10    <==>   CS
		 PD.1    <==> 	INT
*/
			// uDelay(DELAY_2);
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_Input);
			// uDelay(DELAY_2);
			ADDR_BSRR = 0x04FF0000; 
			// uDelay(DELAY_2); 
			ADDR_BSRR = (uint16_t)((addr&0XFB) | ((addr&0x04) << 8)); 
			// uDelay(DELAY_2); 
		  //CHANGE_BSRR(ADDR_BSRR, addr);														  // 读取地址
			//for (uint16_t i = 0; i < 7; ++i) {
			//	HAL_GPIO_WritePin(GPIOB, i, (addr & (1 << i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			//}
		 	HAL_GPIO_WritePin(CS__GPIO_Port, CS__Pin, GPIO_PIN_RESET);// 选中芯片
			// uDelay(DELAY_2);
			HAL_GPIO_WritePin(RD__GPIO_Port, RD__Pin, GPIO_PIN_RESET);// 打开读
			// uDelay(DELAY_2);
		  dat = GPIOA->IDR & 0xff; 																  // 读输入数据寄存器的低八位
			// uDelay(DELAY_2);
			HAL_GPIO_WritePin(RD__GPIO_Port, RD__Pin, GPIO_PIN_SET);  // 关闭读
			// uDelay(DELAY_2);
		  HAL_GPIO_WritePin(CS__GPIO_Port, CS__Pin, GPIO_PIN_SET);  // 取消选中

			//uDelay(20);
			//HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_Output);
			//uDelay(20);
			
       // A0_GPIO_Port->BSRR = ((uint16_t)(~addr) << 16u) | addr; //读取地址	 
		  //GPIOB->CRL &=0;
			//GPIOB->CRL = 0X88888888;	//  置为输入方向 		
/*	 
//	 
    CH438_ADDR_PORT = addr;
   CH438_DATA_PORT = 0xff;   	 置为输入方向 
		CH438_CS_WIRE = 0;
	 CH438_RD_WIRE = 0;
	 dat = CH438_DATA_PORT;
	 CH438_RD_WIRE = 1;
	 CH438_CS_WIRE = 1;
	 CH438_ADDR_PORT = 0xff;    //  置为输入方向 
	 CH438_DATA_PORT = 0xff;	 //置为输入方向 */
	return dat;

}









/*********************************************************************************************************
** 函数名称: WriteCH438Block
** 功能描述: 接口函数，从CH438地址写入数据块
** 输　入: CH438寄存器地址,数据块长度,数据缓冲区地址
**
** 输　出: 无
**         
** 日　期: 2011年8月26日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void WriteCH438Block( UINT8 mAddr, UINT8 mLen, PUINT8 mBuf )   
{

    while ( mLen -- ) 	
	  WriteCH438Data( mAddr, *mBuf++ );

}





/*********************************************************************************************************
** 函数名称: Query438Interrupt
** 功能描述: 接口函数，用于查询中断方式
** 输　入: 无
**
** 输　出: 无
**         
** 日　期: 2011年8月26日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
UINT8 Query438Interrupt( void )
{
#ifdef CH438_INT_WIRE
    return( CH438_INT_WIRE ? FALSE : TRUE );   /* 如果连接了CH438的中断引脚则直接进入中断服务程序处理 */
#else 
    return( 1 );
#endif

}












/*********************************************************************************************************
** 函数名称: CH438_PORT_INIT
** 功能描述: 接口函数，用于初始化单片机IO口
** 输　入: 无
**
** 输　出: 无
**         
** 日　期: 2011年8月26日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**-------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void CH438_PORT_INIT( void )
{
	HAL_GPIO_WritePin(CS__GPIO_Port, CS__Pin, GPIO_PIN_SET);  //取消选中
	HAL_GPIO_WritePin(RD__GPIO_Port, RD__Pin, GPIO_PIN_SET);  //关闭读
	HAL_GPIO_WritePin(WR__GPIO_Port, WR__Pin, GPIO_PIN_SET);  //关闭写
	
	// HAL_GPIO_WritePin(AMOD_GPIO_Port, AMOD_Pin, GPIO_PIN_RESET);  //设置直接地址方式
	
 /* CH438_ADDR_PORT = 0xff;		// 地址端口 默认为输入方向 

  CH438_DATA_PORT = 0xff;		// 数据端口 默认为输入方向 

  CH438_CS_WIRE = 1;			// CS无效 

  CH438_WR_WIRE = 1;			// WR无效 

  CH438_RD_WIRE = 1;			// RD无效  */

}
