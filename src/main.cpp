
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "include/button.h"
#include "include/menu.h"

//#include "../headers/buttonCircle.h"

   // gotta put these in a header
void game1(); 
void game2();
int botChoice();
int RPS(int user, int computer);

int main()
{
    // switches to turn on each game application
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false;

    // main menu display
    sf::RenderWindow window(sf::VideoMode(900, 500), "main game menu");
    window.setVerticalSyncEnabled(true);

    // handle main game menu
    mainMenu(window, game1On, game2On, game3On, game4On);

    // game 1 Roulette
    if (game1On)
    {
        window.close();
        game1();
    }
    // game 2 Rock Paper Scissors
    if (game2On)
    {
        window.close();
        game2();
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

    return 0;
}


void game1()
{
    // game 1

    // bool generateNumber = false;
    bool selectNumber = false;
    bool win = false;
    bool lose = false;
    bool restart = false;
    int number = -1;
    int magicNumber = -1;

    sf::RenderWindow windowGame(sf::VideoMode(800, 600), "Game 1");

    Button quit("quit", {170, 210}, {200, 75}, sf::Color::Green);
    Button newGame("new game", {170, 310}, {200, 75}, sf::Color::Green);
    newGame.setColorTextNormal(sf::Color::White);
    newGame.setColorTextHover(sf::Color::Red);
    quit.setColorTextNormal(sf::Color::White);
    quit.setColorTextHover(sf::Color::Red);

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
    while (windowGame.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event eventGame1;
        while (windowGame.pollEvent(eventGame1))
        {
            // "close requested" event: we close the window
            if (eventGame1.type == sf::Event::Closed)
                windowGame.close();


            pickNumber.update(eventGame1, windowGame);
            if (newGame.update(eventGame1, windowGame))
            {
                restart = true;
            }

            if (quit.update(eventGame1, windowGame))
            {
                windowGame.close();
            }

            if (selectNumber == false)
            {
                if (one.update(eventGame1, windowGame))
                {
                    number = 1;
                    selectNumber = true;
                    one.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (two.update(eventGame1, windowGame))
                {
                    number = 2;
                    selectNumber = true;
                    two.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (three.update(eventGame1, windowGame))
                {
                    number = 3;
                    selectNumber = true;
                    three.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (four.update(eventGame1, windowGame))
                {
                    number = 4;
                    selectNumber = true;
                    four.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (five.update(eventGame1, windowGame))
                {
                    number = 5;
                    selectNumber = true;
                    five.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (six.update(eventGame1, windowGame))
                {
                    number = 6;
                    selectNumber = true;
                    six.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (seven.update(eventGame1, windowGame))
                {
                    number = 7;
                    selectNumber = true;
                    seven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (eight.update(eventGame1, windowGame))
                {
                    number = 8;
                    selectNumber = true;
                    eight.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (nine.update(eventGame1, windowGame))
                {
                    number = 9;
                    selectNumber = true;
                    nine.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (ten.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    ten.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
            }
        }

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
        windowGame.display();

        if (selectNumber == true)
        {
            if (magicNumber == number)
            {
                win = true;
            }
            else
            {
                lose = true;
            }

            // display winning pick
            if (win == true)
            {
                std::string s = std::to_string(magicNumber);
                pickNumber.setText(s); //displays the hidden number
                title.setText("YOU WIN, GET PAID");
            }

            // display losing pick
            if (lose == true)
            {
                std::string s = std::to_string(magicNumber);
                pickNumber.setText(s);
                title.setText("TRY AGAIN SUCKER");
            }

            if (restart == true)
            {
                selectNumber = false;
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
                newGame.setColorTextNormal(sf::Color::White);
                title.setText("Guess my number 1 to 10");
                pickNumber.setText("?");
            }
        }
    }
}
void game2()
{
    // game 2
    bool selectNumber = false;
    bool restart = false;
    int bot = 0;
    int player = 0;

    sf::RenderWindow windowGame(sf::VideoMode(800, 600), "Game 2");

    // start button has no need

    Button quit("quit", {170, 210}, {200, 75}, sf::Color::Green);
    Button newGame("new game", {170, 310}, {200, 75}, sf::Color::Green);
    newGame.setColorTextNormal(sf::Color::White);
    newGame.setColorTextHover(sf::Color::Red);
    quit.setColorTextNormal(sf::Color::White);
    quit.setColorTextHover(sf::Color::Red);
    // ten number buttons
    Button one("rock", {200, 500}, {100, 50}, sf::Color::Blue);
    Button two("paper", {300, 500}, {100, 50}, sf::Color::Blue);
    Button three("scissors", {400, 500}, {100, 50}, sf::Color::Blue);
    Button title("rock paper scissor", {400, 100}, {700, 100}, sf::Color::Blue);
    Button pickNumber("?", {400, 250}, {100, 100}, sf::Color::Blue);

    // run the program as long as the window is open
    while (windowGame.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event eventGame1;
        while (windowGame.pollEvent(eventGame1))
        {
            // "close requested" event: we close the window
            if (eventGame1.type == sf::Event::Closed)
                windowGame.close();
            // start button removed, there is no need

            pickNumber.update(eventGame1, windowGame);
            if (newGame.update(eventGame1, windowGame))
            {
                restart = true;
            }

            if (quit.update(eventGame1, windowGame))
            {
                windowGame.close();
            }

            if (selectNumber == false)
            {
                if (one.update(eventGame1, windowGame))
                {
                    player = 1;
                    selectNumber = true;
                    one.setColorTextNormal(sf::Color::Red);
                    bot = botChoice(); // best place, only generates ONCE
                }
                if (two.update(eventGame1, windowGame))
                {
                    player = 2;
                    selectNumber = true;
                    two.setColorTextNormal(sf::Color::Red);
                    bot = botChoice(); // best place, only generates ONCE
                }
                if (three.update(eventGame1, windowGame))
                {
                    player = 3;
                    selectNumber = true;
                    three.setColorTextNormal(sf::Color::Red);
                    bot = botChoice(); // best place, only generates ONCE
                }
            }
        }

        windowGame.clear();
        windowGame.draw(one);
        windowGame.draw(two);
        windowGame.draw(three);
        windowGame.draw(title);
        windowGame.draw(pickNumber);
        windowGame.draw(quit);
        windowGame.draw(newGame);
        windowGame.display();
        if (selectNumber)
        {
            if (RPS(player, bot) == 1) // display winning pick
                {
                    title.setText("win");
                    std::string s = std::to_string(bot);
                    pickNumber.setText(s);
                }
                if (RPS(player, bot) == 0) //losing pick
                {
                    title.setText("lose");
                    std::string s = std::to_string(bot);
                    pickNumber.setText(s);
                }
                else if (RPS(player, bot) == 2) // tie
                {
                    title.setText("Tie");
                    std::string s = std::to_string(bot);
                    pickNumber.setText(s);
                }

                if (restart == true)
                {
                    selectNumber = false;
                    restart = false;
                    player = 0;
                    bot = 0;
                    one.setColorTextNormal(sf::Color::Green);
                    two.setColorTextNormal(sf::Color::Green);
                    three.setColorTextNormal(sf::Color::Green);
                    newGame.setColorTextNormal(sf::Color::White);
                    title.setText("rock paper scissor");
                }
        }
    }
}

int botChoice()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    return (rand() % 3) + 1; // random number between 1 and 3
}

int RPS(int user, int computer)
{
    if (user == computer)
    {
        // It's a tie
        return 2;
    }
    else if (user == 1 && computer == 2)
    {
        // lose
        return 0;
    }
    else if (user == 1 && computer == 3)
    {
        // win
        return 1;
    }
    else if (user == 2 && computer == 1)
    {
        // win
        return 1;
    }
    else if (user == 2 && computer == 3)
    {
        // lose
        return 0;
    }
    else if (user == 3 && computer == 1)
    {
        // lose
        return 0;
    }
    else if (user == 3 && computer == 2)
    {
        // win
        return 1;
    }
    return -1; // not needed, used to prevent a error
}
