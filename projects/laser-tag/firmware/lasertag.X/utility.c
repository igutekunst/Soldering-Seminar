#include "utility.h"

void printAction(unsigned char action){
    switch (action){
        case 1:
            printStringConstant("HIT");
            break;
        case 2:
            printStringConstant("REVIVE");
            break;
        case 3:
            printStringConstant("ENTERED JAIL");
            break;
        case 4:
            printStringConstant("ENTERED ENEMY JAIL");
            break;
        case 5:
            printStringConstant("ENTERED HOME JAIL");
            break;
        case 6:
            printStringConstant("CHANGE TEAM");
            break;
        case 7:
            printStringConstant("EXTRA");
            break;
        case 8:
            printStringConstant("ENTERED BASE");
            break;
        case 9:
            printStringConstant("None");
            break;
        default:
            printStringConstant("UNKNOWN");
            break;
    }
}

void printGameState(unsigned char gameState){
    switch(gameState){
        case 0:
            printStringConstant("Pre Game");
            break;
        case 1:
            printStringConstant("Dead");
            break;
        case 2:
            printStringConstant("In Home jail");
            break;
        case 3:
            printStringConstant("In enemy jail");
            break;
        case 4:
            printStringConstant("Going to jail");
            break;
        case 5:
            printStringConstant("Bleeding Out");
            break;
        case 6:
            printStringConstant("Walking Home");
            break;
        case 7:
            printStringConstant("Jail Camping");
            break;
        case 8:
            printStringConstant("Trying to jail camp");
            break;
        case 9:
            printStringConstant("Flag camping");
        default:
            printStringConstant("Unknown State");
            break;
    }
}