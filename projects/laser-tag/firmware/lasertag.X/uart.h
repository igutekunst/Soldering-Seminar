#ifndef UART_H
#define UART_H

void UART1GuteInit(int BAUD);
void UART1Init(int BAUD);
void UART1PutChar(char c);
char UART1GetChar();

void UART2Init(int BAUD);
void UART2PutChar(char c);
char UART2GetChar();

#endif
