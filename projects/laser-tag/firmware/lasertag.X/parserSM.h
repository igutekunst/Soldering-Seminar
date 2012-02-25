#ifndef PARSER_SM_H
#define PARSER_SM_H



#include "playerInfo.h"  //parser needs to know about current player for some actions

#include "gameSM.h"      //parser also generates game commands, which are defined in gameSM.h



#include "utility.h"
/**
 * Parser is aiting for a byte to process
 *
 */
#define PARSER_IDLE 0
/**
 * Parser just received a revive packet, and is
 * waiting to hear about the team it came from
 */
#define PARSER_WAITING_FOR_TEAM (1)
/**
 * Parser just received summary/ack packet and is
 * waiting to confirm if it was intended for it
 */
#define PARSER_WAITING_FOR_PLAYER (2)

/**
 * Parser just received confirmation packet was intended for it and is
 *  waiting to confirm seq number
 */
#define PARSER_WAITING_FOR_SEQ_NUM (3)

unsigned char parseCommand(unsigned char byte);



#endif
