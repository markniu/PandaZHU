/*----------------------------------------------------------   
 * 项目名称:

     串口通信驱动程序

 * 功能描述:

     1、串口初始化  
	 2、查询法接收一个字节 
	 3、串口发送一个字节
	 4、串口发送一个字符串 
	 5、串口中断方式接收一个字符

 * 配置说明:
     MCU:             STC15W408AS
     开发板:       	  STC15W408AS最小系统板
     晶振:      	    内部时钟11.0592M
     扩展模块:  	  -
     软件:            Keil.C51.V9.01

 * 备注:
     - 将开发板的串口与电脑串口连接

----------------------------------------------------------*/   

#include<STC15W.h>
#include<USART.h>
#include <intrins.h>
#include <stdio.h>   //用于printf
#include <stdarg.h>  //用于vsprintf函数原型

unsigned char *pchar;				//定义一个全局指针

//----------------------------------------------------------   
//  函数名称：void IniSerialPort(void)   
//  函数功能：串口初始化   
//----------------------------------------------------------   
void InitSerialPort(void)
{ 
		SCON = 0x50;			//8位数据，可变波特率
		AUXR |= 0x01;			
		AUXR |= 0x04;			//定时器时钟为Fosc，1T模式
		T2L = 0xFA;				//定时器初值，内部时钟11.0592M，波特率115200=E8 ;921600=FD; 460800=FA
		T2H = 0xFF;				//定时器初值
		AUXR |= 0x10;			//启动定时器
    ES=0; 					//串口中断开关,采用查询法时不用打开中断      
    REN=1;      			//串口为工作方式1，允许接收数据
    SM0=0;						//SM0 SM1串口工作方式选择，01：8位异步收发，波特率由定时器决定
    SM1=1;

}
//----------------------------------------------------------   
//  函数名称：unsigned char ReceiveByte(void)
//  函数功能：查询法接收一个字节   
//----------------------------------------------------------   
unsigned char ReceiveByte(void)
{
     unsigned char rbyte;
     while(!RI); 					//查询接收标志位，是否有数据到达缓冲区
     RI=0; 							//清零接收标志位
     rbyte=SBUF; 					//从缓冲区读取数据
     return rbyte;
}
//----------------------------------------------------------   
//  函数名称：void SendByte(unsigned char sbyte)
//  函数功能：串口发送一个字节
//----------------------------------------------------------   
void SendByte(unsigned char sbyte)
{  
     SBUF=sbyte; 					//发送数据
     while(!TI); 					//等待发送完成
     TI=0; 							//清零发送标志位
}
//----------------------------------------------------------   
//  函数名称：void SendString(unsigned char *pstr)
//  函数功能：串口发送一个字符串
//----------------------------------------------------------   
void SendString(unsigned char *pstr)
{
     while(*pstr!='\0') 			//字符串是否发完
     {
         SendByte(*pstr);			//发送字符串数据
         pstr++; 					//指向下一个字符
     } 
}




// 7 6 5 4 3 2 1 0
//4 3 2 1 0 : gpio number
//5 : value to set 
//7 6 : 10 = set;   // 

// gpio number:P10~P17 = 0~7;P30~P37 = 8~15;P50~P57 = 16~23;
//////////

// send value: 7 6: 01=0~4; 10=5~9; 11=10~14

//----------------------------------------------------------   
//  函数名称：void SerialPortInte(void)
//  函数功能：串口中断方式接收一个字符
//----------------------------------------------------------   
unsigned char set_v,gpio_n;  
void SerialPortInte(void) interrupt 4  
{ 
	if(RI)
	{

		RI=0;						    //清零接收标志位
/*		*pchar=SBUF;					//读取缓冲区的数据		
	//	set_v=(*pchar>>6);
		gpio_n=*pchar&0x1F;// 
		 
		//if(set_v==2)// set
		{
			
			set_v=(*pchar>>5)&0x01;
			if(gpio_n<8)
			{
				if(set_v)
					P1=P1|(1<<gpio_n);
				else
					P1=P1&(~(1<<gpio_n));
			}
			else if(gpio_n<16)
			{
				gpio_n-=8;
				if(set_v)
					P3=P3|(1<<gpio_n);
				else
					P3=P3&(~(1<<gpio_n));
			}
			else if(gpio_n<24)
			{
				gpio_n-=16;
				if(set_v)
					P5=P5|(1<<gpio_n);
				else
					P5=P5&(~(1<<gpio_n));
			}
			 
		}*/
		/////////////get gpio value
	/*	else if(set_v==1)//get
		{
			SendByte(P1);
			
			if(gpio_n<8)
			{
				set_v=P1&(1<<gpio_n)?1:0;
				SendByte(set_v);
			}
			else if(gpio_n<16)
			{
				gpio_n-=8;
				set_v=P3&(1<<gpio_n)?1:0;
				SendByte(set_v);
			}
			else if(gpio_n<24)
			{
				gpio_n-=16;
				set_v=P5&(1<<gpio_n)?1:0;
				SendByte(set_v);
			}
		}*/
		
	}
	if(TI)
		TI=0;
}


void uart_printf(const char *fmt,...) 
{ 
 va_list ap; 
 char xdata string[32];//访问内部拓展RAM，非访问外部RAM，不能超过内部拓展RAM大小(此处为1024) 

 va_start(ap,fmt); 
 vsprintf(string,fmt,ap);//此处也可以使用sprintf函数，用法差不多，稍加修改即可，此处略去 
 SendString(string); 
 va_end(ap); 
}  

/**********************************THE END**********************************/ 

 

