#include "FileManager.h"
#include "Level.h"
FileManager::FileManager()
{
	//texture
	m_pTexture[PLAYER].loadFromFile("playerStand.png");
	m_pTexture[PLAYERGRAB].loadFromFile("playerGrab.png");
	m_pTexture[BOMB].loadFromFile("bomb.png");
	m_pTexture[BONE].loadFromFile("bone.png");
	m_pTexture[BIGGOLD].loadFromFile("bigGold.png");
	m_pTexture[SMALLGOLD].loadFromFile("smallGold.png");
	m_pTexture[DIAMOND].loadFromFile("diamond.png");
	m_pTexture[PRESENT].loadFromFile("present.png");
	m_pTexture[BIGROCK].loadFromFile("bigRock.png");
	m_pTexture[SMALLROCK].loadFromFile("smallRock.png");
	m_pTexture[ROPE].loadFromFile("rope.png"); 
	m_pTexture[MOUSE].loadFromFile("mouse.png");
	m_pTexture[EXPLOSION].loadFromFile("explosion.png");
	m_pTexture[BACKGROUND].loadFromFile("background.png");
	//fonts
	m_font[0].loadFromFile("gameFont.otf");
	//sounds 
	m_sound[CATCH_s].loadFromFile("catch.wav");
	m_sound[EXPLOSION_s].loadFromFile("explosion.wav");
	m_sound[FINISHLEVEL_s].loadFromFile("finish_level.wav");
	m_sound[GETMONEY_s].loadFromFile("getmoney.wav");
	m_sound[PRESENT_s].loadFromFile("present.wav");
	m_sound[PULLING_s].loadFromFile("pulling.wav");
	m_sound[ROPE_s].loadFromFile("rope.wav");

}
// this functions gets icon texture and return the shpe
const sf::Texture& FileManager::get_icon(size_t shape) const
{
	return m_pTexture[shape];
}

FileManager& FileManager::instance()
{
	static FileManager instance;
	return instance;
}

sf::Font* FileManager::getFont(size_t type)
{
	return &m_font[type];
}

sf::SoundBuffer& FileManager::getSound(size_t type)
{
	return m_sound[type];
}
