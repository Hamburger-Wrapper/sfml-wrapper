
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../headers/button.h"
//#include "../headers/buttonCircle.h"

void game1(); // gotta put these in a header
void game2();
int botChoice();
int RPS(int user, int computer);

int main()
{
<<<<<<< HEAD
<<<<<<< HEAD

=======
    
>>>>>>> 0865dab (game 1 working)
=======

>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
    // switches to turn on games
    bool game1On = false,
         game2On = false,
         game3On = false,
         game4On = false;

<<<<<<< HEAD
<<<<<<< HEAD
    sf::RenderWindow window1(sf::VideoMode(900, 500), "start screen");

<<<<<<< HEAD
    if (!game1On)
    {
        sf::Window window(sf::VideoMode(800, 600), "game 1");
    }
=======
    sf::RenderWindow window(sf::VideoMode(900, 500), "start screen");
=======
    sf::RenderWindow window1(sf::VideoMode(900, 500), "start screen");
>>>>>>> 0865dab (game 1 working)

    //sf::Window windowGame1(sf::VideoMode(800, 600), "Game 1");
    //sf::Window windowGame2(sf::VideoMode(800, 600), "Game 2");
    //sf::Window windowGame3(sf::VideoMode(800, 600), "Game 3");
    //sf::Window windowGame4(sf::VideoMode(800, 600), "Game 4");
>>>>>>> 733f07c (window opens when game is selected, completed starter for Nolan)
=======
    // sf::Window windowGame1(sf::VideoMode(800, 600), "Game 1");
    // sf::Window windowGame2(sf::VideoMode(800, 600), "Game 2");
    // sf::Window windowGame3(sf::VideoMode(800, 600), "Game 3");
    // sf::Window windowGame4(sf::VideoMode(800, 600), "Game 4");
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)

    // buffers at the terminal edges
    Button buffer1("1", {25, 250}, {50, 500}, sf::Color::Red);
    Button buffer2("2", {875, 250}, {50, 500}, sf::Color::Red);
    Button buffer3("3", {450, 25}, {800, 50}, sf::Color::Red);
    Button buffer4("4", {450, 475}, {800, 50}, sf::Color::Red);
    // Button buffer5("", {25,475}, {1000,50}, sf::Color::Black);
    // Button buffer6("", {25,710}, {1000,50}, sf::Color::White);

<<<<<<< HEAD
<<<<<<< HEAD
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
=======
    Button yes("Select A Game",{450,100}, {400, 100}, sf::Color::Red);
=======
    Button yes("Select A Game", {450, 100}, {400, 100}, sf::Color::Red);
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
    yes.setColorTextHover(sf::Color::Cyan);

    // Button no;
    Button playGame1("Guess My Number", {250, 238}, {375, 75}, sf::Color::Red);
    playGame1.setColorTextHover(sf::Color::Cyan);

    Button playGame2("Rock Paper Sicssors", {250, 363}, {375, 75}, sf::Color::Red);
    playGame2.setColorTextHover(sf::Color::Cyan);

    Button playGame3("Tic-Tack-Toe", {650, 238}, {375, 75}, sf::Color::Red);
    playGame3.setColorTextHover(sf::Color::Cyan);

    Button playGame4("Go Marty", {650, 363}, {375, 75}, sf::Color::Red);
    playGame4.setColorTextHover(sf::Color::Cyan);

    // Button error;

<<<<<<< HEAD
    //yes.setFontSize(20);
    //yes.setColorTextHover(sf::Color::Cyan);
    
   // no.setText("No");
   // no.setPosition({350, 610});
   // no.setSize({100, 100});
   // no.setColor(sf::Color::Blue);
   // no.setColorTextHover(sf::Color::Cyan);
   // no.setColorTextNormal(sf::Color::Green);
>>>>>>> 0865dab (game 1 working)
=======
    // yes.setFontSize(20);
    // yes.setColorTextHover(sf::Color::Cyan);
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)

    // no.setText("No");
    // no.setPosition({350, 610});
    // no.setSize({100, 100});
    // no.setColor(sf::Color::Blue);
    // no.setColorTextHover(sf::Color::Cyan);
    // no.setColorTextNormal(sf::Color::Green);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
    // error.setText("error");
    // error.setPosition({150, 610});
    // error.setSize({300, 400});
    // error.setColor(sf::Color::White);
    // error.setColorTextHover(sf::Color::Red);
    // error.setColorTextNormal(sf::Color::Cyan);

    while (window1.isOpen() && !game1On && !game2On && !game3On && !game4On)
=======
    while (window.isOpen() && !game1On && !game2On && !game3On && !game4On)
>>>>>>> 733f07c (window opens when game is selected, completed starter for Nolan)
=======
    while (window1.isOpen() && !game1On && !game2On && !game3On && !game4On)
