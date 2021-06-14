#pragma once
#include  "Objects/Objects.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
#include <iostream>


enum Object_t : size_t
{ PLAYER, PLAYERGRAB, BOMB, BONE, BIGGOLD, SMALLGOLD, DIAMOND, PRESENT, SMALLROCK, BIGROCK,ROPE, MOUSE };
using std::ifstream;
using std::string;


const auto TEXTURES = 12;


class FileManager
{
public:
	const sf::Texture& get_icon(size_t shape) const;


	static FileManager& instance();
	sf::Font* getFont(size_t type);

private:
	FileManager();
	sf::Texture m_pTexture[TEXTURES];
	sf::Font m_font[1];

};