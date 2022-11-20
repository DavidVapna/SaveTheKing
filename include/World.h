#pragma once


#include "Map.h"
#include "const.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdio>

#include <io.h>

class World
{
public:
    World();
    void loadMapsFromFile();
    bool loadNextMap();

    int getCurrentLevel() const;
    void setCurrentLevel(int lev);

    Map getCurrentMap() const;
    sf::Vector2u getMapSize() const;
    sf::Vector2u getPortalLoc(int getPortLoc) const;

private:
    std::vector<sf::Vector2u> m_portals;
    std::vector<Map> m_maps;
    int m_currLevel = 0;
};