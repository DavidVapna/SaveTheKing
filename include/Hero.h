#pragma once
//-----------------------------------------------------------------------------
#include <iostream>
#include "MovingObject.h"
//-----------------------------------------------------------------------------
class Hero : public MovingObject
{
public:
    Hero(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject);
    unsigned int currHp() const;
    
    enum class GiftType{goodTG, badTG, dwarfsG, non};

    virtual void handleCollision(GameObject& currObject) override;
    virtual void handleCollision(King& theKing) override;
    virtual void handleCollision(Mage& theMage) override;
    virtual void handleCollision(Thief& theThief) override;
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

    virtual void updateDamageTime(const sf::Time& addTime);
    virtual void draw(sf::RenderWindow& window) override;
    virtual void highLight(sf::RenderWindow& window);
    sf::Sprite getSprite();
    void portalTime(const sf::Time& timePassed);
    bool isGiftTouched();
    int handleGift();


protected:
    sf::Time m_damaged;
    void damaged();
    static unsigned int m_hp;
    bool m_gotHit = false;
    int m_gift = -1;
    bool m_giftTouched = false;
private:
};
//-----------------------------------------------------------------------------
