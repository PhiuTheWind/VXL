/*
 * scheduler.h
 *
 *  Created on: Nov 10, 2024
 *      Author: phihv
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "main.h"  // File chứa các thư viện cần thiết
#include "stm32f1xx_hal.h"  // Thư viện HAL của STM32 (tùy dòng vi điều khiển bạn sử dụng)
#include "time.h"
#include "global.h"
#include <stdint.h>


// Task structure
typedef struct {
    void (*pTask)(void);    // Task function pointer
    uint32_t Delay;         // Delay before execution
    uint32_t Period;        // Repeat period
    uint8_t RunMe;          // Flag to indicate readiness
    //This is a hint to solve the question below.
    uint32_t TaskID;
} sTask;

// Define the maximum number of tasks
#define SCH_MAX_TASKS	10

// Function prototypes
void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(uint32_t taskID);




#endif /* INC_SCHEDULER_H_ */
