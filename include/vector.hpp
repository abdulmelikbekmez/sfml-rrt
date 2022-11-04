#ifndef H_VECTOR
#define H_VECTOR

#include "SFML/Graphics.hpp"

class Vector : public sf::Vector2f
{
  public:
    Vector(float x, float y) : sf::Vector2f(x, y)
    {
    }
    Vector(const sf::Vector2f &vector) : sf::Vector2f(vector)
    {
    }
    float length() const;

    Vector normalize() const;
};

#endif
