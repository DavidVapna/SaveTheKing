//-----------------------------------------------------------------------------
#include "GameObject.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
GameObject::GameObject(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject)
    : m_location(loc), m_objectSize(size),
      m_sprite(DataLoader::instance().getGameTexture(theObject))
{
    sf::Vector2f scaleTo;
    scaleTo.x = m_objectSize.x / m_sprite.getTexture()->getSize().x;
    scaleTo.y = m_objectSize.y / m_sprite.getTexture()->getSize().y;

    sf::Vector2f origin;
    origin.x = (float)m_sprite.getTexture()->getSize().x * 0.5;
    origin.y = (float)m_sprite.getTexture()->getSize().y * 0.5;
    m_sprite.setOrigin(origin);
    m_sprite.scale(scaleTo);
    m_sprite.setPosition(m_location);
}
//-----------------------------------------------------------------------------
bool GameObject::checkCollision(const sf::FloatRect& floatRect) const
{
    return m_sprite.getGlobalBounds().intersects(floatRect);
}
//-----------------------------------------------------------------------------
sf::FloatRect GameObject::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}
//-----------------------------------------------------------------------------
bool GameObject::isDisposed()
{
    return m_isDisposed;
}
//-----------------------------------------------------------------------------
void GameObject::setDisposed(bool set)
{
    m_isDisposed = set;
}
//-----------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
//-----------------------------------------------------------------------------
sf::Vector2f GameObject::getLocation() const
{
    return m_location;
}
//-----------------------------------------------------------------------------
sf::Vector2f GameObject::getObjectSize()
{
    return m_objectSize;
}
//-----------------------------------------------------------------------------

