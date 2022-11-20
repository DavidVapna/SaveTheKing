//-----------------------------------------------------------------------------
#include "World.h"
#include <fstream>
#include "DataLoader.h"
#include "Const.h"
//-----------------------------------------------------------------------------
const std::string GAME_MAPS = "Board.txt";
//-----------------------------------------------------------------------------
World::World()
{
    loadMapsFromFile();
}
//-----------------------------------------------------------------------------
//loadinig all the maps from the main file to avoid delayed loading mid game,
//we prefer to have slow start on startup than mid-game.
void World::loadMapsFromFile() 
{

    std::ifstream maps;
    maps.open(GAME_MAPS);
    if (!maps) 
    {
        std::cerr << "Unable to open file " << GAME_MAPS << std::endl;
        exit(EXIT_FAILURE);
    }
    char currObject;
    sf::Vector2u levelSize;
    int mapTimer;
    int currentLevel = 0;

    while (maps >> std::skipws >> levelSize.y)
    {

        maps >> std::skipws >> levelSize.x;
        maps >> std::skipws >> mapTimer;
        maps.ignore(1, '\n');//skipping endl(new line).
        m_maps.push_back(Map(levelSize, mapTimer));

        m_maps[currentLevel].resize(levelSize.y);

        // read the map
        for (int y = 0; y < levelSize.y; y++)
        {
            for (int x = 0; x < levelSize.x; x++)
            {
                maps >> std::noskipws >> currObject;
             
                if (currObject == TheKing)
                    m_maps[currentLevel].setKingStart(sf::Vector2u(x, y));
                else if (currObject == ThePortal)
                    m_portals.push_back(sf::Vector2u(x, y));

                m_maps[currentLevel](y, currObject);
            }
            maps.ignore(1, '\n');//skipping again new line.
        }
        //we have a new line between maps (just because).
        maps.ignore(1, '\n');

        currentLevel++;
    }

    maps.close();
}
//-----------------------------------------------------------------------------
int World::getCurrentLevel() const
{
    return m_currLevel;
}
//-----------------------------------------------------------------------------
void World::setCurrentLevel(int lev)
{
    if (lev <0 || lev > m_maps.size())
        lev = 0;
    m_currLevel = lev;
}
//-----------------------------------------------------------------------------
bool World::loadNextMap()
{
    //DataLoader::instance().triggerSound(END_LEVEL);

    if (m_currLevel < m_maps.size() - 1)
    {
        m_currLevel++;
        return true;
    }
    return false;
}
//-----------------------------------------------------------------------------
Map World::getCurrentMap() const
{
    return m_maps[m_currLevel];
}
//-----------------------------------------------------------------------------
sf::Vector2u World::getMapSize() const
{
    auto temp = m_maps[m_currLevel];
    return temp.getMapSize();
}
//-----------------------------------------------------------------------------
sf::Vector2u World::getPortalLoc(int getPortLoc) const
{
    return m_portals[getPortLoc];
}
//-----------------------------------------------------------------------------
