//Example ATmega2560 Project
//File: ATmega2560Project.c
//Author: Robert Howie
//Created: 26 February 2016
//An example file for second year mechatronics project

//include this .c file's header file
#include "Robot.h"

//static function prototypes, functions only called in this file
void function_1(uint8_t input_1, uint8_t * pointer_to_input_2); //example function prototype

//file scope variables
static bool boolean_varaible = true;
static uint8_t eight_bit_unsigned_variable = 255;
static int16_t sixteen_bit_signed_variable = -10000;
static uint32_t thirty_two_bit_unsigned_variable = BIG_NUMBER;

static uint8_t leds = 0x00; //initialise 8 bit unsigned file scope global integer variable LEDS to 0


int main(void)
{
    //variable declarations
    
    
    //initialisation section, runs once
    

    serial0_init(); //initialise serial subsystem
    _delay_ms(10); //some delay may be required 
    
    DDRA = 0xFF; //put whole of PORTA into output mode
    PORTA = leds; //redundant since PORTA should be initialised as 0 anyway (a bad boodloader could leave dirty registers though)
    
    while(1)//main loop
    {
        serial0_print_string(SERIAL_PRINT_MESSAGE); //print a string to the serial terminal
        _delay_ms(500); //1000 millisecond delay
        
		
        leds = leds + 1; //add one to leds and store the result back in leds, how else could you write this?
        PORTA = leds; //write leds to port A
    }
    return(1);
}//end main
