//-----------------------------------------------------------------------------
#include "Hero.h"
#include "Fire.h"
#include "Orc.h"
#include "Wall.h"
#include "Dwarf.h"
#include "Gate.h"
#include "Throne.h"
#include "Portal.h"
#include "GoodTimeGift.h"
#include "BadTimeGift.h"
#include "EliminateDwarfsGift.h"
//-----------------------------------------------------------------------------
unsigned Hero::m_hp = 3;
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

Hero::Hero(const sf::Vector2f& loc, const sf::Vector2f& size, int theObject)
    :MovingObject(loc, size, theObject)
{
    m_speed = HERO_SPEED;
}

//-----------------------------------------------------------------------------
unsigned int Hero::currHp() const
{
    return m_hp;
}
//-----------------------------------------------------------------------------
void Hero::updateDamageTime(const sf::Time& addTime)
{
    if (m_damaged.asSeconds() > 2)
    {
        m_damaged = sf::Time();
        m_gotHit = false;
    }
    if(m_gotHit)
        m_damaged += addTime;
}
//-----------------------------------------------------------------------------
void Hero::damaged()
{
    if (!m_gotHit)
    {
        m_hp--;
        m_gotHit = true;
    }
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(GameObject& currObject)
{
    return;
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(King& theKing)
{
    stepBack(theKing.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Mage& theMage)
{
    stepBack(theMage.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Thief& theThief)
{
    stepBack(theThief.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Warrior& theWarrior)
{
    stepBack(theWarrior.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(GoodTimeGift& gift)
{
    m_giftTouched = true;
    m_gift = badTime;
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(BadTimeGift& gift)
{
    m_giftTouched = true;
    m_gift = goodTime;
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(EliminateDwarfsGift& gift)
{
    m_giftTouched = true;
    m_gift = Eliminate;
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Dwarf& dwarf)
{
    stepBack(dwarf.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Orc& orc)
{
    damaged();
    stepBack(orc.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Fire& fire)
{
    damaged();
    stepBack(fire.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Gate& gate)
{
    stepBack(gate.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Key& key)
{
    return;
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Portal& portal)
{
    if (!m_usedPortal)
    {
        m_location = portal.getOtherPort();
        m_sprite.setPosition(m_location);
        m_usedPortal = true;
    }
}
//-----------------------------------------------------------------------------
void Hero::portalTime(const sf::Time& timePassed)
{
    if (m_usedPortal)
        m_portalCD += timePassed;

    if (m_portalCD.asSeconds() > 2)
    {
        m_portalCD = sf::Time();
        m_usedPortal = false;
    }
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Wall& wall)
{
    stepBack(wall.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::handleCollision(Throne& throne)
{
    stepBack(throne.getLocation());
}
//-----------------------------------------------------------------------------
void Hero::draw(sf::RenderWindow& window)
{
    auto rect = m_sprite;
    rect.setColor(sf::Color(100, 100, 100, 150));
    window.draw(rect);
}
//-----------------------------------------------------------------------------
void Hero::highLight(sf::RenderWindow& window)
{
    auto rect = m_sprite;
    rect.setColor(sf::Color(255, 255, 255, 255));
    window.draw(rect);
}
//-----------------------------------------------------------------------------
sf::Sprite Hero::getSprite()
{
    return m_sprite;
}
//-----------------------------------------------------------------------------
bool Hero::isGiftTouched()
{
    return m_giftTouched;
}
//-----------------------------------------------------------------------------
int Hero::handleGift()
{
    if (m_giftTouched)
    {
        m_giftTouched = false;
        return (int)m_gift;
    }
    else
        return -1;
}
//-----------------------------------------------------------------------------