#include "../include/menu.h"

void mainMenu(sf::RenderWindow &window, bool &switch1, bool &switch2, bool &switch3, bool &switch4, bool &switch5, bool &switch6, bool &q)
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

    // game 3 Slot Machine button
    Button playGame3("Slot Machine",{650,238}, {375, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    // game 4 Black Jack button
    Button playGame4("Black Jack", {650, 363}, {375, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

     // game 5
    Button playGame5("game 5", {250, 488}, {375, 75}, sf::Color::Red);
    playGame5.setColorTextHover(sf::Color::Cyan);

    // game 6 3D engine button
    Button playGame6("3D Engine", {650, 488}, {375, 75}, sf::Color::Red);
    playGame6.setColorTextHover(sf::Color::Cyan);

    while (window.isOpen() && !switch1 && !switch2 && !switch3 && !switch4 && !switch5 && !switch6)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // quit game
            if (event.type == sf::Event::Closed)
            {
                window.close();
                q = true;
            }
            // start game 1 roulette
            if (playGame1.update(event, window))
                switch1 = true;
            // start game 2 RPS
            if (playGame2.update(event, window))
                switch2 = true;
            // start game 3 slot machine
            if (playGame3.update(event, window))
                switch3 = true;
            // start game 4 black jack
            if (playGame4.update(event, window))
                switch4 = true;
            // start game 5 
            if(playGame5.update(event, window))
                switch5 = true;
            // start 3-D engine
            if(playGame6.update(event, window))
                switch6 = true; 
        }

        // clear all images from display screen
        window.clear();
        // title header on start-up screen
        window.draw(title);
        // play game buttons 1-6
        window.draw(playGame1); // roulette
        window.draw(playGame2); // rock paper scissors
        window.draw(playGame3); // slot machine
        window.draw(playGame4); // black jack
        window.draw(playGame5); // no name
        window.draw(playGame6); // 3-D engine
    
        window.display();
    }

}