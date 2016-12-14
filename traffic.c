//------------------------------------------------------------------//
// C file for Traffic Lights - Simple
//------------------------------------------------------------------//
//------------------------------------------------------------------//
//Project: Traffic Light
//Author: Vaidhun, Sudharsan;
//------------------------------------------------------------------//

#include "traffic.h"

state_t traffic_state_g;
uint16_t tick_g = 0;

void timer_2_ISR (void) interrupt Timer_2_Overflow {
	TF2 = 0;
	tick_g += 10;
	switch (traffic_state_g) {
		case Green_state: {
			if (SW1 == 0) {
				traffic_state_g = Yellow_state;
				GREENLED = OFF;
				YELLOWLED = ON;
				REDLED = OFF;
				WHITELED = OFF;
				tick_g = 0;
			}
			break;
		}
		case Yellow_state: {
			if (tick_g >= 2000) {
				traffic_state_g = Red_state;
				GREENLED = OFF;
				YELLOWLED = OFF;
				REDLED = ON;
				WHITELED = ON;
				tick_g = 0;
			}
			break;
		}
		case Red_state: {
			if (tick_g >= 5000) {
				traffic_state_g = Walk_state;
				GREENLED = OFF;
				YELLOWLED = OFF;
				REDLED = ON;
				WHITELED = ON;
				tick_g = 0;
			}
			break;
		}
		case Walk_state: {
			if (tick_g >= 15000) {
				traffic_state_g = Green_state;
				GREENLED = ON;
				YELLOWLED = OFF;
				REDLED = OFF;
				WHITELED = OFF;
				tick_g = 0;
			} else {
				if((tick_g%1000)>=500)
					WHITELED = OFF;
				else
					WHITELED = ON;
			}
			break;
		}
	}
}

void timer_2_init(void) {
	traffic_state_g = Green_state;
	GREENLED = ON;
	YELLOWLED = OFF;
	REDLED = OFF;
	WHITELED = OFF;

	tick_g = 0;
	
	T2MOD &= 0xFC;
	T2CON = 0x00;
	EA = 1;
	ET2 = 1;

	TH2 = Tick_Reload_THx;  // Timer 2 initial value (High Byte)
	TL2 = Tick_Reload_TLx;  // Timer 2 initial value (Low Byte)
	RCAP2H = Tick_Reload_THx;
	RCAP2L = Tick_Reload_TLx;

	TR2 = 1;          // Start timer 2
}
