#ifndef IR_SERIAL_H
#define IR_SERIAL_H
#include "laserTagHardware.h"


#define IR_SEND 0
#define IR_STOP 9
#define IR_DONE 14
#define IR_IDLE 15

extern unsigned char tx_status;
extern unsigned char tx_buffer;

/**
 * Enable ir bitbang output on IR_OUT_PIN
 */
void enableIrSerial();
void irPrintStringConstant(const char * data);
void irEscapeSequence(const char * data);
 void irPutChar(char c);
#endif

 