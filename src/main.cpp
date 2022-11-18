
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "include/button.h"
#include "include/menu.h"
#include "include/rps.h"
#include "include/roulette.h"

//#include "../headers/buttonCircle.h"


int main()
{
    // switches to turn on each game application
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false,
         game5On = false,
         game6On = false,
         quit = false;


    // main menu display
    //window.setVerticalSyncEnabled(true);

    while(!quit)
    {
        sf::RenderWindow window(sf::VideoMode(900, 600), "main game menu");
        // handle main game menu
        mainMenu(window, game1On, game2On, game3On, game4On, game5On, game6On);

        // game 1 Roulette
        if (game1On)
        {
            window.close();
            game1(quit);
        }
        // game 2 Rock Paper Scissors
        if (game2On)
        {
            window.close();
            game2(quit);
        }
        // game 3 Slot Machine
        if (game3On)
        {
            window.close();
            //game3();
        }
        // game 4 3D engine
        if (game4On)
        {
        window.close();
        //game4();
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
