#pragma once
#include "Camera.hpp"
#include "Tile.hpp"
#include <array>

constexpr uint32_t CHUNK_SIZE = 64;

class Chunk
{
private:
	std::array<TileType, CHUNK_SIZE * CHUNK_SIZE> tiles = {};

public:
	void set_tile(Vec2i tile_position);
	void draw(
		SDL_Renderer* renderer,
		Vec2i index,
		GameTextures& game_textures,
		TileTextures tile_textures,
		Camera& camera
	);
};
