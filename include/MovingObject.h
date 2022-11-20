#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
//-----------------------------------------------------------------------------
class MovingObject : public GameObject
{
public:
    using GameObject::GameObject;

    enum class Direction
    {
        Stay, Up, Down, Left, Right
    };
    virtual void move(sf::Time deltaTime);
    void setDirection(sf::Keyboard::Key key);
    Direction getDirection();

    bool limitBounds();
    void mirorDir();
    void stepBack(const sf::Vector2f& location);
    
    
    


protected:
    Direction m_dir = Direction::Stay;
    sf::Clock m_clock;
    float m_speed;

    bool m_usedPortal = false;
    sf::Time m_portalCD;
private:

};
//-----------------------------------------------------------------------------