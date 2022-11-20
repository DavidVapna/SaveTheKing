#pragma once

//-----------------------------------------------------------------------------
#include "GameObject.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"
#include "Dwarf.h"
//-----------------------------------------------------------------------------
class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theTief) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(GoodTimeGift& gift) override;
    virtual void handleCollision(BadTimeGift& gift) override;
    virtual void handleCollision(EliminateDwarfsGift& gift) override;
    virtual void handleCollision(Dwarf& dwarf) override;
    virtual void handleCollision(Orc& orc) override;
    virtual void handleCollision(Fire& fire) override;
    virtual void handleCollision(Gate& gate) override;
    virtual void handleCollision(Key& key) override;
    virtual void handleCollision(Portal& portal) override;
    virtual void handleCollision(Wall& wall) override;
    virtual void handleCollision(Throne& throne) override;
private:

};
//-----------------------------------------------------------------------------