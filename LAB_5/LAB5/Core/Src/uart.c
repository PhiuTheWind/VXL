/*
 * uart.c
 *
 *  Created on: Dec 9, 2024
 *      Author: phihv
 */


#include "uart.h"


uint16_t ADC_value = 0;
uint16_t old_value = 0;

uint8_t text[MAX_BUFFER_SIZE]= {0};
uint8_t index_text = 0;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE]={0};
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int has_ok = 0;
int check_first = 1;
int parser_status = 0;
int uart_status = 0;
int RST_flag = 0;


char str[MAX_BUFFER_SIZE]={0};

void clean_content(){
	memset(text, 0, sizeof(text));
}

void check_content(){
	if(text[0]=='R' && text[1]=='S' && text[2]=='T' && text[3] == '#'){ // If !RST# => flag on
		RST_flag=1;
		clean_content();
	}
	else if(text[0]=='O' && text[1]=='K' && text[2]=='#' && RST_flag==1){   // If !OK# => end
		uart_status=END;
		RST_flag=0;
	}
	else if((text[0]!='R' || text[1]!='S' || text[2]!='T' || text[3] != '#') && RST_flag==0){ // Wrong syntax content
		uart_status=END;
		HAL_UART_Transmit(&huart2, (uint8_t*)str, sprintf(str, "Wrong syntax \n"), 1000);
	}
	else{  // The last case user have not enter "OK"
		uart_status=SENDING;
	}
}
void command_parser_fsm(){
	switch(parser_status){
	case INIT:
		if(temp == '!'){ // If the first is !, it will move to the parser to add the char into buffer, else, do not thing
			parser_status=PARSER;
			index_text = 0;
		}
		break;
	case PARSER: // Check if Enter was push or not, if Push, move to check content between ! and #, else continue save data
		if(temp == '\r'){
			check_content();
			parser_status=INIT;
		}
		else if(temp != '\r'){
			text[index_text] = temp;
			index_text++;
			if(index_text == MAX_BUFFER_SIZE){
				index_text = 0;
			}
		}
		break;
	default:
		break;
	}
}

void uart_communication_fsm(){
	switch(uart_status){
	case WAIT: // Wait the signal of RST_flag
		if(RST_flag==1){
			uart_status=SENDING;
			setTimer2(200);
		}
		break;
	case SENDING: //Sending data when  RST_flag = 1 and timer 2 count down to 0
		if (timer2_flag == 1) {
			if(check_first == 1)
			{
				ADC_value= HAL_ADC_GetValue(&hadc1);
				HAL_UART_Transmit(&huart2, (uint8_t*)str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
				old_value = ADC_value;
				check_first = 0;
				setTimer2(300);
			}
			else if(check_first == 0)
			{
				HAL_UART_Transmit(&huart2, (uint8_t*)str, sprintf(str, "!ADC=%d#\r\n", old_value), 1000);
				setTimer2(300);
			}
		}
		break;
	case END: // clear memory and back to Wait for new communication
		clean_content();
		uart_status = WAIT;
		HAL_UART_Transmit(&huart2, (uint8_t*)str, sprintf(str, "End. \n"), 1000);
		check_first = 1;
		break;
	default:
		break;
	}
}
