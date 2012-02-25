#ifndef IO_H
#define IO_H
#include "laserTagHardware.h"
#include "hamming.h"
#include "irSerial.h"


#include <p24F16KA102.h>
void enableIO();
void _ISR _U1RXInterrupt (void);
void updateLives(unsigned char lives);
#endif