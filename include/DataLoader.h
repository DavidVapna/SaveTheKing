#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>



class DataLoader
{
public:
	~DataLoader();
	static DataLoader& instance();
	sf::Texture& getGameTexture(int wantedTexture);
	sf::Texture& getMenuTexture(int wantedTexture);
	sf::Texture& getHelpTexture (int wantedTexture);
	static int randomNumber(int max);
	sf::Font& getFont();
	void triggerSound(int theSound);


private:
	DataLoader();
	DataLoader(const DataLoader&) = default;
	DataLoader& operator=(const DataLoader&) = default;

	std::vector<sf::Texture> m_gameTextures;
	std::vector<sf::Texture> m_menuTextures;
	std::vector<sf::Texture> m_helpTextures;
	std::vector<sf::SoundBuffer> m_soundsBuffer;
	std::vector<sf::Sound> m_soundEffects;
	sf::Font m_gameFont;

};