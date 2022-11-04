#ifndef H_NODE
#define H_NODE

#include "SFML/System/Vector2.hpp"
#include "circle.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>

class Node
{
  private:
    Circle m_shape;
    std::vector<Node *> m_childs;
    const float MAX_DIST = 10.f;

  public:
    Node(const Vector &pos);
    ~Node();
    float get_dist(const Vector &pos) const;
    float get_angle(const Vector &pos) const;
    Vector get_pos() const;
    Vector get_direction(const Vector &point) const;
    void refactor_point(Vector &pos) const;
    void draw(sf::RenderWindow &window);
    Node *add_child(const Vector &pos);
    bool is_close_enough(const Vector &pos) const;
    void extend_queue(std::queue<Node *> &queue) const;
};

#endif // !H_NODE
