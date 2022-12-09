
/**
 * @file   main.cpp
 * @author Brent Knoppp
 * @brief  main game menu interface
 * @date   11/01/2022
 *
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "include/button.h"
#include "include/menu.h"
#include "include/rps.h"
#include "include/roulette.h"
#include "include/blackjack.h"

int main()
{   
    // starting money
    int credits = 500;

    // switches to turn on each game application
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false,
         game5On = false,
         game6On = false,
         quit = false;

    // user interface
    while(!quit)
    {
        sf::RenderWindow window(sf::VideoMode(900, 600), "main game menu");
        window.setVerticalSyncEnabled(true);
        // handle main game menu
        mainMenu(window, game1On, game2On, game3On, game4On, game5On, game6On, quit, credits);
        // game 1 Roulette
        if (game1On)
        {
            window.close();
            game1(quit, credits);
        }
        // game 2 Rock Paper Scissors
        if (game2On)
        {
            window.close();
            game2(quit, credits);
        }
        // game 3 Slot Machine
        if (game3On)
        {
            window.close();
        }
        // game 4 Black Jack
        if (game4On)
        {
            window.close();
            game4(quit, credits);
        }
        // game 5 Keno
        if(game5On)
        {
            window.close();
            game5(quit, credits);
        }
        // game 6 3D Engine
        if(game6On)
        {
            window.close();
        }   
        game1On = false;
        game2On = false;
        game3On = false;
        game4On = false;
        game5On = false;
        game6On = false;
    }
    return 0;
}
