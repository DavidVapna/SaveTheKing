//-----------------------------------------------------------------------------
#include "Dwarf.h"
#include "Wall.h"
#include "Fire.h"
#include "Orc.h"
#include "Gate.h"
#include "Throne.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Dwarf::handleCollision(GameObject& currObject)
{
    if (&currObject == this)
        return;
    currObject.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(King& theKing)
{
    theKing.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Mage& theMage)
{
    theMage.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Thief& theThief)
{
    theThief.handleCollision(*this);
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Warrior& theWarrior)
{
    theWarrior.handleCollision(*this);
}
void Dwarf::handleCollision(GoodTimeGift& gift)
{
    return;
}
void Dwarf::handleCollision(BadTimeGift& gift)
{
    return;
}
void Dwarf::handleCollision(EliminateDwarfsGift& gift)
{
    return;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Dwarf& dwarf)
{
    stepBack(dwarf.getLocation());
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Orc& orc)
{
    stepBack(orc.getLocation());
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Fire& fire)
{
    stepBack(fire.getLocation());
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Gate& gate)
{
    stepBack(gate.getLocation());
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Key& key)
{
    return;
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Portal& portal)
{
    return;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Wall& wall)
{
    m_steps = 1;
    stepBack(wall.getLocation());
}
//-----------------------------------------------------------------------------
void Dwarf::handleCollision(Throne& throne)
{
    stepBack(throne.getLocation());
}
Dwarf::Dwarf(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject)
    : MovingObject(loc, size, theObject)
{
    m_speed = DWARF_SPEED;
}
////-----------------------------------------------------------------------------
//void Dwarf::handleCollision(GiftAddDwarf&)
//{
//}
////-----------------------------------------------------------------------------
//void Dwarf::handleCollision(GiftAddLive&)
//{
//}
////-----------------------------------------------------------------------------
//void Dwarf::handleCollision(GiftAddBonus&)
//{
//}
////-----------------------------------------------------------------------------
//void Dwarf::handleCollision(GiftAddTime&)
//{
//}
////-----------------------------------------------------------------------------
void Dwarf::move(sf::Time deltaTime)
{

    m_steps--;
    if (m_steps == 0)
    {
        m_steps = 25;
        int dir = rand() % 20;
        if (dir >= 0 && dir <= 5)
            m_dir = Direction::Left;
        else if (dir >= 6 && dir <= 10)
            m_dir = Direction::Right;
        else if (dir >= 11 && dir <= 15)
            m_dir = Direction::Up;
        else if (dir >= 16 && dir <= 20)
            m_dir = Direction::Down;
    }
    MovingObject::move(deltaTime);
}