#ifndef H_CIRCLE
#define H_CIRCLE

#include <SFML/Graphics.hpp>
#include <vector.hpp>

class Circle : protected sf::CircleShape
{
  public:
    Circle(float x, float y);
    Circle(const Vector &pos);
    void set_position(const Vector &pos);
    Vector get_position() const;
    float get_radius() const;
    void draw(sf::RenderWindow &window) const;

  private:
    Vector m_pos;
};

#endif // !H_CIRCLE
