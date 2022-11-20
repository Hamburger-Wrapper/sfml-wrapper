#include "card.h" 
#include "deck.h" 
#include "player.h"
/*
at this point I'm just too confused on this file structure, I should have gotten help but it's too last minute for that
I'll just take the hit, the rest of the files work though just couldn't get main to work.
*/
using namespace std;
int main()
{
    const int MAX_PLAYERS = 6;
    int numPlayers = 0;
    while (1)
    {
        cout << "How many players? ";
        cin >> numPlayers;
        if (numPlayers >= 1 && numPlayers <= MAX_PLAYERS)
        {
            break;
        }
        cout << "Invalid! Valid values are 1 to " << MAX_PLAYERS << ". ";
    }

    // Create a vector of Player objects/instances called players with size equal to number of players
    vector<Player> players(numPlayers);
    // NOTE: This means index 0 is player 1, index 1 is player 2, so on...
    cin.ignore();
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Enter the player name: ";
        string name;
        getline(cin, name);
        players[i].setName(name);
    }

    Deck myDeck;

    char repeat = 'Y';
    while (repeat == 'Y' || repeat == 'y')
    {
        cout << "\n\nDealing two cards to each player\n";
        // Loop through each player
        for (int i = 0; i < numPlayers; i++)
        {
            players[i].newHand(myDeck);
        }

        vector <int> playerScore(numPlayers,0);

        // Variable to keep track of the highest score, set initially to 0
        int highestScore = 0;

        // Set to player 1 (what index value is player 1?)
        // Loop through each player
        int i = 0;
        //for( in i = 0; i<numPlayers; i++)
        char reply;
        while(1)
        {
            players[i].print();
            int score = 0;
            if (score > 21)
            {
                cout << "It's a bust! Better luck next time =(\n";
                break;
            }
            else if (score ==21)
            {
                playerScore[i] = score;
                highestScore = 21;
                cout << "You got a Blackjack!!!\n";
            }
            else
            {
                do
                {
                    cout << "Hit or Stand (enter H or S)?";
                    cin >> reply;
                    if (reply != 'H'||reply != 'S')
                    {
                        break; //for some reason, the do while loop does not break out, so I had to force it to
                    }
                } while (reply != 'H'||reply != 'S');
            }
            if (reply == 'S')
            {
                playerScore[i] = score;
                if(score > highestScore)
                {
                    highestScore=score;
                }
                else
                {
                    players[i].hitCard(myDeck);
                    for (int i = 0; i < numPlayers; i++)
                    {
                        if (playerScore[i]==highestScore)
                        {
                            cout <<players[i].getName()<<endl;
                        }
                    }
                }
            }
        } //end while
        i++;
        if (i == numPlayers)
        {
            i = 0;
        }

        if (highestScore == 0)
        {
            cout << "No winner!\n";
        }
        else
        {
            cout << "\nWinner(s) of the BlackJack Game:\n";
            // Loop through the playerScores vector
                // if player's score is equal to the highest score
                    // Print out the player's name
        }

        // Reset the deck for a new game

        cout << "Play again? [Y / N]: ";
        repeat = cin.get();
    }

    return 0;
}
