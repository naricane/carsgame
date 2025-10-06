#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <string_view>
#include <vector>

struct TextureHandle
{
	uint32_t id;
};

class GameTextures
{
private:
	std::vector<SDL_Texture*> textures;

public:
	TextureHandle load_texture(SDL_Renderer* renderer, std::string_view path);
	SDL_Texture* texture(TextureHandle handle) const;
};
