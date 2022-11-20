#pragma once
//-----------------------------------------------------------------------------
#include "StaticObject.h"
//-----------------------------------------------------------------------------
class Orc : public StaticObject
{
public:
    using StaticObject::StaticObject;
    using StaticObject::handleCollision;

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(Dwarf& theDwarf) override;
private:
};
//-----------------------------------------------------------------------------