/*----------------------------------------------------------   
 * ��Ŀ����:

     ����ͨ����������

 * ��������:

     1�����ڳ�ʼ��  
	 2����ѯ������һ���ֽ� 
	 3�����ڷ���һ���ֽ�
	 4�����ڷ���һ���ַ��� 
	 5�������жϷ�ʽ����һ���ַ�

 * ����˵��:
     MCU:             STC15W408AS
     ������:       	  STC15W408AS��Сϵͳ��
     ����:      	    �ڲ�ʱ��11.0592M
     ��չģ��:  	  -
     ���:            Keil.C51.V9.01

 * ��ע:
     - ��������Ĵ�������Դ�������

----------------------------------------------------------*/   

#include<STC15W.h>
#include<USART.h>
#include <intrins.h>
#include <stdio.h>   //����printf
#include <stdarg.h>  //����vsprintf����ԭ��

unsigned char *pchar;				//����һ��ȫ��ָ��

//----------------------------------------------------------   
//  �������ƣ�void IniSerialPort(void)   
//  �������ܣ����ڳ�ʼ��   
//----------------------------------------------------------   
void InitSerialPort(void)
{ 
		SCON = 0x50;			//8λ���ݣ��ɱ䲨����
		AUXR |= 0x01;			
		AUXR |= 0x04;			//��ʱ��ʱ��ΪFosc��1Tģʽ
		T2L = 0xFA;				//��ʱ����ֵ���ڲ�ʱ��11.0592M��������115200=E8 ;921600=FD; 460800=FA
		T2H = 0xFF;				//��ʱ����ֵ
		AUXR |= 0x10;			//������ʱ��
    ES=0; 					//�����жϿ���,���ò�ѯ��ʱ���ô��ж�      
    REN=1;      			//����Ϊ������ʽ1�������������
    SM0=0;						//SM0 SM1���ڹ�����ʽѡ��01��8λ�첽�շ����������ɶ�ʱ������
    SM1=1;

}
//----------------------------------------------------------   
//  �������ƣ�unsigned char ReceiveByte(void)
//  �������ܣ���ѯ������һ���ֽ�   
//----------------------------------------------------------   
unsigned char ReceiveByte(void)
{
     unsigned char rbyte;
     while(!RI); 					//��ѯ���ձ�־λ���Ƿ������ݵ��ﻺ����
     RI=0; 							//������ձ�־λ
     rbyte=SBUF; 					//�ӻ�������ȡ����
     return rbyte;
}
//----------------------------------------------------------   
//  �������ƣ�void SendByte(unsigned char sbyte)
//  �������ܣ����ڷ���һ���ֽ�
//----------------------------------------------------------   
void SendByte(unsigned char sbyte)
{  
     SBUF=sbyte; 					//��������
     while(!TI); 					//�ȴ��������
     TI=0; 							//���㷢�ͱ�־λ
}
//----------------------------------------------------------   
//  �������ƣ�void SendString(unsigned char *pstr)
//  �������ܣ����ڷ���һ���ַ���
//----------------------------------------------------------   
void SendString(unsigned char *pstr)
{
     while(*pstr!='\0') 			//�ַ����Ƿ���
     {
         SendByte(*pstr);			//�����ַ�������
         pstr++; 					//ָ����һ���ַ�
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
//  �������ƣ�void SerialPortInte(void)
//  �������ܣ������жϷ�ʽ����һ���ַ�
//----------------------------------------------------------   
unsigned char set_v,gpio_n;  
void SerialPortInte(void) interrupt 4  
{ 
	if(RI)
	{

		RI=0;						    //������ձ�־λ
/*		*pchar=SBUF;					//��ȡ������������		
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
 char xdata string[32];//�����ڲ���չRAM���Ƿ����ⲿRAM�����ܳ����ڲ���չRAM��С(�˴�Ϊ1024) 

 va_start(ap,fmt); 
 vsprintf(string,fmt,ap);//�˴�Ҳ����ʹ��sprintf�������÷���࣬�Լ��޸ļ��ɣ��˴���ȥ 
 SendString(string); 
 va_end(ap); 
}  

/**********************************THE END**********************************/ 

 

