#include <p24F16KA102.h>
#include "uart.h"

void UART1Init(int BAUD){

    U1BRG = BAUD;
    U1MODE = 0x8000;
    U1STA = 0x8400;
    IFS0bits.U1RXIF = 0;
}

void UART1DMXInit(int BAUD){

    U1BRG = BAUD;
    U1MODEbits.RXINV = 0;//idle is one?
    U1MODEbits.BRGH = 1; //high speed mode
    U1MODEbits.PDSEL = 0b11;//9 bits, no parity
    U1MODEbits.RTSMD = 1;
    
    U1MODEbits.STSEL = 0;//one stop bit
    U1MODEbits.UARTEN = 1;
    U1MODEbits.UEN = 0; //only rx and tx pins are used
    U1STAbits.URXISEL = 0x00;//interrupt every char

    U1STA = 0x8400;
    IEC4bits.U1ERIE = 1; //enable error interrupt
    IEC0bits.U1RXIE = 1; //enable receive interrupt

    IFS0bits.U1RXIF = 0;
}

UART1GuteInit(int BAUD){
    U1BRG = BAUD;
    U1MODEbits.RXINV = 0;//idle is one,definitely
    U1MODEbits.BRGH = 0; //high speed mode
    U1MODEbits.PDSEL = 0b00;//8 bits, no parity
    U1MODEbits.RTSMD = 1;

    U1MODEbits.STSEL = 0;//one stop bit
    U1MODEbits.UARTEN = 1;
    U1MODEbits.UEN = 0; //only rx and tx pins are used
    U1STAbits.URXISEL = 0x00;//interrupt every char

    U1STA = 0x8400;
   // IEC4bits.U1ERIE = 1; //enable error interrupt
    IPC2bits.U1RXIP = 0x02; //priority of 2..
   IEC0bits.U1RXIE = 1; //enable receive interrupt

    IFS0bits.U1RXIF = 0;
}
void UART2Init(int BAUD){

    U2BRG = BAUD;
    U2MODE = 0x8000;
    U2STA = 0x8400;

    IFS1bits.U2RXIF = 0;
}

void UART1PutChar(char c){
    while(U1STAbits.UTXBF == 1);
    U1TXREG = c;
}

void UART2PutChar(char c){
    while(U2STAbits.UTXBF == 1);
    U2TXREG = c;
}

char UART1GetChar(){
    char Temp;
    while(IFS0bits.U1RXIF == 0);
    Temp = U1RXREG;
    IFS0bits.U1RXIF = 0;
    return Temp;
}

char UART2GetChar(){
    char Temp;
    while(IFS1bits.U2RXIF == 0);
    Temp = U2RXREG;
    IFS1bits.U2RXIF = 0;
    return Temp;
}


void printStringConstant(const char * data){
    while(*data != '\0'){
        UART1PutChar(*data);
        data++;
    }
}

