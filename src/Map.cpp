
//-----------------------------------------------------------------------------
#include "Map.h"
#include <iostream>
//-----------------------------------------------------------------------------
Map::Map(const sf::Vector2u& mapSize, int time)
	: m_mapSize(mapSize), m_mapTimer(time) {}
//-----------------------------------------------------------------------------
int Map::getTimerValue() const
{
	return m_mapTimer;
}
//-----------------------------------------------------------------------------
sf::Vector2u Map::getMapSize()
{
	return m_mapSize;
}
//-----------------------------------------------------------------------------
void Map::setTimer(int timeToSet)
{
	m_mapTimer = timeToSet;
}
//-----------------------------------------------------------------------------
void Map::setSize(sf::Vector2u newSize)
{
	m_mapSize = newSize;
}
//-----------------------------------------------------------------------------
void Map::resize(int size)
{
	m_map.resize(size);
}
//-----------------------------------------------------------------------------
void Map::setKingStart(const sf::Vector2u& kingLoc)
{
	m_kingStart = kingLoc;
}
//-----------------------------------------------------------------------------
sf::Vector2u Map::getKingStart(const sf::Vector2u& kingLoc)
{
	return m_kingStart;
}
//-----------------------------------------------------------------------------
char Map::operator()(const sf::Vector2u& wantedTile) const
{
    return m_map[wantedTile.y][wantedTile.x];
}
//-----------------------------------------------------------------------------
void Map::operator()(int y, char object)
{
	m_map[y].push_back(object);
}
//-----------------------------------------------------------------------------