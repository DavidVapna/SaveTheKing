#include "Wall.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Wall::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Wall::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Wall::handleCollision(Mage& theMage)
{
    theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Wall::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Wall::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Wall::handleCollision(Dwarf& theDwarf)
{
    theDwarf.handleCollision(*this);
}
//-----------------------------------------------------------------------------
