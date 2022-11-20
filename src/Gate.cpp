//-----------------------------------------------------------------------------
#include "Gate.h"
#include "Thief.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Gate::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Gate::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Gate::handleCollision(Mage& theMage)
{
    theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Gate::handleCollision(Thief& theThief)
{
    if (theThief.haveKey())
    {
        m_isDisposed = true;
        theThief.handleCollision(*this);
    }
}
//-----------------------------------------------------------------------------
void Gate::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------