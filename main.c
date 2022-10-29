#include <xc.h>
#include "DeviceConfig.h"
#include "timer.h"

void __attribute__((vector(_TIMER_2_VECTOR), interrupt(ipl3srs), nomips16)) timer2_handler(){
	IFS0bits.T2IF = 0;	// Clear interrupt flag for timer 2
    
    // Interrupt body
    if(LATFbits.LATF0 == 0){
        LATFbits.LATF0 = 1;
    }else
        LATFbits.LATF0 = 0;
}

void main(void){
	// Set ports as digital
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELE = 0;
    ANSELG = 0;

    // Set pin for Timer23 Gate
    TRISFbits.TRISF1 = 1;   // button/trigger
    CNPDFbits.CNPDF1 = 1;   // Pull down resistor for F1 pin
    T2CKR = 0b1011;         // Set up PPS for Timer23 Gate, pin -> F1

    // Set pin for Timer2 signal output
    TRISFbits.TRISF0 = 0;
    
	Set_MaxSpeed_Mode();
//	Timer23Gated_Init();
    Timer2_Init(1000);
    
	while (1){
        
    }
}

