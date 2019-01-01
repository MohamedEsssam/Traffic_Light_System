/*
 * trafficLight.c
 *
 *  Created on: Jan 1, 2019
 *      Author: Mohamed Essam
 */
#include "avr/io.h"
#define F_CPU 8000000
#include "avr/delay.h"
#include "types.h"
#include "ulits.h"



void main(void){
	//SevenSegment Decoder array comman anode
	u8 sevenSegmentArr[10] = {0b11000000,
                              0b11111001,
                              0b10100100,
                              0b10110000,
							  0b10011001,
							  0b10010010,
							  0b10000010,
							  0b11111000,
							  0b10000000,
                              0b10010000};
    //output for leds
	DDRA = 0x07;
	//output for seven segment 1 (1 or 0)
	DDRC = 0xff;
	//output for seven segemnt 2 (1 -> 9)
	DDRD = 0xff;
	//intialize PORTA
	PORTA = 0x01;
	//counter from 9 to 1
	u8 counter;
	//couter for 1 and 0
	u8 count;

	while(1){
		//desplay 10 on seven segement and trun on green led 
		for (count = 0; count < 1; ++count) {
			PORTA = 0x01;
			PORTD = sevenSegmentArr[0];
			PORTC = sevenSegmentArr[1];
		   _delay_ms(1000);
					       }
		//down counter for green led
		for (counter = 9; counter > 0; --counter) {
			PORTC = sevenSegmentArr[0];
			PORTD = sevenSegmentArr[counter];
			_delay_ms(1000);
		              }
		//trun on yellow led and down counter for it 			  
		for (counter = 3; counter > 0; --counter) {
			PORTD = sevenSegmentArr[counter];
			PORTA = 0x02;
			_delay_ms(1000);
	        	}
		//desplay 10 on seven segement and trun on red led 
		for (count = 0; count < 1; ++count) {
			PORTA = 0x04;
			PORTD = sevenSegmentArr[0];
			PORTC = sevenSegmentArr[1];
			_delay_ms(1000);
	       }
		//down counter for red led
		for (counter = 9; counter > 0; --counter) {
			PORTC = sevenSegmentArr[0];
			PORTD = sevenSegmentArr[counter];
			_delay_ms(1000);
		}
	}
	return;
}