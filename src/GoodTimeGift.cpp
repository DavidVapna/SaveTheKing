#include "GoodTimeGift.h"

void GoodTimeGift::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
void GoodTimeGift::handleCollision(King& theKing)
{
    m_isDisposed = true;
    theKing.handleCollision(*this);
}

void GoodTimeGift::handleCollision(Mage& theMage)
{
    m_isDisposed = true;
    theMage.handleCollision(*this);
}

void GoodTimeGift::handleCollision(Thief& theTief)
{
    m_isDisposed = true;
    theTief.handleCollision(*this);
}

void GoodTimeGift::handleCollision(Warrior& theWarrior)
{
    m_isDisposed = true;
    theWarrior.handleCollision(*this);
}

void GoodTimeGift::handleCollision(Dwarf& dwarf)
{
    dwarf.handleCollision(*this);
}