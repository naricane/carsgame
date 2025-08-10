#include "Texture.hpp"

SDL_Texture*
load_texture(SDL_Renderer* renderer, std::string_view path)
{
	SDL_Texture* texture;
	texture = IMG_LoadTexture(renderer, path.data());
	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

	return texture;
}
