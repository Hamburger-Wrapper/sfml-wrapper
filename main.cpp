#include <SFML/Graphics.hpp>
#include <iostream>
#include <assets/components/animation.h>

int main()
{
    // Screen Size
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML works!");

    // Setting the Font
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/JellyBomb.ttf"))
    {
        // error...
    }

    // Animation Module
    sf::Texture texture;
/*  
    // We need to create a 3x9 Texture for this to work
    if (!texture.loadFromFile("./assets/images/animation.png"))
    {
        std::cout << "Error Loading Texture" << std::endl;
    }
*/
    Animation animation(&texture, sf::Vector2u(3, 9), 0.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        animation.Update(0, deltaTime, true);
        // player.setTextureRect(animation.uvRect); // This is for the assest for a 3x9 sprite sheet

        window.clear(sf::Color(150, 150, 150));  // Background Color
        window.draw(shape);
        window.display();
    }

    return 0;
}