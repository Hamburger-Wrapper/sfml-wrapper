/**
 * @file main.cpp
 * @author Brent Knopp
 * @brief  This program testing class buton
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * @aknolegment https://code.markrichards.ninja/sfml/how-to-create-simple-buttons-for-your-sfml-game
 * 
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

int main()
{
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false;

    sf::RenderWindow window(sf::VideoMode(900, 500), "MyButton!");

    Button buffer1("1", {25, 250},  {50,500}, sf::Color:: Red);
    Button buffer2("2", {875, 250}, {50,500}, sf::Color:: Red);
    Button buffer3("3", {450, 25}, {800, 50} ,sf::Color:: Red);
    Button buffer4("4", {450,475}, {800, 50}, sf::Color:: Red);
    //Button buffer5("", {25,475}, {1000,50}, sf::Color::Black);
    //Button buffer6("", {25,710}, {1000,50}, sf::Color::White);

    Button yes("TEXT",{450,100}, {300, 100}, sf::Color::Red);
    yes.setColorTextHover(sf::Color::Cyan);


    Button no;
    Button playGame1("Play Game 1",{250,238}, {350, 75}, sf::Color::Red);
    playGame1.setColorTextHover(sf::Color::Cyan);

    Button playGame2("Play Game 2",{250,363}, {350, 75}, sf::Color::Red);
    playGame2.setColorTextHover(sf::Color::Cyan);

    Button playGame3("Play Game 3",{650,238}, {350, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    Button playGame4("Play Game 4",{650,363}, {350, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

    Button error;

    //yes.setFontSize(20);
    yes.setColorTextHover(sf::Color::Cyan);
    
    no.setText("No");
    no.setPosition({350, 610});
    no.setSize({100, 100});
    no.setColor(sf::Color::Blue);
    no.setColorTextHover(sf::Color::Cyan);
    no.setColorTextNormal(sf::Color::Green);

    //error.setText("error");
    //error.setPosition({150, 610});
    //error.setSize({300, 400});
    //error.setColor(sf::Color::White);
    //error.setColorTextHover(sf::Color::Red);
    //error.setColorTextNormal(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            yes.update(event, window);
            no.update(event, window);
            //error.update(event, window);
            if(playGame1.update(event, window))
                game1On = true;
            if(playGame2.update(event, window))
                game2On = true;
            if(playGame3.update(event, window))
                game3On = true;
            if(playGame4.update(event, window))
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
        if(game1On)
        window.draw(buffer1);
        if(game2On)
        window.draw(buffer2);
        if(game3On)
        window.draw(buffer3);
        if(game4On)
        window.draw(buffer4);

        window.display();
    }

    return 0;


}