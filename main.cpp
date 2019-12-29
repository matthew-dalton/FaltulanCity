#include "Game.h"

const int ROWS = 7;
const int COLUMNS = 8;
const int NUM_FLATULANS = 25;


int main()
{
    Game g(ROWS, COLUMNS, NUM_FLATULANS);
    
    // Play the game
    g.play();
}
