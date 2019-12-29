#include "Game.h"
#include "globals.h"
#include "City.h"
#include "Player.h"
#include <iostream>


int decodeDirection(char dir);  // AUXILLARY FUNCTION PROTOTYPE DECLARATION

Game::Game(int rows, int cols, int nFlatulans)
{
    if (nFlatulans < 0)
    {
        std::cout << "***** Cannot create Game with negative number of Flatulans!" << std::endl;
        exit(1);
    }
    if (nFlatulans > MAXFLATULANS)
    {
        std::cout << "***** Trying to create Game with " << nFlatulans
        << " Flatulans; only " << MAXFLATULANS << " are allowed!" << std::endl;
        exit(1);
    }
    if (rows == 1  &&  cols == 1  &&  nFlatulans > 0)
    {
        std::cout << "***** Cannot create Game with nowhere to place the Flatulans!" << std::endl;
        exit(1);
    }
    
    // Create city
    m_city = new City(rows, cols);
    
    // Add player
    int rPlayer = randInt(1, rows);
    int cPlayer = randInt(1, cols);
    m_city->addPlayer(rPlayer, cPlayer);
    
    // Populate with Flatulans
    while (nFlatulans > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
        // Don't put a Flatulan where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_city->addFlatulan(r, c);
        nFlatulans--;
    }
}

Game::~Game()
{
    delete m_city;
}

void Game::play()
{
    m_city->display();
    Player* p = m_city->player();
    if (p == nullptr)
        return;
    
    while ( ! p->isPassedOut()  &&  m_city->flatulanCount() > 0)
    {
        bool repeat;
        std::string action;
        do{  // DO-WHILE LOOP to check for h and not count it as a turn
            repeat = false;
            std::cout << "Move (u/d/l/r//h/q): ";
            getline(std::cin,action);
            if (action == "h"){
                m_city->history().display();
                std::cout << "Press enter to continue.";
                std::cin.ignore(10000, '\n');  // waits for an enter or return
                repeat = true;
                action = "";
                m_city->display();  // prepare the screen for the next move
            }
        } while(repeat);  // END OF DO-WHILE
        
        if (action.size() == 0)  // player preaches
            p->preach();
        else
        {
            switch (action[0])
            {
                default:   // if bad move, nobody moves
                    std::cout << '\a' << std::endl;  // beep
                    continue;
                case 'q':
                    return;
                case 'u':
                case 'd':
                case 'l':
                case 'r':
                    p->move(decodeDirection(action[0]));
                    break;
            }
        }
        m_city->moveFlatulans();
        m_city->display();
    }
    if (p->isPassedOut())
        std::cout << "You lose." << std::endl;
    else
        std::cout << "You win." << std::endl;
}




// AUXILLARY FUNCTION IMPLEMENTATION

int decodeDirection(char dir)
{
    switch (dir)
    {
        case 'u':  return UP;
        case 'd':  return DOWN;
        case 'l':  return LEFT;
        case 'r':  return RIGHT;
    }
    return -1;  // bad argument passed in!
}
