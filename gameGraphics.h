// This function will be used to draw everything about the game
// including the background and whatnot.
void fullDrawGame(Game *game);

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawGame(Game *game);

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawGame(Game *game);

// If you have anything else you need accessible from outside the gameLogic.c
// file, you can add them here. You likely won't.
