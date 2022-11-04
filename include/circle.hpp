#ifndef H_CIRCLE
#define H_CIRCLE

#include <SFML/Graphics.hpp>
#include <vector.hpp>

class Circle : protected sf::CircleShape
{
  private:
    Vector m_pos;

  public:
    Circle(float x, float y);
    Circle(const Vector &pos);
    void set_position(const Vector &pos);
    Vector get_position() const;
    void draw(sf::RenderWindow &window) const;
};

#endif // !H_CIRCLE
