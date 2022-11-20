    #include "player.h"

    void Player::setName(string name)
    {
        mName=name;
    }
    string Player::getName() const
    {
        return mName;
    }
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
            int points = mHand[i].getValue();
            if (points ==1)
                {points=11;}
            else if (points>10)
                {points = 10;}

            count+=points;
        }
        //return count;
    }
    void Player::print() const
    {
        cout << getName() << endl;
        for (int i = 0; i < static_cast<int>(mHand.size()); i++)
        {
            cout << mHand[i].getValue() << " ";
            //mHand[i].print();
        }
    }
