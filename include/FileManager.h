#pragma once
#include  "Objects/Objects.h"

#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
#include <memory>
#include <string>
#include <iostream>
#include <vector>

enum Object_t { PLAYER, BOMB, BONE, BIGGOLD, SMALLGOLD, DIAMOND, PRESENT, SMALLROCK, BIGROCK,ROPE, MOUSE };
using std::ifstream;
using std::string;


const auto TEXTURES = 11;

enum class textures_type : size_t
{
	bigGold, bigRock, bomb, bone, diamond, mouse, playerGrab, playerStand, present, smallGold, smallRock
};
/*
struct high_score {
	int score;
	std::string name;
};*/


class FileManager
{
public:
	sf::Texture* get_icon(size_t shape);


	static FileManager& instance();


private:
	FileManager();
	sf::Texture m_pTexture[TEXTURES];


};