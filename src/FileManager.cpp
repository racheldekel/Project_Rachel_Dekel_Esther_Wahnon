#include "FileManager.h"
#include "Level.h"
FileManager::FileManager()
{


	/*std::array <std::string, TEXTURES> file_names = { "playerStand.png" , "bomb.png","bone.png" , "bigGold.png" ,"smallGold.png", "diamond.png",
													"present.png" , "bigRock.png" , "smallRock.png", "mouse.png" };*/

	m_pTexture[PLAYER].loadFromFile("playerStand.png");
	m_pTexture[BOMB].loadFromFile("bomb.png");
	m_pTexture[BONE].loadFromFile("bone.png");
	m_pTexture[BIGGOLD].loadFromFile("bigGold.png");
	m_pTexture[SMALLGOLD].loadFromFile("smallGold.png");
	m_pTexture[DIAMOND].loadFromFile("diamond.png");
	m_pTexture[PRESENT].loadFromFile("present.png");
	m_pTexture[BIGROCK].loadFromFile("bigRock.png");
	m_pTexture[SMALLROCK].loadFromFile("smallRock.png");
	m_pTexture[ROPE].loadFromFile("bomb.png"); 
	m_pTexture[MOUSE].loadFromFile("mouse.png");

}
// this functions gets icon texture and return the shpe
sf::Texture* FileManager::get_icon(size_t shape)
{
	return &m_pTexture[shape];
}

FileManager& FileManager::instance()
{
	static FileManager instance;
	return instance;
}
