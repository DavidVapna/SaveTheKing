//-----------------------------------------------------------------------------
#include "Fire.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Fire::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Fire::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Fire::handleCollision(Mage& theMage)
{
    if (!m_isDisposed)
        m_isDisposed = true;
}
//-----------------------------------------------------------------------------
void Fire::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Fire::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Fire::handleCollision(Dwarf& theDwarf)
{
    theDwarf.handleCollision(*this);
}
//-----------------------------------------------------------------------------