/*----------------------------------------------------------   
 * ��Ŀ����:

     ����ͨ����������

 * ��������:

     1�����ڳ�ʼ��  
	 2����ѯ������һ���ֽ� 
	 3�����ڷ���һ���ֽ�
	 4�����ڷ���һ���ַ��� 

 * ��Ȩ��Ϣ:

     (c) �������, 2012.

 * ��ʷ�汾:
     2012-06-30:
       - ��ʼ�汾 V1.0.0;

 * ����˵��:
     MCU:             STC15W408AS
     ������:       	  STC15W408AS��Сϵͳ��
     ����:      	    �ڲ�ʱ��11.0592M
     ��չģ��:  	  -
     ���:            Keil.C51.V9.01


 * ��ע:
     - ��������Ĵ�������Դ�������

----------------------------------------------------------*/   
#ifndef _USART_H_
#define _USART_H_

extern unsigned char *pchar;

#define max_rebuf  10
  // receive form server data
  typedef struct 
  {
	  unsigned char receive_len;
	  unsigned char receive_status; /*1  : idle,0:receiving,2,wait process*/
	  char	 receive_buf[max_rebuf];
  
  } Receive_D;

void InitSerialPort(void);					//���ڳ�ʼ������
unsigned char ReceiveByte(void);			//���ڲ�ѯ������һ���ֽ�
void SendByte(unsigned char sbyte);			//���ڷ���һ���ֽ�
void SendString(unsigned char *pstr);		//���ڷ���һ���ַ���
void uart_printf(const char *fmt,...); 

#endif

//-------------------------THE END------------------------*/   

