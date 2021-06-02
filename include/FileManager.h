#pragma once
#include  "Objects/Objects.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
#include <iostream>


enum Object_t : size_t
{ PLAYER, BOMB, BONE, BIGGOLD, SMALLGOLD, DIAMOND, PRESENT, SMALLROCK, BIGROCK,ROPE, MOUSE };
using std::ifstream;
using std::string;


const auto TEXTURES = 11;


class FileManager
{
public:
	const sf::Texture& get_icon(size_t shape) const;


	static FileManager& instance();


private:
	FileManager();
	sf::Texture m_pTexture[TEXTURES];


};