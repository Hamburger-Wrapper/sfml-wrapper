#include "../include/menu.h"

void mainMenu(sf::RenderWindow &window, bool &switch1, bool &switch2, bool &switch3, bool &switch4)
{
       // main menu title header
    Button title("Select A Game", {450, 100}, {400, 100}, sf::Color::Red);
    title.setColorTextHover(sf::Color::Cyan);

    // game 1 Roulette button
    Button playGame1("Roulette", {250, 238}, {375, 75}, sf::Color::Red);
    playGame1.setColorTextHover(sf::Color::Cyan);

    // game 2 Rock Paper Scissors button
    Button playGame2("Rock Paper Sicssors", {250, 363}, {375, 75}, sf::Color::Red);
    playGame2.setColorTextHover(sf::Color::Cyan);

    Button playGame3("Slot Machine",{650,238}, {375, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    Button playGame4("Black Jack", {650, 363}, {375, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

    while (window.isOpen() && !switch1 && !switch2 && !switch3 && !switch4)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            title.update(event, window);

            if (playGame1.update(event, window))
            {
                switch1 = true;
            }

            if (playGame2.update(event, window))
                switch2 = true;
            if (playGame3.update(event, window))
                switch3 = true;
            if (playGame4.update(event, window))
                switch4 = true;
        }

        // clear all images from display screen
        window.clear();
        // title header on start-up screen
        window.draw(title);
        // play game buttons 1-4
        window.draw(playGame1); // roulette
        window.draw(playGame2); // rock paper scissors
        window.draw(playGame3); // slot machine
        window.draw(playGame4); // 3-D engine

        window.display();
    }

}