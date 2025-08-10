#pragma once
#include <SDL3/SDL_render.h>
#include <array>

constexpr int TILE_SIZE = 16;

enum class TileType
{
	None,
	Asphalt,

	Max
};

class TileTextures
{
private:
	std::array<SDL_Texture*, std::size_t(TileType::Max)> textures;

public:
	TileTextures(SDL_Renderer* renderer);

	SDL_Texture* operator[](TileType tile_type) { return textures[int(tile_type)]; }
};
