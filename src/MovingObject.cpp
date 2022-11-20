//-----------------------------------------------------------------------------
#include "MovingObject.h"
//-----------------------------------------------------------------------------
namespace
{
    sf::Vector2f dirToVector(MovingObject::Direction dir)
    {
        switch (dir)
        {
        case MovingObject::Direction::Right:
            return { 1, 0 };
        case MovingObject::Direction::Left:
            return { -1, 0 };
        case MovingObject::Direction::Up:
            return { 0, -1 };
        case MovingObject::Direction::Down:
            return { 0, 1 };
        case MovingObject::Direction::Stay:
            return { 0, 0 };
        }
        return { 0, 0 }; // just to silence the warning about no return
        // would be better to throw an exception but we haven't learned about it yet
    }
}
//-----------------------------------------------------------------------------
void MovingObject::move(sf::Time deltaTime)
{
    if (m_portalCD.asSeconds() > 3)
        m_portalCD = sf::Time();
    else
        m_portalCD += deltaTime;
    
    sf::Vector2f nextStep = (dirToVector(m_dir) * m_speed * deltaTime.asSeconds());
    m_location += nextStep;
    limitBounds();
    m_sprite.setPosition(m_location);
}
//-----------------------------------------------------------------------------
void MovingObject::setDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Right:
        m_dir = Direction::Right;
        break;
    case sf::Keyboard::Left:
        m_dir = Direction::Left;
        break;
    case sf::Keyboard::Up:
        m_dir = Direction::Up;
        break;
    case sf::Keyboard::Down:
        m_dir = Direction::Down;
        break;
    case sf::Keyboard::Space:
        m_dir = Direction::Stay;
        break;
    }
}
//-----------------------------------------------------------------------------
MovingObject::Direction MovingObject::getDirection()
{
    return m_dir;
}
//-----------------------------------------------------------------------------
bool MovingObject::limitBounds()
{
    auto thisBound = m_sprite.getGlobalBounds();

    if (m_location.x < (thisBound.width / 2))
    {
        m_location.x = thisBound.width / 2;
        return false;
    }
    if (m_location.y < STAT_BAR + (thisBound.height / 2))
    {
        m_location.y = STAT_BAR + (thisBound.height / 2);
        return false;
    }
    if (m_location.x > (GAME_WIDTH - (thisBound.width / 2)))
    {
        m_location.x = GAME_WIDTH - (thisBound.width / 2);
        return false;
    }
    if (m_location.y > (GAME_HEIGHT + STAT_BAR - (thisBound.height / 2)))
    {
        m_location.y = GAME_HEIGHT + STAT_BAR - (thisBound.height / 2);
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
void MovingObject::mirorDir()
{
    if (m_dir == Direction::Down)
    {
        m_dir = Direction::Up;
    }
    if (m_dir == Direction::Up)
    {
        m_dir = Direction::Down;
    }
    if (m_dir == Direction::Left)
    {
        m_dir = Direction::Right;
    }
    if (m_dir == Direction::Right)
    {
        m_dir = Direction::Left;
    }
}
//-----------------------------------------------------------------------------
void MovingObject::stepBack(const sf::Vector2f& location)
{
    sf::Vector2f halfDistanceObj;
    halfDistanceObj.x = (m_objectSize.x * MOVING_DESCALE) * 0.5;
    halfDistanceObj.y = (m_objectSize.y * MOVING_DESCALE) * 0.5;

    sf::Vector2f halfDistanceMoving;
    halfDistanceMoving.x = m_objectSize.x * 0.6;
    halfDistanceMoving.y = m_objectSize.y * 0.6;

    float newY, newX;
    switch (m_dir)
    {
    case Direction::Up:
    {
        newY = location.y + halfDistanceObj.y + halfDistanceMoving.y;
        m_location.y = newY + 2;
    }
        break;
    case Direction::Down:
    {
        newY = location.y - halfDistanceObj.y - halfDistanceMoving.y;
        m_location.y = newY - 2;
    }
        break;
    case Direction::Left:
    {
        newX = location.x + halfDistanceObj.x + halfDistanceMoving.y;
        m_location.x = newX + 2;
    }
        break;
    case Direction::Right:
    {
        newX = location.x - halfDistanceObj.x - halfDistanceMoving.y;
        m_location.x = newX - 2;
    }
        break;
    }
    m_sprite.setPosition(m_location);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

