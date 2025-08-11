#pragma once
#include "Camera.hpp"
#include "Tile.hpp"
#include <array>

constexpr uint32_t CHUNK_SIZE = 64;

class Chunk
{
private:
	std::array<TileType, CHUNK_SIZE * CHUNK_SIZE> tiles = {};
	int index_x, index_y;

public:
	void set_tile(int x, int y);
	void set_index(int x, int y);
	void draw(SDL_Renderer* renderer, Camera& camera, TileTextures& tile_textures);
};
