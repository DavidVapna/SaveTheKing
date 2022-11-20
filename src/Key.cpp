//-----------------------------------------------------------------------------
#include "Key.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Key::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Key::handleCollision(Thief& theThief)
{
    if(!theThief.haveKey())
        m_isDisposed = true;
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------