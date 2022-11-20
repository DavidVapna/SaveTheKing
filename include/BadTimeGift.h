#pragma once
#include "Gift.h"

class BadTimeGift : public Gift
{
public:
	using Gift::Gift;
	using Gift::handleCollision;

	virtual void handleCollision(GameObject& currObject) override;
	virtual void handleCollision(King& theKing) override;
	virtual void handleCollision(Mage& theMage) override;
	virtual void handleCollision(Thief& theTief) override;
	virtual void handleCollision(Warrior& theWarrior) override;
	virtual void handleCollision(Dwarf& dwarf) override;

private:

};