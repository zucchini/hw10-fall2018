#include "gameLogic.h"

void initializeGame(Game* game) {
    // TA-TODO: Initialize everything that's part of this Game struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the game begins.
    UNUSED(game);
}

// TA-TODO: Add any process functions for sub-elements of your game here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.
//
// e.g.:
// static void processSnake(Snake* snake);
// static void generateRandomFoods(Game* game);
void processGame(Game *game, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your game processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that vblank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     */
    UNUSED(game);
    UNUSED(keysPressedBefore);
    UNUSED(keysPressedNow);
}
