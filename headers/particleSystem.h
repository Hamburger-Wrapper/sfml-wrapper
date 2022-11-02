#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>



class ParticleSystem : public sf::Drawable, public sf::Transformable
{
    public:
        ParticleSystem(unsigned int count);
        void setEmitter(sf::Vector2f position);
        void update(sf::Time elapsed);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    private:
        struct Particle
        {
            sf::Vector2f velocity;
            sf::Time lifetime;
        };
        void resetParticle(std::size_t index);
        std::vector<Particle> m_particles;
        sf::VertexArray m_vertices;
        sf::Time m_lifetime;
        sf::Vector2f m_emitter;
};

