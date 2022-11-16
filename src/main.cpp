#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../headers/button.h"
//#include "../headers/buttonCircle.h"

int main()
{

    // switches to turn on games
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false;

    sf::RenderWindow window1(sf::VideoMode(900, 500), "start screen");

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

    Button yes("Select A Game", {450, 100}, {400, 100}, sf::Color::Red);
    yes.setColorTextHover(sf::Color::Cyan);

    // Button no;
    Button playGame1("Guess My Number", {250, 238}, {375, 75}, sf::Color::Red);
    playGame1.setColorTextHover(sf::Color::Cyan);

    Button playGame2("Rock Paper Sicssors", {250, 363}, {375, 75}, sf::Color::Red);
    playGame2.setColorTextHover(sf::Color::Cyan);

    Button playGame3("Slot Machine", {650, 238}, {375, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    Button playGame4("Go Marty", {650, 363}, {375, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

    // Button error;

    // yes.setFontSize(20);
    // yes.setColorTextHover(sf::Color::Cyan);

    // no.setText("No");
    // no.setPosition({350, 610});
    // no.setSize({100, 100});
    // no.setColor(sf::Color::Blue);
    // no.setColorTextHover(sf::Color::Cyan);
    // no.setColorTextNormal(sf::Color::Green);

    // error.setText("error");
    // error.setPosition({150, 610});
    // error.setSize({300, 400});
    // error.setColor(sf::Color::White);
    // error.setColorTextHover(sf::Color::Red);
    // error.setColorTextNormal(sf::Color::Cyan);

    while (window1.isOpen() && !game1On && !game2On && !game3On && !game4On)
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
            yes.update(event, window1);
            // no.update(event, window);
            // error.update(event, window);
            if (playGame1.update(event, window1))
            {
                game1On = true;
            }

            if (playGame2.update(event, window1))
                game2On = true;
            if (playGame3.update(event, window1))
                game3On = true;
            if (playGame4.update(event, window1))
                game4On = true;
        }

        window1.clear();
        window1.draw(yes);
        // window.draw(no);
        window1.draw(playGame1);
        window1.draw(playGame2);
        window1.draw(playGame3);
        window1.draw(playGame4);
        window1.display();
    }

    // game 1

    bool generateNumber = false;
    bool selectNumber = false;
    bool quitGame1 = false;
    bool win = false;
    bool lose = false;
    bool restart = false;
    int number = -1;
    int magicNumber = -1;

    if (game1On)
    {
        window1.close();

        sf::RenderWindow windowGame1(sf::VideoMode(800, 600), "Game 1");

        // start button
        Button start("start", {600, 250}, {150, 100}, sf::Color::Green);

        Button quit("quit", {170, 210}, {200, 75}, sf::Color::Green);
        Button newGame("new game", {170, 310}, {200, 75}, sf::Color::Green);
        newGame.setColorTextNormal(sf::Color::White);
        newGame.setColorTextHover(sf::Color::Red);
        quit.setColorTextNormal(sf::Color::White);
        quit.setColorTextHover(sf::Color::Red);
        // start button
        start.setColorTextNormal(sf::Color::White);
        start.setColorTextHover(sf::Color::Red);
        // ten number buttons
        Button one("1", {250, 400}, {50, 50}, sf::Color::Blue);
        Button two("2", {325, 400}, {50, 50}, sf::Color::Blue);
        Button three("3", {400, 400}, {50, 50}, sf::Color::Blue);
        Button four("4", {475, 400}, {50, 50}, sf::Color::Blue);
        Button five("5", {550, 400}, {50, 50}, sf::Color::Blue);
        Button six("6", {250, 500}, {50, 50}, sf::Color::Blue);
        Button seven("7", {325, 500}, {50, 50}, sf::Color::Blue);
        Button eight("8", {400, 500}, {50, 50}, sf::Color::Blue);
        Button nine("9", {475, 500}, {50, 50}, sf::Color::Blue);
        Button ten("10", {550, 500}, {50, 50}, sf::Color::Blue);
        Button title("Guess my number 1 to 10", {400, 100}, {700, 100}, sf::Color::Blue);
        Button pickNumber("?", {400, 250}, {100, 100}, sf::Color::Blue);

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
                // start button is pushed

                if (start.update(eventGame1, windowGame1) && selectNumber)
                {
                    start.setColorTextNormal(sf::Color::Red);
                    generateNumber = true;
                }

                pickNumber.update(eventGame1, windowGame1);
                if (newGame.update(eventGame1, windowGame1))
                {
                    restart = true;
                }

                if (quit.update(eventGame1, windowGame1))
                {
                    quitGame1 = -true;
                }

                if (selectNumber == false)
                {
                    if (one.update(eventGame1, windowGame1))
                    {
                        number = 1;
                        selectNumber = true;
                        one.setColorTextNormal(sf::Color::Red);
                    }
                    if (two.update(eventGame1, windowGame1))
                    {
                        number = 2;
                        selectNumber = true;
                        two.setColorTextNormal(sf::Color::Red);
                    }
                    if (three.update(eventGame1, windowGame1))
                    {
                        number = 3;
                        selectNumber = true;
                        three.setColorTextNormal(sf::Color::Red);
                    }
                    if (four.update(eventGame1, windowGame1))
                    {
                        number = 4;
                        selectNumber = true;
                        four.setColorTextNormal(sf::Color::Red);
                    }
                    if (five.update(eventGame1, windowGame1))
                    {
                        number = 5;
                        selectNumber = true;
                        five.setColorTextNormal(sf::Color::Red);
                    }
                    if (six.update(eventGame1, windowGame1))
                    {
                        number = 6;
                        selectNumber = true;
                        six.setColorTextNormal(sf::Color::Red);
                    }
                    if (seven.update(eventGame1, windowGame1))
                    {
                        number = 7;
                        selectNumber = true;
                        seven.setColorTextNormal(sf::Color::Red);
                    }
                    if (eight.update(eventGame1, windowGame1))
                    {
                        number = 8;
                        selectNumber = true;
                        eight.setColorTextNormal(sf::Color::Red);
                    }
                    if (nine.update(eventGame1, windowGame1))
                    {
                        number = 9;
                        selectNumber = true;
                        nine.setColorTextNormal(sf::Color::Red);
                    }
                    if (ten.update(eventGame1, windowGame1))
                    {
                        number = 10;
                        selectNumber = true;
                        ten.setColorTextNormal(sf::Color::Red);
                    }
                }
            }

            windowGame1.clear();
            windowGame1.draw(one);
            windowGame1.draw(two);
            windowGame1.draw(three);
            windowGame1.draw(four);
            windowGame1.draw(five);
            windowGame1.draw(six);
            windowGame1.draw(seven);
            windowGame1.draw(eight);
            windowGame1.draw(nine);
            windowGame1.draw(ten);
            windowGame1.draw(title);
            windowGame1.draw(pickNumber);
            windowGame1.draw(start);
            windowGame1.draw(quit);
            windowGame1.draw(newGame);
            windowGame1.display();

            if ((generateNumber == true) && (selectNumber == true))
            {
                // generate number call generator code
                //*****************************************///
                //*****************************************///
                magicNumber = 9;
                if (magicNumber == number)
                {
                    win = true;
                }
                else
                    lose = true;
            }

            // display winning pick
            if (win == true)
            {
                title.setText("   YOU WIN, GET PAID");
            }

            // display losing pick
            if (lose == true)
            {
                title.setText("   TRY AGAIN SUCKER");
            }

            if (restart == true)
            {
                generateNumber = false;
                selectNumber = false;
                quitGame1 = false;
                win = false;
                lose = false;
                restart = false;
                number = -1;
                magicNumber = -1;
                one.setColorTextNormal(sf::Color::Green);
                two.setColorTextNormal(sf::Color::Green);
                three.setColorTextNormal(sf::Color::Green);
                four.setColorTextNormal(sf::Color::Green);
                five.setColorTextNormal(sf::Color::Green);
                six.setColorTextNormal(sf::Color::Green);
                seven.setColorTextNormal(sf::Color::Green);
                eight.setColorTextNormal(sf::Color::Green);
                nine.setColorTextNormal(sf::Color::Green);
                ten.setColorTextNormal(sf::Color::Green);
                start.setColorTextNormal(sf::Color::White);
                newGame.setColorTextNormal(sf::Color::White);
                title.setText("Guess my number 1 to 10");
            }

            // close game
            if (quitGame1 == true)
            {
                windowGame1.close();
            }
        }
    }

    // here Marty ****************************
    // game 3
    if (game3On)
    {
        window1.close();
        sf::RenderWindow windowGame3(sf::VideoMode(800, 600), "Game 2");

        Button display1("#", {200, 150}, {185, 185}, sf::Color::Blue);
        Button display2("#", {400, 150}, {185, 185}, sf::Color::Blue);
        Button display3("#", {600, 150}, {185, 185}, sf::Color::Blue);
        Button slot("", {750, 300}, {50, 500}, sf::Color::Yellow);
        Button quitGame3("Quit", {50, 550}, {50, 50}, sf::Color::White);
        quitGame3.setColorTextHover(sf::Color::Red);

        Button cashDisplay("CASH", {400, 400}, {600, 200}, sf::Color::Red);

        // run the program as long as the window is open
        while (windowGame3.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event eventGame3;
            while (windowGame3.pollEvent(eventGame3))
            {
                // "close requested" event: we close the window
                if (eventGame3.type == sf::Event::Closed || quitGame3.update(eventGame3, windowGame3))
                    windowGame3.close();

                display1.update(eventGame3, windowGame3);
                display2.update(eventGame3, windowGame3);
                display3.update(eventGame3, windowGame3);
                slot.update(eventGame3, windowGame3);
                cashDisplay.update(eventGame3, windowGame3);
            }

            windowGame3.clear();
            windowGame3.draw(display1);
            windowGame3.draw(display2);
            windowGame3.draw(display3);
            windowGame3.draw(slot);
            windowGame3.draw(cashDisplay);
            windowGame3.draw(quitGame3);
            windowGame3.display();
        }
    }

    return 0;
}