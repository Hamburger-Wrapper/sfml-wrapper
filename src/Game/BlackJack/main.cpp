#include "card.h" 
#include "deck.h" 
#include "player.h"


using namespace std;
int blackJack();

int main()
{
    int test = blackJack();
    cout << "test is: " << test;
    return 0;
}

int blackJack()
{
    // Create a vector of Player objects/instances called players with size equal to number of players
    vector<Player> players(2);

    Deck myDeck;

    bool repeat = true;
    //while (repeat)
    //{
        //Dealing two cards to each player
        for (int i = 0; i < 2; i++)
        {
            players[i].newHand(myDeck);
        }

        vector <int> playerScore(2,0);

        // Loop through each player
        char reply;
        while(1)
        {
            players[0].print();
            players[1].print();
            int score = 0;
            cout << "Hit or Stand (enter H or S)?";
            cin >> reply;
            if (reply == 'S' || reply == 's')
            {
                int botScore = players[1].count();
                score = players[0].count();
                if (score > botScore && botScore < 21)
                {
                    players[1].hitCard(myDeck);
                    botScore = players[1].count();
                }
                if (botScore > 21) //extra gaurd
                {
                    botScore = 0;
                    //Bot busted
                }
                if (score > 21 || score < botScore)
                {
                    //bust
                    return 0; //lose
                }
                else if (score ==21 || score > botScore)
                {
                    playerScore[0] = score;
                    //Blackjack
                    return 1; //win
                }
                else if (score == botScore)
                {
                    //tie
                    return 2;
                }
            }
            else if (reply == 'H' || reply == 'h')
            {
                players[0].hitCard(myDeck);
                score = players[0].count();
                if (score > 21)
                {
                    //bust, went over 21
                    return 0; //lose
                }
                else if (score ==21)
                {
                    playerScore[0] = score;
                    //Blackjack
                    return 1; //win
                }
            }
        } //end while
    //}

    return 0;
}
