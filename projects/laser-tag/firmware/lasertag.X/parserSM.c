#include "parserSM.h"
#include "gameSM.h"

#define PARSER_RETURN(x) return ((team_id<<7 ) | (x))


unsigned char parser_state = PARSER_IDLE;
unsigned char player = 0xff;//magic troll player


unsigned char parseCommand(unsigned char byte){

    unsigned char player_id = byte & 0x3F;
    unsigned char new_command = (byte & 0xC0)>>6;
    // unsigned char command = GET_COMMAND(byte);
    // unsigned char team_id = GET_TEAM_ID (byte);
    if(player_id!=my_player_id){
        switch(new_command){
            case 1:
                if(lives>0){
                    lives--;
                }
                break;
            case 2:
                lives = 3;
                break;
            default:
                break;
        }
    }
}
    
/*
    switch(command){
        case COMMAND_HIT:
            PARSER_RETURN(ACTION_HIT);
            
            
            break;
        case COMMAND_RESTORE:
            PARSER_RETURN(ACTION_RESTORE);
          
            break;
        case COMMAND_CHANGE_TEAM:
            PARSER_RETURN(ACTION_CHANGE_TEAM);
            break;
        default:
            PARSER_RETURN(ACTION_NONE);
            break;


    }
*/
   


/*
  switch(parser_state){
        case PARSER_IDLE:



            switch(command){
                case COMMAND_HIT:
                    if(team_id ==my_team_id){
                        PARSER_RETURN(ACTION_REVIVE);
                    }else{
                        PARSER_RETURN(ACTION_HIT);
                    }
                    break;
                case COMMAND_RESTORE:
                    if(team_id ==my_team_id){
                        PARSER_RETURN(ACTION_NONE);
                    }else{
                        PARSER_RETURN(ACTION_RESTORE);
                    }
                    break;
                case COMMAND_CHANGE_TEAM:
                    PARSER_RETURN(ACTION_CHANGE_TEAM);
                    break;
                case COMMAND_ENTER_JAIL:
                    PARSER_RETURN(ACTION_ENTER_JAIL);
                    break;
                case COMMAND_ENTER_BASE:
                    PARSER_RETURN(ACTION_ENTER_BASE);
                    break;
                default:
                    PARSER_RETURN(ACTION_NONE);
                    break;
            }

        break;



        case PARSER_WAITING_FOR_TEAM:
            if (byte & 0x80){
                parser_state = PARSER_IDLE;
                return (ACTION_NONE << 8) | byte;

            }else{      ///if firt bit is one , something broke :( >> return to PARSER_IDLE
                parser_state = PARSER_IDLE;

                return (ACTION_REVIVE << 8) | byte; //should be revived. Game SM makes final decision
            }

            break;


        //is this ack packet realy for me??
        case PARSER_WAITING_FOR_PLAYER:
            player = byte & 0x3F; //only player
            unsigned char team = (byte & 0x40) && 1; //bit 6
            if(player==PLAYER_ID && team ==my_team_id){//looks like it's for me? But is it the correct ack? Let's wait for a seq num
                parser_state = PARSER_WAITING_FOR_SEQ_NUM;
                PARSER_RETURN(ACTION_NONE);
            }else{
                parser_state=PARSER_IDLE;
                PARSER_RETURN(ACTION_NONE);
            }
            break;



        case PARSER_WAITING_FOR_SEQ_NUM:
            parser_state=PARSER_IDLE;
            PARSER_RETURN(ACTION_NONE);
            break;



        default:
            //SOMETHING IS BAD!!!!
            parser_state=PARSER_IDLE;
            PARSER_RETURN(ACTION_NONE);
            break;
 *
    */
 