#pragma once
//-----------------------------------------------------------------------------
#include "StaticObject.h"
//-----------------------------------------------------------------------------
class Portal : public StaticObject
{
public:
    Portal(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject,
            const sf::Vector2u& otherLoc);
    using StaticObject::handleCollision;


    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Warrior& theWarrior) override;

    sf::Vector2f getOtherPort();

private:
    sf::Vector2f m_otherPort;
};
//-----------------------------------------------------------------------------