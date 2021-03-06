/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Farouk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
//#include "img.h"

/* letters as arrays */
u16 Letter_I[4*14] ={   0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,
		                0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0x0000, 0xAAAA,0xAAAA, 0x0000,
						0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,
						0xAAAA, 0xAAAA,0xAAAA, 0xAAAA     };

u16 Letter_L[6*14] ={	0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,0xAAAA,
                        0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
		                0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
       					0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA,
						0x0000,0x0000,0x0000,0x0000,0xAAAA,0xAAAA           };

u16 Letter_D[8*14] ={   0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA   };

u16 Letter_G[11*14] ={  0x0000, 0x0000, 0x0000, 0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000, 0x0000,
						0x0000, 0x0000, 0xAAAA, 0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000,
						0x0000, 0xAAAA, 0xAAAA, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0xAAAA, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000,0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000, 0x0000,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000   };

u16 Letter_T[8*14] ={   0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
						0x0000,0x0000, 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000,
                        0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
						0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA  };

u16 Letter_A[7*14] ={
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA,0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
        0xAAAA,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA,
		0x0000,0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000   };

u16 Letter_C[8*14] ={   0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000, 0x0000,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000,
						0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000, 0x0000   };

u16 Letter_K[6*14] ={    0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						 0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0xAAAA, 0x0000, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0xAAAA, 0x0000, 0xAAAA, 0xAAAA,
						 0x0000, 0xAAAA, 0xAAAA, 0x0000, 0xAAAA, 0xAAAA,
						 0xAAAA, 0xAAAA, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						 0xAAAA, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
						 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA   };

u16 Letter_O[8*14] ={
		0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0xAAAA, 0xAAAA, 0x0000, 0x0000, 0x0000, 0x0000, 0xAAAA, 0xAAAA,
		0x0000, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0xAAAA, 0x0000   };

u16 Num0[10*14] ={	    0x0000,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0x0000,
						0x0000,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0x0000,
                        0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
		                0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
       					0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0x0000,0x0000, 0x0000,0x0000, 0x0000,0x0000,0xAAAA,0xAAAA,
						0xAAAA,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0xAAAA,
						0x0000,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0x0000  };

u16 Num1[10*14] ={	    0x0000,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0x0000,
						0x0000,0xAAAA,0xAAAA,0xAAAA, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0xAAAA,0x0000,
                        0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
		                0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
       					0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0x0000,0xAAAA,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0x0000,0xAAAA,0xAAAA,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0xAAAA,0xAAAA,0x0000,0x0000,
						0x0000,0x0000,0x0000,0x0000, 0xAAAA,0xAAAA, 0xAAAA,0x0000,0x0000,0x0000   };


void main(void)
{
	/* RCC Init */
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);// GPIOA
	RCC_voidEnableClock(RCC_APB2,12);// SPI1

	/* DIO Init */
	MGPIO_voidSetPinDirection(GPIOA,1,OUTPUT_2MHZ_PP);// reset
	MGPIO_voidSetPinDirection(GPIOA,2,OUTPUT_2MHZ_PP);// A0
	MGPIO_voidSetPinDirection(GPIOA,5,OUTPUT_10MHZ_AF_PP);// clk
	MGPIO_voidSetPinDirection(GPIOA,7,OUTPUT_10MHZ_AF_PP);// MOSI

	/* systick Init */
	STK_voidInit();

	/* SPI Init */
	SPI1_voidInit();

	/* TFT Init */
	TFT_voidInit();

	TFT_voidFillColor(0x0000);

	/* Write " Digital Clk" */
	// need to modify the coordination for the word "DIGITAL"
	TFT_voidDrawRectangle(0,127,135,158,0x6E7F);// background for "DIGITAL CLK"

	TFT_voidDrawChar(85+15,92+15 ,140,153,Letter_D);//8
	TFT_voidDrawChar(79+15,82+15 ,140,153,Letter_I);//4
	TFT_voidDrawChar(66+15,76+15 ,140,153,Letter_G);//11
	TFT_voidDrawChar(60+15,63+15 ,140,153,Letter_I);
	TFT_voidDrawChar(50+15,57+15 ,140,153,Letter_T);//8
	TFT_voidDrawChar(41+15,47+15 ,140,153,Letter_A);//7
	TFT_voidDrawChar(33+15,38+15 ,140,153,Letter_L);//6

	TFT_voidDrawChar(16+15,23+15 ,140,153,Letter_C);//8
	TFT_voidDrawChar(8 +15,13+15 ,140,153,Letter_L);//4
	TFT_voidDrawChar(0 +15,5 +15 ,140,153,Letter_K);//6


	TFT_voidDrawRectangle(0,127,0,15,0x6E7F);//background for the clock

	TFT_voidDrawChar(100 ,109 ,0,13,Num0);// hours a7ad
	TFT_voidDrawChar(112 ,121 ,0,13,Num0);// hours 34raat

	TFT_voidDrawChar(74 ,83 ,0,13,Num0);// mins a7ad
	TFT_voidDrawChar(86 ,95 ,0,13,Num0);// mins 34raat

	TFT_voidDrawChar(46 ,55 ,0,13,Num0);// secs a7ad
	TFT_voidDrawChar(58 ,67 ,0,13,Num0);// secs 34raat

	TFT_voidDrawChar(25,31,0,13,Letter_A);
	TFT_voidDrawChar(16,22,0,13,Letter_A);

	STK_voidSetIntervalPeriodic(1000,TFT_voidStartClk);
	//TFT_voidStartClk();

	while(1);


}
