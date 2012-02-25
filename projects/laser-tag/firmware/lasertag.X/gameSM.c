#include "gameSM.h"
#include <p24F16KA102.h>
#include "laserTagHardware.h"
unsigned char state = PRE_GAME;
unsigned char lives = 0;
unsigned char bleed_out_time = BLEED_OUT_TIME;
unsigned char walking_home_time = WALKING_HOME_TIME;
unsigned char tick(unsigned char command_packet){
    unsigned char command = command_packet & 0xF;
    unsigned char team_id = command_packet >> 7;

    

    
    switch(command){
        case ACTION_RESTORE:
          
                state = GAME;
                lives = 3;
                
                
            

            break;
        case ACTION_CHANGE_TEAM:
            my_team_id = team_id;
            state = PRE_GAME;
            lives = 0;
            break;

        case ACTION_HIT:
            switch(state){
                case PRE_GAME:
                    
                break;
                case GAME:
                        if(lives>0){
                            lives--;
                        }else{  //out of lives
                           
                        }

                break;
            
            default:
                state = GAME;
                
                break;
        }
        break;
        case ACTION_REVIVE:
           
                if(lives+REVIVAL_LIVES > 3){
                    lives = 3;
                }else{
                    lives = lives+REVIVAL_LIVES;
                }
            
          
            
            break;
    }
}

void _ISR _T1Interrupt(){

//#define SPECIAL_FUNCTION
#ifdef SPECIAL_FUNCTION
    sendCommand(COMMAND_CHANGE_TEAM,TEAM_ID);
   LIFE_1_LAT = !LIFE_1_LAT;
    GREEN_LAT = !GREEN_LAT;
   RED_LAT = 1;
   BLUE_LAT =1;
#endif

    

    IFS0bits.T1IF = 0;
}
