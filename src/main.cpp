
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/button.h"

int main()
{
    // switches to turn on games
    bool game1On = false,
        game2On = false,
        game3On = false,
        game4On = false;

    sf::RenderWindow window(sf::VideoMode(900, 500), "start screen");

    if (!game1On)
    {
        sf::Window window(sf::VideoMode(800, 600), "game 1");
    }

    // buffers at the terminal edges
    Button buffer1("1", {25, 250}, {50, 500}, sf::Color::Red);
    Button buffer2("2", {875, 250}, {50, 500}, sf::Color::Red);
    Button buffer3("3", {450, 25}, {800, 50}, sf::Color::Red);
    Button buffer4("4", {450, 475}, {800, 50}, sf::Color::Red);
    // Button buffer5("", {25,475}, {1000,50}, sf::Color::Black);
    // Button buffer6("", {25,710}, {1000,50}, sf::Color::White);

    Button yes("TEXT", {450, 100}, {300, 100}, sf::Color::Red);
    yes.setColorTextHover(sf::Color::Cyan);

    Button no;
    Button playGame1("Play Game 1", {250, 238}, {350, 75}, sf::Color::Red);
    playGame1.setColorTextHover(sf::Color::Cyan);

    Button playGame2("Play Game 2", {250, 363}, {350, 75}, sf::Color::Red);
    playGame2.setColorTextHover(sf::Color::Cyan);

    Button playGame3("Play Game 3", {650, 238}, {350, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    Button playGame4("Play Game 4", {650, 363}, {350, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

    Button error;

    // yes.setFontSize(20);
    yes.setColorTextHover(sf::Color::Cyan);

    no.setText("No");
    no.setPosition({350, 610});
    no.setSize({100, 100});
    no.setColor(sf::Color::Blue);
    no.setColorTextHover(sf::Color::Cyan);
    no.setColorTextNormal(sf::Color::Green);

    // error.setText("error");
    // error.setPosition({150, 610});
    // error.setSize({300, 400});
    // error.setColor(sf::Color::White);
    // error.setColorTextHover(sf::Color::Red);
    // error.setColorTextNormal(sf::Color::Cyan);

    while (window.isOpen() && !game1On && !game2On && !game3On && !game4On)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            yes.update(event, window);
            no.update(event, window);
            // error.update(event, window);
            if (playGame1.update(event, window))
            {
                game1On = true;
            }

            if (playGame2.update(event, window))
                game2On = true;
            if (playGame3.update(event, window))
                game3On = true;
            if (playGame4.update(event, window))
                game4On = true;
        }

        window.clear();
        window.draw(yes);
        window.draw(no);
        window.draw(playGame1);
        window.draw(playGame2);
        window.draw(playGame3);
        window.draw(playGame4);

        // bool switch triggers
        if (game1On)
        {
            window.draw(buffer1);
        }

        if (game2On)
            window.draw(buffer2);
        if (game3On)
            window.draw(buffer3);
        if (game4On)
            window.draw(buffer4);

        window.display();
     
    }

        if (game1On)
        {
            sf::Window windowGame1(sf::VideoMode(800, 600), "Game 1");

            // run the program as long as the window is open
            while (windowGame1.isOpen())
            {
                // check all the window's events that were triggered since the last iteration of the loop
                sf::Event eventGame1;
                while (windowGame1.pollEvent(eventGame1))
                {
                    // "close requested" event: we close the window
                    if (eventGame1.type == sf::Event::Closed)
                        windowGame1.close();
                }
            }
        }

    if (game1On)
    {
        sf::Window window(sf::VideoMode(800, 600), "game 1");
    }

        // game 2
       if(game2On)
       {
        window.close();
        sf::Window windowGame2(sf::VideoMode(800, 600), "Game 2");

                // run the program as long as the window is open
                while (windowGame2.isOpen())
                {
                // check all the window's events that were triggered since the last iteration of the loop
                sf::Event eventGame2;
                while (windowGame2.pollEvent(eventGame2))
                {
                    // "close requested" event: we close the window
                if (eventGame2.type == sf::Event::Closed)
                    windowGame2.close();
                }
                }
        }
    return 0;
}