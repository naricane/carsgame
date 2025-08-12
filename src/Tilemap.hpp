#pragma once

#include "Camera.hpp"
#include "Chunk.hpp"
#include "Tile.hpp"
#include <unordered_map>

class Tilemap
{
private:
	TileTextures tile_textures;
	std::unordered_map<uint64_t, Chunk> chunks;

public:
	Tilemap(SDL_Renderer* renderer);
	void set_tile(Vec2i tile_position);
	void draw(SDL_Renderer* renderer, Camera& camera);
};
