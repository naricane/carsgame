#include "Texture.hpp"

uint32_t
GameTextures::load_texture(SDL_Renderer* renderer, std::string_view path)
{
	textures.push_back(IMG_LoadTexture(renderer, path.data()));
	SDL_SetTextureScaleMode(textures.back(), SDL_SCALEMODE_NEAREST);

	return textures.size() - 1;
}

SDL_Texture*
GameTextures::texture(uint32_t id)
{
	return textures[id];
}
