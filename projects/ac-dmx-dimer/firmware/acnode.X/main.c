#include <p24F16KA102.h>
#include <string.h>
#include <stdlib.h>
//_FWDT	(FWDTEN_OFF);
//_FOSC   (POSCFREQ_HS & OSCIOFNC_ON & POSCMOD_HS);

_FWDT	(FWDTEN_OFF);
_FOSCSEL(FNOSC_FRCPLL );
_FOSC   ( POSCFREQ_HS & POSCMOD_HS & OSCIOFNC_ON );
#define CHANNEL_1_TRIS (TRISAbits.TRISA1)
#define CHANNEL_2_TRIS (TRISAbits.TRISA0)
#define CHANNEL_3_TRIS (TRISBbits.TRISB11)
#define CHANNEL_4_TRIS (TRISBbits.TRISB10)
#define CHANNEL_5_TRIS (TRISBbits.TRISB4)
#define CHANNEL_6_TRIS (TRISAbits.TRISA4)

#define CHANNEL_1_LAT (LATAbits.LATA1)
#define CHANNEL_2_LAT (LATAbits.LATA0)
#define CHANNEL_3_LAT (LATBbits.LATB11)
#define CHANNEL_4_LAT (LATBbits.LATB10)
#define CHANNEL_5_LAT (LATBbits.LATB4)
#define CHANNEL_6_LAT (LATAbits.LATA4)
#include "delayNOP.h"
int brightness =1;
int counter = 0;

unsigned int dmx_index = 0;
unsigned char triggered = 0;
unsigned short dmx_values[512];

void main(void){

    delay(10);

    AD1PCFG = 0xffff;
   
    
    char buffer[20];
    char* buffPtr = &buffer[0];

    TRISBbits.TRISB5 = 0;
    
    Nop();
    //UART1TX
    TRISBbits.TRISB7 = 0;

    
    Nop();
    TRISBbits.TRISB14 = 1;
    Nop();
    TRISBbits.TRISB12 = 0;
    Nop();
    LATBbits.LATB12 = 0;

    CHANNEL_1_TRIS = 0;
    Nop();
    CHANNEL_2_TRIS = 0;
    Nop();
    CHANNEL_3_TRIS = 0;
    Nop();
    CHANNEL_4_TRIS = 0;
    Nop();
    CHANNEL_5_TRIS = 0;
    Nop();
    CHANNEL_6_TRIS = 0;
    Nop();



   UART1DMXInit(7);//250000
/*
    dmx_values[0] = 150;
    dmx_values[1] = 150;
    dmx_values[2] = 150;

    dmx_values[3] = 150;
    dmx_values[4] = 150;
    dmx_values[5] = 150;
    dmx_values[6] = 150;

    dmx_values[7] = 150;
    dmx_values[8] = 150;
    dmx_values[9] = 150;

    dmx_values[10] = 150;
    dmx_values[11] = 150;
    dmx_values[12] = 150;
*/
    

    //external interrupt config
    INTCON2bits.INT2EP = 0; //inerrupt on positive edge
    // IPC6bits.INT2IP = 0b1; //priority of 1
  IEC1bits.INT2IE = 1; //enable external interrupt 1


    T2CONbits.T32 = 0; //don't link timer 2 and 3

    //timer 3
    LATBbits.LATB12 = 0;
    T3CON = 0x00; //Stops the Timer3 and reset control reg.
    TMR3 = 0x00; //Clear contents of the timer register
    T3CONbits.TCKPS = 0b01; // 1:8 prescale
    T3CONbits.TCS = 0;      // internal clock source
    //IPC3bits = 0x01; //Setup Timer3 interrupt for desired priority
    PR3 = 0xffff;          //full period
    T3CONbits.TCS = 0;
    IEC0bits.T3IE = 1; //enable interrupts for timer

    //timer 2

    T2CON = 0x00; //Stops the Timer3 and reset control reg.
    TMR2 = 0x00; //Clear contents of the timer register
    T2CONbits.TCKPS = 0b01; // 1:8 prescale
    T2CONbits.TCS = 0;      // internal clock source
    //IPC3bits = 0x01; //Setup Timer3 interrupt for desired priority
    PR2 = 0xffff;          //full period
    T2CONbits.TCS = 0;
    IEC0bits.T2IE = 1; //enable interrupts for timer2
   
   
    while(1){
        
        LATBbits.LATB5 = 1;
       
    }

}

void _ISR _INT2Interrupt(void){
    triggered = 1;
    counter = 255;
    TMR3 = 0xfb20;//not very long...
    T3CONbits.TON = 1; //start the timer
    IFS1bits.INT2IF = 0; //clear the interrupt flag
}


void _ISR _T3Interrupt(void){
    /*brightness =    dmx_values[1];
    if(counter==brightness){
        LATBbits.LATB4 = 1;
        T2CONbits.TON = 1;

    }*/
    

    if(dmx_values[1]==counter){
        CHANNEL_1_LAT = 1;
        
   //     T2CONbits.TON = 1;
    }
    if(dmx_values[2]==counter){
        CHANNEL_2_LAT = 1;
     //   T2CONbits.TON = 1;
    }
    if(dmx_values[3]==counter){
        CHANNEL_3_LAT = 1;
       // T2CONbits.TON = 1;
    }
    if(dmx_values[4]==counter){
        CHANNEL_4_LAT = 1;
      //  T2CONbits.TON = 1;
    }

    if(dmx_values[5]==counter){
        CHANNEL_5_LAT = 1;
        //T2CONbits.TON = 1;
    }

    if(dmx_values[6]==counter){
        CHANNEL_6_LAT = 1;
        //T2CONbits.TON = 1;
    }
 
T2CONbits.TON = 1;
    TMR3 = 0xffee;//set to timer to expire soon
    IFS0bits.T3IF = 0;  //ack interrupt
    counter = counter - 1;
    if(counter==0){
        T3CONbits.TON = 0;      //disable timer
    }

}

void _ISR _T2Interrupt(void){
    TMR2 = 0xfff9;//not very long...
    //zTimer = 1;

    //LATBbits.LATB4 = 0;
    LATA = LATA &11100000;
    LATB = LATB & 0b11101111;
    //PR3 = period;          //full period
    IFS0bits.T2IF = 0;  //ack interrupt
    T2CONbits.TON = 0;      //disable timer
}

void _ISR _U1ErrInterrupt(void){
    IFS4bits.U1ERIF = 0;
    if(U1STAbits.FERR==1){
        dmx_index = 0;
        short lols = U1RXREG;
        IFS0bits.U1RXIF = 0;
    }
    if  ( U1STAbits.OERR == 1 ) {
        U1STAbits.OERR = 0;
    }
}


void _ISR _U1RXInterrupt (void){
    unsigned short temp = U1RXREG;
    if( temp & 256){
        temp = temp & 0xff; //chop of bit 8
        dmx_values[dmx_index] = temp;
        dmx_index++;
    }else{
        dmx_index = 0;
    }
    IFS0bits.U1RXIF = 0;    //acknowledge interrupt
}