#include <cmath>
#include <math.h>
#include <node.hpp>

#define PI 3.14159265

Node::Node(const Vector &pos) : m_shape(pos)
{
    m_shape.set_position(pos);
}

Node::~Node()
{
    for (Node *child : m_childs)
        delete child;
}

float Node::get_dist(const Vector &pos) const
{
    return ((Vector)(pos - get_pos())).length();
}

inline float Node::get_angle(const Vector &pos) const
{
    Vector a = pos - get_pos();
    return std::atan2(a.y, a.x) * 180 / PI;
}

inline Vector Node::get_pos() const
{
    return m_shape.get_position();
}

inline float Node::get_radius() const
{
    return m_shape.get_radius();
}

inline Vector Node::get_direction(const Vector &point) const
{
    Vector dif = point - get_pos();
    return dif.normalize();
}

void Node::refactor_point(Vector &pos) const
{
    Vector dif = pos - get_pos();
    auto length = dif.length();
    Vector direction = dif.normalize();

    if (length < MIN_DIST)
        pos = get_pos() + direction * MIN_DIST;

    else if (length > MAX_DIST)
        pos = get_pos() + direction * MAX_DIST;
}

void Node::draw(sf::RenderWindow &window)
{
    m_shape.draw(window);
    for (Node *n : m_childs)
    {
        auto dist = get_dist(n->get_pos());
        auto angle = get_angle(n->get_pos());

        sf::RectangleShape l{sf::Vector2f{dist, 1}};
        l.setPosition(get_pos() + Vector(n->get_radius(), n->get_radius()));
        l.setRotation(angle);
        n->draw(window);
        window.draw(l);
    }
}

Node *Node::add_child(const Vector &pos)
{
    auto n = new Node(pos);
    m_childs.push_back(n);
    return n;
}

bool Node::is_close_enough(const Vector &pos) const
{
    Vector x = pos - get_pos();
    return x.length() <= MAX_DIST;
}

void Node::extend_queue(std::queue<Node *> &queue) const
{
    for (Node *child : m_childs)
        queue.push(child);
}
