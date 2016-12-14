//------------------------------------------------------------------//
// Header file for Traffic Lights - Simple
//------------------------------------------------------------------//
//------------------------------------------------------------------//
//Project: Traffic Light
//Author: Vaidhun, Sudharsan;
//------------------------------------------------------------------//

#ifndef _TRAFFIC_SIMPLE_H
#define _TRAFFIC_SIMPLE_H

#include "main.h"
#include "port.h"

#define ON 1
#define OFF 0
#define one_msec 1

#define Tick_Reload (65536-((OSC_FREQ*one_msec)/(1020*OSC_PER_INST)))  
#define Tick_Reload_THx (Tick_Reload>>8)
#define Tick_Reload_TLx (Tick_Reload&0xff)

typedef enum {Green_state, Yellow_state, Red_state, Walk_state, Red_flash_state} state_t;

void timer_2_init(void);
void timer_2_ISR (void);

#endif