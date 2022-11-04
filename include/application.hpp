#ifndef H_MAIN
#define H_MAIN

#include <SFML/Graphics.hpp>
#include <rrt.hpp>
#include <vector>

struct WindowOptions
{
    sf::Vector2u size;
    std::string title;
};

class Application
{
  private:
    sf::RenderWindow m_window{sf::VideoMode(800, 600), "RRT Algorithm Visualization"};
    std::vector<sf::Shape *> m_shapes;
    RRT *m_rrt = nullptr;

    void m_handleEvent();
    void m_handleKeyPress();
    void m_draw();
    void m_update();

  public:
    void mainLoop();
    Application() = default;
    ~Application();
    Application(const WindowOptions &w) : m_window{sf::VideoMode(w.size.x, w.size.y), w.title}
    {
    }

    Application(const uint width, const uint height, const std::string title)
        : m_window{sf::VideoMode(width, height), title}
    {
    }
};
#endif // !H_MAIN
