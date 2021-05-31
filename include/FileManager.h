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

const int NUM_OF_ICONS = 7;
const int NUM_OF_FONTS = 2;
const int NUM_OF_SCREENS = 3;


const auto TEXTURES = 11;

enum class textures_type : size_t
{
	bigGold, bigRock, bomb, bone, diamond, mouse, playerGrab, playerStand, present, smallGold, smallRock
};

struct high_score {
	int score;
	std::string name;
};


class FileManager
{
public:
	sf::Texture* getIconTexture(size_t shape);
	sf::Texture* getLifeTexture();
	sf::Font* getFont(size_t type);

	static FileManager& instance();


	sf::Texture* getScreen(size_t screen);


private:
	FileManager();
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Texture m_pScreeen[NUM_OF_SCREENS];

	sf::Texture m_lifeCount;
	sf::Font m_font[NUM_OF_FONTS];
	//sf::SoundBuffer m_playerSounds[NUM_OF_SOUNDS-2];
	//sf::SoundBuffer m_gameSounds[NUM_OF_SOUNDS - 4];

	std::vector<high_score> m_listScore;
};