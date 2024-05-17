///*
// * main.c
// *
// *  Created on: 22 Oct 2023
// *      Author: Ali
// */
//
//
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#define F_CPU 8000000
#include "util/delay.h"

#define PERIOD 15
u8 str[] = "Lol "
		"";
void send_byte(u8 Byte);
void main(void)
{
	DIO_SetPortDirection(PORT_A,PORT_OUTPUT);
	while(1)
	{
		u8 i = 0;
		while(str[i] != '\0')
		{
			send_byte(str[i]);
			i++;
			_delay_ms(1000);
		}

	}

}

void send_byte(u8 Byte)
{
	DIO_SetPinValue(PORT_A,PIN_LOW,PIN_0);
	_delay_ms(PERIOD);

	for(u8 i = 0;i<=7;i++)
	{
		DIO_SetPinValue(PORT_A,(Byte&(0x01<<i)) != 0,PIN_0);
		_delay_ms(PERIOD);
	}
	DIO_SetPinValue(PORT_A,PIN_HIGH,PIN_0);
	_delay_ms(PERIOD);

}
