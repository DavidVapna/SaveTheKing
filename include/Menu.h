#pragma once
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp> 
#include "DataLoader.h"
#include "Const.h"


//-----------------------------------------------------------------------------
class Menu
{
public:
	Menu(sf::RenderWindow& theWindow);
    void setSprites();
    void setFont();
    void renderMenu(const sf::Vector2f& mousePos);
    void setMenuSize();
    enum class Options{ Start, Help, Quit };
    unsigned menuClick(const sf::Vector2f& mouseLoc);


private:
    std::vector<sf::Sprite> m_sprites;
    sf::Text m_text;
    sf::RenderWindow* m_window;
};
//-----------------------------------------------------------------------------