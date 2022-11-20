#pragma once
//-----------------------------------------------------------------------------
#include "Hero.h"
//-----------------------------------------------------------------------------
class Thief : public Hero
{
public:
    using Hero::Hero;
    using Hero::handleCollision;


    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(Gate& gate) override;
    virtual void handleCollision(Key& key) override;


    bool haveKey();

private:
    bool m_key = false;
};
//-----------------------------------------------------------------------------