#pragma once
//-----------------------------------------------------------------------------
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Const.h"
#include "DataLoader.h"
#include "StaticObject.h"
#include "GameObject.h"
#include "Hero.h"
#include "World.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
class Board
{
public:
	Board(sf::RenderWindow& theWindow);
	void renderBoard();
	void setCurrentLevel(int currLevel);
	void loadMapObjects();
	void createObject(char type, const sf::Vector2f& pos, const sf::Vector2f& size);
	void updateBoard();
	void setHeroDirection(sf::Keyboard::Key key);
	void printStats();
	void resetWindowSize();
	std::unique_ptr<Hero> createHero(char type, const sf::Vector2f& loc, const sf::Vector2f& size);
	std::unique_ptr<StaticObject> createStatic(char type, const sf::Vector2f& loc, const sf::Vector2f& size);
	void swapPlayer();
	bool loadNextMap();
	void moveObjects();
	void collisionChecks();
	void resetGameClock();
	int getGameClock();
	void render();
	void setCurrentLevel();


private:
	World m_world;
	Hero* m_currHero;
	std::vector<std::unique_ptr<Dwarf>> m_dwarfs;
	sf::Clock m_gameClock;
	sf::Clock m_animationClock;
	std::vector<std::unique_ptr<Hero>> m_heros;
	std::vector<std::unique_ptr<StaticObject>> m_statics;
	unsigned m_numOfHeros = -1;
    sf::Time m_coolDown;
	int m_portals = -1;
	sf::RenderWindow* m_window;
	sf::Time m_giftEffect;
};
//-----------------------------------------------------------------------------