>>>>>>> 0865dab (game 1 working)
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
            yes.update(event, window1);
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
            //no.update(event, window);
            //error.update(event, window);
            if(playGame1.update(event, window1))
=======
            // no.update(event, window);
            // error.update(event, window);
            if (playGame1.update(event, window1))
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
            {
                game1On = true;
            }

            if (playGame2.update(event, window1))
                game2On = true;
            if (playGame3.update(event, window1))
                game3On = true;
<<<<<<< HEAD
            if(playGame4.update(event, window1))
>>>>>>> 0865dab (game 1 working)
=======
            if (playGame4.update(event, window1))
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
                game4On = true;
        }

        window1.clear();
        window1.draw(yes);
<<<<<<< HEAD
<<<<<<< HEAD
        // window.draw(no);
=======
        //window.draw(no);
>>>>>>> 0865dab (game 1 working)
=======
        // window.draw(no);
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
        window1.draw(playGame1);
        window1.draw(playGame2);
        window1.draw(playGame3);
        window1.draw(playGame4);
<<<<<<< HEAD
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
        window.clear();
        window.draw(yes);
        window.draw(no);
        window.draw(playGame1);
        window.draw(playGame2);
        window.draw(playGame3);
        window.draw(playGame4);
=======
>>>>>>> 0865dab (game 1 working)

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
        // bool switch triggers
        if (game1On)
        {
            window1.draw(buffer1);
        }

        if (game2On)
            window1.draw(buffer2);
        if (game3On)
            window1.draw(buffer3);
        if (game4On)
            window1.draw(buffer4);
        window1.display();
    }

    // game 1
    if (game1On)
    {
        window1.close();
        game1();
    }

    // game 2
    if (game2On)
    {
        window1.close();
        game2();
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

    // start button
    //don't need it, much better without it
    //Button start("start", {600, 250}, {150, 100}, sf::Color::Green);

    Button quit("quit", {170, 210}, {200, 75}, sf::Color::Green);
    Button newGame("new game", {170, 310}, {200, 75}, sf::Color::Green);
    newGame.setColorTextNormal(sf::Color::White);
    newGame.setColorTextHover(sf::Color::Red);
    quit.setColorTextNormal(sf::Color::White);
    quit.setColorTextHover(sf::Color::Red);
    // start button
    // start.setColorTextNormal(sf::Color::White);
    // start.setColorTextHover(sf::Color::Red);
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
    while (windowGame.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event eventGame1;
        while (windowGame.pollEvent(eventGame1))
        {
            // "close requested" event: we close the window
            if (eventGame1.type == sf::Event::Closed)
                windowGame.close();
            // start button is pushed

            // if (start.update(eventGame1, windowGame) && selectNumber)
            // {
            //     start.setColorTextNormal(sf::Color::Red);
            //     generateNumber = true;
            // }

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
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (two.update(eventGame1, windowGame))
                {
                    number = 2;
                    selectNumber = true;
                    two.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (three.update(eventGame1, windowGame))
                {
                    number = 3;
                    selectNumber = true;
                    three.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (four.update(eventGame1, windowGame))
                {
                    number = 4;
                    selectNumber = true;
                    four.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (five.update(eventGame1, windowGame))
                {
                    number = 5;
                    selectNumber = true;
                    five.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (six.update(eventGame1, windowGame))
                {
                    number = 6;
                    selectNumber = true;
                    six.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (seven.update(eventGame1, windowGame))
                {
                    number = 7;
                    selectNumber = true;
                    seven.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (eight.update(eventGame1, windowGame))
                {
                    number = 8;
                    selectNumber = true;
                    eight.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (nine.update(eventGame1, windowGame))
                {
                    number = 9;
                    selectNumber = true;
                    nine.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
                    magicNumber = rand() % 10 + 1; //makes random number
                }
                if (ten.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    ten.setColorTextNormal(sf::Color::Red);
                    srand(time(0));
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
        //windowGame.draw(start);
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
                title.setText("   YOU WIN, GET PAID");
            }

            // display losing pick
            if (lose == true)
            {
                std::string s = std::to_string(magicNumber);
                pickNumber.setText(s);
                title.setText("   TRY AGAIN SUCKER");
            }

            if (restart == true)
            {
                // generateNumber = false;
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
                //start.setColorTextNormal(sf::Color::White);
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

<<<<<<< HEAD
<<<<<<< HEAD
        if(game1On)
    {
        sf::Window window(sf::VideoMode(800, 600), "game 1");
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
=======
>>>>>>> 733f07c (window opens when game is selected, completed starter for Nolan)

        // game 2
       if(game2On)
       {
    //    window1.close();
        sf::Window windowGame2(sf::VideoMode(800, 600), "Game 2");

                // run the program as long as the window is open
                while (windowGame2.isOpen())
=======
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
>>>>>>> 4ba6e7a (Refactored, added game 2, error fixed)
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
    srand(static_cast<unsigned int>(time(0)));
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