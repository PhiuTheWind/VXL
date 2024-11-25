#include "main.h"
#include "timer.h"
#include "scheduler.h"

// Initialize timer counter variables and flags
int timer0_counter = 0;
int timer0_flag = 0;

// Define initialization function for timers
void setTimer0(int duration) {
    timer0_counter = duration / TIME_CYCLE;
    timer0_flag = 0;
}

// Run all counters, called in each interrupt cycle
void timer_run() {
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter <= 0) timer0_flag = 1;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) { // Check the correct timer instance
        SCH_Update();    // Update Scheduler on each interrupt
        timer_run();     // Run all timer counters
    }
}
