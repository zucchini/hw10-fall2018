#include "gba.h"
#include "gameLogic.h"
#include "gameGraphics.h"

// TA-TODO: INCLUDE THE HEADERS YOU NEED FOR IMAGES

#include <stdio.h>
#include <stdlib.h>

// State enum definition
typedef enum {
    // TA-TODO: Add any additional states you need for your game.
    START,
    START_NODRAW,
    GAME_INIT,
    GAME,
    GAMEOVER,
    GAMEOVER_NODRAW,
} GBAState;

int main(void) {
    GBAState state = START;
    Game game;

    // We
    u32 previousButtons = BUTTONS;
    u32 currentButtons = BUTTONS;

    while(1) {
        // Wait for vblank
        waitForVBlank();

        // Load the current state of the buttons
        currentButtons = BUTTONS;

        // TA-TODO: Manipulate the state machine below as needed.
        switch(state) {
        case START:
            // TA-TODO: Draw the start state here.

            state = START_NODRAW;
            break;
        case START_NODRAW:
            // TA-TODO: Check for a button press here to start the game.
            // Start the game by switching the state to GAME_INIT.

            break;
        case GAME_INIT:
            // Initialize the game. Switch to the GAME state.
            initializeGame(&game);

            // Draw the initial state of the game
            fullDrawGame(&game);

            state = GAME;
            break;
        case GAME:
            // Un-draw any potentially moving elements of the game
            undrawGame(&game);

            // Process the game for one frame
            processGame(&game, previousButtons, currentButtons);

            // Draw the current state of the game
            drawGame(&game);

            // Check if the game is over. If it is, then go to the gameover state.
            if (game.gameOver) state = GAMEOVER;

            break;
        case GAMEOVER:
            // TA-TODO: Draw the game over screen

            state = GAMEOVER_NODRAW;
            break;
        case GAMEOVER_NODRAW:
            // TA-TODO: Check for a button press here to go back to the start screen

            break;
        }

        // Store the current state of the buttons
        previousButtons = currentButtons;
    }

    return 0;
}
