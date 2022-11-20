#include "Thief.h"
#include "Key.h"
#include "Gate.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Thief::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Thief::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Thief::handleCollision(Mage& theMage)
{
    theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Thief::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Thief::handleCollision(Gate& gate)
{
    if (m_key)
        m_key = false;
    else
        stepBack(gate.getLocation());
}
//-----------------------------------------------------------------------------
void Thief::handleCollision(Key& key)
{
    if (!m_key)
        m_key = true;
}
//-----------------------------------------------------------------------------
bool Thief::haveKey()
{
    return m_key;
}
//-----------------------------------------------------------------------------