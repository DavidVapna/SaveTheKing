//-----------------------------------------------------------------------------
#include "Orc.h"
#include "Warrior.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Orc::handleCollision(GameObject& currObject)
{
	if (&currObject == this)
		return;
	currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Orc::handleCollision(King& theKing)
{
	theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Orc::handleCollision(Mage& theMage)
{
	theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Orc::handleCollision(Thief& theThief)
{
	theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Orc::handleCollision(Warrior& theWarrior)
{
	m_isDisposed = true;
	theWarrior.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Orc::handleCollision(Dwarf& theDwarf)
{
	theDwarf.handleCollision(*this);
}
//-----------------------------------------------------------------------------