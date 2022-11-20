#pragma once
//-----------------------------------------------------------------------------
#include "MovingObject.h"
//-----------------------------------------------------------------------------
class Dwarf : public MovingObject
{
public:
    Dwarf(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject);

    virtual void move(sf::Time deltaTime) override;
    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
    virtual void handleCollision(Warrior& theWarrior) override;
    virtual void handleCollision(GoodTimeGift& gift);
    virtual void handleCollision(BadTimeGift& gift);
    virtual void handleCollision(EliminateDwarfsGift& gift);
    virtual void handleCollision(Dwarf& dwarf) override;
    virtual void handleCollision(Orc& orc) override;
    virtual void handleCollision(Fire& fire) override;
    virtual void handleCollision(Gate& gate) override;
    virtual void handleCollision(Key& key) override;
    virtual void handleCollision(Portal& portal) override;
    virtual void handleCollision(Wall& wall) override;
    virtual void handleCollision(Throne& throne) override;
private:
    int m_steps = 50;
};
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------