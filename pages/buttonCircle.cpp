#include "buttonCircle.h"

CircleButton::CircleButton(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("buffer.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //creat sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origing to the center of the image (maks rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    mPosition={position};
    mButton.setPosition(position.x,position.y);
    //choose color
    mButton.setColor(sf::Color(color));
    //set size as a ration of original size
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make lable
    
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }

    

    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set lable
    mText.setString(s);
    //set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the midle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}



CircleButton::CircleButton()
{
    if (!mTexture.loadFromFile("yellowButton.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //creat sprite that look like a button
    mButton.setTexture(mTexture);
    
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    //change origing to the center of the image (maks rotation easy)
    mButton.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    mPosition={100,35};  // position
    mButton.setPosition(100, 35); // position.x, position.y
    //choose color
    mButton.setColor(sf::Color(0, 0, 255));
    //set size as a ration of original size
    mButton.setScale(.3, .3);
    //Make lable
    
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }

    

    mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set lable
    mText.setString("Default");
    //set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the midle of the button
    mText.setPosition(100, 35-fontSize/4);      // positio.x, position.y
    //choose colors
    mTextNormal = sf::Color::Green;
    mTextHover = sf::Color::Red;
    mText.setFillColor(mTextNormal);
}

void CircleButton::setColor(sf::Color btnColor)
{
  mButton.setColor(sf::Color(btnColor));  
}

void CircleButton::update(sf::Event& e, sf::RenderWindow& window)
{
     //get position of the mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool mouseInButton = mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
    && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
    && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
    && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
            
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            mText.setFillColor(mTextHover);
        }
        else
        {
            mText.setFillColor(mTextNormal);
        }
            }
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if(e.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        mButton.setRotation(180);
                    }
                    else
                    {
                        mButton.setRotation(0);
                    }
                }
            }
            if (e.type == sf::Event::MouseButtonReleased)
            {
                if (e.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        mText.setFillColor(mTextHover);
                        mButton.setRotation(0);
                    }
                    else
                    {
                        mText.setFillColor(mTextNormal);
                        mButton.setRotation(0);
                    }
                }
            }
}
void CircleButton::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    
    target.draw(mButton, states);
    target.draw(mText, states);
}

void CircleButton::setPosition(sf::Vector2f position)
{
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    //set position
    mPosition={position};
    mButton.setPosition(position.x,position.y);

    //set position at the midle of the button    //set position at the midle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
}

void CircleButton::setSize(sf::Vector2f  size)
{
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();

    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make lable
    
    if (!mFont.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }

    

    //mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set lable
    //mText.setString(s);
    //set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the midle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);  
}

void CircleButton::setText(std::string s)
{
    mText.setString(s);
}

void CircleButton::setFontSize(unsigned int fontSize)
{
    mText.setCharacterSize(fontSize);
}