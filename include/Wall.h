#pragma once
//-----------------------------------------------------------------------------
#include "StaticObject.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
class Wall : public StaticObject
{
public:
    using StaticObject::StaticObject;
    using StaticObject::handleCollision;

    void handleCollision(GameObject& currObject) override;
    void handleCollision(King& theKing) override;
    void handleCollision(Mage& theMage) override;
    void handleCollision(Thief& theThief) override;
    void handleCollision(Warrior& theWarrior) override;
    void handleCollision(Dwarf& theDwarf) override;

private:

};
//-----------------------------------------------------------------------------