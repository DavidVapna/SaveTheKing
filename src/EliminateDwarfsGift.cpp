#include "EliminateDwarfsGift.h"

void EliminateDwarfsGift::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}

void EliminateDwarfsGift::handleCollision(King& theKing)
{
    m_isDisposed = true;
    theKing.handleCollision(*this);
}

void EliminateDwarfsGift::handleCollision(Mage& theMage)
{
    m_isDisposed = true;
    theMage.handleCollision(*this);
}

void EliminateDwarfsGift::handleCollision(Thief& theTief)
{
    m_isDisposed = true;
    theTief.handleCollision(*this);
}

void EliminateDwarfsGift::handleCollision(Warrior& theWarrior)
{
    m_isDisposed = true;
    theWarrior.handleCollision(*this);
}

void EliminateDwarfsGift::handleCollision(Dwarf& dwarf)
{
    dwarf.handleCollision(*this);
}