#define HAMMING
#include "irSerial.h"

#include <p24F16KA102.h>
unsigned char local_tx_buffer;
unsigned char tx_buffer = 0;
unsigned char tx_status = IR_IDLE;
unsigned char pr = 0;
unsigned char current_bit;
unsigned char enable = 0;
unsigned char current_nibble = 0;

void enableIrSerial(){


    IR_OUT_TRIS = 0;
    
    T3CON = 0x00; //Stops the Timer3 and reset control reg.
    TMR3 = 0x00; //Clear contents of the timer register
    T3CONbits.TCKPS = 0b00; // 1:1 prescale
    T3CONbits.TCS = 0;      // internal clock source
    //IPC2bits.T3IP = 0x01; //Setup Timer1 interrupt for desired priority
    PR3 = 110;
    T3CONbits.TCS = 0;
    IPC2bits.T3IP = 0x03;
    IEC0bits.T3IE = 1; //enable interrupts for timer1

    T3CONbits.TON = 1;
}

void irPrintStringConstant(const char * data){
    while(*data != '\0'){
        irPutChar(*data);
        data++;
    }
}

void irEscapeSequence(const char * data){
    irPutChar(0x1B);
    while(*data != '\0'){
        irPutChar(*data);
        data++;
    }
}

 void irPutChar(char c){
   while(tx_status != IR_IDLE);
    local_tx_buffer = c;
    tx_status = 0;
 }


#ifdef HAMMING
 void _ISR _T3Interrupt(void){
   if(enable){

      //  PR3 = 0x71;
        LATAbits.LATA6 = current_bit;


    }else{
        //PR3 = 0x0;
        LATAbits.LATA6 = 0;

    }

    enable = !enable;
    pr = (pr +1);

    if(pr>15){
        //t = !t;
        pr = 0;
        //tx state machine is ticking here

       // current_bit = !current_bit;
            if(tx_status==0){
                //send start bit
                current_bit = 1;
                local_tx_buffer = tx_buffer;

                tx_status++;
            }else if (tx_status<9){
                //current_bit = !(local_tx_buffer & 0x80)&& 1;
                current_bit = !(local_tx_buffer &1);

                local_tx_buffer = local_tx_buffer >>1;

                //
                tx_status++;
            } else if(tx_status <IR_DONE){
                current_bit = 0;
                tx_status++;
            }else if(tx_status==IR_DONE){
                tx_status=IR_IDLE;
                current_bit = 0;

            }
    }




    IFS0bits.T3IF = 0; //ack interrupt

}
#endif