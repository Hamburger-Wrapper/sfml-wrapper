/**
 * @file   main.cpp
 * @author Brent Knoppp
 * @brief  game of keno
 * @date   11/01/2022
 *
 */
#include "../../include/roulette.h"

void game5(bool &s, int &credit)
{
    // game switches for control
    bool selectNumber = false;  // switch for  selecting a number 
    bool win = false;           // switch for win 
    bool lose = false;          // switch for lose
    bool restart = false;       // switch for restart game
    bool menu = false;          // switch for menu
    bool loseDisplay = false;   // switch for lose display
    bool winDisplay = false;    // switch for win display
    bool oneTime = false;       // switch to update credit 1 time per game
    int number = -1;            // users number
    int magicNumber = -1;       // random number of game

    // convert credit for displaying to game screen
    std::string cash;
    std::stringstream ss;
    ss<<credit;
    cash = ss.str();
    // game board
    sf::RenderWindow windowGame(sf::VideoMode(800, 600), "Game 1");
    // buttons for playing game
    Button quit("quit", {170, 210}, {200, 75}, sf::Color::Green);
    Button newGame("new game", {170, 310}, {200, 75}, sf::Color::Green);
    newGame.setColorTextNormal(sf::Color::White);
    newGame.setColorTextHover(sf::Color::Red);
    quit.setColorTextNormal(sf::Color::White);
    quit.setColorTextHover(sf::Color::Red);
    // selecting number to play game
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
    // menu return button
    Button mainMenu("menu", {725, 550}, {100, 60}, sf::Color::White);
    mainMenu.setColorTextNormal(sf::Color::Black);
    // game credits
    Button gameCredit(cash, {100,550}, {150,50}, sf::Color::Blue);
    gameCredit.setColorTextNormal(sf::Color::Black);

    // run the program as long as the window is open
    while (windowGame.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event eventGame1;
        while (windowGame.pollEvent(eventGame1))
        {
            // "close requested" event: we close the window
            if (eventGame1.type == sf::Event::Closed)
            {
                windowGame.close();
                s = true;
            }
            // number is picked
            pickNumber.update(eventGame1, windowGame);

            if (newGame.update(eventGame1, windowGame))
            {
                restart = true;
            }
            // quit game
            if (quit.update(eventGame1, windowGame))
            {
                windowGame.close();
                s = true;
            }
            // back to main menu, change game
            if (mainMenu.update(eventGame1, windowGame))
            {
                windowGame.close();
            }
            // select number to play game
            if (selectNumber == false)
            {
                // number 1 to 10
                if (one.update(eventGame1, windowGame))
                {
                    number = 1;
                    selectNumber = true;
                    one.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (two.update(eventGame1, windowGame))
                {
                    number = 2;
                    selectNumber = true;
                    two.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (three.update(eventGame1, windowGame))
                {
                    number = 3;
                    selectNumber = true;
                    three.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (four.update(eventGame1, windowGame))
                {
                    number = 4;
                    selectNumber = true;
                    four.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (five.update(eventGame1, windowGame))
                {
                    number = 5;
                    selectNumber = true;
                    five.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (six.update(eventGame1, windowGame))
                {
                    number = 6;
                    selectNumber = true;
                    six.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (seven.update(eventGame1, windowGame))
                {
                    number = 7;
                    selectNumber = true;
                    seven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (eight.update(eventGame1, windowGame))
                {
                    number = 8;
                    selectNumber = true;
                    eight.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (nine.update(eventGame1, windowGame))
                {
                    number = 9;
                    selectNumber = true;
                    nine.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                    
                }
                if (ten.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    ten.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
            }
        }
        // draw images
        windowGame.clear();
        windowGame.draw(one);
        windowGame.draw(two);
        windowGame.draw(three);
        windowGame.draw(four);
        windowGame.draw(five);
        windowGame.draw(six);
        windowGame.draw(seven);
        windowGame.draw(eight);
        windowGame.draw(nine);
        windowGame.draw(ten);
        windowGame.draw(title);
        windowGame.draw(pickNumber);
        windowGame.draw(quit);
        windowGame.draw(newGame);
        windowGame.draw(mainMenu);
        windowGame.draw(gameCredit);
        windowGame.display();
        // number is selected
        if (selectNumber == true)
        {
            // won game
            if (magicNumber == number)
            { 
                win = true;
                winDisplay = true;
                if(oneTime == true)
                {
                    credit = credit + 100;
                    oneTime = false;
                }
            }
            // lose game
            else
            {
                lose = true;
                loseDisplay = true;
                if(oneTime == true)
                {
                    credit = credit - 10;
                    oneTime = false;
                }
            }
            // display winning pick
            if (winDisplay == true)
            {
                std::string s = std::to_string(magicNumber);
                pickNumber.setText(s); //displays the hidden number
                title.setText("   YOU WIN, GET PAID ");

            }
            // display losing pick
            if (loseDisplay == true)
            {
                std::string s = std::to_string(magicNumber);
                pickNumber.setText(s);
                title.setText("    TRY AGAIN SUCKER  ");
            }
            // display credit
            gameCredit.setText(std::to_string(credit));
            // restart game
            if (restart == true)
            {
                selectNumber = false;
                winDisplay = false;
                loseDisplay = false;
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
                newGame.setColorTextNormal(sf::Color::White);
                title.setText("Guess my number 1 to 10");
                pickNumber.setText("?");
            }
        }
    }
}