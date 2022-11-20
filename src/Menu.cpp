//-----------------------------------------------------------------------------
#include "Menu.h"
//-----------------------------------------------------------------------------
const int IMAGES_ON_MENU = 4;
const int MENU_FIRST_BUTTON = 100;
const int MENU_OPTIONS_START = 250;
//-----------------------------------------------------------------------------
Menu::Menu(sf::RenderWindow& theWindow)
{
	m_window = &theWindow;
	setSprites();
	setFont();
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//because the menu is something that is continuous and we dont want to change
//it, we will load the sprites in the specific following way.
void Menu::setSprites()
{
	sf::Sprite MenuBgLoader;
	sf::Vector2f menuScaler;

	MenuBgLoader.setTexture(DataLoader::instance().getMenuTexture(WallPaper));
	menuScaler.x = (float)MENU_WIDTH / MenuBgLoader.getTexture()->getSize().x;
	menuScaler.y = (float)MENU_HEIGHT / MenuBgLoader.getTexture()->getSize().y;
	MenuBgLoader.setScale(menuScaler);
	m_sprites.push_back(MenuBgLoader);

	for (int i = Play; i < numOfTextures - 1; i++)
	{
		sf::Sprite loadOptions;
		loadOptions.setTexture(DataLoader::instance().getMenuTexture(i));
		menuScaler.x = (float)MENU_OPTION_WIDTH / loadOptions.getTexture()->getSize().x;
		menuScaler.y = (float)MENU_OPTION_HEIGHT / loadOptions.getTexture()->getSize().y;
		loadOptions.setScale(menuScaler);
		if (i == Play || i == Phl)
			loadOptions.setPosition(50, 100);
		else if (i == Help || i == Hhl)
			loadOptions.setPosition(300, 100);
		else if (i == Quit || i == Qhl)
			loadOptions.setPosition(550, 100);


		m_sprites.push_back(loadOptions);
	}
}
//-----------------------------------------------------------------------------
void Menu::setFont()
{
	m_text.setFont(DataLoader::instance().getFont());
	m_text.setStyle(sf::Text::Bold);
	m_text.setString("GameBy: David V.");
	m_text.setCharacterSize(40);
}
//-----------------------------------------------------------------------------
//
void Menu::setMenuSize()
{

	m_window->setSize(sf::Vector2u(MENU_WIDTH, MENU_HEIGHT));
	m_window->setView(sf::View(sf::FloatRect(0, 0, MENU_WIDTH, MENU_HEIGHT)));
	m_window->clear();
}
//-----------------------------------------------------------------------------
//
void Menu::renderMenu(const sf::Vector2f& mousePos)
{
	m_window->clear();
	m_window->draw(m_sprites[WallPaper]);
	if (m_sprites[Play].getGlobalBounds().contains(mousePos))
	{
		m_window->draw(m_sprites[Phl]);
		m_window->draw(m_sprites[Help]);
		m_window->draw(m_sprites[Quit]);
	}
	else if (m_sprites[Help].getGlobalBounds().contains(mousePos))
	{
		m_window->draw(m_sprites[Play]);
		m_window->draw(m_sprites[Hhl]);
		m_window->draw(m_sprites[Quit]);
	}
	else if (m_sprites[Quit].getGlobalBounds().contains(mousePos))
	{
		m_window->draw(m_sprites[Play]);
		m_window->draw(m_sprites[Help]);
		m_window->draw(m_sprites[Qhl]);
	}
	else
	{
		m_window->draw(m_sprites[Play]);
		m_window->draw(m_sprites[Help]);
		m_window->draw(m_sprites[Quit]);
	}
	m_window->display();
}
//-----------------------------------------------------------------------------
unsigned Menu::menuClick(const sf::Vector2f& mouseLoc)
{
	std::cout << mouseLoc.x << std::endl;
	std::cout << mouseLoc.y << std::endl;
	if (m_sprites[Play].getGlobalBounds().contains(mouseLoc))
		return CurrentMode::Play;
	if (m_sprites[Help].getGlobalBounds().contains(mouseLoc))
		return CurrentMode::Help;
	if (m_sprites[Quit].getGlobalBounds().contains(mouseLoc))
		return CurrentMode::Quit;	

	return CurrentMode::OptionMenu;
}
//-----------------------------------------------------------------------------