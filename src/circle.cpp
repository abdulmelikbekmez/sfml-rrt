#include <circle.hpp>

Circle::Circle(float x, float y) : sf::CircleShape(), m_pos(x, y)
{
    setFillColor(sf::Color(255, 0, 0));
    setPosition(m_pos);
    setRadius(3);
}

Circle::Circle(const Vector &pos) : sf::CircleShape(), m_pos(pos)
{
    setFillColor(sf::Color(255, 0, 0));
    setPosition(m_pos);
    setRadius(3);
}

void Circle::set_position(const Vector &pos)
{
    m_pos = pos;
    setPosition(m_pos);
}

Vector Circle::get_position() const
{
    return m_pos;
}

void Circle::draw(sf::RenderWindow &window) const
{
    window.draw(*this);
}
