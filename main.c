//---------------------------------//
// Main Project File
//---------------------------------//
//---------------------------------//
//Project: MP3 Player
//Author: Singh, Siddharth; Vaidhun, Sudharshan;
//		  Sengupta, Ayush
//---------------------------------//

#include <stdio.h>
#include "main.h"
#include "port.h"
#include "uart.h"
#include "delay.h"
#include "blink.h"
#include "lcd.h"
#include "print_bytes.h"
#include "memory_test.h"
#include "unit_test.h"
#include "SPI.h"
#include "SD_Card.h"

void main(void)
{
	uint8_t received_value;

	CKCON0 = CKCON_V;

	LED_FLASH_Init();
	LED_Test();

	LCD_Init();
	LCD_Test();

	UART_Init(9600);
	UART_Test();

	SPI_Master_Init(400000);
	SD_Init();

	Memory_Test();

	Xdata_Memory_Test();
	
	while(1)
	{
		received_value = UART_Recieve();
		UART_Transmit(received_value);
		LCD_Write(DATA,received_value);
	}
}