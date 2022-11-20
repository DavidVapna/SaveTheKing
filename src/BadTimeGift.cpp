#include "BadTimeGift.h"

void BadTimeGift::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}


void BadTimeGift::handleCollision(King& theKing)
{
    m_isDisposed = true;
    theKing.handleCollision(*this);
}

void BadTimeGift::handleCollision(Mage& theMage)
{
    m_isDisposed = true;
    theMage.handleCollision(*this);
}

void BadTimeGift::handleCollision(Thief& theTief)
{
    m_isDisposed = true;
    theTief.handleCollision(*this);
}

void BadTimeGift::handleCollision(Warrior& theWarrior)
{
    m_isDisposed = true;
    theWarrior.handleCollision(*this);
}

void BadTimeGift::handleCollision(Dwarf& dwarf)
{
    dwarf.handleCollision(*this);
}