//---------------------------------//
// Main Project File
//---------------------------------//
//---------------------------------//
//Project: Traffic Lights          //
//Author: Vaidhun, Sudharsan       //
//---------------------------------//

#include <stdio.h>
#include "main.h"
#include "port.h"
#include "uart.h"
#include "blink.h"
#include "unit_test.h"
#include "traffic.h"

void main(void)
{
	CKCON0 = CKCON_V;
	AUXR = 0x0C;

	LED_FLASH_Init();
	LED_Test();

	UART_Init(9600);
	UART_Test();

	printf("Traffic Systems initialized.\n");
	timer_2_init();

	while(1) {
		
	}
}