#pragma once

#include "Camera.hpp"
#include "Chunk.hpp"
#include "Tile.hpp"
#include <unordered_map>

class Tilemap
{
private:
	std::unordered_map<uint64_t, Chunk> chunks;

public:
	void set_tile(Vec2i tile_position);
	void draw(
		SDL_Renderer* renderer,
		GameTextures& game_textures,
		TileTextures& tile_textures,
		Camera& camera
	);
};
