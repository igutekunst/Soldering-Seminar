#ifndef UTILITY_H
#define UTILITY_H
#include "uart.h"

#define GET_TEAM_ID(y) ((0x8 & y) && 1)
//#define GET_PLAYER_ID(x) (0x3f & x)
//#define SHOOT ((TEAM_ID && 1)<<6 | (PLAYER_ID & 0x3F) | 0x80)
//#define GET_PLAYER_BYTE(x) (0xFF & x)
//#define GET_ACTION(x) (x>>8)
#define GET_COMMAND(y) (0x7 & (y))



void printAction(unsigned char action);
void printGameState(unsigned char gameState);
#endif
