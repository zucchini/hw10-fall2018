#ifndef LOGIC_SEEN
#define LOGIC_SEEN

#include "gba.h"

typedef struct {
    // Store whether or not the game is over in this member:
    int gameOver;

    /*
    * TA-TODO: Add any logical elements you need to keep track of in your game.
    *
    * For example, for a Snake game, those could be:
    *
    * Snake snake;
    * Food foods[10];
    * int points;
    *
    */

} Game;

/*
* TA-TODO: Add any additional structs that you need for your game.
*
* For example, for a Snake game, one could be:
*
* typedef struct {
*   int heading;
*   int length;
*   int x;
*   int y;
* } Snake;
*
*/

// This function can initialize an unused game struct.
void initializeGame(Game *game);

// This function will be used to process game frames.
void processGame(Game *game, u32 keysPressedBefore, u32 keysPressedNow);

// If you have anything else you need accessible from outside the gameLogic.c
// file, you can add them here. You likely won't.

#endif
