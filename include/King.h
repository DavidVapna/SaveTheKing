#pragma once
//-----------------------------------------------------------------------------
#include "Hero.h"
//-----------------------------------------------------------------------------
class King : public Hero
{
public:
    using Hero::Hero;
    using Hero::handleCollision;

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(Throne& throne) override;
    bool isOnThrone();
private:
    bool m_onThrone = false;
};
//-----------------------------------------------------------------------------