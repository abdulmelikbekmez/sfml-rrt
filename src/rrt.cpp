#include "application.hpp"
#include <rrt.hpp>
RRT::RRT(const Vector &start, const Vector &finish) : m_head(new Node(start)), m_finish(finish)
{
    srand((unsigned)time(0));
}

RRT::~RRT()
{
    delete m_head;
}

Vector RRT::m_generate_random_point() const
{
    auto x = rand() % WIDTH;
    auto y = rand() % HEIGHT;
    return Vector(x, y);
}

Node *RRT::m_get_closest_node(const Vector &point) const
{
    std::queue<Node *> que;
    que.push(m_head);
    Node *closest = m_head;
    float dist_min = 999999.;

    while (!que.empty())
    {
        auto tmp = que.front();
        float dist = tmp->get_dist(point);
        if (dist < dist_min)
        {
            closest = tmp;
            dist_min = dist;
        }
        tmp->extend_queue(que);
        que.pop();
    }

    return closest;
}

bool RRT::m_create_new_node()
{
    auto point = m_generate_random_point();
    auto closest_node = m_get_closest_node(point);
    closest_node->refactor_point(point);
    Node *new_node = closest_node->add_child(point);
    return new_node->is_close_enough(m_finish);
}

bool RRT::update()
{
    if (m_finded)
        return true;

    if (m_create_new_node())
    {
        m_finded = true;
        return true;
    }
    return false;
}

void RRT::draw(sf::RenderWindow &window) const
{
    m_head->draw(window);
}

bool RRT::is_finded() const
{
    return m_finded;
}
