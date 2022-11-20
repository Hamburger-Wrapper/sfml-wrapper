#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;


const int NUM_RANKS = 13;
const int NUM_SUITS = 4;
const string RANKS[] = { "Ace", "Two", "Three", "Four", "Five",
                        "Six", "Seven", "Eight", "Nine", "Ten",
                        "Jack", "Queen", "King" };
const string SUITS[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
class card
{
public:
    void setValue(int value);
    void SetValue(int suit, int rank);
    int getValue();
    void print();
private:
    int mCardValue;
    bool checkRange(int val, int min, int max);
};

#endif // CARD_H_INCLUDED
