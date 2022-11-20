//-----------------------------------------------------------------------------
#include "DataLoader.h"
//-----------------------------------------------------------------------------
const int NUM_OF_MENU_TEXTURES = 8;
const char* MENU_TEXTURES[NUM_OF_MENU_TEXTURES] =
{
    "MenuBG.png",
    "Play.png", "Help.png", "Quit.png",
    "PlayHL.png", "HelpHL.png", "QuitHL.png", "Stats.png"
};

const int NUM_OF_GAME_TEXTURES = 14;
const char* GAME_TEXTURES[NUM_OF_GAME_TEXTURES] =
{
  "TheKing(Queen).png", "Mage.png", "Thief.png", "Warrior.png",
  "Orc.png", "Key.png" , "Portal.png", "Fire.png",
  "Throne.png", "Gate.png", "Wall.png", "LevelBG.png",
  "Dwarf.png", "Gift.png"
};
const int NUM_OF_HELP_TEXTURES = 1;
const char* HELP_TEXTURES[NUM_OF_HELP_TEXTURES] =
{
    "HelpMenu.png"
};
const char* FONT = "MarioFont.ttf";

const int NUM_OF_SOUNDS = 1;
const char* SOUND_EFFECTS[NUM_OF_SOUNDS] =
{
    "Fire.ogg"
};


//-----------------------------------------------------------------------------
DataLoader::DataLoader()
{
    srand((unsigned int)time(NULL));

    //Loading all the menu textures:
    m_menuTextures.resize(NUM_OF_MENU_TEXTURES);
    for (int i = 0; i < NUM_OF_MENU_TEXTURES; i++) {
        if (!m_menuTextures[i].loadFromFile(MENU_TEXTURES[i]))
            std::cout << "The following png failed to load:" << MENU_TEXTURES[i] << std::endl;
    }
    //Loading all the game textures:
    m_gameTextures.resize(NUM_OF_GAME_TEXTURES);
    for (int i = 0; i < NUM_OF_GAME_TEXTURES; i++) {
        if (!m_gameTextures[i].loadFromFile(GAME_TEXTURES[i]))
            std::cout << "The following png failed to load:" << GAME_TEXTURES[i] << std::endl;
    }
    //Loading all the help textures:
    m_helpTextures.resize(NUM_OF_HELP_TEXTURES);
    for (int i = 0; i < NUM_OF_HELP_TEXTURES; i++) {
        if (!m_helpTextures[i].loadFromFile(HELP_TEXTURES[i]))
            std::cout << "The following png failed to load:" << HELP_TEXTURES[i] << std::endl;
    }

    // loading the font
    if (!m_gameFont.loadFromFile(FONT))
    {
        std::cout << "*Failed to load font* " << std::endl;
    }

    // load sound.
    m_soundsBuffer.resize(NUM_OF_SOUNDS);
    m_soundEffects.resize(NUM_OF_SOUNDS);
    for (int i = 0; i < NUM_OF_SOUNDS; i++) 
    {
        if (!m_soundsBuffer[i].loadFromFile(SOUND_EFFECTS[i]))
        {
            std::cout << "failed to load sound file:" << SOUND_EFFECTS[i] << std::endl;
        }
        else
            m_soundEffects[i].setBuffer(m_soundsBuffer[i]);
    }
}
//-----------------------------------------------------------------------------
DataLoader::~DataLoader()
{
    m_gameTextures.clear();
    m_menuTextures.clear();
    m_soundsBuffer.clear();
    m_soundEffects.clear();
}
//-----------------------------------------------------------------------------
DataLoader& DataLoader::instance()
{
    static DataLoader inst;
    return inst;
}
//-----------------------------------------------------------------------------
sf::Texture& DataLoader::getGameTexture(int wantedTexture)
{
    return m_gameTextures[wantedTexture];
}
//-----------------------------------------------------------------------------
sf::Texture& DataLoader::getMenuTexture(int wantedTexture)
{
    return m_menuTextures[wantedTexture];
}
//-----------------------------------------------------------------------------
sf::Texture& DataLoader::getHelpTexture(int wantedTexture)
{
    return m_helpTextures[wantedTexture];
}
//-----------------------------------------------------------------------------
sf::Font& DataLoader::getFont()
{
    return m_gameFont;
}
//-----------------------------------------------------------------------------
int DataLoader::randomNumber(int max)
{
    return rand() % max;
}
//-----------------------------------------------------------------------------
void DataLoader::triggerSound(int theSound)
{
    m_soundEffects[theSound].setVolume(100.f);
    m_soundEffects[theSound].setLoop(false);
    m_soundEffects[theSound].play();
}
//-----------------------------------------------------------------------------
