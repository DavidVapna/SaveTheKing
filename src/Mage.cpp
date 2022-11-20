#include "Mage.h"
#include "Fire.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Mage::handleCollision(GameObject& otMagebject)
{
    if (&otMagebject == this)
        return;
    otMagebject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Mage::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}

//-----------------------------------------------------------------------------
void Mage::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Mage::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Mage::handleCollision(Fire& fire)
{
    return;
}
//-----------------------------------------------------------------------------
void Mage::handleCollision(Portal& portal)
{
    return;
}
//-----------------------------------------------------------------------------