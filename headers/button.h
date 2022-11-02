#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>

enum class ButtonState
{
    Idle,
    Hover,
    Active
};

class Button
{
private:
    short unsigned buttonState;
    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height,
           sf::Font *font, std::string text,
           sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    // Accessors
    const bool isPressed() const;

    // Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget &target);
};

#endif // BUTTON_H
