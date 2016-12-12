// Written by Niklas Kamateros


#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */





void screen ();{

}

void screenupdate();{

}


void labinit( void ) { //needs to be updated to match our project
        volatile int* trise = (volatile int *) 0xbf886100; //gives the pointer its address
        *trise &= 0xff00;//sets the bits 7-0 as output

        TRISD = 0xfe0; //sets the bits 11 through 5 as input
        TMR2 = 0; //initialize timer
        T2CON = 0x170; // To get 1:256 prescale value.
        PR2 = (80000000 / 256) / 10;
        T2CONSET = 0x8000; // Start the timer
        return;
}
