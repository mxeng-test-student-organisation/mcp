//Example ATmega2560 Project
//File: ATmega2560Project.c
//Author: Robert Howie
//Created: 26 February 2016
//An example file for second year mechatronics project

//include this .c file's header file
#include "Robot.h"

//static function prototypes, functions only called in this file


//file scope variables

//test
int main(void)
{
    //variable declarations
    
    //initialisation section, runs once
    serial0_init(); //initialise serial subsystem
    //put your initialisation code here
	
	_delay_ms(10); //some delay may be required
	
	while(1)//main loop
    {
		//put your loop code here
    }
    return(1);
}//end main
