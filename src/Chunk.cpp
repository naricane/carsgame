#include "Chunk.hpp"
#include <cstdio>

void
Chunk::set_tile(int x, int y)
{
	tiles[x + y * CHUNK_SIZE] = TileType::Asphalt;
}

void
Chunk::set_index(int x, int y)
{
	index_x = x;
	index_y = y;
}

void
Chunk::draw(SDL_Renderer* renderer, Camera& camera, TileTextures& tile_textures)
{
	for (size_t y = 0; y < CHUNK_SIZE; y++) {
		for (size_t x = 0; x < CHUNK_SIZE; x++) {
			SDL_FRect draw_rect = camera.to_screen(
				{
					float(x * TILE_SIZE) + index_x * int(TILE_SIZE * CHUNK_SIZE),
					float(y * TILE_SIZE) + index_y * int(TILE_SIZE * CHUNK_SIZE),
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
