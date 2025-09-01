/*--------------------------------------------------------------------------------
  
-------------------------------------------------------------------------------------*/
/************************ ***************************************************/

//#include<STC15W.h>
#include<USART.h>

#include <intrins.h>

#include	"GPIO.h"
#include	"STC15Fxxxx.H"

sbit out_pin = P1^5;


//=========================================================================
//Variables and arrays used for communications and data storage
//=========================================================================

//char Direct=0;
 void Delay100us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}

void delay_ms(unsigned int ms)
{
  ms=ms*10;	
  do
  {
     Delay100us();
  }while(--ms);

}


void	GPIO_config(void)
{

	
	GPIO_InitTypeDef	GPIO_InitStructure;		// 
	GPIO_InitStructure.Pin  = GPIO_Pin_All ;//GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;		// 
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		// 
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);	// 
	
		GPIO_InitStructure.Pin  = GPIO_Pin_All;		// 
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		// 
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);	// 
	GPIO_InitStructure.Pin  =  GPIO_Pin_All;		// 
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		// 
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);	// 

	GPIO_InitStructure.Pin  =  GPIO_Pin_4|GPIO_Pin_5;		// 
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		// 
	GPIO_Inilize(GPIO_P5,&GPIO_InitStructure);	// 
	P1=0x00;
	P2=0x00;
	P37=0;
	//P3=0x00;
	P54=1;
	P55=0;

}
extern unsigned char set_v,gpio_n; 
void (*set_gp[6])(void);

void Set_P1(void)
{
	P1=P1|(1<<gpio_n);
}
void Reset_P1(void)
{
	P1=P1&(~(1<<gpio_n));
}

void Set_P3(void)
{
	P3=P3|(1<<gpio_n);
}
void Reset_P3(void)
{
	P3=P3&(~(1<<gpio_n));
}

void Set_P5(void)
{
	P5=P5|(1<<gpio_n);
}
void Reset_P5(void)
{
	P5=P5&(~(1<<gpio_n));
}

 void P1_GPIO_set(void)
{
	set_gp[set_v%2]();
	
}
void P3_GPIO_set(void)
{
	gpio_n-=8;
	set_gp[set_v%2+2]();
	
}
  void  P5_GPIO_set(void)
{
	gpio_n-=16;
	set_gp[set_v%2+4]();
	
}


//=========================================================================

/************************主函数******************************************************/
void main()  
{
    unsigned char rdata=0;
	  void (*gp[3])(void);
		gp[0]=P1_GPIO_set;
	  gp[1]=P3_GPIO_set;
	  gp[2]=P5_GPIO_set;
	  set_gp[1]=Set_P1;
	  set_gp[0]=Reset_P1;
	  set_gp[3]=Set_P3;
	  set_gp[2]=Reset_P3;
	  set_gp[5]=Set_P5;
	  set_gp[4]=Reset_P5;
	
   
	 
	//////////////////
	
  ///////////////  initial extern interrupt
	EA=1;										//使能全局中断
  GPIO_config();
  InitSerialPort(); 									//初始化串口    

  uart_printf(" copyright to pandapi3d.com \n") ;
   
	
    while(1)
    {
			//*pchar=ReceiveByte();
			 while(!RI)  	
			 {
				 // SendByte(P1);
			 }			
       RI=0; 							 
     *pchar=SBUF; 	
			gpio_n=*pchar&0x1F;// 
		//	 set_v=(*pchar>>6);
		  set_v=(*pchar>>5)&0x01;	 
		//	gp[gpio_n/8]();
		{
			
			
			if(gpio_n<8)
			{
				if(set_v)
					P1=P1|(1<<gpio_n);
				else
					P1=P1&(~(1<<gpio_n));
			}
			else if(gpio_n<16)
			{
			//	gpio_n-=8;
				if(set_v)
					P2=P2|(1<<(gpio_n-8));
				else
					P2=P2&(~(1<<(gpio_n-8)));
			}
			else if(gpio_n<24)
			{
				//gpio_n-=16;
				if(set_v)
					P3=P3|(1<<(gpio_n-16));
				else
					P3=P3&(~(1<<(gpio_n-16)));
			}
			else  
			{
				//gpio_n-=16;
				if(set_v)
					P5=P5|(1<<(gpio_n-24));
				else
					P5=P5&(~(1<<(gpio_n-24)));
			}			
		}
		//*/
	
	    
    }
}  
/*********************************The End****************************************/
