    #include "player.h"

    void Player::hitCard(Deck &deck)
    {
        card newCard = deck.dealCard();
        mHand.push_back(newCard);
    }
    void Player::reset()
    {
        mHand.clear();
    }
    void Player::newHand(Deck &deck)
    {
        reset();
        for (int i = 0; i< INITIAL_NUM_CARDS; i++)
        {
            hitCard(deck);
        }
    }
    int Player::count() const
    {
        int size = mHand.size();
        int count = 0;
        for (int i = 0; i<size; i++)
        {
            card myCard = mHand[i];
            int points = myCard.getValue();
            points = points + 1;
            while (points > 13)
            {
                if(points > 13)
                {
                    points = points - 13;
                }
            }
            if (points ==1)
                {points=11;}
            else if (points>10)
                {points = 10;}

            count+=points;
        }
        return count;
    }
    //no need to print the name of the player, just the cards in the hand
    //modify to return values
    void Player::print() const
    {
        for (int i = 0; i < static_cast<int>(mHand.size()); i++)
        {
            card myCard = mHand[i];
            cout << myCard.getValue() << " ";
            myCard.print();
            cout << endl;
        }
    }
