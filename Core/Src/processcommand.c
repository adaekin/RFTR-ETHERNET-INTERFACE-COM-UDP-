/*
 * processcommand.c
 *
 *  Created on: Jul 23, 2026
 *      Author: dogukan.tuncer
 */


#include "main.h"

void Process_Command(const char *cmd, volatile int *led_status){

	if(cmd == NULL) return;

	// CMD:LED:AC

	char HEADER[10] = {0};
	char TARGET[10] = {0};
	char ACTION[10] = {0};
	int parsed_count = sscanf(cmd, "%9[^:]:%9[^:]:%9[^:\r\n]", HEADER, TARGET, ACTION);
	if(parsed_count == 3 && strncmp(HEADER, "CMD", 3) == 0){
		if (strncmp(TARGET, "LED", 3) == 0)
		        {
		            if (strncmp(ACTION, "AC", 2) == 0)
		            {
		            	*led_status = 1;
		            	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, GPIO_PIN_SET);
		            }
		            else if (strncmp(ACTION, "KAPAT", 5) == 0)
		            {
		            	*led_status = 0;
		            	HAL_GPIO_WritePin(led1_GPIO_Port, led1_Pin, 0);
		            }
		        }
		else if (strncmp(TARGET, "ROLE", 4) == 0) // ORNEK KOD
		        {
		            if (strncmp(ACTION, "AC", 2) == 0)
		            {
		            }
		        }
		return;
	}
	else{
// NACK DÖNDÜR
	}
}
