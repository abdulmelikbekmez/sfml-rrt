#ifndef H_MAIN
#define H_MAIN

#include <SFML/Graphics.hpp>
#include <memory>
#include <rrt.hpp>
#include <vector>

#define WIDTH 1366
#define HEIGHT 768

struct WindowOptions
{
    sf::Vector2u size;
    std::string title;
};

class Application
{
  private:
    sf::RenderWindow m_window{sf::VideoMode(WIDTH, HEIGHT), "RRT Algorithm Visualization"};
    std::vector<std::shared_ptr<sf::Shape>> m_shapes;
    RRT *m_rrt = nullptr;

    void m_handleEvent();
    void m_handleKeyPress();
    void m_draw();
    void m_update();

  public:
    void mainLoop();
    Application() = default;
    ~Application();
    Application(const WindowOptions &w);

    Application(const uint width, const uint height, const std::string title)
        : m_window{sf::VideoMode(width, height), title}
    {
    }
};
#endif // !H_MAIN
