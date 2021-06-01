#include "FileManager.h"
#include "Level.h"
FileManager::FileManager()
{
	//std::array <std::string, TEXTURES> file_names = { "bigGold.png","bigRock.png",
	//"bomb.png" ,"bone.png", "diamond.png", "mouse.png", "playerGrab.png", "playerStand.png",
	//"present.png", "smallGold.png", "smallRock.png" };
	//for (size_t i = 0; i < TEXTURES; ++i)
	//	m_pTexture[i].loadFromFile(file_names[i]);
	// loading images
	m_pTexture[PLAYER].loadFromFile("Player.png");
	m_pTexture[ROPE].loadFromFile("bone.png"); //change it!!!!!!!!!!!!!!!!!!
	m_pTexture[BIGGOLD].loadFromFile("bigGold.png");
	m_pTexture[SMALLGOLD].loadFromFile("smallGold.png");
	m_pTexture[BIGROCK].loadFromFile("bigRock.png");
	m_pTexture[SMALLROCK].loadFromFile("smallRock.png");
	m_pTexture[DIAMOND].loadFromFile("diamond.png");
	m_pTexture[PRESENT].loadFromFile("present.png");
	m_pTexture[BONE].loadFromFile("bone.png");
	m_pTexture[BOMB].loadFromFile("bomb.png");
	m_pTexture[MOUSE].loadFromFile("mouse.png");
	m_font[0].loadFromFile("Font1.otf");
	m_font[1].loadFromFile("Font2.otf");
	m_font[2].loadFromFile("gameFont.otf");



}
// this functions gets icon texture and return the shpe
sf::Texture* FileManager::getIconTexture(size_t shape)
{
	return &m_pTexture[shape];
}

// this function used for returning the life's counter
sf::Texture* FileManager::getLifeTexture()
{
	return &m_lifeCount;
}

// this function used for getting and return the fonts
sf::Font* FileManager::getFont(size_t type)
{
	return &m_font[type];
}

// this function used for getting the sounds for the game
FileManager& FileManager::instance()
{
	static FileManager instance;
	return instance;
}

// this function used for getting screens, along the program
sf::Texture* FileManager::getScreen(size_t screen)
{
	return &m_pScreeen[screen];
}
