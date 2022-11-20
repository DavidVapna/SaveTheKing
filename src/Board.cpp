//-----------------------------------------------------------------------------
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Warrior.h"
#include "Wall.h"
#include "Orc.h"
#include "Gate.h"
#include "Throne.h"
#include "Key.h"
#include "Portal.h"
#include "Fire.h"
#include "Gift.h"
#include "Dwarf.h"
#include "EliminateDwarfsGift.h"
#include "BadTimeGift.h"
#include "GoodTimeGift.h"
#include <typeinfo>
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
Board::Board(sf::RenderWindow& theWindow)
    :m_coolDown(sf::Time())
{
    m_window = &theWindow;
    m_world.loadMapsFromFile();
    
    setCurrentLevel(0);
    loadMapObjects();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Board::resetWindowSize()
{
    m_window->setView(sf::View(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT + STAT_BAR)));
    m_window->setSize(sf::Vector2u(GAME_WIDTH, GAME_HEIGHT + STAT_BAR));
}
//-----------------------------------------------------------------------------
void Board::resetGameClock()
{
    m_gameClock.restart();
}
//------------------------------------------------------------------------------
int Board::getGameClock()
{
    return (int)m_gameClock.getElapsedTime().asSeconds();
}
//-----------------------------------------------------------------------------
void Board::loadMapObjects()
{
    m_heros.clear();
    m_statics.clear();
    m_dwarfs.clear();
    m_giftEffect = sf::Time();
    Map currentMap = m_world.getCurrentMap();

    sf::Vector2f objectSize;
    objectSize.x = (float)GAME_WIDTH / currentMap.getMapSize().x;
    objectSize.y = (float)GAME_HEIGHT / currentMap.getMapSize().y;
    
    sf::Vector2f startPos;
    startPos.x = objectSize.x * 0.5;
    startPos.y = objectSize.y * 0.5;

    for (int y = 0; y < currentMap.getMapSize().y; y++) 
    {
        sf::Vector2f objectPosition(startPos.x, (float)(STAT_BAR + y * objectSize.y) + startPos.y);
        for (int x = 0; x < currentMap.getMapSize().x; x++) 
        {
            createObject(currentMap(sf::Vector2u(x, y)), objectPosition, objectSize);
            objectPosition.x += objectSize.x;
        }
    }

    resetGameClock();
}
//-----------------------------------------------------------------------------
void Board::setCurrentLevel(int currLevel)
{
    m_world.setCurrentLevel(currLevel);
}
//-----------------------------------------------------------------------------
/*
* load the next map available
* returns false if no more maps, else true
*/
bool Board::loadNextMap() 
{
    if (m_world.loadNextMap()) 
    {
        setCurrentLevel();
        resetWindowSize();
        return true;
    }
    else
        return false; // no more maps
}
//-----------------------------------------------------------------------------
void Board::setCurrentLevel ()
{
    loadMapObjects();
}
//-----------------------------------------------------------------------------
void Board::renderBoard()
{
    m_window->clear();
    Map currentMap = m_world.getCurrentMap();
    sf::Vector2f objectSize;
    objectSize.x = (float)GAME_WIDTH / currentMap.getMapSize().x;
    objectSize.y = (float)GAME_HEIGHT / currentMap.getMapSize().y;

    sf::Sprite bgPhoto;
    bgPhoto.setTexture(DataLoader::instance().getGameTexture(BackgroundSprite));
    bgPhoto.setScale(objectSize);
    bgPhoto.setPosition(sf::Vector2f(0.f, STAT_BAR));
    m_window->draw(bgPhoto);

    render();
    m_window->display();
}
//-----------------------------------------------------------------------------
void Board::render()
{
    for (auto& staticObject : m_statics)

    {
        if (staticObject != nullptr && staticObject->isDisposed() == false)
            staticObject->draw(*m_window);
    }
    for (auto& dwarf : m_dwarfs)
    {
        if (dwarf != nullptr && dwarf->isDisposed() == false)
            dwarf->draw(*m_window);
    }
    for (auto& movingObject : m_heros)
    {
        if (movingObject != nullptr && movingObject->isDisposed() == false)
            movingObject->draw(*m_window);
    }
    m_currHero->highLight(*m_window);
    printStats();
}
//-----------------------------------------------------------------------------
void Board::createObject(char type, const sf::Vector2f& pos, const sf::Vector2f& size)
{
    auto movingScale = size;
    movingScale.x *= MOVING_SCALE;
    movingScale.y *= MOVING_SCALE;

    switch (type)
    {
    case TheKing: case TheWarrior: case TheMage: case TheThief:
    {
        m_numOfHeros++;
        auto object = createHero(type, pos, movingScale);
        m_heros.push_back(std::move(object));
        if (type == TheKing)
            m_currHero = m_heros[m_heros.size() - 1].get();
    }
        return;
    case TheDwarf:
    {
        m_dwarfs.push_back(std::make_unique<Dwarf>(pos, movingScale, DwarfSprite));
    }
        return;
    case Space:
        return;
    default:
        m_statics.push_back(createStatic(type, pos, size));
        return;
    }
    std::cerr << "Unrecognized char in the file: '" << type << "'" << std::endl;
    exit(EXIT_FAILURE);
}
//-----------------------------------------------------------------------------
std::unique_ptr<Hero> Board::createHero(char type, const sf::Vector2f& loc, const sf::Vector2f& size)
{
    switch (type)
    {
    case TheKing:
        return std::make_unique<King>(loc, size, KingSprite);
    case TheMage:
        return std::make_unique<Mage>(loc, size, MageSprite);
    case TheThief:
        return std::make_unique<Thief>(loc, size, ThiefSprite);
    case TheWarrior:
        return std::make_unique<Warrior>(loc, size, WarriorSprite);
    }
    std::cerr << "failed to make_unique hero" << std::endl;
    return nullptr;
}
//-----------------------------------------------------------------------------
std::unique_ptr<StaticObject> Board::createStatic(char type, const sf::Vector2f& loc, const sf::Vector2f& size)
{
    switch (type)
    {
    case TheOrc:
        return std::make_unique<Orc>(loc, size, OrcSprite);
    case TheKey:
        return std::make_unique<Key>(loc, size, KeySprite);
    case ThePortal:
        m_portals++;
        if ((m_portals) % 2 == 0)
            return std::make_unique<Portal>(loc, size, PortalSprite, m_world.getPortalLoc(m_portals + 1));
        else
            return std::make_unique<Portal>(loc, size, PortalSprite, m_world.getPortalLoc(m_portals - 1));
    case TheFire:
        return std::make_unique<Fire>(loc, size, FireSprite);
    case TheThrone:
        return std::make_unique<Throne>(loc, size, ThroneSprite);
    case TheGate:
        return std::make_unique<Gate>(loc, size, GateSprite);
    case TheWall:
        return std::make_unique<Wall>(loc, size, WallSprite);
    case TheGift:
    {
        switch (DataLoader::instance().randomNumber(4))
        {
        case GiftOptions::badTime:
            return std::make_unique<GoodTimeGift>(loc, size, GiftSprite);
        case GiftOptions::goodTime:
            return std::make_unique<BadTimeGift>(loc, size, GiftSprite);
        default:
            return std::make_unique<EliminateDwarfsGift>(loc, size, GiftSprite);
        }
    }
    }
    std::cerr << "Failed to make_unique static" << std::endl;
    return nullptr;
}
//-----------------------------------------------------------------------------
void Board::updateBoard()
{
    moveObjects();
    collisionChecks();
    
    if (m_currHero->isGiftTouched())
    {
        switch (m_currHero->handleGift())
        {
            case GiftOptions::badTime:
                m_giftEffect -= sf::seconds(15);
                break;
            case GiftOptions::goodTime:
                m_giftEffect += sf::seconds(15);
                break;
            case GiftOptions::Eliminate:
                for (auto& dwarf : m_dwarfs)
                {
                    dwarf->setDisposed(true);
                }
                break;
            default:
                break;
        }
    }
    if (typeid(*m_currHero) == typeid(King))
    {
        auto tempKing = static_cast<King*>(m_currHero);
        if (tempKing->isOnThrone())
            loadNextMap();
    }
    if (typeid(*m_currHero) == typeid(Warrior))
    {
        auto tempWarrior = static_cast<Warrior*>(m_currHero);
        if (tempWarrior->didSlay())
        {
            createObject(TheKey, tempWarrior->newKeyLoc(), tempWarrior->newKeySize());
        }
    }
}
//-----------------------------------------------------------------------------
void Board::moveObjects()
{
    sf::Time deltaTime = m_animationClock.restart();

    for (auto& hero : m_heros)
    {
        hero->move(deltaTime);
        hero->updateDamageTime(deltaTime);
        hero->portalTime(deltaTime);
    }
    for (auto& dwarf : m_dwarfs)
    {
        dwarf->move(deltaTime);
    }
}
//-----------------------------------------------------------------------------
void Board::collisionChecks()
{
    for (auto& hero : m_heros)
    {
        for (auto& dwarf : m_dwarfs)
        {
            if (dwarf == nullptr || dwarf->isDisposed())
                continue;
            if (hero->checkCollision(dwarf->getGlobalBounds()))
            {
                hero->handleCollision(*dwarf);
            }
        }
        for (auto& staticObj : m_statics)
        {
            if (staticObj == nullptr || staticObj->isDisposed())
                continue;
            if (hero->checkCollision(staticObj->getGlobalBounds()))
            {
                hero->handleCollision(*staticObj);
            }
        }
    }
    
    for (auto& dwarf : m_heros)
    {
        if (dwarf == nullptr || dwarf->isDisposed())
            continue;
        for (auto& staticObj : m_statics)
        {
            if (staticObj == nullptr || staticObj->isDisposed())
                continue;
            if (dwarf->checkCollision(staticObj->getGlobalBounds()))
            {
                dwarf->handleCollision(*staticObj);
            }
        }
    }
}
//-----------------------------------------------------------------------------
void Board::setHeroDirection(sf::Keyboard::Key key)
{
    m_currHero->setDirection(key);
}
//-----------------------------------------------------------------------------
void Board::swapPlayer()
{
    m_numOfHeros = (m_numOfHeros + 1) % 4;

    if ((m_currHero = dynamic_cast<King*>(m_heros[m_numOfHeros].get())))
        return;
    else if ((m_currHero = dynamic_cast<Mage*>(m_heros[m_numOfHeros].get())))
        return;
    else if ((m_currHero = dynamic_cast<Thief*>(m_heros[m_numOfHeros].get())))
        return;
    else if ((m_currHero = dynamic_cast<Warrior*>(m_heros[m_numOfHeros].get())))
        return;
}
//-----------------------------------------------------------------------------
void Board::printStats()
{
    if (m_currHero == NULL)
        return;

    bool haveKey = false;
    for (auto& hero : m_heros)
    {
        if (auto thief = dynamic_cast<Thief*>(hero.get()))
        {
            haveKey = thief->haveKey();
            break;
        }
    }

    auto time = (int)(m_world.getCurrentMap().getTimerValue()
        - m_gameClock.getElapsedTime().asSeconds() + m_giftEffect.asSeconds());
    std::string timeLeft;
    if (time < 1000 && time > 99)
        timeLeft = std::to_string(time);

    else if (time > 10 && time < 100)
        timeLeft = ("0" + std::to_string(time));
    else if (time > 0 && time < 10)
        timeLeft = ("00" + std::to_string(time));
    else
        timeLeft = "0000";
    std::string gameInfo =
        " Time: " + timeLeft + "\n"
        " HP:  " + std::to_string(m_currHero->currHp()) +
        "            |Moving:  \n" +
        " Level: " + std::to_string(m_world.getCurrentLevel())
        + "         |Key:  " + (haveKey ? "YES" : "NO");
   
    sf::Text text;
    text.setFont(DataLoader::instance().getFont());
    text.setStyle(sf::Text::Bold);
    text.setString(gameInfo);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(27);
    sf::Rect bounds = text.getGlobalBounds();
    text.setPosition(bounds.left, bounds.top);
    text.setOutlineColor(sf::Color::Red);
    text.setOutlineThickness(1);

    auto statsBar = sf::Sprite(DataLoader::instance().getMenuTexture(StatsSprite));
    sf::Vector2f statsScale;
    statsScale.x = GAME_WIDTH / statsBar.getTexture()->getSize().x;
    statsScale.x = STAT_BAR / statsBar.getTexture()->getSize().y;
    statsBar.scale(statsScale);

    auto currentDisplay = m_currHero->getSprite();
    currentDisplay.scale(0.75, 0.75);
    currentDisplay.setPosition(460, (float)STAT_BAR / 2);

    
    m_window->draw(statsBar);
    m_window->draw(currentDisplay);
    m_window->draw(text);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------