#pragma once


#include <SFML/Graphics.hpp>
#include <vector>

class Map 
{
public:
    Map(const sf::Vector2u& mapSize, int t);
    int getTimerValue() const;
    void setTimer(int timeToSet);
    void setSize(sf::Vector2u newSize);
    void resize(int size);
    sf::Vector2u getMapSize();
    void setKingStart(const sf::Vector2u& kingLoc);
    sf::Vector2u getKingStart(const sf::Vector2u& kingLoc);
    void operator()(int y, char object);
    char operator()(const sf::Vector2u& wantedTile) const;

private:
    std::vector<std::vector<char>> m_map;
    sf::Vector2u m_kingStart;
    int m_mapTimer;
    sf::Vector2u m_mapSize;
};


