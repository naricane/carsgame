#include "Texture.hpp"

TextureHandle
GameTextures::load_texture(SDL_Renderer* renderer, std::string_view path)
{
	textures.push_back(IMG_LoadTexture(renderer, path.data()));
	SDL_SetTextureScaleMode(textures.back(), SDL_SCALEMODE_NEAREST);

	return TextureHandle{ uint32_t(textures.size() - 1) };
}

SDL_Texture*
GameTextures::texture(TextureHandle handle) const
{
	return textures[handle.id];
}
