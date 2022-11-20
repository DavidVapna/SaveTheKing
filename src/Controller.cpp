//-----------------------------------------------------------------------------
#include "Controller.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
Controller::Controller()
    :m_window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT + STAT_BAR), "Save The King!", sf::Style::Default)
{
    m_window.setFramerateLimit(60);
    m_menu = new Menu(m_window);
    m_board = new Board(m_window);
}
//-----------------------------------------------------------------------------
void Controller::run()
{
    m_board->resetWindowSize();
    while (m_window.isOpen())
    {
        switch (m_currMode)
        {
        case CurrentMode::OptionMenu:
        {
            handleEvents();
            m_menu->renderMenu(m_mouseView);
        }
            break;
        case CurrentMode::Play:
        {
            handleEvents();
            m_board->updateBoard();
            m_board->renderBoard();
        }
        break;
        case CurrentMode::Help:
            displayHelp();
            handleEvents();
            break;
        case CurrentMode::Quit:
            m_window.close();
            break;
        }
    }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Controller::handleEvents()
{
    switch (m_currMode)
    {
    case CurrentMode::OptionMenu:
        handleMenuEvents();
        break;
    case CurrentMode::Play:
        handleBoardEvents();
        break;
    case CurrentMode::Help:
        handleHelpEvents();
    }
}
//-----------------------------------------------------------------------------
void Controller::handleBoardEvents()
{
    for (auto event = sf::Event(); m_window.pollEvent(event); )
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window.close();
                break;
            case sf::Keyboard::P:
                m_board->swapPlayer();
                break;
            case sf::Keyboard::R:
                m_board->setCurrentLevel();
                break;
            case sf::Keyboard::M: case sf::Keyboard::Q:
                m_currMode = CurrentMode::OptionMenu;
                m_menu->setMenuSize();
                break;
            default:
                m_board->setHeroDirection(event.key.code);
                break;
            }
        }
            break;
        case::sf::Event::KeyReleased:
            m_board->setHeroDirection(sf::Keyboard::Space);
            break;
        }
    }
}
//-----------------------------------------------------------------------------
void Controller::handleMenuEvents()
{
    m_mousePos = sf::Mouse::getPosition(m_window);
    m_mouseView = m_window.mapPixelToCoords(m_mousePos);

    for (auto event = sf::Event(); m_window.pollEvent(event); )
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_window.close();
                break;
            case sf::Keyboard::P:
                m_currMode = CurrentMode::Play;
                m_board->resetWindowSize();
                break;
            case sf::Keyboard::H:
                m_currMode = CurrentMode::Help;
                m_menu->setMenuSize();
                break;
            }
            break;
        }
        case sf::Event::MouseButtonReleased:
            mouseClicked();
            break;
        }
    }
}
//-----------------------------------------------------------------------------
void Controller::handleHelpEvents()
{
    m_mousePos = sf::Mouse::getPosition(m_window);
    m_mouseView = m_window.mapPixelToCoords(m_mousePos);

    for (auto event = sf::Event(); m_window.pollEvent(event); )
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape: case sf::Keyboard::M:
                m_currMode = CurrentMode::OptionMenu;
                m_menu->setMenuSize();
                break;
            case sf::Keyboard::C:
                m_currMode = CurrentMode::Play;
                m_board->resetWindowSize();
                break;
            }
            break;
        }
        case sf::Event::MouseButtonReleased:
            break;
        }
    }
}
//-----------------------------------------------------------------------------
void Controller::mouseClicked()
{
    switch (m_menu->menuClick(m_mouseView))
    {
    case CurrentMode::Play:
        m_currMode = CurrentMode::Play;
        m_board->resetWindowSize();
        break;
    case CurrentMode::Help:
        m_currMode = CurrentMode::Help;
        m_menu->setMenuSize();
        break;
    case CurrentMode::Quit:
        m_currMode = CurrentMode::Quit;
        break;
    }
}
//-----------------------------------------------------------------------------
void Controller::displayHelp()
{
    m_window.setView(sf::View(sf::FloatRect(0, 0, HELP_WIDTH, HELP_HEIGHT)));
    m_window.setSize(sf::Vector2u(HELP_WIDTH, HELP_HEIGHT));
    sf::Sprite help;
    sf::Vector2f helpScale;
    help.setTexture(DataLoader::instance().getHelpTexture(menuEnum::menuBG));
    helpScale.x = (float)HELP_WIDTH / help.getTexture()->getSize().x;
    helpScale.y = (float)HELP_HEIGHT / help.getTexture()->getSize().y;
    help.setScale(helpScale);
    help.setPosition(0, 0);
    m_window.clear();
    m_window.draw(help);
    m_window.display();
}
//-----------------------------------------------------------------------------


