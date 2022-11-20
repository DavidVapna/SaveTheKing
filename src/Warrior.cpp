#include "Warrior.h"
#include "Orc.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Warrior::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Warrior::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Warrior::handleCollision(Mage& theMage)
{
    theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Warrior::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Warrior::handleCollision(Orc& orc)
{
    //playSound();
    //createKey();
    m_slayed = true;
    m_dropKey = orc.getLocation();
    m_keySize = orc.getObjectSize();
    return;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
bool Warrior::didSlay() const
{
    return m_slayed;
}
//-----------------------------------------------------------------------------
sf::Vector2f Warrior::newKeyLoc()
{
    m_slayed = false;
    return m_dropKey;
}
sf::Vector2f Warrior::newKeySize()
{
    return m_keySize;
}
//-----------------------------------------------------------------------------