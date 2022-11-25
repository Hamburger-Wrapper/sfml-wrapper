#include "../../include/blackjack.h"

void game4(bool &s, int &credit)
{
    // game 1
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
    sf::RenderWindow windowGame(sf::VideoMode(825, 700), "Game 4");
    // buttons for playing game
    Button quit("quit", {100, 600}, {150, 50}, sf::Color::White);
    Button newGame("new game", {100, 550}, {150, 50}, sf::Color::White);
    newGame.setColorTextNormal(sf::Color::Black);
    newGame.setColorTextHover(sf::Color::Red);
    quit.setColorTextNormal(sf::Color::Black);
    quit.setColorTextHover(sf::Color::Red);
    // selecting number to play game
    Button playerOne("?", {250, 500}, {80, 100}, sf::Color::White);
    playerOne.setColorTextNormal(sf::Color::Red);
    Button playerTwo("?", {350, 500}, {80, 100}, sf::Color::White);
    playerTwo.setColorTextNormal(sf::Color::Red);
    Button playerThree("?", {450, 500}, {80, 100}, sf::Color::White);
    playerThree.setColorTextNormal(sf::Color::Red);
    Button playerFour("?", {550, 500}, {80, 100}, sf::Color::White);
    playerFour.setColorTextNormal(sf::Color::Red);
    Button playerFive("?", {650, 500}, {80, 100}, sf::Color::White);
    playerFive.setColorTextNormal(sf::Color::Red);
    Button playerSix("?", {750, 500}, {80, 100}, sf::Color::White);
    playerSix.setColorTextNormal(sf::Color::Red);
    Button playerSeven("?", {250, 625}, {80, 100}, sf::Color::White);
    playerSeven.setColorTextNormal(sf::Color::Red);
    Button playerEight("?", {350, 625}, {80, 100}, sf::Color::White);
    playerEight.setColorTextNormal(sf::Color::Red);
    Button playerNine("?", {450, 625}, {80, 100}, sf::Color::White);
    playerNine.setColorTextNormal(sf::Color::Red);
    Button playerTen("?", {550, 625}, {80, 100}, sf::Color::White);
    playerTen.setColorTextNormal(sf::Color::Red);
    Button playerEleven("?", {650, 625}, {80, 100}, sf::Color::White);
    playerEleven.setColorTextNormal(sf::Color::Red);
    Button playerTwelve("?", {750, 625}, {80, 100}, sf::Color::White);
    playerTwelve.setColorTextNormal(sf::Color::Red);
    // dealers cards
    Button dealerOne("?", {250, 200}, {80, 100}, sf::Color::White);
    dealerOne.setColorTextNormal(sf::Color::Red);
    Button dealerTwo("?", {350, 200}, {80, 100}, sf::Color::White);
    dealerTwo.setColorTextNormal(sf::Color::Red);
    Button dealerThree("?", {450, 200}, {80, 100}, sf::Color::White);
    dealerThree.setColorTextNormal(sf::Color::Red);
    Button dealerFour("?", {550, 200}, {80, 100}, sf::Color::White);
    dealerFour.setColorTextNormal(sf::Color::Red);
    Button dealerFive("?", {650, 200}, {80, 100}, sf::Color::White);
    dealerFive.setColorTextNormal(sf::Color::Red);
    Button dealerSix("?", {750, 200}, {80, 100}, sf::Color::White);
    dealerSix.setColorTextNormal(sf::Color::Red);
    Button dealerSeven("?", {250, 325}, {80, 100}, sf::Color::White);
    dealerSeven.setColorTextNormal(sf::Color::Red);
    Button dealerEight("?", {350, 325}, {80, 100}, sf::Color::White);
    dealerEight.setColorTextNormal(sf::Color::Red);
    Button dealerNine("?", {450, 325}, {80, 100}, sf::Color::White);
    dealerNine.setColorTextNormal(sf::Color::Red);
    Button dealerTen("?", {550, 325}, {80, 100}, sf::Color::White);
    dealerTen.setColorTextNormal(sf::Color::Red);
    Button dealerEleven("?", {650, 325}, {80, 100}, sf::Color::White);
    dealerEleven.setColorTextNormal(sf::Color::Red);
    Button dealerTwelve("?", {750, 325}, {80, 100}, sf::Color::White);
    dealerTwelve.setColorTextNormal(sf::Color::Red);

    Button title("Blackjack", {413, 75}, {700, 100}, sf::Color::Blue);

    // players directions
    Button hit("hit", {475, 513}, {150, 75}, sf::Color::White);
    hit.setColorTextNormal(sf::Color::Black);
    Button stay("stay", {325, 513}, {150, 75}, sf::Color::White);
    stay.setColorTextNormal(sf::Color::Black);

    // menu return button
    Button mainMenu("menu", {100,650}, {150, 50}, sf::Color::White);
    mainMenu.setColorTextNormal(sf::Color::Black);
    // game credits
    // total credits left
    Button gameCredit(cash, {100,475}, {150,50}, sf::Color::Blue);
    gameCredit.setColorTextNormal(sf::Color::Black);
    // dealerLabel
    Button dealerLabel("Dealer", {100, 175}, {150, 50}, sf::Color::Blue);
    dealerLabel.setColorTextNormal(sf::Color::Black);
    // playerLabel
    Button playerLabel("Player", {100, 425}, {150, 50}, sf::Color::Blue);
    playerLabel.setColorTextNormal(sf::Color::Black);

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

            // players directions
            hit.update(eventGame1, windowGame);
            stay.update(eventGame1, windowGame);

            if (newGame.update(eventGame1, windowGame))
            {
                restart = true;
            }

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

            if (selectNumber == false)
            {
                if (playerOne.update(eventGame1, windowGame))
                {
                    number = 1;
                    selectNumber = true;
                    playerOne.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerTwo.update(eventGame1, windowGame))
                {
                    number = 2;
                    selectNumber = true;
                    playerTwo.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerThree.update(eventGame1, windowGame))
                {
                    number = 3;
                    selectNumber = true;
                    playerThree.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerFour.update(eventGame1, windowGame))
                {
                    number = 4;
                    selectNumber = true;
                    playerFour.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerFive.update(eventGame1, windowGame))
                {
                    number = 5;
                    selectNumber = true;
                    playerFive.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerSix.update(eventGame1, windowGame))
                {
                    number = 6;
                    selectNumber = true;
                    playerSix.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerSeven.update(eventGame1, windowGame))
                {
                    number = 7;
                    selectNumber = true;
                    playerSeven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerEight.update(eventGame1, windowGame))
                {
                    number = 8;
                    selectNumber = true;
                    playerEight.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerNine.update(eventGame1, windowGame))
                {
                    number = 9;
                    selectNumber = true;
                    playerNine.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                    
                }
                if (playerTen.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    playerTen.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerEleven.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    playerEleven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (playerTwelve.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    playerTwelve.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerOne.update(eventGame1, windowGame))
                {
                    number = 1;
                    selectNumber = true;
                    dealerOne.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerTwo.update(eventGame1, windowGame))
                {
                    number = 2;
                    selectNumber = true;
                    dealerTwo.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerThree.update(eventGame1, windowGame))
                {
                    number = 3;
                    selectNumber = true;
                    dealerThree.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerFour.update(eventGame1, windowGame))
                {
                    number = 4;
                    selectNumber = true;
                    dealerFour.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerFive.update(eventGame1, windowGame))
                {
                    number = 5;
                    selectNumber = true;
                    dealerFive.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerSix.update(eventGame1, windowGame))
                {
                    number = 6;
                    selectNumber = true;
                    dealerSix.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerSeven.update(eventGame1, windowGame))
                {
                    number = 7;
                    selectNumber = true;
                    dealerSeven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerEight.update(eventGame1, windowGame))
                {
                    number = 8;
                    selectNumber = true;
                    dealerEight.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerNine.update(eventGame1, windowGame))
                {
                    number = 9;
                    selectNumber = true;
                    dealerNine.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerTen.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    dealerTen.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerEleven.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    dealerEleven.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
                if (dealerTwelve.update(eventGame1, windowGame))
                {
                    number = 10;
                    selectNumber = true;
                    dealerTwelve.setColorTextNormal(sf::Color::Red);
                    srand(time(nullptr));
                    magicNumber = rand() % 10 + 1; //makes random number
                    oneTime = true;
                }
            }   
        }

        windowGame.clear();
        windowGame.draw(playerOne);
        windowGame.draw(playerTwo);
        windowGame.draw(playerThree);
        windowGame.draw(playerFour);
        windowGame.draw(playerFive);
        windowGame.draw(playerSix);
        windowGame.draw(playerSeven);
        windowGame.draw(playerEight);
        windowGame.draw(playerNine);
        windowGame.draw(playerTen);
        windowGame.draw(playerEleven);
        windowGame.draw(playerTwelve);
        windowGame.draw(dealerOne);
        windowGame.draw(dealerTwo);
        windowGame.draw(dealerThree);
        windowGame.draw(dealerFour);
        windowGame.draw(dealerFive);
        windowGame.draw(dealerSix);
        windowGame.draw(dealerSeven);
        windowGame.draw(dealerEight);
        windowGame.draw(dealerNine);
        windowGame.draw(dealerTen);
        windowGame.draw(dealerEleven);
        windowGame.draw(dealerTwelve);
        windowGame.draw(dealerLabel);
        windowGame.draw(playerLabel);


        windowGame.draw(title);
        windowGame.draw(hit);
        windowGame.draw(stay);
        windowGame.draw(quit);
        windowGame.draw(newGame);
        windowGame.draw(mainMenu);
        windowGame.draw(gameCredit);
        windowGame.display();

        if (selectNumber == true)
        {
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
                stay.setText(s); //displays the hidden number
            
                title.setText("YOU WIN, GET PAID");

            }

            // display losing pick
            if (loseDisplay == true)
            {
                std::string s = std::to_string(magicNumber);
                stay.setText(s);
                title.setText("TRY AGAIN SUCKER");
            }

            // display credit
            gameCredit.setText(std::to_string(credit));

            if (restart == true)
            {
                selectNumber = false;
                winDisplay = false;
                loseDisplay = false;
                restart = false;
                number = -1;
                magicNumber = -1;
                // players cards
                playerOne.setColorTextNormal(sf::Color::Green);
                playerTwo.setColorTextNormal(sf::Color::Green);
                playerThree.setColorTextNormal(sf::Color::Green);
                playerFour.setColorTextNormal(sf::Color::Green);
                playerFive.setColorTextNormal(sf::Color::Green);
                playerSix.setColorTextNormal(sf::Color::Green);
                playerSeven.setColorTextNormal(sf::Color::Green);
                playerEight.setColorTextNormal(sf::Color::Green);
                playerNine.setColorTextNormal(sf::Color::Green);
                playerTen.setColorTextNormal(sf::Color::Green);
                playerEleven.setColorTextNormal(sf::Color::Green);
                playerTwelve.setColorTextNormal(sf::Color::Green);
                // dealers cards
                dealerOne.setColorTextNormal(sf::Color::Green);
                dealerTwo.setColorTextNormal(sf::Color::Green);
                dealerThree.setColorTextNormal(sf::Color::Green);
                dealerFour.setColorTextNormal(sf::Color::Green);
                dealerFive.setColorTextNormal(sf::Color::Green);
                dealerSix.setColorTextNormal(sf::Color::Green);
                dealerSeven.setColorTextNormal(sf::Color::Green);
                dealerEight.setColorTextNormal(sf::Color::Green);
                dealerNine.setColorTextNormal(sf::Color::Green);
                dealerTen.setColorTextNormal(sf::Color::Green);
                dealerEleven.setColorTextNormal(sf::Color::Green);
                dealerTwelve.setColorTextNormal(sf::Color::Green);

                newGame.setColorTextNormal(sf::Color::White);
                title.setText("Guess my number 1 to 10");
                stay.setText("?");
            }
        }
    }
}