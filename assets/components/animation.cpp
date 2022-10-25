#include "animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);   // We make this a float since it's a unsigned int
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}