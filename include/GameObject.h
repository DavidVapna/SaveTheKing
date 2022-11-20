#pragma once
//-----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <iostream>
#include "const.h"
#include "DataLoader.h"
//-----------------------------------------------------------------------------
class King;
class Mage;
class Thief;
class Warrior;
class Orc;
class Fire;
class Gate;
class Key;
class Portal;
class Wall;
class Throne;
class Dwarf;
class Gift;
class BadTimeGift;
class GoodTimeGift;
class EliminateDwarfsGift;
//-----------------------------------------------------------------------------
class GameObject
{

public:
    GameObject(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject);
    virtual bool checkCollision(const sf::FloatRect&) const;

    virtual void handleCollision(GameObject& currObject) = 0;
    virtual void handleCollision(King& theKing) = 0;
    virtual void handleCollision(Mage& theMage) = 0;
    virtual void handleCollision(Thief& theThief) = 0;
    virtual void handleCollision(Warrior& theWarrior) = 0;
    virtual void handleCollision(GoodTimeGift& gift) = 0;
    virtual void handleCollision(BadTimeGift& gift) = 0;
    virtual void handleCollision(EliminateDwarfsGift& gift) = 0;
    virtual void handleCollision(Dwarf& dwarf) = 0;
    virtual void handleCollision(Orc& orc) = 0;
    virtual void handleCollision(Fire& fire) = 0;
    virtual void handleCollision(Gate& gate) = 0;
    virtual void handleCollision(Key& key) = 0;
    virtual void handleCollision(Portal& portal) = 0;
    virtual void handleCollision(Wall& wall) = 0;
    virtual void handleCollision(Throne& throne) = 0;

    virtual sf::FloatRect getGlobalBounds() const;
    virtual ~GameObject() = default;
    virtual bool isDisposed();
    virtual void draw(sf::RenderWindow& window);
    virtual void setDisposed(bool set);
    sf::Vector2f getLocation() const;

    sf::Vector2f getObjectSize();
    

protected:
    bool m_isDisposed = false;
    sf::Vector2f m_location;
    sf::Sprite m_sprite;
    sf::Vector2f m_objectSize;
};
//-----------------------------------------------------------------------------