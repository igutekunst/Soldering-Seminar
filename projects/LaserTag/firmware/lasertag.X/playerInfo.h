#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H
#define BLUE_TEAM (0)
#define GREEN_TEAM (1)
#define TEAM_ID GREEN_TEAM
//7,8 taken



#define PLAYER_ID (24)





//some special players used for things like jail, flag base, change team, etc
#define ENTERED_JAIL (45)
#define ENTERED_FLAG_BASE (46)
#define CHANGE_TEAM (47)
#define TROLL_PLAYER (0xff)
#define SCORE_BOARD (48)

//#define SPECIAL_FUNCTION


extern unsigned char my_team_id;
extern unsigned char my_player_id;
#endif
