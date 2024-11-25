/*
 * scheduler.c
 *
 *  Created on: Nov 10, 2024
 *      Author: phihv
 */


#include "scheduler.h"
#include "timer.h"
#include "global.h"
#include <stdio.h>
#include "main.h"
#include <string.h> // Added for UART data formatting


// Define array list of tasks and variable count number of tasks
sTask SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

extern UART_HandleTypeDef huart2;

// Delete Task
uint8_t SCH_Delete_Task(uint32_t taskID) {
    if (taskID >= current_index_task) {
        return -1; // No task to delete
    }
    for (int i = taskID; i < current_index_task - 1; i++) {
        SCH_tasks_G[i] = SCH_tasks_G[i + 1];
    }
    // Reset the last task after shifting
    current_index_task--;
    SCH_tasks_G[current_index_task].pTask = NULL;
    SCH_tasks_G[current_index_task].Delay = 0;
    SCH_tasks_G[current_index_task].Period = 0;
    SCH_tasks_G[current_index_task].RunMe = 0;
    SCH_tasks_G[current_index_task].TaskID = 0;
    return taskID;
}


// Initialize SCH_task and delete all tasks
void SCH_Init(void) {
    for (int i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_tasks_G[i].pTask = NULL;
        SCH_tasks_G[i].Delay = 0;
        SCH_tasks_G[i].Period = 0;
        SCH_tasks_G[i].RunMe = 0;
        SCH_tasks_G[i].TaskID = 0;
    }
    current_index_task = 0;
}


uint32_t SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    if (current_index_task >= SCH_MAX_TASKS) {
        // Error: Task queue overflow
        // Implement an error handler here
        return -1;
    }
    // Initialize new task
    SCH_tasks_G[current_index_task].pTask = pFunction;
    SCH_tasks_G[current_index_task].Delay = DELAY / TIME_CYCLE;
    SCH_tasks_G[current_index_task].Period = PERIOD / TIME_CYCLE;
    SCH_tasks_G[current_index_task].RunMe = 0;
    SCH_tasks_G[current_index_task].TaskID = current_index_task;

    current_index_task++; // Update current task index

    return SCH_tasks_G[current_index_task - 1].TaskID;
}


void SCH_Update(void) {
    static uint32_t elapsed_time = 0;
    elapsed_time += TIME_CYCLE;
    for (int i = 0; i < current_index_task; i++) {
        if (SCH_tasks_G[i].Delay > 0) {
            SCH_tasks_G[i].Delay--;
        }
        if (SCH_tasks_G[i].Delay == 0) {
            SCH_tasks_G[i].RunMe++;
            if (SCH_tasks_G[i].Period > 0) {
                SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period; // Reset Delay for periodic tasks
            }

            // Print the elapsed time for the task update via UART
            char timestamp[100];
            sprintf(timestamp, "Task %d updated at elapsed time %lu ms\r\n", i, elapsed_time);
            HAL_UART_Transmit(&huart2, (uint8_t *)timestamp, strlen(timestamp), 1000);
        }
    }
}


void SCH_Dispatch_Tasks(void) {
    for (int i = 0; i < current_index_task; i++) {
        if (SCH_tasks_G[i].RunMe > 0) {
            if (SCH_tasks_G[i].pTask != NULL) {
                (*SCH_tasks_G[i].pTask)(); // Execute task
            }
            SCH_tasks_G[i].RunMe--; // Decrease RunMe count

            // If it's a one-shot task, delete it from the list
            if (SCH_tasks_G[i].Period == 0) {
                SCH_Delete_Task(i);
                i--; // Adjust index to check the next task after shifting
            }
        }
    }
}
