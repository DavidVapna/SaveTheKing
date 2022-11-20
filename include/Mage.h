#pragma once
//-----------------------------------------------------------------------------
#include "Hero.h"
//-----------------------------------------------------------------------------
class Mage : public Hero
{
public:
    using Hero::Hero;
    using Hero::handleCollision;

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(Fire& fire) override;
    virtual void handleCollision(Portal& portal) override;


private:

};
//-----------------------------------------------------------------------------