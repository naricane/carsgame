#pragma once
#include "Texture.hpp"
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
	std::array<uint32_t, std::size_t(TileType::Max)> texture_ids;

public:
	TileTextures(SDL_Renderer* renderer, GameTextures& game_textures);

	uint32_t operator[](TileType tile_type) { return texture_ids[std::size_t(tile_type)]; }
};
