#pragma once
#include <SFML/Graphics.hpp>
#include <array>

const auto TEXTURES = 11;

enum class textures_type : size_t
{
	bigGold, bigRock, bomb, bone, diamond, mouse, playerGrab, playerStand, present, smallGold, smallRock
};

class TextureHandle {
public:
	static TextureHandle& use();
	const sf::Texture& getTexture(textures_type type) const;
private:
	TextureHandle();
	TextureHandle(const TextureHandle&) = default;
	TextureHandle& operator=(const TextureHandle&) = default;
	void loadTextures();
	std::array <sf::Texture, TEXTURES> m_textures;


};