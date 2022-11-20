#pragma once
//-----------------------------------------------------------------------------
#include "Hero.h"
//-----------------------------------------------------------------------------
class Warrior : public Hero
{
public:
    using Hero::Hero;
    using Hero::handleCollision;
   
    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Orc& orc) override;

    bool didSlay() const;
    sf::Vector2f newKeyLoc();
    sf::Vector2f newKeySize();

private:
    bool m_slayed = false;
    sf::Vector2f m_dropKey;
    sf::Vector2f m_keySize;
};
//-----------------------------------------------------------------------------