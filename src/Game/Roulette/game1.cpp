#include "../../include/roulette.h"

void game1(bool &s, int &credit)
{
    // game play switches
    bool selectNumber = false;          // switch for  selecting a number 
    bool win = false;                   // switch for win 
    bool lose = false;                  // switch for lose
    bool restart = false;               // switch for restart game
    bool menu = false;                  // switch for menu
    bool loseDisplay = false;           // switch for lose display
    bool winDisplay = false;            // switch for win display
    bool oneTime = true;               // switch to update credit 1 time per game
    bool spinWheel = false;             // switch to spin wheel


    int number = -1;                     // users number
    int magicNumber = 1;                // random number of game
    bool rotating = false;               // switch for wheel rotation
    int time = 0;                       // time for wheel rotation
    int time2 = 2000 + rand() % 36;     // random time for wheel to stop
    int multipier = 0;                  // multiplier for win
    int bet = 0;                        // number of credits bet  
    bool numberDeterminedBySpin = false;

    // bet switches
    bool switch1 = false,
         switch2 = false,
         switch3 = false,
         switch4 = false,
         switch5 = false,
         switch6 = false,
         switch7 = false,
         switch8 = false,
         switch9 = false,
         switch10 = false,   
         switch11 = false,
         switch12 = false,
         switch13 = false,
         switch14 = false,   
         switch15 = false,
         switch16 = false,
         switch17 = false,
         switch18 = false,   
         switch19 = false,
         switch20 = false,
         switch21 = false,
         switch22 = false,
         switch23 = false,
         switch24 = false,
         switch25 = false,
         switch26 = false,
         switch27 = false,
         switch28 = false,
         switch29 = false,
         switch30 = false,
         switch31 = false,
         switch32 = false,
         switch33 = false,
         switch34 = false,
         switch35 = false,
         switch36 = false,
         switchEven = false,
         switchOdd = false,
         switchRed = false,
         switchBlack = false,
         switch1to18 = false,
         switch19to36 = false;



    // convert credit for credit displaying to game screen
    std::string cash;
    std::stringstream ss;
    ss<<credit;
    cash = ss.str();

    // game board window
    sf::RenderWindow windowGame(sf::VideoMode(825, 700), "Game 4");

    // new game button
    Button newGame("new game", {100, 550}, {150, 50}, sf::Color::White);
    newGame.setColorTextNormal(sf::Color::Black);
    newGame.setColorTextHover(sf::Color::Red);

    // quit button
    Button quit("quit", {100, 600}, {150, 50}, sf::Color::White);
    quit.setColorTextNormal(sf::Color::Black);
    quit.setColorTextHover(sf::Color::Red);

    // spin button
    Button spin("spin", {100, 300}, {150, 50}, sf::Color::White);
    spin.setColorTextNormal(sf::Color::White);
    spin.setColorTextHover(sf::Color::Red);


    // starting positions and metric's for betting buttons
    float xStartnumber = 225;
    float yStartnumber = 500;
    float xNumberOffset = 50;
    float yNumberOffset = 50;
    float widthNumber = 50;
    float heightNumber = 50;

    // 1st row of betting numbers
    Button one("1", {xStartnumber, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    one.setColorTextNormal(sf::Color::White);
    one.setColorTextHover(sf::Color::Red);
    Button two("2", {xStartnumber+xNumberOffset, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    two.setColorTextNormal(sf::Color::White);
    two.setColorTextHover(sf::Color::Red);
    Button three("3", {xStartnumber+xNumberOffset*2, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    three.setColorTextNormal(sf::Color::White);
    three.setColorTextHover(sf::Color::Red);
    Button four("4", {xStartnumber+xNumberOffset*3, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    four.setColorTextNormal(sf::Color::White);
    four.setColorTextHover(sf::Color::Red);
    Button five("5", {xStartnumber+xNumberOffset*4, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    five.setColorTextNormal(sf::Color::White);
    five.setColorTextHover(sf::Color::Red);
    Button six("6", {xStartnumber+xNumberOffset*5, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    six.setColorTextNormal(sf::Color::White);
    six.setColorTextHover(sf::Color::Red);
    Button seven("7", {xStartnumber+xNumberOffset*6, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    seven.setColorTextNormal(sf::Color::White);
    seven.setColorTextHover(sf::Color::Red);
    Button eight("8", {xStartnumber+xNumberOffset*7, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    eight.setColorTextNormal(sf::Color::White);
    eight.setColorTextHover(sf::Color::Red);
    Button nine("9", {xStartnumber+xNumberOffset*8, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    nine.setColorTextNormal(sf::Color::White);
    nine.setColorTextHover(sf::Color::Red);
    Button ten("10", {xStartnumber+xNumberOffset*9, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    ten.setColorTextNormal(sf::Color::White);
    ten.setColorTextHover(sf::Color::Red);
    Button eleven("11", {xStartnumber+xNumberOffset*10, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    eleven.setColorTextNormal(sf::Color::White);
    eleven.setColorTextHover(sf::Color::Red);
    Button twelve("12", {xStartnumber+xNumberOffset*11, yStartnumber}, {widthNumber, heightNumber}, sf::Color::Green);
    twelve.setColorTextNormal(sf::Color::White);
    twelve.setColorTextHover(sf::Color::Red);

    // 2nd row of betting numbers
    Button thirteen("13", {xStartnumber, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);   
    thirteen.setColorTextNormal(sf::Color::White);
    thirteen.setColorTextHover(sf::Color::Red);
    Button fourteen("14", {xStartnumber+xNumberOffset, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    fourteen.setColorTextNormal(sf::Color::White);
    fourteen.setColorTextHover(sf::Color::Red);
    Button fifteen("15", {xStartnumber+xNumberOffset*2, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    fifteen.setColorTextNormal(sf::Color::White);
    fifteen.setColorTextHover(sf::Color::Red);
    Button sixteen("16", {xStartnumber+xNumberOffset*3, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    sixteen.setColorTextNormal(sf::Color::White);
    sixteen.setColorTextHover(sf::Color::Red);
    Button seventeen("17", {xStartnumber+xNumberOffset*4, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    seventeen.setColorTextNormal(sf::Color::White);
    seventeen.setColorTextHover(sf::Color::Red);
    Button eighteen("18", {xStartnumber+xNumberOffset*5, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    eighteen.setColorTextNormal(sf::Color::White);
    eighteen.setColorTextHover(sf::Color::Red);
    Button nineteen("19", {xStartnumber+xNumberOffset*6, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    nineteen.setColorTextNormal(sf::Color::White);
    nineteen.setColorTextHover(sf::Color::Red);
    Button twenty("20", {xStartnumber+xNumberOffset*7, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    twenty.setColorTextNormal(sf::Color::White);
    twenty.setColorTextHover(sf::Color::Red);
    Button twentyone("21", {xStartnumber+xNumberOffset*8, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    twentyone.setColorTextNormal(sf::Color::White);
    twentyone.setColorTextHover(sf::Color::Red);
    Button twentytwo("22", {xStartnumber+xNumberOffset*9, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    twentytwo.setColorTextNormal(sf::Color::White);
    twentytwo.setColorTextHover(sf::Color::Red);
    Button twentythree("23", {xStartnumber+xNumberOffset*10, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    twentythree.setColorTextNormal(sf::Color::White);
    twentythree.setColorTextHover(sf::Color::Red);
    Button twentyfour("24", {xStartnumber+xNumberOffset*11, yStartnumber+yNumberOffset}, {widthNumber, heightNumber}, sf::Color::Green);
    twentyfour.setColorTextNormal(sf::Color::White);
    twentyfour.setColorTextHover(sf::Color::Red);

    // third row of numbers
    Button twentyfive("25", {xStartnumber, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    twentyfive.setColorTextNormal(sf::Color::White);
    twentyfive.setColorTextHover(sf::Color::Red);
    Button twentysix("26", {xStartnumber+xNumberOffset, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    twentysix.setColorTextNormal(sf::Color::White);
    twentysix.setColorTextHover(sf::Color::Red);
    Button twentyseven("27", {xStartnumber+xNumberOffset*2, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    twentyseven.setColorTextNormal(sf::Color::White);
    twentyseven.setColorTextHover(sf::Color::Red);
    Button twentyeight("28", {xStartnumber+xNumberOffset*3, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    twentyeight.setColorTextNormal(sf::Color::White);
    twentyeight.setColorTextHover(sf::Color::Red);
    Button twentynine("29", {xStartnumber+xNumberOffset*4, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    twentynine.setColorTextNormal(sf::Color::White);
    twentynine.setColorTextHover(sf::Color::Red);
    Button thirty("30", {xStartnumber+xNumberOffset*5, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirty.setColorTextNormal(sf::Color::White);
    thirty.setColorTextHover(sf::Color::Red);
    Button thirtyone("31", {xStartnumber+xNumberOffset*6, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtyone.setColorTextNormal(sf::Color::White);
    thirtyone.setColorTextHover(sf::Color::Red);
    Button thirtytwo("32", {xStartnumber+xNumberOffset*7, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtytwo.setColorTextNormal(sf::Color::White);
    thirtytwo.setColorTextHover(sf::Color::Red);
    Button thirtythree("33", {xStartnumber+xNumberOffset*8, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtythree.setColorTextNormal(sf::Color::White);
    thirtythree.setColorTextHover(sf::Color::Red);
    Button thirtyfour("34", {xStartnumber+xNumberOffset*9, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtyfour.setColorTextNormal(sf::Color::White);
    thirtyfour.setColorTextHover(sf::Color::Red);
    Button thirtyfive("35", {xStartnumber+xNumberOffset*10, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtyfive.setColorTextNormal(sf::Color::White);
    thirtyfive.setColorTextHover(sf::Color::Red);
    Button thirtysix("36", {xStartnumber+xNumberOffset*11, yStartnumber+yNumberOffset*2}, {widthNumber, heightNumber}, sf::Color::Green);
    thirtysix.setColorTextNormal(sf::Color::White);
    thirtysix.setColorTextHover(sf::Color::Red);

    // fourth row of numbers
    Button even("Even", {xStartnumber+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    even.setColorTextNormal(sf::Color::White);
    even.setColorTextHover(sf::Color::Red);
    Button odd("Odd", {xStartnumber+xNumberOffset*2+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    odd.setColorTextNormal(sf::Color::White);
    odd.setColorTextHover(sf::Color::Red);
    Button red("Red", {xStartnumber+xNumberOffset*4+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    red.setColorTextNormal(sf::Color::White);
    red.setColorTextHover(sf::Color::Red);
    Button black("Black", {xStartnumber+xNumberOffset*6+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    black.setColorTextNormal(sf::Color::White);
    black.setColorTextHover(sf::Color::Red);
    Button first18("1-18", {xStartnumber+xNumberOffset*8+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    first18.setColorTextNormal(sf::Color::White);
    first18.setColorTextHover(sf::Color::Red);
    Button second18("19-36", {xStartnumber+xNumberOffset*10+25, yStartnumber+yNumberOffset*3}, {2*widthNumber, heightNumber}, sf::Color::Green);
    second18.setColorTextNormal(sf::Color::White);
    second18.setColorTextHover(sf::Color::Red);

    // header
    Button title("Roulette", {413, 75}, {700, 100}, sf::Color::Blue);

    // wheel
    Button wheel(" ?", {500, 300}, {500, 275}, sf::Color::Blue);
    wheel.setColorTextNormal(sf::Color::White);

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

            // starts a new game button, resets all switches
            if (newGame.update(eventGame1, windowGame))
            {
                restart = true;
            }

            // quit game button
            if (quit.update(eventGame1, windowGame))
            {
                windowGame.close();
                s = true;
            }

            if (spin.update(eventGame1, windowGame))
            {
                spinWheel = true;
                rotating = true;
                newGame.setColorTextNormal(sf::Color::Red);
                spin.setColorTextNormal(sf::Color::Red);

            }

            // back to main menu, change game
            if (mainMenu.update(eventGame1, windowGame))
            {
                windowGame.close();
            }

            // no game being played set bets, each button pushed sets a switch
            if (spinWheel == false)
            {
                // bet 1 selected
                if (one.update(eventGame1, windowGame))
                {
                    switch1 = true;
                    selectNumber = true;
                    one.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (two.update(eventGame1, windowGame))
                {
                    switch2 = true;
                    selectNumber = true;
                    two.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (three.update(eventGame1, windowGame))
                {
                    switch3 = true;
                    selectNumber = true;
                    three.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (four.update(eventGame1, windowGame))
                {
                    switch4 = true;
                    selectNumber = true;
                    four.setColorTextNormal(sf::Color::Red);
                    oneTime = true; 
                    bet++;
                   
                }
                if (five.update(eventGame1, windowGame))
                {
                    switch5 = true;
                    selectNumber = true;
                    five.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (six.update(eventGame1, windowGame))
                {
                    switch6 = true;
                    selectNumber = true;
                    six.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (seven.update(eventGame1, windowGame))
                {
                    switch7 = true;
                    selectNumber = true;
                    seven.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (eight.update(eventGame1, windowGame))
                {
                    switch8 = true;
                    selectNumber = true;
                    eight.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (nine.update(eventGame1, windowGame))
                {
                    switch9 = true;
                    selectNumber = true;
                    nine.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                    
                }
                if (ten.update(eventGame1, windowGame))
                {
                    switch10 = true;
                    selectNumber = true;
                    ten.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (eleven.update(eventGame1, windowGame))
                {
                    switch11 = true;
                    selectNumber = true;
                    eleven.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twelve.update(eventGame1, windowGame))
                {
                    switch12 = true;
                    selectNumber = true;
                    twelve.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirteen.update(eventGame1, windowGame))
                {
                    switch13 = true;
                    selectNumber = true;
                    thirteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (fourteen.update(eventGame1, windowGame))
                {
                    switch14 = true;
                    selectNumber = true;
                    fourteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (fifteen.update(eventGame1, windowGame))
                {
                    switch15 = true;
                    selectNumber = true;
                    fifteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (sixteen.update(eventGame1, windowGame))
                {
                    switch16 = true;
                    selectNumber = true;
                    sixteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (seventeen.update(eventGame1, windowGame))
                {
                    switch17 = true;
                    selectNumber = true;
                    seventeen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (eighteen.update(eventGame1, windowGame))
                {
                    switch18 = true;
                    selectNumber = true;
                    eighteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (nineteen.update(eventGame1, windowGame))
                {
                    switch19 = true;
                    selectNumber = true;
                    nineteen.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twenty.update(eventGame1, windowGame))
                {
                    switch20 = true;
                    selectNumber = true;
                    twenty.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentyone.update(eventGame1, windowGame))
                {
                    switch21 = true;
                    selectNumber = true;
                    twentyone.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentytwo.update(eventGame1, windowGame))
                {
                    switch22 = true;
                    selectNumber = true;
                    twentytwo.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentythree.update(eventGame1, windowGame))
                {
                    switch23 = true;
                    selectNumber = true;
                    twentythree.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentyfour.update(eventGame1, windowGame))
                {
                    switch24 = true;
                    selectNumber = true;
                    twentyfour.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentyfive.update(eventGame1, windowGame))
                {
                    switch25 = true;
                    selectNumber = true;
                    twentyfive.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentysix.update(eventGame1, windowGame))
                {
                    switch26 = true;
                    selectNumber = true;
                    twentysix.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentyseven.update(eventGame1, windowGame))
                {
                    switch27 = true;
                    selectNumber = true;
                    twentyseven.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentyeight.update(eventGame1, windowGame))
                {
                    switch28 = true;
                    selectNumber = true;
                    twentyeight.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (twentynine.update(eventGame1, windowGame))
                {
                    switch29 = true;
                    selectNumber = true;
                    twentynine.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirty.update(eventGame1, windowGame))
                {
                    switch30 = true;
                    selectNumber = true;
                    thirty.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtyone.update(eventGame1, windowGame))
                {
                    switch31 = true;
                    selectNumber = true;
                    thirtyone.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtytwo.update(eventGame1, windowGame))
                {
                    switch32 = true;
                    selectNumber = true;
                    thirtytwo.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtythree.update(eventGame1, windowGame))
                {
                    switch33 = true;
                    selectNumber = true;
                    thirtythree.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtyfour.update(eventGame1, windowGame))
                {
                    switch34 = true;
                    selectNumber = true;
                    thirtyfour.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtyfive.update(eventGame1, windowGame))
                {
                    switch35 = true;
                    selectNumber = true;
                    thirtyfive.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (thirtysix.update(eventGame1, windowGame))
                {
                    switch36 = true;
                    selectNumber = true;
                    thirtysix.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (even.update(eventGame1, windowGame))
                {
                    switchEven = true;
                    selectNumber = true;
                    even.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (odd.update(eventGame1, windowGame))
                {
                    switchOdd = true;
                    selectNumber = true;
                    odd.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (red.update(eventGame1, windowGame))
                {
                    switchRed = true;
                    selectNumber = true;
                    red.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (black.update(eventGame1, windowGame))
                {
                    switchBlack = true;
                    selectNumber = true;
                    black.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (first18.update(eventGame1, windowGame))
                {
                    switch1to18 = true;
                    selectNumber = true;
                    first18.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }
                if (second18.update(eventGame1, windowGame))
                {
                    switch19to36 = true;
                    selectNumber = true;
                    second18.setColorTextNormal(sf::Color::Red);
                    oneTime = true;
                    bet++;
                }   
            }   
        }


        

        // wheel
        if(spinWheel == true && time <= time2)
        {   if(magicNumber == 1 && rotating == true)
            {
               wheel.setText("1 ");
               rotating = false;
               title.setText("Loser");
               magicNumber = 2;
            }
            if(magicNumber == 2 && rotating == true)
            {
               wheel.setText("2 ");
               title.setText("Winner");
               rotating = false;
               magicNumber = 3;
            }
            if(magicNumber == 3 && rotating == true)
            {
               wheel.setText("3 ");
               rotating = false;
               title.setText("Loser");
               magicNumber = 4;
            }
            if(magicNumber == 4 && rotating == true)
            {
               wheel.setText("4 ");
               title.setText("Winner");
               rotating = false;
               magicNumber = 5;
            }
            if(magicNumber == 5 && rotating == true)
            {
               wheel.setText("5 ");
               rotating = false;
               title.setText("Loser");
               magicNumber = 6;
            }
            if(magicNumber == 6 && rotating == true)
            {
               wheel.setText("6 ");
               title.setText("Winner");
               rotating = false;
               magicNumber = 7;
            }
            if(magicNumber == 7 && rotating == true)
            {
               wheel.setText("7 ");
               rotating = false;
               title.setText("Loser");
               magicNumber = 8;
            }
            if(magicNumber == 8 && rotating == true)
            {
               wheel.setText("8 ");
               title.setText("Winner");
               rotating = false;
               magicNumber = 9;
            }
            if(magicNumber == 9 && rotating == true)
            {
               wheel.setText("9 ");
               title.setText("Loser");
               rotating = false;
               magicNumber = 10;
            }
            if(magicNumber == 10 && rotating == true)
            {
               wheel.setText("10");
               title.setText("Winner");
               rotating = false;
               magicNumber = 11;
            }
            if(magicNumber == 11 && rotating == true)
            {
               wheel.setText("11");
               rotating = false;
               title.setText("Loser");
               magicNumber = 12;
            }
            if(magicNumber == 12 && rotating == true)
            {
               wheel.setText("12");
               title.setText("Winner");
               rotating = false;
               magicNumber = 13;
            }
            if(magicNumber == 13 && rotating == true)
            {
               wheel.setText("13");
               title.setText("Loser");
               rotating = false;
               magicNumber = 14;
            }
            if(magicNumber == 14 && rotating == true)
            {
               wheel.setText("14");
               title.setText("Winner");
               rotating = false;
               magicNumber = 15;
            }
            if(magicNumber == 15 && rotating == true)
            {
               wheel.setText("15");
               title.setText("Loser");
               rotating = false;
               magicNumber = 16;
            }
            if(magicNumber == 16 && rotating == true)
            {
               wheel.setText("16");
               title.setText("Winner");
               rotating = false;
               magicNumber = 17;
            }
            if(magicNumber == 17 && rotating == true)
            {
               wheel.setText("17");
               rotating = false;
               title.setText("Loser");
               magicNumber = 18;
            }
            if(magicNumber == 18 && rotating == true)
            {
               wheel.setText("18");
               title.setText("Winner");
               rotating = false;
               magicNumber = 19;
            }
            if(magicNumber == 19 && rotating == true)
            {
               wheel.setText("19");
               title.setText("Loser");
               rotating = false;
               magicNumber = 20;
            }
            if(magicNumber == 20 && rotating == true)
            {
               wheel.setText("20");
               title.setText("Winner");
               rotating = false;
               magicNumber = 21;
            }
            if(magicNumber == 21 && rotating == true)
            {
               wheel.setText("21");
               title.setText("Loser");
               rotating = false;
               magicNumber = 22;
            }
            if(magicNumber == 22 && rotating == true)
            {
               wheel.setText("22");
               title.setText("Winner");
               rotating = false;
               magicNumber = 23;
            }
            if(magicNumber == 23 && rotating == true)
            {
               wheel.setText("23");
               title.setText("Loser");
               rotating = false;
               magicNumber = 24;
            }
            if(magicNumber == 24 && rotating == true)
            {
               wheel.setText("24");
               title.setText("Winner");
               rotating = false;
               magicNumber = 25;
            }
            if(magicNumber == 25 && rotating == true)
            {
               wheel.setText("25");
               title.setText("Loser");
               rotating = false;
               magicNumber = 26;
            }
            if(magicNumber == 26 && rotating == true)
            {
               wheel.setText("26");
               title.setText("Winner");
               rotating = false;
               magicNumber = 27;
            }
            if(magicNumber == 27 && rotating == true)
            {
               wheel.setText("27");
               title.setText("Loser");
               rotating = false;
               magicNumber = 28;
            }
            if(magicNumber == 28 && rotating == true)
            {
               wheel.setText("28");
               title.setText("Winner");
               rotating = false;
               magicNumber = 29;
            }
            if(magicNumber == 29 && rotating == true)
            {
               wheel.setText("29");
               title.setText("Loser");
               rotating = false;
               magicNumber = 30;
            }
            if(magicNumber == 30 && rotating == true)
            {
               wheel.setText("30");
               title.setText("Winner");
               rotating = false;
               magicNumber = 31;
            }
            if(magicNumber == 31 && rotating == true)
            {
               wheel.setText("31");
               title.setText("Loser");
               rotating = false;
               magicNumber = 32;
            }
            if(magicNumber == 32 && rotating == true)
            {
               wheel.setText("32");
               rotating = false;
               title.setText("Winner");
               magicNumber = 33;
            }
            if(magicNumber == 33 && rotating == true)
            {
               wheel.setText("33");
               title.setText("Loser");
               rotating = false;
               magicNumber = 34;
            }
            if(magicNumber == 34 && rotating == true)
            {
               wheel.setText("34");
               title.setText("Winner");
               rotating = false;
               magicNumber = 35;
            }
            if(magicNumber == 35 && rotating == true)
            {
               wheel.setText("35");
               title.setText("Loser");
               rotating = false;
               magicNumber = 36;
            }
            if(magicNumber == 36 && rotating == true)
            {
               wheel.setText("36");
               title.setText("Winner");
               rotating = false;
               magicNumber = 1;
            }
            rotating = true;
            time++;
        }

        if(time == time2)
        {
            numberDeterminedBySpin = true;
        }

        //draws everything
        // first row of bets
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
        windowGame.draw(eleven);
        windowGame.draw(twelve);
        // second row of bets
        windowGame.draw(thirteen);
        windowGame.draw(fourteen);
        windowGame.draw(fifteen);
        windowGame.draw(sixteen);
        windowGame.draw(seventeen);
        windowGame.draw(eighteen);
        windowGame.draw(nineteen);
        windowGame.draw(twenty);
        windowGame.draw(twentyone);
        windowGame.draw(twentytwo);
        windowGame.draw(twentythree);
        windowGame.draw(twentyfour);
        // third row of bets
        windowGame.draw(twentyfive);
        windowGame.draw(twentysix);
        windowGame.draw(twentyseven);
        windowGame.draw(twentyeight);
        windowGame.draw(twentynine);
        windowGame.draw(thirty);
        windowGame.draw(thirtyone);
        windowGame.draw(thirtytwo);
        windowGame.draw(thirtythree);
        windowGame.draw(thirtyfour);
        windowGame.draw(thirtyfive);
        windowGame.draw(thirtysix);
        // fourth row of bets
        windowGame.draw(even);
        windowGame.draw(odd);
        windowGame.draw(red);
        windowGame.draw(black);
        windowGame.draw(first18);
        windowGame.draw(second18);

        // game wheel
        windowGame.draw(wheel);
        // player and dealer tags
        windowGame.draw(dealerLabel);
        windowGame.draw(playerLabel);

        // header/tittle
        windowGame.draw(title);
    
        // user buttons
        windowGame.draw(quit);
        windowGame.draw(newGame);
        windowGame.draw(spin);
        windowGame.draw(mainMenu);
        windowGame.draw(gameCredit);
        windowGame.display();

        
        if (numberDeterminedBySpin == true)
        {
            
            if(switch1 == true && magicNumber == 1)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch2 == true && magicNumber == 2)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch3 == true && magicNumber == 3)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch4 == true && magicNumber == 4)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch5 == true && magicNumber == 5)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch6 == true && magicNumber == 6)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch7 == true && magicNumber == 7)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch8 == true && magicNumber == 8)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch9 == true && magicNumber == 9)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch10 == true && magicNumber == 10)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch14 == true && magicNumber == 14)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
                
            }
            if(switch15 == true && magicNumber == 15)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch16 == true && magicNumber == 16)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch17 == true && magicNumber == 17)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch18 == true && magicNumber == 18)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch19 == true && magicNumber == 19)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch20 == true && magicNumber == 20)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch21 == true && magicNumber == 21)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch22 == true && magicNumber == 22)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch23 == true && magicNumber == 23)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch24 == true && magicNumber == 24)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch25 == true && magicNumber == 25)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch26 == true && magicNumber == 26)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch27 == true && magicNumber == 27)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch28 == true && magicNumber == 28)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch29 == true && magicNumber == 29)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch30 == true && magicNumber == 30)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch31 == true && magicNumber == 31)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch32 == true && magicNumber == 32)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch33 == true && magicNumber == 33)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch34 == true && magicNumber == 34)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch35 == true && magicNumber == 35)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch36 == true && magicNumber == 36)
            {
                multipier += 35;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switchEven == true && magicNumber % 2 == 0)
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switchOdd == true && magicNumber % 2 != 0)
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switchRed == true && magicNumber == 1 || magicNumber == 3 || magicNumber == 5 || magicNumber == 7 
               || magicNumber == 9 || magicNumber == 12 || magicNumber == 14 || magicNumber == 16 || magicNumber == 18 
               || magicNumber == 19 || magicNumber == 21 || magicNumber == 23 || magicNumber == 25 || magicNumber == 27 
               || magicNumber == 30 || magicNumber == 32 || magicNumber == 34 || magicNumber == 36)
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switchBlack == true && (magicNumber == 2 || magicNumber == 4 || magicNumber == 6 || magicNumber == 8 
               || magicNumber == 10 || magicNumber == 11 || magicNumber == 13 || magicNumber == 15 || magicNumber == 17 
               || magicNumber == 20 || magicNumber == 22 || magicNumber == 24 || magicNumber == 26 || magicNumber == 28 
               || magicNumber == 29 || magicNumber == 31 || magicNumber == 33 || magicNumber == 35))
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch1to18 == true && magicNumber <= 18)
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(switch19to36 == true && magicNumber >= 19)
            {
                multipier += 2;
                win = true;
                numberDeterminedBySpin = false;
            }
            if(!win)
            {
                lose = true;
            }
            
        } 
        
            
            if (win == true)
            { 
                winDisplay = true;
                if(oneTime == true)
                {
                    credit = credit + (10*multipier);
                    oneTime = false;
                }
            }
            if(lose == true)
            {
                loseDisplay = true;
                if(oneTime == true)
                {
                    credit = credit - (10*bet);
                    oneTime = false;
                }
            }

            // display winning pick
            if (winDisplay == true)
            {
                std::string s = std::to_string(magicNumber);
               
            
                title.setText("WINNER");


            }

            // display losing pick
            if (loseDisplay == true)
            {
                std::string s = std::to_string(magicNumber);
                
                title.setText(" LOSER ");
            }

            // display credit
            gameCredit.setText(std::to_string(credit));

            if (restart == true)
            {

                // reset betting screen buttons
                one.setColorTextNormal(sf::Color::White);
                two.setColorTextNormal(sf::Color::White);
                three.setColorTextNormal(sf::Color::White);
                four.setColorTextNormal(sf::Color::White);
                five.setColorTextNormal(sf::Color::White);
                six.setColorTextNormal(sf::Color::White);
                seven.setColorTextNormal(sf::Color::White);
                eight.setColorTextNormal(sf::Color::White);
                nine.setColorTextNormal(sf::Color::White);
                ten.setColorTextNormal(sf::Color::White);
                eleven.setColorTextNormal(sf::Color::White);
                twelve.setColorTextNormal(sf::Color::White);
                thirteen.setColorTextNormal(sf::Color::White);
                fourteen.setColorTextNormal(sf::Color::White);
                fifteen.setColorTextNormal(sf::Color::White);
                sixteen.setColorTextNormal(sf::Color::White);
                seventeen.setColorTextNormal(sf::Color::White);
                eighteen.setColorTextNormal(sf::Color::White);
                nineteen.setColorTextNormal(sf::Color::White);
                twenty.setColorTextNormal(sf::Color::White);
                twentyone.setColorTextNormal(sf::Color::White);
                twentytwo.setColorTextNormal(sf::Color::White);
                twentythree.setColorTextNormal(sf::Color::White);
                twentyfour.setColorTextNormal(sf::Color::White);
                twentyfive.setColorTextNormal(sf::Color::White);
                twentysix.setColorTextNormal(sf::Color::White);
                twentyseven.setColorTextNormal(sf::Color::White);
                twentyeight.setColorTextNormal(sf::Color::White);
                twentynine.setColorTextNormal(sf::Color::White);
                thirty.setColorTextNormal(sf::Color::White); 
                thirtyfour.setColorTextNormal(sf::Color::White);
                thirtyfive.setColorTextNormal(sf::Color::White);
                thirtysix.setColorTextNormal(sf::Color::White);
                even.setColorTextNormal(sf::Color::White);
                odd.setColorTextNormal(sf::Color::White);
                red.setColorTextNormal(sf::Color::White);
                black.setColorTextNormal(sf::Color::White);
                first18.setColorTextNormal(sf::Color::White);
                second18.setColorTextNormal(sf::Color::White);
                spin.setColorTextNormal(sf::Color::Green);
                newGame.setColorTextNormal(sf::Color::Black);

                // reset switches
                switch1 = false;
                switch2 = false;
                switch3 = false;
                switch4 = false;
                switch5 = false;
                switch6 = false;
                switch7 = false;
                switch8 = false;
                switch9 = false;
                switch10 = false;
                switch11 = false;
                switch12 = false;
                switch13 = false;
                switch14 = false;
                switch15 = false;
                switch16 = false;
                switch17 = false;
                switch18 = false;
                switch19 = false;
                switch20 = false;
                switch21 = false;
                switch22 = false;
                switch23 = false;
                switch24 = false;
                switch25 = false;
                switch26 = false;
                switch27 = false;
                switch28 = false;
                switch29 = false;
                switch30 = false;
                switch31 = false;
                switch32 = false;
                switch33 = false;
                switch34 = false;
                switch35 = false;
                switch36 = false;
                switchEven = false;
                switchOdd = false;
                switchRed = false;
                switchBlack = false; 
                multipier += 35;  
                selectNumber = false;
                winDisplay = false;
                loseDisplay = false;
                restart = false;
                spinWheel = false;   
                time = 0;
                time2 = (rand() % 36) + 2000;
                win = false;
                multipier = 0;
                lose = false;
                loseDisplay = false;
                winDisplay = false;
                lose = false;
                bet = 0;
                magicNumber = 1;  
                number = -1;
                oneTime = true;
                menu = false;  
                bet = 0;
                magicNumber = 1;  
                number = -1;
                numberDeterminedBySpin = false;
                
            }
        
    }
}
                