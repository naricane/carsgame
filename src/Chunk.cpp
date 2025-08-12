#include "Chunk.hpp"
#include <cstdio>

Chunk::Chunk(Vec2i index)
	: index(index)
{
}

void
Chunk::set_tile(Vec2i tile_position)
{
	tiles[tile_position.x + tile_position.y * CHUNK_SIZE] = TileType::Asphalt;
}

void
Chunk::draw(SDL_Renderer* renderer, Camera& camera, TileTextures& tile_textures)
{
	for (size_t y = 0; y < CHUNK_SIZE; y++) {
		for (size_t x = 0; x < CHUNK_SIZE; x++) {
			SDL_FRect draw_rect = camera.to_screen(
				{
					float(int(x * TILE_SIZE) + index.x * int(TILE_SIZE * CHUNK_SIZE)),
					float(int(y * TILE_SIZE) + index.y * int(TILE_SIZE * CHUNK_SIZE)),
					TILE_SIZE,
					TILE_SIZE,
				}
			);

			SDL_RenderTexture(
				renderer, tile_textures[tiles[x + y * CHUNK_SIZE]], nullptr, &draw_rect
			);
		}
	}
}
