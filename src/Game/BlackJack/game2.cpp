#include "../../include/rps.h"

void game2(bool &s)
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
    Button mainMenu("menu", {725, 550}, {100, 60}, sf::Color::White);
    mainMenu.setColorTextNormal(sf::Color::Black);

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

            pickNumber.update(eventGame1, windowGame);
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
        windowGame.draw(mainMenu);
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