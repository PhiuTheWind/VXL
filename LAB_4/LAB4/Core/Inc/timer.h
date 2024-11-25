/*
 * timer.h
 *
 *  Created on: Nov 11, 2024
 *      Author: phihv
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"

#define TIME_CYCLE 10
extern int timer0_counter;
extern int timer0_flag;
extern int time_stamp;
extern int time_offset;


void setTimer0(int duration); // Set the duration for timer0
void timer_run(void);         // Function to run all counters


#endif /* INC_TIMER_H_ */
