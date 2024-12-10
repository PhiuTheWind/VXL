/*
 * uart.h
 *
 *  Created on: Dec 9, 2024
 *      Author: phihv
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <main.h>
#include <string.h>
#include <timer.h>

#define INIT 1
#define PARSER 2
#define WAIT 3
#define SENDING 4
#define END 5
#define MAX_BUFFER_SIZE 30

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

extern uint16_t ADC_value;
extern uint8_t temp;
extern uint8_t text[MAX_BUFFER_SIZE];
extern uint8_t index_text;

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint16_t old_value;

extern int parser_status;
extern int uart_status;
extern int RST_flag;
extern int has_ok;
extern int check_first;

extern char str[MAX_BUFFER_SIZE];

void check_content();
void clean_contet();
void command_parser_fsm();
void uart_communication_fsm();


#endif /* INC_UART_H_ */
