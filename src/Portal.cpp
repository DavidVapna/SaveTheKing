#include "Portal.h"
//-----------------------------------------------------------------------------
sf::Time m_coolDown = sf::Time();
//-----------------------------------------------------------------------------
Portal::Portal(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject,
               const sf::Vector2u& otherLoc)
    : StaticObject(loc, size, theObject)
{
    m_otherPort.x = otherLoc.x * m_objectSize.x + (m_objectSize.x/2);
    m_otherPort.y = otherLoc.y * m_objectSize.y + (m_objectSize.y/2);
}
//-----------------------------------------------------------------------------
void Portal::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Portal::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Portal::handleCollision(Mage& theMage)
{
    return;
}
//-----------------------------------------------------------------------------
void Portal::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Portal::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
sf::Vector2f Portal::getOtherPort()
{
    return m_otherPort;
}
//-----------------------------------------------------------------------------