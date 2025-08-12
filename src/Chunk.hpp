#pragma once
#include "Camera.hpp"
#include "Tile.hpp"
#include <array>

constexpr uint32_t CHUNK_SIZE = 64;

class Chunk
{
private:
	std::array<TileType, CHUNK_SIZE * CHUNK_SIZE> tiles = {};
	Vec2i index;

public:
	Chunk(Vec2i index);
	void set_tile(Vec2i tile_position);
	void draw(SDL_Renderer* renderer, Camera& camera, TileTextures& tile_textures);
};
