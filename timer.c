#include <xc.h>
#include "timer.h"

void Timer23Gated_Init(void){
    T2CON = 0x0;                // Stops any Timer2 operation
    T3CON = 0x0;                // Stops any Timer3 operation
    T2CONbits.T32 = 1;          // TMRx and TMRy form a 32-bit timer
    T2CONbits.TGATE = 1;        // Gated time accumulation is enabled
    T2CONbits.TCS = 0;          // Internal peripheral clock
    T2CONbits.TCKPS = 0b111;    // Prescale value x256
    TMR2 = 0x0;                 // Timer2 count register
    TMR3 = 0x0;                 // Timer3 count register
    PR2 = 0xFFFFFFFF;           // Peroid register
    
    IEC0bits.T2IE = 0;	        // Disable Timer 2 Interrupt
    IFS0bits.T2IF = 0;	        // Clear interrupt flag for timer 2
    IPC2bits.T2IP = 3; 	        // Interrupt priority 3
    IPC2bits.T2IS = 1; 	        // Sub-priority 1
    IEC0bits.T2IE = 1;	        // Enable Timer 2 Interrupt
    
    T2CONbits.ON = 1;           // Module is enabled
}

void Timer2_Init(unsigned int frequency){
    T2CON = 0;
    TMR2 = 0;
    PR2 = SYS_FREQ / ( 8 * 2 * frequency );
    T2CONbits.TCKPS = 0b011;
    
	IEC0bits.T2IE = 0;
	IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 3;
    IPC2bits.T2IS = 1;
    IEC0bits.T2IE = 1;
	
	T2CONbits.ON = 1;
}