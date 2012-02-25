#include <p24F16KA102.h>
#include "delayNOP.h"

#include "io.h"
#include "laserTagHardware.h"
#include "playerInfo.h"
#include "gameSM.h"

// 2 is board with all the shit
// 3 is left board
// 4 is kelly
//5 is isaac
_FWDT	(FWDTEN_OFF);
_FOSCSEL(FNOSC_FRCPLL );
_FOSC   ( POSCFREQ_HS & POSCMOD_HS & OSCIOFNC_OFF );


char bit_counter;
unsigned char command;
unsigned char old_nibble;
unsigned char rx_counter;
unsigned char values[8];

unsigned char rx_timeout;

unsigned long long int counter = 0;
int main(void){
    
    
    //set up interupt to debounce trigger, maybe establish game clock
    enableIO();

    

    
   
    
   




    Nop();


    updateDisplay(lives);

    TRISBbits.TRISB2 = 1; //
    Nop();
    TRISAbits.TRISA6 = 0;
    Nop();
    TRISAbits.TRISA4 = 1;
    Nop();

    TRISBbits.TRISB0 =0;
    AD1PCFG = 0xffff;
    
    while(1){

        
        
    }

}








void _ISR _U1RXInterrupt (void){
#ifndef SPECIAL_FUNCTION
            unsigned char temp = U1RXREG;


            if(U1STAbits.FERR==1){
                //do nothing
                rx_counter= 0;

            }else{
               
                

                    if(rx_counter<5){
                        rx_timeout = 0;
                        values[rx_counter] = temp;
                        rx_counter++;
                    }else if(rx_counter==5){
                        values[rx_counter] = temp;
                        rx_counter = 0;
                        
                       
                    }
                    
                
                

            }
#endif
 IFS0bits.U1RXIF = 0;
  //UART1PutChar(temp);
}
