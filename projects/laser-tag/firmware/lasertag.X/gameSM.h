#ifndef GAME_SM_H
#define GAME_SM_H




#include "gameSettings.h"   //game settings
#include "playerInfo.h"
extern unsigned char lives;
extern unsigned char bleed_out_time;
extern unsigned char state;
 //all actions will have an origin player/team, although it will ve extra info sometimes
/**
 * Player just took a bullet. Could be friendly, in which case game sm decides action
 */
#define ACTION_HIT (1)
/**
 * Player was revived by a revive packet
 */
#define ACTION_REVIVE (2)


//jail, if we have that kind of game
/**
 * Player entered a jail
 */
#define ACTION_ENTER_JAIL (3)

/*
* ***Likely not going to be implemented, although might (parser should not decide based on team)**
* Player entered an enemy jail
*/
#define ACTION_ENTER_ENEMY_JAIL (4)
/**
 * ***Likely not going to be implemented, although might (parser should not decide based on team)***
 * Player entered an enemy jail
 *
 */
#define ACTION_ENTER_HOME_JAIL ((5))
/*
 * Action to Change Team
 */
#define ACTION_CHANGE_TEAM (6)    //same as getting hit by magic change team plaer
#define ACTION_EXTRA (7)     //It's extra!!
/**
 * Entered a base...
 */
#define ACTION_ENTER_BASE (8)
#define ACTION_NONE (9)
#define ACTION_RESTORE (10)
#define ACTION_BLEED_OUT (11)
#define ACTION_DIE (12)


// GAME STATES
// Game state changes based on clock, which causes some ticking actions, as well as async events from world

//should same team players be able to bring you out of pre game?
/**
 *
 */

// Starting state, can leave this state with an enemy revive packet. this is to help prevent cheating
#define PRE_GAME 0
/**
 *  probably unnecessary state, as lives will take care of it
 */
#define DEAD (1)
/**
 * Player has been in home jail within the last second
 *
 */
#define IN_HOME_JAIL (2)
/**
 * Player has been in enemy jail within (5) seconds
 * Might be some kind of penalty for leaving without being freed first
 *
 */
#define IN_ENEMY_JAIL (3)
/**
 * Player is dead, and cannot be revived (because jail is enabled && player has bleed out)
 */
#define WALKING_TO_JAIL (4)
/**
 * Player has just lost last life, and has BLEED_OUT_TIME to be revived
 */
#define BLEEDING_OUT (5)
/**
 * Player has been freed. Must return to home jail
 */
#define WALKING_HOME (6)

/**
 * Payer is being penalized for staying in home jail.
 * * * no effect if jails are disabled * *
 * this probably won't happen due to complications with returning home from enemy jail, and then restoring life.
 *
 *
 */
#define CAMPING (7)

#define GAME (8)


#define COMMAND_HIT (1)

#define COMMAND_CHANGE_TEAM (3)
#define COMMAND_ENTER_JAIL (4)
#define COMMAND_ENTER_BASE (5)
#define COMMAND_RESTORE (6)


#endif
