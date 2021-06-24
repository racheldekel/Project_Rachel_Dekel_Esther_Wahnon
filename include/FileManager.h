#pragma once
#include  "Object/Object.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
#include <iostream>


enum Object_t : size_t
{ PLAYER, PLAYERGRAB, BOMB, BONE, BIGGOLD, SMALLGOLD, DIAMOND, PRESENT, SMALLROCK, BIGROCK ,ROPE, MOUSE, EXPLOSION, BACKGROUND};
enum Sound_t :size_t { CATCH_s, EXPLOSION_s , FINISHLEVEL_s, GETMONEY_s, PRESENT_s, PULLING_s ,ROPE_s };
using std::ifstream;
using std::string;


const auto TEXTURES = 14;
const auto SOUNDS = 7;

class FileManager
{
public:
	const sf::Texture& get_icon(size_t shape) const;
	static FileManager& instance();
	sf::Font* getFont(size_t type);
	sf::SoundBuffer& getSound(size_t type);

private:
	FileManager();
	sf::Texture m_pTexture[TEXTURES];
	sf::Font m_font[1];
	sf::SoundBuffer m_sound[SOUNDS];

};