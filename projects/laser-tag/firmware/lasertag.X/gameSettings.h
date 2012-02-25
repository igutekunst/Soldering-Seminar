#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H



/**
 * If enabled, then upon power on, player must be revied by enemy to start game
 */
#define ENABLE_PRE_GAME (0)

/**
 * With jail enabled, one most go to the enemy jail before being revived
 *
 */
#define ENABLE_JAIL (0)
/**
 * With bleed out time > (0), after loosing last life, one has (5) seconds to be revived
 * NOTE: If jail is disabled, one can be revived anyway
 */
#define BLEED_OUT_TIME (5)

/**
 * Amount of lives restored upon being revived
 * If ==(1), then to get more than one life back, one needs to be revived by mutiple teamates
 */
/**
 * Amount of seconds player has upon beeing freed in which him/her is bulletproof (also out of bullets..)
 * A special setting of zero forces player to return to home jail before being revived
 * 
 */
#define WALKING_HOME_TIME (10)
#define REVIVAL_LIVES (3)


/**
 * If nonzero, one will lose the ability to shoot for indicated number of seconds
 * Must be less than (255)
 **/
#define HOME_JAIL_PENALTY (10)
/**
 * If non zero, the number of seconds a player is penalized for camping in flag area
 */
#define FLAG_CAMPING_PENALTY (0)

#define VULNERABLE_WHILE_BLEEDING_OUT (1)


#endif
