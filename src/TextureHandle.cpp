#include "TextureHandle.h"

TextureHandle::TextureHandle() {
	loadTextures();
}

void TextureHandle::loadTextures() {
	std::array <std::string, TEXTURES> file_names = { "bigGold.png","bigRock.png",
	"bomb.png" ,"bone.png", "diamond.png", "mouse.png", "playerGrab.png", "playerStand.png",
		"present.png", "smallGold.png", "smallRock.png"  };
	for (size_t i = 0; i < TEXTURES; ++i)
		m_textures[i].loadFromFile(file_names[i]);
}

TextureHandle& TextureHandle::use() {
	static TextureHandle textureHandleObj;
	return textureHandleObj;
}

const sf::Texture& TextureHandle::getTexture(textures_type type) const {
	return m_textures[size_t(type)];
}