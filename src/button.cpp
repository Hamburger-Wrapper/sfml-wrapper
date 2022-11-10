
#include "../headers/button.h"

/// @brief Button - button constructor for the button class
/// @param s - text displayed on the button
/// @param position - the position of the button on the display screen
/// @param size - the size of the button 
/// @param color - the color of the button
Button::Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    if (!mTexture.loadFromFile("./assets/images/button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    //creates a sprite that look like a button
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
    if (!mFont.loadFromFile("./assets/fonts/college.ttf"))
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
/// @brief Constructor that will create a button and sets default conditions
Button::Button()
{
    if (!mTexture.loadFromFile("./assets/images/button.png"))
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
    if (!mFont.loadFromFile("./assets/fonts/college.ttf"))
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
/// @brief setColor - sets the color of the button
/// @param btnColor - color of the button
void Button::setColor(sf::Color btnColor)
{
  mButton.setColor(sf::Color(btnColor));  
}
/// @brief handles the mouse interaction with button 
/// @param e - type of event to be executed on the button
/// @param window - display screen of the button
bool Button::update(sf::Event& e, sf::RenderWindow& window)
{
    // on/off switch
    bool on = false;

     //get the position of the mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool mouseInButton = mousePosition.x >= mButton.getPosition().x - mButton.getGlobalBounds().width/2
    && mousePosition.x <= mButton.getPosition().x + mButton.getGlobalBounds().width/2
    && mousePosition.y >= mButton.getPosition().y - mButton.getGlobalBounds().height/2
    && mousePosition.y <= mButton.getPosition().y + mButton.getGlobalBounds().height/2;
    //handles the event from the mouse being clicked      
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
                        on = true;
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
            return on;
}
/// @brief draw - draws the button in the correct state
/// @param target - the object to be drawn
/// @param states - state of the button
void Button::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    // draw the button
    target.draw(mButton, states);
    target.draw(mText, states);
}
/// @brief setPosition() - puts the buttion at a unique position on the screen
/// @param position - the pixel position on the display screen of the button
void Button::setPosition(sf::Vector2f position)
{
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    //set position
    mPosition={position};
    mButton.setPosition(position.x,position.y);
    //set position at the midle of the button    //set position at the midle of the button
    mText.setPosition(position.x, position.y-fontSize/4);
}
/// @brief setSize - increase or decrease the size of the button by magnification
/// @param size - the magnification of the button
void Button::setSize(sf::Vector2f  size)
{
    //get size of image
    sf::Vector2u imageSize=mTexture.getSize();
    mButton.setScale(size.x/imageSize.x, size.y/imageSize.y);
    //Make label
    if (!mFont.loadFromFile("./assets/fonts/college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    //mText.setFont(mFont);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().height/2;
    mText.setCharacterSize(fontSize);
    //set label
    //mText.setString(s);
    //set origing to the middle
    mText.setOrigin(mText.getGlobalBounds().width/2, mText.getGlobalBounds().height/2);
    //set position at the middle of the button
    mText.setPosition(mPosition.x, mPosition.y-fontSize/4);  
}
/// @brief setText - will put text on the button
/// @param s - text that will be placed on the button
void Button::setText(std::string s)
{
    mText.setString(s);
}