#ifndef H_RRT
#define H_RRT

#include "vector.hpp"
#include <node.hpp>

class RRT
{
  private:
    Node *m_head;
    Vector m_finish;
    bool m_finded{false};

    Vector m_generate_random_point() const;
    Node *m_get_closest_node(const Vector &point) const;
    bool m_create_new_node();

  public:
    RRT(const Vector &start, const Vector &finish);
    ~RRT();
    void draw(sf::RenderWindow &window) const;
    bool update();
    bool is_finded() const;
};

#endif // !H_RRT
