#include "SFML/Graphics.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "rrt.hpp"
#include <application.hpp>
#include <iostream>

void Application::mainLoop()
{

    while (m_window.isOpen())
    {
        m_handleEvent();

        m_window.clear();
        m_update();
        m_draw();
        m_window.display();
    }
}

Application::~Application()
{
    for (sf::Shape *c : m_shapes)
        delete c;
}

void Application::m_draw()
{
    for (sf::Shape *c : m_shapes)
        m_window.draw(*c);

    if (m_rrt != nullptr)
        m_rrt->draw(m_window);
}

void Application::m_handleEvent()
{
    sf::Event ev;
    while (m_window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            m_window.close();

        if (ev.type == sf::Event::KeyPressed)
            m_handleKeyPress();

        if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left && m_rrt == nullptr)
        {
            float rad = 10.;
            auto shape = new sf::CircleShape(rad);
            shape->setPosition(ev.mouseButton.x - rad, ev.mouseButton.y - rad);

            m_shapes.push_back(shape);
            if (m_shapes.size() == 2)
            {
                auto a = m_shapes[0]->getPosition();
                auto b = m_shapes[1]->getPosition();
                m_rrt = new RRT(a, b);
            }
        }
    }
}

void Application::m_handleKeyPress()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && m_rrt != nullptr)
    {
        delete m_rrt;
        m_rrt = nullptr;
        for (auto x : m_shapes)
            delete x;

        m_shapes.clear();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window.close();
}

void Application::m_update()
{
    if (m_rrt != nullptr)
        m_rrt->update();
}
