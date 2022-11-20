#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Menu.h"

class Controller
{
public:
    Controller();



    void run();
    void handleEvents();
    void handleBoardEvents();
    void handleMenuEvents();
    void mouseClicked();
    void displayHelp();
    void handleHelpEvents();

private:
    CurrentMode m_currMode = CurrentMode::Play;
    Board* m_board;
    Menu* m_menu;
    sf::RenderWindow m_window;
    sf::Vector2i m_mousePos;
    sf::Vector2f m_mouseView;
};