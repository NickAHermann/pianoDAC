// Piano.c
// This software configures the off-board piano keys
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "tm4c123gh6pm.h"

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void){
	unsigned long volatile delay;
 SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; // activate port E
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTE_AMSEL_R &= ~0x0F;      // no analog
  GPIO_PORTE_AFSEL_R &= ~0x0F ; // disable alt funct on PE3-0
	GPIO_PORTE_DIR_R &= ~0x0F;     // make PE3-0 in
	GPIO_PORTE_DEN_R |= 0x0F;   // enable digital I/O on PE3-0
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2, 0x08 is just Key3
uint32_t Piano_In(void){
	uint16_t input;
	input = (GPIO_PORTE_DATA_R & 0x0F);
  return input; 
}
