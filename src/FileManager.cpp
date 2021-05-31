#include "FileManager.h"
FileManager::FileManager()
{
	std::array <std::string, TEXTURES> file_names = { "bigGold.png","bigRock.png",
	"bomb.png" ,"bone.png", "diamond.png", "mouse.png", "playerGrab.png", "playerStand.png",
	"present.png", "smallGold.png", "smallRock.png" };
	for (size_t i = 0; i < TEXTURES; ++i)
		m_pTexture[i].loadFromFile(file_names[i]);
	// loading images
	//m_pTexture[PLAYER].loadFromFile("Player.png");
	//m_pTexture[ROPE].loadFromFile("enemy.png");
	//m_pTexture[BIG_GOLD].loadFromFile("Coin.png");
	//m_pTexture[SMALL_GOLD].loadFromFile("wall.png");
	//m_pTexture[BIG_ROCK].loadFromFile("Ladder.png");
	//m_pTexture[SMALL_ROCK].loadFromFile("Rod.png");
	//m_pTexture[DIAMOND].loadFromFile("present.png");
	//m_pTexture[PRESENT].loadFromFile("wall.png");
	//m_pTexture[BONE].loadFromFile("Ladder.png");
	//m_pTexture[BOMB].loadFromFile("Rod.png");
	//m_pTexture[MOUSE].loadFromFile("present.png");



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
