#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "card.h"

class Deck
{
public:
    Deck();
    void reset();
    void printUndealtDeck();
    void printDealtDeck();
    bool isEmpty();
    card dealCard();
private:
    vector<card> mUndealt;
    vector<card> mDealt;
};

#endif // DECK_H_INCLUDED
